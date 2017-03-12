// Liuwei_2View.h : interface of the CLiuwei_2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIUWEI_2VIEW_H__B7F08B0F_E503_4358_946C_63135ED030E1__INCLUDED_)
#define AFX_LIUWEI_2VIEW_H__B7F08B0F_E503_4358_946C_63135ED030E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLiuwei_2View : public CView
{
protected: // create from serialization only
	CLiuwei_2View();
	DECLARE_DYNCREATE(CLiuwei_2View)

// Attributes
public:
	CLiuwei_2Doc* GetDocument();
	CPoint m_ptStart;
	CPoint m_ptOld;
	CPoint m_pt1;
    CPoint m_pt2;
	CPoint m_pt3;
    CPoint m_pt4;
	CRect rect ;
	int m_drawType;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLiuwei_2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL


// Implementation
public:
	virtual ~CLiuwei_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	    
	//{{AFX_MSG(CLiuwei_2View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawBezil();
	afx_msg void OnDrawCircle();
	afx_msg void OnDrawDot();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRectangle();
	afx_msg void OnDrawSector();
	afx_msg void OnDrawTextout();
	afx_msg void OnDrawSix();
	afx_msg void OnDrawFive();
	afx_msg void OnDrawThree();
	afx_msg void OnDrawFour();
	afx_msg void OnUpdateXY(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
    afx_msg void OnSelectDrawType(UINT nID); 
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Liuwei_2View.cpp
inline CLiuwei_2Doc* CLiuwei_2View::GetDocument()
   { return (CLiuwei_2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIUWEI_2VIEW_H__B7F08B0F_E503_4358_946C_63135ED030E1__INCLUDED_)
