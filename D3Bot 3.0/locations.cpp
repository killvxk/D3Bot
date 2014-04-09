#include "stdafx.h"
#include "locations.h"


int BotGetLocation()
{

	if(DetectLocation(&globalscreengrab) == 1)
	{
		LoadLocation = 1;
	}
	else
	{
		LoadLocation = 0;
	}



	if(DetectHiddenCamp(&globalscreengrab) == 1)
	{
		LocationName = 2;
		return 1;
	} else if(DetectCaldey(&globalscreengrab) == 1)
	{
		LocationName = 0;
		return 0;
	} else if(DetectBastion(&globalscreengrab) == 1)
	{
		LocationName = 3;
		return 1;
	} else if(DetectNewTristram(&globalscreengrab) == 1)
	{
		LocationName = 1;
		return 1;
	}

	if(DetectCity(&globalscreengrab) == 1)
	{
		CaptureScreen(&globalscreengrab);
		BotGetLocation();
	} 
	else 
	{
		LocationName = 0;
		return 0;
	};

}




int DetectBastion(BITMAPCAPTURE *grab)
{
	if((ColorNoAlpha(BitmapPixel(grab, 817, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 826, 11)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 843, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 845, 13)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 843, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 882, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 882, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 902, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 899, 17)) == 0x00FFFFFF))
	{
			return 1;
	}
	else
	{
			return 0;
	}
}


int DetectLocation(BITMAPCAPTURE *grab)
{

	int whitecolors = 0;

    for(y = 10; y < 18; y++){
        for(x = 870; x < 1000; x++){

			DWORD currentitemcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			
			if(currentitemcolor == 0x00FFFFFF)
			{
				whitecolors++;
			}

		}
	}

	if((whitecolors > 0) && (whitecolors < 500))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int DetectNewTristram(BITMAPCAPTURE *grab)
{
	if((ColorNoAlpha(BitmapPixel(grab, 896, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 904, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 906, 13)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 904, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 911, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 973, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 980, 10)) == 0x00FFFFFF))
	{
			return 1;
	}
	else
	{
			return 0;
	}
}


int GetLocationHash(BITMAPCAPTURE *grab)
{

	int whitecolors = 0;
	int hash = 0;

    for(y = 10; y < 18; y++){
        for(x = 740; x < 1005; x++){

			DWORD currentitemcolor = ColorNoAlpha(BitmapPixel(grab, x, y));
			
			if(currentitemcolor == 0x00FFFFFF)
			{
				hash = hash + (x * y) * 2;
			}

		}
	}

	return hash;
}

int DetectCity(BITMAPCAPTURE *grab)
{

    for(y = 650; y < 676; y++){
        for(x = 306; x < 540; x++){

			DWORD mask1 = ColorNoAlpha(BitmapPixel(grab, x, y));

			if(mask1 == 0x00190D09)
			{
				DWORD mask2 = ColorNoAlpha(BitmapPixel(grab, x + 9, y + 5));
				DWORD mask3 = ColorNoAlpha(BitmapPixel(grab, x - 6, y + 6));
				DWORD mask4 = ColorNoAlpha(BitmapPixel(grab, x + 11, y + 9));
				DWORD mask5 = ColorNoAlpha(BitmapPixel(grab, x + 1, y + 16));

				if((mask2 == 0x00060302) && 
				   (mask3 == 0x009A6B4B) && 
				   (mask4 == 0x00F8EC90) && 
				   (mask5 == 0x00B3A927))
				{
					return 1;
				}
			}
        }
    }

	return 0;

}


int DetectHiddenCamp(BITMAPCAPTURE *grab)
{
	if((ColorNoAlpha(BitmapPixel(grab, 899, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 935, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 962, 11)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 979, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 986, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 986, 13)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 986, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 994, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 1001, 17)) == 0x00FFFFFF))
	{
			return 1;
	}
	else
	{
			return 0;
	}
}





int DetectCaldey(BITMAPCAPTURE *grab)
{
	if((ColorNoAlpha(BitmapPixel(grab, 890, 11)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 899, 11)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 906, 10)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 906, 13)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 906, 17)) == 0x00FFFFFF) &&
	   (ColorNoAlpha(BitmapPixel(grab, 1001, 10)) == 0x00FFFFFF))
	{
			return 1;
	}
	else
	{
			return 0;
	}
}