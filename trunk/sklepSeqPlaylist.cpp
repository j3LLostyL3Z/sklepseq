/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jun 2008 1:55:25 pm

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

#include "sklepSeqPlaylist.h"
#include "sklepSeqPlaylistComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
sklepSeqPlaylist::sklepSeqPlaylist ()
    : playlist (0)
{
    addAndMakeVisible (playlist = new Viewport (String::empty));
    playlist->setViewedComponent (new sklepSeqPlaylistComponent());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

sklepSeqPlaylist::~sklepSeqPlaylist()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (playlist);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void sklepSeqPlaylist::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void sklepSeqPlaylist::resized()
{
    playlist->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
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

<JUCER_COMPONENT documentType="Component" className="sklepSeqPlaylist" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <VIEWPORT name="" id="f9a572f83cace14c" memberName="playlist" virtualName=""
            explicitFocusOrder="0" pos="0 0 100% 100%" vscroll="1" hscroll="1"
            scrollbarThickness="18" contentType="1" jucerFile="sklepSeqPlaylistComponent.cpp"
            contentClass="" constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
