#include "LexicalAnalizer.h"
#include "File.h"

int main(int argv, char** argc) {
	if (argv != 2) {
		printf("Forgot about the file?\n");
		printf("%s.exe <file.atomc>\n",argc[0]);

		return -1;
	}
	unsigned char* file_content = readFile(argc[1]);
	Token* tokens = generateTokens(file_content);
	printTokens(tokens);
}