static int writer(char *data, size_t size, size_t nmemb,std::string *buffer)
{
    int result = 0;
    if (buffer != NULL)
    {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}

int BotCurrentStatus;
int allcolor = 0;

int GetRGBRange(int x, int y, int maxred, int maxgreen, int maxblue, int minred, int mingreen, int minblue);
int FindAllColor(BITMAPCAPTURE *grab, DWORD mydvmin_Color, DWORD mydvmax_Color, int stepy, int stepx, int stepheight, int stepwidth);
int BotGetStatus(BITMAPCAPTURE *grab);
int BotGetFlagStatus(BITMAPCAPTURE *grab);
int BotGetBotInGame(BITMAPCAPTURE *grab);
int DetectPlayersColors(BITMAPCAPTURE *grab, int startx, int starty, int endx, int endy);
int FindDieColor(BITMAPCAPTURE *grab);
int FindFriendDie(BITMAPCAPTURE *grab);
int FindPlayersBeside(BITMAPCAPTURE *grab);
int FindFlagColor(BITMAPCAPTURE *grab);
int DetectAct4();
int FindItemColor(BITMAPCAPTURE *grab);
int FindFollowColor(BITMAPCAPTURE *grab);
int FindMiniAttackColor(BITMAPCAPTURE *grab);
int FindAttackColor(BITMAPCAPTURE *grab);
int botattackcount = 0;

extern BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture);
extern void logprint(std::string text, int ignore);
extern __int64 calcHammingDistance(__int64 x, __int64 y);
extern int GetLocationHash(BITMAPCAPTURE *grab);
extern CURL *curl;
extern int noauthupdate;
extern int found;
extern int x,y,rx,ry;
extern void BotGetScreenPng();
extern HBITMAP membit;
extern IplImage * GetIplImage(HBITMAP HBM);
extern __int64 calcImageHash(IplImage* src, bool show_results);
extern char *TestKey;
extern int train;
extern HDC scrdc, memdc;
extern BITMAPCAPTURE globalscreengrab;
extern int noauth;
extern int salvage;
extern int itemvalue_blue;
extern int itemvalue_yellow;
extern int itemvalue_green;
extern int itemvalue_legendary;
extern int itemvalue_gems;
extern int itemvalue_rings;
extern int itemvalue_amulets;
extern int itemvalue_arhonts;
extern int itemvalue_recipes;
extern int itemvalue_potions;
extern int itemvalue_books;
extern int LocationName;



extern int LOCATION_NEDRA_GORI_ARREAT;
extern int LOCATION_NIZHNIE_ETASHI_KREPOSTI_1;
extern int LOCATION_KAMENNIY_FORT;
extern int LOCATION_NIZHNIE_ETASHI_KREPOSTI_3;
extern int LOCATION_NIZHNIE_ETASHI_KREPOSTI_2;
extern int LOCATION_ARREATSKIY_KRATER_1;
extern int LOCATION_BASHNYA_OBRECHENNUH_1;
extern int LOCATION_ARREATSKIY_KRATER_2;
extern int LOCATION_BASHNYA_PROKLYATIH_1;
extern int LOCATION_MOST_KORSIKKA;
extern int LOCATION_POLYA_KROVAVOI_BOINY;
extern int LOCATION_POLE_BOYA;
extern int LOCATION_MOST_RAKKISA;
extern int LOCATION_BASHNYA_OBRECHENNUH_2;
extern int LOCATION_SERDCE_OBRECHENNUH;
extern int LOCATION_BASHNYA_PROKLYATIH_2;
extern int LOCATION_SERDCE_PROKLYATIH_2;
extern int LOCATION_SERDCE_GREHA;