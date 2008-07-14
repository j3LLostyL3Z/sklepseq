#include "wrapper/formats/Standalone/juce_StandaloneFilterWindow.h"

class app : public JUCEApplication
{
    StandaloneFilterWindow *wnd;
	
	public:
	    app()
	    {
			wnd = 0;
		}
		~app()
		{
		}
	    void initialise (const String& commandLine)
	    {
			ApplicationProperties::getInstance()->setStorageParameters(T("sklepSeq"),T(".options"),T("settings"),250,PropertiesFile::storeAsXML);
			wnd = new StandaloneFilterWindow(T("sklepSeq"), Colours::white);

			wnd->centreWithSize (492, 492+28);
			wnd->setVisible (true);
		}
		void shutdown()
		{
		    if (wnd != 0)
				delete wnd;
		}
		const String getApplicationName()
		{
	        return T("sklepSeq");
	    }
		const String getApplicationVersion()
		{
	        return T("1.0");
	    }
		bool moreThanOneInstanceAllowed()
		{
	        return false;
		}
		void anotherInstanceStarted (const String& commandLine)
		{
		}
};

START_JUCE_APPLICATION (app)
