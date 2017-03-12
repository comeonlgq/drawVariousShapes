// Liuwei_2Doc.h : interface of the CLiuwei_2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIUWEI_2DOC_H__8CE88851_3AC6_4F35_B1A4_250540D310B0__INCLUDED_)
#define AFX_LIUWEI_2DOC_H__8CE88851_3AC6_4F35_B1A4_250540D310B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLiuwei_2Doc : public CDocument
{
protected: // create from serialization only
	CLiuwei_2Doc();
	DECLARE_DYNCREATE(CLiuwei_2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLiuwei_2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLiuwei_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLiuwei_2Doc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIUWEI_2DOC_H__8CE88851_3AC6_4F35_B1A4_250540D310B0__INCLUDED_)
