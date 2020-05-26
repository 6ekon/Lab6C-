#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <io.h>
#include <sstream>

using namespace std;

struct Rivers
{
    string rivername;
    int riverlenghth = 0;
    int avgdepth = 0;
};

void InputOutput(Rivers* mas, const int amount)
{
    for (int i = 0; i < amount; i++)
    {
        cout << "\nНазвание реки: ";
        cin >> mas[i].rivername; cin.ignore();
        cout << "Длина реки (в км): ";
        cin >> mas[i].riverlenghth;
        cout << "Глубина реки (в м): ";
        cin >> mas[i].avgdepth;
    }
    cout << "\n\n";
    for (int i = 0; i < amount; i++)
    {
        cout << "\nНазвание реки: " << mas[i].rivername << endl;
        cout << "Длина реки (в км): " << mas[i].riverlenghth << endl;
        cout << "Глубина реки (в м): " << mas[i].avgdepth << endl;
    }
}

void Write2file(Rivers* mas, const int amount)
{
    int sum = 0;
    ofstream file("D:\\River.txt", ios::binary | ios::out);
    for (int i = 0; i < amount; i++)
    {
        if (mas[i].avgdepth < 50)
        {
            sum += mas[i].riverlenghth;
        }
        file.write((char*)&mas[i].rivername, sizeof mas[i].rivername);
        file.write((char*)&mas[i].riverlenghth, sizeof mas[i].riverlenghth);
        file.write((char*)&mas[i].avgdepth, sizeof mas[i].avgdepth);
    }
    file.close();
}

void task1()
{
    int amount;
    cout << "Количество рек: ";
    cin >> amount;
    Rivers* mas = new Rivers[amount];
    InputOutput(mas, amount);
    Write2file(mas, amount);
    delete[] mas;
}

void task2()
{
    int value1[10], value2[10], count = 0, avg = 0, n = 0;
    ofstream file("D:\\Veshchisla.txt", ios::binary | ios::out);
    cout << "№1\n";
    for (int i = 0; i <= 8; i++)
    {
        value1[i] = -5 + rand() % 10;
        cout << value1[i] << " ";
        file.write((char*)&value1[i], sizeof value1[i]);
    }
    file.close();
    cout << "\n";
    ifstream  file2("D:\\Veshchisla.txt", ios::binary | ios::in);
    cout << "№2\n";
    for (int i = 0; i <= 8; i++)
    {
        file2.read((char*)&value2[i], sizeof value2[i]);
        if (value2[i] < 0)
        {
            count++;
            avg += value2[i];
            n = avg / count;
            value2[i] += n;
        }
        else if (value2[i] > 0)
        {
            value2[i] -= n;
        }
        cout << value2[i] << " ";
    }
    file2.close();
    ofstream file3("D:\\Veshchisla.txt", ios::binary | ios::out);
    for (int i = 0; i <= 9; i++)
    {
        file3.write((char*)&value1[i], sizeof value2[i]);
    }
    file3.close();
}

struct Laboratorywork
{
    string laboratoryname;
    short laboratorynum;
    short laboratoryhours;
    short laboratoryrealhours;
    string laboratorymark;
};

void InputOutput(Laboratorywork* mass, const int amountt)
{
    for (int i = 0; i < amountt; i++)
    {
        cout << "\nНазвание Лабораторной работы: ";
        cin >> mass[i].laboratoryname; cin.ignore();
        cout << "Номер Лабораторной работы: ";
        cin >> mass[i].laboratorynum;
        cout << "Количество часов на выполнение работы: ";
        cin >> mass[i].laboratoryhours;
        cout << "Реально затраченное время на выполнение работы: ";
        cin >> mass[i].laboratoryrealhours;
        cout << "Оценка за выполненную работу: ";
        cin >> mass[i].laboratorymark; cin.ignore();
    }
    cout << "\n\n";
    for (int i = 0; i < amountt; i++)
    {
        cout << "\nНазвание Лабораторной работы: " << mass[i].laboratoryname << endl;
        cout << "Номер Лабораторной работы: " << mass[i].laboratorynum << endl;
        cout << "Количество часов на выполнение работы: " << mass[i].laboratoryhours << endl;
        cout << "Реально затраченное время на выполнение работы: " << mass[i].laboratoryrealhours << endl;
        cout << "Оценка за выполненную работу: " << mass[i].laboratorymark << endl;
    }
}

void Write2file(Laboratorywork* mass, const int amountt)
{
    ofstream file("D:\\Laboratory.txt", ios::binary | ios::out);
    for (int i = 0; i < amountt; i++)
    {
        if (mass[i].laboratoryrealhours < mass[i].laboratoryhours && mass[i].laboratorymark == "Неудовлетворительно")
        {
            mass[i].laboratoryhours += 5;
        }
        file.write((char*)&mass[i].laboratoryname, sizeof mass[i].laboratoryname);
        file.write((char*)&mass[i].laboratorynum, sizeof mass[i].laboratorynum);
        file.write((char*)&mass[i].laboratoryhours, sizeof mass[i].laboratoryhours);
        file.write((char*)&mass[i].laboratoryrealhours, sizeof mass[i].laboratoryrealhours);
        file.write((char*)&mass[i].laboratorymark, sizeof mass[i].laboratorymark);
    }
    file.close();
}

void task3()
{
    int amountt;
    cout << "Введить количество Лабораторных работ: ";
    cin >> amountt;
    Laboratorywork* mass = new Laboratorywork[amountt];
    InputOutput(mass, amountt);
    Write2file(mass, amountt);
}

int main()
{
	short task;
    setlocale(0, "");
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	cout << "Choose your task (available 1, 2, 3): ";
	cin >> task;
	switch (task)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	}
	return 0;
}

