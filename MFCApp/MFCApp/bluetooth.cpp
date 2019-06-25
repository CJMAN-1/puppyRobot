#include "stdafx.h"
#include "bluetooh.h"


using namespace std;


void bluethooth::bluetoothConnect(CString _portNum)
{
	while (1)
	{
		// STEP 1. SerialPort Connect
		if (!serialComm.connect(_portNum)) {
			printf("connect faliled\n");
		}
		else {
			printf("connect successed\n");
			break;
		}
	
	//	Sleep(500);
	}
}

void  bluethooth::bluetoothSend(char data)
{
	//// STEP 2. Send Command
	if (!serialComm.sendCommand(data)) {
		printf("send command failed\n");
	}
	else
		printf("send Command success\n");
}

BYTE bluethooth::bluetoothRecv(void)
{
	BYTE data;
	// STEP 3. Receive Command
		if (!serialComm.recvCommand(data)) {
			printf("send command failed\n");
			return -1;
		}
	return data;
}

void bluethooth::bluetoothDisconnect(void)
{
	serialComm.disconnect();
	printf("\nend connect\n");
}
