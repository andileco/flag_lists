<?php


// @todo: replace this with a config file (yml)


///**
// * @file
// * Contains default views for the flag_lists module.
// */
//
///**
// * Implementation of hook_views_default_views().
// */
//function flag_lists_views_default_views() {
//  $view = new view;
//  $view->name = 'flag_lists';
//  $view->description = 'Flag lists';
//  $view->tag = '';
//  $view->view_php = '';
//  $view->base_table = 'flag_lists_flags';
//  $view->is_cacheable = FALSE;
//  $view->api_version = 2;
//  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
//  $handler = $view->new_display('default', 'Defaults', 'default');
//  $handler->override_option('fields', [
//    'title' => [
//      'label' => 'List',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_list' => 1,
//      'exclude' => 0,
//      'id' => 'title',
//      'table' => 'flag_lists_flags',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//    'name' => [
//      'label' => 'Owner',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_user' => 1,
//      'overwrite_anonymous' => 0,
//      'anonymous_text' => '',
//      'exclude' => 0,
//      'id' => 'name',
//      'table' => 'users',
//      'field' => 'name',
//      'relationship' => 'none',
//    ],
//    'edit_list' => [
//      'label' => 'Operations',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'text' => 'edit',
//      'exclude' => 0,
//      'id' => 'edit_list',
//      'table' => 'flag_lists_flags',
//      'field' => 'edit_list',
//      'relationship' => 'none',
//    ],
//    'delete_list' => [
//      'label' => 'Delete link',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'text' => '',
//      'exclude' => 0,
//      'id' => 'delete_list',
//      'table' => 'flag_lists_flags',
//      'field' => 'delete_list',
//      'relationship' => 'none',
//    ],
//    'name_2' => [
//      'label' => 'Edit template',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 0,
//        'ellipsis' => 0,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_template' => 1,
//      'exclude' => 0,
//      'link_to_list' => FALSE,
//      'id' => 'name_2',
//      'table' => 'flag',
//      'field' => 'name',
//      'relationship' => 'none',
//    ],
//    'type' => [
//      'label' => 'Template types',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'type' => 'separator',
//      'separator' => ', ',
//      'exclude' => 0,
//      'id' => 'type',
//      'table' => 'flag_lists_types',
//      'field' => 'type',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('filters', [
//    'title' => [
//      'operator' => 'contains',
//      'value' => '',
//      'group' => '0',
//      'exposed' => TRUE,
//      'expose' => [
//        'use_operator' => 0,
//        'operator' => 'title_op',
//        'identifier' => 'title',
//        'label' => 'List title',
//        'optional' => 1,
//        'remember' => 1,
//      ],
//      'case' => 0,
//      'id' => 'title',
//      'table' => 'flag_lists_flags',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//    'uid' => [
//      'operator' => 'in',
//      'value' => '',
//      'group' => '0',
//      'exposed' => TRUE,
//      'expose' => [
//        'use_operator' => 0,
//        'operator' => 'uid_op',
//        'identifier' => 'uid',
//        'label' => 'Owner',
//        'optional' => 1,
//        'remember' => 1,
//        'reduce' => 0,
//      ],
//      'id' => 'uid',
//      'table' => 'flag_lists_flags',
//      'field' => 'uid',
//      'relationship' => 'none',
//    ],
//    'name' => [
//      'operator' => 'in',
//      'value' => [],
//      'group' => '0',
//      'exposed' => TRUE,
//      'expose' => [
//        'use_operator' => 0,
//        'operator' => 'name_op',
//        'identifier' => 'name',
//        'label' => 'Template name',
//        'optional' => 1,
//        'single' => 1,
//        'remember' => 0,
//        'reduce' => 0,
//      ],
//      'id' => 'name',
//      'table' => 'flag',
//      'field' => 'name',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('access', [
//    'type' => 'perm',
//    'perm' => 'administer flags',
//  ]);
//  $handler->override_option('cache', [
//    'type' => 'none',
//  ]);
//  $handler->override_option('items_per_page', 25);
//  $handler->override_option('use_pager', '1');
//  $handler->override_option('style_plugin', 'table');
//  $handler->override_option('style_options', [
//    'grouping' => '',
//    'override' => 1,
//    'sticky' => 0,
//    'order' => 'asc',
//    'columns' => [
//      'title' => 'title',
//      'name' => 'name',
//      'edit_list' => 'edit_list',
//      'delete_list' => 'edit_list',
//      'name_2' => 'name_2',
//    ],
//    'info' => [
//      'title' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'name' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'edit_list' => [
//        'separator' => ' ',
//      ],
//      'delete_list' => [
//        'separator' => '',
//      ],
//      'name_2' => [
//        'sortable' => 0,
//        'separator' => '',
//      ],
//    ],
//    'default' => 'title',
//  ]);
//  $views[$view->name] = $view;
//
//  $view = new view;
//  $view->name = 'flag_lists_content';
//  $view->description = 'Flag lists listed content';
//  $view->tag = '';
//  $view->view_php = '';
//  $view->base_table = 'node';
//  $view->is_cacheable = FALSE;
//  $view->api_version = 2;
//  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
//  $handler = $view->new_display('default', 'Defaults', 'default');
//  $handler->override_option('relationships', [
//    'entity_id' => [
//      'label' => 'Listed content',
//      'required' => 1,
//      'id' => 'entity_id',
//      'table' => 'flag_lists_content',
//      'field' => 'entity_id',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('fields', [
//    'title' => [
//      'label' => 'Node Title',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_node' => 1,
//      'exclude' => 0,
//      'id' => 'title',
//      'table' => 'node',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//    'title_1' => [
//      'label' => 'List title',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_list' => 1,
//      'exclude' => 0,
//      'id' => 'title_1',
//      'table' => 'flag_lists_flags',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//    'name' => [
//      'label' => 'Name',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_user' => 1,
//      'overwrite_anonymous' => 0,
//      'anonymous_text' => '',
//      'exclude' => 0,
//      'id' => 'name',
//      'table' => 'users',
//      'field' => 'name',
//      'relationship' => 'uid',
//    ],
//    'timestamp' => [
//      'label' => 'Time listed',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'date_format' => 'small',
//      'custom_date_format' => '',
//      'exclude' => 0,
//      'id' => 'timestamp',
//      'table' => 'flag_lists_content',
//      'field' => 'timestamp',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('filters', [
//    'status' => [
//      'operator' => '=',
//      'value' => '1',
//      'group' => '0',
//      'exposed' => FALSE,
//      'expose' => [
//        'operator' => FALSE,
//        'label' => '',
//      ],
//      'id' => 'status',
//      'table' => 'node',
//      'field' => 'status',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('access', [
//    'type' => 'perm',
//    'perm' => 'view flag lists',
//  ]);
//  $handler->override_option('cache', [
//    'type' => 'none',
//  ]);
//  $handler->override_option('items_per_page', 25);
//  $handler->override_option('use_pager', '1');
//  $handler->override_option('style_plugin', 'table');
//  $handler->override_option('style_options', [
//    'grouping' => '',
//    'override' => 1,
//    'sticky' => 0,
//    'order' => 'desc',
//    'columns' => [
//      'title' => 'title',
//      'title_1' => 'title_1',
//      'name' => 'name',
//      'timestamp' => 'timestamp',
//    ],
//    'info' => [
//      'title' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'title_1' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'name' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'timestamp' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//    ],
//    'default' => 'timestamp',
//  ]);
//  $views[$view->name] = $view;
//
//  $view = new view;
//  $view->name = 'flag_lists_user_lists';
//  $view->description = 'Flag lists user lists';
//  $view->tag = '';
//  $view->view_php = '';
//  $view->base_table = 'flag_lists_flags';
//  $view->is_cacheable = FALSE;
//  $view->api_version = 2;
//  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
//  $handler = $view->new_display('default', 'Defaults', 'default');
//  $handler->override_option('fields', [
//    'title' => [
//      'label' => 'List',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_list' => 1,
//      'exclude' => 0,
//      'id' => 'title',
//      'table' => 'flag_lists_flags',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//    'edit_list' => [
//      'label' => 'Edit link',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'text' => 'Edit',
//      'exclude' => 0,
//      'id' => 'edit_list',
//      'table' => 'flag_lists_flags',
//      'field' => 'edit_list',
//      'relationship' => 'none',
//    ],
//    'delete_list' => [
//      'label' => 'Delete link',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'text' => '',
//      'exclude' => 0,
//      'id' => 'delete_list',
//      'table' => 'flag_lists_flags',
//      'field' => 'delete_list',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('arguments', [
//    'uid' => [
//      'default_action' => 'not found',
//      'style_plugin' => 'default_summary',
//      'style_options' => [],
//      'wildcard' => 'all',
//      'wildcard_substitution' => 'All',
//      'title' => '%1\'s lists',
//      'breadcrumb' => '',
//      'default_argument_type' => 'fixed',
//      'default_argument' => '',
//      'validate_type' => 'none',
//      'validate_fail' => 'not found',
//      'break_phrase' => 0,
//      'not' => 0,
//      'id' => 'uid',
//      'table' => 'flag_lists_flags',
//      'field' => 'uid',
//      'validate_user_argument_type' => 'uid',
//      'validate_user_roles' => [
//        '2' => 0,
//      ],
//      'relationship' => 'none',
//      'default_options_div_prefix' => '',
//      'default_argument_fixed' => '',
//      'default_argument_user' => 0,
//      'default_argument_php' => '',
//      'validate_argument_node_type' => [
//        'page' => 0,
//        'story' => 0,
//      ],
//      'validate_argument_node_access' => 0,
//      'validate_argument_nid_type' => 'nid',
//      'validate_argument_vocabulary' => [],
//      'validate_argument_type' => 'tid',
//      'validate_argument_transform' => 0,
//      'validate_user_restrict_roles' => 0,
//      'validate_argument_node_flag_name' => '*relationship*',
//      'validate_argument_node_flag_test' => 'flaggable',
//      'validate_argument_node_flag_id_type' => 'id',
//      'validate_argument_user_flag_name' => '*relationship*',
//      'validate_argument_user_flag_test' => 'flaggable',
//      'validate_argument_user_flag_id_type' => 'id',
//      'validate_argument_php' => '',
//    ],
//  ]);
//  $handler->override_option('access', [
//    'type' => 'perm',
//    'perm' => 'view flag lists',
//  ]);
//  $handler->override_option('cache', [
//    'type' => 'none',
//  ]);
//  $handler->override_option('items_per_page', 25);
//  $handler->override_option('use_pager', '1');
//  $handler->override_option('style_plugin', 'table');
//  $handler->override_option('style_options', [
//    'grouping' => '',
//    'override' => 1,
//    'sticky' => 0,
//    'order' => 'asc',
//    'columns' => [
//      'title' => 'title',
//      'name' => 'name',
//    ],
//    'info' => [
//      'title' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//      'name' => [
//        'sortable' => 1,
//        'separator' => '',
//      ],
//    ],
//    'default' => 'title',
//  ]);
//  $views[$view->name] = $view;
//
//  $view = new view;
//  $view->name = 'flag_lists_user_list';
//  $view->description = 'Flag lists - one of a user\'s lists';
//  $view->tag = '';
//  $view->view_php = '';
//  $view->base_table = 'node';
//  $view->is_cacheable = FALSE;
//  $view->api_version = 2;
//  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
//  $handler = $view->new_display('default', 'Defaults', 'default');
//  $handler->override_option('fields', [
//    'title' => [
//      'label' => '',
//      'alter' => [
//        'alter_text' => 0,
//        'text' => '',
//        'make_link' => 0,
//        'path' => '',
//        'link_class' => '',
//        'alt' => '',
//        'prefix' => '',
//        'suffix' => '',
//        'target' => '',
//        'help' => '',
//        'trim' => 0,
//        'max_length' => '',
//        'word_boundary' => 1,
//        'ellipsis' => 1,
//        'html' => 0,
//        'strip_tags' => 0,
//      ],
//      'empty' => '',
//      'hide_empty' => 0,
//      'empty_zero' => 0,
//      'link_to_node' => 1,
//      'exclude' => 0,
//      'id' => 'title',
//      'table' => 'node',
//      'field' => 'title',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('sorts', [
//    'timestamp' => [
//      'order' => 'DESC',
//      'id' => 'timestamp',
//      'table' => 'flag_lists_content',
//      'field' => 'timestamp',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('arguments', [
//    'fid' => [
//      'default_action' => 'not found',
//      'style_plugin' => 'default_summary',
//      'style_options' => [],
//      'wildcard' => 'all',
//      'wildcard_substitution' => 'All',
//      'title' => '%1',
//      'breadcrumb' => '',
//      'default_argument_type' => 'fixed',
//      'default_argument' => '',
//      'validate_type' => 'none',
//      'validate_fail' => 'not found',
//      'break_phrase' => 0,
//      'not' => 0,
//      'id' => 'fid',
//      'table' => 'flag_lists_flags',
//      'field' => 'fid',
//      'validate_user_argument_type' => 'uid',
//      'validate_user_roles' => [
//        '2' => 0,
//        '3' => 0,
//        '4' => 0,
//      ],
//      'relationship' => 'none',
//      'default_options_div_prefix' => '',
//      'default_argument_fixed' => '',
//      'default_argument_user' => 0,
//      'default_argument_image_size' => '_original',
//      'default_argument_php' => '',
//      'validate_argument_node_type' => [
//        'image' => 0,
//        'club' => 0,
//        'club_topic' => 0,
//        'page' => 0,
//        'profile' => 0,
//        'story' => 0,
//        'vehicle' => 0,
//      ],
//      'validate_argument_node_access' => 0,
//      'validate_argument_nid_type' => 'nid',
//      'validate_argument_vocabulary' => [
//        '1' => 0,
//        '3' => 0,
//      ],
//      'validate_argument_type' => 'tid',
//      'validate_argument_transform' => 0,
//      'validate_user_restrict_roles' => 0,
//      'validate_argument_node_flag_name' => '*relationship*',
//      'validate_argument_node_flag_test' => 'flaggable',
//      'validate_argument_node_flag_id_type' => 'id',
//      'validate_argument_user_flag_name' => '*relationship*',
//      'validate_argument_user_flag_test' => 'flaggable',
//      'validate_argument_user_flag_id_type' => 'id',
//      'image_size' => [
//        '_original' => '_original',
//        'thumbnail' => 'thumbnail',
//        'preview' => 'preview',
//        'home' => 'home',
//        'expanded' => 'expanded',
//        'block_icon' => 'block_icon',
//        'club_grid' => 'club_grid',
//        'full' => 'full',
//      ],
//      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
//      'validate_argument_group_node_type' => [
//        'club' => 0,
//      ],
//      'validate_argument_php' => '',
//      'override' => [
//        'button' => 'Override',
//      ],
//    ],
//  ]);
//  $handler->override_option('filters', [
//    'status' => [
//      'operator' => '=',
//      'value' => '1',
//      'group' => '0',
//      'exposed' => FALSE,
//      'expose' => [
//        'operator' => FALSE,
//        'label' => '',
//      ],
//      'id' => 'status',
//      'table' => 'node',
//      'field' => 'status',
//      'relationship' => 'none',
//    ],
//  ]);
//  $handler->override_option('access', [
//    'type' => 'none',
//  ]);
//  $handler->override_option('cache', [
//    'type' => 'none',
//  ]);
//  $handler = $view->new_display('page', 'Page', 'page_1');
//  $handler->override_option('path', 'flag/lists/%');
//  $handler->override_option('menu', [
//    'type' => 'none',
//    'title' => '',
//    'description' => '',
//    'weight' => 0,
//    'name' => 'navigation',
//  ]);
//  $handler->override_option('tab_options', [
//    'type' => 'none',
//    'title' => '',
//    'description' => '',
//    'weight' => 0,
//    'name' => 'navigation',
//  ]);
//
//  $views[$view->name] = $view;
//  return $views;
//}
