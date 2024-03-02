#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define STRSIZE 20

typedef struct student {
	char name[STRSIZE];
	int number;
} std;

int main() {
	int input, count;
	char buffer[STRSIZE];
	std c[SIZE];
	FILE* fp1;
	FILE* fp2;
	while (1) {
		printf("(1) input (2) output (3) save (4) load (5) exit\n");
		printf("Do: ");
		scanf("%d", &input);
		if (input == 5) break;
		if (input == 1) {
			printf("how many input?\n");
			scanf("%d", &count);
			for (int i = 0; i < count; i++) {
				printf("name: ");
				scanf("%s", &buffer);
				strcpy(c[i].name, buffer);
				printf("number: ");
				scanf("%d", &c[i].number);
			}
		}
		if (input == 2) {
			for (int i = 0; i < count; i++) {
				printf("name: %s\tnumber: %d\n", c[i].name, c[i].number);
			}
		}
		if (input == 3) {
			if ((fp1 = fopen("cstr.dat", "wb")) == NULL) fprintf(stderr, "e\n");
			fwrite(c, sizeof(std), count, fp1);
			fclose(fp1);
			if ((fp2 = fopen("count.dat", "wb")) == NULL) fprintf(stderr, "e\n");
			fwrite(&count, sizeof(int), 1, fp2);
			fclose(fp2);
			printf("Sucess save!\n");
		}
		if (input == 4) {
			if ((fp1 = fopen("cstr.dat", "rb")) == NULL) fprintf(stderr, "e\n");
			if ((fp2 = fopen("count.dat", "rb")) == NULL) fprintf(stderr, "e\n");
			fread(&count, sizeof(int), 1, fp2);
			fclose(fp2);
			fread(c, sizeof(std), count, fp1);
			fclose(fp1);
			printf("Sucess load!\n");
		}
	}

	return 0;
}