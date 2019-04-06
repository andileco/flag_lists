<?php

namespace Drupal\flag_lists\Plugin\views\field;


use Drupal\Component\Utility\Html;
use Drupal\Core\Database\Database;
use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\Plugin\views\field\PrerenderList;
use Drupal\views\ResultRow;

/**
 * Field handler to provide a list of template node types.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("flag_lists_handler_field_template_types")
 */
class FlagListsHandlerFieldTemplateTypes extends PrerenderList {

  /**
   * Constructor to provide additional field to add.
   *
   * @param array $configuration
   * @param $plugin_id
   * @param $plugin_definition
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->additional_fields['name'] = ['table' => 'flag', 'field' => 'name'];
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->addAdditionalFields();
    $this->field_alias = $this->aliases['name'];
  }

  /**
   * @param $values
   */
  public function preRender(&$values) {
    $names = [];
    $this->items = [];

    foreach ($values as $result) {
      $names[] = $result->{$this->aliases['name']};
    }

    if (count($names)) {
      $database = Database::getConnection();
      $query = $database->select('flag_lists_types', 'flt');
      $query->innerJoin('flag', 'f', 'flt.name = f.name');
      $result = $query->fields('flt', ['type', 'name'])
        ->condition('f.name', $names, 'IN');
        //->orderBy('flt.type')
        //->execute();
      foreach ($result as $type) {
        $this->items[$type->name][$type->type] = Html::escape($type->type);
      }
    }
  }

  public function render(ResultRow $values) {
    $field = $values->{$this->field_alias};
    if (!empty($this->items[$field])) {
      if ($this->options['type'] == 'separator') {
        return implode($this->sanitizeValue($this->options['separator']), $this->items[$field]);
      }
      else {
        $render = [
          '#theme' => 'item_list',
          '#items' => $this->items[$field],
          '#title' => NULL,
          '#list_type' => $this->options['type'],
        ];
      }
      return \Drupal::service('renderer')->render($render);
    }
  }

  public function getValue(ResultRow $values, $field = NULL, $raw = FALSE) {
    if ($raw) {
      return parent::getValue($values, $field);
    }
    $item = $this->getItems($values);
    $item = (array) $item;
    if (isset($field) && isset($item[$field])) {
      return $item[$field];
    }
    return $item;
  }

  /**
   * Renders a single item of a row.
   *
   * @param int $count
   *   The index of the item inside the row.
   * @param mixed $item
   *   The item for the field to render.
   *
   * @return string
   *   The rendered output.
   */
  public function render_item($count, $item) {
    // TODO: Implement render_item() method.
  }

}
