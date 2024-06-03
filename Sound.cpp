#include "includes.h"
//#include <stdio.h>
//#include "windows.h"

#pragma comment(lib, "winmm.lib")

void sound()
{
	bool isPlay = PlaySound(L"magnetic.wav", NULL, SND_FILENAME);

	if (isPlay)
		printf("This sound can be played");

	//return 0;
}