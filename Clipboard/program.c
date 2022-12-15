#include <Windows.h>
#include <stdio.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	system("chcp 1251 > nul");
	LPWSTR message = L"����� �� message";
	ClipboardInputTEXT(message);
	ClipboardOutPutText();
}

DWORD ClipboardInputTEXT(LPWSTR buffer)
{
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

DWORD ClipboardOutPutText()
{
	LPWSTR message = NULL;
	OpenClipboard(NULL);

	HANDLE clipboardData = GetClipboardData(CF_UNICODETEXT);
	message = (LPWSTR)GlobalLock(clipboardData); // ������� �� ����������� ������� ������, ������ � ������
	GlobalUnlock(clipboardData);
	CloseClipboard();
	MessageBox(NULL, message, L"����������� � ����� ������", MB_OK);
	return 100500;
}