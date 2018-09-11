/**
 * \file sample1.h
 * \brief Header with doxygen sample
 * \author AYi
 * \version 0.1
 * \date 01 Janvier 2016
 *
 * Example for using header with doxy plus todolist
 *
 */

/**My Preprocessor Macro
 * \todo test todo TEST_DEFINE macro.*/ 
#define TEST_DEFINE(x) (x*x) 

/**
 * @defgroup TEST_GROUP Test Group
 *
 * @{
 */

/** 
 * \define TEST_AAA 
 * \brief macro AAA documentation
 *
 * details desc of TEST_AAA 
 *
 *  * \todo test todo TEST_AAA macro
 */

#define TEST_AAA (1)
/** Test BBB documentation. */
#define TEST_BBB (2)
/** Test CCC documentation. */
#define TEST_CCC (3)
/** @} */
