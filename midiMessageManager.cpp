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
	}
	else
	{
		return;
	}
}

MidiBuffer *midiMessageManager::getLeftMessages()
{
	return (0);
}
