<?php

function theme_cck_formatter_view($element) {
  $formatter = $element['#formatter'];
  $formatter_id = explode('_', $formatter);
  $formatter_id = array_pop($formatter_id);
  $formatter = cck_formatter_view_load($formatter_id);
  $field = content_fields($element['#field_name']);
  $handler = cck_formatter_view_get_field_handler($field['type']);
  if (CCK_FORMATTER_VIEW_MULTIPLE == $formatter->type) {
    for ($i = 0; isset($element[$i]); $i++) {         
        $args[] = $handler($element[$i]);
    }
    $value = implode($formatter->options['multiple_operation'], $args);
  } else {
    $value = $handler($element);
  }
  return views_embed_view($formatter->view, $formatter->display, $value);
}