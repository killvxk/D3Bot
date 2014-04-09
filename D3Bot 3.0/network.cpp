#include "stdafx.h"
#include "network.h"





int BotGetConfig(char* param)
{

	cout<<"Загрузка: ";
	cout<<param;
	cout<<"...";

	char *myparam = (char*)malloc(strlen(param) + 1);
	sprintf(myparam, "%s", param);

	char *Configdatahttpquery = (char*)malloc(strlen("http://178.132.203.196/D3Bot/getconfig.php?param=config_") + strlen(param) + strlen("&authkey=") + strlen(TestKey) + 1);
	sprintf(Configdatahttpquery, "%s%s%s%s", "http://178.132.203.196/D3Bot/getconfig.php?param=config_", param, "&authkey=", TestKey);
	string Configurls = Configdatahttpquery;
	CURLcode Configresult;
	string Configbuffer;

	curl_easy_setopt(curl, CURLOPT_URL, Configurls.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &Configbuffer);
	Configresult = curl_easy_perform(curl);

	cout<<" - ";
	cout<<atoi((char*)Configbuffer.c_str());
	cout<<"\n";

	logprint(param, -1);
	logprint((char*)Configbuffer.c_str(), -1);

	return atoi((char*)Configbuffer.c_str());

}




void BotUpdateSession()
{
	while(1)
	{
		char *Dropdatahttpquery = (char*)malloc(strlen("http://178.132.203.196/D3Bot/session.php?version=") + strlen(BotVersion) + strlen("&type=") + strlen(BotType) + strlen("&authkey=") + strlen(TestKey) + 1);
		sprintf(Dropdatahttpquery, "%s%s%s%s%s%s", "http://178.132.203.196/D3Bot/session.php?version=", BotVersion, "&type=", BotType, "&authkey=", TestKey);
		string Dropurls = Dropdatahttpquery;

		CURLcode Dropresult;
		string Dropbuffer;

		curl_easy_setopt(curl, CURLOPT_URL, Dropurls.c_str());
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 2);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &Dropbuffer);
		Dropresult = curl_easy_perform(curl);

		if(Dropbuffer == md5(mymd5))
		{
			noauthupdate = 0;
			noauth = 0;
			break;
		}
		else
		{
			noauth = 1;
			noauthupdate = 1;
			BotSleep(0,0,0,0,0,0,0,0,0,0,0,0,300);
			logprint("Ошибка соединения с сервером:", 0);
			logprint(Dropbuffer, 0);
		}
	}
}