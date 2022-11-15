
#include "Orders.h"

Orders::Orders() {
	IdOrder = 0;
	nameOrder = "";
	snameOrder = "";
	typeOrder = "";
	timeIn = "";
	dateIn = "";
	timeOut = "";
	dateOut = "";
}

Orders::Orders(int Id, string name, string sname, string type, string tIn, string dIn, string tOut, string dOut) {
	IdOrder = Id;
	nameOrder = name;
	snameOrder = sname;
	typeOrder = type;
	timeIn = tIn;
	dateIn = dIn;
	timeOut = tOut;
	dateOut = dOut;
}

Orders::~Orders() {
}

void Orders::Print() {
	if (IdOrder != 0) {
		cout << "ID працівника: " << IdOrder << endl;
		cout << "ФІО працівника: " << nameOrder <<" "<< snameOrder << endl;
		cout << "Тип товару: " << typeOrder << endl;
		cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
	}
}

void Orders::SetParametrs(int Id, string name, string sname, string type, string tIn, string dIn, string tOut, string dOut) {
	IdOrder = Id;
	nameOrder = name;
	snameOrder = sname;
	typeOrder = type;
	timeIn = tIn;
	dateIn = dIn;
	timeOut = tOut;
	dateOut = dOut;
}

void Orders::AddToFile(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		fout << "ID працівника: " << IdOrder << endl;
		fout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
		fout << "Тип товару: " << typeOrder << endl;
		fout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
		fout << "____________________________\n";
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}

void Orders::AddToFile1(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		if (IdOrder != 0) {
			fout << IdOrder << endl;
			fout << nameOrder << " " << snameOrder << endl;
			fout << typeOrder << endl;
			fout << timeIn << " " << dateIn << " " << timeOut << " " << dateOut << endl;
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}

void Orders::CSearch(int arr[], int i, bool check) {
	if (arr[i] == typeOrder[0] || arr[i] == IdOrder) {

		cout << "ID працівника: " << IdOrder << endl;
		cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
		cout << "Тип товару: " << typeOrder << endl;
		cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
		cout << "________________________\n";

		AddToFile("OutputOrders.txt");

		check = true;
	}
}

int Orders::OrdersSearch(int IdS, string nameS, string snameS, string typeS, string tInS, string dInS, int IndexSearch) {

	int snameIndex = 0;
	int nameIndex = 0;
	if (nameS.size() <= nameOrder.size() && nameS != "-") {
		for (int i = 0; i < nameOrder.size() - nameS.size() + 1; i++) {
			if (nameOrder[i] == nameS[0]) {
				for (int j = 0; j < nameS.size(); j++) {
					if (nameOrder[i] == nameS[j]) {
						nameIndex++;
					}
					i++;
				}
			}
		}
	}

	if (nameS == "-") {
		nameIndex = nameS.size();
	}

	if (nameIndex == 0) {
		nameIndex = nameS.size() + 1;
	}

	if (snameS.size() <= snameOrder.size() && snameS != "-") {
		for (int i = 0; i < snameOrder.size() - snameS.size() + 1; i++) {
			if (snameOrder[i] == snameS[0]) {
				for (int j = 0; j < snameS.size(); j++) {
					if (snameOrder[i] == snameS[j]) {
						snameIndex++;
					}
					i++;
				}
			}
		}
	}

	if (snameS == "-") {
		snameIndex = snameS.size();
	}

	if (snameIndex == 0) {
		snameIndex = snameS.size() + 1;
	}
	if (IdS == IdOrder || IdS == 0) {
		if (nameIndex == nameS.size() && snameIndex == snameS.size()) {
			if (typeS == typeOrder || typeS == "-") {
				if (tInS != "-" && dInS != "-") {

					string sYear = "0000";
					string tYear = "0000";

					string sMonth = "00";
					string tMonth = "00";

					string sDay = "00";
					string tDay = "00";

					string sHour = "00";
					string tHour = "00";

					string sMinute = "00";
					string tMinute = "00";

					for (int i = 6; i < 10; i++) {

						int j = 0;

						sYear[j] = dInS[i];
						tYear[j] = dateIn[i];

						j++;
					}

					for (int i = 3; i < 5; i++) {

						int j = 0;

						sMonth[j] = dInS[i];
						tMonth[j] = dateIn[i];

						j++;
					}

					for (int i = 0; i < 2; i++) {
						sDay[i] = dInS[i];
						tDay[i] = dateIn[i];
					}

					for (int i = 0; i < 2; i++) {
						sHour[i] = tInS[i];
						tHour[i] = timeIn[i];
					}

					for (int i = 3; i < 5; i++) {

						int j = 0;

						sMinute[j] = tInS[i];
						tMinute[j] = timeIn[i];

						j++;
					}

					int syear = atoi(sYear.c_str());
					int tyear = atoi(tYear.c_str());

					int smonth = atoi(sMonth.c_str());
					int tmonth = atoi(tMonth.c_str());

					int sday = atoi(sDay.c_str());
					int tday = atoi(tDay.c_str());

					int shour = atoi(sHour.c_str());
					int thour = atoi(tHour.c_str());

					int sminute = atoi(sMinute.c_str());
					int tminute = atoi(tMinute.c_str());

					if (syear > tyear) {
						IndexSearch++;
					}
					if (syear == tyear) {
						if (smonth > tmonth) {
							IndexSearch++;
						}
						if (smonth == tmonth) {
							if (sday > tday) {
								IndexSearch++;
							}
							if (sday == tday) {
								if (shour > thour) {
									IndexSearch++;
								}
								if (shour == thour) {
									if (sminute > tminute) {
										IndexSearch++;
									}
								}
							}
						}
					}

					if (syear < tyear) {
						cout << "ID працівника: " << IdOrder << endl;
						cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
						cout << "Тип товару: " << typeOrder << endl;
						cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
						cout << "_______________________\n" << endl;
					}
					if (syear == tyear) {
						if (smonth < tmonth) {
							cout << "ID працівника: " << IdOrder << endl;
							cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
							cout << "Тип товару: " << typeOrder << endl;
							cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
							cout << "____________________________\n" << endl;
						}
						if (smonth == tmonth) {
							if (sday < tday) {
								cout << "ID працівника: " << IdOrder << endl;
								cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
								cout << "Тип товару: " << typeOrder << endl;
								cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
								cout << "___________________________\n" << endl;
							}
							if (sday == tday) {
								if (shour < thour) {
									cout << "ID працівника: " << IdOrder << endl;
									cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
									cout << "Тип товару: " << typeOrder << endl;
									cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
									cout << "_______________________\n" << endl;
								}
								if (shour == thour) {
									if (sminute <= tminute) {
										cout << "ID працівника: " << IdOrder << endl;
										cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
										cout << "Тип товару: " << typeOrder << endl;
										cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
										cout << "_______________________\n" << endl;
									}
								}
							}
						}
					}
				}
				else {
					cout << "ID працівника: " << IdOrder << endl;
					cout << "ФІО працівника: " << nameOrder << " " << snameOrder << endl;
					cout << "Тип товару: " << typeOrder << endl;
					cout << "Час прийняття: " << timeIn << " " << dateIn << " " << "час завершення: " << timeOut << " " << dateOut << endl;
					cout << "_______________________\n" << endl;
				}

			}
			else {
				IndexSearch++;
			}
		}
		else {
			IndexSearch++;
		}
	}
	else {
		IndexSearch++;
	}

	return IndexSearch;

}