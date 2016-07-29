#include <gtest/gtest.h>
#include "MonthPhoneBill.hpp"

class MonthPhoneBillTest : public ::testing::Test{
public:
  void SetUp(){
    //code here be executed before test case
  }

  void TearDown(){
    //Code here be executed after test case
  }
};

/*TEST(TestGame, startFromHere)
{
  FAIL()<<"start from here!";
}*/

TEST(MonthPhoneBillTest, ChooseGolgenWithOneLine)
{
  EPLAN_TYPE plantype = EPLAN_TYPE_GOLDEN;
  u32 linnum = 1;
  MonthPhoneBill mBill(plantype, linnum);
  double monthbill = mBill.GetMonthBill();
  EXPECT_EQ(49.95, monthbill);
}

TEST(MonthPhoneBillTest, ChooseGolgenWithTwoLine)
{
  EPLAN_TYPE plantype = EPLAN_TYPE_GOLDEN;
  u32 linnum = 2;
  MonthPhoneBill mBill(plantype, linnum);
  double monthbill = mBill.GetMonthBill();
  EXPECT_EQ(49.95 + 14.50, monthbill);
}

TEST(MonthPhoneBillTest, ChooseSilverWithOneLine)
{
  EPLAN_TYPE plantype = EPLAN_TYPE_SILVER;
  u32 linnum = 1;
  MonthPhoneBill mBill(plantype, linnum);
  double monthbill = mBill.GetMonthBill();
  EXPECT_EQ(29.95, monthbill);
}

TEST(MonthPhoneBillTest, ChooseGolgenWithThreeLine)
{
  EPLAN_TYPE plantype = EPLAN_TYPE_SILVER;
  u32 linnum = 3;
  MonthPhoneBill mBill(plantype, linnum);
  double monthbill = mBill.GetMonthBill();
  EXPECT_EQ(29.95 + 21.50*2, monthbill);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
