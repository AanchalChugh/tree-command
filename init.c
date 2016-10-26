#include "init.h"
int direc, file;
int count, nore, prune, lev;
void init(char *name, char *a) {
	struct node *root = createnode(name);
	root->type = 'd';
	if(!(strcmp(a, "-a"))) {
		(root->nextdirec) = createtree(name);
		printtreea(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if(!(strcmp(a, "-d"))) {
		(root->nextdirec) = createtree(name);
		printtreed(root);
		if(nore == 0)
			printf("\n%d directories\n", direc);
	}
	else if(!(strcmp(a, "-A"))) {
		(root->nextdirec) = createtree(name);
		printtree(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if(!(strcmp(a, "-f"))) {
		printf(ANSI_COLOR_BLUE "%s\n", root->str);
		printf(ANSI_COLOR_RESET);
		treepath(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	
	}
	else if(!(strcmp(a, "--prune"))) {
		(root->nextdirec) = createtreep(name);
		printtree(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if(!(strcmp(a, "-l"))) {
		(root->nextdirec) = createtreelink(name);
		printtree(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
}
void inittime(char *name, char *a) {
	struct node *root = createnode(name);
	root->type = 'd';
	if(!(strcmp(a, "%c"))) {
		(root->nextdirec) = createtreetime(name);
		printtree(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);

	}

}
void initlimit(char *name, char *a) {
	int limit = atoi(a);
	int lim = Number(name);
	if(lim == -1) {
		printf("%s [error opening dir]\n", name);
	}
	if(limit >= lim) {
		struct node *root = createnode(name);
		root->type = 'd';
		(root->nextdirec) = createtree(name);
		if(!(strcmp(name, ".")))
			printtree(root);
		else
			printtreea(root);
	}
	else {
		printf(ANSI_COLOR_BLUE "%s", name);
		printf(ANSI_COLOR_RESET);
		printf(" [%d enteries exceeds filelimit, not opening dir]\n", lim);
	}
	if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
}
void initlevel(char *name, char *mode) {

	struct node *root = createnode(name);
	root->type = 'd';
	(root->nextdirec) = createtree(name);
	direc = 0, file = 0;
	if(!(strcmp(mode, "-a"))) {
		printtreelevela(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc - 1, file);
	}
	else if(!(strcmp(mode, "-d"))) {
		printtreeleveld(root);
		if(nore == 0)
			printf("\n%d directories\n", file);
		}
	else if(!(strcmp(mode, "-i"))) {
		printtreeleveli(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc - 1, file);
		}
	else {
		printtreelevel(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc - 1, file);
	}
	
}
void initi(char *name, char *a, char *b) {
	struct node *root = createnode(name);
	root->type = 'd';
	if((!(strcmp(a, "-a")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-a"))) ){
		(root->nextdirec) = createtree(name);
		printtreeia(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-d")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-d"))) ) {
		(root->nextdirec) = createtree(name);
		printtreeid(root);
		if(nore == 0)
			printf("\n%d directories\n", direc);
	}
	else if((!(strcmp(a, "-f")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-f"))) ){
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathi(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-A")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-A"))) ){
		(root->nextdirec) = createtree(name);
		printtreei(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	
}
void initifile(char *name, char *fname) {

	FILE *fp;
	fp = fopen(fname, "w");
	if(fp == NULL) {
		printf("tree: invalid filename %s", fname);
	}
	struct node *root = createnode(name);
	root->type = 'd';
	(root->nextdirec) = createtree(name);
	tree_filei(root, fp);
	if(nore == 0)
		fprintf(fp," \n%d directories, %d files\n", direc, file);
}
void initfile(char *name, char *fname, char *mode) {

	FILE *fp;
	fp = fopen(fname, "w");
	if(fp == NULL) {
		printf("tree: invalid filename %s", fname);
	}
	struct node *root = createnode(name);
	root->type = 'd';
	(root->nextdirec) = createtree(name);
	if(!(strcmp(mode, "-a")))
		tree_filea(root, fp);
	else if(!(strcmp(mode, "-d")))
		tree_filed(root, fp);
	else
		tree_file(root, fp);
	if(nore == 0)
		fprintf(fp, "\n%d directories, %d files\n", direc, file);
}

