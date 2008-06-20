// midiMessageManager.cpp: implementation of the midiMessageManager class.
//
//////////////////////////////////////////////////////////////////////

#include "midiMessageManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

midiMessageManager::midiMessageManager()
{
	m.clear();
	midiOutputList.clear();
}

midiMessageManager::~midiMessageManager()
{
	m.clear();
	midiOutputList.clear();
}

void midiMessageManager::addMidiMessage (MidiMessage *msg, int device)
{
	m.add (new midiMessage (msg, device));
}

void midiMessageManager::addMidiBuffer (MidiBuffer *mBuf, int device)
{
	m.add (new midiMessage (mBuf, device));
}

void midiMessageManager::processMidiEvents ()
{
	if (m.size() > 0)
	{
		for (int x=0; x<m.size(); x++)
		{
			midiMessage *msg = m[x];
			if (msg)
			{
				if (msg->id > 0)
				{
					/* out to device */
					if (isDeviceOpen (msg->id))
					{
						sendMessageToDevice (msg);
					}
					m.remove (x, true);
				}
			}
		}
	}
	else
	{
		return;
	}
}

MidiBuffer midiMessageManager::getLeftMessages()
{
	MidiBuffer b;

	for (int x=0; x<m.size(); x++)
	{
		if (m[x]->m)
		{
			b.addEvent (*m[x]->m, x);
		}
		if (m[x]->mB)
		{
			b.addEvents (*m[x]->mB, 0, 0, 0);
		}
	}

	return (b);
}

void midiMessageManager::clear()
{
	m.clear();
}

void midiMessageManager::sendMessageToDevice (midiMessage *m)
{
}

bool midiMessageManager::isDeviceOpen(int device)
{
	return (false);
}