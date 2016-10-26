#include "init.h"
int direc, file;
int count, nore, prune, lev;
void printtreea(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start==NULL)
		return;
	
	printf("\n");
	for(i = 0;i < count - 1; i++)
		printf("%s", s1);
	if(count > 0)
		printf("%s", s);
		if(temp->type != 'd') {
				printf("%s", temp->str);
		}
		else {
			printf(ANSI_COLOR_BLUE "%s", temp->str);
			printf(ANSI_COLOR_RESET);
			count++;
			printtreea(temp->nextdirec);
			count--;
		}
		printtreea(temp->nextfile);	
}
void printtreelevela(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start==NULL)
		return;
	
	printf("\n");
	for(i = 0;i < count - 1; i++)
		printf("%s", s1);
	if(count > 0)
		printf("%s", s);
		if(temp->type != 'd') {
				printf("%s", temp->str);
				++file;
		}
		else {
			++direc;
			printf(ANSI_COLOR_BLUE "%s", temp->str);
			printf(ANSI_COLOR_RESET);
			count++;
			if(count != (lev + 1))
				printtreelevela(temp->nextdirec);
			count--;
		}
		printtreelevela(temp->nextfile);	
}
void printtreelevel(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	if(temp->str[0] != '.') {
		printf("\n");
		for(i=0;i<(count-1);i++)
			printf("%s",s1);
		if(count>0)
			printf("%s",s);
		if(temp->type == 'd') {
			printf(ANSI_COLOR_BLUE "%s",temp->str);
			printf(ANSI_COLOR_RESET);
			++direc;
		}
		else {
			printf("%s",temp->str);
			++file;
		}
	}
	if(temp->type == 'd') {	
		count++;
		if(count != (lev + 1))
			printtreelevel(temp->nextdirec);
		count--;
	}
	printtreelevel(temp->nextfile);	
}

void printtreed(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->type == 'd') {	
			printf("\n");
			for(i = 0;i < count - 1; i++)
				printf("%s", s1);
			if(count > 0)
				printf("%s", s);
			printf(ANSI_COLOR_BLUE "%s", temp->str);
			printf(ANSI_COLOR_RESET);
			count++;
			printtreed(temp->nextdirec);
			count--;
		}
		printtreed(temp->nextfile);	
}
void printtreeleveld(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->type == 'd') {	
			printf("\n");
			for(i = 0;i < count - 1; i++)
				printf("%s", s1);
			if(count > 0)
				printf("%s", s);
			printf(ANSI_COLOR_BLUE "%s", temp->str);
			printf(ANSI_COLOR_RESET);
			++direc;
			count++;
			if(count != (lev + 1))
				printtreeleveld(temp->nextdirec);
			count--;
		}
		printtreeleveld(temp->nextfile);	
}
void printtree(struct node *start) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	if(temp->str[0] != '.') {
		printf("\n");
		for(i=0;i<(count-1);i++)
			printf("%s",s1);
		if(count>0)
			printf("%s",s);
		if(temp->type == 'd') {
			printf(ANSI_COLOR_BLUE "%s",temp->str);
			printf(ANSI_COLOR_RESET);
		}
		else
			printf("%s",temp->str);
	}
	if(temp->type == 'd') {	
		count++;
		printtree(temp->nextdirec);
		count--;
	}
	printtree(temp->nextfile);	
}
void printtreeid(struct node *start) {
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->type == 'd') {	
			printf("\n");
			printf(ANSI_COLOR_BLUE "%s", temp->str);
			printf(ANSI_COLOR_RESET);
			count++;
			printtreeid(temp->nextdirec);
			count--;
		}
		printtreeid(temp->nextfile);	
}
void printtreei(struct node *start) {
	
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	if(temp->str[0] != '.') {
		printf("\n");
		if(temp->type == 'd') {
			printf(ANSI_COLOR_BLUE "%s",temp->str);
			printf(ANSI_COLOR_RESET);
		}
		else
			printf("%s",temp->str);
	}
	if(temp->type == 'd') {	
		count++;
		printtreei(temp->nextdirec);
		count--;
	}
	printtreei(temp->nextfile);	
}
void printtreeleveli(struct node *start) {
	
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	if(temp->str[0] != '.') {
		printf("\n");
		if(temp->type == 'd') {
			printf(ANSI_COLOR_BLUE "%s",temp->str);
			printf(ANSI_COLOR_RESET);
			++direc;
		}
		else {
			++file;
			printf("%s",temp->str);
		}
	}
	if(temp->type == 'd') {	
		count++;
		if(count != (lev + 1))
			printtreeleveli(temp->nextdirec);
		count--;
	}
	printtreeleveli(temp->nextfile);	
}
void printtreeia(struct node *start) {
	struct node *temp = start;
	int i;

	if(start==NULL)
		return;
	
	printf("\n");
	if(temp->type != 'd') {
		printf("%s", temp->str);
	}
	else {
		printf(ANSI_COLOR_BLUE "%s", temp->str);
		printf(ANSI_COLOR_RESET);
		count++;
		printtreeia(temp->nextdirec);
		count--;
	}
	printtreeia(temp->nextfile);	
}
void treepathi(const char *name, int level) {
	DIR *dir;
	struct dirent *dr;
	if (!(dir = opendir(name)))
		return;
	if (!(dr = readdir(dir)))
		return;
	int i;
	do {
	if (dr->d_type == DT_DIR) {
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		if (strcmp(dr->d_name, ".") == 0 || strcmp(dr->d_name, "..") == 0)
			continue;
		++direc;
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		treepathi(path, level + 1);
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		printf("%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
void treepath(const char *name, int level) {
	DIR *dir;
	struct dirent *dr;
	char *s = "|____",*s1 = "|    ";
	if (!(dir = opendir(name)))
		return;
	if (!(dr = readdir(dir)))
		return;
	int i;
	do {
	if (dr->d_type == DT_DIR) {
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		if (strcmp(dr->d_name, ".") == 0 || strcmp(dr->d_name, "..") == 0)
			continue;
		++direc;
		++count;
		for(i=0;i<(count - 1);i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		treepath(path, level + 1);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i<count- 1; ++i)
			printf("|    ");
		--count;
		printf("|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
