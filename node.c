#include "init.h"
int direc, file;
int count, nore, prune, lev;
//create node, store string and initialize its self referential ptrs to NULL
struct node* createnode(char *n) {
	struct node *temp = (struct node * )malloc(sizeof(struct node ));
	temp->str = n;
	temp->nextdirec = NULL;
	temp->nextfile = NULL;
	return temp;
}
//Returns no. of contents(file + Directory) called when --filelimit no option is used if directory has less contents than no. then only director is opened
int Number(char *directory) {
	int n = 0;
	struct dirent *dr;
	DIR *dir = opendir(directory);
	if(dir == NULL) {
		return -1;
	}
	while((dr = readdir(dir)) != NULL) {
		if(strcmp((dr->d_name), ".")!=0 && strcmp((dr->d_name), "..") != 0)
			++n;
		else 
			continue;
	}
	closedir(dir);
	return n;
}
//Used to get last modified time and date of file depending on option
void getFileCreationTime(const char *path, char *a) {
	struct stat attr;
	stat(path, &attr);
	char date[10];
	if(!(strcmp(a, "%x")))
		strftime(date, 10, "%d/%m/%y", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%B")))
		strftime(date, 10, "%B", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%b")))
		strftime(date, 10, "%b", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%a")))
		strftime(date, 10, "%a", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%A")))
		strftime(date, 10, "%A", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%c")))
		printf("[%s] ", ctime(&attr.st_mtime));
	else if(!(strcmp(a, "%d")))
		strftime(date, 10, "%d", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%H")))
		strftime(date, 10, "%H", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%I")))
		strftime(date, 10, "%I", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%j")))
		strftime(date, 10, "%j", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%m")))
		strftime(date, 10, "%m", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%M")))
		strftime(date, 10, "%M", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%p")))
		strftime(date, 10, "%p", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%S")))
		strftime(date, 10, "%S", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%U")))
		strftime(date, 10, "%U", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%w")))
		strftime(date, 10, "%w", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%W")))
		strftime(date, 10, "%W", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%X")))
		strftime(date, 10, "%X", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%y")))
		strftime(date, 10, "%y", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%Y")))
		strftime(date, 10, "%Y", gmtime(&(attr.st_ctime)));
	else if(!(strcmp(a, "%Z")))
		strftime(date, 10, "%Z", gmtime(&(attr.st_ctime)));
	if((strcmp(a, "%c"))) {
		printf("[%s]\n", date);
		date[0] = 0;	
	}
}
void getFileCreationDate(const char *filePath) {
    struct stat attrib;
    stat(filePath, &attrib);
    char date[10];
    strftime(date, 10, "%d/%m/%y", gmtime(&(attrib.st_ctime)));
    printf("[%s]\n", date);
    date[0] = 0;
}
void help() {
	printf("Usage : ./project [option] [directoryname]\n");
	printf("List the contents of directories in a tree-like format\n");
	printf("-a\t All file are printed. Also those beginning with '.'\n");
	printf("-d\t List directories only\n");
	printf("-f\t prints full path prefix for each file\n");
	printf("-L level\t List directories and its contents only upto level specified\n");
	printf("--prune\t Excludes empty directories\n");
	printf("--noreport\t Omits printing of file and directory report at the end of tree\n");
	printf("--filelimit #\t Opens only those directories which contains less than # entries\n");
	printf("--timefmt format\t prints and formats the date according to the format string which uses the strftime syntax\n");
	printf("-o filename\t send output to filename\n");
	printf("-i\t print tree without indentation\n");
} 

}
