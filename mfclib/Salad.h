#pragma once
#include "pch.h"
#include <vector>
#include <memory>
#include "Apple.h"
#include "Fruit.h"

using namespace std;

class Salad
{
public:
	vector<shared_ptr<Fruit>> plate;
	virtual void ReadFromFile(CArchive& archive);
	virtual void WriteToFile(CArchive& archive);
	int GetPlateSize();

	void AddFruit(shared_ptr<Fruit> fruit);
	void AddApple();
	void AddNewFruit(shared_ptr<Fruit> fruit);
	void AddNewApple(shared_ptr<Apple> apple);
	void ClearPlate();

};