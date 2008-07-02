// myMidiMessage.cpp: implementation of the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#include "myMidiMessage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

myMidiMessage::myMidiMessage(int ch)
{
	m = new MidiMessage (MidiMessage::noteOn (ch, 64, 1.0f));
	id = 0;
	enabled = false;
}

myMidiMessage::~myMidiMessage()
{
}

void myMidiMessage::setMidiChannel (int ch)
{
	if (m)
	{
		m->setChannel (ch);
	}
}

void myMidiMessage::setMidiMessage (MidiMessage midiMessage)
{
	const int ch = m->getChannel();
	m = new MidiMessage (midiMessage);

	if (!m->isSysEx())
		m->setChannel (ch);
}

MidiMessage *myMidiMessage::getMidiMessage()
{
	if (m)
	{
		return (m);
	}
	else
	{
		return (0);
	}
}