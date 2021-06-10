#include "application_window.h"


int WinMain(HINSTANCE hinstance, HINSTANCE previnstance, LPSTR lpcmdline, int nShowCmd)
{
	application_window app;
	if (app.init())
	{
		while (app.isRun())
		{
			app.broadcast();
		}
	}

	return 0;
}