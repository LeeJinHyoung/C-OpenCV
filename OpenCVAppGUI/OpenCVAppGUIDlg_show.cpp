
// OpenCVAppGUIDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "OpenCVAppGUI.h"
#include "OpenCVAppGUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define NAME_WINDOW_SRC "srcView"
#define NAME_WINDOW_RESULT "srcResult"


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenCVAppGUIDlg 대화 상자



COpenCVAppGUIDlg::COpenCVAppGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPENCVAPPGUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCVAppGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenCVAppGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOAD, &COpenCVAppGUIDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_SAVE, &COpenCVAppGUIDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_Inspection, &COpenCVAppGUIDlg::OnBnClickedBtnInspection)
END_MESSAGE_MAP()


// COpenCVAppGUIDlg 메시지 처리기

BOOL COpenCVAppGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//ShowWindow(SW_MAXIMIZE);
	//ShowWindow(SW_MINIMIZE);

	//opencv -> window handle
	namedWindow(NAME_WINDOW_SRC, WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle(NAME_WINDOW_SRC);
	HWND hParent = (HWND)FindWindow(NULL, NAME_WINDOW_SRC);
	HWND hOrgParent = ::SetParent(hWnd, GetDlgItem(IDC_PICTURE)->m_hWnd);
	::ShowWindow(hOrgParent, SW_HIDE);

	namedWindow(NAME_WINDOW_RESULT, WINDOW_AUTOSIZE);
	hWnd = (HWND)cvGetWindowHandle(NAME_WINDOW_RESULT);
	hParent = (HWND)FindWindow(NULL, NAME_WINDOW_RESULT);
	hOrgParent = ::SetParent(hWnd, GetDlgItem(IDC_PICTURE_RESULT)->m_hWnd);
	::ShowWindow(hOrgParent, SW_HIDE);

	GetDlgItem(IDC_PICTURE)->GetWindowRect(_rtImageView);
	ScreenToClient(_rtImageView);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COpenCVAppGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.
void COpenCVAppGUIDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
		//CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//if (!_imageView.IsNull())
		//{
		//	dc.SetStretchBltMode(COLORONCOLOR);
		//	_imageView.Draw(dc, _rtImageView);
		//}
//		DisplayImage(IDC_PICTURE, _DrawImage);
		CRect rect;
		::GetWindowRect(GetDlgItem(IDC_PICTURE)->m_hWnd, rect);
		ScreenToClient(rect);

		CBrush brush(HS_DIAGCROSS, RGB(200, 200, 200));
		dc.FillRect(CRect(rect.left + 1, rect.top + 1, rect.right, rect.bottom), &brush);

	/*	if (!_DrawImage.empty())
		{
			Mat DrawResize;
			Size size(int(_dNewScale * _DrawImage.cols), int(_dNewScale * _DrawImage.rows));
			resize(_DrawImage, DrawResize, size);

			resizeWindow(NAME_WINDOW_SRC, size.width, size.height);
			imshow(NAME_WINDOW_SRC, DrawResize);
		}
	*/
		if (!_bShowResult)
		{
			if (!_DrawImage.empty())
			{
				Mat DrawResize;
				Size size(int(_dNewScale * _DrawImage.cols), int(_dNewScale * _DrawImage.rows));
				resize(_DrawImage, DrawResize, size);

				resizeWindow(NAME_WINDOW_SRC, size.width, size.height);
				imshow(NAME_WINDOW_SRC, DrawResize);
			}
		}
		else
		{
			if (!_DrawImage.empty()) //Drawimage 객체가 비어있지 않은 경우. 즉 이미지기 있는 경우 실행
			{
				Mat DrawResize;
				Size size(int(_dNewScale * _DrawImage.cols), int(_dNewScale * _DrawImage.rows));
				resize(_DrawImage, DrawResize, size);

				resizeWindow(NAME_WINDOW_RESULT, size.width, size.height);
				imshow(NAME_WINDOW_RESULT, DrawResize);
			}
		}
		CDialogEx::OnPaint();

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COpenCVAppGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenCVAppGUIDlg::UpdateDispSrc()
{
	_bShowResult = false;
	CRect rectSrc;
	::GetWindowRect(GetDlgItem(IDC_PICTURE)->m_hWnd, rectSrc);
	double dScaleX = rectSrc.Width() / (double)_SourceImage.cols;
	double dScaleY = rectSrc.Height() / (double)_SourceImage.rows;
	_dSrcScale = min(dScaleX, dScaleY);
	_dNewScale = _dSrcScale;
	//_bShowResult = FALSE;
	//防止顯示不同比例圖片時DC殘留
	CWnd* pWnd = GetDlgItem(IDC_PICTURE);
	pWnd->GetClientRect(&rectSrc);//제어 클라이언트 영역의 좌표 얻기
	pWnd->ClientToScreen(rectSrc);//제어 클라이언트 영역에서 대화 영역으로 영역 좌표 변환
	this->ScreenToClient(rectSrc); //다이얼로그 영역의 영역 좌표를 다이얼로그의 클라이언트 영역 좌표로 변환
	InvalidateRect(rectSrc);
	//비율이 다른 사진을 표시할 때 DC 잔여물 방지

	//Scroll Bar


	//Test
	//double d1 = clock ();
	//Mat matResult;
	//matchTemplate (
	// , _matPtrn, matResult, CV_TM_CCORR);
	//double d2 = clock ();

	////From ImageShop
	//matResult.create (_DrawImage.rows - _matPtrn.rows + 1,
	//	_DrawImage.cols - _matPtrn.cols + 1, CV_32FC1);
	//matResult.setTo (0);
	//cv::Mat& matTemplate = _matPtrn;

	//int  t_r_end = matTemplate.rows, t_r = 0;
	//for (int r = 0; r < matResult.rows; r++)
	//{
	//	float* r_matResult = matResult.ptr<float> (r);
	//	uchar* r_source = _DrawImage.ptr<uchar> (r);
	//	uchar* r_template, *r_sub_source;
	//	for (int c = 0; c < matResult.cols; ++c, ++r_matResult, ++r_source)
	//	{
	//		r_template = matTemplate.ptr<uchar> ();
	//		r_sub_source = r_source;
	//		for (t_r = 0; t_r < t_r_end; ++t_r, r_sub_source += _DrawImage.cols, r_template += matTemplate.cols)
	//		{
	//			*r_matResult = *r_matResult + IM_Conv_SIMD (r_template, r_sub_source, matTemplate.cols);
	//		}
	//	}
	//}
	//double d3 = clock ();

	//double d = (d3 - d2) / (d2 - d1);
	//CString str; str.Format ("%.3f", d); AfxMessageBox (str);
	//
}


void COpenCVAppGUIDlg::OnBnClickedBtnLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	if (fileDlg.DoModal() == IDOK)
	{
		CString path = fileDlg.GetPathName();
		string fileName = path;
		//_SourceImage = cv::imread(fileName, IMREAD_COLOR);
		_SourceImage = cv::imread(fileName, IMREAD_ANYCOLOR);

		if (_SourceImage.type() == CV_8UC1)  // 만약 gray라면
			cvtColor(_SourceImage, _DrawImage, COLOR_GRAY2BGR);
		//drawimage에 gray to bgr로 sourceimage를 대입
		else
			_SourceImage.copyTo(_DrawImage);
		//drawimage로 source image 카피

		UpdateDispSrc();

		InvalidateRect(_rtImageView, FALSE);
		AfxMessageBox("Image Loaded");
	}
}

void COpenCVAppGUIDlg::OnBnClickedBtnSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//string fileName = "jetson_clone.bmp";
	//_imageView.Save(fileName.c_str());

	CFileDialog dlgFileSave(FALSE, "*.*", NULL,//화일명 없음
		OFN_FILEMUSTEXIST,
		_T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"), NULL);

	//옵션 선택 부분.
	if (dlgFileSave.DoModal() == IDOK)
	{
		string str = dlgFileSave.GetFileName();
		imwrite(str, _SourceImage);
	}
	AfxMessageBox("Image Saved");
}

void COpenCVAppGUIDlg::OnBnClickedBtnInspection()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

//input

	//OnInspection(InputArray src, OutputArray dst);
	Mat src = _SourceImage;
	//fucntion
		//using Mat
		//OnInspection(src, dst);
	if (_SourceImage.type() == CV_8UC1) //8비트 타입이라면==Grayscale
		_SourceImage.copyTo(src);
	else
		cvtColor(_SourceImage, src, COLOR_BGRA2GRAY);

	Mat dst = src.clone();

		// using pointer to data
	OnInspection(src.data, src.cols, src.rows, dst.data);

	//result & display
	_bShowResult = true;
	cvtColor(dst, _DrawImage, COLOR_GRAY2BGR); //dst를 G->rgb로 draw_image에 저장.
	InvalidateRect(_rtImageView, TRUE);
	//지정된 사각형 영역을 무효화하고 화면을 다시 그리도록 요청함.
	//_rtImageView는 영역을 지정하는 사각형. FALSE는 지정된 영역 안지우기, TRUE는 지우기
}

int COpenCVAppGUIDlg::OnInspection(InputArray src, OutputArray dst)
{
	return 0;
}

int COpenCVAppGUIDlg::OnInspection(Mat src, Mat dst)
{
	return 0;
}

int COpenCVAppGUIDlg::OnInspection(uchar* pSrc, size_t cols, size_t rows, uchar* pDst)
{
	/*
	pSrc = pointer 2d
	cols = width
	rows = height
	pDst = result data, pointer 2d
	*/
	/* todo*/
	// 조건 pSrc = GrayScale
	// pSrc > 128 ? pDst = 255 : pDst = 0
	// 코드를 작성하세요

	int row = 0;
	int col = 0;
	int index = 0;

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
		{
			index = row * cols + col; // index = row*width + col
			pSrc[index] > 128 ? pDst[index] = 255 : pDst[index] = 0;
		}
	/*for (size_t i = 0; i < cols * rows; i++)
	{
		pSrc[i] > 128 ? pDst[i] = 255 : pDst[i] = 0;
	}*/

	return 0;
}




