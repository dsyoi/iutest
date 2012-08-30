//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_fixture_tests.cpp
 * @brief		iutest fixture test
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
#include "../include/iutest.hpp"

class TestFixed : public ::iutest::Test
{
protected:
	static int x;
public:
	virtual void SetUp(void)
	{
		++x;
	}
	static void SetUpTestCase(void)
	{
		x = 0;
	}
};
int TestFixed::x = -1;

IUTEST_F(TestFixed, Test1)
{
	IUTEST_ASSERT_EQ(1, x);
}

IUTEST_F(TestFixed, Test2)
{
	IUTEST_ASSERT_EQ(2, x);
}
