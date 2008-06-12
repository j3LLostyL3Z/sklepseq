/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  12 Jun 2008 12:46:52 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SKLEPSEQEDITOR_SKLEPSEQEDITOR_2379827__
#define __JUCER_HEADER_SKLEPSEQEDITOR_SKLEPSEQEDITOR_2379827__

//[Headers]     -- You can add your own extra header files here --
#include <juce.h>
#include "sklepSeqMain.h"
//[/Headers]

#include "sklepSeqMainComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class sklepSeqEditor  : public AudioProcessorEditor,
                        public ChangeListener,
                        public SliderListener,
                        public AsyncUpdater
{
public:
    //==============================================================================
    sklepSeqEditor (sklepSeqMain *owner, xsync *syncThread);
    ~sklepSeqEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback (void* source);
    sklepSeqMain* getFilter() const throw()       { return (sklepSeqMain*) getAudioProcessor(); }
	void handleAsyncUpdate();
	void sliderValueChanged (Slider *s);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* pause_png;
    static const int pause_pngSize;
    static const char* play_png;
    static const int play_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	xsync *sync;
    //[/UserVariables]

    //==============================================================================
    sklepSeqMainComponent* seqMain;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    sklepSeqEditor (const sklepSeqEditor&);
    const sklepSeqEditor& operator= (const sklepSeqEditor&);
};


#endif   // __JUCER_HEADER_SKLEPSEQEDITOR_SKLEPSEQEDITOR_2379827__
