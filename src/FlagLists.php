<?php

namespace Drupal\flag_lists;


use Drupal\Core\Database\Database;
use Drupal\flag\Entity\Flag;

class flagLists extends Flag {


  // @todo: I started on this, but it needs to be overhauled.

//  function save() {
//    $flag->{$this->flagListsSave($flag)};
//  }
//
//  /**
//   * Saves a flag to the database. It is a wrapper around update($flag) and
//   * insert($flag).
//   */
//  function flagListsSave(&$flag) {
//    if (isset($flag->fid)) {
//      $this->flagListsUpdate($flag);
//      $flag->is_new = FALSE;
//    }
//    else {
//      $this->flagListsInsert($flag);
//      $flag->is_new = TRUE;
//    }
//    // Clear the page cache for anonymous users.
//    //    cache_clear_all('*', 'cache_page', TRUE);
//  }
//
//  /**
//   * Saves an existing flag to the database. Better use save($flag).
//   */
//  function flagListsUpdate($flag) {
//    $database = Database::getConnection();
//    $database->query("UPDATE {flag_lists_flags} SET title = '%s', name = '%s' WHERE fid = %d", $flag->title, $flag->name, $flag->fid);
//  }
//
//  /**
//   * Saves a new flag to the database. Better use save($flag).
//   */
//  function flagListsInsert($flag) {
//    $database = Database::getConnection();
//    $database->query("INSERT INTO {flag_lists_flags} (pfid, uid, content_type, name, title, options) VALUES (%d, %d, '%s', '%s', '%s', '%s')",
//      $flag->pfid, $flag->uid,
//      $flag->content_type,
//      $flag->name,
//      $flag->title,
//      $flag->get_serialized_options($flag));
//    $flag->fid = db_last_insert_id('flags', 'fid');
//    $flag->name = 'flag_lists_' . $flag->uid . '_' . $flag->fid;
//    $flag->{$this->flagListsUpdate($flag)};
//
//    foreach ($flag->types as $type) {
//      $database->query("INSERT INTO {flag_types} (fid, type) VALUES (%d, '%s')", $flag->fid, $type);
//    }
//  }


}
