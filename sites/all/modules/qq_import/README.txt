$Id: README.txt,v 1.1 2010/09/26 11:04:47 sivaji Exp $

-- About --

Quiz questions import (qq_import) is a simple module, designed as an
addon for quiz module. It allows user with permission 'import quiz questions'
to create a bulk of quiz questions from CSV file. The import CSV file must
be in format specified in 'examples' directory.

-- How to use --

* Create questions CSV file. Refer 'examples' directory for sample.

* Login as admin to your drupal site and navigate to
Administer > Quiz management > Import Quiz Questions.

* Select the questions type and upload the CSV file. This steps will
create quiz questions. Navigate to Administer > Content management
> Content to see the list of created questions.


-- How it is different from existing import module --

Proposed module is a subset of existing import module developed for
one of our recent projects.

Existing module supports many import types but nothing works
out-of-box. Handling multiple import types made validation and
submit handler tricky and hard to customize for project specific
needs.

Proposed module supports only CSV import. Import file can have only
one type of questions (either multichoice, truefalse or similar).

The code is posted in drupal.org with an intention of sharing.

For a full description of the module, visit the project page:
  http://drupal.org/project/qq_import

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/qq_import


-- REQUIREMENTS --

This module depends of quiz. To use this module you need to enable,
the quiz module and one of its questions type module (multichoice,
long_answer, etc.)


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONTACT --

Current maintainer:
* Sivaji - http://drupal.org/user/328724

-- CREDIT --
This project has been sponsored by "SG E-ndicus InfoTech Pvt Ltd "
  We provide ERP, CMS & LMS services based on Free and Open Source Software
  for individuals, small businesses, associations and non-profit organizations.
  Visit http://www.e-ndicus.com for more information.
