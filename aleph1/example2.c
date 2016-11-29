void function(char *str) {
	char buffer[16];
	strcpy(buffer,str);
}

void main() {
	char large_string[30];
	int i;

	for(i=0; i<29; i++)
		large_string[i]='A';
	
	function(large_string);
}
