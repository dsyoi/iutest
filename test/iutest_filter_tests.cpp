//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_filter_tests.cpp
 * @brief		filter 対応テスト
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

#include <assert.h>

IUTEST(Test, Fail)
{
	IUTEST_ASSERT_EQ(2, 3);
}

IUTEST(Fail, Test)
{
	IUTEST_ASSERT_EQ(2, 3);
}

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_EQ(3, 3);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	{
		::iutest::IUTEST_FLAG(filter) = "-*Fail*";
		int ret = IUTEST_RUN_ALL_TESTS();
		
		if( ret != 0 ) return 1;
#if !defined(IUTEST_USE_GTEST) || (defined(GTEST_MINOR) && GTEST_MINOR >= 0x07)
		assert( ::iutest::UnitTest::GetInstance()->reportable_test_count() == 1 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_disabled_test_count() == 0 );
#endif
#if !defined(IUTEST_USE_GTEST)
		assert( ::iutest::UnitTest::GetInstance()->skip_test_count() == 2 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_skip_test_count() == 0 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_test_was_skipped_count() == 0 );
#endif
	}
	{
		::iutest::IUTEST_FLAG(filter) = "*Fail*";
		int ret = IUTEST_RUN_ALL_TESTS();
		
		if( ret == 0 ) return 1;
#if !defined(IUTEST_USE_GTEST) || (defined(GTEST_MINOR) && GTEST_MINOR >= 0x07)
		assert( ::iutest::UnitTest::GetInstance()->reportable_test_count() == 2 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_disabled_test_count() == 0 );
#endif
#if !defined(IUTEST_USE_GTEST)
		assert( ::iutest::UnitTest::GetInstance()->skip_test_count() == 1 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_skip_test_count() == 0 );
		assert( ::iutest::UnitTest::GetInstance()->reportable_test_was_skipped_count() == 0 );
#endif
	}
	printf("*** Successful ***\n");
	return 0;
}
