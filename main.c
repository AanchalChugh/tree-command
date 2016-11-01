#include "init.h"
int direc = 0, file = 0;
int count, nore = 0, prune, lev =0;
int main(int argc, char *argv[]) {
	switch(argc) {
		case 1: init(".", "-A");
			break;
		case 2: if(!(strcmp(argv[1], "-a")))
				init(".", argv[1]);
			else if(!(strcmp(argv[1], "-d")))
				init(".", argv[1]);
			else if(!(strcmp(argv[1], "-f"))) {
				init(".", argv[1]);	
			}
			else if(!(strcmp(argv[1], "-i")))
				initi(".", argv[1], "-A");
			else if(!strcmp(argv[1], "--noreport")) {
				nore = 1;
				init(".", "-A");
				nore = 0;
			}
			else if(!(strcmp(argv[1], "--prune"))) {
				init(".", argv[1]);
			}
			else if(!(strcmp(argv[1], "--help"))) {
				help();
			}
			else
				init(argv[1], "-A");
			
			break;
		case 3: if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-a"))) || (!(strcmp(argv[2], "-a")) && !(strcmp(argv[1], "-i"))))
				initi(".", argv[1], argv[2]);
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-d"))) || (!(strcmp(argv[2], "-d")) && !(strcmp(argv[1], "-i"))))
				initi(".", argv[1], argv[2]);
			else if((!(strcmp(argv[1], "-a")) || !(strcmp(argv[1], "-d"))) && !(strcmp(argv[2], "-o"))) 
				printf("tree: missing arguement to -o option");
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-i")))) {	
				nore = 1;
				initi(".", "-i", "-A");
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-a")))) {	
				nore = 1;
				init(".", "-a");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-d")))) {	
				nore = 1;
				init(".", "-d");
				nore = 0;
			}
			else if((!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-f")))) {	
				nore = 1;
				init(".", "-f");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a"))))
				initi(".", argv[1], argv[2]);
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d"))))
				initi(".", argv[1], argv[2]);	
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[2], "-f")) && !(strcmp(argv[1], "-i"))))
				initi(".", argv[1], argv[2]);
			else if(!(strcmp(argv[1], "-a"))) 
				init(argv[2], argv[1]);
			else if(!(strcmp(argv[1], "-i")))
				initi(argv[2], "-i", "-A");
			else if(!(strcmp(argv[1], "-d")))
				init(argv[2], argv[1]);
			else if(!(strcmp(argv[1], "-f"))) 
				init(argv[2], argv[1]); 
			else if(!(strcmp(argv[1], "-o")))
				initfile(".", argv[2], "-A");
			else if(!(strcmp(argv[1], "--prune")))
				init(argv[2], argv[1]);
			else if(!(strcmp(argv[1], "-L"))) {
				lev = atoi(argv[2]);
				initlevel(".", "-A");
			}
			else if(!(strcmp(argv[1], "--filelimit")))				
				initlimit(".", argv[2]);
			else if(!(strcmp(argv[1], "--timefmt"))) {
				inittime(".", argv[2]);
			 }
			break;
		case 4: if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-i")))) {	
				nore = 1;
				initi(argv[3], "-i", "-A");
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-a")))) {	
				nore = 1;
				init(argv[3], "-a");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-d")))) {	
				nore = 1;
				init(argv[3], "-d");
				nore = 0;
			}
			else if((!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "--noreport"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-f")))) {	
				nore = 1;
				init(argv[3], "-f");
				nore = 0;
			}
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a"))))
				initi(argv[3], argv[1], argv[2]);
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d"))))
				initi(argv[3], argv[1], argv[2]);	
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[2], "-f")) && !(strcmp(argv[1], "-i"))))
				initi(argv[3], argv[1], argv[2]);
			else if(!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-o")))
				initfile(".", argv[1], argv[3]);
			else if(!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")))
				initfile(".", argv[3], argv[2]);
			else if(!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-L"))) {
				lev = atoi(argv[3]);
				initlevel(".", argv[1]);
			}
			else if(!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f"))) {
				lev = atoi(argv[2]);
				initlevel(".", argv[3]);
			}
			else if(!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "--noreport"))) {
				nore = 1;
				initfile(".", argv[2], "-A");
				nore = 0;

			}
			else if(!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-o"))) {	
				nore = 1;
				initfile(".", argv[3], "-A");
				nore = 0;
			}	
			else if(!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-L"))) {
				lev = atoi(argv[3]);
				initlevel(".", argv[1]);
			}
			else if(!(strcmp(argv[3], "-d")) && !(strcmp(argv[1], "-L"))) {
				lev = atoi(argv[2]);
				initlevel(".", argv[3]);
			}
			else if(!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-L"))) { 

				lev = atoi(argv[3]);
				initlevel(".", argv[1]);
			}
			else if(!(strcmp(argv[3], "-a")) && !(strcmp(argv[1], "-L"))) {
				lev = atoi(argv[2]);
				initlevel(".", argv[3]);
			}
			else if(!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-L"))) {
				lev = atoi(argv[3]);
				initlevel(".", argv[1]);
			}
			else if(!(strcmp(argv[3], "-i")) && !(strcmp(argv[1], "-L"))) {
				lev = atoi(argv[2]);
				initlevel(".", argv[3]);
			}
			else if(!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-L"))) {
				nore = 1;
				lev = atoi(argv[3]);
				initlevel(".", argv[1]);
				nore =0;
			}
			else if(!(strcmp(argv[3], "--noreport")) && !(strcmp(argv[1], "-L"))) {
				nore = 1;
				lev = atoi(argv[2]);
				initlevel(".", argv[3]);
				nore = 0;
			}
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-i"))))
				initi(argv[3], argv[1], argv[2]);
			else if(!(strcmp(argv[1], "--filelimit")))				
				initlimit(argv[3], argv[2]);
			else if(!(strcmp(argv[1], "-o")))
				initfile(argv[3], argv[2], "-A");
			else if(!(strcmp(argv[2], "-o")) && !(strcmp(argv[1], "-a")))
				initfile(".", argv[3], argv[1]); 
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f"))) || (!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f"))))
				initi(".", argv[1], argv[2]); 
			else if(!(strcmp(argv[2], "-o")) && !(strcmp(argv[1], "-d")))
				initfile(".", argv[3], argv[1]); 
			else if(!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-o")))
				initifile(".", argv[3]);
			else if(!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-a")))
				initi(argv[3], argv[1], argv[2]);
			else if(!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-d")))
				initi(argv[3], argv[1], argv[2]);
			else if(!(strcmp(argv[1], "-L"))) {
				lev = atoi(argv[2]);
				initlevel(argv[3], "-A");
			}
			else if(!(strcmp(argv[1], "--timefmt"))) {
				inittime(argv[3], argv[2]);
			 }
			break;
		case 5: if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-o")))) {	
				nore = 1;
				initifile(".", argv[4]);
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-o")))) {
				nore = 1;
				initfile(".", argv[4], "-a");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {	
				nore = 1;
				initfile(".", argv[4], "-d");
				nore = 0;
			}		 
			if(!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "--noreport"))) {
				nore = 1;
				initfile(argv[4], argv[2], "-A");
				nore = 0;

			}
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-o")))) {
				initFILE(".", argv[4], "-a", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-a"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-a")))) {
				initFILE(".", argv[2], "-a", "-f");
			}
			if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {
				initFILE(".", argv[4], "-d", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-d"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-d")))) {
				initFILE(".", argv[2], "-d", "-f");
			}
			if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-o")))) {
				initFILE(".", argv[4], "-i", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-i"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-i")))) {
				initFILE(".", argv[2], "-i", "-f");
			}
			else if(!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-o"))) {	
				nore = 1;
				initfile(argv[4], argv[3], "-A");
				nore = 0;
			}
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-L"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-L")))) {
				lev = atoi(argv[4]);
				initLEVEL(".", "-a", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-a"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-a")))) {
				lev = atoi(argv[2]);
				initLEVEL(".", "-a", "-f");
			}
			if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {
				lev = atoi(argv[4]);
				initLEVEL(".", "-d", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-d"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-d")))) {
				lev = atoi(argv[2]);
				initLEVEL(".", "-d", "-f");
			}
			if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-L"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-L")))) {
				lev = atoi(argv[4]);
				initLEVEL(".", "-i", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-i"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-i")))) {
				lev = atoi(argv[2]);
				initLEVEL(".", "-i", "-f");
			}
			else if(!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-o")))
				initfile(argv[4], argv[1], argv[3]);
			else if(!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")))
				initfile(argv[4], argv[3], argv[2]);
			else if(!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-L"))) {
				lev = atoi(argv[3]);
				initlevel(argv[4], argv[1]);
			}
			else if(!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f"))) {
				lev = atoi(argv[2]);
				initlevel(argv[4], argv[3]);
			}	
			else if(!(strcmp(argv[2], "-o")) && !(strcmp(argv[1], "-a")))
				initfile(argv[4], argv[3], argv[1]); 
			else if(!(strcmp(argv[2], "-o")) && !(strcmp(argv[1], "-d")))
				initfile(argv[4], argv[3], argv[1]); 
			else if(!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-o")))
				initifile(argv[4], argv[3]);
			break;
			case 6:  if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-o")))) {	
				nore = 1;
				initifile(argv[5], argv[4]);
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[2], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[4], "-i")) && !(strcmp(argv[2], "-o")))) {	
				nore = 1;
				initifile(argv[5], argv[3]);
				nore = 0;
			}	
			if((!(strcmp(argv[3], "-i")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[1], "-o"))) || (!(strcmp(argv[3], "--noreport")) && !(strcmp(argv[4], "-i")) && !(strcmp(argv[1], "-o")))) {	
				nore = 1;
				initifile(argv[5], argv[2]);
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-a");
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[2], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[4], "-a")) && !(strcmp(argv[2], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-a");
				nore = 0;
			}	
			else if((!(strcmp(argv[3], "-a")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[1], "-o"))) || (!(strcmp(argv[3], "--noreport")) && !(strcmp(argv[4], "-a")) && !(strcmp(argv[1], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-a");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "--noreport")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-d");
				nore = 0;
			}		
			else if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[2], "-o"))) || (!(strcmp(argv[1], "--noreport")) && !(strcmp(argv[4], "-d")) && !(strcmp(argv[2], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-d");
				nore = 0;
			}	
			else if((!(strcmp(argv[3], "-d")) && !(strcmp(argv[4], "--noreport")) && !(strcmp(argv[1], "-o"))) || (!(strcmp(argv[3], "--noreport")) && !(strcmp(argv[4], "-d")) && !(strcmp(argv[1], "-o")))) {	
				nore = 1;
				initfile(argv[5], argv[4], "-d");
				nore = 0;
			}	
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-o")))) {
				initFILE(argv[5], argv[4], "-a", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-a"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-a")))) {
				initFILE(argv[5], argv[2], "-a", "-f");
			}
			if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {
				initFILE(argv[5], argv[4], "-d", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-d"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-d")))) {
				initFILE(argv[5], argv[2], "-d", "-f");
			}
			if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-o")))) {
				initFILE(argv[5], argv[4], "-i", "-f");
			}	
			else if((!(strcmp(argv[1], "-o")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-i"))) || (!(strcmp(argv[1], "-o")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-i")))) {
				initFILE(argv[5], argv[2], "-i", "-f");
			}
			else if((!(strcmp(argv[1], "-a")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-L"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-a")) && !(strcmp(argv[3], "-L")))) {
				lev = atoi(argv[4]);
				initLEVEL(argv[5], "-a", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-a"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-a")))) {
				lev = atoi(argv[2]);
				initLEVEL(argv[5], "-a", "-f");
			}
			if((!(strcmp(argv[1], "-d")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-o"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-d")) && !(strcmp(argv[3], "-o")))) {
				lev = atoi(argv[4]);
				initLEVEL(argv[5], "-d", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-d"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-d")))) {
				lev = atoi(argv[2]);
				initLEVEL(argv[5], "-d", "-f");
			}
			if((!(strcmp(argv[1], "-i")) && !(strcmp(argv[2], "-f")) && !(strcmp(argv[3], "-L"))) || (!(strcmp(argv[1], "-f")) && !(strcmp(argv[2], "-i")) && !(strcmp(argv[3], "-L")))) {
				lev = atoi(argv[4]);
				initLEVEL(argv[5], "-i", "-f");
			}	
			else if((!(strcmp(argv[1], "-L")) && !(strcmp(argv[3], "-f")) && !(strcmp(argv[4], "-i"))) || (!(strcmp(argv[1], "-L")) && !(strcmp(argv[4], "-f")) && !(strcmp(argv[3], "-i")))) {
				lev = atoi(argv[2]);
				initLEVEL(argv[5], "-i", "-f");
			}
			break;
		default: printf("USAGE : ./a.out [PATH] \n");		
	}
	return 0;
}
