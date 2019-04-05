<?php

namespace Drupal\flag_lists\Plugin\views\argument;

use Drupal\Component\Utility\Html;
use Drupal\Core\Database\Database;
use Drupal\views\Plugin\views\argument\NumericArgument;

/**
 * Argument handler to accept a list id.
 *
 * @ingroup views_argument_handlers
 *
 * @ViewsArgument("flag_lists_handler_argument_fid")
 */
class FlagListsHandlerArgumentFid extends NumericArgument {

  /**
   * Override the behavior of title(). Get the title of the list.
   */
  function titleQuery() {
    $titles = [];
    // @todo: should use dependency injection
    $database = Database::getConnection();
    $result = $database->select('flag_lists_flags', 'fl')
      ->fields('fl', array('title'))
      ->condition('fl.fid', $this->value, 'IN');
    foreach ($result as $term) {
      $titles[] = Html::escape($term->title);
    }
    return $titles;
  }

}
