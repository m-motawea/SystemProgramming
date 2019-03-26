

typedef struct container {
  char *name;
  int (*start)();
  int (*isolate_net)();
  int (*isolate_pid)();
  int (*isolate_ipc)();
  int (*isolate_uts)();
  int (*isolate_mount)();
  int (*isolate_user)();
  char * (*get_hostname)();
  int (*set_hostname)();
} container;

int start(container *self);
int isolate_net(container *self);
int isolate_pid(container *self);
int isolate_ipc(container *self);
int isolate_uts(container *self);
int set_hostname(container *self);
char * get_hostname(container *self);
container *initializeContainer(char *name);
