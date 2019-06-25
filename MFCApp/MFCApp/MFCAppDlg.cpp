
// MFCAppDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCApp.h"
#include "MFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCAppDlg ��ȭ ����



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


// CMFCAppDlg �޽��� ó����

BOOL CMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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

	font.CreateFont(18, 10, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"���� ���");
	homeDC->SelectObject(font);
	hdc = homeDC->m_hDC;
	SetRect(&rectCJ, 510, 260, 760, 400);

	/////////////////////��� ���� ����
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
	

	//////////////////////////������
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);

		
		
	}
	else
	{
		if (!flagIntialize) {
			CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAppDlg::OnBnClickedthermistor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	hstring += "�� ����!  \n��������� ������!";
	DrawText(hdc, hstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	hstring.Empty();
}


void CMFCAppDlg::OnBnClickedjogging()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	gstring += "lux ����!\n������ ���ƿ�!";
	DrawText(hdc, gstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	gstring.Empty();
}


void CMFCAppDlg::OnBnClickedmouth()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	fstring += "��ŭ\n�� ������!";

	DrawText(hdc, fstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	fstring.Empty();
}


void CMFCAppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

//	communication.detach();
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}



BOOL CMFCAppDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void CMFCAppDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	text.SetString(L"�̽ù� �ð��� ����");
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
	astring += "\n���� ����������!";
	DrawText(hdc, astring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	astring.Empty();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	bstring += "\n6��ȣ�� ������ ���� ���ƿ�!";
	DrawText(hdc, bstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	bstring.Empty();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	cstring += "\n������ ������!";
	DrawText(hdc, cstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	cstring.Empty();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	dstring += "\n���δ� �ݰ�����!";
	DrawText(hdc, dstring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	dstring.Empty();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	estring += "\n��!!!";
	DrawText(hdc, estring, -1, &rectCJ, DT_LEFT | DT_WORDBREAK);
	estring.Empty();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCAppDlg::InThread1() {//������ �Ⱦ���...
	while (1) {
		type = blt.bluetoothRecv();

		if ((type != -1) && (type >= 64)) {
			for (int i = 0; i < 4; i++) {
				ch = blt.bluetoothRecv();
				dataString += *itoa(ch - 48, databuffer, 10);
				databuffer[i] = ch - 48;
			}
			switch (type) {
			case 'A'://����
				astring.Empty();
				astring += "���� ���װ���";
				astring += dataString;
				astring += "�̿���!";

				a = atoi(databuffer);

				break;
			case 'B'://��

				bstring.Empty();
				bstring += "�̹� 6��ȣ �ƽ� ������ ";
				bstring += dataString;
				bstring += "�̿���!";

				b = atoi(databuffer);
				break;
			case 'C'://�Ŀ�
				cstring.Empty();
				cstring += "���δ� ����";
				cstring += dataString;
				cstring += "N���� ������ ��ؿ�!";

				c = atoi(databuffer);
				break;
			case 'D'://PSD

				dstring.Empty();
				dstring += "���δ� ����������!";
				dstring += dataString;
				dstring += "cm�� �ִٰ��!";

				d = atoi(databuffer);
				break;
			case 'E'://������

				estring.Empty();
				estring += "���� �ű�";
				estring += dataString;
				estring += "cm �ڿ� �ִ³�!";

				e = atoi(databuffer);
				break;
			case 'F'://����

				fstring.Empty();
				fstring += "��ġ�� �Ϸ翡 3��! �ų�! ";
				f = atoi(databuffer);
				break;
			case 'G'://CDS
				gstring.Empty();
				gstring += "������ ���� �峭 �ƴϱ���";
				gstring += dataString;
				gstring += "����!";

				g = atoi(databuffer);
				break;
			case 'H'://�µ�

				hstring.Empty();
				hstring += "�Ƶ� ���� ����??";
				hstring += dataString;
				hstring += "����!";

				h = atoi(databuffer);

				break;
			}

		}
		type = -1;
		ch = -1;
		if (dataString.IsEmpty() != TRUE)	//strText�� ���ڿ��� �ֳ� Ȯ���Ѵ�.
		{
			dataString.Empty();				//strText�� ���ڿ��� ������ �����.
		}
		if (outputString.IsEmpty() != TRUE)	//strText�� ���ڿ��� �ֳ� Ȯ���Ѵ�.
		{
			outputString.Empty();				//strText�� ���ڿ��� ������ �����.
		}
		databuffer[0] = 0;
		databuffer[1] = 0;
		databuffer[2] = 0;
		databuffer[3] = 0;
		Sleep(10);
	}
}