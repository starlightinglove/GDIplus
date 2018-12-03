
// GDIplusView.h: CGDIplusView 클래스의 인터페이스
//

#pragma once


class CGDIplusView : public CView
{
protected: // serialization에서만 만들어집니다.
	CGDIplusView() noexcept;
	DECLARE_DYNCREATE(CGDIplusView)

// 특성입니다.
public:
	CGDIplusDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CGDIplusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // GDIplusView.cpp의 디버그 버전
inline CGDIplusDoc* CGDIplusView::GetDocument() const
   { return reinterpret_cast<CGDIplusDoc*>(m_pDocument); }
#endif

