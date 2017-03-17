#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"
/*	#include <encrypt.h>
	#include <checksum.h>
	if use <angle> bracket, it to be able to compile and assemble (-c)
	to create object file, use -I. cz compiler search header file in
	standart directory first.
	> gcc -c tescode.c -I. -o tescode.o
	it's also may to compile and linkking with another object file
	using (-I.). the (.) dot is current directory.
	> gcc tescode.c -I. -L. -llowsecurity -o tescode
	-I. : compiler will search header file(*.h) in current directory.
	-L. : compiler will search archive file(*.a) in current directory.
	-l  : for lib archive file.
	*/

int main() {
	char *_s = "EMPEROR"; /* string here is string literal
							 cannot be changed. its belong
							 to somewhere in memory
							 */
	char s[] = "EMPEROR"; /* string here is in stack. it can
							 to replace, delete or something.
							 because it is not string literal.
							 its just an array
							 */
	encrypt(s);
	printf("Encrypted to:\t'%s'\n", s);
	printf("Checksum is:\t%i\n", checksum(s));
	encrypt(s);
	printf("Decrypted to:\t'%s'\n", s);
	printf("Checksum is:\t%i\n", checksum(s));
	return 0;
}
