#include "LexicalAnalizer.h"
#include "Auxiliary.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

Token* initializeTokenList() {
	return calloc(1,sizeof(Token));
}

int addToken(Token* tokenList,Token** lastToken,int code, int line) {
	Token* token = calloc(1,sizeof(Token));
	//SAFEALLOC(token,&token, 1);

	token->code = code;
	token->line = line;
	token->next = NULL;

	if (*lastToken != NULL)
		(*lastToken)->next = token;
	else
		*tokenList = *token;

	*lastToken = token;

	return 1;
}

Token* generateTokens(unsigned char* file_content) {
	int state = 0;
	int line = 1;
	int id_length = 0;
	int added = 0;
	int number_base = 10; //default
	unsigned char character;
	unsigned char prevCharacter = 0;
	int null = 0;
	const unsigned char* pStartCharacter = NULL;
	Token* tokenList = calloc(1, sizeof(Token));
	Token* token = tokenList;

	state = 0;

	while (file_content != 0) {
		added = 0;
		state = START;
		prevCharacter = 255;

		while (1) { // bucla infinita

			character = *file_content;


			switch (state) {
			case START: // testare tranzitii posibile din starea 0
				//to do => swap the virgin if with the chad switch
				if (isalpha(character) || character == '_') {
					pStartCharacter = file_content;
					file_content++;
					state = ID;
				}
				else if (character == '\n') {
					line++;
					file_content++;
				}
				else if (character == ' ' ||
					character == '\r' ||
					character == '\t')
					file_content++;
				else if (character == '/') {
					file_content++;
					state = LINECOMMENT_STATE_1;
				}
				else if (character == ',') {
					file_content++;
					state = COMMA;
				}
				else if (character == ';') {
					file_content++;
					state = SEMICOLON;
				}
				else if (character == '(') {
					file_content++;
					state = LPAR;
				}
				else if (character == ')') {
					file_content++;
					state = RPAR;
				}
				else if (character == '[') {
					file_content++;
					state = LBRACKET;
				}
				else if (character == ']') {
					file_content++;
					state = RBRACKET;
				}
				else if (character == '{') {
					file_content++;
					state = LACC;
				}
				else if (character == '}') {
					file_content++;
					state = RACC;
				}
				else if (character == '+') {
					file_content++;
					state = ADD;
				}
				else if (character == '-') {
					file_content++;
					state = SUB;
				}
				else if (character == '*') {
					file_content++;
					state = MULT;
				}
				else if (character == '\0' || character == 255) {
					file_content++;
					state = END;
				}
				else if (character == '.') {
					file_content++;
					state = DOT;
				}
				else if (character == '&') {
					file_content++;
					state = AND;
				}
				else if (character == '|') {
					file_content++;
					state = OR;
				}
				else if (character == '!') {
					file_content++;
					state = NOT;
				}
				else if (character == '=') {
					file_content++;
					state = EQUAL;
				}
				else if (character == '<') {
					file_content++;
					state = LESS;
				}
				else if (character == '>') {
					file_content++;
					state = GREATER;
				}
				else if (character == '\'') {
					pStartCharacter = file_content;
					file_content++;
					state = CHAR_STATE_0;
				}
				else if (character == '\"') {
					file_content++;
					pStartCharacter = file_content;
					state = STRING_STATE_0;
				}
				else if (isdigit(character) && character != '0') { // number
					pStartCharacter = file_content;
					file_content++;
					state = BASE_10_INT;
				}
				else if (character == '0') { //hexa or octal number
					pStartCharacter = file_content;
					file_content++;
					state = BASE_8_INT;
				}
				else {
					return tokenList->next;
				}
				break;
			case ID:
				id_length = file_content - pStartCharacter;
				if (id_length == 5 && !memcmp(pStartCharacter, "break", id_length)) {
					added = addToken(tokenList, &token, BREAK, line);
				}
				else if (id_length == 4 && !memcmp(pStartCharacter, "char", id_length)) {
					added = addToken(tokenList, &token, CHAR, line);
				}
				else if (id_length == 6 && !memcmp(pStartCharacter, "double", id_length)) {
					added = addToken(tokenList, &token, DOUBLE, line);
				}
				else if (id_length == 4 && !memcmp(pStartCharacter, "else", id_length)) {
					added = addToken(tokenList, &token, ELSE, line);
				}
				else if (id_length == 3 && !memcmp(pStartCharacter, "for", id_length)) {
					added = addToken(tokenList, &token, FOR, line);
				}
				else if (id_length == 2 && !memcmp(pStartCharacter, "if", id_length)) {
					added = addToken(tokenList, &token, IF, line);
				}
				else if (id_length == 3 && !memcmp(pStartCharacter, "int", id_length)) {
					added = addToken(tokenList, &token, INT, line);
				}
				else if (id_length == 6 && !memcmp(pStartCharacter, "return", id_length)) {
					added = addToken(tokenList, &token, RETURN, line);
				}
				else if (id_length == 6 && !memcmp(pStartCharacter, "struct", id_length)) {
					added = addToken(tokenList, &token, STRUCT, line);
				}
				else if (id_length == 4 && !memcmp(pStartCharacter, "void", id_length)) {
					added = addToken(tokenList, &token, VOID, line);
				}
				else if (id_length == 5 && !memcmp(pStartCharacter, "while", id_length)) {
					added = addToken(tokenList, &token, WHILE, line);
				}
				else if (!isalnum(character) && character != '_') {
					added = addToken(tokenList, &token, ID, line);
					token->string = calloc(id_length + 1, sizeof(char));
					memcpy(token->string, pStartCharacter, id_length);
					break;
				}
				if (added == 1)
					break;
				file_content++;
				break;
			case COMMA:
				added = addToken(tokenList, &token, COMMA, line);
				break;
			case SEMICOLON:
				added = addToken(tokenList, &token, SEMICOLON, line);
				break;
			case LPAR:
				added = addToken(tokenList, &token, LPAR, line);
				break;
			case RPAR:
				added = addToken(tokenList, &token, RPAR, line);
				break;
			case LBRACKET:
				added = addToken(tokenList, &token, LBRACKET, line);
				break;
			case RBRACKET:
				added = addToken(tokenList, &token, RBRACKET, line);
				break;
			case LACC:
				added = addToken(tokenList, &token, LACC, line);
				break;
			case RACC:
				added = addToken(tokenList, &token, RACC, line);
				break;
			case ADD:
				added = addToken(tokenList, &token, ADD, line);
				break;
			case SUB:
				added = addToken(tokenList, &token, SUB, line);
				break;
			case MULT:
				added = addToken(tokenList, &token, MULT, line);
				break;
			case END:
				added = addToken(tokenList, &token, END, line);
				break;
			case DOT:
				added = addToken(tokenList, &token, DOT, line);
				break;
			case DIV:
				added = addToken(tokenList, &token, DIV, line);
				break;
			case AND:
				if (character == '&') {
					file_content++;
					added = addToken(tokenList, &token, AND, line);
				}
				else
					return tokenList->next;
					break;
			case OR:
				if (character == '|') {
					file_content++;
					added = addToken(tokenList, &token, OR, line);

				}
				else
					return tokenList->next;
					break;
			case NOT:
				if (character == '=') {
					file_content++;
					added = addToken(tokenList, &token, NOTEQ, line);
				}
				else
					added = addToken(tokenList, &token, NOT, line);
				break;
			case EQUAL:
				if (character == '=') {
					file_content++;
					added = addToken(tokenList, &token, EQUAL, line);
				}
				else
					added = addToken(tokenList, &token, ASSIGN, line);
				break;
			case LESS:
				if (character == '=') {
					file_content++;
					added = addToken(tokenList, &token, LESSEQ, line);
				}
				else
					added = addToken(tokenList, &token, LESS, line);
				break;
			case GREATER:
				if (character == '=') {
					file_content++;
					added = addToken(tokenList, &token, GREATEREQ, line);
				}
				else
					added = addToken(tokenList, &token, GREATER, line);
				break;
			case CHAR_STATE_0:
				if (character == '\\')
					state = ESCAPE_CHARS;
				else
					state = CHAR_STATE_2;
				file_content++;
				break;
			case ESCAPE_CHARS:
				prevCharacter = escapeChar(character);
				state = CHAR_STATE_2;
				file_content++;
				break;
			case CHAR_STATE_1:
				
				break;

			case CHAR_STATE_2:
				if (character == '\'') {
					state = CT_CHAR;
				}
				else {
					return tokenList->next;
				}

				break;
			case CT_CHAR:
				added = addToken(tokenList, &token, CT_CHAR, line);
				if (prevCharacter == 255)
					memcpy(&token->integer, pStartCharacter, 1);
				else
					memcpy(&token->integer, &prevCharacter, 1);
				file_content++;
					break;
			case STRING_STATE_0:
				if (character == '\\') {
					*file_content = 7;
					state = ESCAPE_STRING;
				}
				else 
					state = STRING_STATE_2;
				file_content++;
				break;
			case ESCAPE_STRING:
				*file_content = escapeChar(character);
				state = STRING_STATE_2;
				file_content++;
				break;
			case STRING_STATE_2:
				if (character == '"') {
					state = CT_STRING;
				}
				else
					state = STRING_STATE_0;
				break;
			case CT_STRING:
				id_length = file_content - pStartCharacter;
				added = addToken(tokenList, &token, CT_STRING, line);
				token->string = calloc(id_length + 1, sizeof(unsigned char));
				memcpy(token->string, pStartCharacter, id_length);
				file_content++;
				break;
				

			case BASE_10_INT:
				if (character == '.')
					state = REAL_STATE_0;
				else if (character == 'e' || character == 'E')
					state = REAL_STATE_2;
				else if (!isdigit(character)) {
					number_base = 10;
					state = CT_INT;
				}
				file_content++;
				break;
			case BASE_8_INT:
				if (character == 'x' || character == 'X') {
					file_content++;

					state = BASE_16_INT;
					break;
				}
				else if (character == '.') {
					state = REAL_STATE_0;
					file_content++;
				}
				else if (character == 'e' || character == 'E') {
					file_content++;
					state = REAL_STATE_2;
				}
				else if (character >= '0' && character <= '9') {// octal values 0-7
					file_content++;
				}
				else {
					number_base = 8;
					state = CT_INT;
				}
				break;
			case BASE_16_INT:
				if ((character >= '0' && character <= '9') ||
					(character >= 'A' && character <= 'F') ||
					(character >= 'a' && character <= 'f')) {

					file_content++;
				}
				else {
					number_base = 16;
					state = CT_INT;
				}
				break;
			case CT_INT:
				added = addToken(tokenList, &token, CT_INT, line);
				token->integer = strtol(pStartCharacter, NULL, number_base);
				break;
			case REAL_STATE_0:
				if (isdigit(character))
					state = REAL_STATE_1;
				else
					return tokenList->next;
				file_content++;
				break;
			case REAL_STATE_1:
				if (character == 'e' || character == 'E')
					state = REAL_STATE_2;
				else if (!isdigit(character)) {
					state = CT_REAL;
					break;
				}
				else
					return tokenList->next;

				file_content++;
				break;
			case REAL_STATE_2:
				if (character == '+' || character == '-') {
					state = REAL_STATE_3;
					file_content++;
				}
				else
					state = REAL_STATE_3;
				break;
			case REAL_STATE_3:
				while (isdigit(character)) {
					file_content++;
					character = *file_content;
				}
				state = CT_REAL;
				break;
			case CT_REAL:
				added = addToken(tokenList, &token, CT_REAL, line);
				token->real = strtod(pStartCharacter, NULL);
				break;
			case LINECOMMENT_STATE_1:
				if (character == '/')
					state = LINECOMMENT;
				else
					state = DIV_COMMENT;
				break;
			case LINECOMMENT:
				while (1) {
					if (character == '\r' || character == '\n' ||
						character == '\t' || character == '\0')
						break;
					file_content++;
					character = *file_content;
				}
				state = START;
				break;
			case DIV_COMMENT:
				if (character == '*') {
					state = COMMENT_STATE_1;
					file_content++;

				}
				else {
					state = DIV;
				}
				break;
			case COMMENT_STATE_1:
				if (character == '*') {
					state = COMMENT_STATE_2;
				}
				else if (character == '\n')
					line++;
				file_content++;
				break;
			case COMMENT_STATE_2:					
				if (character == '/')
					state = START;
				file_content++;
				break;
				
			}//switch

			if (added == 1)
				break;

		}//while loop

	}
	return tokenList->next;
}// function
