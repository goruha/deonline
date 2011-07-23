/* $Id: classroom.assignments.js,v 1.1 2009/07/27 14:14:06 osoh Exp $ */
if (Drupal.jsEnabled) {
  $("input[name='classroom_assignment[end_date][type]']").ready( function(){
      update_end_date();
      })

  function update_end_date() {
    value = $("input[name='classroom_assignment[end_date][type]']:checked").val();
    switch (value) {
      case '0': //Fixed date
        $("#edit-classroom-assignment-end-date-date-wrapper").show(350);
        $("#edit-classroom-assignment-end-date-relative-end-wrapper").hide(350);     
        break;
      case '1': //Relative date
        $("#edit-classroom-assignment-end-date-date-wrapper").hide(350);
        $("#edit-classroom-assignment-end-date-relative-end-wrapper").show(350);
        break;
      case '2': //Without date
        $("#edit-classroom-assignment-end-date-date-wrapper").hide(350);
        $("#edit-classroom-assignment-end-date-relative-end-wrapper").hide(350);
        break;
    }
  }
}

