/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  2 Jul 2008 2:39:19 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "stepEditController.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
stepEditController::stepEditController (myMidiMessage *msg)
    : slider (0),
      slider2 (0),
      label (0),
      label2 (0)
{
    addAndMakeVisible (slider = new Slider (T("new slider")));
    slider->setRange (1, 16564, 1);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider (T("new slider")));
    slider2->setRange (1, 16564, 1);
    slider2->setSliderStyle (Slider::IncDecButtons);
    slider2->setTextBoxStyle (Slider::TextBoxLeft, false, 35, 20);
    slider2->addListener (this);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Controller Value")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Controller Number")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (112, 224);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

stepEditController::~stepEditController()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (slider);
    deleteAndZero (slider2);
    deleteAndZero (label);
    deleteAndZero (label2);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void stepEditController::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void stepEditController::resized()
{
    slider->setBounds (0, 32, 112, 112);
    slider2->setBounds (4, 176, 108, 24);
    label->setBounds (4, 8, 104, 24);
    label2->setBounds (4, 152, 104, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void stepEditController::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="stepEditController" componentName=""
                 parentClasses="public Component" constructorParams="myMidiMessage *msg"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="1" initialWidth="112"
                 initialHeight="224">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="594ba86bfe4c9ed5" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="0 32 112 112" min="1" max="16564"
          int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="6ce30323c5dbf062" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="4 176 108 24" min="1"
          max="16564" int="1" style="IncDecButtons" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="35" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6682b679404c2a6e" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="4 8 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Controller Value" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a92dafe37c5039b7" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="4 152 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Controller Number" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
