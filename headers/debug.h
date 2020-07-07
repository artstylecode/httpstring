#ifndef __DEBUG_H__
#define INFO_DEBUG 1
#define INFO_INFO 2
#define INFO_ERROR 3
#define __DEBUG_H__ 1
int debug(char * log);
int info(char *log);
int error(char * log);
int writeLog(char *log, int type);
#endif