
#include "Func.h"

int KolElFronFile(string nameFile) {
	ifstream fin(nameFile);
	int k;

	if (fin.is_open()) {
		fin >> k;
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fin.close();
	return k;
}

void ReadFromFileAboutOrders(Orders *T, string nameFile) {
	ifstream fin(nameFile);

	int k;
	int Id;
	string name, sname;
	string type;
	string tIn, dIn, tOut, dOut;

	if (fin.is_open()) {
		fin >> k;
		for (int i = 0; i < k; i++) {
			fin >> Id;
			fin >> name >> sname;
			fin >> type;
			fin >> tIn >> dIn >> tOut >> dOut;

			T[i].SetParametrs(Id, name, sname, type, tIn, dIn, tOut, dOut);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fin.close();
}

void ReadFromFileAboutSOrders(TypeOfSlave *S, string nameFile) {
	ifstream fin(nameFile);

	int k;
	int master;
	int slave;
	string stype;
	int sprice;
	int quan;

	if (fin.is_open()) {
		fin >> k;
		for (int i = 0; i < k; i++) {
			fin >> master;
			fin >> slave;
			fin >> stype;
			fin >> sprice;
			fin >> quan;

			S[i].SetParametrs(master, slave, stype, sprice, quan);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fin.close();
}

void WriteInFileOrders(string nameF, Orders *T, TypeOfSlave *S, int n1, int n) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		for (int i = 0; i < n; i++) {
			T[i].AddToFile(nameF);
			for (int j = 0; j < n1; j++) {
				bool check = S[j].masterSearch(i + 1);
				if (check == true) {
					S[j].AddToFile(nameF);
				}
			}
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}

void WriteInFileInputOrders(string nameF, Orders *T, int n) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n - 1 << endl;
		for (int i = 0; i < n; i++) {
			T[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}

void WriteInFileInputSOrders(string nameF, TypeOfSlave *S, int n) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n - 1 << endl;
		for (int i = 0; i < n; i++) {
			S[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}



void WriteInFileInputOrders(int n, string nameF, Orders *T) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			T[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}

void WriteInFileInputSOrders(int n, string nameF, TypeOfSlave *S) {
	ofstream fout(nameF, std::ios::out);
	if (fout.is_open()) {
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			S[i].AddToFile1(nameF);
		}
	}
	else {
		cout << "Помилка відкриття файлу. \n";
	}
	fout.close();
}
