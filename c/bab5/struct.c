#include <stdio.h>
#include <stdlib.h>

typedef struct {
	const char *judul[1]; // array of pointer, sama dengan variabel pointer, cuman ini bisa menyimpan lebih banyak address string literal
	char band[1][30]; // array of array
	const char *alamat; // variabel pointer
} music;

typedef struct {
	const char *name;
	const char *aka;
	const char *division[2];
	music mp3;
} hacker;

void cetak(hacker a, char *counter) {
	printf("\nNama: %s\na.k.a: %s\nDivision: %s\nMusic: %s\nBand : %s\nAlamat: %s\n\n", a.name, a.aka, a.division[atoi(counter)], a.mp3.judul[0], a.mp3.band[0], a.mp3.alamat);
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("\nUSE: %s <0 or 1>\n\n", argv[0]);
		exit(1);
	}
	hacker h = {"Muhammad Adib Dzulfikar", "ACE", {"Shellcode", "Metasploit"}, {"Langit Tak Mendengar","Peterpan - Alexandria", "Semboro"}};
	cetak(h, argv[1]);
	return 1;
}
