#include <stdio.h>

void main() {

    printf("Content-type: text/html\n\n") ;
    
    /** Print the HTML response page to STDOUT. **/
    printf("<html>\n") ;
    printf("<head><title>CGI Output</title></head>\n") ;
    printf("<body>\n") ;
    printf("<h1>Hello, world.</h1>\n") ;
    printf("</body>\n") ;
    printf("</html>\n") ;

    exit(0) ;
}
