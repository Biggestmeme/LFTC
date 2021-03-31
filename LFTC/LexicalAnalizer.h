#pragma once
#ifndef LEXICALANALIZER_H_
#define LEXICALANALIZER_H_
#include <stdbool.h>

enum {
	START, ID, BREAK, CHAR, DOUBLE, ELSE, FOR, IF, INT, RETURN, STRUCT, VOID, WHILE, CT_INT, CT_REAL, CT_CHAR,
	COMMA, SEMICOLON, LPAR, RPAR, LBRACKET, RBRACKET, LACC, RACC, ADD, SUB, MULT, DIV, DOT, AND, OR, NOT, ASSIGN, EQUAL,
	NOTEQ, LESS, LESSEQ, GREATER, GREATEREQ, LINECOMMENT, LINECOMMENT_STATE_1, COMMENT, CHAR_STATE_0, CHAR_STATE_1,CHAR_STATE_2,
	STRING_STATE_0, STRING_STATE_1, STRING_STATE_2,ESCAPE_STRING,CT_STRING,END, ESCAPE_CHARS, BASE_10_INT, BASE_8_INT, BASE_16_INT, DIV_COMMENT,
	COMMENT_STATE_1,COMMENT_STATE_2, REAL_STATE_0, REAL_STATE_1, REAL_STATE_2, REAL_STATE_3
};


typedef struct token {
	union {
		char* string;
		long int integer;
		double real;
	};
	int code;
	int line; 
	struct Token* next; 
}Token;

unsigned char escapeChar(unsigned char character);
Token* generateTokens(unsigned char* file_content);
bool checkError(Token* tokens);
printTokens(Token* tokens);

#endif