#include <stdio.h>
#include "../headers/str.h"
#include "../headers/http.h"
int main(void){
    StartLine *line = buildStratLine("GET", "/", "HTTP/1.1");
    Header * header = buildHeader("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36");
    Http http = {
                line,
                {header},
                "12312"
                };
    char * httpstr =  resolveHttp(&http, 1);
    printf("http string:%s", httpstr);
    
    
    free_str();
    return 0;
}