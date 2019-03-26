#include "container.h"
#include <stdio.h>


int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("missing container name");
    return 0;
  }
  for (int i = 1; i < argc; i++) {
    container *cnt = initializeContainer(argv[i]);
    int x;
    if(x=(cnt->start(cnt))==0) {
      printf("container %s started successfully.\n", argv[i]);
      return 0;
    } else {
      printf("failed to start container %s. ret_code: \n", argv[i], x);
      return x;
    }

    return 0;
  }
}
