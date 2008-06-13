/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  13 Jun 2008 3:41:28 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SKLEPSEQMAINCOMPONENT_SKLEPSEQMAINCOMPONENT_5C6BCF58__
#define __JUCER_HEADER_SKLEPSEQMAINCOMPONENT_SKLEPSEQMAINCOMPONENT_5C6BCF58__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
#include "sklepSeqCursorComponent.h"
#include "sklepSeqMain.h"
//[/Headers]

#include "sklepSeqTransportComponent.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class sklepSeqMainComponent  : public Component,
                               public AsyncUpdater
{
public:
    //==============================================================================
    sklepSeqMainComponent (DemoJuceFilter *f);
    ~sklepSeqMainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setPosition (AudioPlayHead::CurrentPositionInfo pos);
    void handleAsyncUpdate();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* sq_back_png;
    static const int sq_back_pngSize;
    static const char* sq_nazwa_png;
    static const int sq_nazwa_pngSize;
    static const char* sq_kursor_1_png;
    static const int sq_kursor_1_pngSize;
    static const char* sq_kursor_2_png;
    static const int sq_kursor_2_pngSize;
    static const char* sq_kursor_3_png;
    static const int sq_kursor_3_pngSize;
    static const char* sq_kursor_4_png;
    static const int sq_kursor_4_pngSize;
    static const char* sq_kursor_5_png;
    static const int sq_kursor_5_pngSize;
    static const char* sq_kursor_6_png;
    static const int sq_kursor_6_pngSize;
    static const char* sq_kursor_7_png;
    static const int sq_kursor_7_pngSize;
    static const char* sq_kursor_8_png;
    static const int sq_kursor_8_pngSize;
    static const char* sq_kursor_9_png;
    static const int sq_kursor_9_pngSize;
    static const char* sq_kursor_10_png;
    static const int sq_kursor_10_pngSize;
    static const char* sq_kursor_11_png;
    static const int sq_kursor_11_pngSize;
    static const char* sq_kursor_12_png;
    static const int sq_kursor_12_pngSize;
    static const char* sq_kursor_13_png;
    static const int sq_kursor_13_pngSize;
    static const char* sq_kursor_14_png;
    static const int sq_kursor_14_pngSize;
    static const char* sq_kursor_15_png;
    static const int sq_kursor_15_pngSize;
    static const char* sq_kursor_16_png;
    static const int sq_kursor_16_pngSize;
    static const char* sq_step_off_1_png;
    static const int sq_step_off_1_pngSize;
    static const char* sq_step_off_2_png;
    static const int sq_step_off_2_pngSize;
    static const char* sq_step_off_3_png;
    static const int sq_step_off_3_pngSize;
    static const char* sq_step_off_4_png;
    static const int sq_step_off_4_pngSize;
    static const char* sq_step_off_5_png;
    static const int sq_step_off_5_pngSize;
    static const char* sq_step_off_6_png;
    static const int sq_step_off_6_pngSize;
    static const char* sq_step_off_7_png;
    static const int sq_step_off_7_pngSize;
    static const char* sq_step_off_8_png;
    static const int sq_step_off_8_pngSize;
    static const char* sq_step_off_9_png;
    static const int sq_step_off_9_pngSize;
    static const char* sq_step_off_10_png;
    static const int sq_step_off_10_pngSize;
    static const char* sq_step_off_11_png;
    static const int sq_step_off_11_pngSize;
    static const char* sq_step_off_12_png;
    static const int sq_step_off_12_pngSize;
    static const char* sq_step_off_13_png;
    static const int sq_step_off_13_pngSize;
    static const char* sq_step_off_14_png;
    static const int sq_step_off_14_pngSize;
    static const char* sq_step_off_15_png;
    static const int sq_step_off_15_pngSize;
    static const char* sq_step_off_16_png;
    static const int sq_step_off_16_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	OwnedArray <sklepSeqCursorComponent> cursor;
	DemoJuceFilter *ownerFilter;
	int prevPos;
    //[/UserVariables]

    //==============================================================================
    sklepSeqTransportComponent* transportComponent;
    Label* positionLabel;
    Image* internalCachedImage1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    sklepSeqMainComponent (const sklepSeqMainComponent&);
    const sklepSeqMainComponent& operator= (const sklepSeqMainComponent&);
};


#endif   // __JUCER_HEADER_SKLEPSEQMAINCOMPONENT_SKLEPSEQMAINCOMPONENT_5C6BCF58__
