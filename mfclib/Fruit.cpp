#include "pch.h"
#include "Fruit.h"

IMPLEMENT_SERIAL(Fruit, CObject, 0)

Fruit::Fruit() {}
Fruit::~Fruit() {}

CString Fruit::toString()
{
	CString str;
	str.Format(_T("fruit"));
	return str;
}

void Fruit::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << name;
		ar << amount;
		ar << price;
	}
	else
	{
		ar >> name >> amount >> price;
	}
}