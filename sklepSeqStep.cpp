// sklepSeqStep.cpp: implementation of the sklepSeqStep class.
//
//////////////////////////////////////////////////////////////////////

#include "sklepSeqStep.h"
#include "sklepSeqStepComponentEditor.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sklepSeqStep::sklepSeqStep(Image *i, Image *i2, int x, int y) : ImageButton (T("sklepSeq step"))
{
	setBufferedToImage (true);

	posX = x;
	posY = y;
	image = i;
	imageOver = i2;

	setImages (true, false, true, image, 1.0f, Colour(0x0), imageOver, 1.0f, Colour(0x0), imageOver, 1.0f, Colour(0x0));
}

sklepSeqStep::~sklepSeqStep()
{
}

int sklepSeqStep::getX()
{
	return (posX);
}

int sklepSeqStep::getY()
{
	return (posY);
}

void sklepSeqStep::clicked (const ModifierKeys &modifiers)
{
	if (modifiers.isPopupMenu())
	{
	}
}
