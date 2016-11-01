#include "init.h"
int direc, file;
int count, nore, prune, lev;
//writing the output of -a option to file given as arguement name fp is the file pointer to this file in which output is to be directed.
void tree_filea(struct node *start, FILE *fp) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
	fprintf(fp, "\n");
	for(i = 0 ; i < count - 1 ; i++)
		fprintf(fp, "%s", s1);
	if(count > 0)
		fprintf(fp, "%s", s);
		if(temp->type != 'd')
			fprintf(fp, "%s", temp->str);

		else {
			fprintf(fp, ANSI_COLOR_BLUE "%s", temp->str);
			fprintf(fp, ANSI_COLOR_RESET);
			count++;
			tree_filea(temp->nextdirec, fp);
			count--;
		}
		tree_filea(temp->nextfile, fp);	
}
//writing the output of -d(only directories) option to file given as arguement name fp is the file pointer to this file in which output is to be directed.
void tree_filed(struct node *start, FILE *fp) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;
	
		if(temp->type == 'd') {
 			fprintf(fp, "\n");
			for(i = 0; i < (count - 1) ; i++)
				fprintf(fp, "%s", s1);
			if(count > 0)
				fprintf(fp, "%s", s);
			fprintf(fp, ANSI_COLOR_BLUE "%s", temp->str);
			fprintf(fp, ANSI_COLOR_RESET);
			count++;
			tree_filed(temp->nextdirec, fp);
			count--;
		}
		tree_filed(temp->nextfile, fp);	
}
//writing the output (excludes all file beginning with '.')to file given as arguement name fp is the file pointer to this file in which output is to be directed.
void tree_file(struct node *start, FILE *fp) {
	char *s = "|____",*s1 = "|    ";
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;

	if(temp->str[0] != '.') {
		fprintf(fp, "\n");
		for(i = 0; i < (count - 1); i++)
			fprintf(fp, "%s", s1);
		if(count>0)
			fprintf(fp, "%s",s);
		if(temp->type == 'd') {
			fprintf(fp, ANSI_COLOR_BLUE "%s",temp->str);
			fprintf(fp, ANSI_COLOR_RESET);
			
		}
		else {
			fprintf(fp, "%s", temp->str);
			
		}
	}
	if(temp->type == 'd') {	
		count++;
		tree_file(temp->nextdirec, fp);
		count--;
	}
	tree_file(temp->nextfile, fp);	
}
//writing the output of -i option(without indentation) to file given as arguement name fp is the file pointer to this file in which output is to be directed.
void tree_filei(struct node *start, FILE *fp) {
	struct node *temp = start;
	int i;

	if(start == NULL)
		return;

	if(temp->str[0] != '.') {
		fprintf(fp, "\n");
		if(temp->type == 'd') {
			fprintf(fp, ANSI_COLOR_BLUE "%s",temp->str);
			fprintf(fp, ANSI_COLOR_RESET);
			
		}
		else {
			fprintf(fp, "%s", temp->str);
			
		}
	}
	if(temp->type == 'd') {	
		count++;
		tree_filei(temp->nextdirec, fp);
		count--;
	}
	tree_filei(temp->nextfile, fp);	
}

//writing the output of -f option(full path of file and directory) to file given as arguement name fp is the file pointer to this file in which output is to be directed.
void tree_filef(const char *name, int level, FILE *fp) {
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
			fprintf(fp, "%s",s1);
		if((count + 1) > 0)
			fprintf(fp, "%s",s);
		fprintf(fp, ANSI_COLOR_BLUE "%s\n", path);
		fprintf(fp, ANSI_COLOR_RESET);
		tree_filef(path, level + 1, fp);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i < count - 1; i++)
			fprintf(fp, "|    ");
		--count;
		fprintf(fp, "|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
/*writing the output of -a -L level -f option to file given as arguement name fp is the file pointer to this file in which output is to be directed.
writing the full path of directory and its contents only till particular specified level*/
void tree_FILEa(const char *name, int level, FILE *fp) {
	
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
			fprintf(fp, "%s",s1);
		if((count + 1) > 0)
			fprintf(fp, "%s",s);
		fprintf(fp, ANSI_COLOR_BLUE "%s\n", path);
		fprintf(fp, ANSI_COLOR_RESET);
		tree_FILEa(path, level + 1, fp);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		++count;
		for(i = 0; i < count - 1; i++)
			fprintf(fp, "|    ");
		--count;
		fprintf(fp, "|____%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}

/*writing the output of -d -L level -f option to file given as arguement name fp is the file pointer to this file in which output is to be directed.
writing the full path of directory and its contents only till particular specified level*/
void tree_FILEd(const char *name, int level, FILE *fp) {
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
		for(i = 0;i < (count - 1);i++)
			fprintf(fp, "%s",s1);
		if((count + 1) > 0)
			fprintf(fp, "%s",s);
		fprintf(fp, ANSI_COLOR_BLUE "%s\n", path);
		fprintf(fp, ANSI_COLOR_RESET);
		tree_FILEd(path, level + 1, fp);
		--count;
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
/*writing the output of -i -L level -f option to file given as arguement name fp is the file pointer to this file in which output is to be directed.
writing the full path of directory and its contents WITHOUT INDENTATION only till particular specified level*/
void tree_FILEi(const char *name, int level, FILE *fp) {
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
		fprintf(fp, ANSI_COLOR_BLUE "%s\n", path);
		fprintf(fp, ANSI_COLOR_RESET);
		tree_FILEi(path, level + 1, fp);
		--count;
	}
	else {
		++file;
		char path[1024];
		int len = snprintf(path, sizeof(path)-1, "%s/%s", name, dr->d_name);
		path[len] = 0;
		fprintf(fp, "%s\n", path);
	}
	
	} while (dr = readdir(dir));
	closedir(dir);
}
