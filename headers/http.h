#ifndef __HTTP_H__
#define __HTTP_H__ 1
//http开始行结构体
struct HtppStartLine
{
    //方法类型
    char *method;
    //地址
    char * url;
    //http版本信息
    char * httpversion;
};
typedef struct HtppStartLine StartLine;
//http 头部信息
struct HttpHeader
{
    //头部键名
    char * key;
    //头部值
    char * value;
};
typedef struct HttpHeader Header;


//http内容
struct HttpBase
{
    //开始行信息
    StartLine * startline;
    //头部数组信息
    Header * headers;
    //body内容
    char * body;
};
typedef struct HttpBase  Http;
//创建协议开始行
StartLine * buildStratLine(char * method, char * url, char * version);
//创建协议头
Header* buildHeader(char * key, char * value);
//创建http信息
char * resolveHttp(Http * http, int headerCount);
char * resolveStartLine(StartLine *);
char * resolveHeader(Header *);
void freeHtpp();

#endif