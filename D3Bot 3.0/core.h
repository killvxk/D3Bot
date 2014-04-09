BITMAPCAPTURE globalscreengrab;
BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture);
HBITMAP membit;
HDC scrdc, memdc;
CURL *curl;
CURL *curlfile;

int SleepTime;
int x, y, rx, ry, c, found;
int ScreenResolution2 = GetSystemMetrics(SM_CXSCREEN);
int ScreenResolutionMinus = 342;
int NoEventCount = 0;
int loglevel = -1;
ofstream logfile;
char currentPath[_MAX_PATH];
IplImage *object=0, *image=0;


extern int noauth;