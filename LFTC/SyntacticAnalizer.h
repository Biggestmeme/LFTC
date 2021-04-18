#pragma once
#ifndef SYNTACTIC_ANALIZER_H_
#define SYNTACTIC_ANALIZER_H_
#include <stdbool.h>
#include "LexicalAnalizer.h"

Token* consumeToken(Token** currentToken, int code);
void analizeTokens(Token** tokens);
bool declareTypeBase(Token** currentToken);
#endif