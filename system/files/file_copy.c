#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
  char c;
  int in, out;

  in = open("file.in", O_RDONLY);
  out = open("file.out", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
  while (read(in, &c, 1) == 1) {
    write(out, &c, 1);
  }
  exit(0);
}
