
#include"Func.h"

using namespace std;

string stateM;
void MainMenu() {
	cout << "    ����\n"
		<< "(0) �����\n"
		<< "(1) ��������� ����������\n"
		<< "(2) ��������� ���������\n"
		<< "(3) ����������� ���������\n"
		<< "(4) ��������� ����������\n"
		<< "(5) ����� ���������\n"
		<< "��� ����: ";
	cin >> stateM;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string InputOrders = "InputOrders.txt";
	string InputSlaveOrders = "InputSlaveOrders.txt";
	string OutputOrders = "OutputOrders.txt";

	int kolOrders = KolElFronFile(InputOrders);
	int kolSlaveOrders = KolElFronFile(InputSlaveOrders);

	Orders *T = new Orders[kolOrders];
	TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];

	ReadFromFileAboutOrders(T, InputOrders);
	ReadFromFileAboutSOrders(S, InputSlaveOrders);

	system("pause");
	system("cls");
	MainMenu();

	while (stateM != "0") {

		if (stateM == "1") {
			system("cls");

			string state;
			cout << "(1) ������ master\n"
				<< "(2) ������ slave\n"
				<<"��� ����: ";
			cin >> state;

			system("cls");

			if (state == "1") {

				int Id;
				string name, sname;
				string type;
				string tIn, dIn, tOut, dOut;

				int newKolOrders = kolOrders + 1;
				Orders *T1 = new Orders[newKolOrders];
				ReadFromFileAboutOrders(T1, InputOrders);

				Id = newKolOrders;
				cout << "������ ��'�: ";
				cin >> name;
				cout << "������ �������: \n";
				cin >> sname;
				cout << "������ ��� ����������: ";
				cin >> type;
				cout << "������ ��� ��������� �� ��� ����������: ";
				cin >> tIn >> dIn >> tOut >> dOut;

				T1[newKolOrders - 1].SetParametrs(Id, name, sname, type, tIn, dIn, tOut, dOut);
				WriteInFileInputOrders(newKolOrders, InputOrders, T1);

				kolOrders = KolElFronFile(InputOrders);
				Orders *T = new Orders[kolOrders];
				ReadFromFileAboutOrders(T, InputOrders);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");

			}
			else if (state == "2") {

				int master;
				int slave;
				string stype;
				int sprice;
				int quan;

				int newKolSlaveOrders = kolSlaveOrders + 1;
				TypeOfSlave *S1 = new TypeOfSlave[newKolSlaveOrders];
				ReadFromFileAboutSOrders(S1, InputSlaveOrders);

				cout << "������ ����� ������� �� ����� ������ ������ slave: ";
				cin >> master;
				slave = newKolSlaveOrders;
				cout << "������ ���������� ��: ";
				cin >> stype;
				cout << "������ ����: ";
				cin >> sprice;
				cout << "������ �������: ";
				cin >> quan;

				S1[newKolSlaveOrders - 1].SetParametrs(master, slave, stype, sprice, quan);
				WriteInFileInputSOrders(newKolSlaveOrders, InputSlaveOrders, S1);

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");

			}
			else {

				cout << "�������\n";

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}

		if (stateM == "2") {
			system("cls");

			string state;
			cout << "(1) �������� master\n"
				<< "(2) �������� slave\n"
				<< "��� ����: ";
			cin >> state;

			system("cls");

			if (state == "1") {

				kolOrders = KolElFronFile(InputOrders);
				Orders *T = new Orders[kolOrders];
				ReadFromFileAboutOrders(T, InputOrders);

				int Id = 0;
				string name = "", sname = "";
				string type = "";
				string tIn = "", dIn = "", tOut = "", dOut = "";

				int indexDel;
				cout << "������ ����� ����������, ��� ������ �������� �� 1 �� " << kolOrders << " : ";
				cin >> indexDel;

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);
				for (int i = 0; i < kolSlaveOrders; i++) {
					bool check = S[i].masterSearch(indexDel);
					if (check == true) {
						int master = 0;
						int slave = 0;
						string stype = "";
						int sprice = 0;
						int quan = 0;
						int indexDel2 = i;

						S[indexDel2].SetParametrs(master, slave, stype, sprice, quan);
						WriteInFileInputSOrders(InputSlaveOrders, S, kolSlaveOrders);

						kolSlaveOrders = KolElFronFile(InputSlaveOrders);
						S = new TypeOfSlave[kolSlaveOrders];
						ReadFromFileAboutSOrders(S, InputSlaveOrders);

						i--;
					}
				}

				T[indexDel - 1].SetParametrs(Id, name, sname, type, tIn, dIn, tOut, dOut);
				WriteInFileInputOrders(InputOrders, T, kolOrders);

				kolOrders = KolElFronFile(InputOrders);
				T = new Orders[kolOrders];
				ReadFromFileAboutOrders(T, InputOrders);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else if (state == "2") {

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);

				int master = 0;
				int slave = 0;
				string stype = "";
				int sprice = 0;
				int quan = 0;

				int indexDel;
				cout << "������ ����� ����������, ��� ������ �������� �� 1 �� " << kolSlaveOrders << " : ";
				cin >> indexDel;

				S[indexDel - 1].SetParametrs(master, slave, stype, sprice, quan);
				WriteInFileInputSOrders(InputSlaveOrders, S, kolSlaveOrders);

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else {

				cout << "�������\n";

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}

		if (stateM == "3") {
			system("cls");

			string state;
			cout << "(1) ���������� master\n"
				<< "(2) ���������� slave\n"
				<< "��� ����: ";
			cin >> state;

			system("cls");

			if (state == "1") {

				kolOrders = KolElFronFile(InputOrders);
				Orders *T = new Orders[kolOrders];
				ReadFromFileAboutOrders(T, InputOrders);

				int Id;
				string name, sname;
				string type;
				string tIn, dIn, tOut, dOut;

				int index;
				cout << "������ ����� ����������, � ����� ������ ������ ��������� �� 1 �� " << kolOrders << " : ";
				cin >> index;

				Id = index;
				cout << "������ ��'�: ";
				cin >> name;
				cout << "������ �������: ";
				cin >> sname;
				cout << "������ ��� ����������: ";
				cin >> type;
				cout << "������ ��� ��������� �� ��� ����������: ";
				cin >> tIn >> dIn >> tOut >> dOut;

				T[index - 1].SetParametrs(Id, name, sname, type, tIn, dIn, tOut, dOut);
				WriteInFileInputOrders(kolOrders, InputOrders, T);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else if (state == "2") {

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);

				int master;
				int slave;
				string stype;
				int sprice;
				int quan;

				int index;
				cout << "������ ����� ����������, � ����� ������ ������ ��������� �� 1 �� " << kolSlaveOrders << " : ";
				cin >> index;

				master = S[index - 1].GetMaster_id();
				slave = index;
				cout << "������ ���������� ��: ";
				cin >> stype;
				cout << "������ ����: ";
				cin >> sprice;
				cout << "������ �������: ";
				cin >> quan;

				S[index - 1].SetParametrs(master, slave, stype, sprice, quan);
				WriteInFileInputSOrders(kolSlaveOrders, InputSlaveOrders, S);

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else {

				cout << "�������\n";

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}

		if (stateM == "4") {
			system("cls");

			bool w;
			cout << "������� � �������/� ���� (1/0): ";
			cin >> w;
			system("cls");

			kolOrders = KolElFronFile(InputOrders);
			Orders *T = new Orders[kolOrders];
			ReadFromFileAboutOrders(T, InputOrders);

			kolSlaveOrders = KolElFronFile(InputSlaveOrders);
			TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
			ReadFromFileAboutSOrders(S, InputSlaveOrders);

			if (w) {
				for (int i = 0; i < kolOrders; i++) {
					T[i].Print();
					cout << "****************************\n";
					for (int j = 0; j < kolSlaveOrders; j++) {
						bool check = S[j].masterSearch(i + 1);
						if (check == true) {
							S[j].Print();
							cout << "    ************************\n";
						}
					}
				}
			}
			else {
				WriteInFileOrders(OutputOrders, T, S, kolSlaveOrders, kolOrders);
				cout << "���������� �������� � ���� \"" << OutputOrders << "\"\n";
			}

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}

		if (stateM == "5") {
			system("cls");

			string state;
			cout << "(1) ������ master\n"
				<< "(2) ������ slave\n"
				<< "��� ����: ";
			cin >> state;

			system("cls");

			if (state == "1") {

				kolOrders = KolElFronFile(InputOrders);
				Orders *T = new Orders[kolOrders];
				ReadFromFileAboutOrders(T, InputOrders);

				int IdS;
				string nameS, snameS;
				string typeS;
				string tInS, dInS, tOutS, dOutS;

				cout << "������ ID ���������� (����������: 0): ";
				cin >> IdS;
				cout << "������ ��'� �� ������� (����������: - -): ";
				cin >> nameS >> snameS;
				cout << "������ ��� ���������� (����������: -): ";
				cin >> typeS;
				cout << "������ ��� ��������� (����������: - -): ";
				cin >> tInS >> dInS;
				cout << "************************\n";

				int IndexSearch = 0;
				int IndexSearch1 = 0;

				for (int i = 0; i < kolOrders; i++) {
					IndexSearch1 = IndexSearch1 + T[i].OrdersSearch(IdS, nameS, snameS, typeS, tInS, dInS, IndexSearch);
				}
				if (IndexSearch1 == kolOrders) {
					cout << "���������� �� ��������\n"
						<< "************************\n";
				}

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else if (state == "2") {

				kolSlaveOrders = KolElFronFile(InputSlaveOrders);
				TypeOfSlave *S = new TypeOfSlave[kolSlaveOrders];
				ReadFromFileAboutSOrders(S, InputSlaveOrders);

				int slave;
				string stype;
				int sprice;
				int quan;

				cout << "������ ID ���������� (����������: 0): ";
				cin >> slave;
				cout << "������ ���������� �� (����������: -): ";
				cin >> stype;
				cout << "������ ���� (����������: 0): ";
				cin >> sprice;
				cout << "������ ������� (����������: 0): ";
				cin >> quan;
				cout << "************************\n";

				int IndexSearch = 0;
				int IndexSearch1 = 0;

				for (int i = 0; i < kolSlaveOrders; i++) {
					IndexSearch1 = IndexSearch1 + S[i].SlaveSearch(slave, stype, sprice, quan, IndexSearch);
				}
				if (IndexSearch1 == kolSlaveOrders) {
					cout << "���������� �� ��������\n"
						<< "************************\n";
				}

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
			else {

				cout << "�������\n";

				system("pause");
				system("cls");
				MainMenu();
				system("cls");
			}
		}
		if (stateM != "0" && stateM != "1" && stateM != "2" && stateM != "3" && stateM != "4" && stateM != "5") {
			cout << "_________________________________________________________\n"
				<< "������ ������� ����. ������ ������ �� ��������������.\n"
				<< "_________________________________________________________*\n";

			system("pause");
			system("cls");
			MainMenu();
			system("cls");
		}
	}
	system("cls");
}
