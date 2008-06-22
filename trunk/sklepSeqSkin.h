// sklepSeqSkin.h: interface for the sklepSeqSkin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKLEPSEQSKIN_H__11CF9117_D562_40B9_B58F_D5DC5801E166__INCLUDED_)
#define AFX_SKLEPSEQSKIN_H__11CF9117_D562_40B9_B58F_D5DC5801E166__INCLUDED_

#include <juce.h>

class sklepSeqSkin : public LookAndFeel  
{
	public:
		sklepSeqSkin();
		~sklepSeqSkin();
		void drawDocumentWindowTitleBar (DocumentWindow &window, Graphics &g,int	w, int h, int titleSpaceX, int titleSpaceW, const Image *icon, bool drawTitleTextOnLeft);
};

#endif // !defined(AFX_SKLEPSEQSKIN_H__11CF9117_D562_40B9_B58F_D5DC5801E166__INCLUDED_)
