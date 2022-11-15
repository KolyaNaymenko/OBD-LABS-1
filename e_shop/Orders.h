#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Orders {
private:
	int IdOrder;
	string nameOrder, snameOrder;
	string typeOrder;
	string timeIn, dateIn, timeOut, dateOut;

public:
	Orders();
	Orders(int Id, string name, string sname, string type, string tIn, string dIn, string tOut, string dOut);
	~Orders();

	void Print();
	int OrdersSearch(int IdS, string nameS, string snameS, string typeS, string tInS, string dInS, int IndexSearch);
	void SetParametrs(int Id, string name, string sname, string type, string tIn, string dIn, string tOut, string dOut);
	void CSearch(int arr[], int i, bool check);

	int GetNumberOrder() { return IdOrder; };
	string GetNameOrder() { return nameOrder; };
	string GetSnameOrder() { return snameOrder; };
	string GetTypeTrain() { return typeOrder; };
	string GetTimeIn() { return timeIn; };
	string GetDateIn() { return dateIn; };
	string GetTimeOut() { return timeOut; };
	string GetDateOut() { return dateOut; };
	void AddToFile(string NameF);
	void AddToFile1(string NameF);
};
