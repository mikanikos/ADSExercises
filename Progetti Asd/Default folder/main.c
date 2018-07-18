#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void set_std_buffer_off() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
	// turn off the std buffering
	set_std_buffer_off();

	int a;
	printf("!!!Hello World!!!\n"); // prints !!!Hello World!!!
	scanf("\n%d",&a);
	printf("\nIl numero immesso è %d", a);
	return 0;
}
