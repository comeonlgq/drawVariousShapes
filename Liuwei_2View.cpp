// Liuwei_2View.cpp : implementation of the CLiuwei_2View class
//

#include "stdafx.h"
#include "Liuwei_2.h"
#include "MainFrm.h"

#include "Liuwei_2Doc.h"
#include "Liuwei_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View

IMPLEMENT_DYNCREATE(CLiuwei_2View, CView)

BEGIN_MESSAGE_MAP(CLiuwei_2View, CView)
	//{{AFX_MSG_MAP(CLiuwei_2View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(ID_LEFT,OnUpdateXY)
    ON_UPDATE_COMMAND_UI(ID_RIGHT,OnUpdateXY)
	ON_COMMAND(ID_DRAW_BEZIL, OnDrawBezil)
	ON_COMMAND(ID_DRAW_CIRCLE, OnDrawCircle)
	ON_COMMAND(ID_DRAW_DOT, OnDrawDot)
	ON_COMMAND(ID_DRAW_ELLIPSE, OnDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_RECTANGLE, OnDrawRectangle)
	ON_COMMAND(ID_DRAW_SECTOR, OnDrawSector)
	ON_COMMAND(ID_DRAW_TEXTOUT, OnDrawTextout)
	ON_COMMAND(ID_DRAW_SIX, OnDrawSix)
	ON_COMMAND(ID_DRAW_FIVE, OnDrawFive)
	ON_COMMAND(ID_DRAW_THREE, OnDrawThree)
	ON_COMMAND(ID_DRAW_FOUR, OnDrawFour)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View construction/destruction

CLiuwei_2View::CLiuwei_2View()
{
	// TODO: add construction code here
   m_drawType=0;
   m_pt1.x=0;
   m_pt1.y=0;
   m_pt2.x=0;
   m_pt2.y=0;
   m_pt3.x=0;
   m_pt3.y=0;
   m_pt4.x=0;
   m_pt4.y=0;
   rect=new CRect(0,0,0,0);
}

CLiuwei_2View::~CLiuwei_2View()
{

}

BOOL CLiuwei_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View drawing

void CLiuwei_2View::OnDraw(CDC* pDC)
{
	CLiuwei_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
   
}

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View printing

BOOL CLiuwei_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLiuwei_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLiuwei_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View diagnostics

#ifdef _DEBUG
void CLiuwei_2View::AssertValid() const
{
	CView::AssertValid();
}

void CLiuwei_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLiuwei_2Doc* CLiuwei_2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLiuwei_2Doc)));
	return (CLiuwei_2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLiuwei_2View message handlers


void CLiuwei_2View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    switch(m_drawType)
	{
	    case 1:
			 m_ptStart=point;
			 break;
		case 2:
		case 3:
		case 4:
		case 5:
			 m_ptStart = point;
		     m_ptOld= point;
		     SetCapture();
			 break;
	
	}
			 
    
	CView::OnLButtonDown(nFlags, point);
}



void CLiuwei_2View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptOld=point;
    ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CLiuwei_2View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	CMainFrame *pFrame=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus =&pFrame->m_wndStatusBar;


	CClientDC dc(this);
	switch(m_drawType)
	{
	    case 1:
			dc.SetPixel(m_ptOld,RGB(0,0,0));
			break;
        case 2:
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptOld);
			break;
		case 3:
			dc.Rectangle(CRect(m_ptStart,m_ptOld));
			break;
		case 4:
		case 5:
		
			rect.left = m_ptStart.x;
            rect.top =m_ptStart.y;
			rect.right = abs(m_ptOld.x-m_ptStart.x)+m_ptStart.x ;
			rect.bottom =abs(m_ptOld.x-m_ptStart.x)+m_ptStart.y;
			dc.Ellipse(&rect);
			break;

	}

	if(pStatus)
	{
		switch(m_drawType)
		{
			 case 1:
                	str.Format("画点");
					break;
			 case 2:
                    str.Format("画直线");
					break;
			 case 3:
				   str.Format("画矩形");
					break;
			 case 4:
				  str.Format("画圆");
					break;
			 case 5:
				  str.Format("画椭圆");
					break;
		    
		}
        pStatus->SetPaneText(1,str);
		str.Format("X=%d",point.x);
		pStatus->SetPaneText(2,str);
		str.Format("Y=%d",point.y);
		pStatus->SetPaneText(3,str);
	}
    CView::OnMouseMove(nFlags, point);
}



void CLiuwei_2View::OnDrawBezil() 
{
	// TODO: Add your command handler code here
	m_drawType = 8;
}

void CLiuwei_2View::OnDrawCircle() 
{
	// TODO: Add your command handler code here

	m_drawType = 4;
}

void CLiuwei_2View::OnDrawDot() 
{
	// TODO: Add your command handler code here

	m_drawType = 1;
}

void CLiuwei_2View::OnDrawEllipse() 
{
	// TODO: Add your command handler code here
	
	m_drawType = 5;
}

void CLiuwei_2View::OnDrawLine() 
{
	// TODO: Add your command handler code here

	m_drawType = 2;
}


void CLiuwei_2View::OnDrawRectangle() 
{
	// TODO: Add your command handler code here

	m_drawType = 3;
}

void CLiuwei_2View::OnDrawSector() 
{
	// TODO: Add your command handler code here

	m_drawType = 7;
}

void CLiuwei_2View::OnDrawTextout() 
{
	// TODO: Add your command handler code here

	m_drawType = 9;
}


void CLiuwei_2View::OnDrawSix() 
{
	// TODO: Add your command handler code here
	m_drawType = 13;
}
void CLiuwei_2View::OnDrawFive() 
{
	// TODO: Add your command handler code here
    m_drawType = 12;
}

void CLiuwei_2View::OnDrawThree() 
{
	// TODO: Add your command handler code here
	m_drawType = 10;

}

void CLiuwei_2View::OnDrawFour() 
{
	// TODO: Add your command handler code here
	m_drawType = 11;
}

void CLiuwei_2View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;//菜单
    CMenu* pPopupMenu;//菜单指针
	
	menu.LoadMenu(IDR_MENU1);//加载ID为IDR_MENU1的菜单

	
	pPopupMenu = menu.GetSubMenu(0);   //获取弹出菜单的第一层子菜单的类指针
	
	ClientToScreen(&point);//将鼠标单击处的坐标转换为屏幕坐标
	
	//弹出菜单函数，第一个参数表示快捷菜单的下边界与由参数y指定的坐标对齐 
	
	//第二和第三个为x、y坐标，第四个表示拥有此菜单的窗口句柄，
	
	//第五个默认为NULL,表示当用户在菜单以外的区域按鼠标键时，菜单会消失
	
	pPopupMenu->TrackPopupMenu(TPM_BOTTOMALIGN,point.x,point.y,this,NULL);
	CView::OnRButtonDown(nFlags, point);
}

void CLiuwei_2View::OnUpdateXY(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(TRUE); //使窗格文本能够被更新
}

