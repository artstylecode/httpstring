#include "../headers/str.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
static char * freelist[100];
static int freeindex = 0;
void free_str(){
    for(int i =0;i < freeindex;i++){
        free(freelist[freeindex]);
    }
}
char * str_add2(int num, ...){
    va_list ap;
    va_list cpAp;
    va_start(ap, num);
    va_copy(cpAp, ap);
    int len = 0;
    for(int i =0;i < num;i++){
        char * str = va_arg(ap, char *);
        if(str != NULL){
            len += strlen(str);
        }
        
    }
    va_end(ap);
    char * dest = malloc(len + 1);
    int offset = 0;
    for(int i = 0;i < num;i++){
        char * str = va_arg(cpAp, char *);
        if(str != NULL){
            if(offset == 0){
                strcpy(dest, str);
                offset = strlen(dest);
            }else{
                strcpy(dest + offset, str);
                offset += strlen(str);
            }
            
        }
    }
    freelist[freeindex] = dest;
    freeindex++;
    va_end(cpAp);
    return dest;
    
}
char * str_add(char *str1, char * str2){
    int len;
    if(str1 == NULL && str2 == NULL){
        return NULL;
    }
    if(str1 == NULL){
        len = strlen(str2) + 1;
    }else{
        len = strlen(str1) + strlen(str2) + 2;
    }
    
    char * dest = (char *)malloc(len);
    int offsetLen = 0;
    if(str1!=NULL){
        strcpy(dest, str1);
        offsetLen += strlen(str1);
    }
    if(str2 != NULL){
        strcpy(dest + offsetLen, str2);
    }
    freelist[freeindex] = dest;
    freeindex++;
    return dest;
}
char * currentTime(){
    time_t t =  time(0);
    struct tm * timeinfo = localtime(&t);
    char *strDate = (char *)malloc(18); 
    sprintf(strDate,"%d-%d-%d %d:%d:%d",timeinfo -> tm_year+1900, timeinfo -> tm_mon + 1, timeinfo -> tm_mday, timeinfo -> tm_hour, timeinfo -> tm_min, timeinfo -> tm_sec);
    freelist[freeindex] = strDate;
    return strDate;
}