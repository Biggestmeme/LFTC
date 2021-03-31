#include "LexicalAnalizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool checkError(Token* tokens) {
	Token* temp = calloc(1, sizeof(Token));
	temp = tokens;

	while (temp->next != NULL) {
		printTokens(temp);
		temp = temp->next;
	}

	if (temp->code != END) {
		printf("Error at line %d\n", temp->line);
		return true;
	}
	else {
		printTokens(temp);
	}

	return false;
}



printTokens(Token* tokens) {
	if (tokens == NULL)
		return;

	printf("LINE : %d | ", tokens->line);
	printf("COD : %d  | ", tokens->code);
	switch (tokens->code) {
	case CT_INT:
			printf("ID: %s | VALUE : %d", "int",tokens->integer);
			break;
	case ID:
			printf("Variable_Name : %s", tokens->string);
			break;
	case CHAR:
			printf("ID : %s", "char");
			break;
	case END:
			printf("ID : %s", "END");
			break;
	case LPAR:
			printf("ID : %s", "LPAR");
			break;
	case RPAR:
			printf("ID : %s", "RPAR");
			break;
	case LBRACKET:
			printf("ID : %s", "LBRACKET");
			break;
	case RBRACKET:
			printf("ID : %s", "RBRACKET");
			break;
	case INT:
			printf("ID : %s", "int");
			break;
	case LACC:
			printf("ID : %s", "LACC");
			break;
	case RACC:
			printf("ID : %s", "RACC");
			break;
	case IF:
			printf("ID : %s", "IF");
			break;
	case ELSE:
			printf("ID : %s", "ELSE");
			break;
	case FOR:
			printf("ID : %s", "FOR");
			break;
	case SEMICOLON:
			printf("ID : %s", "SEMICOLON");
			break;
	case COMMA:
			printf("ID : %s", "COMMA");
			break;
	case EQUAL:
			printf("ID : %s", "EQUAL");
			break;
	case ASSIGN:
			printf("ID : %s", "ASSIGN");
			break;
	case RETURN:
			printf("ID : %s", "RETURN");
			break;
	case ADD:
			printf("ID : %s", "ADD");
			break;
	case LESS:
			printf("ID : %s", "LESS");
			break;
	case LESSEQ:
			printf("ID : %s", "LESSEQ");
			break;
	case GREATER:
			printf("ID : %s", "GREATER");
			break;
	case GREATEREQ:
			printf("ID : %s", "GREATEREQ");
			break;

	case SUB:
			printf("ID : %s", "SUB");
			break;
	case VOID:
			printf("ID : %s", "void");
			break;
	case CT_CHAR:
			printf("ID : %s | VALUE  %c", "char",tokens->integer);
			break;
	case CT_STRING:
			printf("ID : %s | VALUE : %s", "string",tokens->string );
			break;
	case DIV:
			printf("ID : %s", "DIV");
			break;
	case CT_REAL:
			printf("ID : %s | VALUE : %f", "CT_REAL",tokens->real);
			break;
	case MULT:
			printf("ID : %s", "MULT");
			break;
	case DOUBLE:
			printf("ID : %s", "double");
			break;
	case STRUCT:
			printf("ID : %s", "struct");
			break;
	case DOT:
			printf("ID : %s", "DOT");
			break;
	case AND:
			printf("ID : %s", "AND");
			break;
	}
	printf("\n");
}

unsigned char escapeChar(unsigned char character) {
	unsigned char prevCharacter;
	switch (character) {
	case 'a':
		prevCharacter = '\a';
		break;
	case 'b':
		prevCharacter = '\b';
		break;
	case 'f':
		prevCharacter = '\f';
		break;
	case 'n':
		prevCharacter = '\n';
		break;
	case 'r':
		prevCharacter = '\r';
		break;
	case 't':
		prevCharacter = '\t';
		break;
	case 'v':
		prevCharacter = '\v';
		break;
	case '\'':
		prevCharacter = '\'';
		break;
	case '\\':
		prevCharacter = '\\';
		break;
	case '?':
		prevCharacter = '\?';
		break;
	case '\0':
		prevCharacter = '\0';
		break;
	case '\"':
		prevCharacter = '\"';
		break;
	default:
		prevCharacter = '\a';
	}

	return prevCharacter;
}

