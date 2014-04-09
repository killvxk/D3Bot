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

int movebutton;
int randomfollowx = 0;
int randomfollowy = 0;
int Event = 0;
int StartLevel = 0;
int teleportstepcount = 0;
int teleportsleepcount = 0;
int noputitemteleport = 0;
int startteleport = 0;

typedef boost::uniform_int<> NumberDistribution; 
typedef boost::mt19937 RandomNumberGenerator; 
typedef boost::variate_generator<RandomNumberGenerator&, NumberDistribution> Generator; 
RandomNumberGenerator generator; 

void MoveButton();
void randomfollow();
void BotGoToBase();
void BotFollowFlag();
int TraversedLocations = 0;

extern CURL *curlfile;
extern vector<string> splitString(string input, string delimiter);
extern HBITMAP membit;
extern IplImage * GetIplImage(HBITMAP HBM);
extern void BotGetScreenPng();
extern int GetLocationHash(BITMAPCAPTURE *grab);
extern void logprint(std::string text, int ignore);
extern int key_showitems;
extern int act4;
extern int DetectAct4();
extern void BotDropItems();
extern void BotNewGame();
extern BITMAPCAPTURE globalscreengrab;
extern BOOL CaptureScreen(BITMAPCAPTURE *bmpCapture);
extern int BotGetStatus(BITMAPCAPTURE *grab);
extern int location;
extern int solo;
extern int BotGetLocation();
extern void BotHeal();
extern int LoadLocation;
extern int FullSlot;
extern int dropitems;
extern int FindAttackColor(BITMAPCAPTURE *grab);
extern int FindFollowColor(BITMAPCAPTURE *grab);
extern int FindItemColor(BITMAPCAPTURE *grab);
extern void BotStashItems();
extern void BotSleep(int type, int perem1, int perem2, int perem3, int perem4, int perem5, int perem6, int perem7, int perem8, int perem9, int perem10, int perem11, int sleeptime);
extern int NoEventCount;
extern int rx, ry;
extern void SetCursorPosition(int x,int y);
extern int BotGetFlagStatus(BITMAPCAPTURE *grab);
extern int DetectPlayersColors(BITMAPCAPTURE *grab, int startx, int starty, int endx, int endy);
extern char *TestKey;
extern CURL *curl;
extern void BotGetMinimap(int intlocationhash);

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