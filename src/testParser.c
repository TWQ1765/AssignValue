#include "testParser.h"
/**
 * Parse and compare string number to value.
 * It igonres all spaces.
 * it return zero, otherwise zero value.
 * if result return 1 the pointer stop at the last char
 * and ignore spaces behind.
 * else result return 0 the pointer back to 1st char
 * function needed:
 *	-int skipSpace(char** linePtr);
 *	
 */
int parseCompare(char **linePtr, char *cmpStr){
	int i = 0,j=0;
	int indexCount=0;
	int temp1=0,temp2=0,temp3=0,tempResult=0;//return value for func skipSpace()
	if (((*linePtr == NULL) ||  (cmpStr == NULL))){
		return 0;
	}
	else{
		char *strTemp = (char *)malloc(strlen(*linePtr));
		strcpy(strTemp,*linePtr);
		temp1=skipSpace(&strTemp);
		temp2=skipSpace(linePtr);//skip space and move pionter.
		temp3=skipSpace(&cmpStr);
		while ((strTemp[i] == cmpStr[i])&&(strTemp[i] != ' ')&&(cmpStr[i] != ' ')){
			if((strTemp[i] == cmpStr[i])){	
				indexCount++;
			}i++;			
		}
		while(strTemp[i+j] == ' '){//make test pass(space trailing)
			j++;
		}
		if(j==0){
			j=0;
		}
		else{
			j=j+1;	
		}
		if (((strlen(strTemp)-j) == (indexCount-1))){
			tempResult = temp3 - temp1;
			tempResult = pow(tempResult,2);
			tempResult = sqrt(tempResult);//for only +ve value
			///printf("tempResult =%d\n",tempResult);
			if(temp1==temp3){
				*linePtr = *linePtr + ((indexCount-temp1));
			}
			else{
				*linePtr = *linePtr + ((indexCount-1-tempResult));
			}
			//free(strTemp);
			return 1;
		}
		else{
			*linePtr = *linePtr-temp1;
			//free(strTemp);
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
	int i = 0,j = 0,k =0; 
	int calResult = 0;
	int convertValue = 0;
	int numOfSpaceTrailing=0;
	int temp = skipSpace(linePtr);//skip Space
	char * strTemp = (char *)malloc(strlen(*linePtr));
	char * addressValue = (char *)malloc(strlen(*linePtr));
	strcpy(strTemp,*linePtr);
	while((strTemp[i] != '\0')){
		addressValue[i] = (strTemp[i]-48);
		//printf("addressValue2=%d\n",addressValue[i]);
		if((strTemp[i] == ' ')){
			numOfSpaceTrailing++;
		}else{
			numOfSpaceTrailing=numOfSpaceTrailing;
		}i++;
	}
	i=i-1-numOfSpaceTrailing;
	//printf("numOfSpaceTrailing=%d\n",numOfSpaceTrailing);
	while((i) >= 0){
		calResult = (addressValue[j]*(pow(10,i)));
		convertValue = convertValue + calResult;
		i--;
		j++;
	}
	//printf("convertValue=%d\n",convertValue);
	//printf("i=%d\n",i);
	free(addressValue);
	//free(strTemp);
	return convertValue;
}
//useless function waiting and readly for delete
int tryOnlyreturnTrue(){
	return 1;
}
char *getStringUntilSpace(char *line){
	int i = 0, j =0;
	char *getString;
	int spaces = skipSpace(&line);//skip space here...
	//printf("spaces = %d\n",spaces);
	while(line[i] != ' '){
		//printf("line[i]= %c\n",line[i]);
		i++;
	}
	i=i-1;//get string length i
	getString = (char *)malloc(i);
	while(line[j] != ' '){
		getString[j] = line[j];
		j++;
	}
	getString[j] = '\0';//end string...
	//printf("getString = %s\n",getString);
	return getString;
}
//useless function waiting and readly for delete
/*
char *getStringName(char **linePtr){
	char * strTemp = (char *)malloc(strlen(*linePtr));
	strcpy(strTemp,*linePtr);
	return strTemp;
}*/
int parseTextAndAssignValues(char *line, VariableMapping *varTableMapping) {
	
	char * errorMsg;
	int compareResult = 0 ;
	int convertedResult = 0;
	compareResult = parseCompare(&line, "assign");
	printf("compareResult= %d\n",compareResult);
	if (compareResult == 0){
		convertedResult = parseAndConvertToNum(&line);
	}else{
		convertedResult = 0;
	}
	printf("convertedResult= %d\n",convertedResult);
	
	return compareResult;
}

/*
 *this function only skip space which is ' ' in front text. 
 * pionter are move until the 1st char are pionted.
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
	//free(strTemp);
	return count;
}
