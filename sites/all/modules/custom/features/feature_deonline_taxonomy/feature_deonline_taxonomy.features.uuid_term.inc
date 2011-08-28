<?php

/**
 * Implementation of hook_uuid_features_default_terms().
 */
function feature_deonline_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'uuid' => '471c4430-d16f-11e0-9495-001e33587f06',
    'name' => 'Немецкий Бизнес',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b552a-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471c6186-d16f-11e0-9495-001e33587f06',
    'name' => 'Немецкий Toiffle',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b552a-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471c8396-d16f-11e0-9495-001e33587f06',
    'name' => 'Немецкий туризм',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b552a-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471c9f0c-d16f-11e0-9495-001e33587f06',
    'name' => 'A',
    'description' => 'Элементарное владение 
(Basic User)',
    'weight' => '0',
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471cb94c-d16f-11e0-9495-001e33587f06',
    'name' => 'B',
    'description' => 'Самостоятельное владение
(Independent User)',
    'weight' => '0',
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471ce318-d16f-11e0-9495-001e33587f06',
    'name' => 'C',
    'description' => 'Свободное владение
(Proficient User)',
    'weight' => '0',
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471d0988-d16f-11e0-9495-001e33587f06',
    'name' => 'A1',
    'description' => 'Уровень выживания
(Breakthrough)',
    'weight' => '0',
    'parent' => array(
      '0' => '471c9f0c-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471d30c0-d16f-11e0-9495-001e33587f06',
    'name' => 'A2',
    'description' => 'Предпороговый уровень
(Waystage)',
    'weight' => '0',
    'parent' => array(
      '0' => '471c9f0c-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471d53c0-d16f-11e0-9495-001e33587f06',
    'name' => 'B1',
    'description' => 'Пороговый уровень
(Threshold)',
    'weight' => '0',
    'parent' => array(
      '0' => '471cb94c-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471d75da-d16f-11e0-9495-001e33587f06',
    'name' => 'B2',
    'description' => 'Пороговый продвинутый уровень
(Vantage)',
    'weight' => '0',
    'parent' => array(
      '0' => '471cb94c-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471e8c54-d16f-11e0-9495-001e33587f06',
    'name' => 'C1',
    'description' => 'Уровень профессионального владения
(Effective Operational Proficiency)',
    'weight' => '0',
    'parent' => array(
      '0' => '471ce318-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471ea338-d16f-11e0-9495-001e33587f06',
    'name' => 'C2',
    'description' => 'Уровень владения в совершенстве
(Mastery)',
    'weight' => '0',
    'parent' => array(
      '0' => '471ce318-d16f-11e0-9495-001e33587f06',
    ),
    'uuid_vocabulary' => '471b762c-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471eb8fa-d16f-11e0-9495-001e33587f06',
    'name' => 'Индивидуальные',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b9224-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471ece1c-d16f-11e0-9495-001e33587f06',
    'name' => 'Парные',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b9224-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471ee906-d16f-11e0-9495-001e33587f06',
    'name' => 'Групповые',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471b9224-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f0396-d16f-11e0-9495-001e33587f06',
    'name' => 'gramma',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471bac64-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f1b6a-d16f-11e0-9495-001e33587f06',
    'name' => 'Warum suchst du dir nicht ein Zimmer in einer netten Wohngemeinschaft?',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471bac64-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f30e6-d16f-11e0-9495-001e33587f06',
    'name' => '< 16',
    'description' => '',
    'weight' => '-4',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f44b4-d16f-11e0-9495-001e33587f06',
    'name' => '16-18',
    'description' => '',
    'weight' => '-3',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f5332-d16f-11e0-9495-001e33587f06',
    'name' => '19-25',
    'description' => '',
    'weight' => '-2',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f6052-d16f-11e0-9495-001e33587f06',
    'name' => '26-35',
    'description' => '',
    'weight' => '-1',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f6dcc-d16f-11e0-9495-001e33587f06',
    'name' => '36-45',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f7ab0-d16f-11e0-9495-001e33587f06',
    'name' => '>46',
    'description' => '',
    'weight' => '1',
    'uuid_vocabulary' => '471bc672-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f8c4e-d16f-11e0-9495-001e33587f06',
    'name' => 'Начинающий с нуля',
    'description' => '',
    'weight' => '-2',
    'uuid_vocabulary' => '471be850-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471f9bc6-d16f-11e0-9495-001e33587f06',
    'name' => 'Начальный',
    'description' => '',
    'weight' => '-1',
    'uuid_vocabulary' => '471be850-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471fa8dc-d16f-11e0-9495-001e33587f06',
    'name' => 'Средний',
    'description' => '',
    'weight' => '0',
    'uuid_vocabulary' => '471be850-d16f-11e0-9495-001e33587f06',
  );
  $terms[] = array(
    'uuid' => '471fbdb8-d16f-11e0-9495-001e33587f06',
    'name' => 'Высокий',
    'description' => '',
    'weight' => '1',
    'uuid_vocabulary' => '471be850-d16f-11e0-9495-001e33587f06',
  );
  return $terms;
}
