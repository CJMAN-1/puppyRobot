
// MFCAppDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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


// CMFCAppDlg 대화 상자



CMFCAppDlg::CMFCAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_thermister, &CMFCAppDlg::OnBnClickedthermistor)
	ON_BN_CLICKED(IDC_jogging, &CMFCAppDlg::OnBnClickedjogging)
	ON_BN_CLICKED(IDC_mouth, &CMFCAppDlg::OnBnClickedmouth)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, &CMFCAppDlg::OnBnClickedCancel)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_A, &CMFCAppDlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_B, &CMFCAppDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_C, &CMFCAppDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_D, &CMFCAppDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_E, &CMFCAppDlg::OnBnClickedE)
END_MESSAGE_MAP()


// CMFCAppDlg 메시지 처리기

BOOL CMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
//	this->GetWindowRect(sizeOfDialog);
	
	GetClientRect(sizeOfDialog);
	//1920X1080
	int iScreenWidth = 900;
	int iScreenHeight = 700;
	SetWindowPos(&wndTop, 510, 190, iScreenWidth, iScreenHeight, SWP_SHOWWINDOW);
	button = (CButton *)GetDlgItem(IDC_jogging);
	button->MoveWindow(10, top+240, width, height);
	button = (CButton *)GetDlgItem(IDC_mouth);
	button->MoveWindow(10, top+240 +increment, width, height);
	button = (CButton *)GetDlgItem(IDC_thermister);
	button->MoveWindow(10, top +240+ 2* increment, width, height);
	button = (CButton *)GetDlgItem(IDC_A);
	button->MoveWindow(10, top +240+ 3* increment, width, height);
	button = (CButton *)GetDlgItem(IDC_B);
	button->MoveWindow(left, top+ 4 * increment, width, height);
	button = (CButton *)GetDlgItem(IDC_C);
	button->MoveWindow(left, top + 5 * increment, width, height);
	button = (CButton *)GetDlgItem(IDC_D);
	button->MoveWindow(left, top + 6 * increment, width, height);
	button = (CButton *)GetDlgItem(IDC_E);
	button->MoveWindow(left, top + 7 * increment, width, height);
	button = (CButton *)GetDlgItem(IDCANCEL);
	button->MoveWindow(left, top + 8 * increment, width, height);
	

	homeDC = GetDC();
	homeDC->SetStretchBltMode(HALFTONE);

	font.CreateFont(18, 10, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"맑은 고딕");
	homeDC->SelectObject(font);
	hdc = homeDC->m_hDC;
	SetRect(&rectCJ, 510, 260, 760, 400);

	/////////////////////블루 투스 실험
	CString s("COM11");
	/*
	blt.bluetoothConnect(s);

	blt.bluetoothSend('a');
//	Sleep(1000);
	blt.bluetoothSend('a');
//	Sleep(1000);
	blt.bluetoothSend('a');
//	Sleep(1000);
	blt.bluetoothSend('a');
//	Sleep(1000);
	
//	communication = thread(&CMFCAppDlg::InThread1, this);
	*/
	

	//////////////////////////여까지
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

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
		if (!flagIntialize) {
			CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
			GetClientRect(sizeOfDialog);
			dc.SetStretchBltMode(HALFTONE);
			if (screenImage.Load(_T("puppyimage/home.jpg")) == S_OK) {


				screenImage.StretchBlt(dc.m_hDC, sizeOfDialog);
			}
			screenImage.Destroy();
			++flagIntialize;
		}
		else
			CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAppDlg::OnBnClickedthermistor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (screenImage.Load(_T("puppyimage/hot.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();

	blt.bluetoothSend('H');

	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		hstring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch ;
	}
	hstring += "도 에요!  \n헥헥헥북핵 더워요!";
	DrawText(hdc, hstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	hstring.Empty();
}


void CMFCAppDlg::OnBnClickedjogging()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (screenImage.Load(_T("puppyimage/weathergood.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();
	
	blt.bluetoothSend('G');
	
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		gstring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	gstring += "lux 레요!\n날씨가 좋아요!";
	DrawText(hdc, gstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	gstring.Empty();
}


void CMFCAppDlg::OnBnClickedmouth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (screenImage.Load(_T("puppyimage/mouth.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();
	//homeDC->TextOutW(500, 280, fstring);
	
	blt.bluetoothSend('F');
	
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		fstring += *itoa(ch - 48, databuffer, 10);
		
		databuffer[i] = ch - 48;
	}
	fstring += "만큼\n너 냄새나!";

	DrawText(hdc, fstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	fstring.Empty();
}


void CMFCAppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

//	communication.detach();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}



BOOL CMFCAppDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreCreateWindow(cs);
}


void CMFCAppDlg::OnBnClickedCancel()
{
	if (screenImage.Load(_T("puppyimage/destroy.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();


	Sleep(5000);
	ReleaseDC(homeDC);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CMFCAppDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	text.SetString(L"이시발 시간이 없다");
	DrawText(hdc, text, -1, &rectCJ, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL);

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFCAppDlg::OnBnClickedA()
{
	if (screenImage.Load(_T("puppyimage/angry.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();


	blt.bluetoothSend('A');
	Sleep(10);
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		astring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	astring += "\n아잇 간지러워요!";
	DrawText(hdc, astring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	astring.Empty();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCAppDlg::OnBnClickedB()
{
	if (screenImage.Load(_T("puppyimage/water.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();

	blt.bluetoothSend('B');
	Sleep(10);
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		bstring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	bstring += "\n6월호가 수위가 정말 높아요!";
	DrawText(hdc, bstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	bstring.Empty();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCAppDlg::OnBnClickedC()
{
	if (screenImage.Load(_T("puppyimage/angry.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();
	
	blt.bluetoothSend('C');
	Sleep(10);
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		cstring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	cstring += "\n적당히 눌러요!";
	DrawText(hdc, cstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	cstring.Empty();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCAppDlg::OnBnClickedD()
{
	if (screenImage.Load(_T("puppyimage/feelgood.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();

	blt.bluetoothSend('D');
	Sleep(10);
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		dstring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	dstring += "\n주인님 반가워요!";
	DrawText(hdc, dstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	dstring.Empty();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCAppDlg::OnBnClickedE()
{
	if (screenImage.Load(_T("puppyimage/angry.jpg")) == S_OK) {
		screenImage.StretchBlt(homeDC->m_hDC, sizeOfDialog);
	}
	Invalidate(FALSE);
	screenImage.Destroy();

	blt.bluetoothSend('E');
	Sleep(10);
	for (int i = 0; i < 4; i++) {
		ch = blt.bluetoothRecv();
		estring += *itoa(ch - 48, databuffer, 10);
		databuffer[i] = ch - 48;
	}
	estring += "\n가!!!";
	DrawText(hdc, estring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	estring.Empty();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCAppDlg::InThread1() {//스레드 안쓴다...
	while (1) {
		type = blt.bluetoothRecv();

		if ((type != -1) && (type >= 64)) {
			for (int i = 0; i < 4; i++) {
				ch = blt.bluetoothRecv();
				dataString += *itoa(ch - 48, databuffer, 10);
				databuffer[i] = ch - 48;
			}
			switch (type) {
			case 'A'://저항
				astring.Empty();
				astring += "지금 저항값이";
				astring += dataString;
				astring += "이에요!";

				a = atoi(databuffer);

				break;
			case 'B'://물

				bstring.Empty();
				bstring += "이번 6월호 맥심 수위가 ";
				bstring += dataString;
				bstring += "이에요!";

				b = atoi(databuffer);
				break;
			case 'C'://파워
				cstring.Empty();
				cstring += "주인님 저를";
				cstring += dataString;
				cstring += "N으로 누르면 어떡해요!";

				c = atoi(databuffer);
				break;
			case 'D'://PSD

				dstring.Empty();
				dstring += "주인님 가지마세요!";
				dstring += dataString;
				dstring += "cm나 멀다고요!";

				d = atoi(databuffer);
				break;
			case 'E'://초음파

				estring.Empty();
				estring += "어이 거기";
				estring += dataString;
				estring += "cm 뒤에 있는놈!";

				e = atoi(databuffer);
				break;
			case 'F'://가스

				fstring.Empty();
				fstring += "양치는 하루에 3번! 매너! ";
				f = atoi(databuffer);
				break;
			case 'G'://CDS
				gstring.Empty();
				gstring += "날씨가 아주 장난 아니구만";
				gstring += dataString;
				gstring += "에요!";

				g = atoi(databuffer);
				break;
			case 'H'://온도

				hstring.Empty();
				hstring += "아따 덥다 그제??";
				hstring += dataString;
				hstring += "에요!";

				h = atoi(databuffer);

				break;
			}

		}
		type = -1;
		ch = -1;
		if (dataString.IsEmpty() != TRUE)	//strText에 문자열이 있나 확인한다.
		{
			dataString.Empty();				//strText에 문자열이 있으면 지운다.
		}
		if (outputString.IsEmpty() != TRUE)	//strText에 문자열이 있나 확인한다.
		{
			outputString.Empty();				//strText에 문자열이 있으면 지운다.
		}
		databuffer[0] = 0;
		databuffer[1] = 0;
		databuffer[2] = 0;
		databuffer[3] = 0;
		Sleep(10);
	}
}