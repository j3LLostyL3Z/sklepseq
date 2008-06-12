#ifndef __JUCE_PLUGIN_CHARACTERISTICS_H__
#define __JUCE_PLUGIN_CHARACTERISTICS_H__

#define JucePlugin_Name                     "xclock generator"
#define JucePlugin_Desc                     "midi clock source"
#define JucePlugin_Manufacturer             "sndlab.com"
#define JucePlugin_ManufacturerCode         'SndL'
#define JucePlugin_PluginCode               'xloc'
#define JucePlugin_MaxNumInputChannels              0
#define JucePlugin_MaxNumOutputChannels             0
#define JucePlugin_PreferredChannelConfigurations   { 1, 1 }, { 2, 2 }
#define JucePlugin_IsSynth                          1
#define JucePlugin_WantsMidiInput                   0
#define JucePlugin_ProducesMidiOutput               1
#define JucePlugin_SilenceInProducesSilenceOut      0
#define JucePlugin_EditorRequiresKeyboardFocus      1
#define JucePlugin_VersionCode              0x00010100
#define JucePlugin_VersionString            "1.1"
#define JUCE_USE_VSTSDK_2_4                 1
#define JucePlugin_VSTUniqueID              JucePlugin_PluginCode
#if JucePlugin_IsSynth
  #define JucePlugin_VSTCategory            kPlugCategSynth
#else
  #define JucePlugin_VSTCategory            kPlugCategEffect
#endif

#endif
