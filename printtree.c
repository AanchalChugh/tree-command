#include "init.h"
int direc, file;
int count, nore, prune, lev;
//prints all the file including those beginning with '.'
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
// prints all files and directory including those starting with '.' upto a certin level 'lev'
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
//prints files and directories upto  certain level 'lev' given as command line arguement
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
// print only directories
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
//print only directories upto a certain level 'lev'
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
//prints all directories and files excluding those beginning with '.'
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
//print only directories WITHOUT INDENTATION	-d -i option
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
//print tree WITHOUT INDENTATION -i option
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
//prints tree WITHOUT IDENTATION upto a certain level 'lev'
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
//prints tree all files including those starting with '.' WITHOUT INDENTATION -i -a option
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
//prints full path of files and directory and WITHOUT INDENTATION
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
//prints tree Full path of files and directories
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
		for(i = 0; i < (count - 1); i++)
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
		for(i = 0; i < count- 1; ++i)
			printf("|    ");
		--count;
		printf("|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
//print full path of directories only -d -f option
void treepathd(const char *name, int level) {
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
		for(i = 0; i < (count - 1); i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		treepathd(path, level + 1);
		--count;
	}
	} while (dr = readdir(dir));
	closedir(dir);
}
//Depending on mode i.e %c %x print tree along with last modified date and time of files and directories
void printtreetime(const char *name, int level, char *a) {
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
		for(i = 0; i < (count - 1); i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		getFileCreationTime(path, a);
		printf(ANSI_COLOR_BLUE "%s\n", dr->d_name);
		printf(ANSI_COLOR_RESET);
		printtreetime(path, level + 1, a);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i < count- 1; ++i)
			printf("|    ");
		--count;
		printf("|____");
		getFileCreationTime(path, a);
		printf("%s\n", dr->d_name);

	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
//print tree full path of directories and files upto a certain level 'lev'
void treelevelf(const char *name, int level) {
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
		for(i = 0; i < (count - 1);i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET); 
		if(count != (lev + 1))
			treelevelf(path, level + 1);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i < count- 1; ++i)
			printf("|    ");
		--count;
		printf("|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
// -f -L level option

void treepathlevel(const char *name, int level) {
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
		for(i = 0;i < (count - 1); i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		if(count != (lev +1))
			treepathlevel(path, level + 1);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i < count- 1; ++i)
			printf("|    ");
		--count;
		printf("|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
// -d -f -L level option display only directories(full path) upto a certain level
void treepathleveld(const char *name, int level) {
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
		for(i = 0; i < (count - 1); i++)
			printf("%s",s1);
		if((count + 1) > 0)
			printf("%s",s);
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		if(count != (lev +1))
			treepathd(path, level + 1);
		--count;
	}
	} while (dr = readdir(dir));
	closedir(dir);
}
//-f -i -L level full path of files and directories + no INDENTATION + upto certain level
void treepathleveli(const char *name, int level) {
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
		++count;
		printf(ANSI_COLOR_BLUE "%s\n", path);
		printf(ANSI_COLOR_RESET);
		if(count != (lev +1))
			treepathleveli(path, level + 1);
		--count;
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

