
// MFCApp.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCAppApp:
// �� Ŭ������ ������ ���ؼ��� MFCApp.cpp�� �����Ͻʽÿ�.
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCAppApp theApp;