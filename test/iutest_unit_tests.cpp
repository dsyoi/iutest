﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_unit_tests.cpp
 * @brief		iutest test
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "iutest.hpp"

class Base {};
class Derived : public Base {};
class Hoge {};
void Func(void) {}

typedef int inttype;

IUTEST(UnitTest, is_class)
{
	IUTEST_STATIC_ASSERT( !::iutest_type_traits::is_class<int>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::is_class<Base>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::is_class<Derived>::value );
	IUTEST_STATIC_ASSERT( !::iutest_type_traits::is_class<void (*)()>::value );
}

IUTEST(UnitTest, is_same)
{
	IUTEST_STATIC_ASSERT( !(::iutest_type_traits::is_same<int, char>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_same<int, int>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_same<int, inttype>::value) );
}

IUTEST(UnitTest, is_void)
{
	IUTEST_STATIC_ASSERT( !::iutest_type_traits::is_void<void*>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::is_void<void>::value );
	IUTEST_STATIC_ASSERT( !::iutest_type_traits::is_void<int>::value );
}

IUTEST(UnitTest, is_base_of)
{
	IUTEST_STATIC_ASSERT( !(::iutest_type_traits::is_base_of<int, Base>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_base_of<Base, Derived>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_base_of<Base, const Derived>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_base_of<const volatile Base, Derived>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_base_of<volatile Base, volatile Derived const>::value) );
	IUTEST_STATIC_ASSERT( !(::iutest_type_traits::is_base_of<Base, Hoge>::value) );
	IUTEST_STATIC_ASSERT(  (::iutest_type_traits::is_base_of<Derived, Derived>::value) );
}

#if !defined(IUTEST_NO_ARGUMENT_DEPENDENT_LOOKUP)

struct X
{
	int a,b,c;
};
struct Y
{
	int a,b,c;
	bool operator == (const Y&) { return true; }
};

struct Z
{
	int a,b,c;
};

bool operator == (const Z&, const Z&) { return true; }

typedef ::iutest::tuples::tuple<bool, int, int> Tuple;

IUTEST(UnitTest, has_equal_to)
{
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to<int>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to<float>::value );
	IUTEST_STATIC_ASSERT( !::iutest_type_traits::has_equal_to<X>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to<Y>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to<Z>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to<Tuple>::value );
	IUTEST_STATIC_ASSERT(  ::iutest_type_traits::has_equal_to< ::std::vector<int> >::value );
}

#endif

IUTEST(UnitTest, StringReplace)
{
	::std::string str = "a1a2a3a4b5";
	::iutest::detail::StringReplace(str, 'a', "ii");
	IUTEST_EXPECT_STREQ("ii1ii2ii3ii4b5", str);
}

IUTEST(UnitTest, AddDefaultPackageName)
{
	IUTEST_EXPECT_STREQ("Test.a1a2a3a4b5", ::iutest::TestEnv::AddDefaultPackageName("a1a2a3a4b5"));
	IUTEST_EXPECT_STREQ("Hoge.a1a2a3a4b5", ::iutest::TestEnv::AddDefaultPackageName("Hoge.a1a2a3a4b5"));
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	::iutest::IUTEST_FLAG(default_package_name) = "Test";
	return IUTEST_RUN_ALL_TESTS();
}

