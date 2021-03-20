#pragma once
#ifndef AUXILIARY_H_
#define AUXILIARY_H_

#include <stdlib.h>

#define SAFEALLOC(var,Type,size) if((var=(Type*)malloc(sizeof(Type) * size))==NULL)Error("not enough memory");

void Error(const char* error);
void advanceArrayPointer(unsigned char** string);


#endif