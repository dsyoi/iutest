﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        iutest_switch_for_gtest.hpp
 * @brief       switching to iutest from gtest
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2011-2018, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_IUTEST_SWITCH_FOR_GTEST_HPP_5770CDF3_B5D0_46BC_AAF8_B721902F9871
#define INCG_IRIS_IUTEST_SWITCH_FOR_GTEST_HPP_5770CDF3_B5D0_46BC_AAF8_B721902F9871

#if defined(IUTEST_USE_GTEST)

#if defined(INCG_IRIS_IUTEST_HPP_)
#  if IUTEST_HAS_TUPLE
#    define GTEST_USE_OWN_TR1_TUPLE 0
#  endif
#  ifdef StaticAssertTypeEq
#    undef StaticAssertTypeEq
#  endif
#endif

#if defined(_MSC_VER) && _MSC_VER == 1700
#  ifndef _VARIADIC_MAX
#    define _VARIADIC_MAX   10
#  endif

#include <tuple>
namespace std {
namespace tr1
{
    using ::std::tuple;
}
}
#endif

#ifdef __STRICT_ANSI__
#  undef __STRICT_ANSI__
#  include <string.h>
#  include <stdlib.h>
#  include <cstdio>
#  define __STRICT_ANSI__
#endif

//======================================================================
// include
#include "../iutest_ver.hpp"
#include <gtest/gtest.h>
#if defined(IUTEST_USE_GMOCK)
#include <gmock/gmock.h>
#include "iutest_gmock_ver.hpp"
#endif
#include "iutest_gtest_ver.hpp"
#include "../internal/iutest_pragma.hpp"

#if GTEST_VER < 0x01040000
#  error google test 1.3.0 or less is not supported...
#else

//======================================================================
// define

#if defined(INCG_IRIS_IUTEST_HPP_)
#undef IUTEST_SUCCEED
#undef IUTEST_FAIL
#undef IUTEST_ADD_FAILURE
#undef IUTEST_ADD_FAILURE_AT

#undef IUTEST_HAS_PARAM_TEST
#undef IUTEST_HAS_AUTOFIXTURE_PARAM_TEST
#undef IUTEST_HAS_ANY_PARAM_TEST
#undef IUTEST_HAS_COMBINE
#undef IUTEST_HAS_PAIRWISE
#undef IUTEST_HAS_CONCAT
#undef IUTEST_HAS_CSVPARAMS
#undef IUTEST_HAS_VARIADIC_VALUES
#undef IUTEST_HAS_VARIADIC_COMBINE
#undef IUTEST_HAS_VARIADIC_PAIRWISE
#undef IUTEST_HAS_VARIADIC_PRED
#undef IUTEST_HAS_TYPED_TEST
#undef IUTEST_HAS_TYPED_TEST_P
#undef IUTEST_TYPED_TEST_P_STRICT
#undef IUTEST_HAS_TYPED_TEST_APPEND_TYPENAME
#undef IUTEST_HAS_PARAM_TEST_PARAM_NAME_GENERATOR

#undef IUTEST_HAS_ARITHMETIC_EXPRESSION_DECOMPOSE
#undef IUTEST_HAS_BITWISE_EXPRESSION_DECOMPOSE

#undef IUTEST_HAS_ASSERTION_NOEQUALTO_OBJECT

#undef IUTEST_HAS_VALUESGEN
#undef IUTEST_HAS_RANDOMVALUES
#undef IUTEST_STATIC_ASSERT_MSG
#undef IUTEST_HAS_STATIC_ASSERT_TYPEEQ
#ifdef IUTEST_USE_THROW_ON_ASSERT_FAILURE
#  undef IUTEST_USE_THROW_ON_ASSERT_FAILURE
#endif
#undef IUTEST_USE_THROW_ON_ASSERTION_FAILURE
#undef IUTEST_HAS_LAMBDA_STATEMENTS
#undef IUTEST_HAS_SPI_LAMBDA_SUPPORT
#undef IUTEST_HAS_CATCH_SEH_EXCEPTION_ASSERTION
#undef IUTEST_HAS_GENRAND
#undef IUTEST_HAS_PRINT_TO
#undef IUTEST_HAS_TESTNAME_ALIAS
#undef IUTEST_HAS_TESTNAME_ALIAS_JP
#undef IUTEST_HAS_STREAM_RESULT

#undef IUTEST_HAS_VARIADIC_TEMPLATES
#undef IUTEST_HAS_VARIADIC_TEMPLATE_TEMPLATES
#undef IUTEST_HAS_INITIALIZER_LIST
#undef IUTEST_HAS_CHAR16_T
#undef IUTEST_HAS_CHAR32_T

#undef IUTEST_HAS_EXCEPTIONS
#undef IUTEST_HAS_RTTI
#undef IUTEST_HAS_REGEX
#undef IUTEST_HAS_SEH

#undef IUTEST_HAS_STREAM_BUFFER

#undef IUTEST_OPERAND
#undef IUTEST_EXPRESSION

#endif

#if GTEST_VER > 0x01040000
#  define IUTEST_SUCCEED        GTEST_SUCCEED
#else
#  define IUTEST_SUCCEED()      GTEST_SUCCESS_("Succeeded")
#endif
#define IUTEST_FAIL             GTEST_FAIL
#define IUTEST_ADD_FAILURE      ADD_FAILURE
#define IUTEST_ADD_FAILURE_AT   ADD_FAILURE_AT

#define IUTEST_HAS_PARAM_TEST               GTEST_HAS_PARAM_TEST
#define IUTEST_HAS_AUTOFIXTURE_PARAM_TEST   0
#define IUTEST_HAS_ANY_PARAM_TEST           0
#define IUTEST_HAS_COMBINE                  GTEST_HAS_COMBINE
#define IUTEST_HAS_PAIRWISE                 0
#define IUTEST_HAS_CONCAT                   0
#define IUTEST_HAS_CSVPARAMS                0
#define IUTEST_HAS_VARIADIC_VALUES          0
#define IUTEST_HAS_VARIADIC_COMBINE         0
#define IUTEST_HAS_VARIADIC_PAIRWISE        0
#define IUTEST_HAS_VARIADIC_PRED            0
#define IUTEST_HAS_TYPED_TEST               GTEST_HAS_TYPED_TEST
#define IUTEST_HAS_TYPED_TEST_P             GTEST_HAS_TYPED_TEST_P
#define IUTEST_TYPED_TEST_P_STRICT          1

#define IUTEST_HAS_TYPED_TEST_APPEND_TYPENAME   0
#if GTEST_VER < 0x01080000
#  define IUTEST_HAS_PARAM_TEST_PARAM_NAME_GENERATOR    0
#else
#  define IUTEST_HAS_PARAM_TEST_PARAM_NAME_GENERATOR    1
#endif

#define IUTEST_HAS_ARITHMETIC_EXPRESSION_DECOMPOSE  0
#define IUTEST_HAS_BITWISE_EXPRESSION_DECOMPOSE     1

#define IUTEST_HAS_ASSERTION_NOEQUALTO_OBJECT   0

#define IUTEST_HAS_VALUESGEN            0
#define IUTEST_HAS_RANDOMVALUES         0
#define IUTEST_HAS_STATIC_ASSERT_TYPEEQ 1
#define IUTEST_USE_THROW_ON_ASSERTION_FAILURE   0
#define IUTEST_HAS_LAMBDA_STATEMENTS    0
#define IUTEST_HAS_SPI_LAMBDA_SUPPORT   0
#define IUTEST_HAS_CATCH_SEH_EXCEPTION_ASSERTION    0
#define IUTEST_HAS_GENRAND              0
#define IUTEST_HAS_PRINT_TO             1
#define IUTEST_HAS_TESTNAME_ALIAS       0
#define IUTEST_HAS_TESTNAME_ALIAS_JP    0
#define IUTEST_HAS_STREAM_RESULT        1

#define IUTEST_HAS_STREAM_BUFFER        0

#define IUTEST_HAS_EXCEPTIONS       GTEST_HAS_EXCEPTIONS
#define IUTEST_HAS_RTTI             GTEST_HAS_RTTI
#define IUTEST_HAS_REGEX            GTEST_USES_POSIX_RE
#define IUTEST_HAS_SEH              GTEST_HAS_SEH

#if GTEST_VER < 0x01070000
#  define IUTEST_NO_RECORDPROPERTY_OUTSIDE_TESTMETHOD_LIFESPAN
#  define IUTEST_NO_UNITEST_AD_HOC_TEST_RESULT_ACCESSOR
#  define IUTEST_NO_TESTCASE_AD_HOC_TEST_RESULT_ACCESSOR
#endif

#ifndef IUTEST_CXX_OVERRIDE
#  define IUTEST_CXX_OVERRIDE
#endif
#ifndef IUTEST_CXX_DEFAULT_FUNCTION
#  define IUTEST_CXX_DEFAULT_FUNCTION   {}
#endif

#include "switch/iutest_switch_port.hpp"
#include "switch/iutest_switch_core.hpp"

#include "switch/iutest_switch_gmock.hpp"

#include "switch/iutest_switch_assert.hpp"
#include "switch/iutest_switch_expect.hpp"
#include "switch/iutest_switch_inform.hpp"
#include "switch/iutest_switch_assume.hpp"

#include "switch/iutest_switch_assertion_return.hpp"
#include "switch/iutest_switch_package.hpp"
#include "switch/iutest_switch_peep.hpp"
#include "switch/iutest_switch_pmz.hpp"
#include "switch/iutest_switch_pred.hpp"
#include "switch/iutest_switch_skip.hpp"
#include "switch/iutest_switch_throw_value.hpp"
#include "switch/iutest_switch_no_failure.hpp"

#include "switch/iutest_switch_filepath.hpp"

#include "switch/iutest_switch_cmphelper.hpp"

#ifndef IUTEST_STATIC_ASSERT_MSG
#  define IUTEST_STATIC_ASSERT_MSG(B, Msg)  typedef ::testing::iusupport::StaticAssertionTest<  \
        sizeof(::testing::iusupport::StaticAssertionFailure< (bool)B >) > IUTEST_PP_CAT(iutest_static_assert_typedef_, __LINE__)    // NOLINT
#endif

#ifndef IUTEST_STATIC_ASSERT
#  define IUTEST_STATIC_ASSERT(...) IUTEST_STATIC_ASSERT_MSG((__VA_ARGS__), "")
#endif

#ifdef IUTEST_ASSERT_EXIT
#  undef IUTEST_ASSERT_EXIT
#endif
#define IUTEST_ASSERT_EXIT(cond)    do { if( !(cond) ) {                                                    \
                                        GTEST_MESSAGE_(#cond, ::testing::TestPartResult::kFatalFailure);    \
                                        exit(1);                                                            \
                                    } } while(::testing::internal::AlwaysFalse())

#define IUTEST_OPERAND(op)          op
#define IUTEST_EXPRESSION(expr)     expr

#if GTEST_VER < 0x01070000

#undef GTEST_COMPILE_ASSERT_
#define GTEST_COMPILE_ASSERT_(expr, msg) \
  typedef ::testing::internal::CompileAssert<(static_cast<bool>(expr))> \
      msg[static_cast<bool>(expr) ? 1 : -1] GTEST_ATTRIBUTE_UNUSED_

#endif

namespace testing
{

//======================================================================
// function
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, char** argv)
{
    InitGoogleTest(pargc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, wchar_t** argv)
{
    InitGoogleTest(pargc, argv);
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, const char** argv)
{
    InitGoogleTest(pargc, const_cast<char**>(argv));
}
inline void IUTEST_ATTRIBUTE_UNUSED_ InitIrisUnitTest(int* pargc, const wchar_t** argv)
{
    InitGoogleTest(pargc, const_cast<wchar_t**>(argv));
}

// tuple
namespace tuples
{
#if GTEST_HAS_STD_TUPLE_
    using ::std::tuple;
    using ::std::tuple_size;
    using ::std::tuple_element;
    using ::std::make_tuple;
    using ::std::get;
#else
    using ::std::tr1::tuple;
    using ::std::tr1::tuple_size;
    using ::std::tr1::tuple_element;
    using ::std::tr1::make_tuple;
    using ::std::tr1::get;
#endif
}   // end of namespace tuples

#if GTEST_VER < 0x01080000
using tuples::tuple;
using tuples::tuple_size;
using tuples::tuple_element;
#endif

using tuples::make_tuple;
using tuples::get;

#if !defined(IUTEST_USING_BEGIN_END)
#  define IUTEST_USING_BEGIN_END()  \
    using ::std::begin; using ::std::end
#endif

namespace iusupport
{
    /** @private */
    template<bool b>struct StaticAssertionFailure;
    /** @overload */
    template<> struct StaticAssertionFailure<true> { enum { value = 1 }; };
    /** @private */
    template<int x>struct StaticAssertionTest {};
}

inline const char* GetAssertionResultMessage(const AssertionResult& ar)
{
#if GTEST_VER <= 0x01040000
    return ar.failure_message();
#else
    return ar.message();
#endif
}

#if defined(INCG_IRIS_IUTEST_HPP_)

namespace iusupport
{
    inline AssertionResult iuMakeAssertionResult(const AssertionResult& ar) { return ar; }
    inline AssertionResult iuMakeAssertionResult(const ::iutest::AssertionResult& ar)
    {
#if GTEST_VER > 0x01040000
        return AssertionResult(static_cast<bool>(ar)) << ar.message();
#else
        return static_cast<bool>(ar) ? AssertionSuccess() : AssertionFailure(Message(ar.message()));
#endif
    }
}   // end of namespace iusupport

// ::iutest::AssertionResult -> ::testing::AssertionResult
#undef GTEST_ASSERT_
#define GTEST_ASSERT_(expression, on_failure) \
  GTEST_AMBIGUOUS_ELSE_BLOCKER_ \
  if (const ::testing::AssertionResult gtest_ar = ::testing::iusupport::iuMakeAssertionResult(expression)) \
    ; \
  else \
    on_failure(GetAssertionResultMessage(gtest_ar))

#endif

namespace internal
{

template<typename T>
struct is_pointer<T* volatile> : public true_type {};

}   // end of namespace internal

// ostream
typedef ::std::ostream  iu_ostream;

#if GTEST_VER < 0x01060000

namespace dummy_printer
{

template<typename T>
inline ::std::string PrintToString(T)
{
    // google test 1.5 or less is not supported to PrintToString
    return "";
}

}   // end of namespace dummy_printer

#if !defined(IUTEST_USE_GMOCK)
using dummy_printer::PrintToString;
#elif GTEST_VER < 0x01050000
using dummy_printer::PrintToString;
#endif

#endif

}   // end of namespace testing

#if defined(INCG_IRIS_IUTEST_HPP_)
// すでに iutest namespace が存在するので、define で対応
#  define iutest testing
#else
namespace iutest = testing;
#endif

#include "../iutest_util.hpp"

#ifndef INCG_IRIS_IUTEST_HPP_
#  define INCG_IRIS_IUTEST_HPP_ // 以降で、iutest が include されないようにする
#endif

#endif

#endif

#endif // INCG_IRIS_IUTEST_SWITCH_FOR_GTEST_HPP_5770CDF3_B5D0_46BC_AAF8_B721902F9871
