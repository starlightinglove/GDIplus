﻿
// KeyBoardView.cpp: CKeyBoardView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "KeyBoard.h"
#endif

#include "KeyBoardDoc.h"
#include "KeyBoardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyBoardView

IMPLEMENT_DYNCREATE(CKeyBoardView, CView)

BEGIN_MESSAGE_MAP(CKeyBoardView, CView)
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CKeyBoardView 생성/소멸

CKeyBoardView::CKeyBoardView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	//방향키로 사각형 움직이기
	/*
	m_xPos = m_yPos = 60;
	m_bFill = FALSE;
	*/
}

CKeyBoardView::~CKeyBoardView()
{
}

BOOL CKeyBoardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CKeyBoardView 그리기

void CKeyBoardView::OnDraw(CDC* /*pDC*/)
{
	CKeyBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CKeyBoardView 진단

#ifdef _DEBUG
void CKeyBoardView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyBoardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyBoardDoc* CKeyBoardView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyBoardDoc)));
	return (CKeyBoardDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyBoardView 메시지 처리기


void CKeyBoardView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	//방향키로 사각형 움직이기
	/*
	CBrush brush, *pOldBrush;
	if (m_bFill == TRUE) {
		brush.CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		pOldBrush = dc.SelectObject(&brush);
	}
	dc.Rectangle(m_xPos - 20, m_yPos - 20, m_xPos + 20, m_yPos + 20);

	if (m_bFill)
		dc.SelectObject(pOldBrush);
		*/

	//글자 표시하기
	/**/
	//화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreatePointFont(150, _T("Arial"));
	dc.SelectObject(&font);

	//현재까지 입력된 글자들을 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
	SIZE sizex, sizey;
	::GetTextExtentPoint(dc.m_hDC, m_strTemp.GetData(), m_strTemp.GetSize(), &sizex);
	::GetTextExtentPoint(dc.m_hDC, m_str.GetData(), m_str.GetSize(), &sizey);
	SetCaretPos(CPoint(sizex.cx, m_nLine*sizey.cy));

}


void CKeyBoardView::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//캐럿 사용하기
	/*
	CreateSolidCaret(20, 20);//캐럿 생성
	SetCaretPos(CPoint(50, 50));//캐럿의 위치를 설정
	ShowCaret();//캐럿을 화면에 보인다.
	*/
}


void CKeyBoardView::OnKillFocus(CWnd* pNewWnd)
{
	CView::OnKillFocus(pNewWnd);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//캐럿 사용하기
	/*
	HideCaret();//캐럿을 숨긴다.
	::DestroyCaret();//캐럿을 파괴한다.
	*/
}


void CKeyBoardView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	//방향키로 사각형 움직이기
	/*
	m_xMax = cx;
	m_yMax = cy;
	*/
}


void CKeyBoardView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//방향키로 사각형 움직이기
	/*
	switch (nChar) {
	case VK_LEFT:
		m_xPos -= 20;
		break;
	case VK_RIGHT:
		m_xPos += 20;
		break;
	case VK_UP:
		m_yPos -= 20;
		break;
	case VK_DOWN:
		m_yPos += 20;
		break;
		case
		VK_SPACE:
			m_bFill = !m_bFill;
	}
	m_xPos = min(max(20, m_xPos), m_xMax - 20);
	m_yPos = min(max(20, m_yPos), m_yMax - 20);
	Invalidate(FALSE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	*/
}


int CKeyBoardView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	//글자 표시하기
	/**/
	CreateSolidCaret(20, 20); //캐럿을 생성한다.
	SetCaretPos(CPoint(50, 50));
	ShowCaret();
	m_nLine = 0;

	return 0;
}


void CKeyBoardView::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//글자 표시하기
	/**/
	HideCaret(); //캐럿을 숨긴다.
	::DestroyCaret(); //캐럿을 파괴한다

	CView::OnClose();
}


void CKeyBoardView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//글자 표시하기
	/**/
	//Backspace 입력시 맨 마지막 글자를 삭제한다.
	if (nChar == VK_BACK) {
		if (m_str.GetSize() > 0) {
			m_str.RemoveAt(m_str.GetSize() - 1);
			m_strTemp.RemoveAt(m_strTemp.GetSize() - 1);
		}
	}
	else if (nChar == VK_RETURN) {
		CClientDC dc(this);
		m_nLine++;
		m_str.Add(nChar);
		m_strTemp.RemoveAll();
	}
	//그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else {
		m_str.Add(nChar);
		m_strTemp.Add(nChar);
	}
	//화면을 갱신한다.
	Invalidate();


	CView::OnChar(nChar, nRepCnt, nFlags);
}
