#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct table {
	char surname[100] = "huy";
	int num;
	int math;
	int physics;
	int chemical;
	int drawing;
	double average;
};
int main() {
	srand(time(NULL));
	table result[16];
	FILE* FileTable, * NewTable;
	FileTable = fopen("Table.txt", "w"); //первый файл открыт
	fprintf(FileTable, "  Surname|Number|Math|Physics|Chemical|Drawing|\n");
	if (FileTable != NULL) {
		for (int i = 0;i < 16;i++) {
			result[i].num = rand() % 500 + 500;
			result[i].math = rand() % 3 + 3;
			result[i].physics = rand() % 3 + 3;
			result[i].chemical = rand() % 3 + 3;
			result[i].drawing = rand() % 3 + 3;
			result[i].average = ((result[i].math + result[i].physics) + (result[i].chemical + result[i].drawing)) / 4.;
			gets_s(result[i].surname, 100);
			fprintf(FileTable, "%10s|%12d|%8d|%14d|%14d|%14d|\n", result[i].surname, result[i].num, result[i].math, result[i].physics, result[i].chemical, result[i].drawing);
		}
	}fclose(FileTable);

	FileTable = fopen("table.txt", "r");
	NewTable = fopen("NewTable.txt", "w");
	NewTable = fopen("NewTable.txt", "w");
	char NewStr[500];
	fseek(FileTable, 0L, SEEK_SET);
	fgets(NewStr, 100, FileTable);
	NewStr[strlen(NewStr) - 1] = '\0';
	fprintf(NewTable, "%sAverage|\n", NewStr);
	for (int i = 0;i < 16;i++) {
		int m = 0;
		fgets(NewStr, 100, FileTable);
		NewStr[strlen(NewStr) - 1] = '\0';
		fprintf(NewTable, "%s%10.2lf|\n", NewStr, result[i].average);
	}
	fclose(NewTable);fclose(FileTable);
	return 0;

}