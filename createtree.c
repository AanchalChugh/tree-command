#include "init.h"
int direc, file;
int count, nore, prune, lev;
//createtree function opens directory recursively and stores directory name, file name, type 'd' if directory and 'f' if file

struct node* createtree(char *dname) {		
	DIR *dir = opendir(dname);
	if(dir == NULL) {
		printf("%s [error opening dir]\n", dname);
		return NULL;
	}
	struct dirent *dr = NULL;
	struct node *ptr = NULL, *temp = NULL, *temp1 = NULL;
	char path[1024];
	while((dr = readdir(dir)) != NULL) {
			if(strcmp((dr->d_name), ".") != 0 && strcmp((dr->d_name), "..") != 0)  {
				temp = createnode(dr->d_name);
			}
			else {
				temp = NULL;
				continue;
			}
			if(temp1 != NULL) {
				temp1->nextfile = temp;
			}
			else {
				ptr = temp;
			}

			if((dr->d_type) == DT_DIR ) {
				++direc;
				temp->type = 'd';
				int len = snprintf(path, sizeof(path)-1, "%s/%s", dname, dr->d_name);
				path[len] = 0;
				(temp->nextdirec) = createtree(path);
			}
			else {
				++file;
				(temp)->type = 'f';
				(temp)->nextdirec = NULL;		
			}

		temp1 = temp;
	}
	closedir(dir);
	return (ptr);
}

//createtreep function does same work as createtree only in this function empty directories are excluded
struct node* createtreep(char *dname) {
	
	DIR *dir = opendir(dname);
	if(dir == NULL) {
		printf("%s [error opening dir]\n", dname);
		return NULL;
	}
	struct dirent *dr = NULL;
	struct node *ptr = NULL,*temp = NULL,*temp1 = NULL;
	char path[1024];
	int c = Number(dname);
	if(c == 1) {
		return NULL;
	}
	while((dr = readdir(dir)) != NULL) {
			if(strcmp((dr->d_name), ".")!=0 && strcmp((dr->d_name), "..") != 0) {
				temp = createnode(dr->d_name);				
			}
			else {
				temp = NULL;
				continue;
			}
			if(temp1 != NULL) {
				temp1->nextfile = temp;
			
			}
			else {
				ptr = temp;
			}

			if((dr->d_type) == DT_DIR) {
				
				temp->type = 'd';
				int len = snprintf(path, sizeof(path)-1, "%s/%s", dname, dr->d_name);
				path[len] = 0;
				temp->nextdirec = createtreep(path);
				if(temp->nextdirec == NULL) {
					free(temp);
				}
				else {
					++direc;
					temp1 = temp;
				
				}	
			}
			else {
				++file;
				(temp)->type = 'f';
				(temp)->nextdirec = NULL;
				temp1 = temp;	
			}
		}
	closedir(dir);
	return (ptr);
}

