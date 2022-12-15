
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>
LPWSTR ClipboardOutPutText1();
#define SIZE_BUFFER 512

int WINAPI WinMain(HINSTANCE hInstance,    // ���������� �������� ���������� ���� 
	HINSTANCE hPrevInstance,// ���������� ����������� ���������� ����
	LPSTR lpCmdLine,        // ��������� �� ��������� ������
	int nCmdShow            // ���������� ��������� ����

)
{
	while (TRUE) {
		LPSTR Data = ClipboardOutPutText1();
		TCHAR Alert[] = L"�� ������ ���� �����: ";
		TCHAR Number[] = L"";
		TCHAR third[512]; // ������ �� ����������� ����� ��������
		swprintf(third, sizeof third, L"%s%s", Alert, Data);

		switch (*Data) 
		{
		case '1':
		{
			swprintf(third, sizeof third, L"%����", Number, Data);
			break;
		}
		case '2': {

			swprintf(third, sizeof third, L"%���", Number, Data);
			break;
		}
		case '3': {

			swprintf(third, sizeof third, L"%���", Number, Data);
			break;
		}
		case '4': {

			swprintf(third, sizeof third, L"%������", Number, Data);
			break;
		}
		case '5': {

			swprintf(third, sizeof third, L"%����", Number, Data);
			break;
		}
		case '6': {

			swprintf(third, sizeof third, L"%�����", Number, Data);
			break;
		}
		case '7': {

			swprintf(third, sizeof third, L"%����", Number, Data);
			break;
		}
		case '8': {

			swprintf(third, sizeof third, L"%������", Number, Data);
			break;
		}
		case '9':
		{
			swprintf(third, sizeof third, L"%������", Number, Data);
			break;
		}
		case '0':
		{
			swprintf(third, sizeof third, L"%����", Number, Data);
			break;
		}

		}
		if (*Data != 0) // ���� �������� ���� �� ����� ���� (�� ������ ������)
		{ 
			MessageBoxW(NULL, &third, L"�� ����������� �����", MB_OK);
			ClipboardInputTEXT(""); // ������ ������ ������ ��� �������
		}
		else {};
		Sleep(1000);
	}
	return 0;
}
TCHAR* ClipboardOutPutText1() {

	TCHAR* message = NULL;
	OpenClipboard(NULL);

	HANDLE clipboardData = GetClipboardData(CF_UNICODETEXT);
	message = (TCHAR*)GlobalLock(clipboardData); // ������� �� ����������� ������� ������, ������ � ������
	GlobalUnlock(clipboardData);
	CloseClipboard();
	EmptyClipboard();
	return message;
}
int ClipboardInputTEXT(LPWSTR buffer) {


	DWORD lenghtWord;
	HANDLE hMem;
	lenghtWord = wcslen(buffer) + 1; // ����� � �������
	hMem = GlobalAlloc(GMEM_MOVEABLE, lenghtWord * sizeof(LPWSTR)); // ����������� ����� ������ � �������
	memcpy(GlobalLock(hMem), buffer, lenghtWord * sizeof(LPWSTR)); // ����������� ������� ������ �� buffer � hmem
	// ����������� ������ ���� ������ ������� �� ����

	GlobalUnlock(hMem); // ��� ������ ����
	OpenClipboard(0); // ������� ����� ������
	EmptyClipboard(); // �������� �����
	SetClipboardData(CF_UNICODETEXT, hMem); // ������ � ����� ���������������� ����
	CloseClipboard(); // ������� �����
	return 100500;

}