#include "SyntacticAnalizer.h"
#include "File.h"
#include "Auxiliary.h"


int main(int argv, char** argc) {
	
	unsigned char* file_content = readFile("test_program.txt");
	Token* tokens = generateTokens(file_content);
	checkError(tokens);
	
	//printTokens(tokens);
}