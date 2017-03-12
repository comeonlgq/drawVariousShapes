// Liuwei_2Doc.cpp : implementation of the CLiuwei_2Doc class
//

#include "stdafx.h"
#include "Liuwei_2.h"

#include "Liuwei_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2Doc

IMPLEMENT_DYNCREATE(CLiuwei_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLiuwei_2Doc, CDocument)
	//{{AFX_MSG_MAP(CLiuwei_2Doc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2Doc construction/destruction

CLiuwei_2Doc::CLiuwei_2Doc()
{
	// TODO: add one-time construction code here

}

CLiuwei_2Doc::~CLiuwei_2Doc()
{
}

BOOL CLiuwei_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2Doc serialization

void CLiuwei_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2Doc diagnostics

#ifdef _DEBUG
void CLiuwei_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLiuwei_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2Doc commands

