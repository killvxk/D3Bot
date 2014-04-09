int noauth = 0;
char *mymd5;
char *TestKey;
int noauthupdate = 0;

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

int BotGetConfig(char* param);
void BotUpdateSession();

extern CURL *curl;
extern char *BotVersion;
extern char *BotType;
extern void BotSleep(int type, int perem1, int perem2, int perem3, int perem4, int perem5, int perem6, int perem7, int perem8, int perem9, int perem10, int perem11, int sleeptime);
extern void logprint(std::string text, int ignore);