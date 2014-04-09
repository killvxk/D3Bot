#include "stdafx.h"
#include "stash.h"


void BotStashItems()
{

		SetCursorPosition(10,12);
		Sleep(100);

		keybd_event('I', 0,0,0);
		keybd_event('I', 0,KEYEVENTF_KEYUP,0);
		
		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);

		CaptureScreen(&globalscreengrab);
		int BotStatus = BotGetStatus(&globalscreengrab);

		if((finditem == 0) || ((Event == 1) || ((BotStatus == 14)) && (((needrepair < 4) && (repair == 1)) || (repair == 0))))
		{
			//если слоты все пустые
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

			keybd_event('I', 0,0,0);
			keybd_event('I', 0,KEYEVENTF_KEYUP,0);
			Sleep(200);

			if(LocationName == 1)
			{
				SetCursorPosition(940,360);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
				SetCursorPosition(460,520);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
			}
			else if(LocationName == 3)
			{
				if(act4 == 1)
				{
					SetCursorPosition(317,456);
					Sleep(100);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
				}
				else
				{
					SetCursorPosition(220,440);
					Sleep(100);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
				}
			}
			else if(LocationName == 2)
			{
				SetCursorPosition(523,512);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
			}

			return;
		}

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

		if(identify == 1)
		{
			BotIdentifyItems();
		}

		keybd_event('I', 0,0,0);
		keybd_event('I', 0,KEYEVENTF_KEYUP,0);
		Sleep(200);

		if(LocationName == 1)
		{
			SetCursorPosition(935,259);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
			SetCursorPosition(800,280);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
			SetCursorPosition(615,300);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
		}
		else if(LocationName == 3)
		{
			SetCursorPosition(790,30);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,4000);
			SetCursorPosition(570,260);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
		}
		else if(LocationName == 2)
		{
			SetCursorPosition(540,10);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,4000);
			SetCursorPosition(533,200);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
		}

		SetCursorPosition(1,12);
		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,900);

		CaptureScreen(&globalscreengrab);
		BotStatus = BotGetStatus(&globalscreengrab);
		
		if((BotStatus == 13) || (BotStatus == 14))
		{
			//все ок
		}
		else
		{
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);
			CaptureScreen(&globalscreengrab);
			BotStatus = BotGetStatus(&globalscreengrab);
		}

		if((BotStatus == 13) || (BotStatus == 14))
		{

			if(repair == 1)
			{
				BotRepairItems();
			}

			if(salvage == 1)
			{
				BotSalvageItems();
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			Sleep(500);

			if(LocationName == 1)
			{
				SetCursorPosition(170,420);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
				SetCursorPosition(290,250);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
				SetCursorPosition(444,309);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
			}
			else if(LocationName == 3)
			{
				SetCursorPosition(233,638);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2500);
				SetCursorPosition(80,300);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,3000);
				SetCursorPosition(410,320);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
			}
			else if(LocationName == 2)
			{
				SetCursorPosition(285,665);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2500);
				SetCursorPosition(300,450);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
				SetCursorPosition(307,177);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,3000);
				SetCursorPosition(445,286);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
			}
			
			CaptureScreen(&globalscreengrab);
			BotStatus = BotGetStatus(&globalscreengrab);
			if((BotStatus == 5) || (BotStatus == 14))
			{
				SetCursorPosition(365,165);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,700);
				BotGetScreenPng();
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,700);
				BotPutStashItems();
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);

				CaptureScreen(&globalscreengrab);
				if(((identify == 1) && (Item_x.size() > 0)) || ((identify == 0) && (FindIdentifyColor(&globalscreengrab) == 1)))
				{
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);
					SetCursorPosition(365,257);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
					BotGetScreenPng();
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
					BotPutStashItems();
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);

					CaptureScreen(&globalscreengrab);
					if(((identify == 1) && (Item_x.size() > 0)) || ((identify == 0) && (FindIdentifyColor(&globalscreengrab) == 1)))
					{
						BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);
						SetCursorPosition(365,348);
						mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
						mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
						BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
						BotGetScreenPng();
						BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
						BotPutStashItems();
					}
				}

			CaptureScreen(&globalscreengrab);
			if(((identify == 1) && (Item_x.size() > 0)) || ((identify == 0) && (FindIdentifyColor(&globalscreengrab) == 1)))
			{
				FullSlot = 1;
				dropitems = 0;
				finditem = 0;
			}
			else
			{
				FullSlot = 0;
				dropitems = 1;
				finditem = 0;
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);

			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// ћоделируем возврат клавиши в не нажатое состо€ние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			}
			


			Sleep(300);

			if(LocationName == 1)
			{
				SetCursorPosition(760,550);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
				SetCursorPosition(490,507);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1500);
			}
			else if(LocationName == 3)
			{
				SetCursorPosition(630,550);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);
				SetCursorPosition(451,470);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
			}
			else if(LocationName == 2)
			{
				SetCursorPosition(790,550);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2500);
				SetCursorPosition(853,589);
				Sleep(100);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,2000);
			}

		}
		else
		{
			//√люк на подходе к сундуку - идем к телепорту.
			StartLevel = 0;
			PrepareStashItemsStep = 0;
			return;
		}

	PrepareStashItemsStep = 0;
}











void BotDropItems()
{

	keybd_event('I', 0,0,0);
	keybd_event('I', 0,KEYEVENTF_KEYUP,0);

	for(int y = 0; y < 6; y++){
		for(int x = 0; x < 10; x++){

			if(((y == 0) && (x > 1)) || (y > 0))
			{
				BotGetScreenPng();
				if(BotGetInventaryInfo(y,x) != 1)
				{
					rx = 680 + x * 35;
					ry = 435 + y * 35;
					SetCursorPosition(rx,ry);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
					SetCursorPosition(405,510);
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);
				}
			}

		}
	}

	keybd_event('I', 0,0,0);
	keybd_event('I', 0,KEYEVENTF_KEYUP,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
	
}



void BotPutStashItems()
{


BotGetScreenPng();
BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);



if(BotGetInventaryInfo(0,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(0,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(0,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,436);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}



if(BotGetInventaryInfo(1,0) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,0) != 0)
{
	SetCursorPosition(1024 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,1) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,1) != 0)
{
	SetCursorPosition(1058 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(1,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(1,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(1,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(1,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,470);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,0) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,0) != 0)
{
	SetCursorPosition(1024 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(2,1) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,1) != 0)
{
	SetCursorPosition(1058 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(2,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(2,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(2,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(2,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,504);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}







if(BotGetInventaryInfo(3,0) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,0) != 0)
{
	SetCursorPosition(1024 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(3,1) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,1) != 0)
{
	SetCursorPosition(1058 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(3,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(3,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(3,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(3,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(3,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(3,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(3,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(3,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(3,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,538);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}








if(BotGetInventaryInfo(4,0) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,0) != 0)
{
	SetCursorPosition(1024 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,1) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,1) != 0)
{
	SetCursorPosition(1058 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}

if(BotGetInventaryInfo(4,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(4,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(4,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,572);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}









if(BotGetInventaryInfo(5,0) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,0) != 0)
{
	SetCursorPosition(1024 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,1) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,1) != 0)
{
	SetCursorPosition(1058 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,2) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,2) != 0)
{
	SetCursorPosition(1092 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,3) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,3) != 0)
{
	SetCursorPosition(1126 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,4) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,4) != 0)
{
	SetCursorPosition(1160 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,5) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,5) != 0)
{
	SetCursorPosition(1194 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,6) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,6) != 0)
{
	SetCursorPosition(1228 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,7) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,7) != 0)
{
	SetCursorPosition(1262 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(BotGetInventaryInfo(5,8) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,8) != 0)
{
	SetCursorPosition(1296 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}



if(BotGetInventaryInfo(5,9) == 1)
{
	//если слот пустой ничего не делаем
}
else if(BotGetInventaryInfo(5,9) != 0)
{
	SetCursorPosition(1330 - ScreenResolutionMinus,606);
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,400);
}


if(identify == 1)
{

	int ii;
	for(ii=0; ii < Item_x.size(); ii++)
	{
		if(Item_x[ii] != 100500)
		{
			Sleep(150);
			CaptureScreen(&globalscreengrab);
			DWORD coloritem = ColorNoAlpha(BitmapPixel(&globalscreengrab, Item_x[ii], Item_y[ii]));
			DWORD coloritem2 = ColorNoAlpha(BitmapPixel(&globalscreengrab, Item_x[ii] + 1, Item_y[ii] + 1));
			SetCursorPosition(Item_x[ii],Item_y[ii]);
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
			SetCursorPosition(20,11);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);
			CaptureScreen(&globalscreengrab);
			DWORD nextcoloritem = ColorNoAlpha(BitmapPixel(&globalscreengrab, Item_x[ii], Item_y[ii]));
			DWORD nextcoloritem2 = ColorNoAlpha(BitmapPixel(&globalscreengrab, Item_x[ii] + 1, Item_y[ii] + 1));
			if((coloritem == nextcoloritem) && (coloritem2 == nextcoloritem2))
			{
				return;
			}
			else
			{
				Item_x[ii] = 100500;
				Item_y[ii] = 100500;
			}
		}
	}


	int ii2;
	int noemptycount = 0;
	for(ii2=0; ii2 < Item_x.size(); ii2++)
	{
		if(Item_x[ii2] != 100500)
		{
			noemptycount++;	
		}
	}

	if(noemptycount == 0)
	{
		Item_x.clear();
		Item_y.clear();
	}

}
else
{
	int currentrx;
	int currentry;
	while(1)
	{
		SetCursorPosition(10,13);
		Sleep(400);
		CaptureScreen(&globalscreengrab);

		if(FindIdentifyColor(&globalscreengrab) == 1)
		{
			if((currentrx != rx) || (currentry != ry))
			{
				currentrx = rx;
				currentry = ry;
				SetCursorPosition(rx,ry);
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
				Sleep(500);
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

}









int BotPrepareStashItems()
{

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);
		BotGetScreenPng();

		int items = 0;

 
		if(GetRGBRange(1080 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 424, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1012 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1046 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1080 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 458, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1012 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1046 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1080 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 492, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1012 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1046 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1080 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 526, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1012 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1046 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1080 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 560, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1012 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1046 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1080 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1114 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1148 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1182 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1216 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1250 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1284 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		if(GetRGBRange(1318 - ScreenResolutionMinus, 594, 30, 20, 15, 0, 0, 0) != 1)
		{
			items++;
		}

		Sleep(100);
		SetCursorPosition(11,9);
		Sleep(100);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( Ќ≈ «јЅџ¬ј“№ )
		Sleep(100);

		PrepareStashItemsStep = 1;

		if(items > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}


}



