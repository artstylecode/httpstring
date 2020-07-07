#include "../headers/file.h"
#include "../headers/str.h"
#include <stdio.h>
#include <string.h>
//获取文本文件内容
char * getFileContent(char * name){
    FILE * fp;
    if((fp = fopen(name, "r")) == NULL){
        return NULL;
    }
    char * content = NULL;
    char ch;
    char chstr[2];
    
    while((ch = (char)getc(fp))!= EOF){
        chstr[0] = ch;
        content = str_add(content, chstr);
    }
    fclose(fp);
    return content;
}
//写入文本至文件中
int putFileContent(char * name, char * content){
    return putContent(name, content, "w+");
}
//追加写入文本
int appendFileContent(char * name, char * content){
    return putContent(name, content, "a+");
}
//写入文本公有函数
int putContent(char * name, char * content, char * mode){
    FILE * fp;
    if((fp = fopen(name, mode)) == NULL){
        return -1;
    }
    int len = strlen(content);
    for(int i = 0;i < len;i++){
        int ch = (int)content[i];
        putc(ch, fp);
    }
    return 0;
}