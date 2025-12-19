#include <stdio.h>

int main(int argc, char **argv, char s[1000]){
  FILE *f;

	if (argc == 1){printf("No arguments."); return 1;}

	if (argv[1] == NULL){printf("No filename."); return 1;}

	f = fopen(argv[1], "w");
	if (f == NULL){printf("Could not open the file."); return 1;}

  printf("@ ");
  scanf("%s", s);

	fprintf(f,s);
	fclose(f);
	return 0;
}
