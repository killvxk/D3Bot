// D3Bot 3.0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "about.h"
#include "D3Bot 3.0.h"



///sssss
// для хранения каналов RGB
IplImage* rgb = 0;
IplImage* h_plane = 0;
IplImage* s_plane = 0;
IplImage* v_plane = 0;
// для хранения каналов RGB после преобразования
IplImage* r_range = 0;
IplImage* g_range = 0;
IplImage* b_range = 0;
// для хранения суммарной картинки
IplImage* rgb_and = 0;

int Rmin = 0;
int Rmax = 256;

int Gmin = 0;
int Gmax = 256;

int Bmin = 0;
int Bmax = 256;

int RGBmax = 256;




// сравнение объектов по моментам их контуров 








 
int main()
{

	//Получаем директорию программы
	_getcwd(currentPath, _MAX_PATH);

	IdentifyImageEmptySlots = cvLoadImage(".\\items\\emptyslots.png", 3);
	IdentifyImageItemsToStash = cvLoadImage(".\\items\\itemstostash.png", 3);

	setlocale(LC_ALL,"RUS");
	logfile.open("logfile.txt", fstream::app);
	logprint("-----------", -1);
	logprint("-----------", -1);
	logprint("Запуск бота", -1);
	logprint("-----------", -1);
	logprint("-----------\n", -1);

	//Получаем инфо из ини файла
	char *datainifile = "\\key.ini";
	char *datainipath = (char*)malloc(strlen(currentPath) + strlen(datainifile) + 1);
	sprintf(datainipath, "%s%s", currentPath, datainifile);
	TestKey = GetValueFromINI(datainipath, "auth", "key");
	free(datainipath);

	logprint("D3Бот 3.0 [Релиз]", 1);
	logprint("Автор: Линк", 1);
	logprint("Вебсайт команды: oneprojects.ru\n", 1);

	logprint("Cоединение с сервером...", 0);

	curl = curl_easy_init();

	//Отправляем запросы на сервер
	srand((unsigned)time(NULL));
	char *Solt = (char*)malloc(7);
	sprintf(Solt, "%d", rand()%999999 + 100000 );

	mymd5 = (char*)malloc(strlen(TestKey) + strlen("diablo3bot") + strlen(Solt) + 1);
	sprintf(mymd5, "%s%s%s", TestKey, "diablo3bot", Solt);
	
	char *datahttpquery = (char*)malloc(strlen("http://diablo3bot.ru/D3Bot/auth.php?version=2.1&authkey=") + strlen(TestKey) + strlen("&solt=") + strlen(Solt) + 1);
	sprintf(datahttpquery, "%s%s%s%s", "http://diablo3bot.ru/D3Bot/auth.php?version=2.1&authkey=", TestKey, "&solt=", Solt);
    string urls = datahttpquery;
    CURL *curl1;
    CURLcode result;
    string buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    curl1 = curl_easy_init();
    curl_easy_setopt(curl1, CURLOPT_URL, urls.c_str());
    curl_easy_setopt(curl1, CURLOPT_WRITEFUNCTION, writer);
    curl_easy_setopt(curl1, CURLOPT_WRITEDATA, &buffer);
    result = curl_easy_perform(curl1);
	
	Sleep(300);

	if(buffer == md5(mymd5))
	{
		logprint("Ключ принят, загружаем настройки...\n", 0);
	}
	else
	{
		logprint("Ключ НЕ принят, ошибка: ", 0);
		if(buffer != "")
		{
			logprint(buffer, 0);
			Sleep(100000000);
		}
		else
		{
			logprint("Ошибка соединения с сервером, проверьте соединение с интернетом", 0);
			Sleep(100000000);
		}
		
		noauth = 1;
		noauthupdate = 1;
	}

	itemvalue_blue = BotGetConfig("itemvalue_blue");
	itemvalue_yellow = BotGetConfig("itemvalue_yellow");
	itemvalue_green = BotGetConfig("itemvalue_green");
	itemvalue_legendary = BotGetConfig("itemvalue_legendary");
	itemvalue_gems = BotGetConfig("itemvalue_gems");
	itemvalue_rings = BotGetConfig("itemvalue_rings");
	itemvalue_amulets = BotGetConfig("itemvalue_amulets");
	itemvalue_arhonts = BotGetConfig("itemvalue_arhonts");
	itemvalue_recipes = BotGetConfig("itemvalue_recipes");
	itemvalue_potions = BotGetConfig("itemvalue_potions");
	itemvalue_books = BotGetConfig("itemvalue_books");

	downclicks = BotGetConfig("downclicks");
	ycoordinate = BotGetConfig("ycoordinate");

	GameSubMode = BotGetConfig("submode");

	SleepTime = BotGetConfig("sleep");
	
	MainAttack = BotGetConfig("mainattack");
	
	loglevel = BotGetConfig("loglevel");

	attackskillduration = BotGetConfig("attackskillduration");
	mainattackcooldown = BotGetConfig("mainattackcooldown");
	secondaryattackcooldown = BotGetConfig("secondaryattackcooldown");
	secondaryattackpause = BotGetConfig("secondaryattackpause");
	secondaryduration = BotGetConfig("secondaryduration");
	attackbutton1 = BotGetConfig("attackbutton1");
	attackbutton2 = BotGetConfig("attackbutton2");
	attackbutton3 = BotGetConfig("attackbutton3");
	attackbutton4 = BotGetConfig("attackbutton4");
	healbutton1 = BotGetConfig("healbutton1");
	healbutton2 = BotGetConfig("healbutton2");
	healbutton3 = BotGetConfig("healbutton3");
	healbutton4 = BotGetConfig("healbutton4");
	buffbutton = BotGetConfig("buffbutton");
	movebutton = BotGetConfig("movebutton");
	buffduration = BotGetConfig("buffduration");
	BuffCount = buffduration - 1;
	leavehp = BotGetConfig("leavehp");
	dangerleavehp = BotGetConfig("dangerleavehp");
	skillhp = BotGetConfig("skillhp");
	potionhp = BotGetConfig("potionhp");
	maxdeathcount = BotGetConfig("maxdeathcount");
	endeventrestart = BotGetConfig("endeventrestart");
	salvage = BotGetConfig("salvage");
	repair = BotGetConfig("repair");
	identify = BotGetConfig("identify");
	key_showitems = BotGetConfig("key_showitems");

	logprint("Настройки загружены", 0);
	Sleep(600);
  

    if((GetSystemMetrics(SM_CXSCREEN) != 1024) && (GetSystemMetrics(SM_CYSCREEN) != 768))
	{
		logprint("Бот поддерживает только расширение 1024х768!\n", 0);
		Sleep(100000000);
	}

	//Задержка чтобы войти в окно диаблы

	logprint("Бот начнет работу через 3...", 0);
	Sleep(1000);
	logprint("2...", 0);
	Sleep(1000);
	logprint("1...", 0);
	Sleep(1000);
	if(GetKeyState(0x14) == 1)
	{
		logprint("D3Бот активирован", 0);
	}
	else
	{
		logprint("Для активации бота нажмите КАПС ЛОК в Диабло 3", 0);
	}
	Sleep(1000);

	while(1)
	{
		if(GetKeyState(0x14) == 1)
		{

		if((AuthEvent == 150) || (noauthupdate == 1))
		{
			AuthEvent = 0;
			BotUpdateSession();
		}
		else
		{
			AuthEvent++;
		}

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,SleepTime);
		CaptureScreen(&globalscreengrab);
		int BotStatus = BotGetStatus(&globalscreengrab);
		location = BotGetLocation();

		if(BotStatus == 4)
		{
			logprint("Cмерть", 0);

			needrepair++;

			BotDeathCount++;
			if(BotDeathCount > maxdeathcount)
			{
				logprint("Новая игра (Причина - превышение максимального количества смертей)", 0);
				BotNewGame();
			}
			else
			{
				int deathtimecount = 0;
				
				int maxdeathtimeout;
				if(Event == 0)
				{
					maxdeathtimeout = 20;
				}
				else
				{
					maxdeathtimeout = 100;
				}

				while(deathtimecount <= maxdeathtimeout)
				{
					CaptureScreen(&globalscreengrab);
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);
					deathtimecount++;
					int BotStatus = BotGetStatus(&globalscreengrab);
					if(BotStatus == 17)
					{
						SetCursorPosition(565,541);
						mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
						mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
						break;
					}
				}

				if(deathtimecount > 20)
				{
					SetCursorPosition(565,599);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,5000);
				}

			}
		
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

		}



		else if(BotStatus == 17)
		{
			SetCursorPosition(565,541);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
		}

		else if(BotStatus == 19)
		{
			SetCursorPosition(435,570);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			Sleep(500);
		}

		else if(BotStatus == 18)
		{
			SetCursorPosition(992,270);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			Sleep(500);
		}

		else if(BotStatus == 12)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			Event = 0;

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
		}


		else if(BotStatus == 14)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
		}


		else if(BotStatus == 8)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
			restartgame = 1;
			kickgame = 1;
			BotNewGame();
		}

		else if(BotStatus == 10)
		{
			restartgame = 1;
			BotNewGame();
		}


		else if(BotStatus == 1)
		{
			Event = 1;

			SetCursorPosition(440,466);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

			SetCursorPosition(440,491);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

			SetCursorPosition(440,516);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

		}

		else if(BotStatus == 15)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			Sleep(300);
		}

		else if(BotStatus == 20)
		{
			while(1)
			{
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,SleepTime);
				CaptureScreen(&globalscreengrab);
				int BotStatus = BotGetStatus(&globalscreengrab);

				if(BotStatus != 20)
				{
					BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200 + SleepTime);
					break;
				}
			}
		}

		else if(BotStatus == 7)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
		}

		else if(BotStatus == 5)
		{
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

			BotNewGame();
		}

		else if(BotStatus == 9)
		{
			Event = 1;
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			endeventcount++;
			Sleep(5000);

			while(1)
			{
				CaptureScreen(&globalscreengrab);
				Sleep(SleepTime);
				if((FullSlot == 0) && (FindItemColor(&globalscreengrab) == 1))
				{
					if((finditemx == rx) && (finditemy == ry))
					{
						break;
					}
					else
					{
						finditemx = rx;
						finditemy = ry;

						SetCursorPosition(rx + 10,ry + 5);
						BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);
						mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
						mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
						BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);
					}
				}
				else
				{
					break;
				}
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

			CaptureScreen(&globalscreengrab);
			int BotStatus = BotGetStatus(&globalscreengrab);
			location = BotGetLocation();
			if((location == 0))
			{
				BotGoToBase();
			}

			Event = 0;

			if(endeventrestart <= endeventcount)
			{
				logprint("Новая игра (Причина - превышение максимального количества завершенных миссий)", 0);
				BotNewGame();
			}
			else if(BotStatus == 0)
			{
				Sleep(30000);
			}
			
		}






		else if(BotStatus == 3)
		{
			SetCursorPosition(525,450);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			Sleep(10000);
			restartgame = 1;
			BotNewGame();
		}

		else if(BotStatus == 2)
		{
			
			logprint("ВЫХОД - ПРЕВЫШЕНИЕ МАКСИМАЛЬНОГО КОЛИЧЕСТВА КОММАНД", 0);
			Sleep(1000000);

		}


















		else if(BotStatus == 16)
		{
			SetCursorPosition(440,269);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
		}

 
		else if(BotStatus == 0)
		{

			RestartEventCount++;
			if(RestartEventCount > 20000)
			{
				logprint("Новая игра (Причина - превышение 20000 действий)", 0);
				BotNewGame();
			}
			else
			{

					CaptureScreen(&globalscreengrab);
					location = BotGetLocation();


					if(location == 0)
					{
						StartLevel = 1;
						if((FindFriendDie(&globalscreengrab) == 1) || (FindDieColor(&globalscreengrab) == 1))
						{
							healdanger = 1;
						}

						if((FullSlot == 0) && (FindItemColor(&globalscreengrab) == 1))
						{

 
							if(dropitems == 1)
							{
								logprint("Выкидывание вещей (видим шмот который хотим подобрать)", 0);
								BotDropItems();
								dropitems = 0;
								FullSlot = 0;
							}

							finditem = 1;
							botattackcount = 0;
							followcount = 0;
							finditemcount++;
							if((finditemcount > 15) && (finditemx == rx) && (finditemy == ry))
							{
								noputitemteleport = 1;
								BotGoToBase();
							}
							else if(finditemcount > 20)
							{
								FullSlot = 1;
							}
							else
							{
								finditemx = rx;
								finditemy = ry;
							

								SetCursorPosition(rx + 10,ry + 5);
								BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);
								mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
								mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

								BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

							}
						}
						else if(FindAttackColor(&globalscreengrab) == 1)
						{
							finditemcount = 0;
							followcount = 0;
							BotAttack();
							BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,10);
							BotHeal();
						} 
						else if(FindFollowColor(&globalscreengrab) == 1)
						{
							//Не нашли цель - бегаем за союзником
							botattackcount = 0;
							finditemcount = 0;
							BotFollowPlayer(rx, ry);
						}
						else if((location == 0) && (FindPlayersBeside(&globalscreengrab) == 0))
						{
							botattackcount = 0;
							followcount = 0;
							BotGoToBase();
						}
					}
					else if(location == 1)
					{

						if(((FindFlagColor(&globalscreengrab) == 1) || (startteleport == 1)))
						{
							while(1)
							{
								//Не нашли ни союзника, ни цели - ищем флаг и бежим к союзнику

								CaptureScreen(&globalscreengrab);
								location = BotGetLocation();
								if(BotGetStatus(&globalscreengrab) != 0)
								{
									logprint("Игровой статус не равен 0", 0);
									break;
								}

								if(NoTeleportCount > 150)
								{
									startteleport = 0;
									logprint("Новая игра (Причина - превышение 150 кликов по флагу)", 0);
									BotNewGame();
									break;
								} else if(NoTeleportCount == 50)
								{
									StartLevel = 0;
								}

								if(location == 0)
								{

									
									int teleportfirstsleep = 0;
									while(teleportfirstsleep < 30)
									{
										Sleep(SleepTime);
										CaptureScreen(&globalscreengrab);
										if((FindFollowColor(&globalscreengrab) == 1) || (FindAttackColor(&globalscreengrab) == 1))
										{
											break;
										}
										teleportfirstsleep++;
									}

									startteleport = 0;
									NoTeleportCount = 0;
									break;
								}
								else if(location == 1)
								{
									FindFlagColor(&globalscreengrab);
									BotFollowFlag();
									NoEventCount = NoEventCount + 3;
									NoTeleportCount++;
									BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
								}

							}
						}
						else
						{
							logprint("Не найден цвет флага", 0);
							NoTeleportCount++;
							if(NoTeleportCount > 150)
							{
								startteleport = 0;
								logprint("Новая игра (Причина - превышение 150 кликов по флагу)", 0);
								BotNewGame();
							} else if(NoTeleportCount == 50)
							{
								StartLevel = 0;
							}
						}
					}
					

					



			}

		};

	}
	else
	{
		Sleep(2500);
	}

	}
	return 0;
}






//Стартуем новый раунд
void BotNewGame()
{
		logprint("Cтарт новой игры", 0);
		StartLevel = 0;

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

		noauthupdate = 1;
		endeventcount = 0;
		teleportstepcount = 0;
		RestartEventCount = 0;
		NoTeleportCount = 0;
		BotDeathCount = 0;
		FullSlot = 0;
		Event = 0;
		location = 1;

	if(restartgame == 0)
	{

		CaptureScreen(&globalscreengrab);
		int BotStatus = BotGetStatus(&globalscreengrab);

		if(BotStatus != 10)
		{

			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 ); 
			// Моделируем возврат клавиши в не нажатое состояние 
			keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

			CaptureScreen(&globalscreengrab);
			int BotStatus = BotGetStatus(&globalscreengrab);

			if(BotStatus != 15)
			{
				keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
				keybd_event( VK_ESCAPE, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,500);

				CaptureScreen(&globalscreengrab);
				BotStatus = BotGetStatus(&globalscreengrab);
			}

			if(BotStatus == 15)
			{
				SetCursorPosition(514,415);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100000);
			}
		}

	}
	else
	{
		if(firststart == 1)
		{
			firststart = 0;
		}
		else
		{
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,20000);
		}
	}
		
		SetCursorPosition(171,414);
		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,3000);



		if(GameSubMode == 1)
		{


			
			SetCursorPosition(412,202);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,3000);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);
			

			int downstep = 1;

			while(downstep <= downclicks)
			{
				SetCursorPosition(410,600);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

				BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,100);
				downstep++;
			}



			
			SetCursorPosition(110,ycoordinate);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);

		}


		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,1000);



		SetCursorPosition(684,618);

		mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
		mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )


		BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,60000);

		BotUpdateSession();

		CaptureScreen(&globalscreengrab);
		location = BotGetLocation();
		if(BotGetBotInGame(&globalscreengrab) == 1)
		{
			restartgame = 0;
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,160000);
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,rand() % 60000 + 100);
			BotNewGame();
		}
		else
		{

			if(((downclicks == 19) && (ycoordinate == 589)) ||
			   ((downclicks == 20) && (ycoordinate == 570)) ||
			   ((downclicks == 20) && (ycoordinate == 610))
			)
			{
				act4 = 1;
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,10000);

			if(LocationName == 1)
			{
				SetCursorPosition(250,330);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			}
			else if(LocationName == 2)
			{
				SetCursorPosition(280,400);
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
			}
			else if(LocationName == 3)
			{
				if(act4 == 1)
				{
					SetCursorPosition(500,670);
					Sleep(150);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
				}
				else
				{
					SetCursorPosition(300,378);
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
				}
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);

			if(buffbutton != 0)
			{
				if(buffbutton == 1)
				{
					keybd_event(49, 0,0,0);
					keybd_event(49, 0,KEYEVENTF_KEYUP,0);
				}
				else if(buffbutton == 2)
				{
					keybd_event(50, 0,0,0);
					keybd_event(50, 0,KEYEVENTF_KEYUP,0);
				}
				else if(buffbutton == 3)
				{
					keybd_event(51, 0,0,0);
					keybd_event(51, 0,KEYEVENTF_KEYUP,0);
				} 
				else if(buffbutton == 4)
				{
					keybd_event(52, 0,0,0);
					keybd_event(52, 0,KEYEVENTF_KEYUP,0);
				}
				else if(buffbutton == 5)
				{
					mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
				}
				else if(buffbutton == 6)
				{
					mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
					mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )
				}
			}

			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,200);

			restartgame = 0;
			startteleport = 1;
		}
}