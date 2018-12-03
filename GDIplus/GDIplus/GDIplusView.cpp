
// GDIplusView.cpp: CGDIplusView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GDIplus.h"
#endif

#include "GDIplusDoc.h"
#include "GDIplusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIplusView

IMPLEMENT_DYNCREATE(CGDIplusView, CView)

BEGIN_MESSAGE_MAP(CGDIplusView, CView)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGDIplusView 생성/소멸

CGDIplusView::CGDIplusView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGDIplusView::~CGDIplusView()
{
}

BOOL CGDIplusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGDIplusView 그리기

void CGDIplusView::OnDraw(CDC* pDC)
{
	CGDIplusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//GDIplus를 사용하기 위한 추가
	//선 그리기
	/*
	Graphics graphics(pDC->m_hDC);
	Pen pen(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256), 4);
	SolidBrush brush(Color(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
	graphics.DrawLine(&pen, 50, 50, 500, 50);
	graphics.DrawRectangle(&pen, 50, 100, 200, 100);
	graphics.FillRectangle(&brush, 300, 100, 200, 100);
	graphics.DrawEllipse(&pen, 50, 250, 200, 200);
	graphics.FillEllipse(&brush, 300, 250, 200, 200);
	graphics.DrawPie(&pen, 550, 100, 200, 200, 225, 90);
	graphics.FillPie(&brush, 550, 300, 200, 200, 225, 90);
	graphics.DrawArc(&pen, 800, 100, 200, 200, 225, 90);
	*/

	//다각형과 곡선 그리기
	/*
	Graphics graphics(pDC->m_hDC);
	Pen pen(Color(255, 0, 0, 0), 3);

	int i = 0;

	//좌표지정
	Point points[] = { Point(30,30), Point(120,50), Point(170,40),Point(160,20),Point(280,100),Point(150,90),Point(90,70),Point(50,130) };

	int pointNum = sizeof(points) / sizeof(points[0]);

	graphics.DrawPolygon(&pen, points, pointNum);

	//다각형
	for (i = 0; i < pointNum; i++)
		points[i].X += 300;

	graphics.DrawClosedCurve(&pen, points, pointNum, 0.5f);

	for (i = 0; i < pointNum; i++)
		points[i].X += 300;

	graphics.DrawClosedCurve(&pen, points, pointNum, 1);

	for (i = 0; i < pointNum; i++) {
		points[i].X -= 600;
		points[i].Y += 200;
	}
	graphics.DrawCurve(&pen, points, pointNum, 0);

	for (i = 0; i < pointNum; i++)
		points[i].X += 300;
	graphics.DrawCurve(&pen, points, pointNum, 0.5);

	for (i = 0; i < pointNum; i++)
		points[i].X += 300;
	graphics.DrawCurve(&pen, points, pointNum, 1);
	*/

	//펜두께 조절
	/*
	Graphics graphics(pDC->m_hDC);

	Pen blackPen(Color(255, 0, 0, 0), 1);
	Pen greenPen(Color(255, 0, 255, 0), 10);

	greenPen.SetAlignment(PenAlignmentInset); // 기준점을 기준으로 안쪽으로 그린다.
	graphics.DrawRectangle(&greenPen, 50, 50, 100, 100);
	graphics.DrawRectangle(&blackPen, 50, 50, 100, 100);

	greenPen.SetAlignment(PenAlignmentCenter); // 기준점을 기준으로 반반으로 안, 밖에 나오게 그린다.
	graphics.DrawRectangle(&greenPen, 180, 50, 100, 100);
	graphics.DrawRectangle(&blackPen, 180, 50, 100, 100);
	*/

	//선끝 모양/연결 모양
	/*
	Graphics graphics(pDC->m_hDC);

	//선끝모양 지양
	Pen capPen(Color(255, 0, 0, 0), 5);

	capPen.SetStartCap(LineCapSquare);
	capPen.SetEndCap(LineCapRound);
	graphics.DrawLine(&capPen, 50, 50, 400, 50);

	capPen.SetStartCap(LineCapTriangle);
	capPen.SetEndCap(LineCapNoAnchor);
	graphics.DrawLine(&capPen, 50, 100, 400, 100);

	capPen.SetStartCap(LineCapSquareAnchor);
	capPen.SetEndCap(LineCapRoundAnchor);
	graphics.DrawLine(&capPen, 50, 150, 400, 150);

	capPen.SetStartCap(LineCapDiamondAnchor);
	capPen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLine(&capPen, 50, 200, 400, 200);

	//선연결모양지정
	Pen joinPen(Color(255, 0, 0, 0), 10);

	joinPen.SetLineJoin(LineJoinBevel);
	graphics.DrawRectangle(&joinPen, 50, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinMiter);
	graphics.DrawRectangle(&joinPen, 180, 250, 100, 100);

	joinPen.SetLineJoin(LineJoinRound);
	graphics.DrawRectangle(&joinPen, 310, 250, 100, 100);
	*/

	//선 패턴 지정
	/*
	Graphics graphics(pDC->m_hDC);
	Pen pen(Color(255, 0, 0, 0), 3);

	pen.SetDashStyle(DashStyleSolid); //실선
	graphics.DrawLine(&pen, 50, 50, 400, 50);

	pen.SetDashStyle(DashStyleDash); //파선
	graphics.DrawLine(&pen, 50, 100, 400, 100);

	pen.SetDashStyle(DashStyleDot); // 점선
	graphics.DrawLine(&pen, 50, 150, 400, 150);

	pen.SetDashStyle(DashStyleDashDot); //일점 쇄선
	graphics.DrawLine(&pen, 50, 200, 400, 200);

	pen.SetDashStyle(DashStyleDashDotDot); //이점 쇄선
	graphics.DrawLine(&pen, 50, 250, 400, 250);

	pen.SetDashOffset(5); // 시작점을 5픽셀 이동
	graphics.DrawLine(&pen, 50, 260, 400, 260);

	REAL dashVals[4] = { 5,1,2,1 };
	pen.SetDashPattern(dashVals, 4); //사용자 정의선 패턴
	graphics.DrawLine(&pen, 50, 310, 400, 310);
	*/

	//솔리드 브러시
	/*
	Graphics graphics(pDC->m_hDC);

	CRect rect;
	GetClientRect(&rect);
	int x = 0, y = 0;

	SolidBrush brush(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillRectangle(&brush, x, y, 200, 100);
	//사각형

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillEllipse(&brush, x, y, 200, 100);
	//원

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));
	x = rand() % rect.Width();
	y = rand() % rect.Height();
	graphics.FillPie(&brush, x, y, 200, 200, 135, 90);
	//파이

	brush.SetColor(Color(rand() % 129, rand() % 256, rand() % 256, rand() % 256));

	//좌표지정
	Point* pPoints = new Point[6];
	for (int j = 0; j < 6; j++) {
		x = rand() % rect.Width();
		y = rand() % rect.Height();
		pPoints[j].X = x;
		pPoints[j].Y = y;
	}
	graphics.FillClosedCurve(&brush, pPoints, 6, FillModeAlternate, 1);
	delete[] pPoints;
	*/

	//그라디언트브러시
	/*
	Graphics graphics(pDC->m_hDC);

	//선형 그라디언트 브러시
	LinearGradientBrush linerBrush(Point(50, 100), Point(400, 250), Color(255, 0, 255, 0), Color(255, 0, 0, 255));
	graphics.FillRectangle(&linerBrush, 50, 100, 300, 150);//사각형

	//패스 그라디언트 브러시
	GraphicsPath path;
	path.AddEllipse(50, 300, 300, 150);

	int count = 1;
	PathGradientBrush pathBrush(&path);
	pathBrush.SetCenterColor(Color(255, 0, 0, 255));
	pathBrush.SetSurroundColors(&Color(255, 255, 255, 0), &count);
	graphics.FillEllipse(&pathBrush, 50, 300, 300, 150);
	*/

	//패턴 브러시
	/*
	Graphics graphics(pDC->m_hDC);

	for (int i = 0; i < HatchStyleTotal; i++) {
		HatchBrush brush((Gdiplus::HatchStyle)i, Color(255, 0, 0, 255), Color(255, 100, 255, 100));
		graphics.FillRectangle(&brush, 20 + (i % 7) * 90, 20 + (i / 7) * 60, 80, 50);
	}
	*/

//비트맵
/*
Graphics graphics(pDC->m_hDC);

//jpg파일읽기
Image image(_T("earth.jpg"));
int width = image.GetWidth();
int height = image.GetHeight();

//화면에 출력
graphics.DrawImage(&image, 10, 01, width / 10, height / 10);

//찌그러뜨려 출력
Point points[] = { Point(250,20), Point(200,100), Point(350, 50) };
graphics.DrawImage(&image, points, 3);

//축소 출력
graphics.SetInterpolationMode(InterpolationModeNearestNeighbor);
graphics.DrawImage(&image, 10, 150, width / 7, width / 7);
graphics.SetInterpolationMode(InterpolationModeHighQualityBilinear);
graphics.DrawImage(&image, 300, 150, width / 7, width / 7);
*/

//텍스트 출력
/*
//using Gdiplus::Font;
CRect rect;
GetClientRect(rect);

Graphics graphics(pDC->m_hDC);
TCHAR string[] = _T("대한사람대한으로길이보전하세");

//글꼴 생성
FontFamily fontFamily(_T("궁서체"));
Gdiplus::Font font(&fontFamily, 24, FontStyleBold, UnitPixel); // using Gdiplus::Font와 같음.

//브러시 생성
SolidBrush brush(Color(255, 0, 0, 255));

//가운데 정렬
StringFormat stringFormat;
stringFormat.SetAlignment(StringAlignmentCenter);
stringFormat.SetLineAlignment(StringAlignmentCenter);

//윈도우의 중심점에 정렬한 텍스트 출력
PointF pointF(rect.Width() / 2.0f, rect.Height() / 2.0f);
graphics.DrawString(string, (INT)wcslen(string), &font, pointF, &stringFormat, &brush);

//텍스트 출력 품질 조절
graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);

//사각형의 중앙에 정렬한 텍스트 출력
RectF rectF(150, 20, 200, 100);
graphics.DrawString(string, (INT)wcslen(string), &font, rectF, &stringFormat, &brush);

Pen pen(Color(255, 255, 0, 0));
graphics.DrawRectangle(&pen, rectF);
*/


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGDIplusView 진단

#ifdef _DEBUG
void CGDIplusView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIplusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIplusDoc* CGDIplusView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIplusDoc)));
	return (CGDIplusDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIplusView 메시지 처리기



void CGDIplusView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
	Graphics graphics(dc);

	// Draw실행을 위한 코드
	//OnDraw(&dc);
	
	//이 코드를 넣으면 선이 훨신 부드러워집니다.
	/*
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen RedPen(Color(255, 255, 0, 0), 2.0f);
	Pen GreenPen(Color(255, 0, 255, 0), 2.0f);
	Pen BluePen(Color(255, 0, 0, 255), 2.0f);

	Point points[6] = { Point(10,150), Point(110,10), Point(170,250), Point(220,120),Point(270,150),Point(350,150) };
	graphics.DrawCurve(&RedPen, points, 6, 0.0f);
	graphics.DrawCurve(&GreenPen, points, 6, 0.5f);
	graphics.DrawCurve(&BluePen, points, 6, 1.0f);
	*/
}

