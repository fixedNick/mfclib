#include "pch.h"
#include "framework.h"
#include "mfclib.h"
#include "Salad.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
BEGIN_MESSAGE_MAP(CmfclibApp, CWinApp)
END_MESSAGE_MAP()
CmfclibApp::CmfclibApp(){}
CmfclibApp theApp;
BOOL CmfclibApp::InitInstance() { CWinApp::InitInstance(); return TRUE; }



struct FruitExport
{
	char name[100];
	int amount;
	double price;
};

struct AppleExport
{
	char name[100];
	int amount;
	double price;

	char color[100];
	int seed;
	int trees;
};

Salad salad;

extern "C" _declspec(dllexport) void __stdcall ReadFromFile(const char* path)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file(CString(path), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	salad.ReadFromFile(ar);
	ar.Close();
	file.Close();
}

extern "C" _declspec(dllexport) void __stdcall WriteToFile(const char* path)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CFile file(CString(path), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	salad.WriteToFile(ar);
	ar.Close();
	file.Close();
}

extern "C" _declspec(dllexport) int __stdcall GetPlateSize()
{
	return salad.GetPlateSize();
}

extern "C" _declspec(dllexport) BOOL __stdcall IsApple(int idx)
{
	Apple* isApple = dynamic_cast<Apple*>(salad.plate[idx].get());
	return (isApple) ? true : false;
}

// Не работает, NullReferenceException при попытке достать name|amount|price
extern "C" _declspec(dllexport) void __stdcall GetFruit(FruitExport & fruit, int idx)
{
	// TODO
	// Cast into const char* мшф CStringA constructor could go wrong
	strcpy_s(fruit.name, salad.plate[idx]->name);
	fruit.amount = salad.plate[idx]->amount;
	fruit.price = salad.plate[idx]->price;
}

extern "C" _declspec(dllexport) void __stdcall GetApple(AppleExport & apple, int idx)
{
	Apple* appleToImport = dynamic_cast<Apple*>(salad.plate[idx].get());

	auto cName = appleToImport->name;
	CStringA cstrName(cName);
	auto cColor = appleToImport->color;
	CStringA cstrColor(cColor);

	strcpy_s(apple.name, cstrName);
	strcpy_s(apple.color, cstrColor);
	apple.amount = appleToImport->amount;
	apple.price = appleToImport->price;
	apple.seed = appleToImport->seed;
	apple.trees = appleToImport->trees;
}

extern "C" _declspec(dllexport) void __stdcall FruitAdd(FruitExport & fruit)
{
	auto fruit_ptr = make_shared<Fruit>();
	fruit_ptr->name = fruit.name;
	fruit_ptr->amount = fruit.amount;
	fruit_ptr->price = fruit.price;
	salad.AddNewFruit(fruit_ptr);
}

extern "C" _declspec(dllexport) void __stdcall AppleAdd(AppleExport & apple)
{
	auto apple_ptr = make_shared<Apple>();
	apple_ptr->name = apple.name;
	apple_ptr->amount = apple.amount;
	apple_ptr->price = apple.price;
	apple_ptr->color = apple.color;
	apple_ptr->seed = apple.seed;
	apple_ptr->trees = apple.trees;
	salad.AddNewApple(apple_ptr);
}

extern "C" _declspec(dllexport) void __stdcall ClearPlate()
{
	salad.plate.clear();
}