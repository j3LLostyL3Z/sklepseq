// midiMessageManager.h: interface for the midiMessageManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
#define AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_

#include <juce.h>

class midiMessage
{
	public:
		midiMessage (MidiMessage *_m, int _i)
		{
			m = _m;
			mB = 0;
			id = _i;
		};

		midiMessage (MidiBuffer *_mB, int _i)
		{
			mB = _mB;
			id = _i;
			m = 0;
		}

		MidiBuffer *mB;
		MidiMessage *m;
		int id;
};

class midiDevice
{
	public:
		midiDevice (int _deviceIndex)
		{
			deviceIndex = _deviceIndex;
			d			= 0;
			open		= false;
		}

		~midiDevice()
		{
		}

		bool openDevice ()
		{
			Logger::writeToLog (String::formatted (T("opening device: %d"), deviceIndex));
			if (d || deviceIndex == 0)
			{
				open = true;
				return (true);
			}
			d = MidiOutput::openDevice (deviceIndex);
			
			if (d)
			{
				Logger::writeToLog (T("success!!!"));
				open = true;
				return (true);
			}
			else
			{
				Logger::writeToLog (T("FAILED!!!"));
				open = false;
				d = 0;
				return (false);
			}
		}
		
		void sendMessage (const MidiMessage *m)
		{
			if (isOpen())
			{
				d->sendMessageNow (*m);
			}
			else
			{
				return;
			}
		}
		bool isOpen()
		{
			return (open);
		}
	private:
		int deviceIndex;
		MidiOutput *d;
		bool open;
};

class midiMessageManager  
{
	public:
		midiMessageManager();
		~midiMessageManager();
		void addMidiMessage (MidiMessage *msg, int device = 0);
		void addMidiBuffer (MidiBuffer *mBuf, int device = 0);
		void processMidiEvents ();
		MidiBuffer getLeftMessages();
		void clear();
		void sendMessageToDevice (midiMessage *m);
		bool isDeviceOpen(int id);
		void initDevices();
		void prepareDevice(int i);
		int getCurrentEventsCount ();

	private:
		StringArray midiOutputList;
		OwnedArray <midiMessage> m;
		OwnedArray <midiDevice> device;
};

#endif // !defined(AFX_MIDIMESSAGEMANAGER_H__198293E7_B17B_4844_A44A_42B7E392EEDD__INCLUDED_)
