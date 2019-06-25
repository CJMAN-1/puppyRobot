
// MFCAppDlg.h : 헤더 파일
//

#pragma once
#include <atlimage.h>
#include "afxext.h"
#include "afxwin.h"
#include "bluetooh.h"
#include <thread>
using namespace std;
// CMFCAppDlg 대화 상자
class CMFCAppDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCAppDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

	//화면 그리는 변수
	CDC* homeDC;
	CImage screenImage;
	CRect sizeOfDialog;

	//버튼 위치 설정
	CButton* button;
	enum {//버튼 위치
		left = 775,
		top = 120,
		increment = 60,
		width = 100,
		height = 40
	};

	//초기화면 설정을 위한 플래그
	int flagIntialize = 0;

	//센서값 들어오면 띄울 플래그
	int flagCDS = 0;
	int flagThermistor = 0;
	int flagPSD = 0;
	int flagUlatraSonic = 0;
	int flagGas = 0;
	int flagResistance = 0;
	int flagWater = 0;
	int flagPressure = 0;

	//블루 투스
	bluethooth blt;
	thread communication;
	void InThread1();

	//글자 출력
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
