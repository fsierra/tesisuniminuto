<?php
/**
 * @file
 * Contains the basic ticket field handler.
 */

/**
 * Field handler to provide simple renderer
 */
class TuFieldHandlerField extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function query() {
  }

  function render($values) {
    $content = '-';
    if (isset($values->field_field_project_teacher) && empty($values->field_field_project_teacher)) {
      $content = l(t('Solicitar docente'), 'request/teacher/' . $values->nid);
    }
    return $content;
  }
}

/**
 * Field handler to provide simple renderer
 */
class TuTeacherStatusFieldHandlerField extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function query() {
  }

  function render($values) {
    $content = '-';
    switch ($values->tu_requests_status) {
      case 0:
        $content = 'pendiente';
        break;
      
      case 1:
        $content = 'aprobado';
        break;

      case 2:
        $content = 'rechazado';
        break;

    }
    return $content;
  }
}



/**
 * Field handler to provide simple renderer
 */
class TuTeacherResponseFieldHandlerField extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function query() {
  }

  function render($values) {
    $content = '-';
    switch ($values->tu_requests_status) {
      case 0:
        $content = l(t('Actualizar'), 'request/teacher/response/' . $values->node_tu_requests_nid);
        break;
      
      default:
        $content = '-';
        break;        
    }
    return $content;
  }
}

