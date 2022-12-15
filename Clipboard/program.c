#include <Windows.h>
#include <stdio.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	system("chcp 1251 > nul");
	LPWSTR message = L"Текст из message";
	ClipboardInputTEXT(message);
	ClipboardOutPutText();
}

DWORD ClipboardInputTEXT(LPWSTR buffer)
{
	DWORD lenghtWord;
	HANDLE hMem;
	lenghtWord = wcslen(buffer) + 1; // длина в юникоде
	hMem = GlobalAlloc(GMEM_MOVEABLE, lenghtWord * sizeof(LPWSTR)); // определение длины строки в юникоде
	memcpy(GlobalLock(hMem), buffer, lenghtWord * sizeof(LPWSTR)); // копирование области памяти из buffer в hmem
	// резервируем память чтоб другой процесс не взял

	GlobalUnlock(hMem); // для других прог
	OpenClipboard(0); // открыть буфер обмена
	EmptyClipboard(); // очистить буфер
	SetClipboardData(CF_UNICODETEXT, hMem); // запись в буфер соответствующего типа
	CloseClipboard(); // закрыли буфер
	return 100500;

}

DWORD ClipboardOutPutText()
{
	LPWSTR message = NULL;
	OpenClipboard(NULL);

	HANDLE clipboardData = GetClipboardData(CF_UNICODETEXT);
	message = (LPWSTR)GlobalLock(clipboardData); // считали из глобального участка памяти, привел к строке
	GlobalUnlock(clipboardData);
	CloseClipboard();
	MessageBox(NULL, message, L"Скопировано в буфер обмена", MB_OK);
	return 100500;
}