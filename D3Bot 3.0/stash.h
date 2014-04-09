int FullSlot;



int itemvalue_blue;
int itemvalue_yellow;
int itemvalue_green;
int itemvalue_legendary;
int itemvalue_gems;
int itemvalue_rings;
int itemvalue_amulets;
int itemvalue_arhonts;
int itemvalue_recipes;
int itemvalue_potions;
int itemvalue_books;
int needrepair = 0;
int repair;
int salvage;
int PrepareStashItemsStep = 0;
void BotStashItems();
void BotPutStashItems();
int BotPrepareStashItems();
int dropitems;
int key_showitems;

extern int identify;
extern int FindIdentifyColor(BITMAPCAPTURE *grab);
extern int finditem;
extern int rx, ry;
extern int FindYellowItems(BITMAPCAPTURE *grab);
extern void SetCursorPosition(int x,int y);
extern void BotSleep(int type, int perem1, int perem2, int perem3, int perem4, int perem5, int perem6, int perem7, int perem8, int perem9, int perem10, int perem11, int sleeptime);
extern BITMAPCAPTURE globalscreengrab;
extern BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture);
extern int BotGetStatus(BITMAPCAPTURE *grab);
extern int Event;
extern int LocationName;
extern int act4;
extern void BotIdentifyItems();
extern void BotSalvageItems();
extern void BotRepairItems();
extern void BotGetScreenPng();
extern int StartLevel;
extern int BotGetInventaryInfo(int slot_y, int slot_x);
extern int ScreenResolutionMinus;
extern vector<int> Item_x;
extern vector<int> Item_y;
extern int GetRGBRange(int x, int y, int maxred, int maxgreen, int maxblue, int minred, int mingreen, int minblue);