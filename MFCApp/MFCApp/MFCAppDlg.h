
// MFCAppDlg.h : ��� ����
//

#pragma once
#include <atlimage.h>
#include "afxext.h"
#include "afxwin.h"
#include "bluetooh.h"
#include <thread>
using namespace std;
// CMFCAppDlg ��ȭ ����
class CMFCAppDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCAppDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedthermistor();
	afx_msg void OnBnClickedjogging();
	afx_msg void OnBnClickedmouth();
	afx_msg void OnDestroy();

	//ȭ�� �׸��� ����
	CDC* homeDC;
	CImage screenImage;
	CRect sizeOfDialog;

	//��ư ��ġ ����
	CButton* button;
	enum {//��ư ��ġ
		left = 775,
		top = 120,
		increment = 60,
		width = 100,
		height = 40
	};

	//�ʱ�ȭ�� ������ ���� �÷���
	int flagIntialize = 0;

	//������ ������ ��� �÷���
	int flagCDS = 0;
	int flagThermistor = 0;
	int flagPSD = 0;
	int flagUlatraSonic = 0;
	int flagGas = 0;
	int flagResistance = 0;
	int flagWater = 0;
	int flagPressure = 0;

	//��� ����
	bluethooth blt;
	thread communication;
	void InThread1();

	//���� ���
	CFont font;
	HDC hdc;
	RECT rectCJ;
	CString text;
	BYTE ch = -1;
	BYTE type = -1;
	CString dataString;
	CString outputString;

	int Ares, Bwater, Cpower, Dpsd, Eultra, Fgas, Gcds, Hthermistor;
	char databuffer[10];
	char databuffer2[10];
	int a=0, b=0, c=0,d=0, e=0, f=0, g=0, h=0;
	CString astring;
	CString bstring;
	CString cstring;
	CString dstring;

	CString estring;
	CString fstring;
	CString gstring;
	CString hstring;
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedA();
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedE();
};
