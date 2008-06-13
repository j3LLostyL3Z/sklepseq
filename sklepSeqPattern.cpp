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
	patternLength	=	16;
}

sklepSeqPattern::~sklepSeqPattern()
{
}

int sklepSeqPattern::getPatternId()
{
	return (patternId);
}

int sklepSeqPattern::getPatternLength()
{
	return (patternLength);
}
