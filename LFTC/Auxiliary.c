#include "Auxiliary.h"
#include <stdlib.h>
#include <stdio.h>

void Error(const char* error) {
	fprintf(stderr, "Error : %s\n", error);
	exit(-1);
}

void advanceArrayPointer(unsigned char** string) {
	unsigned char* temp = *string;
	temp++;
	*string = temp;
}