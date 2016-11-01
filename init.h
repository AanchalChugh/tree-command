#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#define ANSI_COLOR_BLUE "\e[0;34m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_RESET "\x1b[0m"
struct node {
	char *str;
	char type;		
	struct node *nextdirec;	
	struct node *nextfile;
};

struct node* createtreelink(char *);
void tree_filed(struct node *, FILE *);
void tree_filea(struct node *, FILE *);
struct node* createtree(char *);
struct node* createtreepath(char *);
void printtree(struct node *);
struct node* createnode(char* );
void init(char *name, char *a);
void initfile(char *, char *, char *);
void printtreea(struct node *);
void printtreed(struct node *);
void tree_file(struct node *, FILE *);
void initifile(char *, char *);
void initi(char *, char *, char *);
void tree_filei(struct node *, FILE *);
void printtreeia(struct node *);
void printtreeid(struct node *);
void printtreei(struct node *);
struct node* createtreep(char *dname);
void treepath(const char *, int);
void initlevel(char *, char *);
void initlimit(char *, char *);
int Number(char *);
void printtreelevela(struct node*);
void printtreeleveld(struct node*);
void printtreeleveli(struct node*);
void printtreelevel(struct node*);
void treepathi(const char *, int);
void inittime(char *, char *);
struct node* createtreetime(char *);
void getFileCreationTime(const char *, char *);
void help();

