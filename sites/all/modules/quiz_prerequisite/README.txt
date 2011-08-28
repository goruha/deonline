
-- SUMMARY --

The Quiz Prerequisite module lets site administrators configure quizzes to have prerequisites.  
When enabled and configured, this module will check to see if a prerequisite quiz has been taken 
before allowing users take a quiz. The module allows administrators to configure which user roles
need to meet the prerequisites.  

I must credit the Drupal 5 module posted by @sunsetco from http://drupal.org/node/518104 as the
source of the beginnings of this module.

-- REQUIREMENTS --

* The Quiz module must be installed and enabled for this module to work.

-- INSTALLATION --

* No special installation.

-- CONFIGURATION --

* The permissions are inherited from the Quiz module's permissions

* Configure quiz prerequisite options in Administer >> Quiz settings >> Prerequisite Configuration:

  - Quiz Prequisite Message
  
    Set a message to display users that need to take a prequisite quiz
  
  - Redirect to prerequisite quiz
  
    This option will redirect users to the prerequisite quiz
  
* Each quiz node will have a new "Prerequisites" tab.
 
  This tab allows administrators to configure the prerequisite requirements, and which user roles can skip.
 
 -- CONTACT --
  
 This project is co-developed by:
 * BitSprout LLC (http://www.bitsprout.net)
 * Alternative Productions (http://www.altprod.com)
