#include "file.h"
int countd = 0, countt = 0, i = 1, j, k = 0;
void init(char *a) {
	
	int c;
	c = noofptrs(a, 0);
	p = (node **)malloc((c+1) * sizeof(node *)); 
	p[0] = (node *)malloc(sizeof(node));
	p[0]->str = (char *)malloc(strlen(a) + 1);
	strcpy(p[0]->str, a);
	int d = countmemory(a);
	allocatememory(d);
	
}
void allocatememory(int count) {

	
	p[i - 1]->next = (node *)malloc( count * sizeof(node));
	p[i] = p[i - 1]->next;
	++i;
	j = 0;
}

int countmemory(const char *name) {	
	DIR *dir;
	struct dirent *NAME;

	if (!(dir = opendir(name)))
		return 0;
	if (!(NAME = readdir(dir)))
		return 0;
	do {	
		
		if (strcmp(NAME->d_name, ".") == 0 || strcmp(NAME->d_name, "..") == 0)
			continue;
		countt++;
	} while (NAME = readdir(dir));
	closedir(dir);
	return countt;
}

int noofptrs(const char *name, int level)
{
	DIR *dir;
	struct dirent *NAME;

	if (!(dir = opendir(name)))
		return 0;
	if (!(NAME = readdir(dir)))
		return 0;

	do {
		if (NAME->d_type == DT_DIR) {
			char path[1024];
			int l = snprintf(path, sizeof(path)-1, "%s/%s", name, NAME->d_name);
			path[l] = 0;
			if (strcmp(NAME->d_name, ".") == 0 || strcmp(NAME->d_name, "..") == 0)
				continue;
			++countd;
			noofptrs(path, level + 1);
		}
		
	} while (NAME = readdir(dir));
	closedir(dir);
	return countd;
}


void listdir(const char *name, int level) {
	DIR *dir;
	struct dirent *NAME;

	if (!(dir = opendir(name)))
	return;
	if (!(NAME = readdir(dir)))
	return;
	do {
		if (NAME->d_type == DT_DIR) {
			char path[1024];
			int l = snprintf(path, sizeof(path)-1, "%s/%s", name, NAME->d_name);
			path[l] = 0;
			if (strcmp(NAME->d_name, ".") == 0 || strcmp(NAME->d_name, "..") == 0)
			continue;
			int no = countmemory(NAME->d_name); 
			p[i - 1][j].str = (char *)malloc(strlen(NAME->d_name) + 1);
			strcpy(p[i - 1][j].str, NAME->d_name);
			printf("p[%d][%d] = %s\n", i - 1, j, p[i - 1][j].str);
			if(no != 0) {
				allocatememory(no);
			}
			else {
				p[i - 1][j].next = NULL;	
				++j;
				}
			listdir(path, level + 1);
	}
		else {
			p[i - 1][j].str = (char *)malloc(strlen(NAME->d_name) + 1);
			strcpy(p[i - 1][j].str, NAME->d_name);
			printf("p[%d][%d] = %s\n", i - 1, j, p[i - 1][j].str);
			p[i - 1][j].next = NULL;
			++j;
		
	}
	} while (NAME = readdir(dir));
	closedir(dir);
}


