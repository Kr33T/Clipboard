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
		TCHAR Alert[] = L"¬ы не получите этот текст: ";
		TCHAR third[512]; // массив на ограничение длины символов
		swprintf(third, sizeof third, L"%s%s!", Alert, Data);
		if (*Data != 0)
		{ // если значение даты не равно нулю (не пуста€ строка)

			MessageBoxW(NULL, &third, L" опирование запрещено!", MB_OK | MB_ICONWARNING);
			ClipboardInputTEXT(""); // кладем пустую строку дл€ очистки


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
	message = (TCHAR*)GlobalLock(clipboardData); // считали из глобального участка пам€ти, привел к строке
	GlobalUnlock(clipboardData);
	CloseClipboard();
	EmptyClipboard();
	return message;
}
int ClipboardInputTEXT(LPWSTR buffer) {


	DWORD lenghtWord;
	HANDLE hMem;
	lenghtWord = wcslen(buffer) + 1; // длина в юникоде
	hMem = GlobalAlloc(GMEM_MOVEABLE, lenghtWord * sizeof(LPWSTR)); // определение длины строки в юникоде
	memcpy(GlobalLock(hMem), buffer, lenghtWord * sizeof(LPWSTR)); // копирование области пам€ти из buffer в hmem
	// резервируем пам€ть чтоб другой процесс не вз€л

	GlobalUnlock(hMem); // дл€ других прог
	OpenClipboard(0); // открыть буфер обмена
	EmptyClipboard(); // очистить буфер
	SetClipboardData(CF_UNICODETEXT, hMem); // запись в буфер соответствующего типа
	CloseClipboard(); // закрыли буфер
	return 100500;

}

