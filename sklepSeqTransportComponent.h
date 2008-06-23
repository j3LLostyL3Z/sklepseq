/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  23 Jun 2008 2:06:24 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.11

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SKLEPSEQTRANSPORTCOMPONENT_SKLEPSEQTRANSPORTCOMPONENT_7DC855BB__
#define __JUCER_HEADER_SKLEPSEQTRANSPORTCOMPONENT_SKLEPSEQTRANSPORTCOMPONENT_7DC855BB__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
#include "sklepSeqMain.h"
#include "sklepSeqPlaylist.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class sklepSeqTransportComponent  : public Component,
                                    public SliderListener,
                                    public ButtonListener
{
public:
    //==============================================================================
    sklepSeqTransportComponent (DemoJuceFilter *_f);
    ~sklepSeqTransportComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setBpm (int b);
	void closePlaylist();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* rondw_05_png;
    static const int rondw_05_pngSize;
    static const char* rondw_07_png;
    static const int rondw_07_pngSize;
    static const char* rondw_09_png;
    static const int rondw_09_pngSize;
    static const char* rondw_10_png;
    static const int rondw_10_pngSize;
    static const char* rondw_11_png;
    static const int rondw_11_pngSize;
    static const char* rondw_11_1_png;
    static const int rondw_11_1_pngSize;
    static const char* rondw_05_1_png;
    static const int rondw_05_1_pngSize;
    static const char* rondw_07_1_png;
    static const int rondw_07_1_pngSize;
    static const char* rondw_09_1_png;
    static const int rondw_09_1_pngSize;
    static const char* rondw_10_1_png;
    static const int rondw_10_1_pngSize;
    static const char* playlist_png;
    static const int playlist_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	DemoJuceFilter *parent;
	sklepSeqPlaylist *playlist;
    //[/UserVariables]

    //==============================================================================
    Slider* bpmInput;
    ImageButton* puaseButton;
    ImageButton* playButton;
    ImageButton* stopButton;
    Label* bpmLabel;
    ToggleButton* syncToHost;
    ImageButton* playlistButton;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    sklepSeqTransportComponent (const sklepSeqTransportComponent&);
    const sklepSeqTransportComponent& operator= (const sklepSeqTransportComponent&);
};


#endif   // __JUCER_HEADER_SKLEPSEQTRANSPORTCOMPONENT_SKLEPSEQTRANSPORTCOMPONENT_7DC855BB__
