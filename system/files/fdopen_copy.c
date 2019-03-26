#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
  int c, in, out;
  FILE *in_file, *out_file;

  in = open("file.in", O_RDONLY);
  out = open("fd_file.out", O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);

  in_file = fdopen(in, "r");
  out_file = fdopen(out, "w");

  while ((c = fgetc(in_file)) != EOF) {
    fputc(c, out_file);
  }

  exit(0);
}
