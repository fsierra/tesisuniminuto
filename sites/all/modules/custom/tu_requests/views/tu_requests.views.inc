<?php
/**
 * @file
 * Views file.
 */


/**
 * Implements hook_views_data_alter().
 */
function tu_requests_views_data_alter(&$data) {
  $data['node']['est_request'] = array(
    'group' => t('Custom item'),
    'title' => t('Custom estudent request link'),
    'help' => t('Custom estudent request link'),
    'field' => array(
      'handler' => 'TuFieldHandlerField'
    )
  );

  $data['tu_requests']['teacher_status_requ'] = array(
    'group' => t('Custom item'),
    'title' => t('Custom teacher request status'),
    'help' => t('Custom teacher request status'),
    'field' => array(
      'handler' => 'TuTeacherStatusFieldHandlerField'
    )
  );

  $data['tu_requests']['teacher_status_response'] = array(
    'group' => t('Custom item'),
    'title' => t('Custom teacher request response'),
    'help' => t('Custom teacher request response'),
    'field' => array(
      'handler' => 'TuTeacherResponseFieldHandlerField'
    )
  );


}

/**
 * Implements hook_views_data().
 */
function tu_requests_views_data() {
  $data = array(
    // Table pre_registrations.
    'tu_requests' => array(
      'table' => array(
        'group' => t('Tesis Uniminuto requests'),
        'base' => array(
          'field' => 'id',
          'title' => t('Tesis Uniminuto request'),
          'help' => t('Includes information about all teacher request.'),
        ),
        'join' => array(
          'node' => array(
            'left_field' => 'nid',
            'field' => 'motorcycle'
          ),
          'users' => array(
            'left_field' => 'uid',
            'field' => 'tuid',
          ),
        ),
      ),

      'id' => array(
        'title' => t('Request id'),
        'help' => t('Request serial number'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),

      'nid' => array(
        'title' => t('Request project'),
        'help' => t('Request user project'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'relationship' => array(
          'base' => 'node',
          'base field' => 'nid',
          'handler' => 'views_handler_relationship',
          'label' => t('Project node being used'),
          'title' => t('Project node being used'),
          'help' => t('Add the request node to the mix'),
        ),
      ),

      'uid' => array(
        'title' => t('Request project user'),
        'help' => t('Request user project that did request'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'relationship' => array(
          'base' => 'users',
          'base field' => 'uid',
          'handler' => 'views_handler_relationship',
          'label' => t('Project uid being used'),
          'title' => t('Project uid being used'),
          'help' => t('Add the request node to the mix'),
        ),
      ),

      'tuid' => array(
        'title' => t('Request project user teacher'),
        'help' => t('Request user teacher project that did request'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'relationship' => array(
          'base' => 'users',
          'base field' => 'uid',
          'handler' => 'views_handler_relationship',
          'label' => t('Project tuid being used'),
          'title' => t('Project tuid being used'),
          'help' => t('Add the request node to the mix'),
        ),
      ),

      'status' => array(
        'title' => t('Request status'),
        'help' => t('Status request'),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ) 
      ),

      'created' => array(
        'title' => t('Request created'),
        'help' => t('Request created register timestamp'),
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
      ),

    ),
  );
  return $data;
}