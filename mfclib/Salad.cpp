#include "pch.h"
#include "Salad.h"
#include <fstream>
#include <iostream>

using namespace std;

void Salad::AddNewFruit(shared_ptr<Fruit> fruit)
{
	plate.push_back(fruit);
}

void Salad::AddNewApple(shared_ptr<Apple> apple)
{
	plate.push_back(apple);
}

void Salad::ReadFromFile(CArchive& ar)
{
	int n;
	ar >> n;
	for (int i = 0; i < n; i++)
	{
		Fruit* fruit;
		ar >> fruit;
		plate.push_back(shared_ptr<Fruit>(fruit));
	}
	// уже не работает

	ofstream ofstr("whatsread.txt", ios::binary);
	for (int i = 0; i < plate.size(); i++)
	{
		ofstr << "Object number: " << i << "\n";
		ofstr << plate[i].get()->name;
		ofstr << plate[i].get()->amount;
		ofstr << plate[i].get()->price;
	}
	ofstr.close();
}

void Salad::WriteToFile(CArchive& ar)
{
	ar << plate.size();
	for (auto o : plate)
	{
		ar << o.get();
	}
}

void Salad::ClearPlate()
{
	plate.clear();
}

int Salad::GetPlateSize()
{
	return plate.size();
}

void Salad::AddFruit(shared_ptr<Fruit> fruit)
{
	plate.push_back(fruit);
}

void Salad::AddApple()
{
	auto apple = make_shared<Apple>();
	plate.push_back(apple);
}