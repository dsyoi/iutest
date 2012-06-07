//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_type_param_tests3.cpp
 * @brief		iutest type parameter test
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "iutest_type_param_tests.hpp"

#if IUTEST_HAS_TYPED_TEST_P

template<typename T>
class TypeParamTest3 : public iutest::Test
{
public:
	static T value;
};

template<typename T>
T TypeParamTest3<T>::value = 0;


IUTEST_TYPED_TEST_CASE_P(TypeParamTest3);

IUTEST_TYPED_TEST_P(TypeParamTest3, Mul2)
{
	TypeParam x = 1;
	IUTEST_ASSERT_EQ(x+x, 2*x);
}

IUTEST_TYPED_TEST_P(TypeParamTest3, StaticMul2)
{
	TestFixture::value = 1;
	IUTEST_ASSERT_EQ(TestFixture::value+TestFixture::value, 2*TestFixture::value);
}

IUTEST_REGISTER_TYPED_TEST_CASE_P(TypeParamTest3, StaticMul2, Mul2);

namespace type_param_test
{

IUTEST_INSTANTIATE_TYPED_TEST_CASE_P(My3, TypeParamTest, float);
IUTEST_INSTANTIATE_TYPED_TEST_CASE_P(My3, TypeParamTest3, short);

}


#endif

