// myMidiMessage.cpp: implementation of the myMidiMessage class.
//
//////////////////////////////////////////////////////////////////////

#include "myMidiMessage.h"
#include "sklepSeqPattern.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

myMidiMessage::myMidiMessage(int ch, int nIndex, sklepSeqPattern *owner)
{
	multi			= false;
	m				= new MidiMessage (MidiMessage::noteOn (ch, 64, 1.0f));
	mB				= 0;
	index			= nIndex;
	messageLength	= 1;
	enabled			= false;
	midiChannel		= ch;
	deviceId		= 0;
	ownerPattern	= owner;
}

myMidiMessage::~myMidiMessage()
{
}

void myMidiMessage::setOwner (sklepSeqPattern *owner)
{
	ownerPattern = owner;
}

Array <myMidiMessage *>*myMidiMessage::getExtraEvents()
{
	return (&extraMessages);
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

int myMidiMessage::getIndex()
{
	return (index);
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
	if (l != messageLength)
	{
		/* midi len changed */
		myMidiMessage *noteOffMessage = ownerPattern->getStep (getMyNoteOff());

		/* remove my note off */
		noteOffMessage->removeExtra (noteOff);

		/* set new length */
		messageLength = l;

		/* add my new note off based on my new length */
		noteOffMessage = ownerPattern->getStep (getMyNoteOff());
		if (noteOff)
		{
			/* we can do this, the array in the note off event is not a ownedArray */
			deleteAndZero (noteOff);
		}

		noteOff = new myMidiMessage (midiChannel, 1, ownerPattern);
		noteOff->setMidiMessage (MidiMessage::noteOff (midiChannel, m->getNoteNumber()));
		noteOffMessage->addExtra (noteOff);
	}
}

short myMidiMessage::getLength ()
{
	return (messageLength);
}

short myMidiMessage::getMyNoteOff()
{
	if (messageLength+index < 32)
	{
		return (messageLength+(index+1));
	}
	else
	{
		/* d0h */
		return ((32 - (index+1))+messageLength);
	}
}

void myMidiMessage::removeExtra (myMidiMessage *m)
{
	extraMessages.removeValue (m);
}

void myMidiMessage::addExtra(myMidiMessage *m)
{
	extraMessages.add (m);
}