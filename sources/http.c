#include "../headers/http.h"
#include "../headers/str.h"
#include <stdlib.h>
//创建协议开始行
StartLine * buildStratLine(char * method, char * url, char * version){
    StartLine * result = malloc(sizeof(StartLine));
    result -> method = method;
    result -> url = url;
    result -> httpversion = version;
    return result;
}
//创建协议头
Header* buildHeader(char * key, char * value){
    Header * result = malloc(sizeof(Header));
    result ->key = key;
    result -> value = value;
    return result;
}
char * resolveStartLine(StartLine *startline){
    char *res = str_add2(6, startline ->method," ", startline ->url, " ", startline -> httpversion, "\n");
    return res;
}
char * resolveHeader(Header *header){
    char * res = str_add2(4, header ->key, ":", header ->value, "\n");
    return res;
}
void freeHtpp();
//创建http信息
char * resolveHttp(Http * http, int headerCount){
    char *res = resolveStartLine(http ->startline);
    for(int i =0;i < headerCount;i++){
        Header *item = http -> headers[i];
        res = str_add(res, resolveHeader(item));
    }
    return res;
}