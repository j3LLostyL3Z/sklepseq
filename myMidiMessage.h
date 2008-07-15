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
		void setMidiMessageMulti (MidiBuffer midiBuffer);
		void setMidiMessageRaw (uint8 *data, int len);
		void setMidiDevice (int dId);
		void insertMidiMessage (MidiMessage midiMessage);
		bool isMulti();
		int getId();
		int getDeviceId();
		void setLength (short l);
		short getLength ();
		MidiMessage *getMidiMessage();
		MidiBuffer *getMidiBuffer();

		MidiMessage *m;
		MidiBuffer *mB;
		bool enabled;

	private:
		int id;
		int deviceId;
		int midiChannel;
		bool multi;
		short messageLength;
};

#endif // !defined(AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_)
