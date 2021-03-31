#include "LexicalAnalizer.h"
#include "File.h"

int main(int argv, char** argc) {
	
	unsigned char* file_content = readFile("test_program.txt");
	Token* tokens = generateTokens(file_content);
	checkError(tokens);
	//printTokens(tokens);
}