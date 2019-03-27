#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  int opt, depth;
  char * path;
  int v = 0;

  while ((opt = getopt(argc, argv, "p:d:v")) != -1) {
    switch(opt) {
      case 'p':
        path = optarg;
        break;
      case 'd':
        depth = atoi(optarg);
        break;
      case 'v':
        v = 1;
        break;
      case '?':
        printf("unknown option: %c\n", opt);
        break;
    }
  }

  printf("path: %s\n", path);
  printf("depth: %d\n", depth);
  if (v) {
    printf("verbose\n");
  }
  exit(0);
}
