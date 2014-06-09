#include "stdafx.h"

#include "TestHarness.h"

#include "ranged_number.h"

TEST(cTor, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 5;
	//CHECK_EQUAL(5, grade);
	CHECK_EQUAL(grade, 5);
}

TEST(preIncrement, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 5;
	//CHECK_EQUAL(5, grade);
	CHECK_EQUAL(grade, 5);

	++grade;
	//CHECK_EQUAL(6, grade);
	CHECK_EQUAL(grade, 6);
}

TEST(preIncrementConstraint, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 12;
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);

	++grade;
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);
}

TEST(postIncrementConstraint, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 12;
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);

	grade++;
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);

}

TEST(preDecrementConstraint, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 1;
	//CHECK_EQUAL(1, grade);
	CHECK_EQUAL(grade, 1);

	--grade;
	//CHECK_EQUAL(1, grade);
	CHECK_EQUAL(grade, 1);

}

TEST(postDecrementConstraint, ranged_number)
{
	ranged_number<short, 1, 12> grade;

	grade = 1;
	//CHECK_EQUAL(1, grade);
	CHECK_EQUAL(grade, 1);

	grade--;
	//CHECK_EQUAL(1, grade);
	CHECK_EQUAL(grade, 1);
}

typedef ranged_number<int, 1, 12> Grade;

TEST(operatorPlus, ranged_number)
{
	Grade grade = 5;

	grade = grade + Grade(5);
	//CHECK_EQUAL(10, grade);
	CHECK_EQUAL(grade, 10);

	grade = grade + Grade(5);
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);
}

TEST(operatorPlusEquals, ranged_number)
{
	Grade grade = 5;

	grade += 5;
	//CHECK_EQUAL(10, grade);
	CHECK_EQUAL(grade, 10);

	grade += 5;
	//CHECK_EQUAL(12, grade);
	CHECK_EQUAL(grade, 12);
}
/**/