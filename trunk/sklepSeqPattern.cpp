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

	for (int x=0; x<32; x++)
	{
		midiNotes.addEvent (MidiMessage (0xf0, (double)x));
	}
}

sklepSeqPattern::~sklepSeqPattern()
{
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
	if (pos == currentPosition)
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