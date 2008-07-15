// myMidiMessage.cpp: implementation of the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#include "myMidiMessage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

myMidiMessage::myMidiMessage(int ch)
{
	multi			= false;
	m				= new MidiMessage (MidiMessage::noteOn (ch, 64, 1.0f));
	mB				= 0;
	id				= 0;
	messageLength	= 1;
	enabled			= false;
	midiChannel		= ch;
	deviceId		= 0;
}

myMidiMessage::~myMidiMessage()
{
}

/* append a midi message as the first one on stack
	if the message is a single message, make it a multi
*/
void myMidiMessage::insertMidiMessage (MidiMessage midiMessage)
{
	if (isMulti())
	{
		MidiBuffer copy;
		MidiBuffer::Iterator i (*mB);
		MidiMessage msg(0xf0, 0.0);
		int pos;

		copy.addEvent (midiMessage, 0);

		while (i.getNextEvent (msg, pos))
		{
			copy.addEvent (msg, pos+1);
		}

		if (mB)
			deleteAndZero (mB);

		mB = new MidiBuffer (copy);
	}
	else
	{
		multi = true;
		MidiBuffer copy;

		copy.addEvent (midiMessage, 0);
		copy.addEvent (*m, 1);

		mB = new MidiBuffer (copy);

		deleteAndZero (m);
	}
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
	if (mB)
		deleteAndZero (mB);

	if (!m->isSysEx())
	{
		m->setChannel (midiChannel);
	}
}

void myMidiMessage::setMidiMessageRaw (uint8 *data, int dataLen)
{
	multi	= false;
	m		= new MidiMessage (data, dataLen, 0);


	if (m)
	{
		uint8 *d = m->getRawData();
		int len  = m->getRawDataSize();

		String t;
		for (int x=0; x<len; x++)
		{
			if (x==0)
				t << String::formatted (T("%x"), *(d+x));
			else
				t << String::formatted (T(":%x"), *(d+x));
		}

		Logger::writeToLog (t);
	}
}

void myMidiMessage::setMidiMessageMulti (MidiBuffer midiBuffer)
{
	multi	= true;
	if (m)
		deleteAndZero (m);

	m		= 0;
	mB		= new MidiBuffer(midiBuffer);
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

MidiBuffer *myMidiMessage::getMidiBuffer()
{
	if (mB)
	{
		return (mB);
	}
	else
	{
		return (0);
	}
}

int myMidiMessage::getId()
{
	return (id);
}

void myMidiMessage::setMidiDevice (int dId)
{
	if (deviceId < 0)
	{
		deviceId = 0;
		return;
	}

	deviceId = dId;
}

int myMidiMessage::getDeviceId ()
{
	return (deviceId);
}

void myMidiMessage::setLength (short l)
{
	messageLength = l;
}

short myMidiMessage::getLength ()
{
	return (messageLength);
}