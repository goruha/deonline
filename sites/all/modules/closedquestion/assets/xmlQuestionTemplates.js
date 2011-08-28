/**
 * @file
 * ClosedQuestion specific templates for the xmlEditor.
 */

/**
 * Creates the xml for an empty multiple-choice question, loads it and switches
 * to the editor tab.
 */
function QC_CreateMC() {
  CQ_LoadTemplate('\
<question type="OPTION">\n\
  <text>Put the question here</text>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <option correct="0">\n\
    <choice>Option 1</choice>\n\
    <feedback>feedback for option 1</feedback>\n\
  </option>\n\
  <option correct="0">\n\
    <choice>Option 2</choice>\n\
    <feedback>feedback for option 2</feedback>\n\
  </option>\n\
  <option correct="1">\n\
    <choice>Option 3</choice>\n\
    <feedback>feedback for option 3</feedback>\n\
  </option>\n\
  <option correct="0">\n\
    <choice>Option 4</choice>\n\
    <feedback>feedback for option 4</feedback>\n\
  </option>\n\
</question>');
}

/**
 * Creates the xml for an empty multiple-answer question, loads it and switches
 * to the editor tab.
 */
function QC_CreateMA() {
  CQ_LoadTemplate('\
<question type="CHECK">\n\
  <text>Put the question here</text>\n\
  <correct>Feedback if the student answers the question correct.</correct>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <option>\n\
    <choice>Option 1</choice>\n\
    <feedback>feedback for option 1</feedback>\n\
  </option>\n\
  <option correct="1">\n\
    <choice>Option 2</choice>\n\
    <feedback>feedback for option 2</feedback>\n\
  </option>\n\
  <option correct="1">\n\
    <choice>Option 3</choice>\n\
    <feedback>feedback for option 3</feedback>\n\
  </option>\n\
  <option>\n\
    <choice>Option 4</choice>\n\
    <feedback>feedback for option 4</feedback>\n\
  </option>\n\
</question>');
}

/**
 * Creates the xml for an empty multiple-answer question with advanced response
 * processing, loads it and switches to the editor tab.
 */
function QC_CreateMAA() {
  CQ_LoadTemplate('\
<question type="CHECK">\n\
  <text>Put the question here</text>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <option id="a">\n\
    <choice>Option 1</choice>\n\
  </option>\n\
  <option id="b">\n\
    <choice>Option 2</choice>\n\
  </option>\n\
  <option id="c">\n\
    <choice>Option 3</choice>\n\
  </option>\n\
  <option id="d">\n\
    <choice>Option 4</choice>\n\
  </option>\n\
  <mapping correct="1">\n\
    <match pattern="a" />\n\
    <match pattern="c" />\n\
    <feedback>That is correct.</feedback>\n\
  </mapping>\n\
</question>');
}

/**
 * Creates the xml for an empty Select&Order question, loads it and switches
 * to the editor tab.
 */
function QC_CreateSO1() {
  CQ_LoadTemplate('\
<question type="selectorder" duplicates="0">\n\
  <text>Select and order the needed steps. This example question contains only one target box.</text>\n\
  <option id="a">\n\
    <choice>Step A.</choice>\n\
  </option>\n\
  <option id="b">\n\
    <choice>Step B.</choice>\n\
  </option>\n\
  <option id="c">\n\
    <choice>Step C.</choice>\n\
  </option>\n\
  <option id="d">\n\
    <choice>Step D.</choice>\n\
  </option>\n\
  <option id="e">\n\
    <choice>Step E.</choice>\n\
  </option>\n\
  <option id="f">\n\
    <choice>Step F.</choice>\n\
  </option>\n\
    <hint mintries="1">A first hint.</hint>\n\
    <hint mintries="2">A second hint.</hint>\n\
    <hint mintries="3">A third hint.</hint>\n\
  <mapping correct="1">\n\
    <match pattern="^bcd$" />\n\
    <feedback>Correct. You only need steps B, C and D.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <match pattern="^[^b]*c.*$" />\n\
    <feedback>You can not do step C unless you first do step B.</feedback>\n\
  </mapping>\n\
</question>');
}

/**
 * Creates the xml for an empty Select&Order question with multile target boxes,
 * loads it and switches to the editor tab.
 */
function QC_CreateSO2() {
  CQ_LoadTemplate('\
<question type="selectorder">\n\
  <text>Select and order the needed steps. This example question contains two target boxes.</text>\n\
  <option id="a">\n\
    <choice>Step A.</choice>\n\
  </option>\n\
  <option id="b">\n\
    <choice>Step B.</choice>\n\
  </option>\n\
  <option id="c">\n\
    <choice>Step C.</choice>\n\
  </option>\n\
  <option id="d">\n\
    <choice>Step D.</choice>\n\
  </option>\n\
  <option id="e">\n\
    <choice>Step E.</choice>\n\
  </option>\n\
  <option id="f">\n\
    <choice>Step F.</choice>\n\
  </option>\n\
  <option id="1"><choice>Day 1</choice></option>\n\
  <option id="2"><choice>Day 2</choice></option>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <mapping correct="1">\n\
    <match pattern="^1bc2d$" />\n\
    <feedback>Correct. You need to do steps B and C on day 1 and step D on day 2.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <match pattern="^[^b]*c.*$" />\n\
    <feedback>You can not do step C unless you first do step B.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <match pattern="([^d12]d)|(d[^d12])" />\n\
    <feedback>Step D is an all-day event, you can not combine it with other\n\
    steps on the same day.</feedback>\n\
  </mapping>\n\
</question>');
}

/**
 * Creates the xml for an empty hotspot question, loads it and switches to the
 * editor tab.
 */
function QC_CreateHS() {
  CQ_LoadTemplate('\
<question type="hotspot">\n\
  <text><p>Point out the correct two items.</p></text>\n\
  <matchImg src="[attachurl:1]" maxChoices="2">\n\
    <hotspot id="A" shape="circle" coords="275,68,68">Hotspot A.</hotspot>\n\
    <hotspot id="B" shape="rect" coords="0,21,43,121"></hotspot>\n\
    <hotspot id="C" shape="poly" coords="174,282,258,293,320,318,366,360,267,468,207,438,149,443,99,465,85,486,7,416,7,354,64,307">Hotspot C.</hotspot>\n\
  </matchImg>\n\
   <hint mintries="1">A first hint.</hint>\n\
   <hint mintries="2">A second hint.</hint>\n\
   <hint mintries="3">A third hint.</hint>\n\
  <mapping correct="1">\n\
    <match hotspot="A" />\n\
    <match hotspot="B" />\n\
    <feedback>Very Good, you pointed out the correct two items</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <match hotspot="C" />\n\
    <feedback>You have pointed out an incorrect item.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <not><match hotspot="A" /></not>\n\
    <feedback>You have not pointed out the first correct item.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <not>\n\
      <or>\n\
        <match hotspot="A" />\n\
        <match hotspot="B" />\n\
        <match hotspot="C" />\n\
      </or>\n\
    </not>\n\
    <feedback mintries="1">You have not selected any item.</feedback>\n\
  </mapping>\n\
</question>');
}

/**
 * Creates the xml for an empty hotspot question, loads it and switches to the
 * editor tab.
 */
function QC_CreateDD() {
  CQ_LoadTemplate('\
<question type="dragdrop">\n\
  <text>Drag the items to the corresponding locations on the image.</text>\n\
  <matchImg src="[attachurl:1]">\n\
    <hotspot shape="rect" coords="2,91,119,124" identifier="h1" />\n\
    <hotspot shape="circle" coords="6,196,123" identifier="h2" />\n\
    <hotspot shape="poly" coords="6,268,6,301,153,301,123,208" identifier="h3" />\n\
    <draggable identifier="d1">Draggable 1</draggable>\n\
    <draggable identifier="d2">Draggable 2</draggable>\n\
    <draggable identifier="d3">Draggable 3</draggable>\n\
  </matchImg>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <mapping correct="1">\n\
    <combination hotspot="h1" draggable="d1" />\n\
    <combination hotspot="h2" draggable="d2" />\n\
    <combination hotspot="h3" draggable="d3" />\n\
    <feedback>Correct. You have put the items at the right locations.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <combination hotspotpattern="h.*" draggablepattern="d[0-9]" />\n\
    <feedback>You have at least one draggable on one hotspot.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <combination hotspot="h1" draggablepattern="d[0-9]" />\n\
    <feedback>You have at least one draggable on hotspot 1.</feedback>\n\
  </mapping>\n\
  <mapping correct="0">\n\
    <combination hotspotpattern="h.*" draggable="d1" />\n\
    <feedback>You have draggable 1 on a hotspot.</feedback>\n\
  </mapping>\n\
</question>');
}

/**
 * Creates the xml for an empty FillBlanks question, loads it and switches to
 * the editor tab.
 */
function QC_CreateFB1() {
  CQ_LoadTemplate('\
<question type="fillblanks">\n\
  <matheval expression="a=random()" store="1" />\n\
  <matheval expression="b=random()" store="1" />\n\
  <matheval expression="a=round(a*0.8+0.11,2)" />\n\
  <matheval expression="b=round(b*5+2,0)" />\n\
  <matheval expression="ans=a*b" />\n\
  <matheval expression="min=ans-0.01" />\n\
  <matheval expression="max=ans+0.01" />\n\
  <text><p>You have measured a concentration of <mathresult expression="a" />mg/ml in a <mathresult expression="b" />-times diluted sample.<br/>\n\
What was the concentration in the non-diluted solution?</p>\n\
<p><b>The original concentration was: <inlineChoice identifier="c" freeform="1" />g/l</b></p></text>\n\
  <hint mintries="1">A first hint.</hint>\n\
  <hint mintries="2">A second hint.</hint>\n\
  <hint mintries="3">A third hint.</hint>\n\
  <mapping correct="1">\n\
    <range inlineChoice="c" minval="min" maxval="max" />\n\
    <feedback>Very good. The difference between your answer and the "real" answer is: <mathresult e="abs(ans-c)" /></feedback>\n\
  </mapping>\n\
  <mapping correct="0" stop="1">\n\
    <not><match inlineChoice="c" pattern="^[+-]?[0-9]+([,.][0-9]+)?([eE][+-]?[0-9]+)?$" /></not>\n\
    <feedback>Please give a number.</feedback>\n\
  </mapping>\n\
</question>');
}
