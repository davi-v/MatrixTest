#include <Mat.hpp>
#include <gtest/gtest.h>

typedef Mat<int, 3, 3> mat3i;
typedef Mat<double, 2, 2> mat2d;

TEST(MatrixTest, ZeroInitialized)
{
	mat3i m1;
	mat3i m2{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	EXPECT_EQ(m1, m2);
}

TEST(MatrixTest, Equal)
{
	mat2d m1{ 2., 56., 4., 3. };
	mat2d m2{ 2., 56., 4., 3. };
	EXPECT_EQ(m1, m2);
}

TEST(MatrixTest, Different)
{
	mat2d m1{ 2., 56., 4., 3. };
	mat2d m2{ 2., 56., 3., 3. };
	EXPECT_NE(m1, m2);
}

TEST(MatrixTest, Multiply3333)
{
	mat3i m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	);
	mat3i m2(
		1, 6, 3,
		1, 6, 3,
		1, 6, 3
	);
	mat3i res{
		6, 36, 18,
		15, 90, 45,
		24, 144, 72
	};
	EXPECT_EQ(m1 * m2, (mat3i{
		6, 36, 18,
		15, 90, 45,
		24, 144, 72
		}));
}

TEST(MatrixTest, Multiply1224)
{
	typedef Mat<int, 1, 2> m12;
	typedef Mat<int, 2, 4> m24;
	typedef Mat<int, 1, 4> m14;
	m12 m1{
		1, 2
	};
	m24 m2{
		2, 6, 5, 2,
		6, 8, 88, 2
	};
	EXPECT_EQ(m1 * m2, (m14{
		14, 22, 181, 6
		}));
}