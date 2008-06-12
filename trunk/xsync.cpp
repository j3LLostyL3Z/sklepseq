// xSync.cpp: implementation of the xSync class.
//
//////////////////////////////////////////////////////////////////////

#include "xsync.h"
#include "sklepSeqEditor.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

xsync::xsync() : Thread (T("Sync thread"))
{
	setPriority (9);
	updateAsync = 0;
	timeBPM = 120;
	timeElapsed = 0;
	timeNow = 0;
	midiQuarterNote = midiTicks = midiEighthNote = midiSixteenthNote = 0;
}

xsync::~xsync()
{
}

void xsync::run()
{
	timeElapsed = 0;
	timeNow = 0;
	midiQuarterNote = midiEighthNote = midiSixteenthNote = 0;
	midiTicks = 0;

	while (1)
	{
		timeNow =  Time::getMillisecondCounter();
		Time::waitForMillisecondCounter (timeNow + 1);

		timeElapsed = timeElapsed + (Time::getMillisecondCounter() - timeNow);

		if (timeElapsed >= timeMidiTick)
		{
			if (midiTicks == 6 || midiTicks == 12 || midiTicks == 18 || midiTicks == 0)
			{
				midiSixteenthNote++;

				if (midiSixteenthNote == 2 || midiSixteenthNote == 4)
				{
					midiEighthNote++;

					if (midiEighthNote == 2 || midiEighthNote == 4)
					{
						midiQuarterNote++;

						if (midiQuarterNote == 4)
						{
							midiQuarterNote = 0;
						}
						
						if (midiEighthNote == 4)
							midiEighthNote = 0;
					}
				}

				if (midiSixteenthNote == 4)
					midiSixteenthNote = 0;

				/* async updates, like GUI */
				if (updateAsync)
				{
					((AsyncUpdater *)updateAsync)->triggerAsyncUpdate();
				}

				/* sync updates, like midi manager */
				sendChangeMessage (this);
			}

			timeElapsed = 0;
			
			midiTicks++;

			if (midiTicks == 23)
				midiTicks = 0;
		}

		if (threadShouldExit())
			return;
	}
}

void xsync::setBPM (unsigned int bpm)
{
	timeBPM = bpm;
	timeMidiTick = 60000 / (24 * timeBPM);
}

void xsync::setGui (void *ptr)
{
	updateAsync = ptr;
}

unsigned int xsync::getMidiQuarterNote()
{
	return (midiQuarterNote);
}

unsigned int xsync::getMidiEighthNote()
{
	return (midiEighthNote);
}

unsigned int xsync::getMidiSixteenthNote()
{
	return (midiSixteenthNote);
}