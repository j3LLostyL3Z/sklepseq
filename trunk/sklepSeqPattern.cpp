// sklepSeqPattern.cpp: implementation of the sklepSeqPattern class.
//
//////////////////////////////////////////////////////////////////////

#include "sklepSeqPattern.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sklepSeqPattern::sklepSeqPattern(int _id)
{
	patternId		=	_id;
	patternLength	=	12;
	isActive		=	false;
	currentPosition	=	1;
	mode			=	patternForward;
	midiChannel		=	1;
	midiDevice		=	1;

	for (int x=0; x<32; x++)
	{
		notes.add (new myMidiMessage(midiChannel));
		notes[x]->getMidiMessage()->setTimeStamp (double(x+1));
	}
}

sklepSeqPattern::~sklepSeqPattern()
{
	notes.clear();
}

int sklepSeqPattern::getPatternId()
{
	return (patternId);
}

void sklepSeqPattern::setPatternLength(int len)
{
	if (len > 32 || len < 1)
		patternLength = 16;
	else
		patternLength = len;
}

int sklepSeqPattern::getPatternLength()
{
	return (patternLength);
}

void sklepSeqPattern::forward(int pos)
{
	if (pos == currentPosition || !isActive)
		return;

	if (patternHasBeenActivated)
	{
		currentPosition = pos;
		patternHasBeenActivated = false;
	}

	if (mode == patternForward)
		currentPosition++;

	if (mode == patternReverse)
		currentPosition--;

	if (currentPosition > patternLength)
	{
		currentPosition = (currentPosition - patternLength);
	}

	triggerEvents();
}

void sklepSeqPattern::triggerEvents ()
{
	if (notes[currentPosition-1]->enabled)
	{
		if (notes[currentPosition-1]->isMulti() == true)
		{
			midiManager->addMidiBuffer (notes[currentPosition-1]->mB, midiDevice);
		}
		else
		{
			midiManager->addMidiMessage (notes[currentPosition-1]->m, midiDevice);
		}
	}
}

void sklepSeqPattern::setActive (bool t)
{
	if (!isActive)
	{
		patternHasBeenActivated = true;
	}

	isActive = t;
}

bool sklepSeqPattern::getActive ()
{
	return (isActive);
}

int sklepSeqPattern::getCurrentPosition ()
{
	return (currentPosition);
}

void sklepSeqPattern::addMidiManager (midiMessageManager *m)
{
	midiManager = m;
}

void sklepSeqPattern::setStep (int nId, int nNumber, float nVelo)
{
	if (nNumber == 0 && nVelo == 0.0)
	{
		if (notes[nId]->enabled)
		{
			notes[nId]->enabled = false;
			deleteAndZero (notes[nId]->m);
		}
	}
	else
	{
		if (notes[nId]->enabled)
			deleteAndZero (notes[nId]->m);
		
		notes[nId]->m = new MidiMessage (MidiMessage::noteOn (midiChannel, nNumber, nVelo));
	}
}

myMidiMessage* sklepSeqPattern::getStep (int nId)
{
	if (notes[nId])
	{
		if (notes[nId]->enabled)
			return (notes[nId]);
		else
			return (0);
	}
	else
	{
		return (0);
	}
}

myMidiMessage* sklepSeqPattern::getStepNoVeirfy (int nId)
{
	if (notes[nId])
	{
		return (notes[nId]);
	}
	else
	{
		return (0);
	}
}

void sklepSeqPattern::toggleStep(int nId)
{
	if (notes[nId])
	{
		if (notes[nId]->enabled)
		{
			notes[nId]->enabled = false;
		}
		else
		{
			notes[nId]->enabled = true;
		}
	}
}

void sklepSeqPattern::setMidiChannel (int c)
{
	if (c>1 && c<16)
		midiChannel = c;
	else
		midiChannel = 1;

	for (int x=0; x<notes.size(); x++)
	{
		if (notes[x])
		{
			notes[x]->setMidiChannel (midiChannel);
		}
	}
}

int sklepSeqPattern::getMidiChannel ()
{
	return (midiChannel);
}

void sklepSeqPattern::setMidiDevice (int d)
{
	Logger::writeToLog (T("pattern, set midi device"));
	midiManager->prepareDevice (d);
	midiDevice = d;
}

int sklepSeqPattern::getMidiDevice ()
{
	return (midiDevice);
}

MidiMessageSequence sklepSeqPattern::serialize()
{
	MidiMessageSequence sequence;
	for (int x=0; x<32; x++)
	{
		sequence.addEvent (*notes[x]->getMidiMessage());
	}

	return (sequence);
}