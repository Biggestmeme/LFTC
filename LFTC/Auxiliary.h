#pragma once
#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include "LexicalAnalizer.h"

#define TokenError(arg1, ...) do {            \
   int _x[] = { __VA_ARGS__ };   \
   _TokenError(arg1,sizeof(_x)/sizeof(_x[0]), _x); \
} while(0)

void _TokenError(Token * token, int num_of_args, int args[]);
#endif