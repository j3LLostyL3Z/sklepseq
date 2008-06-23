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

#ifndef __JUCER_HEADER_SKLEPSEQPLAYLIST_SKLEPSEQPLAYLIST_C0CEEDD__
#define __JUCER_HEADER_SKLEPSEQPLAYLIST_SKLEPSEQPLAYLIST_C0CEEDD__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class sklepSeqPlaylist  : public Component
{
public:
    //==============================================================================
    sklepSeqPlaylist ();
    ~sklepSeqPlaylist();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    Viewport* playlist;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    sklepSeqPlaylist (const sklepSeqPlaylist&);
    const sklepSeqPlaylist& operator= (const sklepSeqPlaylist&);
};


#endif   // __JUCER_HEADER_SKLEPSEQPLAYLIST_SKLEPSEQPLAYLIST_C0CEEDD__
