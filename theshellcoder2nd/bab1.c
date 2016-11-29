#include <stdio.h>

int triangle(int width, int height) {
	int array[5] = {0,1,2,3,4};
	int area;
	area = (width * height) / 2;
	return (area);
}

int main() {
	int hasil = triangle(2, 3);
	printf("hasil : %i\n", hasil);
}
