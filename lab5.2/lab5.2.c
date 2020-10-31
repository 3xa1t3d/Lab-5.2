#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {
	setlocale(LC_ALL, "RUS");     //������� ����.
	int ArraySize, Str, Col, MaxNum;     
	printf("������� ������ ���������� �������:");
	scanf_s("%d", &ArraySize);     //������ ������ ��������.
	int** A = (int**)malloc(sizeof(int*) * ArraySize);     //������ ������ A � �������� ������ ��� ������.
    // � ����� �������� ������ ��� ����� � ��������� ������� � ����������.
	for (Str = 0; Str < ArraySize; Str++) {
		A[Str] = (int*)malloc(sizeof(int)*ArraySize); //��������� ������ ��� ��������� ������.
		for (Col = 0; Col < ArraySize; Col++) {
			printf("������� ������� [%d][%d]:", Str+1, Col+1);
			scanf_s("%d", &A[Str][Col]);
		}
	}
	printf("\n�������� �������:\n");     
	//���������� ��������� �������.
	for (Str = 0; Str < ArraySize; Str++) {
		for (Col = 0; Col < ArraySize; Col++) {
			printf("%d\t", A[Str][Col]);
		}
		printf("\n");
	}
	MaxNum = 0;
	//������� ����������� ������� � ������� �������� �������, ��������� �������� � ��������� �� �������� ���������� MaxNum, ���� ����������� ��������� ������, ��� MaxNum - ����������� ������ ������.
	for (Str = 0; Str < ArraySize; Str++) {
		for (Col = Str; Col < ArraySize - Str; Col++) {
			if (MaxNum < A[Str][Col]) {
				MaxNum = A[Str][Col];
			}
		}
	}
	printf("\n������������ �������� � ���������� ������� ������� ����� %d", MaxNum);    //����� ����������. 
//	for (Str = ArraySize - 1; Str>= 0; --Str) {
//		free (A[Str]);
//	}
//	free(A);
	return 0;
}