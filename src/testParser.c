#include "testParser.h"
/**
 * Parse and compare string number to value.
 * It igonres all spaces.
 * it return zero, otherwise zero value.
 */
int parseCompare(char **linePtr, char *cmpStr){
	int i = 0;
	int indexCount=0;//do nothing
	if (((*linePtr == NULL) ||  (cmpStr == NULL))){
		
		return 0;
	}
	else{
		while((*linePtr[i] != '\0') || (cmpStr[i] != '\0'))
		{
			if ((**linePtr == cmpStr[i]))//|| (*linePtr == ' ')
			{
				i++;
				indexCount++;//do nothing
				*linePtr++;
			}
			else
			{
				//*linePtr = *linePtr + indexCount;//(strlen(*linePtr));//indexCount;
				return 1;
			}
		}
	}
}
/**
 * Parse and convert the 1st string number to value.
 * It igonres all spaces.
 * The value is returned if the number is ok.
 * converted. If there is no number, ERR_NOT_A_NUMBER
 * is thrown.
 */
int parseAndConvertToNum(char **linePtr){
	return 0;
}

int parseTextAndAssignValues(){
	
}
int tryOnlyreturnTrue(){
	
	return 1;
}