
// MouseMessageView.cpp: CMouseMessageView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MouseMessage.h"
#endif

#include "MouseMessageDoc.h"
#include "MouseMessageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseMessageView

IMPLEMENT_DYNCREATE(CMouseMessageView, CView)

BEGIN_MESSAGE_MAP(CMouseMessageView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

// CMouseMessageView 생성/소멸

CMouseMessageView::CMouseMessageView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	//Mouse
	//원 그리기
	m_bDrawMode = FALSE;

	//MouseLeave
	m_bMouseIn = FALSE;
}

CMouseMessageView::~CMouseMessageView()
{
}

BOOL CMouseMessageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMouseMessageView 그리기

void CMouseMessageView::OnDraw(CDC* /*pDC*/)
{
	CMouseMessageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMouseMessageView 진단

#ifdef _DEBUG
void CMouseMessageView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseMessageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseMessageDoc* CMouseMessageView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseMessageDoc)));
	return (CMouseMessageDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseMessageView 메시지 처리기


void CMouseMessageView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//Mouse
	//원 그리기
	/*
	//그리기모드를 시작한다.
	m_bDrawMode = TRUE;
	//좌표를 저장한다.
	m_x1 = m_x2 = point.x;
	m_y1 = m_y2 = point.y;


	//마우스 캡처를 시작한다.
	SetCapture();
	*/


	CView::OnLButtonDown(nFlags, point);
}


void CMouseMessageView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//Mouse
	//원 그리기
	/*
	if (m_bDrawMode) {
		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);

		//이전에 그린 타원을 지운다.
		dc.SetROP2(R2_XORPEN);
		dc.SelectStockObject(WHITE_PEN);
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);

		//새로운 타원을 그린다.
		m_x2 = point.x;
		m_y2 = point.y;
		dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	}
	*/

	if (m_bMouseIn == FALSE) {
		//마우스 커서 추적을 요청한다
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.hwndTrack = this->m_hWnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		::TrackMouseEvent(&tme);

		//메인 윈도우크기를 300*150으로 변경한다.
		CWnd* pMainWnd = AfxGetMainWnd();
		CRect rect;
		pMainWnd->GetWindowRect(&rect);
		rect.right = rect.left + 500;
		rect.bottom = rect.top + 250;
		pMainWnd->MoveWindow(&rect);

		//마우스 커서가 클라이언트 영역에 있음을 표시한다.
		m_bMouseIn = TRUE;
	}

	CView::OnMouseMove(nFlags, point);
}


void CMouseMessageView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//Mouse
	//원 그리기
	/*
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);

	//최종적인 타원을 그린다.
	m_x2 = point.x;
	m_y2 = point.y;
	dc.Ellipse(m_x1, m_y1, m_x2, m_y2);

	//그리기 모드를 끝낸다.
	m_bDrawMode = FALSE;


	//마우스 캡처를 해제한다.
	::ReleaseCapture();
	*/

	CView::OnLButtonUp(nFlags, point);

}


void CMouseMessageView::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//MouseLeave
	//마우스 커서가 클라이언트 영역 밖에 있음을 표시한다.
	m_bMouseIn = FALSE;

	//메인윈도우 크기를 200*100으로 변경한다.
	CWnd* pMainWnd = AfxGetMainWnd();
	CRect rect;
	pMainWnd->GetWindowRect(&rect);
	rect.right = rect.left + 200;
	rect.bottom = rect.top + 500;
	pMainWnd->MoveWindow(&rect);

	CView::OnMouseLeave();
}
