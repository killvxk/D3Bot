void BotSalvageItems();
void LeftButton();
void BotRepairItems();

extern int needrepair;
extern void SetCursorPosition(int x,int y);
extern void BotSleep(int type, int perem1, int perem2, int perem3, int perem4, int perem5, int perem6, int perem7, int perem8, int perem9, int perem10, int perem11, int sleeptime);
extern void BotGetScreenPng();
extern int BotGetInventaryInfo(int slot_y, int slot_x);
extern int ScreenResolutionMinus;
extern int SleepTime;
extern HBITMAP membit;
extern IplImage * GetIplImage(HBITMAP HBM);
extern __int64 calcImageHash(IplImage* src, bool show_results);
extern __int64 calcHammingDistance(__int64 x, __int64 y);
extern BITMAPCAPTURE globalscreengrab;
extern BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture);
extern int BotGetStatus(BITMAPCAPTURE *grab);