// sklepSeqStep.h: interface for the sklepSeqStep class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKLEPSEQSTEP_H__A7AE8B73_28EE_43D5_989D_AF567303C440__INCLUDED_)
#define AFX_SKLEPSEQSTEP_H__A7AE8B73_28EE_43D5_989D_AF567303C440__INCLUDED_

#include <juce.h>

class sklepSeqStepComponentEditor;

class sklepSeqStep : public ImageButton, public MidiKeyboardState
{
	public:
		sklepSeqStep(Image *i, Image *i2, int x, int y);
		~sklepSeqStep();
		int getX();
		int getY();
		void clicked (const ModifierKeys &modifiers);

	private:
		int posX, posY;
		Image *image;
		Image *imageOver;
		int midiChannel;

};

#endif // !defined(AFX_SKLEPSEQSTEP_H__A7AE8B73_28EE_43D5_989D_AF567303C440__INCLUDED_)
