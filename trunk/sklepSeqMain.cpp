#include <juce.h>
#include "sklepSeqMain.h"
#include "sklepSeqEditor.h"


//==============================================================================
/**
    This function must be implemented to create a new instance of your
    plugin object.
*/
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DemoJuceFilter();
}

//==============================================================================
DemoJuceFilter::DemoJuceFilter()
{
	for (int x=0; x<32; x++)
		patterns.add (new sklepSeqPattern(x));

	patterns[0]->setActive (true);
	_p = 1;
	currentPattern = 0;
	currentPatternPtr = patterns[0];
	isSyncedToHost = true;

    zeromem (&lastPosInfo, sizeof (lastPosInfo));
    lastPosInfo.timeSigNumerator = 4;
    lastPosInfo.timeSigDenominator = 4;
    lastPosInfo.bpm = 120;
}

DemoJuceFilter::~DemoJuceFilter()
{
}

//==============================================================================
const String DemoJuceFilter::getName() const
{
    return "Juce Demo Filter";
}

int DemoJuceFilter::getNumParameters()
{
    return 1;
}

float DemoJuceFilter::getParameter (int index)
{
    return (index == 0) ? gain
                        : 0.0f;
}

void DemoJuceFilter::setParameter (int index, float newValue)
{
    if (index == 0)
    {
        if (gain != newValue)
        {
            gain = newValue;

            // if this is changing the gain, broadcast a change message which
            // our editor will pick up.
            sendChangeMessage (this);
        }
    }
}

const String DemoJuceFilter::getParameterName (int index)
{
    if (index == 0)
        return T("gain");

    return String::empty;
}

const String DemoJuceFilter::getParameterText (int index)
{
    if (index == 0)
        return String (gain, 2);

    return String::empty;
}

const String DemoJuceFilter::getInputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

const String DemoJuceFilter::getOutputChannelName (const int channelIndex) const
{
    return String (channelIndex + 1);
}

bool DemoJuceFilter::isInputChannelStereoPair (int index) const
{
    return false;
}

bool DemoJuceFilter::isOutputChannelStereoPair (int index) const
{
    return false;
}

bool DemoJuceFilter::acceptsMidi() const
{
    return true;
}

bool DemoJuceFilter::producesMidi() const
{
    return true;
}

//==============================================================================
void DemoJuceFilter::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // do your pre-playback setup stuff here..
    keyboardState.reset();
}

void DemoJuceFilter::releaseResources()
{
    // when playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void DemoJuceFilter::processBlock (AudioSampleBuffer& buffer,
                                   MidiBuffer& midiMessages)
{
    // have a go at getting the current time from the host, and if it's changed, tell
    // our UI to update itself.
	if (isSyncedToHost)
	{
		AudioPlayHead::CurrentPositionInfo pos;

		if (getPlayHead() != 0 && getPlayHead()->getCurrentPosition (pos))
		{
	        if (memcmp (&pos, &lastPosInfo, sizeof (pos)) != 0)
			{
	            lastPosInfo = pos;

				const int ppqPerBar		= (pos.timeSigNumerator * 4 / pos.timeSigDenominator);
				const double beats		= (fmod (pos.ppqPosition, ppqPerBar) / ppqPerBar) * pos.timeSigNumerator;
				const double position	= beats*4;
				const int beat			= (int)position;
				
				currentBpm	= (int)pos.bpm;

				if (_p != beat)
				{
					currentPatternPtr->forward(beat+1);
					currentBeat = currentPatternPtr->getCurrentPosition();

					if (currentBeat > 16)
						currentBeat = currentBeat - 16;

					sendChangeMessage (this);
				}
				
				_p = beat;
			}
		}
		else
		{
	        zeromem (&lastPosInfo, sizeof (lastPosInfo));
			lastPosInfo.timeSigNumerator = 4;
	        lastPosInfo.timeSigDenominator = 4;
			lastPosInfo.bpm = 120;
	   }	
	}
}

//==============================================================================
AudioProcessorEditor* DemoJuceFilter::createEditor()
{
    return new DemoEditorComponent (this);
}

//==============================================================================
void DemoJuceFilter::getStateInformation (MemoryBlock& destData)
{
    XmlElement xmlState (T("MYPLUGINSETTINGS"));

    // add some attributes to it..
    xmlState.setAttribute (T("pluginVersion"), 1);
    xmlState.setAttribute (T("gainLevel"), gain);

    // you could also add as many child elements as you need to here..


    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xmlState, destData);
}

void DemoJuceFilter::setStateInformation (const void* data, int sizeInBytes)
{
    // use this helper function to get the XML from this binary blob..
    XmlElement* const xmlState = getXmlFromBinary (data, sizeInBytes);

    if (xmlState != 0)
    {
        // check that it's the right type of xml..
        if (xmlState->hasTagName (T("MYPLUGINSETTINGS")))
        {
            // ok, now pull out our parameters..
            gain = (float) xmlState->getDoubleAttribute (T("gainLevel"), gain);

            sendChangeMessage (this);
        }

        delete xmlState;
    }
}

sklepSeqPattern *DemoJuceFilter::getCurrentPattern()
{
	return (currentPatternPtr);
}

void DemoJuceFilter::setCurrentPattern (int p)
{
	if (patterns[p])
	{
		currentPatternPtr = patterns[p];
		currentPattern = p;
	}
	else
	{
		currentPatternPtr = patterns[0];
		currentPattern = 0;
	}
}

void DemoJuceFilter::setSyncToHost (bool t)
{
	if (t != isSyncedToHost)
	{
		zeromem (&lastPosInfo, sizeof (lastPosInfo));
		lastPosInfo.timeSigNumerator = 4;
		lastPosInfo.timeSigDenominator = 4;
		lastPosInfo.bpm = 120;

		sendChangeMessage (this);
	}
	
	isSyncedToHost = t;
}

bool DemoJuceFilter::getSyncToHost ()
{
	return (isSyncedToHost);
}