#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

#include "TypeOfSlave.h"
#include "Orders.h"
#include "Func.h"

using namespace std;

int KolElFronFile(string nameFile);
void ReadFromFileAboutOrders(Orders *T, string nameFile);
void ReadFromFileAboutSOrders(TypeOfSlave *S, string nameFile);
void WriteInFileOrders(string nameF, Orders *T, TypeOfSlave *S, int n1, int n);
void WriteInFileInputOrders(string nameF, Orders *T, int n);
void WriteInFileInputSOrders(string nameF, TypeOfSlave *S, int n);
void WriteInFileInputOrders(int n, string nameF, Orders *T);
void WriteInFileInputSOrders(int n, string nameF, TypeOfSlave *S);
