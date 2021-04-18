#include <stdlib.h>
#include "Auxiliary.h"
#include <stdbool.h>
#include <stdio.h>
void analizeTokens(Token** tokens) {
	//bool idk = checkTypeBase(tokens);
	//printf("%d", idk);

}


Token* consumeToken(Token** currentToken, int code) {
	Token* consumedToken = *currentToken;
	if (consumedToken->code == code) {
		*currentToken = (*currentToken)->next;
		return consumedToken;
	}
	return NULL;
}


bool declareStruct(Token** currentToken) {
	Token* startingToken = *currentToken;
	if (consumeToken(currentToken, STRUCT) != NULL) {
		if (consumeToken(currentToken, ID) != NULL) {
			if (consumeToken(currentToken, LACC) != NULL) {
				//if(consumeToken(currentToken, ))
			}
		}
	}
}



//typeBase: INT | DOUBLE | CHAR | STRUCT ID;
bool declareTypeBase(Token** currentToken) {
	Token* startingToken = *currentToken;
	if (consumeToken(currentToken, INT) != NULL ||
		consumeToken(currentToken, DOUBLE) != NULL ||
		consumeToken(currentToken, CHAR) != NULL) {
		
		return true;
	}
	else if (consumeToken(currentToken, STRUCT) != NULL) {
		if (consumeToken(currentToken, ID) != NULL) {
		
			return true;
		}
	}
	
	TokenError(*currentToken,INT,DOUBLE,CHAR,STRUCT,ID);
	*currentToken = startingToken;
	return false;
}


bool expression(Token** currentToken) {

}


/*
exprPrimary: ID ( LPAR ( expr ( COMMA expr )* )? RPAR )?
		   | CT_INT
		   | CT_REAL
		   | CT_CHAR
		   | CT_STRING
		   | LPAR expr RPAR ;

*/

bool expressionPrimary(Token** currentToken) {
	Token* startingToken = *currentToken;
	if (consumeToken(currentToken, ID) != NULL) {
		if (consumeToken(currentToken, LPAR) != NULL) {
			expression(currentToken);
			while(consumeToken(currentToken, COMMA) != NULL) {
				expression(currentToken);
			}
			if (consumeToken(currentToken, RPAR) == NULL){
				TokenError(currentToken, RPAR);
				*currentToken = startingToken;
				return false;
			}
		}
		else 
			return true;
	}

	TokenError(currentToken, ID,LPAR,COMMA);
	*currentToken = startingToken;
	return false;
}

/*
exprPostfix: exprPostfix LBRACKET expr RBRACKET
		   | exprPostfix DOT ID
		   | exprPrimary ;
*/

bool expressionPostfix(Token** currentToken) {

}