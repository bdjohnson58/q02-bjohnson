/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(PiezasTest, BoardStartsBlank)
{
	Piezas test;
	for(int i=0; i< BOARD_COLS; i++)
	{
		for(int j=0; j<BOARD_ROWS; j++)
		{
			EXPECT_EQ(test.pieceAt(j,i), Blank);
		}
	}
	
	
}
TEST(PiezasTest, CheckReset)
{
	Piezas test;
	for(int i=0; i< BOARD_COLS; i++)
	{
		for(int j=0; j<BOARD_ROWS; j++)
		{
			test.dropPiece(i);
		}
	}
	test.reset();
	for(int i=0; i< BOARD_COLS; i++)
	{
		for(int j=0; j<BOARD_ROWS; j++)
		{
			EXPECT_EQ(test.pieceAt(j,i), Blank);
		}
	}

}


TEST(PiezasTest, toggleTurnCheck)
{
	Piezas test;
	test.dropPiece(1);
	test.dropPiece(1);
	test.dropPiece(1);
	ASSERT_EQ(test.pieceAt(0,1),X);
	ASSERT_EQ(test.pieceAt(1,1),O);
	ASSERT_EQ(test.pieceAt(2,1),X);
}

TEST(PiezasTest, FullColumnReturnsBlank)
{
	Piezas test;
	test.dropPiece(1);
	test.dropPiece(1);
	test.dropPiece(1);
	Piece check = test.dropPiece(1);
	ASSERT_EQ(check, Blank);

}

TEST(PiezasTest, OutofBoundsDrop)
{
	Piezas test;
	Piece check = test.dropPiece(-1);
	ASSERT_EQ(check, Invalid);
	test.dropPiece(1);
	ASSERT_EQ(test.pieceAt(0,1), O);
	check = test.dropPiece(4);
	ASSERT_EQ(check, Invalid);
	
}

TEST(PiezasTest, dropPieceReturnsPiece)
{
	Piezas test;
	Piece check = test.dropPiece(1);
	ASSERT_EQ(check, X);
}

TEST(PiezasTest, PieceAtOutOfBoundsCheck)
{
	Piezas test;
	Piece check1 = test.pieceAt(-1,0);
	Piece check2 = test.pieceAt(3,0);
	Piece check3 = test.pieceAt(0,-1);
	Piece check4 = test.pieceAt(0,4);
	ASSERT_EQ(check1, Invalid);
	ASSERT_EQ(check2, Invalid);
	ASSERT_EQ(check3, Invalid);
	ASSERT_EQ(check4, Invalid);

}
