// myMidiMessage.cpp: implementation of the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#include "myMidiMessage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

myMidiMessage::myMidiMessage(int ch)
{
	multi		= false;
	m			= new MidiMessage (MidiMessage::noteOn (ch, 64, 1.0f));
	id			= 0;
	enabled		= false;
	midiChannel = ch;
}

myMidiMessage::~myMidiMessage()
{
}

void myMidiMessage::setMidiChannel (int ch)
{
	if (m)
	{
		m->setChannel (ch);
		midiChannel = ch;
	}
}

void myMidiMessage::setMidiMessage (MidiMessage midiMessage)
{
	multi	= false;
	m		= new MidiMessage (midiMessage);
	m->setChannel (midiChannel);

	uint8 *d = m->getRawData();
	Logger::writeToLog (String::formatted (T("%x:%x:%x"), *d, *(d+1), *(d+2)));
}

void myMidiMessage::setMidiMessageMulti (MidiBuffer midiBuffer)
{
	multi	= true;
	m		= 0;
	mB		= new MidiBuffer(midiBuffer);

	MidiBuffer::Iterator i (*mB);
	MidiMessage msg (0xf4, 0.0);
	int s;

	while (i.getNextEvent(msg,s))
	{
		uint8 *d = msg.getRawData();
		Logger::writeToLog (String::formatted (T("%x:%x:%x"), *d, *(d+1), *(d+2)));
	}
}

bool myMidiMessage::isMulti()
{
	return (multi);
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