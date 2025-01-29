#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 3

//döngüler yardýmý ile matrisi çizdiriyoruz
void drawMatrix(int matrix[SIZE][SIZE])
{
	printf("\n===================\n");
	for (int i = 0; i < SIZE; i++) {
		printf("|     |     |     |\n");
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] < 10) {  // Bu kýsýmda 10 ile kontrol etme sebebi, eðer basamak sayýsý 1'den büyükse sayýnýn daha az boþluk býrakmasý
				printf("|  %d  ", matrix[i][j]);
			}
			else {
				printf("| %d  ", matrix[i][j]);
			}
		}
		printf("|\n");
		if (i < SIZE - 1) {  // Son satýr dýþýnda çizgiyi ekle
			printf("|_____|_____|_____|\n");
		}
	}
	printf("===================\n\n");
}



//girilen sayýnýn matrixteki yerini bulmamýz lazým,bunun için matrixteki elemanlarý döngü ile kontrol edip istenilen sayýya eþit
//olup olmadýðýný kontrol edeceðiz.eþit olan sayý bulunduðunda i ve j konumalýrýný x ve y adlý deðiþkenlere atayacaðýz ki
//sonradan konum deðiþimi yapabilelim.bunlara dayanarak matrix[i][j],number,x ve y olmak üzere 4 deðiþken alan bir fonsiyon yazýcaz.


void findtheNumberPosition(int matrix[SIZE][SIZE], int number, int* x, int* y) 
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			if (matrix[i][j] == number) 
			{
				*x = i;  //x ve y deðiþkenlerimizi pointer"*" ile gösterimini yaptýk çünkü bu deðerleri main den alýcaz ve adesteki deðeri
				*y= j;  //deðiþsin istiyoruz
				return;

			}

		}
		
	}

}

//haraket sadece yan yana yada alt alta olan kareler için geçerli olduðu için bunun kontrolü yapýlmakta,
//kontrol mantýðýmýz ise bu iki kare arasýndaki kordinat farkýnýn 1 olmasý gerekliliðine dayalý,
//abs mutlak deðer fonksiyonudur,bu fonsiyon iki kordinat arasýndaki farkýn 1 e eþit olup olmadýðýný kontrol eder buna göre true false döndürür.
bool isMoveAcceptable(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2)) == 1;
}




//bu kýsýmda count deðiþkenimizi 1 arttýra arttýra ve matrisin elemanlarýyla  tek tek karþýlaþtýrarak sýralý mý diye kontrol ediyoruz

bool isSorted(int matrix[SIZE][SIZE]) {
	int count = 1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] != count++) {
				return false; // Sýralý deðilse false döner
			}
		}
	}
	return true; // Tüm deðerler sýralýysa true döner
}


// Hamle sayýsýný gösteren çerçeve
void printMoves(int moves) {
	printf("\n===========================\n");
	printf("|                         |\n");
	printf("|  Yapilan Hamle Sayisi: %2d  |\n", moves);
	printf("|                         |\n");
	printf("===========================\n\n");
}

int main() {
	int matrix[SIZE][SIZE]; //tanýmlamalarý yaptýk
	int numbers[9];
	int index = 0, moves = 0;

	//matrise yazacaðýmýz random sayýlar için hazýrlýk yapýyoruz
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		numbers[i] = i + 1;
	}


	//numbers dizisindeki sayýlarý karýþtýrýyoruz

	for (int i = 0; i < 9; i++) {
		int j = rand() % 9;
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}

	// karýþtýrdýðýmýz sayýlardan oluþan numbers dizisindeki rakamlarla matrisi dolduruyoruz
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = numbers[index++];
		}
	}


	printf("\n\n*************** SAYISAL YAPBOZ OYUNUNA HOSGELDINIZ ***************\n\n");

	while (1) {
		// Matrisi göster
		drawMatrix(matrix);


		printMoves(moves);

		// Kullanýcýdan giriþ al
		int num1, num2;
		printf("Yerlerini degistireceginiz iki sayiyi girin (num1 num2): ");
		scanf_s("%d %d", &num1, &num2);

		// Pozisyonlarý bul
		int x1, y1, x2, y2;
		findtheNumberPosition(matrix, num1, &x1, &y1);
		findtheNumberPosition(matrix, num2, &x2, &y2);

		// Hareket geçerli mi?
		if (!isMoveAcceptable(x1, y1, x2, y2)) {
			printf("\n!!! Gecersiz hareket! Sadece yan yana veya alt ustteki sayilar degistirilebilir. !!!\n\n");
			continue;
		}

		// Deðiþtir
		int temp = matrix[x1][y1];
		matrix[x1][y1] = matrix[x2][y2];
		matrix[x2][y2] = temp;
		moves++;

		// Kazanma durumunu kontrol et
		if (isSorted(matrix)) {
			drawMatrix(matrix);
			printf("\nTebrikler! Oyunu %d hamlede tamamladiniz.\n", moves);
			printf("************************************************************\n");
			// Programýn sonlanmasýný engellemek için kullanýcýdan bir tuþa basmasýný bekle
			printf("Oyunu bitirdiniz. Devam etmek için bir tus tuslayin...\n");
			getchar();  // Bu satýr, kullanýcýdan giriþ alarak programýn sonlanmasýný engeller
			getchar();  // Bir tuþa basýlmasýný bekler
			break;
		}
	}

	return 0;

}