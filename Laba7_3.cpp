#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

int* treatment(int* Arr, int SizeArr); //функция обработки массива для записи в обратном порядке
int main()
{
	srand(time(NULL));
	FILE* FilePtr;int *BinaryArr, SizeArr=0;
	printf("enter the array size:");scanf_s("%d", &SizeArr); BinaryArr = (int*)calloc(SizeArr, sizeof(int));
	if (BinaryArr!=NULL) {
		fopen_s(&FilePtr, "Binary.txt", "wb"); // открытие файла для записи компонентов из массива в обычном порядке
		if (FilePtr) {
			printf("File has opened\n\n");
			printf("Our array:\n");
			for (int i = 0;i < SizeArr;i++) {
				BinaryArr[i] = rand() % 100 + 30;
				printf("%d ", BinaryArr[i]);
				fwrite(&BinaryArr[i], sizeof(int), 1, FilePtr);
			}
			fclose(FilePtr);
			free(BinaryArr);
		}
	}
	fopen_s(&FilePtr, "Binary.txt", "rb"); //открытие файла для чтения компонентов бинарного файла
		int tmp, count = 0;
		while (fread(&tmp, sizeof(int), 1, FilePtr)) {
			++count;
		}
		int* NewArr = (int*)calloc(count, sizeof(int));
		printf("\n\nOur components:\n");
		if(FilePtr)fseek(FilePtr, 0, SEEK_SET);
		for (int i = 0;i < count;i++) {
			fread(&NewArr[i], sizeof(int), 1, FilePtr);
			printf("%d ", NewArr[i]);
		}printf("\n\n");
		treatment(NewArr, count); 
		if(FilePtr)fclose(FilePtr);
	
	fopen_s(&FilePtr, "Binary2.txt", "wb"); //открытие 2-го файла, для записи компонентов в обратном порядке
	if (FilePtr) {
		fseek(FilePtr, 0, SEEK_SET);
		for (int i = 0;i < count;i++) {
			fwrite(&NewArr[i], sizeof(int), 1, FilePtr); // запись обработванных компонентов в другой Бинарный файл, для сравнения
		}
	}if(FilePtr)fclose(FilePtr);
	free(NewArr);
	return 0;
}







int* treatment(int* Arr, int SizeArr) {
	int* p = (int*)calloc(SizeArr,sizeof(int));
	for (int i = 0;i < SizeArr;i++) {
		p[i] = Arr[i];
	}
	for (int i = 0;i < SizeArr;i++)
		Arr[i] = p[SizeArr - 1 - i];
	return Arr;
}



