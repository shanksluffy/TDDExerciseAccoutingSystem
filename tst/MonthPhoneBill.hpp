#include <iostream>
using namespace std;

enum EPLAN_TYPE
 {
   EPLAN_TYPE_GOLDEN,
   EPLAN_TYPE_SILVER
 };
typedef unsigned int u32;

const double GoldenBasicRate = 49.95;
const double GoldenAddtionalRatePerLine = 14.50;
const double SilverBasicRate = 29.95;
const double SilverAddtionalRatePerLine = 21.50;

class MonthPhoneBill
{
  private:
  EPLAN_TYPE m_plantype;
  u32 m_linenum;
 
  public:
  MonthPhoneBill(EPLAN_TYPE plantype, u32 linenum):m_plantype(plantype),m_linenum(linenum){}
  double GetMonthBill()
  {
    switch(m_plantype)
	{
	  case EPLAN_TYPE_GOLDEN:
	     return (GoldenBasicRate + GoldenAddtionalRatePerLine*(m_linenum - 1));
	  case EPLAN_TYPE_SILVER:
	     return (SilverBasicRate + SilverAddtionalRatePerLine*(m_linenum - 1));
	  default:
	     cout<<"invalid plantype parameter!";
		 return 0;
	}
  }
};
