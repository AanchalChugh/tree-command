#include "init.h"
int direc, file;
int count, nore, prune, lev;
int symlink_exists(const char *path, char *linkname) {

	struct stat buf;
	int ret = 0;
	if(lstat(path, &buf) == 0) {
		linkname = malloc(buf.st_size + 1);
		readlink(path, linkname, buf.st_size + 1);
		linkname[buf.st_size] = '\0';

		if(stat(linkname, &buf) == 0) {
			printf("---> %s points to %s\n", path, linkname);
			ret = 1;
		}

	}
	return ret;
}
struct node* createnode(char *n) {
	struct node *temp = (struct node * )malloc(sizeof(struct node ));
	temp->str = n;
	temp->nextdirec = NULL;
	temp->nextfile = NULL;
	return temp;
}

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
char *getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    return(ctime(&attr.st_mtime));
}
