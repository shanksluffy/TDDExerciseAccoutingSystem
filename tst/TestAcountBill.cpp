#include <gtest/gtest.h>

#include "Account.hpp"

class TestAccount : public ::testing::Test{
};


TEST(TestAccount, GivenGoldAcountWithOneLineShallHaveMainLineCost)
{
  Account account = Account(Gold);
  double bill = account.Bill(1);
  EXPECT_DOUBLE_EQ(GoldBasicRate, bill);
}

TEST(TestAccount, GivenGoldAccountWithTwoLinesShallHaveMainLineCostPlusAdditionalLineCost)
{
  Account account = Account(Gold);
  double bill = account.Bill(2);

  EXPECT_DOUBLE_EQ(GoldBasicRate + GoldAdditionRate, bill);
}


TEST(TestAccount, GivenSilverAccountWithOneLineShallHaveMainLineCost)
{
  Account account = Account(Silver);
  double bill = account.Bill(1);
  
  EXPECT_DOUBLE_EQ(SilverBasicRate, bill);
}

TEST(TestAccount, GivenSliverAccountWithMultLinesShallHaveMainLineCostPlusMoreAdditionLineCost){
  Account account = Account(Silver);
  double bill = account.Bill(3);
  
  EXPECT_DOUBLE_EQ((2*SilverAdditionRate) + SilverBasicRate, bill);
}


TEST(TestAccount, GoldAccountMinutesUsedInQuota)
{
  Account account = Account(Gold);
  double bill = account.Bill(1, GoldQuota - 1);

  EXPECT_DOUBLE_EQ(GoldBasicRate, bill);
}

TEST(TestAccount, GoldAccountMinutesExceedQuotaShallPlusExceedFee)
{
  Account account = Account(Gold);
  double bill = account.Bill(1, GoldQuota + 1);

  EXPECT_DOUBLE_EQ(GoldBasicRate + GoldExceedMinutesRate, bill);
  EXPECT_DOUBLE_EQ(GoldBasicRate + (10 * GoldExceedMinutesRate), account.Bill(1, GoldQuota + 10));
}



