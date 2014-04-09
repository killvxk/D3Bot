#include "stdafx.h"
#include "vision.h"




int BotGetStatus(BITMAPCAPTURE *grab)
{

	if((ColorNoAlpha(BitmapPixel(grab, 30, 30)) == 0x00000000) && (ColorNoAlpha(BitmapPixel(grab, 1000, 20)) == 0x00000000) && (ColorNoAlpha(BitmapPixel(grab, 1000, 720)) == 0x00000000) && (ColorNoAlpha(BitmapPixel(grab, 20, 720)) == 0x00000000))
	{
		//VideoEvent
		logprint("Идет видео заставка", 0);
		BotCurrentStatus = 20;
		return 20;
	} else if((ColorNoAlpha(BitmapPixel(grab, 497, 131)) == 0x00C58600) && (ColorNoAlpha(BitmapPixel(grab, 506, 131)) == 0x00C58600))
	{
		//SalvageAccept and AcceptNotFullEvent
		logprint("Подтверждение разбития предмета или подтверждение вступления в бой не полной пати", 0);
		BotCurrentStatus = 16;
		return 16;
	} else if((ColorNoAlpha(BitmapPixel(grab, 497, 60)) == 0x00FFFFFF) && (ColorNoAlpha(BitmapPixel(grab, 506, 60)) == 0x00FFFFFF) && (ColorNoAlpha(BitmapPixel(grab, 533, 60)) == 0x00FFFFFF))
	{
		//AcceptEvent
		logprint("Подтверждение участия в событии", 0);
		BotCurrentStatus = 1;
		noauthupdate = 1;
		return 1;
	} else if((ColorNoAlpha(BitmapPixel(grab, 476, 301)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 508, 301)) == 0x00FFA300))
	{
		//SendManyCommandsToServer
		logprint("Превышение максимального количества команд", 0);
		BotCurrentStatus = 2;
		return 2;
	} else if(ColorNoAlpha(BitmapPixel(grab, 508, 303)) == 0x00E28F01)
	{
		//ErrorConnectServer
		logprint("Ошибка соединения с сервером", 0);
		BotCurrentStatus = 3;
		return 3;
	} else if((ColorNoAlpha(BitmapPixel(grab, 475, 194)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 477, 197)) == 0x00FFA300))
	{
		//Menu
		logprint("Меню", 0);
		BotCurrentStatus = 15;
		return 15;
	} else if((ColorNoAlpha(BitmapPixel(grab, 449, 301)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 462, 303)) == 0x00FFA300))
	{
		//Kick
		logprint("Нас кикнули", 0);
		BotCurrentStatus = 8;
		return 8;
	} else if((ColorNoAlpha(BitmapPixel(grab, 466, 538)) == 0x00F3AA55) && (ColorNoAlpha(BitmapPixel(grab, 553, 540)) == 0x00F3AA55))
	{
		//Ressurect
		logprint("Нас воскресили", 0);
		BotCurrentStatus = 17;
		return 17;
	} else if((ColorNoAlpha(BitmapPixel(grab, 377, 601)) == 0x00F3AA55) && (ColorNoAlpha(BitmapPixel(grab, 663, 599)) == 0x00F3AA55))
	{
		//Death
		logprint("Мы умерли", 0);
		BotCurrentStatus = 4;
		noauthupdate = 1;
		return 4;
	} else if(((ColorNoAlpha(BitmapPixel(grab, 97, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 264, 92)) == 0x00FFA300)) ||
			  ((ColorNoAlpha(BitmapPixel(grab, 86, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 117, 92)) == 0x00FFA300)) ||
			  ((ColorNoAlpha(BitmapPixel(grab, 118, 98)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 131, 92)) == 0x00FFA300)))
	{
		//Salvage
		logprint("Разбор предметов", 0);
		BotCurrentStatus = 13;
		return 13;
	} else if((ColorNoAlpha(BitmapPixel(grab, 164, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 803, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 819, 95)) == 0x00FFA300))
	{
		//Stash
		//Добавить вторую проверку
		logprint("Сундук", 0);
		BotCurrentStatus = 5;
		return 5;
	} else if( ((ColorNoAlpha(BitmapPixel(grab, 714, 551)) == 0x00080400) || (ColorNoAlpha(BitmapPixel(grab, 714, 551)) == 0x00070400)) && ((ColorNoAlpha(BitmapPixel(grab, 748, 551)) == 0x00080400) || (ColorNoAlpha(BitmapPixel(grab, 748, 551)) == 0x00070400)))
	{
		//EmptySlots
		logprint("Слоты пустые", 0);
		BotCurrentStatus = 14;
		return 14;
	} else if( ((ColorNoAlpha(BitmapPixel(grab, 118, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 137, 92)) == 0x00FFA300)) ||
			   ((ColorNoAlpha(BitmapPixel(grab, 165, 99)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 192, 96)) == 0x00FFA300)) ||
			   ((ColorNoAlpha(BitmapPixel(grab, 169, 99)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 206, 96)) == 0x00FFA300)) ||
			   ((ColorNoAlpha(BitmapPixel(grab, 164, 92)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 201, 99)) == 0x00FFA300)))
	{
		//WayPoint-Trader (Close windows)
		logprint("Врата странствий", 0);
		BotCurrentStatus = 7;
		return 7;
	} else if((ColorNoAlpha(BitmapPixel(grab, 530, 545)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 588, 545)) == 0x00FFA300))
	{
		//EndEvent
		logprint("Конец миссии", 0);
		BotCurrentStatus = 9;
		noauthupdate = 1;
		return 9;
	} else if((ColorNoAlpha(BitmapPixel(grab, 531, 545)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 637, 545)) == 0x00FFA300))
	{
		//EndEvent2
		logprint("Конец события", 0);
		BotCurrentStatus = 12;
		return 12;
	} else if(((ColorNoAlpha(BitmapPixel(grab, 116, 293)) == 0x00F3AA55) && (ColorNoAlpha(BitmapPixel(grab, 138, 293)) == 0x00F3AA55)) ||
			  ((ColorNoAlpha(BitmapPixel(grab, 160, 293)) == 0x00F3AA55) && (ColorNoAlpha(BitmapPixel(grab, 181, 293)) == 0x00F3AA55)))
	{
		//Main
		logprint("Главное окно диаблы", 0);
		BotCurrentStatus = 10;
		return 10;
	} else if((ColorNoAlpha(BitmapPixel(grab, 991, 269)) == 0x00FFE7A5) && (ColorNoAlpha(BitmapPixel(grab, 992, 269)) == 0x00FFE7A5))
	{
		//Plus
		logprint("Задачи не скрыты", 0);
		BotCurrentStatus = 18;
		return 18;
	} else if(((ColorNoAlpha(BitmapPixel(grab, 480, 430)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 531, 430)) == 0x00FFA300) && (ColorNoAlpha(BitmapPixel(grab, 493, 432)) == 0x00FFA300)))
	{
		//AcceptKick
		logprint("Подтвердить кик союзника", 0);
		BotCurrentStatus = 19;
		return 19;
	} else {
		BotCurrentStatus = 0;
		return 0;
	};


}










int BotGetFlagStatus(BITMAPCAPTURE *grab)
{

    found = 0;
	int starty, startx, minusy, minusx;

	starty = 0;
	startx = 0;
	minusy = 130;
	minusx = 0;                                                                                                                                                       

    for(y = starty; y < grab->height - minusy; y++){
        for(x = startx; x < grab->width - minusx; x++){
			
			if((ColorNoAlpha(BitmapPixel(grab, x, y))) == (ColorNoAlpha(BitmapPixel(grab, x, y + 1))))
			{
				if((ColorNoAlpha(BitmapPixel(grab, x, y)) == 0x00C7B377) && 
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 1)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 2)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 3)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 4)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 5)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 6)) == 0x00C7B377) &&
				   (ColorNoAlpha(BitmapPixel(grab, x, y + 7)) == 0x00C7B377)
				  )
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y + 15)) == 0x00FFFFFF) && 
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 22)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 18)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 5, y + 18)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 39, y + 15)) == 0x00FFFFFF)
					  )
					{
						//NewTristram;
					}
					else if((ColorNoAlpha(BitmapPixel(grab, x + 2, y + 15)) == 0x00FFFFFF) && 
					   (ColorNoAlpha(BitmapPixel(grab, x + 2, y + 22)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 16, y + 18)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 45, y + 17)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 71, y + 19)) == 0x00FFFFFF)
					  )
					{
						//HiddenCamp;
					}
					else if((ColorNoAlpha(BitmapPixel(grab, x, y + 15)) == 0x00FFFFFF) && 
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 17)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 18, y + 17)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 57, y + 22)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 81, y + 15)) == 0x00FFFFFF)
					  )
					{
						//Bastion;
					}
					else if((ColorNoAlpha(BitmapPixel(grab, x + 9, y + 21)) == 0x00FFFFFF) && 
					   (ColorNoAlpha(BitmapPixel(grab, x + 17, y + 21)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 23, y + 19)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 25, y + 17)) == 0x00FFFFFF) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 43, y + 19)) == 0x00FFFFFF)
					  )
					{
						//Bastion: Amunition;
					}
					else
					{
						found = 1;
						break;
					}
				}
			}
        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}











int BotGetBotInGame(BITMAPCAPTURE *grab)
{

	BotGetScreenPng();
	IplImage *object = GetIplImage(membit);

	cvSetImageROI(object, cvRect(31, 9, 21, 7));
	__int64 mynickimagehash = calcImageHash(object, false);
	cvResetImageROI(object);

	char *mynickhash = (char*)malloc(32);
	sprintf(mynickhash, "%I64d", mynickimagehash);



	char *NickHashdatahttpquery = (char*)malloc(strlen("http://178.132.203.196/D3Bot/nickname-updatehash.php?authkey=") + strlen(TestKey) + strlen("&nickhash=") + strlen(mynickhash) + 1);
	sprintf(NickHashdatahttpquery, "%s%s%s%s", "http://178.132.203.196/D3Bot/nickname-updatehash.php?authkey=", TestKey, "&nickhash=", mynickhash);
	string NickHashurls = NickHashdatahttpquery;
	CURLcode NickHashresult;
	string NickHashbuffer;

	curl_easy_setopt(curl, CURLOPT_URL, NickHashurls.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &NickHashbuffer);
	NickHashresult = curl_easy_perform(curl);





	cvSetImageROI(object, cvRect(31, 110, 21, 7));
	__int64 secondnickimagehash = calcImageHash(object, false);
	cvResetImageROI(object);

	char *secondnickhash = (char*)malloc(32);
	sprintf(secondnickhash, "%I64d", secondnickimagehash);




	cvSetImageROI(object, cvRect(31, 210, 21, 7));
	__int64 thirdnickimagehash = calcImageHash(object, false);
	cvResetImageROI(object);

	char *thirdnickhash = (char*)malloc(32);
	sprintf(thirdnickhash, "%I64d", thirdnickimagehash);




	cvSetImageROI(object, cvRect(31, 311, 21, 7));
	__int64 fourthnickimagehash = calcImageHash(object, false);
	cvResetImageROI(object);

	char *fourthnickhash = (char*)malloc(32);
	sprintf(fourthnickhash, "%I64d", fourthnickimagehash);


	char *PlayerNickHashdatahttpquery = (char*)malloc(strlen("http://178.132.203.196/D3Bot/nickname-getdistance.php?nickhash1=") + strlen(secondnickhash) + strlen("&nickhash2=") + strlen(thirdnickhash) + strlen("&nickhash3=") + strlen(fourthnickhash) + 1);
	sprintf(PlayerNickHashdatahttpquery, "%s%s%s%s%s%s", "http://178.132.203.196/D3Bot/nickname-getdistance.php?nickhash1=", secondnickhash, "&nickhash2=", thirdnickhash, "&nickhash3=", fourthnickhash);
	string PlayerNickHashurls = PlayerNickHashdatahttpquery;
	CURLcode PlayerNickHashresult;
	string PlayerNickHashbuffer;

	curl_easy_setopt(curl, CURLOPT_URL, PlayerNickHashurls.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &PlayerNickHashbuffer);
	PlayerNickHashresult = curl_easy_perform(curl);

	cvReleaseImage(&object);
	if(PlayerNickHashbuffer == "0")
	{
		return 0;
	}
	else if(PlayerNickHashbuffer == "1")
	{
		return 1;
	}
	else
	{
		return 0;
	}

}



int FindAllColor(BITMAPCAPTURE *grab, DWORD mydvmin_Color, DWORD mydvmax_Color, int stepy, int stepx, int stepheight, int stepwidth)
{
    allcolor = 0;
    for(y = stepy; y < stepheight; y++){
		for(x = stepx; x < stepwidth; x++){

			DWORD mydvcurrentcolor = ColorNoAlpha(BitmapPixel(grab, x, y));

			int currentredcolor = GetRValue(mydvcurrentcolor);
			int currentgreencolor = GetGValue(mydvcurrentcolor);
			int currentbluecolor = GetBValue(mydvcurrentcolor);

			int minredcolor = GetRValue(mydvmin_Color);
			int mingreencolor = GetGValue(mydvmin_Color);
			int minbluecolor = GetBValue(mydvmin_Color);

			int maxredcolor = GetRValue(mydvmax_Color);
			int maxgreencolor = GetGValue(mydvmax_Color);
			int maxbluecolor = GetBValue(mydvmax_Color);

            if( ((currentredcolor > minredcolor) && (currentredcolor < maxredcolor)) &&
				((currentgreencolor > mingreencolor) && (currentgreencolor < maxgreencolor)) &&
				((currentbluecolor > minbluecolor) && (currentbluecolor < maxbluecolor))
			){
                allcolor++;
            }
        }
    }

	return allcolor;
}





int GetRGBRange(int x, int y, int maxred, int maxgreen, int maxblue, int minred, int mingreen, int minblue)
{
		COLORREF currentpixelcol = GetPixel(memdc, x, y);
		int GetRGBRangered = GetRValue(currentpixelcol);
		int GetRGBRangegreen = GetGValue(currentpixelcol);
		int GetRGBRangeblue = GetBValue(currentpixelcol);

		if(((GetRGBRangered < maxred) && (GetRGBRangegreen < maxgreen) && (GetRGBRangeblue < maxblue)) && ((GetRGBRangered > minred) && (GetRGBRangegreen > mingreen) && (GetRGBRangeblue > minblue)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
}

int FindAttackColor(BITMAPCAPTURE *grab)
{

	if(FindMiniAttackColor(&globalscreengrab) == 1)
	{
		return 1;
	}

    found = 0;
	int starty, startx, minusy, minusx;

	starty = 0;
	startx = 0;
	minusy = 130;
	minusx = 0;                                                                                                                                                       

    for(y = starty; y < grab->height - minusy; y++){
        for(x = startx; x < grab->width - minusx; x++){

			DWORD currentattackcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			DWORD currentattackcolor2 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
			
			if(currentattackcolor == currentattackcolor2)
			{

				//2.1
				//DWORD dwAttackRedColor = 0x00B30400; // Красная полоска
				//DWORD dwAttackRedColor2 = 0x00B20400; // Красная полоска 2
				//DWORD dwAttackRedColor3 = 0x00B20100; // Красная полоска 3
				//DWORD dwAttackRedColor4 = 0x00F70000; // Красная полоска 4
				//DWORD dwAttackRedColor5 = 0x00B20400; // Красная полоска 5
				//DWORD dwAttackRedColor6 = 0x00B60400; // Красная полоска 5
				//DWORD dwAttackRedColor7 = 0x00B20300; // Красная полоска 2

				DWORD dwAttackRedColor = 0x00DC0100; // Красная полоска 4
				DWORD dwAttackRedColor2 = 0x00B20100; // Красная полоска 2
				DWORD dwAttackRedColor3 = 0x00F70000; // Красная полоска 5

				if((currentattackcolor == dwAttackRedColor) || (currentattackcolor == dwAttackRedColor2) || (currentattackcolor == dwAttackRedColor3))
				{
					rx = x;
					ry = y;
					found = 1;
					break;
				}
			}

        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int FindMiniAttackColor(BITMAPCAPTURE *grab)
{
    found = 0;

    for(y = 200; y < 420; y++){
        for(x = 400; x < 620; x++){

			DWORD currentattackcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			DWORD currentattackcolor2 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
			
			if(currentattackcolor == currentattackcolor2)
			{

				DWORD dwAttackRedColor = 0x00DC0100; // Красная полоска 4
				DWORD dwAttackRedColor2 = 0x00B20100; // Красная полоска 2
				DWORD dwAttackRedColor3 = 0x00F70000; // Красная полоска 5

				if((currentattackcolor == dwAttackRedColor) || (currentattackcolor == dwAttackRedColor2) || (currentattackcolor == dwAttackRedColor3))
				{
					rx = x;
					ry = y;
					found = 1;
					break;
				}
			}

        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int FindFollowColor(BITMAPCAPTURE *grab)
{

    for(y = 160; y < 530; y++){
        for(x = 280; x < 720; x++){

			DWORD currentcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			DWORD dwPlayerGreenColor = 0x0000A500; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor2 = 0x00009200; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor3 = 0x0000E700; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor4 = 0x0000A300; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor5 = 0x0000D900; // Зеленая полоска союзника

			if((currentcolor == dwPlayerGreenColor) || (currentcolor == dwPlayerGreenColor2) || (currentcolor == dwPlayerGreenColor3) || (currentcolor == dwPlayerGreenColor4) || (currentcolor == dwPlayerGreenColor5))
			{
				rx = x;
				ry = y;
				return 1;
			}

        }
    }


	found = 0;
	int starty, startx, minusy, minusx;
	starty = 0;
	startx = 0;
	minusy = 0;
	minusx = 0;                                                                                                                                                       

    for(y = starty; y < grab->height - minusy; y++){
        for(x = startx; x < grab->width - minusx; x++){

			DWORD currentcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			DWORD dwPlayerGreenColor = 0x0000A500; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor2 = 0x00009200; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor3 = 0x0000E700; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor4 = 0x0000A300; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor5 = 0x0000D900; // Зеленая полоска союзника

			if((currentcolor == dwPlayerGreenColor) || (currentcolor == dwPlayerGreenColor2) || (currentcolor == dwPlayerGreenColor3) || (currentcolor == dwPlayerGreenColor4) || (currentcolor == dwPlayerGreenColor5))
			{
				rx = x;
				ry = y;
				found = 1;
				break;
			}

        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int FindItemColor(BITMAPCAPTURE *grab)
{

	if(noauth == 1)
	{
		Sleep(5000);
	}

    found = 0;

	int starty, startx, minusy, minusx;
	starty = 40;
	startx = 0;
	
	minusy = 80;
	minusx = 0;

    for(y = starty; y < grab->height - minusy; y++){
        for(x = startx; x < grab->width - minusx; x++){
				
			if( (((y < 530) || ((y > 620) && (y < 685))) || (x > 300)) && ((y > 70) && (x > 140)) )
			{
				DWORD CurrentItemColor = ColorNoAlpha(BitmapPixel(grab, x, y));
				
				DWORD BlueColor = 0x006969FF; // Синие
				DWORD YellowColor = 0x00FFFF00; // Желтые
				DWORD LegendaryColor = 0x00BF642F; // Легендарки
				DWORD GreenColor = 0x0000FF00; // Сетовые
				DWORD PotionGemBooksColor = 0x0099BBFF; // Хилки
				DWORD GoldColor = 0x00FFFFFF; // Золото

				if((CurrentItemColor == LegendaryColor) && (itemvalue_legendary == 1))
				{
					int ItemColorCount = 0;
					int NoItemColorCount = 0;
					int ItemColorMaxCount = 0;
					for(int currentitemy = y; currentitemy < y+6; currentitemy++){
						for(int currentitemx = x; currentitemx < x + 15; currentitemx++){

							int currenty = currentitemy;
							int CurrentItemColorCount = 0;
							while(currenty <= currentitemy + 6)
							{
								if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currenty)) == LegendaryColor)
								{
									CurrentItemColorCount++;
									if(ItemColorMaxCount < CurrentItemColorCount)
									{
										ItemColorMaxCount = CurrentItemColorCount;
									}
								}
								currenty++;
							}

							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) == LegendaryColor)
							{
								ItemColorCount++;
							}
							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) < 0x00707070)
							{
								NoItemColorCount++;
							}
						}
					}

					if((ItemColorCount > 7) && (NoItemColorCount > 50) && (ItemColorMaxCount == 7))
					{
						logprint("Нашли легендарный предмет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == GreenColor) && (itemvalue_green == 1))
				{
					int ItemColorCount = 0;
					int NoItemColorCount = 0;
					int ItemColorMaxCount = 0;
					for(int currentitemy = y; currentitemy < y+6; currentitemy++){
						for(int currentitemx = x; currentitemx < x + 15; currentitemx++){

							int currenty = currentitemy;
							int CurrentItemColorCount = 0;
							while(currenty <= currentitemy + 6)
							{
								if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currenty)) == GreenColor)
								{
									CurrentItemColorCount++;
									if(ItemColorMaxCount < CurrentItemColorCount)
									{
										ItemColorMaxCount = CurrentItemColorCount;
									}
								}
								currenty++;
							}

							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) == GreenColor)
							{
								ItemColorCount++;
							}
							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) < 0x00707070)
							{
								NoItemColorCount++;
							}
						}
					}

					if((ItemColorCount > 7) && (NoItemColorCount > 50) && (ItemColorMaxCount == 7))
					{
						logprint("Нашли сетовый предмет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == YellowColor) && (itemvalue_yellow == 1))
				{
					int ItemColorCount = 0;
					int NoItemColorCount = 0;
					int ItemColorMaxCount = 0;
					for(int currentitemy = y; currentitemy < y+6; currentitemy++){
						for(int currentitemx = x; currentitemx < x + 15; currentitemx++){

							int currenty = currentitemy;
							int CurrentItemColorCount = 0;
							while(currenty <= currentitemy + 6)
							{
								if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currenty)) == YellowColor)
								{
									CurrentItemColorCount++;
									if(ItemColorMaxCount < CurrentItemColorCount)
									{
										ItemColorMaxCount = CurrentItemColorCount;
									}
								}
								currenty++;
							}

							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) == YellowColor)
							{
								ItemColorCount++;
							}
							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) < 0x00707070)
							{
								NoItemColorCount++;
							}
						}
					}

					if((ItemColorCount > 7) && (NoItemColorCount > 50) && (ItemColorMaxCount == 7))
					{
						logprint("Нашли желтый предмет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == BlueColor) && (itemvalue_blue == 1))
				{
					int ItemColorCount = 0;
					int NoItemColorCount = 0;
					int ItemColorMaxCount = 0;
					for(int currentitemy = y; currentitemy < y+6; currentitemy++){
						for(int currentitemx = x; currentitemx < x + 15; currentitemx++){

							int currenty = currentitemy;
							int CurrentItemColorCount = 0;
							while(currenty <= currentitemy + 6)
							{
								if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currenty)) == BlueColor)
								{
									CurrentItemColorCount++;
									if(ItemColorMaxCount < CurrentItemColorCount)
									{
										ItemColorMaxCount = CurrentItemColorCount;
									}
								}
								currenty++;
							}

							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) == BlueColor)
							{
								ItemColorCount++;
							}
							if(ColorNoAlpha(BitmapPixel(grab, currentitemx, currentitemy)) < 0x00707070)
							{
								NoItemColorCount++;
							}
						}
					}

					if((ItemColorCount > 7) && (NoItemColorCount > 50) && (ItemColorMaxCount == 7))
					{
						logprint("Нашли синий предмет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == PotionGemBooksColor) && (itemvalue_gems == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 1)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 5, y)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 11, y + 3)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 6)) == PotionGemBooksColor))
					{
						logprint("Нашли самоцвет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == PotionGemBooksColor) && (itemvalue_potions == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y + 1)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 7, y + 1)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 1)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 4, y + 9)) == PotionGemBooksColor))
					{
						logprint("Нашли зелье здоровья", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == PotionGemBooksColor) && (itemvalue_books == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 1)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 2, y + 4)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 3, y + 2)) == PotionGemBooksColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 3, y + 6)) == PotionGemBooksColor))
					{
						logprint("Нашли книгу тайн", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == YellowColor) && (itemvalue_recipes == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y + 4)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 14, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 20, y + 9)) == YellowColor))
					{
						logprint("Нашли рецепт", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == YellowColor) && (itemvalue_arhonts == 1))
				{
					//Архонтовы вещи
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x - 1, y + 1)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 3, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 12)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 21, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 3)) == YellowColor))
					{
						logprint("Нашли Архонтовы вещи", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Изогнутый топор
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 17, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 22, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 31, y + 6)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 66, y + 3)) == YellowColor))
					{
						logprint("Нашли Изогнутый топор", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Шипованные наручи
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 11, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 14, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 25, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 83, y + 6)) == YellowColor))
					{
						logprint("Нашли Шипованные наручи", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}



					//Убийственный меч
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 8, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 15, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 66, y + 5)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 101, y + 2)) == YellowColor))
					{
						logprint("Нашли Убийственный меч", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Темный клинок
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 2, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 10, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 41, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 59, y + 3)) == YellowColor))
					{
						logprint("Нашли Темный клинок", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Рунический меч
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 4, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 8)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 29, y + 7)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 73, y + 3)) == YellowColor))
					{
						logprint("Нашли Рунический меч", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Опустошительный жезл
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 7, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 57, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 110, y + 6)) == YellowColor))
					{
						logprint("Нашли Опустошительный жезл", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Высокие ножны
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 4, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 56, y + 6)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 93, y + 9)) == YellowColor))
					{
						logprint("Нашли Высокие ножны", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Уничтожитель
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 1, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 8, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 15, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 59, y + 5)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 77, y + 2)) == YellowColor))
					{
						logprint("Нашли Уничтожитель", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Священный щит
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 14, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 28, y + 10)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 52, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 80, y + 10)) == YellowColor))
					{
						logprint("Нашли Священный щит", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Центурионово копье
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 28, y + 12)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 87, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 107, y + 9)) == YellowColor))
					{
						logprint("Нашли Центурионово копье", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Небесная длань
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 18, y + 1)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 54, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 64, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 76, y + 4)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 90, y + 3)) == YellowColor))
					{
						logprint("Нашли Небесная длань", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Срыватель покровов
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x - 3, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 13, y + 6)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 37, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 66, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 86, y + 12)) == YellowColor))
					{
						logprint("Нашли Срыватель покровов", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Толстая цепь
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 2, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 10, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 16, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 30, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 44, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 56, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 73, y + 9)) == YellowColor))
					{
						logprint("Нашли Толстая цепь", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}

					//Тяжелая портупея
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 2, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 9, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 15, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 35, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 49, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 66, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 71, y + 12)) == YellowColor))
					{
						logprint("Нашли Тяжелая портупея", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}


				}
				
				if((CurrentItemColor == YellowColor) && (itemvalue_amulets == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x - 1, y + 1)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 3, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 6, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 16, y + 12)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 12, y + 3)) == YellowColor))
					{
						logprint("Нашли амулет", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
				if((CurrentItemColor == YellowColor) && (itemvalue_rings == 1))
				{
					if((ColorNoAlpha(BitmapPixel(grab, x, y)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 3, y + 2)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 10, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 18, y + 3)) == YellowColor) &&
					   (ColorNoAlpha(BitmapPixel(grab, x + 22, y + 9)) == YellowColor))
					{
						logprint("Нашли кольцо", 0);
						rx = x;
						ry = y;
						found = 1;
						break;
					}
				} 
				
			}

        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}










int DetectAct4()
{

	BotGetScreenPng();
	IplImage *object = GetIplImage(membit);

	cvSetImageROI(object, cvRect(917, 115, 6, 11));
	__int64 hashObject = calcImageHash(object, true);
	cvResetImageROI(object);
	cvReleaseImage(&object);

	if(calcHammingDistance(hashObject, 139638253484287) <= 3)
	{
		logprint("Мы в 4 акте", 0);
		return 1;
	}
	else
	{
		logprint("Мы не в 4 акте", 0);
		return 0;
	}

}




int FindFlagColor(BITMAPCAPTURE *grab)
{
    found = 0;
    for(y = 100; y < grab->height - 100; y++){
        for(x = 100; x < grab->width - 150; x++){

			if( (((y < 250) || ((y > 370) && (y < 685))) || (x < 770)) )
			{

				DWORD mycurrentrangecolor = ColorNoAlpha(BitmapPixel(grab, x, y));

				if(LocationName == 1)
				{
					if(
						((mycurrentrangecolor >= 0x00FCFC7F) && (mycurrentrangecolor <= 0x00FCFC93)) ||
						((mycurrentrangecolor >= 0x00EEF159) && (mycurrentrangecolor <= 0x00EEF15F)) ||
						((mycurrentrangecolor >= 0x00F7F949) && (mycurrentrangecolor <= 0x00F7F94F)) 
					  )
					{
						//((mycurrentrangecolor >= 0x00E8EA50) && (mycurrentrangecolor <= 0x00E8EA6F))
						if(!found){
							rx = x;
							ry = y;
							found = 1;
							break;
						}
					}
				}
				else if(LocationName == 2)
				{
					if(
						((mycurrentrangecolor >= 0x00FFFF50) && (mycurrentrangecolor <= 0x00FFFF58))
					  )
					{
						if(!found){
							rx = x;
							ry = y;
							found = 1;
							break;
						}
					}
				}
				else if(LocationName == 3)
				{
					if(
						((mycurrentrangecolor >= 0x00FFFF50) && (mycurrentrangecolor <= 0x00FFFF5F))
					  )
					{
						if(!found){
							rx = x;
							ry = y;
							found = 1;
							break;
						}
					}
				}


			}
			if(found == 1)
			{
				break;
			}
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int FindFriendDie(BITMAPCAPTURE *grab)
{

		DWORD player1hp = ColorNoAlpha(BitmapPixel(grab, 19, 177));
		DWORD player1hpcolor1 = ColorNoAlpha(BitmapPixel(grab, 20, 177));
		DWORD player1hpcolor2 = ColorNoAlpha(BitmapPixel(grab, 21, 177));

		if(player1hp == 0x00E98F27)
		{
			if( (player1hpcolor1 == 0x00A10000) && 
				(player1hpcolor2 == 0x00A10000) )
			{
				//return 1;
			}
			else
			{
				return 1;
			}
		}



		
		DWORD player2hp = ColorNoAlpha(BitmapPixel(grab, 19, 277));
		DWORD player2hpcolor1 = ColorNoAlpha(BitmapPixel(grab, 20, 277));
		DWORD player2hpcolor2 = ColorNoAlpha(BitmapPixel(grab, 21, 277));

		if(player2hp == 0x00DA8524)
		{
			if( (player2hpcolor1 == 0x00A10000) && 
				(player2hpcolor2 == 0x00A10000) )
			{
				//return 1;
			}
			else
			{
				return 1;
			}
		}




		DWORD player3hp = ColorNoAlpha(BitmapPixel(grab, 19, 378));
		DWORD player3hpcolor1 = ColorNoAlpha(BitmapPixel(grab, 20, 378));
		DWORD player3hpcolor2 = ColorNoAlpha(BitmapPixel(grab, 21, 378));
		
		if(player3hp == 0x00E98F27)
		{
			if( (player3hpcolor1 == 0x00A50000) && 
				(player3hpcolor2 == 0x00A50000) )
			{
				//return 1;
			}
			else
			{
				return 1;
			}
		}

	return 0;
}




int FindDieColor(BITMAPCAPTURE *grab)
{

    found = 0;

	int starty, startx, minusy, minusx, findlasercolor;
	
	starty = 80;
	startx = 0;

	minusy = 120;

	minusx = 0;
	findlasercolor = 0;

    for(y = starty; y < grab->height - minusy; y++){
        for(x = startx; x < grab->width - minusx; x++){
				
			if( ((y < 530) || (y > 620)) || (x > 300) )
			{
				DWORD currentdiecolor = ColorNoAlpha(BitmapPixel(grab, x, y));

				DWORD currentdiecolor1 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
				DWORD currentdiecolor2 = ColorNoAlpha(BitmapPixel(grab, x + 2, y));
				DWORD currentdiecolor3 = ColorNoAlpha(BitmapPixel(grab, x + 3, y));
				DWORD currentdiecolor4 = ColorNoAlpha(BitmapPixel(grab, x + 4, y));
				DWORD currentdiecolor5 = ColorNoAlpha(BitmapPixel(grab, x + 5, y));
				DWORD currentdiecolor6 = ColorNoAlpha(BitmapPixel(grab, x + 6, y));
				DWORD currentdiecolor7 = ColorNoAlpha(BitmapPixel(grab, x + 7, y));


				DWORD currentdiecolor8 = ColorNoAlpha(BitmapPixel(grab, x, y + 1));
				DWORD currentdiecolor9 = ColorNoAlpha(BitmapPixel(grab, x, y + 2));
				DWORD currentdiecolor10 = ColorNoAlpha(BitmapPixel(grab, x, y + 3));
				DWORD currentdiecolor11 = ColorNoAlpha(BitmapPixel(grab, x, y + 4));
				DWORD currentdiecolor12 = ColorNoAlpha(BitmapPixel(grab, x, y + 5));
				DWORD currentdiecolor13 = ColorNoAlpha(BitmapPixel(grab, x, y + 6));
				DWORD currentdiecolor14 = ColorNoAlpha(BitmapPixel(grab, x, y + 7));

				DWORD currentdiecolor15 = ColorNoAlpha(BitmapPixel(grab, x + 1, y + 7));
				DWORD currentdiecolor16 = ColorNoAlpha(BitmapPixel(grab, x + 2, y + 7));
				DWORD currentdiecolor17 = ColorNoAlpha(BitmapPixel(grab, x + 3, y + 7));
				DWORD currentdiecolor18 = ColorNoAlpha(BitmapPixel(grab, x + 4, y + 7));
				DWORD currentdiecolor19 = ColorNoAlpha(BitmapPixel(grab, x + 5, y + 7));
				DWORD currentdiecolor20 = ColorNoAlpha(BitmapPixel(grab, x + 6, y + 7));
				DWORD currentdiecolor21 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 7));

				DWORD currentdiecolor22 = ColorNoAlpha(BitmapPixel(grab, x + 7, y));
				DWORD currentdiecolor23 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 1));
				DWORD currentdiecolor24 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 2));
				DWORD currentdiecolor25 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 3));
				DWORD currentdiecolor26 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 4));
				DWORD currentdiecolor27 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 5));
				DWORD currentdiecolor28 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 6));
				DWORD currentdiecolor29 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 7));


				DWORD dwDieColor1 = 0x001B510D; // Зеленая хрень на полу
				DWORD dwDieColor2 = 0x00FFFFFF; // Лазер
				DWORD dwDieColor3 = 0x00FF66FF; // Лазер
				DWORD dwDieColor4 = 0x00FF3A0B; // Красная булькающая хрень на полу

				if(currentdiecolor == dwDieColor4)
				{
					rx = x;
					ry = y;
					found = 1;
					break;
				}

				if(currentdiecolor == dwDieColor1)
				{
					rx = x;
					ry = y;
					found = 1;
					break;
				}

				if(currentdiecolor == dwDieColor3)
				{
					findlasercolor = 1;
				}
				
				if ((findlasercolor == 1) && (currentdiecolor == dwDieColor2) && (currentdiecolor1 == dwDieColor2) && (currentdiecolor2 == dwDieColor2) && (currentdiecolor3 == dwDieColor2) && (currentdiecolor4 == dwDieColor2) && (currentdiecolor5 == dwDieColor2) && (currentdiecolor6 == dwDieColor2) && (currentdiecolor7 == dwDieColor2) && (currentdiecolor8 == dwDieColor2) && (currentdiecolor9 == dwDieColor2) && (currentdiecolor10 == dwDieColor2) && (currentdiecolor11 == dwDieColor2) && (currentdiecolor12 == dwDieColor2) && (currentdiecolor13 == dwDieColor2) && (currentdiecolor14 == dwDieColor2) && (currentdiecolor15 == dwDieColor2) && (currentdiecolor16 == dwDieColor2) && (currentdiecolor17 == dwDieColor2) && (currentdiecolor18 == dwDieColor2) && (currentdiecolor19 == dwDieColor2) && (currentdiecolor20 == dwDieColor2) && (currentdiecolor21 == dwDieColor2) && (currentdiecolor22 == dwDieColor2) && (currentdiecolor23 == dwDieColor2) && (currentdiecolor24 == dwDieColor2) && (currentdiecolor25 == dwDieColor2) && (currentdiecolor26 == dwDieColor2) && (currentdiecolor27 == dwDieColor2) && (currentdiecolor28 == dwDieColor2) && (currentdiecolor29 == dwDieColor2))
				{
					rx = x;
					ry = y;
					found = 1;
					break;
				}
			}

        }
		if(found == 1)
		{
			break;
		}
    }
    if(found)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




int DetectPlayersColors(BITMAPCAPTURE *grab, int startx, int starty, int endx, int endy)
{

	int playerscolors = 0;

    for(y = starty; y < endy; y++){
        for(x = startx; x < endx; x++){

			DWORD currentcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			DWORD dwPlayerGreenColor = 0x0000A500; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor2 = 0x00009200; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor3 = 0x0000E700; // Зеленая полоска союзника 2
			DWORD dwPlayerGreenColor4 = 0x0000A300; // Зеленая полоска союзника
			DWORD dwPlayerGreenColor5 = 0x0000D900; // Зеленая полоска союзника

			if((currentcolor == dwPlayerGreenColor) || (currentcolor == dwPlayerGreenColor2) || (currentcolor == dwPlayerGreenColor3) || (currentcolor == dwPlayerGreenColor4) || (currentcolor == dwPlayerGreenColor5))
			{
				playerscolors = 1;
				break;
			}

		}
		if(playerscolors == 1)
		{
			break;
		}
	}

	if(playerscolors == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int FindPlayersBeside(BITMAPCAPTURE *grab)
{

    for(y = 108; y < 185; y++){
        for(x = 856; x < 933; x++){

			DWORD mask1 = ColorNoAlpha(BitmapPixel(grab, x, y));

			if(mask1 == 0x005A92FF)
			{
				DWORD mask2 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
				DWORD mask3 = ColorNoAlpha(BitmapPixel(grab, x, y + 1));
				DWORD mask4 = ColorNoAlpha(BitmapPixel(grab, x + 1, y + 1));

				if((mask1 == mask2) || (mask1 == mask3) || (mask1 == mask4))
				{
					return 1;
				}
			}
        }
    }

	return 0;

}







int FindGateTravel(BITMAPCAPTURE *grab)
{

    for(y = 0; y < 1000; y++){
        for(x = 0; x < 680; x++){
			if((ColorNoAlpha(BitmapPixel(grab, x, y)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x, y + 9)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x + 9, y + 3)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x + 9, y + 12)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x + 47, y + 3)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x + 51, y + 12)) == 0x00FFFFFF) &&
				(ColorNoAlpha(BitmapPixel(grab, x + 102, y + 9)) == 0x00FFFFFF))
			{
					return 1;
			}
        }
    }

	return 0;

}


void BotGetMinimap(int intlocationhash)
{
	IplImage* rgb = 0;
	IplImage* h_plane = 0;
	IplImage* s_plane = 0;
	IplImage* v_plane = 0;
	IplImage* r_range = 0;
	IplImage* g_range = 0;
	IplImage* b_range = 0;
	IplImage* rgb_and = 0;

	CaptureScreen(&globalscreengrab);

	//начало получения миникарты
	BotGetScreenPng();
	IplImage *minimap = GetIplImage(membit);

	if(train == 1)
	{
		int p[3];
		p[0] = CV_IMWRITE_JPEG_QUALITY;
		p[1] = 30;
		p[2] = 0;
		cvSaveImage("screen.jpg", minimap, p);
	}

	cvSetImageROI(minimap, cvRect(831, 84, 128, 128));

	rgb = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 3 );
	h_plane = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	s_plane = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	v_plane = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	r_range = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	g_range = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	b_range = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	rgb_and = cvCreateImage( cvGetSize(minimap), IPL_DEPTH_8U, 1 );
	cvCvtColor( minimap, rgb, CV_BGR2HSV ); 
	cvCvtPixToPlane( rgb, h_plane, s_plane, v_plane, 0 );



	if(LOCATION_NEDRA_GORI_ARREAT == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_NIZHNIE_ETASHI_KREPOSTI_1 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(4), cvScalar(20), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(80), g_range);
		cvInRangeS(v_plane, cvScalar(55), cvScalar(100), b_range);
	}
	else if(LOCATION_KAMENNIY_FORT == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_NIZHNIE_ETASHI_KREPOSTI_3 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(4), cvScalar(20), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(80), g_range);
		cvInRangeS(v_plane, cvScalar(55), cvScalar(100), b_range);
	}
	else if(LOCATION_NIZHNIE_ETASHI_KREPOSTI_2 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(4), cvScalar(20), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(80), g_range);
		cvInRangeS(v_plane, cvScalar(55), cvScalar(100), b_range);
	}
	else if(LOCATION_ARREATSKIY_KRATER_1 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_BASHNYA_OBRECHENNUH_1 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(8), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(70), cvScalar(215), b_range);
	}
	else if(LOCATION_ARREATSKIY_KRATER_2 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_BASHNYA_PROKLYATIH_1 == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(8), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(70), cvScalar(215), b_range);
	}
	else if(LOCATION_SERDCE_GREHA == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(55), cvScalar(215), b_range);
	}
	else if(LOCATION_MOST_KORSIKKA == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(30), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_POLE_BOYA == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(30), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_POLYA_KROVAVOI_BOINY == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(30), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}
	else if(LOCATION_MOST_RAKKISA == intlocationhash)
	{
		cvInRangeS(h_plane, cvScalar(13), cvScalar(79), r_range);
		cvInRangeS(s_plane, cvScalar(40), cvScalar(170), g_range);
		cvInRangeS(v_plane, cvScalar(80), cvScalar(215), b_range);
	}

	cvAnd(r_range, g_range, rgb_and);
	cvAnd(rgb_and, b_range, rgb_and);
	CvSize size = cvSize( 3, 3 );
	CvPoint pt = cvPoint( 64, 64 );
	cvEllipse( rgb_and, pt, size, 0,0, 360, CV_RGB(0,0,0), 21,8,0 );

	cvSaveImage("minimap.png", rgb_and);
	//конец получения миникарты

	cvResetImageROI(minimap);
	cvReleaseImage(&minimap);
	cvReleaseImage(&rgb);
	cvReleaseImage(&h_plane);
	cvReleaseImage(&s_plane);
	cvReleaseImage(&v_plane);
	cvReleaseImage(&r_range);
	cvReleaseImage(&g_range);
	cvReleaseImage(&b_range);
	cvReleaseImage(&rgb_and);
}