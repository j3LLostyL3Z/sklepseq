// midiMessageManager.h: interface for the midiMessageManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
#define AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_

#include <juce.h>

class midiMessage
{
	public:
		midiMessage (MidiMessage *_m, int _i)
		{
			m = _m;
			mB = 0;
			id = _i;
		};

		midiMessage (MidiBuffer *_mB, int _i)
		{
			mB = _mB;
			id = _i;
			m = 0;
		}

		MidiBuffer *mB;
		MidiMessage *m;
		int id;
};

class midiMessageManager  
{
	public:
		midiMessageManager();
		~midiMessageManager();
		void addMidiMessage (MidiMessage *msg, int device = 0);
		void addMidiBuffer (MidiBuffer *mBuf, int device = 0);
		void processMidiEvents ();
		MidiBuffer *getLeftMessages();

	private:
		StringArray midiOutputList;
		OwnedArray <midiMessage> m;
};

#endif // !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
