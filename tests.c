
/******************************************************************
 *  File: tests.c
 *  Project: Impossible Triangle                                  *
 *  Author: Lucas Wagner                                          *
 *  Purpose: Testing Functions in CUnit 
 *  FOR DEMONSTRATION USE ONLY                                    *
 *  COPYRIGHT (c)2017, Lucas C. Wagner. All Rights Reserved.      *
 ******************************************************************/

#include "CUnit/Basic.h"
#include "common.h"
#include "pos.h"
#include "board.h"
#include "jump.h"

int init_suite(void)
{
	initializeBoard(1);

	/* Testing Board Setup:
	 *
	 *        1
	 *      1   1
	 *    1   1   c
	 *  1   1   0   1
	 *
	 *  c = curPos (which equals 1)
	 *  0 = empty
	 */

	Coord temp={2,2};
	setCurPos(&temp);

	Coord temp2 = {3,2};
	setState(&temp2,0);

	return 0;
}

int clean_suite(void)
{
	return 0;
}

/* board.c */

void testINITIALIZEBOARD(void){
	CU_ASSERT(10 == initializeBoard(1));
}

void testCHECKSTATE(void){
	Coord temp={2,2};
	CU_ASSERT(1 == checkState(&temp));
}

void testSETSTATE(void){
	Coord temp={0,0};
	setState(&temp, 0);
	CU_ASSERT(0 == checkState(&temp));
}

void testCHECKBOARDFORWIN(void){
	/* re=initialize board, leaving only a single 1 */
	initializeBoard(0);
	Coord temp={0,0};
	setState(&temp, 1);
	CU_ASSERT(1 == checkBoardForWin());
}

/* jump.c */

void testISLEFTPARENTVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_EQUAL(isLeftParentValid(&temp), NULL);
}

void testISRIGHTPARENTVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_NOT_EQUAL(isRightParentValid(&temp), NULL);
}
void testISLEFTSIBLINGVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_EQUAL(isLeftSiblingValid(&temp), NULL);
}

void testISRIGHTSIBLINGVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_NOT_EQUAL(isRightSiblingValid(&temp), NULL);
}

void testISLEFTCHILDVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_EQUAL(isLeftChildValid(&temp), NULL);
}

void testISRIGHTCHILDVALID(void){
	Coord temp = {3,0};
	CU_ASSERT_PTR_EQUAL(isRightChildValid(&temp), NULL);
}

void testVALIDJUMPS(void){
	Coord temp = {3,0};
	CU_ASSERT(JUMPFLAGS_RSIBLING == validJumps(&temp));
}

void testVALIDRANDOMJUMP(void){
	Coord temp = {3,0};
	CU_ASSERT(0 < validRandomJump(&temp));	
}

void testJUMPFROMCURPOS(void){
	Coord temp = {3,0};
	setCurPos(&temp);
	CU_ASSERT(1 == jumpFromCurPos(JUMPFLAGS_RSIBLING));
}

/* pos.c */

void testSETCURPOS(void)
{
	Coord temp = {1,1};
	CU_ASSERT_PTR_NOT_EQUAL(setCurPos(&temp), NULL);
}

void testGETRANDOMPOS(void)
{
	CU_ASSERT_PTR_NOT_EQUAL(getRandomPos(), NULL);
}

int main()
{
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* board.c */
   pSuite = CU_add_suite("board.c", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of initializeBoard()", testINITIALIZEBOARD)) ||
	   (NULL == CU_add_test(pSuite, "test of checkState()", testCHECKSTATE)) ||
	   (NULL == CU_add_test(pSuite, "test of setState()", testSETSTATE)) ||
	   (NULL == CU_add_test(pSuite, "test of checkBoardForWin()", testCHECKBOARDFORWIN)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* pos.c */
   pSuite = CU_add_suite("pos.c", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of setCurPos()", testSETCURPOS)) ||
       (NULL == CU_add_test(pSuite, "test of getRandomPos()", testGETRANDOMPOS)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* jump.c */
   pSuite = CU_add_suite("jump.c", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of isLeftParentValid()", testISLEFTPARENTVALID)) ||
	   (NULL == CU_add_test(pSuite, "test of isRightParentValid()", testISRIGHTPARENTVALID)) ||
	   (NULL == CU_add_test(pSuite, "test of isLeftSiblingValid()", testISLEFTSIBLINGVALID)) ||
	   (NULL == CU_add_test(pSuite, "test of isRightSiblingValid()", testISRIGHTSIBLINGVALID)) ||
	   (NULL == CU_add_test(pSuite, "test of isLeftChildValid()", testISLEFTCHILDVALID)) ||
	   (NULL == CU_add_test(pSuite, "test of isRightChildValid()", testISRIGHTCHILDVALID)) ||
       (NULL == CU_add_test(pSuite, "test of validJumps()", testVALIDJUMPS)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }



   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

