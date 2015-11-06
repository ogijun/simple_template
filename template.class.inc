<?php
function h($str) {
  return htmlspecialchars($str);
}

class Template {
  protected $filename;
  protected $layout = null;
  protected $context = array();

  function __construct($filename, $layout = null) {
    $this->filename = $filename;
    $this->layout = $layout;
  }
  
  function bind($key, $value){
    $this->context[$key] = $value;
  }

  function display($bindings = null) {
    echo $this->render($bindings);
  }

  function render($bindings = null) {
    $context = $this->context;
    if ($bindings != null && is_array($bindings)) {
      $context = array_merge($context, $bindings);
    }
    $renderd_content = self::render_template($this->filename, $context);

    if (isset($context['_layout'])) {
      $layout = $context['_layout'];
    } else {
      $layout = $this->layout;
    }

    if ($layout) {
      $context['_content'] = $renderd_content;
      $renderd_content = self::render_template($layout, $context);
    }
    return $renderd_content;
  }

  static function render_template($filename, &$context) {
    extract($context);
    ob_start();
    include($filename);
    return ob_get_clean();
  }

}