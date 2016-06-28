﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        iutest_switch_expect.hpp
 * @brief       EXPECT フレーバー切り替え ファイル
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_SWITCH_EXPECT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_
#define INCG_IRIS_IUTEST_SWITCH_EXPECT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_

#if !defined(IUTEST_USE_GTEST)

//======================================================================
// undef
#if defined(GTEST_INCLUDE_GTEST_GTEST_H_)

#undef EXPECT_TRUE
#undef EXPECT_FALSE
#undef EXPECT_EQ
#undef EXPECT_NE
#undef EXPECT_LT
#undef EXPECT_LE
#undef EXPECT_GT
#undef EXPECT_GE
#undef EXPECT_NEAR
#undef EXPECT_FLOAT_EQ
#undef EXPECT_DOUBLE_EQ
#undef EXPECT_STREQ
#undef EXPECT_STRNE
#undef EXPECT_STRCASEEQ
#undef EXPECT_STRCASENE
#undef EXPECT_THROW
#undef EXPECT_NO_THROW
#undef EXPECT_ANY_THROW
#undef EXPECT_NO_FATAL_FAILURE
#undef EXPECT_PRED_FORMAT1
#undef EXPECT_PRED_FORMAT2
#undef EXPECT_PRED_FORMAT3
#undef EXPECT_PRED_FORMAT4
#undef EXPECT_PRED_FORMAT5
#undef EXPECT_PRED1
#undef EXPECT_PRED2
#undef EXPECT_PRED3
#undef EXPECT_PRED4
#undef EXPECT_PRED5

#ifdef GTEST_OS_WINDOWS
#undef EXPECT_HRESULT_SUCCEEDED
#undef EXPECT_HRESULT_FAILED
#endif

#endif

//======================================================================
// define
#define EXPECT_TRUE     IUTEST_EXPECT_TRUE
#define EXPECT_FALSE    IUTEST_EXPECT_FALSE
#define EXPECT_EQ       IUTEST_EXPECT_EQ
#define EXPECT_NE       IUTEST_EXPECT_NE
#define EXPECT_LT       IUTEST_EXPECT_LT
#define EXPECT_LE       IUTEST_EXPECT_LE
#define EXPECT_GT       IUTEST_EXPECT_GT
#define EXPECT_GE       IUTEST_EXPECT_GE
#define EXPECT_NEAR     IUTEST_EXPECT_NEAR
#define EXPECT_FLOAT_EQ     IUTEST_EXPECT_FLOAT_EQ
#define EXPECT_DOUBLE_EQ    IUTEST_EXPECT_DOUBLE_EQ
#define EXPECT_STREQ        IUTEST_EXPECT_STREQ
#define EXPECT_STRNE        IUTEST_EXPECT_STRNE
#define EXPECT_STRCASEEQ    IUTEST_EXPECT_STRCASEEQ
#define EXPECT_STRCASENE    IUTEST_EXPECT_STRCASENE
#define EXPECT_THROW        IUTEST_EXPECT_THROW
#define EXPECT_NO_THROW     IUTEST_EXPECT_NO_THROW
#define EXPECT_ANY_THROW    IUTEST_EXPECT_ANY_THROW
#define EXPECT_NO_FATAL_FAILURE IUTEST_EXPECT_NO_FATAL_FAILURE

#ifdef IUTEST_OS_WINDOWS
#  define EXPECT_HRESULT_SUCCEEDED  IUTEST_EXPECT_HRESULT_SUCCEEDED
#  define EXPECT_HRESULT_FAILED     IUTEST_EXPECT_HRESULT_FAILED
#endif

#define EXPECT_PRED1    IUTEST_EXPECT_PRED1
#define EXPECT_PRED2    IUTEST_EXPECT_PRED2
#define EXPECT_PRED3    IUTEST_EXPECT_PRED3
#define EXPECT_PRED4    IUTEST_EXPECT_PRED4
#define EXPECT_PRED5    IUTEST_EXPECT_PRED5

#define EXPECT_PRED_FORMAT1 IUTEST_EXPECT_PRED_FORMAT1
#define EXPECT_PRED_FORMAT2 IUTEST_EXPECT_PRED_FORMAT2
#define EXPECT_PRED_FORMAT3 IUTEST_EXPECT_PRED_FORMAT3
#define EXPECT_PRED_FORMAT4 IUTEST_EXPECT_PRED_FORMAT4
#define EXPECT_PRED_FORMAT5 IUTEST_EXPECT_PRED_FORMAT5


#else // !defined(IUTEST_USE_GTEST)

//======================================================================
// undef
#if defined(INCG_IRIS_IUTEST_HPP_)

#undef IUTEST_EXPECT
#undef IUTEST_EXPECT_NOT
#undef IUTEST_EXPECT_TRUE
#undef IUTEST_EXPECT_FALSE
#undef IUTEST_EXPECT_EQ
#undef IUTEST_EXPECT_NE
#undef IUTEST_EXPECT_LT
#undef IUTEST_EXPECT_LE
#undef IUTEST_EXPECT_GT
#undef IUTEST_EXPECT_GE
#undef IUTEST_EXPECT_NEAR
#undef IUTEST_EXPECT_NULL
#undef IUTEST_EXPECT_NOTNULL
#undef IUTEST_EXPECT_SAME
#undef IUTEST_EXPECT_FLOAT_EQ
#undef IUTEST_EXPECT_DOUBLE_EQ
#undef IUTEST_EXPECT_STREQ
#undef IUTEST_EXPECT_STRNE
#undef IUTEST_EXPECT_STRCASEEQ
#undef IUTEST_EXPECT_STRCASENE
#undef IUTEST_EXPECT_THROW
#undef IUTEST_EXPECT_NO_THROW
#undef IUTEST_EXPECT_ANY_THROW
#undef IUTEST_EXPECT_NO_FATAL_FAILURE
#undef IUTEST_EXPECT_PRED_FORMAT1
#undef IUTEST_EXPECT_PRED_FORMAT2
#undef IUTEST_EXPECT_PRED_FORMAT3
#undef IUTEST_EXPECT_PRED_FORMAT4
#undef IUTEST_EXPECT_PRED_FORMAT5
#undef IUTEST_EXPECT_PRED1
#undef IUTEST_EXPECT_PRED2
#undef IUTEST_EXPECT_PRED3
#undef IUTEST_EXPECT_PRED4
#undef IUTEST_EXPECT_PRED5

#ifdef IUTEST_OS_WINDOWS
#undef IUTEST_EXPECT_HRESULT_SUCCEEDED
#undef IUTEST_EXPECT_HRESULT_FAILED
#endif

#undef IUTEST_EXPECT_FAIL
#undef IUTEST_EXPECT_FAIL_AT

#undef IUTEST_EXPECT_FAILURE

#endif

//======================================================================
// define
#define IUTEST_EXPECT(...)                  EXPECT_TRUE(__VA_ARGS__)
#define IUTEST_EXPECT_NOT(...)              EXPECT_FALSE(__VA_ARGS__)
#define IUTEST_EXPECT_TRUE(...)             EXPECT_TRUE(!!(__VA_ARGS__))
#define IUTEST_EXPECT_FALSE(...)            EXPECT_FALSE((__VA_ARGS__))
#define IUTEST_EXPECT_EQ                    EXPECT_EQ
#define IUTEST_EXPECT_NE(expected, actual)  EXPECT_PRED_FORMAT2(    \
                                                ::testing::internal::NeHelper<GTEST_IS_NULL_LITERAL_(expected)>::Compare, expected, actual)
#define IUTEST_EXPECT_LT                    EXPECT_LT
#define IUTEST_EXPECT_LE                    EXPECT_LE
#define IUTEST_EXPECT_GT                    EXPECT_GT
#define IUTEST_EXPECT_GE                    EXPECT_GE
#define IUTEST_EXPECT_NEAR                  EXPECT_NEAR
#define IUTEST_EXPECT_NULL(v)               EXPECT_EQ(NULL, v)
#define IUTEST_EXPECT_NOTNULL(v)            EXPECT_TRUE(NULL != (v))
#define IUTEST_EXPECT_SAME(v1, v2)          EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperSame, v1, v2)
#define IUTEST_EXPECT_FLOAT_EQ              EXPECT_FLOAT_EQ
#define IUTEST_EXPECT_DOUBLE_EQ             EXPECT_DOUBLE_EQ
#define IUTEST_EXPECT_STREQ                 EXPECT_STREQ
#define IUTEST_EXPECT_STRNE                 EXPECT_STRNE
#define IUTEST_EXPECT_STRCASEEQ             EXPECT_STRCASEEQ
#define IUTEST_EXPECT_STRCASENE             EXPECT_STRCASENE
#define IUTEST_EXPECT_THROW(statement, expected_exception)  EXPECT_THROW((void)(statement), expected_exception)
#define IUTEST_EXPECT_NO_THROW(statement)                   EXPECT_NO_THROW((void)(statement))
#define IUTEST_EXPECT_ANY_THROW(statement)                  EXPECT_ANY_THROW((void)(statement))
#define IUTEST_EXPECT_NO_FATAL_FAILURE      EXPECT_NO_FATAL_FAILURE

#ifdef GTEST_OS_WINDOWS
#  define IUTEST_EXPECT_HRESULT_SUCCEEDED   EXPECT_HRESULT_SUCCEEDED
#  define IUTEST_EXPECT_HRESULT_FAILED      EXPECT_HRESULT_FAILED
#endif

#define IUTEST_EXPECT_PRED1 EXPECT_PRED1
#define IUTEST_EXPECT_PRED2 EXPECT_PRED2
#define IUTEST_EXPECT_PRED3 EXPECT_PRED3
#define IUTEST_EXPECT_PRED4 EXPECT_PRED4
#define IUTEST_EXPECT_PRED5 EXPECT_PRED5

#define IUTEST_EXPECT_PRED_FORMAT1  EXPECT_PRED_FORMAT1
#define IUTEST_EXPECT_PRED_FORMAT2  EXPECT_PRED_FORMAT2
#define IUTEST_EXPECT_PRED_FORMAT3  EXPECT_PRED_FORMAT3
#define IUTEST_EXPECT_PRED_FORMAT4  EXPECT_PRED_FORMAT4
#define IUTEST_EXPECT_PRED_FORMAT5  EXPECT_PRED_FORMAT5

#define IUTEST_EXPECT_FAIL      ADD_FAILURE
#define IUTEST_EXPECT_FAIL_AT   ADD_FAILURE_AT

#define IUTEST_EXPECT_FAILURE   GTEST_NONFATAL_FAILURE_

#endif // !defined(IUTEST_USE_GTEST)

#define EXPECT_NULL     IUTEST_EXPECT_NULL
#define EXPECT_NOTNULL  IUTEST_EXPECT_NOTNULL
#define EXPECT_SAME     IUTEST_EXPECT_SAME

#endif // INCG_IRIS_IUTEST_SWITCH_EXPECT_HPP_F4AD6E1B_4B1F_40EE_A0CC_D454587B2C39_
