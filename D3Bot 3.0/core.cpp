#include "stdafx.h"
#include "core.h"

#include <sys/types.h>
#include <errno.h>

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

void logprint(std::string text, int ignore)
{
	if(ignore == -1)
	{
		logfile<<"["<<time(NULL)<<"] "<<text<<endl;
	}
	else
	{
		if(loglevel == 0)
		{

		} else if(loglevel == 1)
		{
			cout<<text<<endl;
		}
		else if((loglevel == 2) || (loglevel == -1))
		{
			cout<<text<<endl;
			if(ignore == 0)
			{
				logfile<<"["<<time(NULL)<<"] "<<text<<endl;
			}
		}
	}
}

void testMatch(IplImage* original, IplImage* templ)
{
        assert(original!=0);
        assert(templ!=0);

        printf("[i] test cvMatchShapes()\n");

        IplImage *src=0;

        src=cvCloneImage(original);

        IplImage* binI = cvCreateImage( cvGetSize(src), 8, 1);
        IplImage* binT = cvCreateImage( cvGetSize(templ), 8, 1);

        // заведём цветные картинки
        IplImage* rgb = cvCreateImage(cvGetSize(original), 8, 3);
        cvConvertImage(src, rgb, CV_GRAY2BGR);
        IplImage* rgbT = cvCreateImage(cvGetSize(templ), 8, 3);
        cvConvertImage(templ, rgbT, CV_GRAY2BGR);

        // получаем границы изображения и шаблона
        cvCanny(src, binI, 50, 200);
        cvCanny(templ, binT, 50, 200);

        // показываем
        cvNamedWindow( "cannyI", 1 );
        cvShowImage( "cannyI", binI);

        cvNamedWindow( "cannyT", 1 );
        cvShowImage( "cannyT", binT);

        // для хранения контуров
        CvMemStorage* storage = cvCreateMemStorage(0);
        CvSeq* contoursI=0, *contoursT=0;

        // находим контуры изображения
        int contoursCont = cvFindContours( binI, storage, &contoursI, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

        // для отметки контуров
        CvFont font;
        cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1.0, 1.0);
        int counter=0;

        // нарисуем контуры изображения
        if(contoursI!=0){
                for(CvSeq* seq0 = contoursI;seq0!=0;seq0 = seq0->h_next){
                        // рисуем контур
                        cvDrawContours(rgb, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8); 
                        // выводим его номер
                        //CvPoint2D32f point; float rad;
                        //cvMinEnclosingCircle(seq0,&point,&rad); // получим окружность содержащую контур
                        //cvPutText(rgb, itoa(++counter, buf, 10), cvPointFrom32f(point), &font, CV_RGB(0,255,0));
                }
        }
        // показываем
        cvNamedWindow( "cont", 1 );
        cvShowImage( "cont", rgb );

        cvConvertImage(src, rgb, CV_GRAY2BGR);

        // находим контуры шаблона
        cvFindContours( binT, storage, &contoursT, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

        CvSeq* seqT=0;
        double perimT = 0;

        if(contoursT!=0){
                // находим самый длинный контур 
                for(CvSeq* seq0 = contoursT;seq0!=0;seq0 = seq0->h_next){
                        double perim = cvContourPerimeter(seq0);
                        if(perim>perimT){
                                perimT = perim;
                                seqT = seq0;
                        }
                        // рисуем
                        cvDrawContours(rgbT, seq0, CV_RGB(255,216,0), CV_RGB(0,0,250), 0, 1, 8); // рисуем контур
                }
        }
        // покажем контур шаблона
        cvDrawContours(rgbT, seqT, CV_RGB(52,201,36), CV_RGB(36,201,197), 0, 2, 8); // рисуем контур
        cvNamedWindow( "contT", 1 );
        cvShowImage( "contT", rgbT );


        CvSeq* seqM=0;
        double matchM=1000;
        // обходим контуры изображения 
        counter=0;
        if(contoursI!=0){
                // поиск лучшего совпадения контуров по их моментам 
                for(CvSeq* seq0 = contoursI;seq0!=0;seq0 = seq0->h_next){
                        double match0 = cvMatchShapes(seq0, seqT, CV_CONTOURS_MATCH_I3);
                        if(match0<matchM){
                                matchM = match0;
                                seqM = seq0;
                        }
                        printf("[i] %d match: %.2f\n", ++counter, match0);
                }
        }
        // рисуем найденный контур
        cvDrawContours(rgb, seqM, CV_RGB(52,201,36), CV_RGB(36,201,197), 0, 2, 8); // рисуем контур

        cvNamedWindow( "find", 1 );
        cvShowImage( "find", rgb );

        // ждём нажатия клавиши
        cvWaitKey(0);

        // освобождаем ресурсы
        cvReleaseMemStorage(&storage);

        cvReleaseImage(&src);
        cvReleaseImage(&rgb);
        cvReleaseImage(&rgbT);
        cvReleaseImage(&binI);
        cvReleaseImage(&binT);

        // удаляем окна
        cvDestroyAllWindows();
}



void BotSleep(int type, int perem1, int perem2, int perem3, int perem4, int perem5, int perem6, int perem7, int perem8, int perem9, int perem10, int perem11, int sleeptime)
{

	if(noauth == 1)
	{
		Sleep(4000);
	}

	if(GetKeyState(0x14) == 0)
	{
		while(1)
		{
			if(GetKeyState(0x14) == 1)
			{
				break;
			}

			Sleep(sleeptime);
		}
	}
	int step = 0;

	if(type == 0)
	{
		Sleep(sleeptime);
	}
	else if(type == 1)
	{
		while(sleeptime / 100 > step)
		{
			CaptureScreen(&globalscreengrab);
			if(1 == 1)
			{
				break;
			}
			else
			{
				Sleep(100);
			}
			step++;
		}					
	}
}

BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture) // by Napalm
{
	DeleteObject(globalscreengrab.hbm);
    BOOL bResult = FALSE;
    if(!bmpCapture)
        return bResult;
    ZeroMemory(bmpCapture, sizeof(BITMAPCAPTURE));
    HDC hdcScreen  = GetDC(NULL);
    HDC hdcCapture = CreateCompatibleDC(NULL);
    int nWidth     = GetSystemMetrics(SM_CXSCREEN),
        nHeight    = GetSystemMetrics(SM_CYSCREEN);
    LPBYTE lpCapture;
    BITMAPINFO bmiCapture = { {
        sizeof(BITMAPINFOHEADER), nWidth, -nHeight, 1, 32, BI_RGB, 0, 0, 0, 0, 0,
    } };
    bmpCapture->hbm = CreateDIBSection(hdcScreen, &bmiCapture,
        DIB_RGB_COLORS, (LPVOID *)&lpCapture, NULL, 0);
    if(bmpCapture->hbm){
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcCapture, bmpCapture->hbm);
        BitBlt(hdcCapture, 0, 0, nWidth, nHeight, hdcScreen, 0, 0, SRCCOPY);
        SelectObject(hdcCapture, hbmOld);
        bmpCapture->pixels = (LPDWORD)lpCapture;
        bmpCapture->width  = nWidth;
        bmpCapture->height = nHeight;
        bResult = TRUE;
    }

    DeleteDC(hdcCapture);
    DeleteDC(hdcScreen);
    return bResult;
}

void BotGetScreenPng()
{
	DeleteObject(membit);
    DeleteDC(memdc);
    DeleteDC(scrdc);
    // Получаем HDC рабочего стола
    // Параметр HWND для рабочего стола всегда равен нулю.
    scrdc = GetDC(0);
    // Определяем разрешение экрана
    int Height, Width;
    Height = GetSystemMetrics(SM_CYSCREEN);
    Width = GetSystemMetrics(SM_CXSCREEN);
    // Создаем новый DC, идентичный десктоповскому и битмап размером с экран.
    memdc = CreateCompatibleDC(scrdc);
    membit = CreateCompatibleBitmap(scrdc, Width, Height);
    SelectObject(memdc, membit);
    // Улыбаемся... Снято!
    BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
}

void SetCursorPosition(int x,int y)
{
    POINT pt;
    pt.x = x;
    pt.y = y;
    ClientToScreen(0, &pt);
    SetCursorPos(pt.x, pt.y);
	Sleep(20);
}

__int64 calcImageHash(IplImage* src, bool show_results)
{
	if(!src){
		return 0;
	}
	IplImage *res=0, *gray=0, *bin =0;
	res = cvCreateImage( cvSize(8, 8), src->depth, src->nChannels);
	gray = cvCreateImage( cvSize(8, 8), IPL_DEPTH_8U, 1);
	bin = cvCreateImage( cvSize(8, 8), IPL_DEPTH_8U, 1);
	cvResize(src, res);
	cvCvtColor(res, gray, CV_BGR2GRAY);
	CvScalar average = cvAvg(gray);
	cvThreshold(gray, bin, average.val[0], 255, CV_THRESH_BINARY);
	__int64 hash = 0;
	int i=0;
	for( int y=0; y<bin->height; y++ ) {
		uchar* ptr = (uchar*) (bin->imageData + y * bin->widthStep);
		for( int x=0; x<bin->width; x++ ) {
			if(ptr[x]){
				hash |= 1i64<<i; 
			}
			i++;
		}
	}

	cvReleaseImage(&res);
	cvReleaseImage(&gray);
	cvReleaseImage(&bin);
	return hash;
}


__int64 calcHammingDistance(__int64 x, __int64 y)
{
	__int64 dist = 0, val = x ^ y;
	while(val)
	{
		++dist; 
		val &= val - 1;
	}
	return dist;
}



LPSTR GetValueFromINI(LPSTR FileName, LPSTR Section, LPSTR Key)
{
	char *key;
	key = (char *)malloc(256);
	GetPrivateProfileStringA(Section, Key, NULL, key, 256, FileName);
	return key;
	free(key);
}




IplImage * GetIplImage(HBITMAP HBM)
{
        BITMAP BM;       
        LPBITMAPINFO BIP;  
        HDC DC;      
        DWORD DataSize;   
        WORD BitCount;          

        GetObject(HBM, sizeof(BITMAP), (LPSTR)&BM);
        
        BitCount = (WORD)BM.bmPlanes * BM.bmBitsPixel;
        DataSize = ((BM.bmWidth*BitCount+31) & ~31)/8*BM.bmHeight;

        BIP=(LPBITMAPINFO)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(BITMAPINFOHEADER));
        BIP->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        BIP->bmiHeader.biWidth = BM.bmWidth;
        BIP->bmiHeader.biHeight = BM.bmHeight;
        BIP->bmiHeader.biPlanes = 1;
        BIP->bmiHeader.biBitCount = BitCount;
        BIP->bmiHeader.biCompression = 0;
        BIP->bmiHeader.biSizeImage = DataSize;
        BIP->bmiHeader.biXPelsPerMeter = 0;
        BIP->bmiHeader.biYPelsPerMeter = 0;
        if (BitCount < 16) 
                BIP->bmiHeader.biClrUsed = (1<<BitCount);
        BIP->bmiHeader.biClrImportant = 0;

        DC = GetDC(0); 
        
        BYTE * bits;                    // массив для битов изображения
        long imgsize, pixels;   // Различные размерности для записи файла               

        pixels = BIP->bmiHeader.biWidth * BIP->bmiHeader.biHeight; 

        switch(BIP->bmiHeader.biBitCount) 
        { 
        case 4:
                imgsize = pixels / 2;
                break; 
        case 8:
                imgsize = pixels;
                break; 
        case 16:
                imgsize = pixels * 2;
                break; 
        case 24:
                imgsize = pixels * 3;
                break; 
        case 32:
                imgsize = pixels * 4;
                break; 
        default:
                break;
        }

        //      выделяем память под биты изображения
        bits = (unsigned char*)GlobalAlloc(GMEM_FIXED,imgsize); 

        //Заполняем массив битов изображения 
        int i = GetDIBits( DC, // дескриптор контекста устройства 
                HBM, // дескриптор изображения 
                0, // первая выбираемая линия для изображения назначения 
                BIP->bmiHeader.biHeight, // количество выбираемых линий 
                bits, // адрес массива битов изображения 
                (BITMAPINFO*)&BIP->bmiHeader,// адрес структуры с данными изображения 
                DIB_RGB_COLORS // RGB или индекс палитры 
                );      

        //      заполняем данные по изображению
        int nChannels = BM.bmBitsPixel == 1 ? 1 : BM.bmBitsPixel/8 ;
        int depth = BM.bmBitsPixel == 1 ? IPL_DEPTH_1U : IPL_DEPTH_8U;
        IplImage* img = cvCreateImageHeader(cvSize(BM.bmWidth, BM.bmHeight), depth, nChannels);

        //      выделяем память под биты
        img->imageData = (char*) malloc( BM.bmHeight * BM.bmWidth* nChannels * sizeof(char));           

        //      копируем биты 
        memcpy( img->imageData, (char*)(bits), BM.bmHeight * BM.bmWidth * nChannels);

    //  изображение получается перевернутым     
        IplImage * imgModified = cvCreateImage(cvSize(img->width,img->height),img->depth, 3);
        cvCvtColor(img, imgModified, CV_BGRA2BGR); //   в img используеются 4 канала, мне необходимо только три
        IplImage * imgMirror = cvCreateImage(cvSize(img->width,img->height),img->depth, 3);
        cvMirror(imgModified, imgMirror);       //      приводим в нормальный вид
        
        //      убираем мусор
        cvReleaseImage(&imgModified);
        free( img->imageData);  
        cvReleaseImage(&img);   
        ReleaseDC(0, DC);               
        GlobalFree((HGLOBAL)bits);      
        HeapFree(GetProcessHeap(),0,(LPVOID)BIP);               
        return  (imgMirror);            
}



vector<string> splitString(string input, string delimiter)
{
 vector<string> output;
 size_t start = 0;
 size_t end = 0;

 while (start != string::npos && end != string::npos)
 {
    start = input.find_first_not_of(delimiter, end);

    if (start != string::npos)
    {
       end = input.find_first_of(delimiter, start);

       if (end != string::npos)
       {
          output.push_back(input.substr(start, end - start));
       }
       else
       {
          output.push_back(input.substr(start));
       }
    }
 }

 return output;

}