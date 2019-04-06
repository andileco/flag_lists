<?php

namespace Drupal\flag_lists\Plugin\views\filter;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\filter\StringFilter;

/**
 * Filter by flag lists.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsField("flag_lists_handler_filter_list")
 */
class FlagListsHandlerFilterList extends StringFilter {

  /**
   * {@inheritdoc}
   */
  protected function valueForm(&$form, FormStateInterface $form_state) {
    parent::valueForm($form, $form_state);
    if ($form['value']['#type'] == 'textfield') {
      $form['value']['#autocomplete_path'] =
        'flag-lists/autocomplete_list_callback';
    }
  }

}
