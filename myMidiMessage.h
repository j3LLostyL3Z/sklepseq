// myMidiMessage.h: interface for the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_)
#define AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_

#include <juce.h>

class myMidiMessage
{
	public:
		myMidiMessage(int ch);
		~myMidiMessage();

		void setMidiChannel (int ch);
		void setMidiMessage (MidiMessage midiMessage);
		MidiMessage *getMidiMessage();

		MidiMessage *m;
		bool enabled;

	private:
		int id;
};

#endif // !defined(AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_)
