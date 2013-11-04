//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_throw_on_fialure_tests.cpp
 * @brief		throw_on_fialure 対応テスト
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

#if IUTEST_HAS_EXCEPTIONS

IUTEST(Expect, Test)
{
	IUTEST_EXPECT_EQ(2, 1);
}

IUTEST(Expect, Dummy)
{
	IUTEST_EXPECT_EQ(2, 1);
}

IUTEST(Assert, Test)
{
	IUTEST_ASSERT_EQ(2, 1);
}

IUTEST(Assert, Dummy)
{
	IUTEST_ASSERT_EQ(2, 1);
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	::iutest::IUTEST_FLAG(throw_on_failure) = true;
#if !defined(IUTEST_USE_GTEST)
	::iutest::IUTEST_FLAG(catch_exceptions_global) = false;
#endif
	
#if IUTEST_HAS_EXCEPTIONS
	try
	{
		::iutest::IUTEST_FLAG(filter) = "*Expect*";
		IUTEST_INIT(&argc, argv);
		(void)IUTEST_RUN_ALL_TESTS();
		
		return 1;
	}
	catch(...)
	{
	}

	try
	{
		::iutest::IUTEST_FLAG(filter) = "*Assert*";
		IUTEST_INIT(&argc, argv);
		(void)IUTEST_RUN_ALL_TESTS();
		
		return 1;
	}
	catch(...)
	{
	}
#endif
	printf("*** Successful ***\n");
	return 0;
}
