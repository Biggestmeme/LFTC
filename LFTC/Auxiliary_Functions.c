#include "LexicalAnalizer.h"
#include <stdlib.h>
#include <stdio.h>

printTokens(Token* tokens) {
	if (tokens == NULL)
		return;

	printf("LINE : %d | ", tokens->line);
	printf("COD : %d  | ", tokens->code);
	switch (tokens->code) {
	case CT_INT:
			printf("ID: %s", "int");
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
			printf("ID : %s", "char");
			break;
	case CT_STRING:
			printf("ID : %s", "string");
			break;
	case DIV:
			printf("ID : %s", "DIV");
			break;
	case CT_REAL:
			printf("ID : %s", "CT_REAL");
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
	printTokens(tokens->next);
}