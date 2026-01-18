#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char s[1000]){
	FILE *main, *bak;
	char bakP[] = "./backup.bak";
	char _bak;

	if (argc == 1){printf("No arguments."); return 1;}

	if (argv[1] == NULL){printf("No filename."); return 1;}

	main = fopen(argv[1], "w");
	bak = fopen(bakP, "w");
	if (bak == NULL){fclose(main); printf("Could not open the file for backup"); return 1;}
	if (main == NULL){printf("Could not open the file."); return 1;}

	printf("\n");

	printf("@ ");
	scanf("%s", s);

	fprintf(main,s);
	fclose(main); fclose(bak);
	return 0;
}
