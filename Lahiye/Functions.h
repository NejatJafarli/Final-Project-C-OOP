#pragma once
#include <iostream>
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<string>
#include <windows.h>
#include <vector>
#include<fstream>
#include<sstream>
using namespace std;

enum Direction { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13 };
void mySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}
int login(int select) {
	while (true) {
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "As Guest Click\n";
			mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "As Admin Click\n";
			mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Register Guest\n";
			mySetColor(7, 0);
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				if (select - 1 != 0) {
					system("cls");
					select--;
					continue;
				}
				else {
					system("cls");
					select=3;
					continue;
				}
			}
			else if (key == DOWN)
			{
				if (select + 1 != 4) {
					system("cls");
					select++;
					continue;
				}
				else {
					system("cls");
					select = 1;
					continue;
				}
			}
		}
		else if (key == ENTER)
		{
			return select;
		}
		system("cls");
	}
}
int SelectWhatDoYouAdd(const string& temp,int select=1) {
	while (true) {
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << temp<<" Notebook\n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << temp << " Component\n";
		mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << temp << " Phone\n";
		mySetColor(7, 0);
		if (select == 4) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Exit This Panel\n";
		mySetColor(7, 0);
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				if (select - 1 != 0) {
					system("cls");
					select--;
					continue;
				}
				else {
					system("cls");
					select = 4;
					continue;
				}
			}
			else if (key == DOWN)
			{
				if (select + 1 != 5) {
					system("cls");
					select++;
					continue;
				}
				else {
					system("cls");
					select = 1;
					continue;
				}
			}
		}
		else if (key == ENTER)
		{
			if (select==4)
			{
				return -1;
			}
			return select;
		}
		system("cls");
	}
}
int ComponentSelect(int select=1) {
	while (true) {
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add Cpu\n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add Monitor\n";
		mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add VideoCard\n";
		mySetColor(7, 0);
		if (select == 4) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add Memory\n";
		mySetColor(7, 0);
		if (select == 5) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add SSD\n";
		mySetColor(7, 0);
		if (select == 6) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add HDD\n";
		mySetColor(7, 0);
		if (select == 7) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Exit This Panel\n";
		mySetColor(7, 0);
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				if (select - 1 != 0) {
					system("cls");
					select--;
					continue;
				}
				else {
					system("cls");
					select = 7;
					continue;
				}
			}
			else if (key == DOWN)
			{
				if (select + 1 != 8) {
					system("cls");
					select++;
					continue;
				}
				else {
					system("cls");
					select = 1;
					continue;
				}
			}
		}
		else if (key == ENTER)
		{
			return select;
		}
		system("cls");
	}
}
int CartMenuForComponent(int select = 1) {
	while (true) {
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Buy \n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Delete This item in Cart\n";
		mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Exit\n";
		mySetColor(7, 0);
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				if (select - 1 != 0) {
					system("cls");
					select--;
					continue;
				}
				else
				{
					system("cls");
					select = 3;
					continue;
				}
			}
			else if (key == DOWN)
			{
				if (select + 1 != 4) {
					system("cls");
					select++;
					continue;
				}
				else
				{
					system("cls");
					select = 1;
					continue;
				}
			}
		}
		else if (key == ENTER)
		{
			return select;
		}
		system("cls");
	}
}
int AdminPanel(const string& name, int select = 1) {
	while (true) {
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[1]ShowAll" << name << "\n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[2]add" << name << "\n";
		mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[3]Delete" << name << "\n";
		mySetColor(7, 0);
		if (select == 4) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[4]Uptade" << name << "\n";
		mySetColor(7, 0);
		if (select == 5) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[5]Read Notifications\n";
		mySetColor(7, 0);

		cout << "\n\n";
		if (select == 6) {
			mySetColor(4, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "[6]Add Category\n\n";
		mySetColor(7, 0);
		if (select == 7) {
			mySetColor(4, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "[7]Delete Category\n\n";
		mySetColor(7, 0);
		if (select == 8) {
			mySetColor(4, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "[8]Change Category Name\n\n";
		mySetColor(7, 0);

		if (select == 9) {
			mySetColor(2, 0);
			cout << "\t\t\t-->> ";
		}
		else cout << "\t\t\t";
		cout << "[9]Exit Control Panel\n\n";
		mySetColor(7, 0);
		int key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == UP)
			{
				if (select - 1 != 0) {
					system("cls");
					select--;
					continue;
				}
				else
				{
					system("cls");
					select = 9;
					continue;
				}
			}
			else if (key == DOWN)
			{
				if (select + 1 != 10) {
					system("cls");
					select++;
					continue;
				}
				else
				{
					system("cls");
					select = 1;
					continue;
				}
			}
		}
		else if (key == ENTER)
		{
			return select;
		}
		system("cls");
	}
}
void ReadNot() {
	ifstream fin("not.txt", ios::in);
	if (fin.is_open()) {
		string value;
		while (!fin.eof())
		{
			getline(fin, value);
			mySetColor(4, 0);
			cout <<"\t\t"<< value << endl;
		}
			mySetColor(7, 0);
	}
	fin.close();
}
void AddPrice(int Price) {
	ifstream fin("Income.txt",ios::in);
	int CurrentPrice=0;
	if (fin.is_open())
	{
		string temp;
		fin >> temp;
		fin >> temp;
		fin >> temp;

		fin >> temp;
		stringstream temp2(temp);
		temp2 >> CurrentPrice;
	}
	fin.close();
	remove("Income.txt");
	ofstream fout("Income.txt", ios::app);
	if (fout.is_open())
	{
		fout << "Your Totaly Income: " << to_string(Price+CurrentPrice);
	}
	fout.close();
}
string Taketime() {
	time_t now = time(0);
	char dt[30]{};
	ctime_s(dt, sizeof dt, &now);
	string time = dt;
	return time;
};
