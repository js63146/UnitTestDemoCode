// my_tests.cpp : Defines the class behaviors for the application.
//

//#include "stdafx.h"
#include "my_tests.h"

//#include <cppunit/ui/mfc/TestRunner.h>
//#include <cppunit/extensions/TestFactoryRegistry.h>
#include <D:/unittest/cppunit/include/msvc6/testrunner/TestRunner.h>
#include <D:/unittest/cppunit/include/cppunit/extensions/TestFactoryRegistry.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy_testsApp

BEGIN_MESSAGE_MAP(CMy_testsApp, CWinApp)
	//{{AFX_MSG_MAP(CMy_testsApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy_testsApp construction

CMy_testsApp::CMy_testsApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMy_testsApp object

CMy_testsApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMy_testsApp initialization

BOOL CMy_testsApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    // declare a test runner, fill it with our registered tests and run them
    CppUnit::MfcUi::TestRunner runner;

    runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );

    runner.run();    

    return TRUE;
}
