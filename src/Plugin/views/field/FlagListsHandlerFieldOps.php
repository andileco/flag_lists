<?php

namespace Drupal\flag_lists\Plugin\views\field;


use Drupal\Component\Utility\Html;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\Plugin\views\style\Table;
use Drupal\views\ResultRow;

/**
 * Field handler to provide simple renderer that links to the list edit page.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("flag_lists_handler_field_ops")
 */
class FlagListsHandlerFieldListOps extends FieldPluginBase {

  /**
   * Constructor to provide additional field to add.
   *
   * @param array $configuration
   * @param $plugin_id
   * @param $plugin_definition
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
  }

  /**
   * {@inheritdoc}
   */
  public function defineOptions() {
    $options = parent::defineOptions();
    $options['flo'] = [
      'contains' => [
        'force_single' => ['default' => FALSE],
        'operation' => ['default' => 'flag'],
      ],
    ];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
    $form['flo'] = [
      '#type' => 'fieldset',
      '#title' => $this->t('Flag lists operations'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    ];
    $form['flo']['force_single'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Force single'),
      '#default_value' => $this->options['flo']['force_single'],
      '#description' => $this->t('Check this box to restrict selection to a single value.'),
    ];
    $form['flo']['operation'] = [
      '#type' => 'radios',
      '#title' => $this->t('Operation'),
      '#default_value' => $this->options['flo']['operation'],
      '#description' => $this->t('The flag lists operation for this selection.'),
      '#options' => [
        'flag' => $this->t('Add to list'),
        'unflag' => $this->t('Remove from list'),
      ],
      '#required' => TRUE,
    ];
  }

  /**
   * If the view is using a table style, provide a
   * placeholder for a "select all" checkbox.
   */
  public function label() {
    if ($this->view->style_plugin instanceof Table && !$this->options['flo']['force_single']) {
      return '<!--flag-lists-ops-select-all-->';
    }
    else {
      return parent::label();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function render(ResultRow $values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  /**
   * @param $form
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   */
  public function viewsForm(&$form, FormStateInterface $form_state) {
    // The view is empty, abort.
    if (empty($this->view->result)) {
      return;
    }

    $form[$this->options['id']] = [
      '#tree' => TRUE,
    ];

    // Do we add or delete?
    $operation = [];
    if ($this->options['flo']['operation'] == 'flag') {
      $operation[0] = 'Add';
      $operation[1] = 'to';
    }
    else {
      $operation[0] = 'Remove';
      $operation[1] = 'from';
    };

    // At this point, the query has already been run, so we can access the results
    // in order to get the base key value (for example, nid for nodes).
    foreach ($this->view->result as $row_index => $row) {
      $entity_id = $this->getValue($row);
      $name = \Drupal::state()->get('flag_lists_name', 'list');

      if ($this->options['flo']['force_single']) {
        $form[$this->options['id']][$row_index] = [
          '#type' => 'radio',
          '#parents' => [$this->options['id']],
          '#return_value' => $entity_id . (isset($row->flag_lists_flags_fid) ? ('-' . $row->flag_lists_flags_fid) : ''),
          '#attributes' => [
            'title' =>
              [
                $this->t('@oper this item, @entity_id, @direction the @name',
                  [
                    '@oper' => $operation[0],
                    '@entity_id' => $entity_id,
                    '@direction' => $operation[1],
                    '@name' => $name,
                  ]
                ),
              ],
          ],
        ];
      }
      else {
        $form[$this->options['id']][$row_index] = [
          '#type' => 'checkbox',
          '#return_value' => $entity_id . (isset($row->flag_lists_flags_fid) ? ('-' . $row->flag_lists_flags_fid) : ''),
          '#default_value' => FALSE,
          '#attributes' => [
            'class' => ['flo-select'],
            'title' => [
              $this->t('@oper item @entity_id @direction the @name',
                [
                  '@oper' => $operation[0],
                  '@entity_id' => $entity_id,
                  '@direction' => $operation[1],
                  '@name' => $name,
                ]),
            ],
          ],
        ];
      }
    }
  }

}
