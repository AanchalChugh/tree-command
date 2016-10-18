#include "file.h"
int count = 0, j = 0;
void inito(char *a) {
	
	q = (node *)malloc(sizeof(node));
	q->str = (char *)malloc(strlen(a) + 1);
	strcpy(q->str, a);
	int d = countmemoryo(a, 0);
	q->next = (node *)malloc(d * sizeof(node));
	
}
int countmemoryo(const char *name, int level) {	
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
			countmemoryo(path, level + 1);
		}
		else {
			++count;
		}
	} while (NAME = readdir(dir));
	return count;
	closedir(dir);
}

void listdiro(const char *name, int level) {
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
			listdir(path, level + 1);
	}
		else {
			q->next[j].str = (char *)malloc(strlen(NAME->d_name) + 1);
			strcpy(q->next[j].str, NAME->d_name);
			printf("%s", q->next[j].str);
			q->next[j].next = NULL;
			++j;
		
	}
	} while (NAME = readdir(dir));
	closedir(dir);
}


