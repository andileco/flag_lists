<?php

namespace Drupal\flag_lists\Plugin\views\filter;


use Drupal\Core\Url;
use Drupal\views\Plugin\views\filter\InOperator;

/**
 * Filter by list template
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsField("flag_lists_handler_filter_template")
 */
class FlagListsHandlerFilterTemplate extends InOperator {

  /**
   * {@inheritdoc}
   */
  public function getValueOptions() {
    if (!isset($this->value_options)) {
      $this->value_title = $this->t('List templates');
      $this->value_options = [];
      $templates = flag_lists_get_templates();
      if (empty($templates)) {
        drupal_set_message(
          $this->t('No templates found, create a flag lists <a href="@url">template</a>',
            ['@url' => Url::fromRoute('flag_lists.template')]),
          'info');
      }
      else {
        if ($templates['0'] === FALSE) {
          drupal_set_message(
            $this->t('No enabled template found, enable the built in flag lists <a href="@url">template</a>',
              ['@url' => Url::fromRoute('flag_lists.fl_template')]),
            'warning');
        }
        else {
          foreach ($templates as $template) {
            $options[$template->name] = $template->name;
          }
          $this->value_options = $options;
        }
      }
    }
    return $this->value_options;
  }

}
