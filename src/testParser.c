#include "testParser.h"
/**
 * Parse and compare string number to value.
 * It igonres all spaces.
 * it return zero, otherwise zero value.
 * function needed:
 *	-int skipSpace(char** linePtr);
 */
int parseCompare(char **linePtr, char *cmpStr){
	int i = 0,j=0;
	int indexCount=0;
	int temp1=0,temp2=0,temp3=0,tempResult=0;//return value for func skipSpace()
	int temp4=0,temp5=0,temp6=0;//return value for func skipSpace()
	if (((*linePtr == NULL) ||  (cmpStr == NULL))){
		return 0;
	}
	else{
		char * strTemp = (char *)malloc(strlen(*linePtr));
		strcpy(strTemp,*linePtr);
		///printf("strTemp =%s, *linePtr=%s\n",strTemp,*linePtr);//before skip space
		temp1=skipSpace(&strTemp);
		temp2=skipSpace(linePtr);//skip space and move pionter.
		temp3=skipSpace(&cmpStr);
		///printf("strTemp =%s, *linePtr=%s\n",strTemp,*linePtr);//after skip space
		///printf("cmpStr =%s\n",cmpStr);
		//printf("lineptrr =%c\n",strTemp[6] );
		//printf("i =%d,j=%d\n",i,j);
		//printf("lineptr =%c\n",strTemp[2] );
		//printf("temp1 =%d,temp2=%d,temp3=%d\n",temp1,temp2,temp3);
		while ((strTemp[i] == cmpStr[i])) 
		{
			if((strTemp[i] == cmpStr[i]))
			{	
				//printf("lineptr =%c\n",strTemp[i] );
				indexCount++;
			}i++;			
		}
		temp4=skipSpace(&strTemp);
		temp5=skipSpace(linePtr);
		temp6=skipSpace(&cmpStr);
		//printf("i =%d,indexCount=%d\n",i,indexCount);
		//printf("tempResult =%d\n",tempResult);
		//printf("strTemplen =%d, (indexCount-1-temp1)=%d\n",strlen(strTemp) ,((indexCount-1-temp1)));
		if ((strlen(strTemp) == (indexCount-1))){//|| ((strlen(strTemp) == (indexCount)))){
			if(temp1==temp3){
			*linePtr = *linePtr + ((indexCount-temp1));
			}
			else{
			tempResult = temp3 - temp1;
			tempResult = pow(tempResult,2);
			tempResult = sqrt(tempResult);//for only +ve value
			*linePtr = *linePtr + ((indexCount-1-tempResult));
			}
			
		return 1;
		}
		else{
			*linePtr = *linePtr + indexCount;
			
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
/*
 *this function only skip space which is ' ' in front text
 */
int skipSpace(char** linePtr){
	int count = 0;
	int i=0;
	
	char * strTemp = (char *)malloc(strlen(*linePtr));
	strcpy(strTemp,*linePtr);
	
	//printf("strTemp=%c\n",strTemp[1]);
		while(strTemp[i] == ' '){
		i++;
		count++;
		}
	//printf("count=%d\n",count);
	*linePtr=*linePtr+count;
	free(strTemp);
	return count;
}
void skipSpacebehind(char** linePtr){
	int i = 0 ;
	int linePtrLen = strlen(*linePtr);
	int stringLen=0 ;
	char * strTemp = (char *)malloc(linePtrLen);
	strcpy(strTemp,*linePtr);
	while(strTemp[i] != ' '){
	i++;
	}
	
	printf("strTemp[i]=%c\n",strTemp[3]);
	printf("i=%d\n",i);
	
	stringLen = linePtrLen - i;
	printf("linePtr[stringLen]=%c\n",linePtr[stringLen]);
	printf("stringLen=%d\n",stringLen);
	linePtr[stringLen] = '\0'; 
	free(strTemp);
		 
}