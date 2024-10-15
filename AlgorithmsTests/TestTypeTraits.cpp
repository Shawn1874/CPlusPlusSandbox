#include "stdafx.h"
#include "TestTypeTraits.h"
#include <type_traits>
#include <iostream>

TEST_F(TestTypeTraits, TestIsFundamental)
{
	EXPECT_TRUE(std::is_fundamental<bool>());
	EXPECT_TRUE(std::is_fundamental<int>());
	EXPECT_TRUE(std::is_fundamental<float>());
	EXPECT_TRUE(std::is_fundamental<double>());
	EXPECT_TRUE(std::is_fundamental<char>());
	EXPECT_TRUE(std::is_fundamental<char16_t>());
	EXPECT_TRUE(std::is_fundamental<char32_t>());
	EXPECT_TRUE(std::is_fundamental<wchar_t>());
	EXPECT_TRUE(std::is_fundamental<void>());
	EXPECT_TRUE(std::is_fundamental<nullptr_t>());
}

TEST_F(TestTypeTraits, TestIsVoid)
{
	EXPECT_TRUE(std::is_void<void>());
}

TEST_F(TestTypeTraits, TestIsNullPtr)
{
	EXPECT_FALSE(std::is_null_pointer<void*>());
	EXPECT_FALSE(std::is_null_pointer<int*>());
	EXPECT_TRUE(std::is_null_pointer<nullptr_t>());
}

TEST_F(TestTypeTraits, TestIsArithmetic)
{
	EXPECT_TRUE(std::is_arithmetic<bool>());
	EXPECT_TRUE(std::is_arithmetic<int>());
	EXPECT_TRUE(std::is_arithmetic<int16_t>());
	EXPECT_TRUE(std::is_arithmetic<float>());
	EXPECT_TRUE(std::is_arithmetic<double>());
	EXPECT_TRUE(std::is_arithmetic<char>());
	EXPECT_TRUE(std::is_arithmetic<char16_t>());
	EXPECT_TRUE(std::is_arithmetic<char32_t>());
	EXPECT_TRUE(std::is_arithmetic<wchar_t>());
	EXPECT_FALSE(std::is_arithmetic<void>());
	EXPECT_FALSE(std::is_arithmetic<nullptr_t>());

	int test = 0;
}

TEST_F(TestTypeTraits, TestIsReference)
{
	// Test if something is L or R value reference
	class A {};

	EXPECT_TRUE(std::is_lvalue_reference<A&>());
	EXPECT_FALSE(std::is_rvalue_reference<A&>());

	EXPECT_TRUE(std::is_rvalue_reference<A&&>());
	EXPECT_FALSE(std::is_lvalue_reference<A&&>());

	EXPECT_FALSE(std::is_rvalue_reference<A>());  // value type so is not a reference at all
	EXPECT_FALSE(std::is_lvalue_reference<A>());  // value type so is not a reference at all

	EXPECT_TRUE(std::is_lvalue_reference<int&>());
	EXPECT_FALSE(std::is_rvalue_reference<int&>());

	EXPECT_TRUE(std::is_rvalue_reference<int&&>());
	EXPECT_FALSE(std::is_rvalue_reference<int&>());

	EXPECT_FALSE(std::is_rvalue_reference<int>());  // value type so is not a reference at all
	EXPECT_FALSE(std::is_lvalue_reference<int>());  // value type so is not a reference at all
}

TEST_F(TestTypeTraits, TestSprintf)
{
	char tprop_str[13] = { 0 };
	int m_subtractor[2] = { 1, 2 };
	double m_multiplier[2] = { 1.125, 2.0 };
	// Verify the string without the = modifier
	sprintf(tprop_str, "%07.3f%04d", m_multiplier[0], m_subtractor[0]);
	EXPECT_STREQ(tprop_str, "001.1250001");

	// Verify the string with the modifier which should add the + to positive numbers
	sprintf(tprop_str, "%07.3f%+04d", m_multiplier[0], m_subtractor[0]);
	EXPECT_STREQ(tprop_str, "001.125+001");

	// Verify the string with the modifier which should add the + to positive numbers
	m_subtractor[0] = 0;
	sprintf(tprop_str, "%07.3f%+04d", m_multiplier[0], m_subtractor[0]);
	EXPECT_STREQ(tprop_str, "001.1250000");

	// test negative number.  With or without the + modifier the result will be the same
	m_subtractor[0] = -1;
	sprintf(tprop_str, "%07.3f%+04d", m_multiplier[0], m_subtractor[0]);
	EXPECT_STREQ(tprop_str, "001.125-001");
	sprintf(tprop_str, "%07.3f%04d", m_multiplier[0], m_subtractor[0]);
	EXPECT_STREQ(tprop_str, "001.125-001");

}