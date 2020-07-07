#ifndef __STR_H_
#include <stdio.h>
#include <stdarg.h>
char * str_add(char *str1, char * str2);
char * str_add2(int num, ...);
void free_str();
char * currentTime();
#define __STR_H_ 1


#endif