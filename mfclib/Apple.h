#pragma once
#include "pch.h"
#include "Fruit.h"

class Apple : public Fruit
{
public:
	DECLARE_SERIAL(Apple)

	CString color;
	int trees;
	int seed;

	Apple();
	~Apple();

	virtual void Serialize(CArchive& ar);
	virtual CString toString();
};