<?php

namespace Drupal\flag_lists\Plugin\views\field;


use Drupal\Component\Utility\Html;
use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\ResultRow;

/**
 * Field handler to provide simple renderer that allows linking to a list.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("flag_lists_handler_field_list")
 */
class FlagListsHandlerFieldList extends FieldPluginBase {

  /**
   * Constructor to provide additional field to add.
   *
   * @param array $configuration
   * @param $plugin_id
   * @param $plugin_definition
   */
  function __construct(array $configuration, $plugin_id, $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->additional_fields['fid'] = ['table' => 'flag_lists_flags', 'field' => 'fid'];
    $this->additional_fields['uid'] = ['table' => 'flag_lists_flags', 'field' => 'uid'];
  }

  /**
   * {@inheritdoc}
   */
  function defineOptions() {
    $options = parent::defineOptions();
    $options['link_to_list'] = ['default' => FALSE];
    return $options;
  }

  /**
   * Provide link to list option
   *
   * @param $form
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   */
  function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
    $form['link_to_list'] = [
      '#title' => $this->t('Link this field to its list'),
      '#description' => $this->t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_list']),
    ];
  }

  /**
   * Render whatever the data is as a link to the list.
   *
   * Data should be made XSS safe prior to calling this function.
   *
   * @param $data
   * @param $values
   *
   * @return
   */
  function renderLink($data, $values) {
    if (!empty($this->options['link_to_list']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "user/" . $values->{$this->aliases['uid']} . "/flag/lists/" . $values->{$this->aliases['fid']};
    }
    return $data;
  }

  function render(ResultRow $values) {
    return $this->renderLink(Html::escape($values->{$this->field_alias}), $values);
  }

}
