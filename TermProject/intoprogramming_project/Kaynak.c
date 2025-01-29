#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 3

//d�ng�ler yard�m� ile matrisi �izdiriyoruz
void drawMatrix(int matrix[SIZE][SIZE])
{
	printf("\n===================\n");
	for (int i = 0; i < SIZE; i++) {
		printf("|     |     |     |\n");
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] < 10) {  // Bu k�s�mda 10 ile kontrol etme sebebi, e�er basamak say�s� 1'den b�y�kse say�n�n daha az bo�luk b�rakmas�
				printf("|  %d  ", matrix[i][j]);
			}
			else {
				printf("| %d  ", matrix[i][j]);
			}
		}
		printf("|\n");
		if (i < SIZE - 1) {  // Son sat�r d���nda �izgiyi ekle
			printf("|_____|_____|_____|\n");
		}
	}
	printf("===================\n\n");
}



//girilen say�n�n matrixteki yerini bulmam�z laz�m,bunun i�in matrixteki elemanlar� d�ng� ile kontrol edip istenilen say�ya e�it
//olup olmad���n� kontrol edece�iz.e�it olan say� bulundu�unda i ve j konumal�r�n� x ve y adl� de�i�kenlere atayaca��z ki
//sonradan konum de�i�imi yapabilelim.bunlara dayanarak matrix[i][j],number,x ve y olmak �zere 4 de�i�ken alan bir fonsiyon yaz�caz.


void findtheNumberPosition(int matrix[SIZE][SIZE], int number, int* x, int* y) 
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			if (matrix[i][j] == number) 
			{
				*x = i;  //x ve y de�i�kenlerimizi pointer"*" ile g�sterimini yapt�k ��nk� bu de�erleri main den al�caz ve adesteki de�eri
				*y= j;  //de�i�sin istiyoruz
				return;

			}

		}
		
	}

}

//haraket sadece yan yana yada alt alta olan kareler i�in ge�erli oldu�u i�in bunun kontrol� yap�lmakta,
//kontrol mant���m�z ise bu iki kare aras�ndaki kordinat fark�n�n 1 olmas� gereklili�ine dayal�,
//abs mutlak de�er fonksiyonudur,bu fonsiyon iki kordinat aras�ndaki fark�n 1 e e�it olup olmad���n� kontrol eder buna g�re true false d�nd�r�r.
bool isMoveAcceptable(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2)) == 1;
}




//bu k�s�mda count de�i�kenimizi 1 artt�ra artt�ra ve matrisin elemanlar�yla  tek tek kar��la�t�rarak s�ral� m� diye kontrol ediyoruz

bool isSorted(int matrix[SIZE][SIZE]) {
	int count = 1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] != count++) {
				return false; // S�ral� de�ilse false d�ner
			}
		}
	}
	return true; // T�m de�erler s�ral�ysa true d�ner
}


// Hamle say�s�n� g�steren �er�eve
void printMoves(int moves) {
	printf("\n===========================\n");
	printf("|                         |\n");
	printf("|  Yapilan Hamle Sayisi: %2d  |\n", moves);
	printf("|                         |\n");
	printf("===========================\n\n");
}

int main() {
	int matrix[SIZE][SIZE]; //tan�mlamalar� yapt�k
	int numbers[9];
	int index = 0, moves = 0;

	//matrise yazaca��m�z random say�lar i�in haz�rl�k yap�yoruz
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		numbers[i] = i + 1;
	}


	//numbers dizisindeki say�lar� kar��t�r�yoruz

	for (int i = 0; i < 9; i++) {
		int j = rand() % 9;
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}

	// kar��t�rd���m�z say�lardan olu�an numbers dizisindeki rakamlarla matrisi dolduruyoruz
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = numbers[index++];
		}
	}


	printf("\n\n*************** SAYISAL YAPBOZ OYUNUNA HOSGELDINIZ ***************\n\n");

	while (1) {
		// Matrisi g�ster
		drawMatrix(matrix);


		printMoves(moves);

		// Kullan�c�dan giri� al
		int num1, num2;
		printf("Yerlerini degistireceginiz iki sayiyi girin (num1 num2): ");
		scanf_s("%d %d", &num1, &num2);

		// Pozisyonlar� bul
		int x1, y1, x2, y2;
		findtheNumberPosition(matrix, num1, &x1, &y1);
		findtheNumberPosition(matrix, num2, &x2, &y2);

		// Hareket ge�erli mi?
		if (!isMoveAcceptable(x1, y1, x2, y2)) {
			printf("\n!!! Gecersiz hareket! Sadece yan yana veya alt ustteki sayilar degistirilebilir. !!!\n\n");
			continue;
		}

		// De�i�tir
		int temp = matrix[x1][y1];
		matrix[x1][y1] = matrix[x2][y2];
		matrix[x2][y2] = temp;
		moves++;

		// Kazanma durumunu kontrol et
		if (isSorted(matrix)) {
			drawMatrix(matrix);
			printf("\nTebrikler! Oyunu %d hamlede tamamladiniz.\n", moves);
			printf("************************************************************\n");
			// Program�n sonlanmas�n� engellemek i�in kullan�c�dan bir tu�a basmas�n� bekle
			printf("Oyunu bitirdiniz. Devam etmek i�in bir tus tuslayin...\n");
			getchar();  // Bu sat�r, kullan�c�dan giri� alarak program�n sonlanmas�n� engeller
			getchar();  // Bir tu�a bas�lmas�n� bekler
			break;
		}
	}

	return 0;

}