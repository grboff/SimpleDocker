#include <stdlib.h>

#include "fcgi_stdio.h"

int main(void) {
  while (FCGI_Accept() >= 0) {
    printf(
       "Content-type: text/html\r\n\r\nHave a nice day! And..."
        "<title>Hello World!</title>"
        "<h1>Hello World!</h1>"
        "<h1>Part 6</h1>\n");
  }
  return 0;
}