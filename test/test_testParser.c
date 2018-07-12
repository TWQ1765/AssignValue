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
/*pass
void test_testParser_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement testParser");
}
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
*/

void test_parseAndCompare_given_assign_with_extra_trailing_space_in_front_should_return_true(void)
{
	char *line = "  assign";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}

///*
void test_parseAndCompare_given_assign_with_extra_trailing_space_should_return_true(void)
{
	char *line = "assign  ";
	char *originalLine = line;
	
	TEST_ASSERT_TRUE(parseCompare(&line, "assign"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 6, line );

	TEST_ASSERT_TRUE(tryOnlyreturnTrue());
}
//*/

void xtest_parseAndCompare_given_HeLLo_and_Hello_expect_return_Flase(void)
{
	char *line = "HeLLo";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 2 , line );
}

void xtest_parseAndCompare_given_NULL_and_Hello_expect_return_Flase(void)
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
	TEST_ASSERT_EQUAL_PTR(originalLine +3, line );
}
void test_parseAndCompare_given_2spaceHallo_and_2spaceHello_expect_return_flase(void)
{
	char *line = "  Hallo";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "  Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 3, line );
}
void test_parseAndCompare_given_2spaceHeLlo_and_2spaceHello_expect_return_flase(void)
{
	char *line = "  HeLlo";
	char *originalLine = line;
	
	TEST_ASSERT_FALSE(parseCompare(&line, "  Hello"));
	TEST_ASSERT_EQUAL_PTR(originalLine + 4, line );
}
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
}

void test_parseTextAndAssignValues_given_no_command_should_do_nothing(void) {
  CEXCEPTION_T e;
  int tomato = 0;
  VariableMapping varTableMapping[] = {
    {"tomato", &tomato},
    {NULL, NULL},
  };
  char *line = NULL;

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    // Should reach here because no command given
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

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
    TEST_FAIL_MESSAGE("Expect ERR_UNKNOWN_COMMAND. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_UNKNOWN_COMMAND, e->errorCode);
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
    TEST_FAIL_MESSAGE("Expect ERR_UNKNOWN_VARIABLE. But no exception thrown.");
  } Catch(e) {
    TEST_ASSERT_EQUAL(23, guava);
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_UNKNOWN_VARIABLE, e->errorCode);
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
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN, e->errorCode);
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
}*/