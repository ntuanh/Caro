#include "includes.h"
//#include <stdio.h>
//#include "windows.h"

#pragma comment(lib, "winmm.lib")

void sound_keyboard()
{
	bool isPlay = PlaySound(L"magnetic.wav", NULL, SND_FILENAME  );
	//return 0;
}

int sound_kick() {
	PlaySound(L"kick.wav", NULL, SND_FILENAME | SND_ASYNC);
	return 0;
}