#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include "library/palindroms.h"

int main() {

	FILE* source, * target;
	char str[100], new_str[100];
	char name1[] = "C:\\Users\\son of chemistry\\OneDrive - ÔÃÁÎÓ ÂÎ ÏÃÓÒÈ\\Ïðîãðàììèðîâàíèå\\Ëàáà7\\laba7_1\\Files\\text.txt";
	char name2[] = "C:\\Users\\son of chemistry\\OneDrive - ÔÃÁÎÓ ÂÎ ÏÃÓÒÈ\\Ïðîãðàììèðîâàíèå\\Ëàáà7\\laba7_1\\Files\\palindroms.txt";
	source = fopen(name1, "w");
	int count = 0;
	if (source != NULL) {
		while (*str != '0') {
			fgets(str, 100, stdin);
			if (*str != '0') {
				fputs(str, source);
				count++;
			}
			
		}
		fclose(source);
	}
	else
		return 1;

	source = fopen(name1, "r");
	target = fopen(name2, "w");if (target == NULL)printf("file hasn't opened");
	
	for (int i = 0;i < count;i++){
		fgets(new_str, 100, source);
		if (palindroms(new_str) == 1) {  
			fputs(new_str, target);
		}
	}
	fclose(source);
	fclose(target);
}

