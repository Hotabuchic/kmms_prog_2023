#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	IBusko::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}


class CompareFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber two = IBusko::LongNumber("2");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
};



TEST_F(CompareFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(CompareFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(CompareFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}



TEST_F(CompareFixture, greater) {
	ASSERT_TRUE(two > one_v1) << "Проверка " << two << " > " << one_v1;
}

TEST_F(CompareFixture, not_greater) {
	ASSERT_FALSE(one_v1 > twelve) << "Проверка " << one_v1 << " > " << twelve;
}

TEST_F(CompareFixture, not_greater_v2) {
	ASSERT_FALSE(one_v1 > one_v2) << "Проверка " << one_v1 << " > " << one_v2;
}
	
TEST_F(CompareFixture, greater_negative_var) {
	ASSERT_TRUE(one_v1 > negative_one) 
		<< "Проверка " << one_v1 << " > " << negative_one;
}


TEST_F(CompareFixture, less) {
	ASSERT_FALSE(two < one_v1) << "Проверка " << two << " < " << one_v1;
}

TEST_F(CompareFixture, not_less) {
	ASSERT_TRUE(one_v1 < twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(CompareFixture, not_less_v2) {
	ASSERT_FALSE(one_v1 < one_v2) << "Проверка " << one_v1 << " < " << one_v2;
}
	
TEST_F(CompareFixture, less_negative_var) {
	ASSERT_FALSE(one_v1 < negative_one) 
		<< "Проверка " << one_v1 << " < " << negative_one;
}

class ProcedureFixture : public testing::Test {
	public:
		IBusko::LongNumber one = IBusko::LongNumber("1");
		IBusko::LongNumber noll = IBusko::LongNumber("0");
		IBusko::LongNumber two = IBusko::LongNumber("2");
		IBusko::LongNumber three = IBusko::LongNumber("3");
		IBusko::LongNumber six = IBusko::LongNumber("6");
		IBusko::LongNumber ten = IBusko::LongNumber("10");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
		IBusko::LongNumber negative_two = IBusko::LongNumber("-2");
};


TEST_F(ProcedureFixture, addition) {
	ASSERT_TRUE((one + two) == three) << "Проверка " << one << " + " << two << " = " << three;
}

TEST_F(ProcedureFixture, addition_v2) {
	ASSERT_TRUE((one + negative_one) == noll) << "Проверка " << one << " + " << negative_one << " = " << noll;
}

TEST_F(ProcedureFixture, addition_v3) {
	ASSERT_TRUE((two + ten) == twelve) << "Проверка " << two << " + " << ten << " = " << twelve;
}



TEST_F(ProcedureFixture, subtract) {
	ASSERT_TRUE((one - negative_one) == two) << "Проверка " << one << " - " << negative_one << " = " << two;
}

TEST_F(ProcedureFixture, subtract_v2) {
	ASSERT_TRUE((twelve - ten) == two) << "Проверка " << twelve << " - " << ten << " = " << two;
}

TEST_F(ProcedureFixture, subtract_v3) {
	ASSERT_FALSE((three - two) == negative_one) << "Проверка " << three << " - " << two << " = " << negative_one;
}



TEST_F(ProcedureFixture, multiplication) {
	ASSERT_TRUE((one * noll) == noll) << "Проверка " << one << " * " << noll << " = " << noll;
}

TEST_F(ProcedureFixture, multiplication_v2) {
	ASSERT_TRUE((one * ten) == ten) << "Проверка " << one << " * " << ten << " = " << ten;
}

TEST_F(ProcedureFixture, multiplication_v3) {
	ASSERT_TRUE((three * two) == six) << "Проверка " << three << " * " << two << " = " << six;
}

TEST_F(ProcedureFixture, multiplication_v4) {
	ASSERT_TRUE((negative_one * two) == negative_two) << "Проверка " << negative_one << " * " << two << " = " << negative_two;
}



TEST_F(ProcedureFixture, division) {
	ASSERT_TRUE((noll / one) == noll) << "Проверка " << noll << " / " << one << " = " << noll;
}

TEST_F(ProcedureFixture, division_v2) {
	ASSERT_TRUE((twelve / six) == two) << "Проверка " << twelve << " / " << six << " = " << two;
}

TEST_F(ProcedureFixture, division_v3) {
	ASSERT_TRUE((two / negative_one) == negative_two) << "Проверка " << two << " / " << negative_one << " = " << negative_two;
}



TEST_F(ProcedureFixture, remainder_of_division) {
	ASSERT_TRUE((two / negative_one) == negative_two) << "Проверка " << two << " % " << negative_one << " = " << negative_two;
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}