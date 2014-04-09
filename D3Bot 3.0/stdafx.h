// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <cvaux.h>
#include <string.h>
#include <curl/curl.h>
#include <direct.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <locale>
#include <tchar.h>

using namespace std;

typedef struct _BITMAPCAPTURE {
    HBITMAP hbm;
    LPDWORD pixels;
    INT     width;
    INT     height;
} BITMAPCAPTURE;

#define ARGB_TO_COLORREF(a)     (COLORREF)(((a) & 0xFF00FF00) | (((a) & 0xFF0000) >> 16) | (((a) & 0xFF) << 16)) // ARGB to ABGR
#define BitmapPixel(b, x, y)    ((b)->pixels[(y) * (b)->width + (x)]) // pixel is ARGB
#define GetAValue(cr)           (int)((cr) >> 24)
#define ColorNoAlpha(p)         ((p) & 0x00FFFFFF)

#include "md5.h"
#include "boost/random.hpp" 
 
#include <iostream> 
#include <ctime> 