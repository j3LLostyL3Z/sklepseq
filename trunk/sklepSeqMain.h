#ifndef XCLOCK_H
#define XCLOCK_H

#include "xSync.h"

class sklepSeqMain  : public AudioProcessor, public ChangeBroadcaster, public ChangeListener
{
public:
    sklepSeqMain();
    ~sklepSeqMain();
    enum
    {
		kBitDepth,
		kSampleRate
    };

	/* VST specific */
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    AudioProcessorEditor* createEditor();
    const String getName() const;
    int getNumParameters();
    float getParameter (int index);
    void setParameter (int index, float newValue);
    const String getParameterName (int index);
    const String getParameterText (int index);
    const String getInputChannelName (const int channelIndex) const;
    const String getOutputChannelName (const int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    bool acceptsMidi() const;
    bool producesMidi() const;
    int getNumPrograms()                                        { return 0; }
    int getCurrentProgram()                                     { return 0; }
    void setCurrentProgram (int index)                          { }
    const String getProgramName (int index)                     { return String::empty; }
    void changeProgramName (int index, const String& newName)   { }
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
	/* end VST specific methods */

	/* seq specific methods */
	void setBPM (unsigned int t);
	unsigned int getBPM ();
	void stop();
	void start();
	bool isPlaying();
	void changeListenerCallback (void *ptr);
	/* end seq specific methods */

    juce_UseDebuggingNewOperator

private:
	AudioPlayHead::CurrentPositionInfo lastPosInfo;
	unsigned int bpm;
	xsync *sync;
	bool isSyncedToHost;
};

#endif
