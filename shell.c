#include "user.h"

void main(void) {
  printf("Hello World from shell!\n");

  while (1) {
prompt:
    printf("> ");
    char cmdline[128];
    for (int i = 0;; i++) {
      char ch = getchar();
      putchar(ch);
      if (i == sizeof(cmdline) - 1) {
        printf("Command line is too long\n");
        goto prompt;
      } else if (ch == '\r') {
        printf("\n");
        cmdline[i] = '\0';
        break;
      } else {
        cmdline[i] = ch;
      }
    }

    if (strcmp(cmdline, "exit") == 0) {
      exit();
    } else if (strcmp(cmdline, "readfile") == 0) {
      char buf[128];
      int len = readfile("./hello.txt", buf, sizeof(buf));
      buf[len] = '\0';
      printf("%s\n", buf);
    } else if (strcmp(cmdline, "writefile") == 0) {
      writefile("./hello.txt", "Hello from shell!\n", 19);
    } else {
      printf("Unknown command: %s\n", cmdline);
    }
  }
}
