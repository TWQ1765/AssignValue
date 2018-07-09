#include "unity.h"
#include "testParser.h"
#include "Error.h"
#include "Exception.h"
#include "CExceptionConfig.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_testParser_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement testParser");
}

void test_parseAndCompare_given_assign_with_extra_trailing_space_should_return_true(void)
{
	char *line = "assign ";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}
void test_parseAndCompare_given_HeLLo_and_hello_expect_return_Flase(void)
{
	char *line = "HeLLo";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 5 , line );
}
/*

//assign orange  = 21346 apple = 1 lemon=10
void xtest_testParser_given_orange_21346_apple_1_lemon_10_should_assigned_correctly(void)
{
	int orange = 0, apple = 0, lemon = 0;
	VariableMapping variableMapping[] = {
		{"apple", &apple},
		{"orange", &apple},
		{"lemon", &apple},
		{NULL,NULL},
	};
	
	char *line = "assign orange  = 21346 apple = 1 lemon=10"
	
	parseTextAndAssignValues(&line, variableMapping);
	
    TEST_ASSERT_EQUAL(21346,orange);
	TEST_ASSERT_EQUAL(1,apple);
	TEST_ASSERT_EQUAL(10,lemon);
	
}*/
/*
void xtest_testParser_given_malform_guava_apple_1_lemon_10_should_assigned_correctly(void)
{
	CEXCEPTION_T = e;
	int guava = 0;
	VariableMapping variableMapping[] = {
		{"guava", &guava},
		{NULL,NULL},
	};
	
	char *line = "assign guava=23 cucumber=92"
	Try{
	parseTextAndAssignValues(line, variableMapping);
	TEST_FAIL_MESSAGE("Expect ERR_VARIABLE_NOT_FOUND. But not exception thrown.");
	
    
	}Catch(e){
	TEST_ASSERT_EQUAL(23,guava);
	printf(e->errorMsg);
	TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND,e->errorCode);
		
	}
}
void xtest_testParser_given_malform_pineapple_without_equal_sign_should_thrown_ERR_VARIABLE_NOT_FOUND(void)
{
	CEXCEPTION_T = e;
	int pineapple = 0;
	VariableMapping variableMapping[] = {
		{"pineapple", &pineapple},
		{NULL,NULL},
	};
	
	char *line = "assign pineapple 23"
	Try{
	parseTextAndAssignValues(line, variableMapping);
	TEST_FAIL_MESSAGE("Expect ERR_VARIABLE_NOT_FOUND. But not exception thrown.");
	
    
	}Catch(e){
	TEST_ASSERT_EQUAL(23,pineapple);
	printf(e->errorMsg);
	TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND,e->errorCode);
		
	}
}
void xtest_testParser_given_ciku_without_Number_should_thrown_ERR_VARIABLE_NOT_FOUND(void)
{
	CEXCEPTION_T = e;
	int ciku = 0;
	VariableMapping variableMapping[] = {
		{"ciku", &ciku},
		{NULL,NULL},
	};
	
	char *line = "assign ciku ="
	Try{
	parseTextAndAssignValues(line, variableMapping);
	TEST_FAIL_MESSAGE("Expect ERR_VARIABLE_NOT_FOUND. But not exception thrown.");
	
    
	}Catch(e){
	TEST_ASSERT_EQUAL(23,ciku);
	printf(e->errorMsg);
	TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND,e->errorCode);
		
	}
}
void xtest_testParser_given_text_without_assign_should_thrown_ERR_VARIABLE_NOT_FOUND(void)
{
	CEXCEPTION_T = e;
	int papaya = 0;
	VariableMapping variableMapping[] = {
		{"papaya", &papaya},
		{NULL,NULL},
	};
	
	char *line = "papaya =345"
	Try{
	parseTextAndAssignValues(line, variableMapping);
	TEST_FAIL_MESSAGE("Expect ERR_MALFORM_TEXT_FOUND. But not exception thrown.");
	
    
	}Catch(e){
	TEST_ASSERT_EQUAL(23,papaya);
	printf(e->errorMsg);
	TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND,e->errorCode);
		
	}
}*/