#include "pch.h"
#include "Apple.h"

IMPLEMENT_SERIAL(Apple, Fruit, 1)

Apple::Apple() {}
Apple::~Apple() {}

CString Apple::toString()
{
	CString str;
	str.Format(_T("apple"));
	return str;
}

void Apple::Serialize(CArchive& ar)
{
	Fruit::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << name << amount << price;
		ar << color << trees << seed;
	}
	else
	{
		ar >> name;
		ar >> amount;
		ar >> price;

		ar >> color;
		ar >> trees;
		ar >> seed;
	}
}