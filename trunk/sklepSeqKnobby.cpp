/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  10 Jul 2008 11:03:26 pm

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

#include "sklepSeqKnobby.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
sklepSeqKnobby::sklepSeqKnobby ()
    : slider (0)
{
    addAndMakeVisible (slider = new Slider (T("new slider")));
    slider->setRange (1, 256, 1);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 24, 14);
    slider->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    slider->setColour (Slider::textBoxTextColourId, Colours::black);
    slider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (492, 492);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

sklepSeqKnobby::~sklepSeqKnobby()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (slider);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void sklepSeqKnobby::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x93000000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void sklepSeqKnobby::resized()
{
    slider->setBounds (32, 24, 48, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void sklepSeqKnobby::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
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

<JUCER_COMPONENT documentType="Component" className="sklepSeqKnobby" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="492" initialHeight="492">
  <BACKGROUND backgroundColour="93000000"/>
  <SLIDER name="new slider" id="95cc8fd1b4f9fae3" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="32 24 48 56" rotaryslideroutline="ff000000"
          textboxtext="ff000000" min="1" max="256" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="24"
          textBoxHeight="14" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
