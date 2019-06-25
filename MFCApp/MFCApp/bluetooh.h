#pragma once
#include <stdio.h>
#include "serialcomm.h"
#include <iostream>

class bluethooth {
public:
	int startflag = 0;
	CSerialComm serialComm;


	void bluetoothConnect(CString _portNum);
	void  bluetoothSend(char data);
	BYTE bluetoothRecv(void);
	void bluetoothDisconnect(void);
};
