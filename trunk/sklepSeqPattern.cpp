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

	for (int x=0; x<32; x++)
	{
		notes.add (new midiMessage2());
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

void sklepSeqPattern::setNote (int nId, int nNumber, float nVelo)
{
	if (nNumber == 0 && nVelo == 0.0)
	{
		deleteAndZero (notes[nId]->m);
	}
}