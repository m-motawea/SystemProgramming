#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
  struct utsname uts;
  char computer[256];

  if (gethostname(computer, 255) != 0 || uname(&uts) < 0) {
    fprintf(stderr, "Could not get host info");
    exit(1);
  }

  printf("Computer hostname: %s\n", computer);
  printf("System is %s on %s hardware\n", uts.sysname, uts.machine);
  printf("Nodename is %s\n", uts.nodename);
  printf("Version is %s, %s\n", uts.release, uts.version);
  exit(0);
}
