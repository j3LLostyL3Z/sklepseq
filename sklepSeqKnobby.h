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

#ifndef __JUCER_HEADER_SKLEPSEQKNOBBY_SKLEPSEQKNOBBY_95899B55__
#define __JUCER_HEADER_SKLEPSEQKNOBBY_SKLEPSEQKNOBBY_95899B55__

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
class sklepSeqKnobby  : public Component,
                        public SliderListener
{
public:
    //==============================================================================
    sklepSeqKnobby ();
    ~sklepSeqKnobby();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    Slider* slider;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    sklepSeqKnobby (const sklepSeqKnobby&);
    const sklepSeqKnobby& operator= (const sklepSeqKnobby&);
};


#endif   // __JUCER_HEADER_SKLEPSEQKNOBBY_SKLEPSEQKNOBBY_95899B55__
