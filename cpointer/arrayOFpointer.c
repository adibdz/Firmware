#include <stdio.h>

int main() {
	int arr[] = {1,2,3,4};
	int *arrptr[4];
	int i; // loop variable

	for(i = 0; i < 4; i++)
		arrptr[i] = &arr[i];

	printf("Address of arr  %p\n", arr);
	printf("Address of &arr %p\n", &arr);
	for(i = 0; i < 4; i++){ 
		printf("Arr indeks-%d: Address: %p --> Val: %d\n",
				i, &arr[i], arr[i]);
	}
	printf("\n");
	printf("Address of arrptr  %p\n", arrptr);
	printf("Address of &arrptr %p\n", &arrptr);
	for(i = 0;i < 4; i++) {
		printf("Arrptr indeks-%d: Address: %p --> Val: %p\n",
				i, &arrptr[i], arrptr[i]);
	}
}
