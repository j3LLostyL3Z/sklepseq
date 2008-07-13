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
	deviceId	= 0;
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
	if (!m->isSysEx())
	{
		m->setChannel (midiChannel);
	}

	uint8 *d = m->getRawData();
	Logger::writeToLog (String::formatted (T("%x:%x:%x"), *d, *(d+1), *(d+2)));
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