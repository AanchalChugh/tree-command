#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct node {

char *str;
struct node *next;

}node;
node **p;
node *q;
void init(char *a);
void allocatememory(int count);
int countmemory(const char *name);
int noofptrs(const char *name, int level);
void listdir(const char *name, int level);

void inito(char *a);
int countmemoryo(const char *name, int level);
void listdiro(const char *name, int level);
