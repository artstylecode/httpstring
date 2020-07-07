#include "../headers/debug.h"
#include "../headers/file.h"
#include "../headers/str.h"
#include <stdio.h>
int debug(char * log){
    return writeLog(log, INFO_DEBUG);
}
int info(char *log){
   return writeLog(log, INFO_INFO);

}
int error(char * log){
    return writeLog(log, INFO_ERROR);
}
int writeLog(char *log, int type){
    char *infoTitle = NULL;
    switch (type)
    {
    case INFO_DEBUG:
        infoTitle = "[DEBUG] ";
        break;
    case INFO_INFO:
        infoTitle = "[INFO] ";
        break;
    case INFO_ERROR:
        infoTitle = "[ERROR] ";
        break;
    
    default:
        break;
    }
    log = str_add(log, "\n");
    log = str_add(" ", log);
    char * date =  currentTime();
    log = str_add(date, log);
    char * content = str_add(infoTitle, log);
    appendFileContent("debug.log", content);
    free_str();
    return 0;
}