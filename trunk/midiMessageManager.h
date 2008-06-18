// midiMessageManager.h: interface for the midiMessageManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
#define AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_

#include <juce.h>

class midiMessageManager  
{
	public:
		midiMessageManager();
		~midiMessageManager();
		void addMidiMessage (MidiMessage *msg, int device = 0);
		void addMidiBuffer (MidiBuffer *mBuf, int device = 0);
		void processMidiEvents (MidiBuffer *outputBuffer = 0, int device = 0);

	private:
		StringArray midiOutputList;
		MidiBuffer pendingMessages;
};

#endif // !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
