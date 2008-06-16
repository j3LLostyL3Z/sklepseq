// sklepSeqCursorComponent.cpp: implementation of the sklepSeqCursorComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "sklepSeqCursorComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

sklepSeqCursorComponent::sklepSeqCursorComponent(Image *i, int x, int y)
{
	posX		= x;
	posY		= y;
	image		= i;
}

sklepSeqCursorComponent::~sklepSeqCursorComponent()
{
}

void sklepSeqCursorComponent::paint(Graphics &g)
{
	if (isMouseOver())
		g.drawImage (imageOver, 0, 0, 48, 48, 0, 0, 48, 48);
	else
		g.drawImage (image, 0, 0, 48, 48, 0, 0, 48, 48);
}

int sklepSeqCursorComponent::getX()
{
	return (posX);
}

int sklepSeqCursorComponent::getY()
{
	return (posY);
}
