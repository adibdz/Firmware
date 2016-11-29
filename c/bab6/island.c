#include <stdio.h>

typedef struct island {
	const char *name;
	const char *opens;
	const char *closes;
	struct island *next;
} island;

void display(island *i) {
	// island *i = start;
	printf("\n- awal i point ke %p\n\n", i);
	for(; i != NULL; i = i->next) {
		printf("i point ke %p : Pulau: %s \nbuka: %s - %s\n", i, (*i).name, i->opens, i->closes);
	}
	printf("\n- akhir i point ke %p\n", i);


	// Maksudnya i !=NULL : apakah i masih point ke addressnya variabel struct (amity dkk) ? jika tidak
	// sekarang ia telah point ke 0 (NULL) karena dari assigment i = i->next. Dimana i->next
	// ini telah mencapai pulau terahir yaitu shutter yg shutter.next-nya bernilai NULL
	// diassigmentkan ke i. Sehingga variabel pointer i sekarang point ke NULL. LOOP berhenti. :)
}

int main(int argc, char *argv[]) {
	island amity = {"Amity", "09:00", "17:00", NULL};
	island craggy = {"Craggy", "09:00", "17:00", NULL};
	island isla_nubar = {"Isla Nubar", "09:00", "17:00", NULL};
	// island shutter = {"Shutter", "09:00", "17:00", &amity}; // LOOP forever XD
	island shutter = {"Shutter", "09:00", "17:00", NULL};
	island skull = {"Skull", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nubar;
	isla_nubar.next = &skull;
	skull.next = &shutter;

	// printf("amity.next = %p\n", amity.next);
	
	display(&amity);

	return 1;
}
