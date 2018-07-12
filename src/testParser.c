#include "testParser.h"
/**
 * Parse and compare string number to value.
 * It igonres all spaces.
 * it return zero, otherwise zero value.
 */
int parseCompare(char **linePtr, char *cmpStr){
	int i = 0;
	int indexCount=0;
	if (((*linePtr == NULL) ||  (cmpStr == NULL))){
		return 0;
	}
	else{
		char * strTemp = (char *)malloc(strlen(*linePtr));
		strcpy(strTemp,*linePtr);
		
		//printf("strTemp =%sXXX, *linePtr=%s\n",strTemp,*linePtr);
		while ((strTemp[i] == cmpStr[i]) && ((strTemp[i] != ' ')|| (cmpStr[i]!= ' ')))
		{
			if((strTemp[i] == cmpStr[i])|| (strTemp[i] == ' ')|| (cmpStr[i]== ' '))
		    {	
				//printf("lineptr =%c\n",strTemp[0] );
				i++;
				indexCount++;
				//*linePtr++;
			}			
		}
		printf("lineptr =%c\n",strTemp[indexCount] );
		//while((strTemp[indexCount] ==' ') && (strTemp[indexCount]!= '\0')){
		//	indexCount=indexCount+1;
		//}
		*linePtr = *linePtr + (indexCount);//(strlen(*linePtr));//indexCount;
		printf("strTemplen =%d, indexCount=%d\n",strlen(strTemp) ,indexCount);
		
		if((strlen(strTemp-1)) == indexCount){
			return 1;
		}
		else{
			return 0;
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


int tryOnlyreturnTrue(){
	
	return 1;
}

int parseTextAndAssignValues(char *line, VariableMapping *varTableMapping) {
  return 0;
}