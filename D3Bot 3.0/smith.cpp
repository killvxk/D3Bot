#include "stdafx.h"
#include "smith.h"





void BotRepairItems()
{

		SetCursorPosition(360,440);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
		SetCursorPosition(200,420);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,700);
		needrepair = 0;

}



void BotSalvageItems()
{

		SetCursorPosition(360,350);
		Sleep(300);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,700);

		SetCursorPosition(204,196);
		Sleep(300);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

		Sleep(300);

		BotGetScreenPng();

		if(BotGetInventaryInfo(0,2) == 0)
		{
		    SetCursorPosition(1092 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,3) == 0)
		{
		    SetCursorPosition(1126 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,4) == 0)
		{
		    SetCursorPosition(1160 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,5) == 0)
		{
		    SetCursorPosition(1194 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,6) == 0)
		{
		    SetCursorPosition(1228 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,7) == 0)
		{
		    SetCursorPosition(1262 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,8) == 0)
		{
		    SetCursorPosition(1296 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(0,9) == 0)
		{
		    SetCursorPosition(1330 - ScreenResolutionMinus,436);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,0) == 0)
		{
		    SetCursorPosition(1024 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,1) == 0)
		{
		    SetCursorPosition(1058 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,2) == 0)
		{
		    SetCursorPosition(1092 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,3) == 0)
		{
		    SetCursorPosition(1126 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,4) == 0)
		{
		    SetCursorPosition(1160 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,5) == 0)
		{
		    SetCursorPosition(1194 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,6) == 0)
		{
		    SetCursorPosition(1228 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,7) == 0)
		{
		    SetCursorPosition(1262 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,8) == 0)
		{
		    SetCursorPosition(1296 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(1,9) == 0)
		{
		    SetCursorPosition(1330 - ScreenResolutionMinus,470);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(2,0) == 0)
		{
		    SetCursorPosition(1024 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,1) == 0)
		{
		    SetCursorPosition(1058 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,2) == 0)
		{
		    SetCursorPosition(1092 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,3) == 0)
		{
		    SetCursorPosition(1126 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,4) == 0)
		{
		    SetCursorPosition(1160 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,5) == 0)
		{
		    SetCursorPosition(1194 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,6) == 0)
		{
		    SetCursorPosition(1228 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,7) == 0)
		{
		    SetCursorPosition(1262 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,8) == 0)
		{
		    SetCursorPosition(1296 - ScreenResolutionMinus,504);
		    LeftButton();
		}
		

		if(BotGetInventaryInfo(2,9) == 0)
		{
			SetCursorPosition(1330 - ScreenResolutionMinus,504);
			LeftButton();
		}



		if(BotGetInventaryInfo(3,0) == 0)
		{
		    SetCursorPosition(1024 - ScreenResolutionMinus,538);
		    LeftButton();
		}

		if(BotGetInventaryInfo(3,1) == 0)
		{
		    SetCursorPosition(1058 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,2) == 0)
		{
		    SetCursorPosition(1092 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,3) == 0)
		{
		    SetCursorPosition(1126 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,4) == 0)
		{
		    SetCursorPosition(1160 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,5) == 0)
		{
		    SetCursorPosition(1194 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,6) == 0)
		{
		    SetCursorPosition(1228 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,7) == 0)
		{
		    SetCursorPosition(1262 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,8) == 0)
		{
		    SetCursorPosition(1296 - ScreenResolutionMinus,538);
		    LeftButton();
		}
		
		if(BotGetInventaryInfo(3,9) == 0)
		{
			SetCursorPosition(1330 - ScreenResolutionMinus,538);
			LeftButton();
		}


		if(BotGetInventaryInfo(4,0) == 0)
		{
			SetCursorPosition(1024 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,1) == 0)
		{
			SetCursorPosition(1058 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,2) == 0)
		{
			SetCursorPosition(1092 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,3) == 0)
		{
			SetCursorPosition(1126 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,4) == 0)
		{
			SetCursorPosition(1160 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,5) == 0)
		{
			SetCursorPosition(1194 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,6) == 0)
		{
			SetCursorPosition(1228 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,7) == 0)
		{
			SetCursorPosition(1262 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,8) == 0)
		{
			SetCursorPosition(1296 - ScreenResolutionMinus,572);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(4,9) == 0)
		{
			SetCursorPosition(1330 - ScreenResolutionMinus,572);
			LeftButton();
		}
		

		if(BotGetInventaryInfo(5,0) == 0)
		{
			SetCursorPosition(1024 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,1) == 0)
		{
			SetCursorPosition(1058 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,2) == 0)
		{
			SetCursorPosition(1092 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,3) == 0)
		{
			SetCursorPosition(1126 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,4) == 0)
		{
			SetCursorPosition(1160 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,5) == 0)
		{
			SetCursorPosition(1194 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,6) == 0)
		{
			SetCursorPosition(1228 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,7) == 0)
		{
			SetCursorPosition(1262 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,8) == 0)
		{
			SetCursorPosition(1296 - ScreenResolutionMinus,606);
			LeftButton();
		}
		
		if(BotGetInventaryInfo(5,9) == 0)
		{
			SetCursorPosition(1330 - ScreenResolutionMinus,606);
			LeftButton();
		}

}




void LeftButton()
{
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,SleepTime);

	BotGetScreenPng();
	IplImage *object = GetIplImage(membit);
	cvSetImageROI(object, cvRect(158, 178, 59, 59));
	__int64 hashObject = calcImageHash(object, true);
	cvResetImageROI(object);
	cvReleaseImage(&object);

	if((calcHammingDistance(hashObject, -9114836230197444223) <= 1) ||
	   (calcHammingDistance(hashObject, -9114836230197182079) <= 1))
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,900);

		BotGetScreenPng();
		CaptureScreen(&globalscreengrab);
		if(BotGetStatus(&globalscreengrab) == 16)
		{
			SetCursorPosition(600,260);
			Sleep(60);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(100);

			SetCursorPosition(198,202);
			Sleep(60);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(60);
		}

		SetCursorPosition(10,13);
		Sleep(200);
		BotGetScreenPng();
	}
	else
	{
		SetCursorPosition(198,202);
		Sleep(60);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
		Sleep(60);
	}

}

