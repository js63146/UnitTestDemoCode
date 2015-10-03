// DiskDataTest.cpp: implementation of the DiskDataTest class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestDataTestCase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


/*---------------------------
Visa gets 10%
MC gets 5% interest
Discover gets 1% interest
 
Each Card Type can have multiple cards and there can be multiple Wallets for a Person. 
 
NOTE:  SIMPLE INTEREST for this test case (means 1 month of interest, if the interest rate is 10% and the amount is 100.00 – interest in this case would be 10.00) 


Here are the test Cases - 
 
1.	1 person has 1 wallet and 3 cards (1 Visa, 1 MC 1 Discover) – 
         Each Card has a balance of $100 – calculate the total interest (simple interest) for this person and per card. 

2.	1 person has 2 wallets  Wallet 1 has a Visa and Discover , wallet 2 a MC -  each card has $100 balance
        - calculate the total interest(simple interest) for this person and interest per wallet

3.	2 people have 1 wallet each,  person 1 has 1 wallet , with 2 cards MC and visa person 2 has 1 wallet – 1 visa and 1 MC -  		each card has $100 balance -  calculate the total interest(simple interest) for each person and interest per wallet
*---------------------------/

#define INTERESET_VISA_100	10
#define INTERESET_MC_100	5
#define INTERESET_DISCOVER_100	1




CPPUNIT_TEST_SUITE_REGISTRATION(DiskDataTestCase);


void DiskDataTestCase::setUp()
{
	//fixture = new TestData();
}
 
void DiskDataTestCase::tearDown()
{
	//delete fixture;
	//fixture = NULL;
}


//========================================================================================================================
//1.	1 person has 1 wallet and 3 cards (1 Visa, 1 MC 1 Discover) – 
//         Each Card has a balance of $100 – calculate the total interest (simple interest) for this person and per card. 
//========================================================================================================================
void DiskDataTestCase::TestCase1()
{
	CString str;
	int	nVisaInterest;
	int	nMCInterest;
	int	nDiscoverInterest;
	int 	nSum;

	GetInterest Get_Interest;
	CreditCardInterestBuilder* pVisaCreditCardInterestBuilder = new VisaCreditCardInterestBuilder;
	CreditCardInterestBuilder* pMCCreditCardInterestBuilder   = new MCCreditCardInterestBuilder;
	CreditCardInterestBuilder* pDiscoverCreditCardInterestBuilder = new DiscoverCreditCardInterestBuilder;

	Get_Interest.CreditCardInterestBuilder(pVisaCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nVisaInterest = Get_Interest.getInterest(100);
	if ( nVisaInterest == INTERESET_VISA_100 )
		str.Format(L"Visa Interest of 100 is %d. passed", nVisaInterest )
	else
		str.Format(L"Visa Interest of 100 test fails.")
	CPPUNIT_ASSERT_MESSAGE(str);

	Get_Interest.CreditCardInterestBuilder(pMCCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nMCInterest = Get_Interest.getInterest(100);
	if ( nMCInterest == INTERESET_MC_100 )
		str.Format(L"MC Interest of 100 is %d. passed", nMCInterest )
	else
		str.Format(L"MC Interest of 100 test fails." )
	CPPUNIT_ASSERT_MESSAGE(str);

	Get_Interest.CreditCardInterestBuilder(pDiscoverCreditCardInterestBuilder );
	Get_Interest.constructCreditCardInteres();
	nDiscoverInterest = Get_Interest.getInterest(100);
	if ( nDiscoverInterest == INTERESET_DISCOVER_100 )
		str.Format(L"Discover Interest of 100 is %d. passed", nDiscoverInterest )
	els
		str.Format(L"Discover Interest of 100 test fails.");
	CPPUNIT_ASSERT_MESSAGE(str);
 
	nSum =  nVisaInterest +  nMCInterest + nDiscoverInterest;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100+INTERESET_DISCOVER_100 ) )
		str.Format(L"Visa Interest of 3 cards is %d. passed", nSum )
	else
		str.Format(L"TotalInterest of 3 cards test fails.");
	CPPUNIT_ASSERT_MESSAGE(str);


	delete pVisaCreditCardInterestBuilder;
	delete pMCCreditCardInterestBuilder;
	delete pDiscoverCreditCardInterestBuilder;  

	
}

//===================================================================================================================
//
//2.	1 person has 2 wallets  Wallet 1 has a Visa and Discover , wallet 2 a MC -  each card has $100 balance
//        - calculate the total interest(simple interest) for this person and interest per wallet
//===================================================================================================================
void DiskDataTestCase::TestCase2()
{	
	CString str;
	int	nVisaInterest;
	int	nMCInterest;
	int	nDiscoverInterest;
	int 	nSum;

	GetInterest Get_Interest;
	CreditCardInterestBuilder* pVisaCreditCardInterestBuilder = new VisaCreditCardInterestBuilder;
	CreditCardInterestBuilder* pMCCreditCardInterestBuilder   = new MCCreditCardInterestBuilder;
	CreditCardInterestBuilder* pDiscoverCreditCardInterestBuilder = new DiscoverCreditCardInterestBuilder;

	Get_Interest.CreditCardInterestBuilder(pVisaCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nVisaInterest = Get_Interest.getInterest(100);
	

	Get_Interest.CreditCardInterestBuilder(pMCCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nMCInterest = Get_Interest.getInterest(100);
	
	Get_Interest.CreditCardInterestBuilder(pDiscoverCreditCardInterestBuilder );
	Get_Interest.constructCreditCardInteres();
	nDiscoverInterest = Get_Interest.getInterest(100);
 
	nSum =  nVisaInterest +  nMCInterest + nDiscoverInterest;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100+INTERESET_DISCOVER_100 ) )
		str.Format(L"Visa Interest of 100 is %d. passed", nSum )
	else
		str.Format(L"TotalInterest of 3 cards test fails.");
	CPPUNIT_ASSERT_MESSAGE(str);

	// wallets 1
	nSum = nVisaInterest +  nDiscoverInterest;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_DISCOVER_100 ) )
		str.Format(L"Wallet 1 Interest is %d. passed", nSum );
	else
		str.Format(L"Wallets 1 Interest test fails" );
	CPPUNIT_ASSERT_MESSAGE(str);
	
	if ( nMCInterest == INTERESET_MC_100 )
		str.Format(L"Wallet 2 Interest of s %d. passed", nMCInterest );
	else
		str.Format(L"Wallet 2 Interest test fails." )
	CPPUNIT_ASSERT_MESSAGE(str);


	delete pVisaCreditCardInterestBuilder;
	delete pMCCreditCardInterestBuilder;
	delete pDiscoverCreditCardInterestBuilder;  
}

//============================================================================================================================
//
//3.	2 people have 1 wallet each,  person 1 has 1 wallet , with 2 cards MC and visa 
//	person 2 has 1 wallet – 1 visa and 1 MC - each card has 
//	$100 balance -  calculate the total interest(simple interest) for each person and interest per wallet
================================================================================================================================

void DiskDataTestCase::TestCase3()
{
	CString str;
	int	nPerson1VisaInterest;
	int	nPerson1MCInterest;

	int	nPerson2VisaInterest;
	int	nPerson2MCInterest;

	int	nDiscoverInterest;
	int 	nSum;

	GetInterest Get_Interest;
	CreditCardInterestBuilder* pVisaCreditCardInterestBuilder = new VisaCreditCardInterestBuilder;
	CreditCardInterestBuilder* pMCCreditCardInterestBuilder   = new MCCreditCardInterestBuilder;
	CreditCardInterestBuilder* pDiscoverCreditCardInterestBuilder = new DiscoverCreditCardInterestBuilder;

	Get_Interest.CreditCardInterestBuilder(pVisaCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nPerson1VisaInterest = nPerson2VisaInterest = Get_Interest.getInterest(100);
	

	Get_Interest.CreditCardInterestBuilder(pMCCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	nPerson1MCInterest = nPerson2MCInterest = Get_Interest.getInterest(100);
	
	Get_Interest.CreditCardInterestBuilder(pDiscoverCreditCardInterestBuilder );
	Get_Interest.constructCreditCardInteres();
	nDiscoverInterest = Get_Interest.getInterest(100);
 
	nSum =  nPerson1VisaInterest +  nPerson1MCInterest ;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100 ) )
		str.Format(L"Personal 1 Interest is %d. passed", nSum )
	else
		str.Format(L"Person 1 Interest test fails.");
	CPPUNIT_ASSERT_MESSAGE(str);

	nSum =  nPerson2VisaInterest +  nPerson2MCInterest ;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100 ) )
		str.Format(L"Personal 2 Interest is %d. passed", nSum )
	else
		str.Format(L"Person 2 Interest test fails.");
	CPPUNIT_ASSERT_MESSAGE(str);

	// wallets 1
	nSum =  nPerson1VisaInterest +  nPerson1MCInterest ;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100 ) )
		str.Format(L"Person1 Wallet Interest is %d. passed", nSum );
	else
		str.Format(L"Person1 Wallets Interest test fails" );
	CPPUNIT_ASSERT_MESSAGE(str);
	
	nSum =  nPerson2VisaInterest +  nPerson2MCInterest ;
	if ( nSum == ( INTERESET_VISA_100+INTERESET_MC_100 ) )
		str.Format(L""Person2 Wallets Interest of s %d. passed", nMCInterest );
	else
		str.Format(L""Person2 Wallets Interest test fails." )
	CPPUNIT_ASSERT_MESSAGE(str);


	delete pVisaCreditCardInterestBuilder;
	delete pMCCreditCardInterestBuilder;
	delete pDiscoverCreditCardInterestBuilder;  
}
