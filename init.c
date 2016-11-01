#include "init.h"
int direc, file;
int count, nore, prune, lev;
/*init function is used for -a -d -f --prune options
It creates first node and calls createtree to store directories hierarchy
calls printtree too to print tree
depending on the noreport options display no. of directories and files report at the end.
*/
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
}
//inittime function depending on the arguement i.e. %c %x displays tree along with last modification date and time of file and directory.

void inittime(char *name, char *a) {

	getFileCreationTime(name, a);
	printf(ANSI_COLOR_BLUE "%s\n", name);
	printf(ANSI_COLOR_RESET);
	printtreetime(name, 0, a);
	if(nore == 0)
		printf("\n%d directories, %d files\n", direc, file);

}
//initlimit checks for the no. of files whwn --filelimit option is used
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
//It works just like init function only initlevel calls printtreelevel functions which print trees only till specified level.
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
	else if(!(strcmp(mode, "-f"))) {
		treelevelf(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc - 1, file);
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
//initLEVEL calls functions which prints trees when options is used like -a -f -L level means all files including '.' files + full path + only till specified level 
void initLEVEL(char *name, char *a, char *b) {
	struct node *root = createnode(name);
	root->type = 'd';
	if((!(strcmp(a, "-a")) && !(strcmp(b, "-f"))) || (!(strcmp(a, "-f")) && !(strcmp(b, "-a")))) {
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathlevel(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-d")) && !(strcmp(b, "-f"))) || (!(strcmp(a, "-f")) && !(strcmp(b, "-d")))) {
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathleveld(root->str, 0);
		if(nore == 0)
			printf("\n%d directories\n", direc);
	}
	else if((!(strcmp(a, "-f")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-f")))) {
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathleveli(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
}
/*initi function 
-a -i 
-d -i
-f -i
when some option is used with -i option */
void initi(char *name, char *a, char *b) {
	struct node *root = createnode(name);
	root->type = 'd';
	if((!(strcmp(a, "-a")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-a")))) {
		(root->nextdirec) = createtree(name);
		printtreeia(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-d")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-d")))) {
		(root->nextdirec) = createtree(name);
		printtreeid(root);
		if(nore == 0)
			printf("\n%d directories\n", direc);
	}
	else if((!(strcmp(a, "-f")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-f")))){
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathi(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-A")) && !(strcmp(b, "-i"))) || (!(strcmp(a, "-i")) && !(strcmp(b, "-A")))) {
		(root->nextdirec) = createtree(name);
		printtreei(root);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-a")) && !(strcmp(b, "-f"))) || (!(strcmp(a, "-f")) && !(strcmp(b, "-a")))) {
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepath(root->str, 0);
		if(nore == 0)
			printf("\n%d directories, %d files\n", direc, file);
	}
	else if((!(strcmp(a, "-d")) && !(strcmp(b, "-f"))) || (!(strcmp(a, "-f")) && !(strcmp(b, "-d")))) {
		printf(ANSI_COLOR_BLUE "%s\n",root->str);
		printf(ANSI_COLOR_RESET);
		treepathd(root->str, 0);
		if(nore == 0)
			printf("\n%d directories\n", direc);
	}
	
}
//calls function which writes to a file WITHOUT INDENTATION
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
//calls function which writes to the file named fname used with -a -f -d -i option i.e. -a along with -o option
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
	else if(!(strcmp(mode, "-f")))
		tree_filef(root, 0, fp);
	else if(!(strcmp(mode, "-i"))) 
		printtreeleveli(root);
	else
		tree_file(root, fp);
	if(nore == 0)
		fprintf(fp, "\n%d directories, %d files\n", direc, file);
}

/*calls function to perform options like -a -f -o filename
i.e all files including '.'+ full path + writing to file given as arguement*/
void initFILE(char *name, char *fname, char *mode1, char *mode2) {

	FILE *fp;
	fp = fopen(fname, "w");
	if(fp == NULL) {
		printf("tree: invalid filename %s", fname);
	}
	fprintf(fp, ANSI_COLOR_BLUE "%s\n", name);
	fprintf(fp, ANSI_COLOR_RESET);
	if(!(strcmp(mode1, "-d")) && !(strcmp(mode2, "-f"))) {
		tree_FILEd(name, 0, fp);
		if(nore == 0)
			fprintf(fp, "\n%d directories\n", direc);
	}
	else if(!(strcmp(mode1, "-a")) && !(strcmp(mode2, "-f"))) {
		tree_FILEa(name, 0, fp);
		if(nore == 0)
			fprintf(fp, "\n%d directories, %d files\n", direc, file);
	}
	else if(!(strcmp(mode1, "-i")) && !(strcmp(mode2, "-f"))) {
		tree_FILEi(name, 0, fp);
		if(nore == 0)
			fprintf(fp, "\n%d directories, %d files\n", direc, file);
	}
}

