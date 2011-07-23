// $Id: classroom.courses.js,v 1.2 2009/08/04 13:02:06 manolopm Exp $
if (Drupal.jsEnabled) {
  $(document).ready( function () {
      function change_element_status(obj, element) {
        if (obj.checked) {
          element.hide(350);
        }
        else {
          element.show(350);
        }
      }

      $("#edit-classroom-course-unlimitedend").click(function(){
        change_element_status(this,$("#edit-classroom-course-end-date-wrapper"));
       })

      $("#edit-classroom-course-open-end-inscription").click(function() {
        change_element_status(this,$("#edit-classroom-course-registration-end-date-wrapper"));
      })

      change_element_status( $("#edit-classroom-course-unlimitedend")[0],
        $("#edit-classroom-course-end-date-wrapper"));
      change_element_status( $("#edit-classroom-course-open-end-inscription")[0],
        $("#edit-classroom-course-registration-end-date-wrapper"));
  })
}

