#include "stdafx.h"
#include "develop.h"


void GetImageHash()
{

	//построение хешей изображений
	IplImage *image;
	char* image_filename;

	char *img_name = "\\1.png";
	char *img_name_path = (char*)malloc(strlen(currentPath) + strlen(img_name) + 1);
	sprintf(img_name_path, "%s%s", currentPath, img_name);
	image_filename = img_name_path;
	image = cvLoadImage(image_filename, 1);
	__int64 hashI = calcImageHash(image, false);
	printf("hash1: %I64d\n", hashI);

    fstream file;
    file.open("hashes.txt", ios::out | ios::app);
    file << hashI;
	file << "\n\n";
    file.close();

}

void BotTrainFollowArea()
{

	POINT cursorpos;
	GetCursorPos(&cursorpos);

	char *locationhash=(char *)malloc(10);
	int intlocationhash = GetLocationHash(&globalscreengrab);
	sprintf(locationhash, "%i", intlocationhash);

	BotGetMinimap(intlocationhash);

  CURLcode res;
 
  struct curl_httppost *formpost=NULL;
  struct curl_httppost *lastptr=NULL;
  struct curl_slist *headerlist=NULL;
  static const char buf[] = "Expect:";
 
  /* Fill in the file upload field */ 
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "sendfile",
               CURLFORM_FILE, "minimap.png",
               CURLFORM_END);
 
  /* Fill in the filename field */ 
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "filename",
               CURLFORM_COPYCONTENTS, "minimap.png",
               CURLFORM_END);


  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "sendfile2",
               CURLFORM_FILE, "screen.jpg",
               CURLFORM_END);
 
 
  /* Fill in the submit field too, even if this is rarely needed */ 
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "authkey",
               CURLFORM_COPYCONTENTS, TestKey,
               CURLFORM_END);

char *xpos=(char *)malloc(4);
sprintf(xpos, "%i", cursorpos.x);

  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "x",
               CURLFORM_COPYCONTENTS, xpos,
               CURLFORM_END);

char *ypos=(char *)malloc(4);
sprintf(ypos, "%i", cursorpos.y);

  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "y",
			   CURLFORM_COPYCONTENTS, ypos,
               CURLFORM_END);


  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "locationhash",
			   CURLFORM_COPYCONTENTS, locationhash,
               CURLFORM_END);

 
  headerlist = curl_slist_append(headerlist, buf);

    /* what URL that receives this POST */ 
    curl_easy_setopt(curlfile, CURLOPT_URL, "http://diablo3bot.ru/D3Bot/DB/add.php");

      /* only disable 100-continue header if explicitly requested */ 
      curl_easy_setopt(curlfile, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curlfile, CURLOPT_HTTPPOST, formpost);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curlfile);
	cout<<res;
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* then cleanup the formpost chain */ 
    curl_formfree(formpost);
    /* free slist */ 
    curl_slist_free_all (headerlist);

	keybd_event( VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
	keybd_event( VK_CAPITAL, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

}