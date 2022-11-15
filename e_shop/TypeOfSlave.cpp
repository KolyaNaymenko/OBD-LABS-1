
#include "TypeOfSlave.h"

TypeOfSlave::TypeOfSlave() {
	master_id = 0;
	slave_id = 0;
	slave_type = "";
	price = 0;
	quantity = 0;
}

TypeOfSlave::TypeOfSlave(int master, int slave, string stype, int sprice, int quan) {
	master_id = master;
	slave_id = slave;
	slave_type = stype;
	price = sprice;
	quantity = quan;
}

TypeOfSlave::~TypeOfSlave() {

}

void TypeOfSlave::SetParametrs(int master, int slave, string stype, int sprice, int quan) {
	master_id = master;
	slave_id = slave;
	slave_type = stype;
	price = sprice;
	quantity = quan;
}

void TypeOfSlave::Print() {
	cout << "    ID ����������: " << slave_id << endl;
	cout << "    ����� ��: " << slave_type << endl;
	cout << "    ֳ��: " << price << " ���" << endl;
	cout << "    ʳ������: " << quantity << endl;
}

void TypeOfSlave::AddToFile1(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		if (slave_id != 0) {
			fout << master_id << endl;
			fout << slave_id << endl;
			fout << slave_type << endl;
			fout << price << endl;
			fout << quantity << endl;
		}
	}
	else {
		cout << "������� �������� �����. \n";
	}
	fout.close();
}

void TypeOfSlave::AddToFile(string NameF) {
	ofstream fout(NameF, std::ios::app);

	if (fout.is_open()) {
		fout << "    ID ����������: " << slave_id << endl;
		fout << "    ����� ��: " << slave_type << endl;
		fout << "    ֳ��: " << price << endl;
		fout << "    ʳ������: " << quantity << endl;
		fout << "    ________________________\n";
	}
	else {
		cout << "������� �������� �����. \n";
	}
	fout.close();
}

bool TypeOfSlave::masterSearch(int master) {
	bool check = false;
	if (master_id == master) {
		check = true;
	}
	return check;
}

int TypeOfSlave::SlaveSearch(int slave, string stype, int sprice, int quan, int IndexSearch) {
	if (slave_id == slave || slave == 0) {
		if (slave_type == stype || stype == "-") {
			if (price == sprice || sprice == 0) {
				if (quantity == quan || quan == 0) {
					cout << "ID ����������: " << slave_id << endl;
					cout << "����� ��: " << slave_type << endl;
					cout << "ֳ��: " << price << " ���" << endl;
					cout << "ʳ������: " << quantity << endl;
					cout << "_____________________\n" << endl;
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
	}
	else {
		IndexSearch++;
	}
	return IndexSearch;
}