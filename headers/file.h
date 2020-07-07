#ifndef __FILE_H__
int putFileContent(char * name, char * content);
int appendFileContent(char * name, char * content);
int putContent(char * name, char * content, char * mode);
#define __FILE_H__ 1

#endif