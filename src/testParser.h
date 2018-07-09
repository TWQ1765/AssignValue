#ifndef _TESTPARSER_H
#define _TESTPARSER_H
#include	<stdio.h>
#include	<stdarg.h>
#include	<malloc.h>
#include	<stdlib.h>

typedef struct VariableMapping VariableMapping;
struct VariableMapping {
	char *name;
	int *storage;	
};



/**
 * Parse and compare string number to value.
 * It igonres all spaces.
 * it return zero, otherwise zero value.
 */
int parseCompare(char **linePtr, char *cmpStr);
/**
 * Parse and convert the 1st string number to value.
 * It igonres all spaces.
 * The value is returned if the number is ok.
 * converted. If there is no number, ERR_NOT_A_NUMBER
 * is thrown.
 */
int parseAndConvertToNum(char **linePtr);
int parseTextAndAssignValues();

//try
int tryOnlyreturnTrue();
#endif // _TESTPARSER_H
