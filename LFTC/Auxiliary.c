#include "Auxiliary.h"
#include "LexicalAnalizer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define TokenError(arg1, ...) do {            \
   int _x[] = { __VA_ARGS__ };   \
   _TokenError(Token* token,sizeof(_x)/sizeof(_x[0]), _x); \
} while(0)

void _TokenError(Token* token, int num_of_args, int args[]) {
	printf("Error at line : %d\n", token->line);

	for (int i = 0; i < num_of_args; i++) {
		switch (args[i]) {
		case CT_INT:
			printf("Expected an integer");
			break;
		case ID:
			printf("Variable name");
			break;
		case CHAR:
			printf("Type error : expected char");
			break;
		case END:
			printf("End of file not found");
			break;
		case LPAR:
			printf("Expected '(' ");
			break;
		case RPAR:
			printf("Expected ')' ");
			break;
		case LBRACKET:
			printf("Expected '[' ");
			break;
		case RBRACKET:
			printf("Expected ']' ");
			break;
		case INT:
			printf("Type error : expected int");
			break;
		case LACC:
			printf("Expected '{' ");
			break;
		case RACC:
			printf("Expected '}' ");
			break;
		case IF:
			printf("Expected 'If' statement");
			break;
		case ELSE:
			printf("Expected 'Else' statement");
			break;
		case FOR:
			printf("Expected 'For' statement");
			break;
		case SEMICOLON:
			printf("Expected ';' ");
			break;
		case COMMA:
			printf("Expected ' , ' ");
			break;
		case EQUAL:
			printf("Expected '==' ");
			break;
		case ASSIGN:
			printf("Expected '=' ");
			break;
		case RETURN:
			printf("Missing return statement");
			break;
		case ADD:
			printf("Expected '+' ");
			break;
		case LESS:
			printf("Expected '<'");
			break;
		case LESSEQ:
			printf("Expected '<='");
			break;
		case GREATER:
			printf("Expected '>'");
			break;
		case GREATEREQ:
			printf("Expected '>='");
			break;
		case SUB:
			printf("Expected '-'");
			break;
		case VOID:
			printf("Type error : expected void");
			break;
		case CT_CHAR:
			printf("char error, unknown : %c",token->integer);
			break;
		case CT_STRING:
			printf("string error, unknown : %s",token->string);
			break;
		case DIV:
			printf("Expected '/' ");
			break;
		case CT_REAL:
			printf("ID : %s | VALUE : %f", "CT_REAL");
			break;
		case MULT:
			printf("ID : %s", "MULT");
			break;
		case DOUBLE:
			printf("Type error : expected double");
			break;
		case STRUCT:
			printf("Type error : expected struct");
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
	printf("-----------------------------\n");
	
}

void advanceArrayPointer(unsigned char** string) {
	unsigned char* temp = *string;
	temp++;
	*string = temp;
}