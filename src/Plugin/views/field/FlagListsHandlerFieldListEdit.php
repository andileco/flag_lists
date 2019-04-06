<?php

namespace Drupal\flag_lists\Plugin\views\field;


use Drupal\Component\Utility\Html;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\ResultRow;

/**
 * Field handler to provide simple renderer that links to the list edit page.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("flag_lists_handler_field_list_edit")
 */
class FlagListsHandlerFieldListEdit extends FieldPluginBase {

  /**
   * Constructor to provide additional field to add.
   *
   * @param array $configuration
   * @param $plugin_id
   * @param $plugin_definition
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->additional_fields['fid'] = 'fid';
  }

  /**
   * {@inheritdoc}
   */
  public function defineOptions() {
    $options = parent::defineOptions();
    $options['text'] = ['default' => '', 'translatable' => TRUE];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
    $form['text'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Text to display'),
      '#default_value' => $this->options['text'],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensureMyTable();
    $this->addAdditionalFields();
  }

  /**
   * {@inheritdoc}
   */
  public function render(ResultRow $values) {
    $fid = $values->{$this->aliases['fid']};

    // Check edit access.
    if (!flag_lists_is_owner('edit', $fid)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    $url = Url::fromRoute('flag_lists.edit', $fid);

    return Link::fromTextAndUrl($text, $url);
  }

}
