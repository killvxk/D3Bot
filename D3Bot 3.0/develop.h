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

void GetImageHash();

extern CURL *curlfile;
extern char *TestKey;
extern BITMAPCAPTURE globalscreengrab;
extern int GetLocationHash(BITMAPCAPTURE *grab);
extern void BotGetMinimap(int intlocationhash);
extern char currentPath[_MAX_PATH];
extern __int64 calcImageHash(IplImage* src, bool show_results);