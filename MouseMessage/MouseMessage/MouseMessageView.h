
// MouseMessageView.h: CMouseMessageView 클래스의 인터페이스
//

#pragma once


class CMouseMessageView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMouseMessageView() noexcept;
	DECLARE_DYNCREATE(CMouseMessageView)

// 특성입니다.
public:
	CMouseMessageDoc* GetDocument() const;

// 작업입니다.
public:

	//Mouse
	//원 그리기
	BOOL m_bDrawMode; // 그리기 작업이 진행중임을 나타낸다.
	int m_x1, m_y1, m_x2, m_y2; // 타원에 외접하는 직사각형의 좌상단/우하단 좌표

	//MouseLeave
	BOOL m_bMouseIn;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMouseMessageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

#ifndef _DEBUG  // MouseMessageView.cpp의 디버그 버전
inline CMouseMessageDoc* CMouseMessageView::GetDocument() const
   { return reinterpret_cast<CMouseMessageDoc*>(m_pDocument); }
#endif

