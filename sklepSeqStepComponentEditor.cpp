/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  18 Jun 2008 9:23:13 pm

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

#include "sklepSeqStepComponentEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
sklepSeqStepComponentEditor::sklepSeqStepComponentEditor (sklepSeqStep *parent)
    : keyboardCmp (0)
{
    addAndMakeVisible (keyboardCmp = new MidiKeyboardComponent (*parent,MidiKeyboardComponent::horizontalKeyboard ));
    keyboardCmp->setName (T("Keyboard"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (256, 92);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

sklepSeqStepComponentEditor::~sklepSeqStepComponentEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (keyboardCmp);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void sklepSeqStepComponentEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.setColour (Colour (0x6cffffff));
    g.fillRoundedRectangle (0.0f, 0.0f, 256.0f, 92.0f, 10.5000f);

    g.setColour (Colour (0xffcfcfcf));
    g.drawRoundedRectangle (0.0f, 0.0f, 256.0f, 92.0f, 10.5000f, 1.0000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void sklepSeqStepComponentEditor::resized()
{
    keyboardCmp->setBounds (8, 40, 240, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="sklepSeqStepComponentEditor"
                 componentName="" parentClasses="public Component" constructorParams="sklepSeqStep *parent"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="1" initialWidth="256"
                 initialHeight="92">
  <BACKGROUND backgroundColour="ffffff">
    <ROUNDRECT pos="0 0 256 92" cornerSize="10.5" fill="solid: 6cffffff" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffcfcfcf"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="Keyboard" id="3f760baf8d941098" memberName="keyboardCmp"
                    virtualName="" explicitFocusOrder="0" pos="8 40 240 48" class="MidiKeyboardComponent"
                    params="*parent,MidiKeyboardComponent::horizontalKeyboard "/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
