// DiskDataTest.h: interface for the DiskDataTest class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISKDATATEST_H__A8FD9FB1_9875_4AA1_8363_0AEA24515729__INCLUDED_)
#define AFX_DISKDATATEST_H__A8FD9FB1_9875_4AA1_8363_0AEA24515729__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include <cppunit/TestCase.h>
//#include <cppunit/extensions/HelperMacros.h>

#include <D:/unittest/cppunit/include/cppunit/TestCase.h>
#include <D:/unittest/cppunit/include/cppunit/extensions/HelperMacros.h>

#include "TestData.h"


class DiskDataTestCase : public CppUnit::TestCase  
{
	CPPUNIT_TEST_SUITE(DiskDataTestCase);
		CPPUNIT_TEST(TestCase1);
		CPPUNIT_TEST(TestCase2);
		CPPUNIT_TEST(TestCase3);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

protected:
	void TestCase1();
	void TestCase2();
	void TestCase3();


private:
	TestData *fixture;

};

#endif // !defined(AFX_DISKDATATEST_H__A8FD9FB1_9875_4AA1_8363_0AEA24515729__INCLUDED_)
