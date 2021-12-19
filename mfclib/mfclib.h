// mfclib.h: основной файл заголовка для библиотеки DLL mfclib
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CmfclibApp
// Реализацию этого класса см. в файле mfclib.cpp
//

class CmfclibApp : public CWinApp
{
public:
	CmfclibApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
