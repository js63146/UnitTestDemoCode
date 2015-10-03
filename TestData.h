// DiskData.h: interface for the DiskData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISKDATA_H__02686765_6D2B_480A_8BF7_5E0510FCCA3F__INCLUDED_)
#define AFX_DISKDATA_H__02686765_6D2B_480A_8BF7_5E0510FCCA3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <string>
#include <iostream>

using namespace std;

// "Product"
class CreditCardInterest 
{
	public:
		void setInterest(float fInterest)
		{
			m_fInterest = fInterest;
		}
		
		int CalcInterest(int iAmount) const
		{
			return iAmount * m_fInterest;
		}

	private:
		float m_fInterest;
		
};

// "Abstract Builder"
class CreditCardInterestBuilder
{
	public:
                virtual ~CreditCardInterestBuilder() {}; 

		//CreditCardInterest * getCreditCardInterest ()
		//{
		//	return m_fInterest;
		//}
		void createNewCreditCardInterestProduct()
		{
			m_CreditCardInterest = new CreditCardInterest;
		}
		virtual void buildCreditCardInterest() = 0;
		virtual int CalcCreditCardInterest() = 0;

	protected:
		CreditCardInterest * m_CreditCardInterest;
};

class VisaCreditCardInterestBuilder : public CreditCardInterestBuilder
{
	public:
        virtual ~VisaCreditCardInterestBuilder() {}; 

		virtual void buildCreditCardInterest()
		{
			m_CreditCardInterest->setInterest(0.1);
		}

		virtual void CalcCreditCardInterest(int iAmount)
		{
			m_CreditCardInterest->CalcInterest(iAmount);
		}
		
};

class MCCreditCardInterestBuilder : public CreditCardInterestBuilder
{
	public:
        virtual ~MCCreditCardInterestBuilder() {}; 

		virtual void buildCreditCardInterest()
		{
			m_CreditCardInterest->setInterest(0.05);
		}

		virtual void CalcCreditCardInterest(int iAmount)
		{
			m_CreditCardInterest->CalcInterest(iAmount);
		}
		
};

class DiscoverCreditCardInterestBuilder : public CreditCardInterestBuilder
{
	public:
        virtual ~DiscoverCreditCardInterestBuilder() {}; 

		virtual void buildCreditCardInterest()
		{
			m_CreditCardInterest->setInterest(0.01);
		}

		virtual void CalcCreditCardInterest(int iAmount)
		{
			m_CreditCardInterest->CalcInterest(iAmount);
		}
		
};

class GetInterest 
{
	public:
		void setCreditCardInterestBuilder(CreditCardInterestBuilder* pb)
		{
			m_CreditCardInterestBuilder = pb;
		}
	

		int getIntereset(int iAmount)
		{
			return m_CreditCardInterestBuilder->CalcInterest(int iAmount);
		}

		void constructCreditCardInteres()	
		{
			m_CreditCardInterestBuilder->createNewCreditCardInterestProduct;
			m_CreditCardInterestBuilder->buildCreditCardInterest();	
		}

	private:
		CreditCardInterestBuilder* m_CreditCardInterestBuilder;
};

#ifdef REF_CODE
int main()
{
	GetInterest Get_Interest;
	CreditCardInterestBuilder* pVisaCreditCardInterestBuilder = new VisaCreditCardInterestBuilder;
	CreditCardInterestBuilder* pMCCreditCardInterestBuilder   = new MCCreditCardInterestBuilder;
	CreditCardInterestBuilder* pDiscoverCreditCardInterestBuilder = new DiscoverCreditCardInterestBuilder;
	
	Get_Interest.CreditCardInterestBuilder(pVisaCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	Get_Interest.getInterest(100);

	Get_Interest.CreditCardInterestBuilder(pMCCreditCardInterestBuilder);
	Get_Interest.constructCreditCardInteres();
	Get_Interest.getInterest(100);

	Get_Interest.CreditCardInterestBuilder(pDiscoverCreditCardInterestBuilder );
	Get_Interest.constructCreditCardInteres();
	Get_Interest.getInterest(100);
	
	
	
	delete pVisaCreditCardInterestBuilder;
	delete pMCCreditCardInterestBuilder;
	delete pDiscoverCreditCardInterestBuilder;  
	
};
#endif


#endif // !defined(AFX_DISKDATA_H__02686765_6D2B_480A_8BF7_5E0510FCCA3F__INCLUDED_)
