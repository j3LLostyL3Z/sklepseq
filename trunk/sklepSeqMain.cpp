#include <juce.h>
#include "sklepSeqMain.h"
#include "sklepSeqEditor.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new sklepSeqMain();
}

sklepSeqMain::sklepSeqMain()
{
	bpm = 120;
	isSyncedToHost = false;

	zeromem (&lastPosInfo, sizeof (lastPosInfo));
    lastPosInfo.timeSigNumerator = 4;
    lastPosInfo.timeSigDenominator = 4;
    lastPosInfo.bpm = 120;

	sync = new xsync();
	sync->addChangeListener (this);
	sync->setBPM (120);
}

sklepSeqMain::~sklepSeqMain()
{
	sync->stopThread (100);
	deleteAndZero (sync);
}

const String sklepSeqMain::getName() const
{
    return "xclock generator";
}

int sklepSeqMain::getNumParameters()
{
    return (0);
}

float sklepSeqMain::getParameter (int index)
{
	return (0.0);
}

void sklepSeqMain::setParameter (int index, float newValue)
{
}

const String sklepSeqMain::getParameterName (int index)
{
	return String::empty;
}

const String sklepSeqMain::getParameterText (int index)
{
	return String::empty;
}

const String sklepSeqMain::getInputChannelName (const int channelIndex) const
{
    return String::empty;
}

const String sklepSeqMain::getOutputChannelName (const int channelIndex) const
{
    return String::empty;
}

bool sklepSeqMain::isInputChannelStereoPair (int index) const
{
    return false;
}

bool sklepSeqMain::isOutputChannelStereoPair (int index) const
{
    return false;
}

bool sklepSeqMain::acceptsMidi() const
{
    return false;
}

bool sklepSeqMain::producesMidi() const
{
    return true;
}

void sklepSeqMain::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void sklepSeqMain::releaseResources()
{
}

void sklepSeqMain::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	AudioPlayHead::CurrentPositionInfo pos;

    if (getPlayHead() != 0 && getPlayHead()->getCurrentPosition (pos) && isSyncedToHost)
    {
        if (memcmp (&pos, &lastPosInfo, sizeof (pos)) != 0)
        {
            lastPosInfo = pos;
            sendChangeMessage (this);
        }
    }
    else
    {
        zeromem (&lastPosInfo, sizeof (lastPosInfo));
        lastPosInfo.timeSigNumerator = 4;
        lastPosInfo.timeSigDenominator = 4;
        lastPosInfo.bpm = 120;
    }

	MidiBuffer::Iterator i (midiMessages);
	MidiMessage message (0xf4, 0.0);
    int time;

    while (i.getNextEvent (message, time))
	{
		if (message.isNoteOn() || message.isNoteOff())
		{
		}
	}

	return;
}

AudioProcessorEditor* sklepSeqMain::createEditor()
{
	sklepSeqEditor *e = new sklepSeqEditor (this, sync);
	sync->setGui (e);

    return e;
}

void sklepSeqMain::getStateInformation (MemoryBlock& destData)
{
}

void sklepSeqMain::setStateInformation (const void* data, int sizeInBytes)
{
}

void sklepSeqMain::setBPM (unsigned int t)
{
	bpm = t;

	if (sync)
		sync->setBPM (bpm);
}

unsigned int sklepSeqMain::getBPM()
{
	return (bpm);
}

void sklepSeqMain::start()
{
	sync->startThread();
}

void sklepSeqMain::stop()
{
	if (sync->isThreadRunning())
		sync->stopThread (20);
}

bool sklepSeqMain::isPlaying()
{
	return (sync->isThreadRunning());
}

void sklepSeqMain::changeListenerCallback (void *ptr)
{
}