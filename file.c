#include "init.h"
int direc, file;
int count, nore, prune, lev;
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
}#include "init.h"
int direc, file;
int count, nore, prune, lev;
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
