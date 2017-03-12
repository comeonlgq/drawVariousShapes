// Liuwei_2.h : main header file for the LIUWEI_2 application
//

#if !defined(AFX_LIUWEI_2_H__F526A8A5_609A_4DED_8FF3_7FFCFEE2251D__INCLUDED_)
#define AFX_LIUWEI_2_H__F526A8A5_609A_4DED_8FF3_7FFCFEE2251D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2App:
// See Liuwei_2.cpp for the implementation of this class
//

class CLiuwei_2App : public CWinApp
{
public:
	CLiuwei_2App();
 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLiuwei_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLiuwei_2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIUWEI_2_H__F526A8A5_609A_4DED_8FF3_7FFCFEE2251D__INCLUDED_)
