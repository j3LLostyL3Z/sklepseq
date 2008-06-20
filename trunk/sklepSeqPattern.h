// sklepSeqPattern.h: interface for the sklepSeqPattern class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKLEPSEQPATTERN_H__F277BDA6_FA04_4DC5_8E91_89AF43BE3A54__INCLUDED_)
#define AFX_SKLEPSEQPATTERN_H__F277BDA6_FA04_4DC5_8E91_89AF43BE3A54__INCLUDED_

#include <juce.h>
#include "midiMessageManager.h"

class midiMessage2
{
	public:
		midiMessage2()
		{
			m = new MidiMessage (MidiMessage::noteOn (1, 64, 1.0f));
			id = 0;
			enabled = false;
		};
		MidiMessage *m;
		int id;
		bool enabled;
};

class sklepSeqPattern  : public Component
{
	public:
		sklepSeqPattern(int _id);
		~sklepSeqPattern();
		bool fromXml (XmlElement *e);
		void setMidiData (MidiBuffer b);
		void setMidiEvent (int n, MidiMessage note);
		MidiMessage *getMidiEvent (int n);
		int getPatternId();
		int getPatternLength();
		void setPatternLength(int len);
		void forward(int pos);
		void setActive (bool t);
		bool getActive();
		int getCurrentPosition();
		enum patternMode
		{
			patternForward,
			patternReverse,
			patternRandom
		};
		void addMidiManager (midiMessageManager *m);
		void triggerEvents ();
		void setStep (int nId, int nNumber, float nVelo);
		MidiMessage* getStep (int nId);
		void toggleStep(int nId);

	private:
		int patternLength;
		int patternId;
		int currentPosition;
		int previousPosition;
		bool isActive;
		short mode;
		bool patternHasBeenActivated;
		midiMessageManager *midiManager;
		int midiChannel;
		OwnedArray <midiMessage2> notes;
};

#endif // !defined(AFX_SKLEPSEQPATTERN_H__F277BDA6_FA04_4DC5_8E91_89AF43BE3A54__INCLUDED_)
