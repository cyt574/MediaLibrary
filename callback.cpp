#include "callback.h"
#include <curl/curl.h>
#include <cstdio>


size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata)
{
    FILE* stream = (FILE*)userdata;
    if (!stream) {
        printf("!!! No stream\n");
        return 0;
    }

    size_t written = fwrite((FILE*)ptr, size, nmemb, stream);
    return written;
}

bool download_jpeg(char* url)
{
    FILE* fp = fopen("out.jpg", "wb");
    if (!fp) {
        printf("!!! Failed to create file on the disk\n");
        return false;
    }

    CURL* curlCtx = curl_easy_init();
    curl_easy_setopt(curlCtx, CURLOPT_URL, url);
    curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, 1);

    CURLcode rc = curl_easy_perform(curlCtx);
    if (rc) {
        printf("!!! Failed to download: %s\n", url);
        return false;
    }

    long res_code = 0;
    curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK)) {
        printf("!!! Response code: %d\n", res_code);
        return false;
    }

    curl_easy_cleanup(curlCtx);
    fclose(fp);

    return true;
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

bool download_jpeg2(char* url)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char* outfilename = "out2.jpg";

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    else {
        printf("!!!curl init failed\n");
        return false;
    }

    return true;
}


/*
 * @Todo
 */
QStringList findFiles(const QString &startPath, QStringList filter)
{
    QStringList names;
    QDir dir(startPath);
    foreach(QString file, dir.entryList(filter, QDir::Files))
    {
        names += startPath + "\\" + file;
    }
    foreach(QString file, dir.entryList(filter, QDir::AllDirs | QDir::NoDotAndDotDot))
    {
        names += findFiles(startPath + "\\" + file, filter);
    }
    return names;
}
