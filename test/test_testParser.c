#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>
#include "unity.h"
#include "Error.h"
#include "testParser.h"
#include "Exception.h"
#include "CException.h"

//#include "CExceptionConfig.h"

void setUp(void)
{
}

void tearDown(void)
{
}
//*test function skipSpace pass
void test_skipSpace_given_spaceABD_expect_return_ture(void)
{
	char *line = " ABC";
	char *originalLine = line;
	int i = skipSpace(&line);
	TEST_ASSERT_EQUAL_PTR(originalLine + 1, line);
}
void test_skipSpace_given_doubleSpaceABD_expect_return_ture(void)
{
	char *line = "  ABC";
	char *originalLine = line;
	int i = skipSpace(&line);
	TEST_ASSERT_EQUAL_PTR(originalLine + 2, line);
}
void test_skipSpace_given_tribleSpaceABD_expect_return_ture(void)
{
	char *line = "   ABC";
	char *originalLine = line;
	int i = skipSpace(&line);
	
	TEST_ASSERT_EQUAL_PTR(originalLine + 3, line);
}
//*/

//*test function parseAndCompare pass
void test_parseAndCompare_given_assign_with_extra_trailing_space_in_front_should_return_true(void)
{
	char *line = " assign";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}
void test_parseAndCompare_given_assign_with_extra_two_trailing_space_should_return_true(void)
{
	char *line = "assign  ";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}
void test_parseAndCompare_given_assign_with_an_extra_trailing_space_should_return_true(void)
{
	char *line = "assign ";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}
void test_parseAndCompare_given_HeLLo_and_Hello_expect_return_Flase(void)
{
	char *line = "HeLLo";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine , line );
}

void test_parseAndCompare_given_NULL_and_Hello_expect_return_Flase(void)
{
	char *line = NULL;
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine  , line );
}

void test_parseAndCompare_given_2spaceHello_and_2spaceHello_expect_return_ture(void)
{
	char *line = "  Hello";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "  Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine+6  , line );
}
void test_parseAndCompare_given_2space_and_Hello_expect_return_flase(void)
{
	char *line = "  H";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine , line );
}
void test_parseAndCompare_given_ass_space__ign_and_assign_expect_return_flase(void)
{
	char *line = "ass ign";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine, line );
}
//*/

//*test_parseAndConvertToNum pass
void test_parseAndConvertToNum_given_char_589_compare_with_int_589_expect_true(void) {
	char *line = "589";
    int convertValue = parseAndConvertToNum(&line);
	
	TEST_ASSERT_EQUAL_INT(convertValue,589);
}
void test_parseAndConvertToNum_given_char_2_space_589_compare_with_int_589_expect_true(void) {
	char *line = "  589";
    int convertValue = parseAndConvertToNum(&line);
	
	TEST_ASSERT_EQUAL_INT(convertValue,589);
}
//*/
/*
void xtest_parseAndConvertToNum_given_char_2_trailing_space_589_compare_with_int_589_expect_true(void) {
	char *line = "589  ";
    int convertValue = parseAndConvertToNum(&line);
	
	TEST_ASSERT_EQUAL_INT(convertValue,589);
}
*/

/*
void test_parseTextAndAssignValues_given_no_table_mapping_should_throw_ERR_TABLE_IS_MISSING(void) {
  CEXCEPTION_T e;
  char *line = " assign mango = 589 ";

  Try {
    parseTextAndAssignValues(line, NULL);
    TEST_FAIL_MESSAGE("Expect ERR_TABLE_IS_MISSING. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}*/
void test_Try_something_about_EXCEPTION(void) {
  CEXCEPTION_T e;
  int try = 1;
	if(tryOnlyreturnTrue()==0){
	Try {
		TEST_FAIL_MESSAGE("Expect someting happen");
	} Catch(e) {
		printf(e->errorMsg);
		freeError(e);
	}
	}
	else{
		TEST_ASSERT_EQUAL_INT(try,tryOnlyreturnTrue());
	}
}

void test_parseTextAndAssignValues_given_no_command_should_do_nothing(void) {
  CEXCEPTION_T e;
  int tomato = 0;
  VariableMapping varTableMapping[] = {
    {"tomato", &tomato},
    {NULL, NULL},
  };
  char *line = NULL;
/*
  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_ASSERT_EQUAL(0,tomato);
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
  */
}

void test_parseTextAndAssignValues_just_test(void) {
  int tomato = 0;
  VariableMapping varTableMapping[] = {
    {"tomato", &tomato},
    {NULL, NULL},
  };
  char *line = "  assign  1";
  char *line2 =  getStringUntilSpace(line);
    int result = parseTextAndAssignValues(line2, varTableMapping);
	printf("line= %s\n",line+5);
    TEST_ASSERT_TRUE(result);
 
}
void test_getStringUntilSpace_just_test(void) {
	
	char *line = "  assign  1";
	char * getString = getStringUntilSpace(line);
	TEST_ASSERT_EQUAL_STRING(getString,"assign");
}


/*
void test_parseTextAndAssignValues_given_input_command_is_NULL_should_do_nothing(void) {
  CEXCEPTION_T e;
  int kiwi = 0;
  VariableMapping varTableMapping[] = {
    {"kiwi", &kiwi},
    {NULL, NULL},
  };
  char *line = "  ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    // Should reach here because no command given
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

// assign orange  = 21346 apple = 1 lemon=10
void test_parseTextAndAssignValues_given_orange_21346_apple_1_lemon_10_should_assigned_correctly(void) {
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"apple", &apple},
    {"orange", &orange},
    {"lemon", &lemon},
    {NULL, NULL},
  };
  char *line = "assign orange  = 21346 apple = 1 lemon=10";

  Try {
    parseTextAndAssignValues(line, varTableMapping);

    TEST_ASSERT_EQUAL(21346, orange);
    TEST_ASSERT_EQUAL(1, apple);
    TEST_ASSERT_EQUAL(10, lemon);
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_melon_and_value_with_trailing_spaces_should_parse_properly(void) {
  CEXCEPTION_T e;
  int melon = 0;
  VariableMapping varTableMapping[] = {
    {"melon  ", &melon},
    {NULL, NULL},
  };
  char *line = "assign melon = 89   ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_ASSERT_EQUAL(89, melon);
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_text_without_assign_should_throw_ERR_UNKNOWN_COMMAND(void) {
  CEXCEPTION_T e;
  int papaya = 0;
  VariableMapping varTableMapping[] = {
    {"papaya", &papaya},
    {NULL, NULL},
  };
  char *line = "  papaya = 345 ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN_FOUND. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN_FOUND, e->errorCode);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_guava_23_cucumber_92_should_throw_ERR_UNKNOWN_VARIABLE(void) {
  CEXCEPTION_T e;
  int guava = 0;
  VariableMapping varTableMapping[] = {
    {"guava", &guava},
    {NULL, NULL},
  };
  char *line = "assign guava=23 cucumber=92";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_VARIABLE_NOT_FOUND. But no exception thrown.");
  } Catch(e) {
    TEST_ASSERT_EQUAL(23, guava);
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND, e->errorCode);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_malform_pineapple_without_equal_sign_should_throw_ERR_MALFORM_ASSIGN(void) {
  CEXCEPTION_T e;
  int pineapple = 0;
  VariableMapping varTableMapping[] = {
    {"pineapple", &pineapple},
    {NULL, NULL},
  };
  char *line = "assign pineapple 23 ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN_FOUND. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN_FOUND, e->errorCode);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_malform_ciku_without_number_should_throw_ERR_NOT_A_NUMBER(void) {
  CEXCEPTION_T e;
  int ciku = 0;
  VariableMapping varTableMapping[] = {
    {"ciku", &ciku},
    {NULL, NULL},
  };
  char *line = "assign ciku =  durian = 6";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_NOT_A_NUMBER. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NOT_A_NUMBER, e->errorCode);
    freeError(e);
  }
}
*/