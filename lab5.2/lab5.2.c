#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "RUS");     //Русский язык.
	int ArraySize, Str, Col, MaxNum;     
	printf("Введите размер квадратной матрицы:");
	scanf_s("%d", &ArraySize);     //Вводим размер мартрицы.
	int** A = (int**)malloc(sizeof(int*) * ArraySize);     //Задаем массив A и выделяем память под строки.
    // В цикле выделяем память для строк и заполняем матрицу с клавиатуры.
	for (Str = 0; Str < ArraySize; Str++) {
		A[Str] = (int*)malloc(sizeof(int)*ArraySize); //Выделение памяти для элементов строки.
		for (Col = 0; Col < ArraySize; Col++) {
			printf("Введите элемент [%d][%d]:", Str+1, Col+1);
			scanf_s("%d", &A[Str][Col]);
		}
	}
	printf("\nИсходная матрица:\n");     
	//Отображаем введенную матрицу.
	for (Str = 0; Str < ArraySize; Str++) {
		for (Col = 0; Col < ArraySize; Col++) {
			printf("%d\t", A[Str][Col]);
		}
		printf("\n");
	}
	MaxNum = 0;
	//Находим наиборльший элемент в верхней четверти матрицы, перебирая элементы и присваиая их значение переменной MaxNum, если встречается значениие больше, чем MaxNum - выполняется замена данных.
	for (Str = 0; Str < ArraySize; Str++) {
		for (Col = Str; Col < ArraySize - Str; Col++) {
			if (MaxNum < A[Str][Col]) {
				MaxNum = A[Str][Col];
			}
		}
	}
	printf("\nМаксимальное значение в выделенном участке матрицы равно %d", MaxNum);    //Вывод результата. 
//	for (Str = ArraySize - 1; Str>= 0; --Str) {
//		free (A[Str]);
//	}
//	free(A);
	return 0;
}