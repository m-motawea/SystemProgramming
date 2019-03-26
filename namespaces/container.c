#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <unistd.h>
#include "container.h"
#include <string.h>


typedef struct container container;

char * get_hostname(container *self) {
  struct utsname utsname;
  uname(&utsname);
  printf("%s\n", utsname.nodename);
  return utsname.nodename;
}


int set_hostname(container *self) {
  int x;
  if (x=(sethostname(self->name, strlen(self->name)))==0) {
    printf("hostname: %s set.\n", self->name);
    return 0;
  } else {
    printf("failed to set hostname. ret_code: %d\n", x);
    return x;
  }
}


int start(container *self) {
  self->isolate_net(self);
  self->isolate_pid(self);
  self->isolate_ipc(self);
  self->isolate_uts(self);
  self->isolate_mount(self);
  sleep(1);
  self->set_hostname(self);
  self->isolate_user(self);
  printf("starting a new shell in container: %s\n", self->name);
  system("bash");
  return 0;
}



int isolate_net(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWNET))==0){
    printf("New `net` Namespace:\n");
    system("ip link");
    printf("\n\n");
    return 0;
  } else {
    printf("failed to create new network namespace. ret_code: %d\n", x);
    return x;
  }
}



int isolate_pid(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWPID))==0) {
    printf("New `PID` Namespace.\nPID: %d\n", getpid());
    return 0;
  } else {
    printf("Failed to unshare PID Namespace. ret_code: %d\n", x);
    return x;
  }
}



int isolate_ipc(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWIPC))==0) {
    printf("New IPC namespace\n");
    return 0;
  } else {
    printf("Failed to unshare IPC namespace. ret_code: %d\n", x);
    return x;
  }
}



int isolate_uts(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWUTS))==0) {
    printf("New UTS namespace\n");
    return 0;
  } else {
    printf("Failed to unshare UTS namespace. ret_code: %d\n", x);
    return x;
  }
}


int isolate_mount(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWNS))==0) {
    printf("New mount namespace\n");
    return 0;
  } else {
    printf("failed to unshare mount namespace. ret_code: %d\n", x);
    return x;
  }
}


int isolate_user(container *self) {
  int x;
  if (x=(unshare(CLONE_NEWUSER))==0) {
    printf("New Userspace\n");
    return 0;
  } else {
    printf("failed to unshare userspace. ret_code: %d\n", x);
    return x;
  }
}


container *initializeContainer(char *name) {
  container *cnt = malloc(sizeof(container));

  cnt->name = strdup(name);
  cnt->start = start;
  cnt->isolate_net = isolate_net;
  cnt->isolate_pid = isolate_pid;
  cnt->isolate_ipc = isolate_ipc;
  cnt->isolate_uts = isolate_uts;
  cnt->get_hostname = get_hostname;
  cnt->set_hostname = set_hostname;
  cnt->isolate_mount = isolate_mount;
  cnt->isolate_user = isolate_user;

  return cnt;
}


