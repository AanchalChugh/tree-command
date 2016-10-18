#include "file.h"
void Usage() {
		printf("<usage> ./try <directory name> Working only for some kind of trees\n");
		printf("<usage> ./try -a <directory name>\n This option isn't working\n");
		printf("Rest all not implemented\n");
}
int main( int argc, char *argv[] ) {
	
	if(argc!= 1) {
		Usage();
	}
	
	if(strcmp(argv[1], "-a") == 0) {
		inito(argv[2]);
		listdiro(argv[2], 0);	
	}
	else {
		init(argv[1]);
		listdir(argv[1], 0);
	}
	return 0;
	
}
