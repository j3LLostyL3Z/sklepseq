// myMidiMessage.h: interface for the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_)
#define AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_

#include <juce.h>
class sklepSeqPattern;

class myMidiMessage
{
	public:
		myMidiMessage(int ch, int nIndex, sklepSeqPattern *owner);
		~myMidiMessage();

		void setMidiChannel (int ch);
		void setMidiMessage (MidiMessage midiMessage);
		void setMidiMessageMulti (MidiBuffer midiBuffer);
		void setMidiMessageRaw (uint8 *data, int len);
		void setMidiDevice (int dId);
		void insertMidiMessage (MidiMessage midiMessage);
		bool isMulti();
		int getIndex();
		int getDeviceId();
		void setLength (short l);
		short getLength ();
		short getMyNoteOff();
		MidiMessage *getMidiMessage();
		MidiBuffer *getMidiBuffer();
		Array <myMidiMessage *>*getExtraEvents();
		void setOwner (sklepSeqPattern *owner);
		void removeExtra (myMidiMessage *m);
		void addExtra(myMidiMessage *m);

		MidiMessage *m;
		MidiBuffer *mB;
		bool enabled;
		myMidiMessage *noteOff;

	private:
		int id;
		int deviceId;
		int midiChannel;
		bool multi;
		int index;
		short messageLength;
		Array <myMidiMessage *>extraMessages;
		sklepSeqPattern *ownerPattern;
};

#endif // !defined(AFX_MYMIDIMESSAGE_H__34252E74_5689_4D69_9892_8CCF3ACE31E4__INCLUDED_)
