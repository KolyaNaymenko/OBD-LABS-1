#pragma once

#include<string>
#include<iostream>
#include <fstream>

using namespace std;

class TypeOfSlave {
private:
	int master_id;
	int slave_id;
	string slave_type;
	int price;
	int quantity;

public:
	TypeOfSlave();
	TypeOfSlave(int master, int slave, string stype, int sprice, int quan);
	~TypeOfSlave();

	void Print();
	int GetMaster_id() { return master_id; };
	int GetSlave_id() { return slave_id; };
	string GetSlave_type() { return slave_type; };
	int GetPrice() { return price; };
	int GetQuantity() { return quantity; };

	void SetParametrs(int master, int slave, string stype, int sprice, int quan);
	void AddToFile1(string NameF);
	void AddToFile(string NameF);
	bool masterSearch(int master);
	int SlaveSearch(int slave, string stype, int sprice, int quan, int IndexSearch);
};