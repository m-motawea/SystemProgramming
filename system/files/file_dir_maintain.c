#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main() {
  /*if (chmod("/home/maged/Code/TestDir1/TestFile1", S_IRUSR|S_IWUSR|S_IXUSR)==0) {
    printf("rwx for owner\n");
  } else {
    printf("failed to chmod\n");
  }*/

  /*if (unlink("/home/maged/Code/TestDir1/TestFile1")==0) {
    printf("unlink file\n");
  } else {
    printf("failed to unlink file");
  }*/

  if (link("/home/maged/Code/TestDir1/TestFile1", "/home/maged/Code/TestDir2/TestFile1")==0) {
    printf("link created\n");
  } else {
    printf("failed to link");
  }

  return 0;
}
