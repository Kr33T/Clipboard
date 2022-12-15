#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>
LPWSTR ClipboardOutPutText1();
#define SIZE_BUFFER 512

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{        
	while (TRUE) {
		LPSTR Data = ClipboardOutPutText1();
		TCHAR Alert[] = L"�� �� �������� ���� �����: ";
		TCHAR third[512]; // ������ �� ����������� ����� ��������
		swprintf(third, sizeof third, L"%s%s!", Alert, Data);
		if (*Data != 0)
		{ // ���� �������� ���� �� ����� ���� (�� ������ ������)

			MessageBoxW(NULL, &third, L"����������� ���������!", MB_OK | MB_ICONWARNING);
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

