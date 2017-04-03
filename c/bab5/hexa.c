#include <stdio.h>

int main(int argc, char *argv[]) {
	typedef struct {
		unsigned int nyari_istri_solekhah:1;
		unsigned int hijaber:1; // 1 bit (true or false)
		unsigned int umur:7; // umur diperkirakan 1-100th. 100. dan 2 pangkat 7 = 128. 2 pangkat 6 = 64. yg mendekati 100 2 pangkat 7. 7 adalah jumlah bit.
	} bitfields;
	
	int hexa = 0xff;
	printf("\nhexa: %i\n\n", hexa);

	bitfields binik = {1,1,26};
	printf("Nyari istri solekhah: %i \nHijaber: %i \nUmur: %i \n\n", binik.nyari_istri_solekhah, binik.hijaber, binik.umur);
	return 1;
}
