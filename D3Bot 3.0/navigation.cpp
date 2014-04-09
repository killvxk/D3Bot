#include "stdafx.h"
#include "navigation.h"


void BotGoToBase()
{
	if(teleportstepcount > 10)
	{
		logprint("Новая игра (Причина - превышение 10 неудачных телепортаций на базу)", 0);
		BotNewGame();
	}
	else
	{
		//Не нашли ни союзника, ни цели, ни флаг и не стартанул эвент - значит потерялись и надо портаться на базу.
		
		if(dropitems == 1)
		{
			logprint("Выкидывание вещей перед телепортацией", 0);
			BotDropItems();
			dropitems = 0;
			FullSlot = 0;
		}

		keybd_event('T', 0,0,0);
		keybd_event('T', 0,KEYEVENTF_KEYUP,0);
		
		while(1)
		{

			CaptureScreen(&globalscreengrab);
			int BotStatus = BotGetStatus(&globalscreengrab);
			location = BotGetLocation();
			teleportsleepcount++;
			Sleep(100);
			
			if(BotStatus != 0)
			{
				teleportsleepcount = 0;
				teleportstepcount = 0;
				noputitemteleport = 0;
				BotHeal();
				break;
			}
			else if((Event == 0) && (LoadLocation == 1) && (teleportsleepcount < 30) && (location == 0) && (((FindAttackColor(&globalscreengrab) == 1) || ((FindFollowColor(&globalscreengrab) == 1) && (solo == 0))) || ((FullSlot == 0) && (noputitemteleport == 0) && (FindItemColor(&globalscreengrab) == 1)) ))
			{
				teleportsleepcount = 0;
				teleportstepcount = 0;
				noputitemteleport = 0;
				BotHeal();
				break;
			}
			else if((teleportsleepcount >= 30) && (teleportsleepcount < 70))
			{
				//момент телепортации
				if((location == 1) && (LoadLocation == 1))
				{
					teleportsleepcount = 70;
				}
			}
			else if(teleportsleepcount >= 70)
			{
				if((location == 1) && (LoadLocation == 1))
				{
					teleportstepcount = 0;
					noputitemteleport = 0;

					if(key_showitems == 0)
					{ 
						keybd_event(VK_MENU, 0,0,0);
						keybd_event(VK_MENU, 0,KEYEVENTF_KEYUP,0);
					}
					else if(key_showitems == 1)
					{
						keybd_event('P', 0,0,0);
						keybd_event('P', 0,KEYEVENTF_KEYUP,0);
					}

					if(DetectAct4() == 1)
					{
						act4 = 1;
					}
					else
					{
						act4 = 0;
					}

					BotStashItems();

					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);
					
					NoEventCount = 200;

					if(key_showitems == 0)
					{
						keybd_event(VK_MENU, 0,0,0);
						keybd_event(VK_MENU, 0,KEYEVENTF_KEYUP,0);
					}
					else if(key_showitems == 1)
					{
						keybd_event('P', 0,0,0);
						keybd_event('P', 0,KEYEVENTF_KEYUP,0);
					}

					startteleport = 1;
					teleportsleepcount = 0;
					TraversedLocations++;
					break;
				}
				else
				{
					teleportstepcount++;
					teleportsleepcount = 0;
					break;
				}
			}
		}
	}
}





void BotFollowFlag()
{

	srand ( time(NULL) );
	int followflagtype = rand() % 4 + 1;
	
	if(StartLevel == 0)
	{
		if(followflagtype == 1)
		{
			SetCursorPosition(rx + 20,ry + 20);
		}
		else if(followflagtype == 2)
		{
			SetCursorPosition(rx - 20,ry + 20);
		}
		else if(followflagtype == 3)
		{
			SetCursorPosition(rx - 20,ry - 20);
		}
		else if(followflagtype == 4)
		{
			SetCursorPosition(rx + 20,ry - 20);
		}
	}
	else
	{
		if(followflagtype == 1)
		{
			SetCursorPosition(367,228);
		}
		else if(followflagtype == 2)
		{
			SetCursorPosition(649,253);
		}
		else if(followflagtype == 3)
		{
			SetCursorPosition(346,450);
		}
		else if(followflagtype == 4)
		{
			SetCursorPosition(674,451);
		}
	}

	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,800);
	CaptureScreen(&globalscreengrab);

	if(BotGetFlagStatus(&globalscreengrab) == 1)
	{
		StartLevel = 0;
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
		BotSleep(1,0,0,0,0,0,0,0,0,0,0,0,1000);
	}
}



void randomfollow()
{
	generator.seed(std::time(0)); // seed with the current time 

	NumberDistribution distributiony(-15, 160);
	Generator numberGeneratory(generator, distributiony); 
	randomfollowy = numberGeneratory();

	NumberDistribution distributionx(-80, 120);
	Generator numberGeneratorx(generator, distributionx); 
	randomfollowx = numberGeneratorx();
}



void MoveButton()
{
	if(movebutton == 1)
	{
		keybd_event(49, 0,0,0);
		keybd_event(49, 0,KEYEVENTF_KEYUP,0);
	}
	else if(movebutton == 2)
	{
		keybd_event(50, 0,0,0);
		keybd_event(50, 0,KEYEVENTF_KEYUP,0);
	}
	else if(movebutton == 3)
	{
		keybd_event(51, 0,0,0);
		keybd_event(51, 0,KEYEVENTF_KEYUP,0);
	} 
	else if(movebutton == 4)
	{
		keybd_event(52, 0,0,0);
		keybd_event(52, 0,KEYEVENTF_KEYUP,0);
	}
	else if(movebutton == 5)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
	}
	else if(movebutton == 6)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
	}
}


void BotClickFollowArea()
{


    //Сюды

	int ypos = 0;
	int xpos = 1;

	generator.seed(std::time(0)); // seed with the current time 

	NumberDistribution distributiony(-50, 50);
	Generator numberGeneratory(generator, distributiony); 
	int randomy = numberGeneratory();

	NumberDistribution distributionx(-30, 30);
	Generator numberGeneratorx(generator, distributionx); 
	int randomx = numberGeneratorx();

	NumberDistribution distributionsleep(-280, 100);
	Generator numberGeneratorSleep(generator, distributionsleep); 
	int randomsleep = numberGeneratorSleep();

	if(ypos + randomy > 680)
	{
		randomy = 0;
	}

	SetCursorPosition(xpos + randomx, ypos + randomy);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
	BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300 + randomsleep);
}