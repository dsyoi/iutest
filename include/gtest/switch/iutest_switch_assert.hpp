﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        iutest_switch_assert.hpp
 * @brief       ASSERT フレーバー切り替え ファイル
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_SWITCH_ASSERT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_
#define INCG_IRIS_IUTEST_SWITCH_ASSERT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_

#if !defined(IUTEST_USE_GTEST)

//======================================================================
// undef
#if defined(GTEST_INCLUDE_GTEST_GTEST_H_)

#undef ASSERT_TRUE
#undef ASSERT_FALSE
#undef ASSERT_EQ
#undef ASSERT_NE
#undef ASSERT_LT
#undef ASSERT_LE
#undef ASSERT_GT
#undef ASSERT_GE
#undef ASSERT_NEAR
#undef ASSERT_FLOAT_EQ
#undef ASSERT_DOUBLE_EQ
#undef ASSERT_STREQ
#undef ASSERT_STRNE
#undef ASSERT_STRCASEEQ
#undef ASSERT_STRCASENE
#undef ASSERT_THROW
#undef ASSERT_NO_THROW
#undef ASSERT_ANY_THROW
#undef ASSERT_NO_FATAL_FAILURE
#undef ASSERT_PRED_FORMAT1
#undef ASSERT_PRED_FORMAT2
#undef ASSERT_PRED_FORMAT3
#undef ASSERT_PRED_FORMAT4
#undef ASSERT_PRED_FORMAT5
#undef ASSERT_PRED1
#undef ASSERT_PRED2
#undef ASSERT_PRED3
#undef ASSERT_PRED4
#undef ASSERT_PRED5

#ifdef GTEST_OS_WINDOWS
#undef ASSERT_HRESULT_SUCCEEDED
#undef ASSERT_HRESULT_FAILED
#endif

#endif

//======================================================================
// define
#define ASSERT_TRUE     IUTEST_ASSERT_TRUE
#define ASSERT_FALSE    IUTEST_ASSERT_FALSE
#define ASSERT_EQ       IUTEST_ASSERT_EQ
#define ASSERT_NE       IUTEST_ASSERT_NE
#define ASSERT_LT       IUTEST_ASSERT_LT
#define ASSERT_LE       IUTEST_ASSERT_LE
#define ASSERT_GT       IUTEST_ASSERT_GT
#define ASSERT_GE       IUTEST_ASSERT_GE
#define ASSERT_NEAR     IUTEST_ASSERT_NEAR
#define ASSERT_FLOAT_EQ     IUTEST_ASSERT_FLOAT_EQ
#define ASSERT_DOUBLE_EQ    IUTEST_ASSERT_DOUBLE_EQ
#define ASSERT_STREQ        IUTEST_ASSERT_STREQ
#define ASSERT_STRNE        IUTEST_ASSERT_STRNE
#define ASSERT_STRCASEEQ    IUTEST_ASSERT_STRCASEEQ
#define ASSERT_STRCASENE    IUTEST_ASSERT_STRCASENE
#define ASSERT_THROW        IUTEST_ASSERT_THROW
#define ASSERT_NO_THROW     IUTEST_ASSERT_NO_THROW
#define ASSERT_ANY_THROW    IUTEST_ASSERT_ANY_THROW
#define ASSERT_NO_FATAL_FAILURE IUTEST_ASSERT_NO_FATAL_FAILURE

#ifdef IUTEST_OS_WINDOWS
#  define ASSERT_HRESULT_SUCCEEDED  IUTEST_ASSERT_HRESULT_SUCCEEDED
#  define ASSERT_HRESULT_FAILED     IUTEST_ASSERT_HRESULT_FAILED
#endif

#define ASSERT_PRED1    IUTEST_ASSERT_PRED1
#define ASSERT_PRED2    IUTEST_ASSERT_PRED2
#define ASSERT_PRED3    IUTEST_ASSERT_PRED3
#define ASSERT_PRED4    IUTEST_ASSERT_PRED4
#define ASSERT_PRED5    IUTEST_ASSERT_PRED5

#define ASSERT_PRED_FORMAT1 IUTEST_ASSERT_PRED_FORMAT1
#define ASSERT_PRED_FORMAT2 IUTEST_ASSERT_PRED_FORMAT2
#define ASSERT_PRED_FORMAT3 IUTEST_ASSERT_PRED_FORMAT3
#define ASSERT_PRED_FORMAT4 IUTEST_ASSERT_PRED_FORMAT4
#define ASSERT_PRED_FORMAT5 IUTEST_ASSERT_PRED_FORMAT5


#else // !defined(IUTEST_USE_GTEST)

//======================================================================
// undef
#if defined(INCG_IRIS_IUTEST_HPP_)

#undef IUTEST_ASSERT
#undef IUTEST_ASSERT_NOT
#undef IUTEST_ASSERT_TRUE
#undef IUTEST_ASSERT_FALSE
#undef IUTEST_ASSERT_EQ
#undef IUTEST_ASSERT_NE
#undef IUTEST_ASSERT_LT
#undef IUTEST_ASSERT_LE
#undef IUTEST_ASSERT_GT
#undef IUTEST_ASSERT_GE
#undef IUTEST_ASSERT_NEAR
#undef IUTEST_ASSERT_NULL
#undef IUTEST_ASSERT_NOTNULL
#undef IUTEST_ASSERT_SAME
#undef IUTEST_ASSERT_FLOAT_EQ
#undef IUTEST_ASSERT_DOUBLE_EQ
#undef IUTEST_ASSERT_STREQ
#undef IUTEST_ASSERT_STRNE
#undef IUTEST_ASSERT_STRCASEEQ
#undef IUTEST_ASSERT_STRCASENE
#undef IUTEST_ASSERT_THROW
#undef IUTEST_ASSERT_NO_THROW
#undef IUTEST_ASSERT_ANY_THROW
#undef IUTEST_ASSERT_NO_FATAL_FAILURE
#undef IUTEST_ASSERT_PRED_FORMAT1
#undef IUTEST_ASSERT_PRED_FORMAT2
#undef IUTEST_ASSERT_PRED_FORMAT3
#undef IUTEST_ASSERT_PRED_FORMAT4
#undef IUTEST_ASSERT_PRED_FORMAT5
#undef IUTEST_ASSERT_PRED1
#undef IUTEST_ASSERT_PRED2
#undef IUTEST_ASSERT_PRED3
#undef IUTEST_ASSERT_PRED4
#undef IUTEST_ASSERT_PRED5

#ifdef IUTEST_OS_WINDOWS
#undef IUTEST_ASSERT_HRESULT_SUCCEEDED
#undef IUTEST_ASSERT_HRESULT_FAILED
#endif

#undef IUTEST_ASSERT_FAIL

#undef IUTEST_ASSERT_FAILURE

#endif

//======================================================================
// define
#define IUTEST_ASSERT(...)                  ASSERT_TRUE(__VA_ARGS__)
#define IUTEST_ASSERT_NOT(...)              ASSERT_FALSE(__VA_ARGS__)
#define IUTEST_ASSERT_TRUE(...)             ASSERT_TRUE(!!(__VA_ARGS__))
#define IUTEST_ASSERT_FALSE(...)            ASSERT_FALSE((__VA_ARGS__))
#define IUTEST_ASSERT_EQ                    ASSERT_EQ
#define IUTEST_ASSERT_NE(expected, actual)  ASSERT_PRED_FORMAT2(    \
                                                ::testing::internal::NeHelper<GTEST_IS_NULL_LITERAL_(expected)>::Compare, expected, actual)
#define IUTEST_ASSERT_LT                    ASSERT_LT
#define IUTEST_ASSERT_LE                    ASSERT_LE
#define IUTEST_ASSERT_GT                    ASSERT_GT
#define IUTEST_ASSERT_GE                    ASSERT_GE
#define IUTEST_ASSERT_NEAR                  ASSERT_NEAR
#define IUTEST_ASSERT_NULL(v)               IUTEST_THROUGH_ANALYSIS_ASSUME((v) == NULL, ASSERT_EQ(NULL, v))
#define IUTEST_ASSERT_NOTNULL(v)            IUTEST_THROUGH_ANALYSIS_ASSUME((v) != NULL, ASSERT_TRUE(NULL != (v)))
#define IUTEST_ASSERT_SAME(v1, v2)          ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperSame, v1, v2)
#define IUTEST_ASSERT_FLOAT_EQ              ASSERT_FLOAT_EQ
#define IUTEST_ASSERT_DOUBLE_EQ             ASSERT_DOUBLE_EQ
#define IUTEST_ASSERT_STREQ                 ASSERT_STREQ
#define IUTEST_ASSERT_STRNE                 ASSERT_STRNE
#define IUTEST_ASSERT_STRCASEEQ             ASSERT_STRCASEEQ
#define IUTEST_ASSERT_STRCASENE             ASSERT_STRCASENE
#define IUTEST_ASSERT_THROW(statement, expected_exception)      ASSERT_THROW((void)(statement), expected_exception)
#define IUTEST_ASSERT_NO_THROW(statement)                       ASSERT_NO_THROW((void)(statement))
#define IUTEST_ASSERT_ANY_THROW(statement)                      ASSERT_ANY_THROW((void)(statement))
#define IUTEST_ASSERT_NO_FATAL_FAILURE      ASSERT_NO_FATAL_FAILURE

#ifdef GTEST_OS_WINDOWS
#  define IUTEST_ASSERT_HRESULT_SUCCEEDED   ASSERT_HRESULT_SUCCEEDED
#  define IUTEST_ASSERT_HRESULT_FAILED      ASSERT_HRESULT_FAILED
#endif

#define IUTEST_ASSERT_PRED1 ASSERT_PRED1
#define IUTEST_ASSERT_PRED2 ASSERT_PRED2
#define IUTEST_ASSERT_PRED3 ASSERT_PRED3
#define IUTEST_ASSERT_PRED4 ASSERT_PRED4
#define IUTEST_ASSERT_PRED5 ASSERT_PRED5

#define IUTEST_ASSERT_PRED_FORMAT1  ASSERT_PRED_FORMAT1
#define IUTEST_ASSERT_PRED_FORMAT2  ASSERT_PRED_FORMAT2
#define IUTEST_ASSERT_PRED_FORMAT3  ASSERT_PRED_FORMAT3
#define IUTEST_ASSERT_PRED_FORMAT4  ASSERT_PRED_FORMAT4
#define IUTEST_ASSERT_PRED_FORMAT5  ASSERT_PRED_FORMAT5

#define IUTEST_ASSERT_FAIL      GTEST_FAIL

#define IUTEST_ASSERT_FAILURE   GTEST_FATAL_FAILURE_

#endif // !defined(IUTEST_USE_GTEST)

#define ASSERT_NULL     IUTEST_ASSERT_NULL
#define ASSERT_NOTNULL  IUTEST_ASSERT_NOTNULL
#define ASSERT_SAME     IUTEST_ASSERT_SAME

#endif // INCG_IRIS_IUTEST_SWITCH_ASSERT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_
