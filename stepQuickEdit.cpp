/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  1 Jul 2008 2:05:57 pm

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
#include "sklepSeqMainComponent.h"
//[/Headers]

#include "stepQuickEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
stepQuickEdit::stepQuickEdit (sklepSeqMainComponent *parent, MidiMessage *msg)
    : veloSlider (0),
      midiKeyboardComponent (0)
{
    addAndMakeVisible (veloSlider = new Slider (T("Velocity")));
    veloSlider->setTooltip (T("Velocity"));
    veloSlider->setRange (1, 127, 1);
    veloSlider->setSliderStyle (Slider::LinearVertical);
    veloSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    veloSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    veloSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffffff));
    veloSlider->addListener (this);

    addAndMakeVisible (midiKeyboardComponent = new MidiKeyboardComponent (midiKeyboardState, MidiKeyboardComponent::verticalKeyboardFacingRight));
    midiKeyboardComponent->setName (T("new component"));


    //[UserPreSize]
	if (msg)
	{
		veloSlider->setValue (msg->getVelocity(), false);
	}
	midiKeyboardState.addListener (parent);
    //[/UserPreSize]

    setSize (96, 272);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

stepQuickEdit::~stepQuickEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (veloSlider);
    deleteAndZero (midiKeyboardComponent);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void stepQuickEdit::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    GradientBrush gradient_1 (Colour (0xad353535),
                              56.0f, 0.0f,
                              Colours::black,
                              56.0f, 256.0f,
                              false);
    g.setBrush (&gradient_1);
    g.fillRoundedRectangle (0.0f, 16.0f, 96.0f, 256.0f, 10.0000f);

    //[UserPaint] Add your own custom painting code here..
	LookAndFeel::drawGlassLozenge (g, 0, 0, 96, 16, Colour(64,64,64).withAlpha (0.8f), 0.0f, 5.0f, false, false, false, true);
    //[/UserPaint]
}

void stepQuickEdit::resized()
{
    veloSlider->setBounds (72, 16, 24, 256);
    midiKeyboardComponent->setBounds (0, 16, 72, 256);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void stepQuickEdit::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == veloSlider)
    {
        //[UserSliderCode_veloSlider] -- add your slider handling code here..
        //[/UserSliderCode_veloSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void stepQuickEdit::mouseDown (const MouseEvent& e)
{
	myDragger.startDraggingComponent (this, 0);
}

void stepQuickEdit::mouseDrag (const MouseEvent& e)
{
	myDragger.dragComponent (this, e);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="stepQuickEdit" componentName=""
                 parentClasses="public Component" constructorParams="sklepSeqMainComponent *parent, MidiMessage *msg"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="1" initialWidth="96"
                 initialHeight="272">
  <BACKGROUND backgroundColour="ff6262">
    <ROUNDRECT pos="0 16 96 256" cornerSize="10" fill="linear: 56 0, 56 256, 0=ad353535, 1=ff000000"
               hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Velocity" id="946772637523ebbb" memberName="veloSlider"
          virtualName="" explicitFocusOrder="0" pos="72 16 24 256" tooltip="Velocity"
          textboxtext="ffffffff" textboxbkgd="ffffff" min="1" max="127"
          int="1" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="new component" id="9427308f14b9d83e" memberName="midiKeyboardComponent"
                    virtualName="" explicitFocusOrder="0" pos="0 16 72 256" class="MidiKeyboardComponent"
                    params="midiKeyboardState, MidiKeyboardComponent::verticalKeyboardFacingRight"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
