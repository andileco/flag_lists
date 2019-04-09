<?php

/**
 * @file
 * Provides support for the Views module.
 */

/**
 * Implementation of hook_views_data_alter().
 */
function flag_lists_views_data_alter(&$data) {

  // We want access to users table fields.
  $data['users']['table']['join']['flag_lists_flags'] = [
    'left_field' => 'uid',
    'field' => 'uid',
  ];

  // We need fid and name form flags' data, and join.
  $data['flag'] = [
    'table' => [
      'group' => t('Flag'),
      'join' => [
        'flag_lists_flags' => [
          'left_field' => 'pfid',
          'field' => 'fid',
        ],
      ],
    ],
    'fid' => [
      'title' => t('Flag fid'),
      'help' => t('Flag id'),
      'field' => [
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'name' => [
      'title' => t('Template name'),
      'help' => t('The name of the list template flag'),
      'field' => [
        'handler' => 'flag_lists_handler_field_template',
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'flag_lists_handler_filter_template',
        'allow empty' => TRUE,
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
  ];

  // Add the checkbox for flagging nodes VBO style, minus batch API
  foreach (\Drupal::entityTypeManager()->getDefinitions() as $entity_type => $info) {
    if (isset($info['base table']) && $info['base table'] == 'node' && isset($data[$info['base table']])) {
      $data[$info['base table']]['flag_lists_ops'] = [
        'title' => t('Flag lists operations'),
        'help' => t('Provide a checkbox to select the row for flag lists operations.'),
        'real field' => $info['entity keys']['id'],
        'field' => [
          'handler' => 'flag_lists_handler_field_ops',
          'click sortable' => FALSE,
        ],
      ];
      break;
    }
  }
}

/**
 * Implementation of hook_views_data().
 */
function flag_lists_views_data() {
  $data = [];

  // flag_lists_flags data
  $data['flag_lists_flags'] = [
    'table' => [
      'base' => [
        'field' => 'fid',
        'title' => t('Flag lists'),
        'help' => 'User created flag lists',
        'weight' => 10,
        'database' => 'default',
      ],
      'group' => t('Flag lists'),
      'join' => [
        'node' => [
          'table' => 'flag_lists_flags',
          'left_table' => 'flag_lists_content',
          'left_field' => 'fid',
          'field' => 'fid',
        ],
      ],
    ],
    'fid' => [
      'title' => t('fid'),
      'help' => t('Flag list id, required for Flag lists operationis\'s "unflag" action.'),
      'field' => [
        'handler' => 'flag_lists_handler_field_list',
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ],
      'argument' => [
        'handler' => 'flag_lists_handler_argument_fid',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'pfid' => [
      'title' => t('pfid'),
      'help' => t('Template flag id'),
      'field' => [
        'handler' => 'flag_lists_handler_field_pfid',
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],

    'uid' => [
      'title' => t('Uid'),
      'help' => t('The list owner\'s uid'), // The help that appears on the UI,
      'field' => [
        'handler' => 'views_handler_field_user',
        'click sortable' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_user_uid',
        'name field' => 'name', // display this field in the summary
      ],
      'filter' => [
        'title' => t('Name'),
        'handler' => 'views_handler_filter_user_name',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'name' => [
      'title' => t('machine name'),
      'help' => t('Machine name of the list'),
      'field' => [
        'handler' => 'flag_lists_handler_field_list',
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'views_handler_filter_string',
        'allow empty' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_string',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'title' => [
      'title' => t('List title'),
      'help' => t('Title of the list'),
      'field' => [
        'click sortable' => TRUE,
        'handler' => 'flag_lists_handler_field_list',
      ],
      'filter' => [
        'handler' => 'flag_lists_handler_filter_list',
      ],
      'argument' => [
        'handler' => 'views_handler_argument_string',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
    'edit_list' => [
      'field' => [
        'title' => t('Edit link'),
        'help' => t('Link to edit the list title'),
        'handler' => 'flag_lists_handler_field_list_edit',
      ],
    ],
    'delete_list' => [
      'field' => [
        'title' => t('Delete link'),
        'help' => t('Link to delete the list'),
        'handler' => 'flag_lists_handler_field_list_delete',
      ],
    ],
  ];

  // Flag_lists_content data

  $data['flag_lists_content'] = [
    'table' => [
      'join' => [
        'node' => [
          'left_field' => 'nid',
          'field' => 'entity_id',
        ],
      ],
      'group' => t('Flag lists'),
    ],
    'uid' => [
      'relationship' => [
        'title' => t('User'),
        'help' => t('The user who listed this node'),
        'base' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('List user'),
      ],
    ],
    'entity_id' => [
      'relationship' => [
        'title' => t('Node'),
        'help' => t('The node that has been listed'),
        'base' => 'node',
        'handler' => 'views_handler_relationship',
        'label' => t('Listed content'),
      ],
    ],
    'timestamp' => [
      'title' => t('Time listed'),
      'help' => t('The time this node was listed'),
      'field' => [
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ],
      'filter' => [
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ],
      'argument' => [
        'handler' => 'views_handler_argument_numeric',
      ],
      'sort' => [
        'handler' => 'views_handler_sort',
      ],
    ],
  ];

  // Flag_lists_types data

  $data['flag_lists_types'] = [
    'table' => [
      'group' => t('Flag lists'),
      'join' => [
        'flag_lists_flags' => [
          'table' => 'flag_lists_types',
          'type' => 'INNER',
          'left_table' => 'flag',
          'left_field' => 'name',
          'field' => 'name',
        ],
      ],
    ],
    'type' => [
      'title' => t('Template types'),
      'help' => t('Node types that can be listed by lists using this template'),
      'field' => [
        'click sortable' => FALSE,
        'handler' => 'flag_lists_handler_field_template_types',
      ],
    ],
  ];
  return $data;
}
