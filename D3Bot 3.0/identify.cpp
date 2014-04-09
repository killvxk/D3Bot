#include "stdafx.h"
#include "identify.h"


int FindUsefulItems(BITMAPCAPTURE *grab)
{

	int found63lvl = 0;
		for(int y = 100; y < grab->height - 10; y++){
			for(int x = rx - 350; x < rx - 10; x++){

				DWORD lvl63mask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD lvl63mask2 = ColorNoAlpha(BitmapPixel(grab, x + 2, y - 4));
				DWORD lvl63mask3 = ColorNoAlpha(BitmapPixel(grab, x + 5, y - 2));
				DWORD lvl63mask4 = ColorNoAlpha(BitmapPixel(grab, x + 5, y + 1));
				DWORD lvl63mask5 = ColorNoAlpha(BitmapPixel(grab, x + 17, y - 3));
				DWORD lvl63mask6 = ColorNoAlpha(BitmapPixel(grab, x + 29, y - 1));
				DWORD lvl63mask7 = ColorNoAlpha(BitmapPixel(grab, x + 63, y - 3));
				DWORD lvl63mask8 = ColorNoAlpha(BitmapPixel(grab, x + 106, y - 2));
				DWORD lvl63mask9 = ColorNoAlpha(BitmapPixel(grab, x + 105, y - 2));
				DWORD lvl63mask10 = ColorNoAlpha(BitmapPixel(grab, x + 107, y - 2));

				if((lvl63mask1 == 0x00FFFFFF) && 
				   (lvl63mask2 == 0x00FFFFFF) && 
				   (lvl63mask3 == 0x00FFFFFF) && 
				   (lvl63mask4 == 0x00FFFFFF) && 
				   (lvl63mask5 == 0x00FFFFFF) && 
				   (lvl63mask6 == 0x00FFFFFF) && 
				   (lvl63mask7 == 0x00FFFFFF) && 
				   (lvl63mask8 == 0x00FFFFFF) && 
				   (lvl63mask9 != 0x00FFFFFF) && 
				   (lvl63mask10 != 0x00FFFFFF))
				{
					found63lvl = 1;
					break;
				}
        }
		if(found63lvl == 1)
		{
			break;
		}
    }



	int foundring = 0;
		for(int y = 100; y < grab->height - 10; y++){
			for(int x = rx - 350; x < rx - 10; x++){

				DWORD ringmask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD ringmask2 = ColorNoAlpha(BitmapPixel(grab, x, y + 4));
				DWORD ringmask3 = ColorNoAlpha(BitmapPixel(grab, x + 3, y));
				DWORD ringmask4 = ColorNoAlpha(BitmapPixel(grab, x + 14, y + 2));
				DWORD ringmask5 = ColorNoAlpha(BitmapPixel(grab, x + 19, y + 4));
				DWORD ringmask6 = ColorNoAlpha(BitmapPixel(grab, x + 40, y + 4));
				DWORD ringmask7 = ColorNoAlpha(BitmapPixel(grab, x + 55, y + 2));
				DWORD ringmask8 = ColorNoAlpha(BitmapPixel(grab, x + 58, y + 7));
				DWORD ringmask9 = ColorNoAlpha(BitmapPixel(grab, x + 64, y + 7));

				if((ringmask1 == 0x00FFFF00) && 
				   (ringmask2 == 0x00FFFF00) && 
				   (ringmask3 == 0x00FFFF00) && 
				   (ringmask4 == 0x00FFFF00) && 
				   (ringmask5 == 0x00FFFF00) && 
				   (ringmask6 == 0x00FFFF00) && 
				   (ringmask7 == 0x00FFFF00) && 
				   (ringmask8 == 0x00FFFF00) && 
				   (ringmask9 == 0x00FFFF00))
				{
					foundring = 1;
					break;
				}
        }
		if(foundring == 1)
		{
			break;
		}
    }




	int foundamulet = 0;
		for(int y = 100; y < grab->height - 10; y++){
			for(int x = rx - 350; x < rx - 10; x++){

				DWORD amuletmask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD amuletmask2 = ColorNoAlpha(BitmapPixel(grab, x, y + 4));
				DWORD amuletmask3 = ColorNoAlpha(BitmapPixel(grab, x + 3, y));
				DWORD amuletmask4 = ColorNoAlpha(BitmapPixel(grab, x + 14, y + 2));
				DWORD amuletmask5 = ColorNoAlpha(BitmapPixel(grab, x + 19, y + 4));
				DWORD amuletmask6 = ColorNoAlpha(BitmapPixel(grab, x + 43, y + 4));
				DWORD amuletmask7 = ColorNoAlpha(BitmapPixel(grab, x + 46, y + 2));
				DWORD amuletmask8 = ColorNoAlpha(BitmapPixel(grab, x + 51, y + 2));
				DWORD amuletmask9 = ColorNoAlpha(BitmapPixel(grab, x + 55, y + 6));

				if((amuletmask1 == 0x00FFFF00) && 
				   (amuletmask2 == 0x00FFFF00) && 
				   (amuletmask3 == 0x00FFFF00) && 
				   (amuletmask4 == 0x00FFFF00) && 
				   (amuletmask5 == 0x00FFFF00) && 
				   (amuletmask6 == 0x00FFFF00) && 
				   (amuletmask7 == 0x00FFFF00) && 
				   (amuletmask8 == 0x00FFFF00) && 
				   (amuletmask9 == 0x00FFFF00))
				{
					foundamulet = 1;
					break;
				}
        }
		if(foundamulet == 1)
		{
			break;
		}
    }

	if(itemvalue_yellow == 1)
	{
		return 1;
	}

	if(itemvalue_rings == 1)
	{
		if(foundring == 1)
		{
			return 1;
		}
	}

	if(itemvalue_amulets == 1)
	{
		if(foundamulet == 1)
		{
			return 1;
		}
	}

	if(itemvalue_arhonts == 1)
	{
		if(found63lvl == 1)
		{
			return 1;
		}
	}

	return 0;

}



int BotGetInventaryInfo(int slot_y, int slot_x)
{

	IplImage *object = GetIplImage(membit);

	int start_x, start_y, end_x, end_y;

	if(slot_x == 0)
	{
		start_x = 663;
		end_x = 695;
	}
	else if(slot_x == 1)
	{
		start_x = 697;
		end_x = 730;
	}
	else if(slot_x == 2)
	{
		start_x = 732;
		end_x = 765;
	}
	else if(slot_x == 3)
	{
		start_x = 767;
		end_x = 799;
	}
	else if(slot_x == 4)
	{
		start_x = 801;
		end_x = 834;
	}
	else if(slot_x == 5)
	{
		start_x = 836;
		end_x = 868;
	}
	else if(slot_x == 6)
	{
		start_x = 870;
		end_x = 903;
	}
	else if(slot_x == 7)
	{
		start_x = 905;
		end_x = 937;
	}
	else if(slot_x == 8)
	{
		start_x = 939;
		end_x = 972;
	}
	else if(slot_x == 9)
	{
		start_x = 974;
		end_x = 1007;
	}

	if(slot_y == 0)
	{
		start_y = 417;
		end_y = 449;
	}
	else if(slot_y == 1)
	{
		start_y = 451;
		end_y = 483;
	}
	else if(slot_y == 2)
	{
		start_y = 485;
		end_y = 517;
	}
	else if(slot_y == 3)
	{
		start_y = 519;
		end_y = 551;
	}
	else if(slot_y == 4)
	{
		start_y = 553;
		end_y = 585;
	}
	else if(slot_y == 5)
	{
		start_y = 587;
		end_y = 620;
	}

	cvSetImageROI(object, cvRect(start_x, start_y, end_x - start_x + 1, end_y - start_y + 1));
	IplImage *TemplateImage = cvCreateImage(cvGetSize(object), object->depth, object->nChannels);
	cvCopy(object, TemplateImage, NULL);

	if(BotTemplateMatch(slot_x, slot_y, IdentifyImageEmptySlots, TemplateImage, start_x, start_y, end_x, end_y) == 1)
	{
		cvResetImageROI(object);
		cvReleaseImage(&object);
		return 1;
	}

	if(BotTemplateMatch(slot_x, slot_y, IdentifyImageItemsToStash, TemplateImage, start_x, start_y, end_x, end_y) == 1)
	{
		cvResetImageROI(object);
		cvReleaseImage(&object);
		return 2;
	}

	cvResetImageROI(object);
	cvReleaseImage(&object);
	return 0;	

}




int FindIdentifyColor(BITMAPCAPTURE *grab)
{
	found = 0;
		for(y = 420; y < grab->height - 150; y++){
			for(x = 665; x < grab->width - 20; x++){

				DWORD itemmask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD itemmask2 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
				DWORD itemmask3 = ColorNoAlpha(BitmapPixel(grab, x + 3, y - 1));
				DWORD itemmask4 = ColorNoAlpha(BitmapPixel(grab, x + 7, y));
				DWORD itemmask5 = ColorNoAlpha(BitmapPixel(grab, x + 8, y + 1));
				DWORD itemmask6 = ColorNoAlpha(BitmapPixel(grab, x + 7, y + 6));
				DWORD itemmask7 = ColorNoAlpha(BitmapPixel(grab, x + 6, y + 7));
				DWORD itemmask8 = ColorNoAlpha(BitmapPixel(grab, x + 4, y + 10));
				DWORD itemmask9 = ColorNoAlpha(BitmapPixel(grab, x + 4, y + 15));
				DWORD itemmask10 = ColorNoAlpha(BitmapPixel(grab, x + 3, y + 1));

				if(((itemmask1 > 0x00C8C8C8) && 
				   (itemmask2 > 0x00C8C8C8) && 
				   (itemmask3 > 0x00C8C8C8) && 
				   (itemmask4 > 0x00C8C8C8) && 
				   (itemmask5 > 0x00C8C8C8) && 
				   (itemmask6 > 0x00C8C8C8) && 
				   (itemmask7 > 0x00C8C8C8) && 
				   (itemmask8 > 0x00C8C8C8) && 
				   (itemmask9 > 0x00C8C8C8)) && (itemmask10 < 0x004444C8))
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


int FindLegendaryItems(BITMAPCAPTURE *grab)
{
	int legendary = 0;
	found = 0;
		for(y = 100; y < grab->height - 10; y++){
			for(x = rx - 350; x < rx - 10; x++){
				
				DWORD set_itemmask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD set_itemmask2 = ColorNoAlpha(BitmapPixel(grab, x + 1, y));
				DWORD set_itemmask3 = ColorNoAlpha(BitmapPixel(grab, x + 13, y - 1));
				DWORD set_itemmask4 = ColorNoAlpha(BitmapPixel(grab, x + 18, y - 1));
				DWORD set_itemmask5 = ColorNoAlpha(BitmapPixel(grab, x + 21, y - 1));
				DWORD set_itemmask6 = ColorNoAlpha(BitmapPixel(grab, x + 24, y - 1));
				DWORD set_itemmask7 = ColorNoAlpha(BitmapPixel(grab, x + 30, y - 1));

				DWORD leg_itemmask1 = ColorNoAlpha(BitmapPixel(grab, x, y));
				DWORD leg_itemmask2 = ColorNoAlpha(BitmapPixel(grab, x + 4, y));
				DWORD leg_itemmask3 = ColorNoAlpha(BitmapPixel(grab, x + 4, y + 7));
				DWORD leg_itemmask4 = ColorNoAlpha(BitmapPixel(grab, x + 13, y + 2));
				DWORD leg_itemmask5 = ColorNoAlpha(BitmapPixel(grab, x + 23, y + 4));
				DWORD leg_itemmask6 = ColorNoAlpha(BitmapPixel(grab, x + 30, y + 2));

				if((((set_itemmask1 == 0x00FF0000) || (set_itemmask1 == 0x0000FF00) || (set_itemmask1 == 0x00BF642F)) &&
				   (set_itemmask1 == set_itemmask2) && 
				   (set_itemmask1 == set_itemmask3) && 
				   (set_itemmask1 == set_itemmask4) && 
				   (set_itemmask1 == set_itemmask5) && 
				   (set_itemmask1 == set_itemmask6) && 
				   (set_itemmask1 == set_itemmask7)) 
				   
				   || 
				   

				   (((leg_itemmask1 == 0x00FF0000) || (leg_itemmask1 == 0x0000FF00) || (leg_itemmask1 == 0x00BF642F)) && 
				   (leg_itemmask1 == leg_itemmask2) && 
				   (leg_itemmask1 == leg_itemmask3) && 
				   (leg_itemmask1 == leg_itemmask4) && 
				   (leg_itemmask1 == leg_itemmask5) && 
				   (leg_itemmask1 == leg_itemmask6)))
				{
					legendary = 1;
					logprint("Определили легендарный предмет!", 0);
					break;
				}


        }
		if(legendary == 1)
		{
			break;
		}
    }
    if(legendary == 0)
	{
		return 0;
	}
	else if(legendary == 1)
	{
		return 1;
	}
}




void BotIdentifyItems()
{

	while(1)
	{
		SetCursorPosition(10,13);
		Sleep(400);
		CaptureScreen(&globalscreengrab);
		if(FindIdentifyColor(&globalscreengrab) == 0)
		{
			break;
		}
		else
		{
			SetCursorPosition(rx,ry);
			Sleep(500);
			CaptureScreen(&globalscreengrab);

			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); // нажали левую кнопку мыши
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0); // отпустили левую кнопку мыши ( НЕ ЗАБЫВАТЬ )

			if(FindLegendaryItems(&globalscreengrab) == 1)
			{
				Sleep(7000);
				Item_x.push_back(rx);
				Item_y.push_back(ry);
				logprint("Легендарный предмет распознан и занесен в массив", 0);
			}
			else
			{
				Sleep(3000);
				CaptureScreen(&globalscreengrab);
				if(FindUsefulItems(&globalscreengrab) == 0)
				{
					//если вещь бесполезная тупо оставляем в инвентаре - выкинет на поле битвы
					logprint("Вещь бесполезна", 0);
				}
				else
				{
					Item_x.push_back(rx);
					Item_y.push_back(ry);
					logprint("Вещь полезна, занесена в массив", 0);
				}
			}
		}
	}
}




int BotTemplateMatch(int slot_x, int slot_y, IplImage *Source, IplImage *TemplateImage, int start_x, int start_y, int end_x, int end_y)
{

	IplImage *aaresult = cvCreateImage(cvSize(Source->width - TemplateImage->width + 1,Source->height - TemplateImage->height + 1),32,1);
	cvMatchTemplate( Source, TemplateImage, aaresult, CV_TM_CCOEFF_NORMED);

	double min,max;
	CvPoint minpos, maxpos;
	cvMinMaxLoc(aaresult,&min,&max,&minpos,&maxpos);

	if(max > 0.8)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}