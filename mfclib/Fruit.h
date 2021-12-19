#pragma once
#include "pch.h"

class Fruit : public CObject
{
public:

	DECLARE_SERIAL(Fruit)

	CString name;
	int amount;
	double price;

	Fruit();
	~Fruit();

	virtual void Serialize(CArchive& ar);
	virtual CString toString();
};