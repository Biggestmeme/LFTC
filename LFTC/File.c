#include "File.h"
#include "Auxiliary.h"
#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable : 4996)

int fileSize(FILE* file) {
	if (file == NULL)
		return 0;

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	return size;
}

unsigned char* readFile(const char* PATH) {
	if (PATH == NULL)
		return NULL;

	FILE* file = fopen(PATH, "r");
	if (file == NULL) {
		Error("File Open");
	}

	int file_size = fileSize(file);
	unsigned char* file_content;
	SAFEALLOC(file_content, unsigned char, file_size);

	unsigned char current_character = 0;
	int index = 0;
	while ((current_character = fgetc(file)) != UNSIGNED_EOF) {
		file_content[index] = current_character;
		index++;
	}

	file_content[index] = '\0';

	fclose(file);

	return file_content;
}