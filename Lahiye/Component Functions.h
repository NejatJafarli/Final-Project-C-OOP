#pragma once
#include"Component.h"
Monitor* CreateMonitor() {
	mySetColor(6, 0);
	cout << "\t\tMonitor Inch ->";
	double inch;
	mySetColor(2, 0);
	cin >> inch;
	cout << "\t\tMonitor hz ->";
	int monitorhz;
	mySetColor(6, 0);
	cin >> monitorhz;
	cout << "\t\tMonitor Price ->";
	int price;
	mySetColor(2, 0);
	cin >> price;
	Monitor *m=new Monitor(" ",inch, monitorhz, price, 0);
	return m;
}
Cpu* CreateCpu() {
	mySetColor(2, 0);
	cout << "\t\tCpu Name ->";
	string cname;
	mySetColor(6, 0);
	getline(cin >> ws, cname);
	cout << "\t\tCpu Price ->";
	int price;
	mySetColor(2, 0);
	cin >> price;
	cout << "\t\tCpu GHZ ->";
	double ghz;
	mySetColor(6, 0);
	cin >> ghz;
	cout << "\t\tCpu Core ->";
	int core;
	mySetColor(2, 0);
	cin >> core;
	cout << "\t\tCpu Thread ->";
	int thread;
	mySetColor(6, 0);
	cin >> thread;
	Cpu *c=new Cpu(price, cname, core, ghz, thread,0);
	mySetColor(7, 0);
	return c;
}
VideoCard* CreateVideoCard() {
	mySetColor(2, 0);
	cout << "\t\tVideo Card Name ->";
	string vname;
	mySetColor(6, 0);
	getline(cin >> ws, vname);
	mySetColor(6, 0);
	cout << "\t\tVideo Card Memory ->";
	int memory;
	mySetColor(2, 0);
	cin >> memory;
	mySetColor(2, 0);
	cout << "\t\tVideo Card Price ->";
	int price;
	mySetColor(6, 0);
	cin >> price;
	VideoCard *v=new VideoCard(vname, memory, price,0);
	mySetColor(7, 0);
	return v;
}
Memory* CreateMemory() {
	mySetColor(2, 0);
	cout << "\t\tMemory Name ->";
	string mname;
	mySetColor(6, 0);
	getline(cin >> ws, mname);
	cout << "\t\tMemory GB ->";
	int gb;
	mySetColor(2, 0);
	cin >> gb;
	cout << "\t\tMemory MHZ ->";
	int mhz;
	mySetColor(6, 0);
	cin >> mhz;
	cout << "\t\tMemory Price ->";
	int price;
	mySetColor(2, 0);
	cin >> price;
	Memory* m=new Memory(mname, gb, mhz, price, 0);
	return m;
}
SSD* CreateSSD() {
	mySetColor(2, 0);
	cout << "\t\tSSD Name ->";
	string SSDName;
	mySetColor(6, 0);
	getline(cin >> ws, SSDName);
	cout << "\t\tSSD Space->";
	int space;
	mySetColor(2, 0);
	cin >> space;
	cout << "\t\tSSD Price ->";
	int price;
	mySetColor(6, 0);
	cin >> price;
	SSD *s=new SSD(SSDName,space, price, 0);
	mySetColor(7, 0);
	return s;
}
HDD* CreateHDD() {
	mySetColor(2, 0);
	cout << "\t\tHDD Name ->";
	string HDDName;
	mySetColor(6, 0);
	getline(cin >> ws, HDDName);
	cout << "\t\tHDD Space->";
	int space;
	mySetColor(2, 0);
	cin >> space;
	cout << "\t\tHDD RPM ->";
	int RPM;
	mySetColor(6, 0);
	cin >> RPM;
	cout << "\t\tHDD Price ->";
	int price;
	mySetColor(2, 0);
	cin >> price;
	HDD *h=new HDD(HDDName,space, RPM, price, 0);
	mySetColor(7, 0);
	return h;
}
Notebook* CreateNotebook() {
		mySetColor(2, 0);
	cout << "\t\tNoteBook Name->";
	string name;
		mySetColor(6, 0);
	getline(cin >> ws, name);
	cout << "\t\tNoteBook Quality ->";
	int num;
		mySetColor(4, 0);
	cin >> num;
	cout << "------------------------------------\n";
		mySetColor(7, 0);

	try
	{
		auto m = CreateMonitor();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		auto c = CreateCpu();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		auto v = CreateVideoCard();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		auto me = CreateMemory();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		
		bool isSSD;
	while (true)
	{
		mySetColor(2, 0);
		cout << "\t\tHDD OR SSD -> ";
		string select;
		mySetColor(6, 0);
		cin >> select;
		mySetColor(7, 0);
		if (select == "hdd" || select == "HDD") {
			isSSD = 0;
			break;
		}
		else if (select == "SSD" || select == "ssd") {
			isSSD = 1;
			break;
		}
		else {
			mySetColor(4, 0);
			cout << "\t\tWront Input!!!";
			mySetColor(7, 0);
		}
	}
	if (isSSD)
	{
		auto s = CreateSSD();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		HDD *h=new HDD;
		Notebook*note=new Notebook(isSSD, name, *m, *c, *v, *me, *h, *s,num, 1);
		return note;
	}
	else
	{
		SSD *s=new SSD;
		auto h = CreateHDD();
		mySetColor(4, 0);
		cout << "------------------------------------\n";
		mySetColor(7, 0);
		Notebook*note=new Notebook(isSSD, name, *m, *c, *v, *me, *h, *s,num, 1);
		return note;
	}
	}
	catch (const Exception ex)
	{
		ex.printMsg();
	}
}

void UpdateNoteBook(Notebook* temp3,int select) {
	if (select == 1) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp3->setCategoryId(temp2);
	}
	if (select == 2)
	{
		mySetColor(4, 0);
		cout << "\t\tNoteBook Name->";
		string temp;
		getline(cin >> ws, temp);
		mySetColor(7, 0);
		temp3->setNotebookName(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 3) {
		mySetColor(4, 0);
		cout << "\t\tNoteBook Quality ->";
		int temp;
		cin >> temp;
		temp3->setQuality(temp);
		mySetColor(7, 0);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 4) {
		mySetColor(4, 0);
		cout << "\t\tNoteBook Monitor Inch ->";
		double temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookMonitor()->setMonitorInch(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 5) {
		mySetColor(4, 0);
		cout << "\t\tNoteBook Monitor hz ->";
		int temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookMonitor()->setMonitorHz(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 6) {
		mySetColor(4, 0);
		cout << "\t\tNoteBook Monitor Price ->";
		int temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookMonitor()->setPrice(temp);
		system("cls");
		temp3->setNoteBookPrice();
		temp3->ShowDetails();
	}
	else if (select == 7) {
		mySetColor(4, 0);
		cout << "\t\tCpu Name->";
		string temp;
		getline(cin >> ws, temp);
		mySetColor(7, 0);
		temp3->getNoteBookCpu()->setCpuName(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 8) {
		mySetColor(4, 0);
		cout << "\t\tCpu GHZ->";
		double temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookCpu()->setCpuHz(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 9) {
		mySetColor(4, 0);
		cout << "\t\tCpu Core->";
		int temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookCpu()->setCpuCores(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 10) {
		mySetColor(4, 0);
		cout << "\t\tCpu Thread->";
		int temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookCpu()->setCpuThread(temp);
		system("cls");
		temp3->ShowDetails();
	}
	else if (select == 11) {
		mySetColor(4, 0);
		cout << "\t\tCpu Price->";
		int temp;
		cin >> temp;
		mySetColor(7, 0);
		temp3->getNoteBookCpu()->setPrice(temp);
		system("cls");
		temp3->setNoteBookPrice();
		temp3->ShowDetails();
	}
	else if (select == 12) {
	mySetColor(4, 0);
	cout << "\t\tVideo Card Name->";
	string temp;
	getline(cin >> ws, temp);
	mySetColor(7, 0);
	temp3->getNoteBookVideoCard()->setVideoCardName(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 13) {
	mySetColor(4, 0);
	cout << "\t\tVideo Card Memory->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookVideoCard()->setVideoCardMemory(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 14) {
	mySetColor(4, 0);
	cout << "\t\tVideo Card Price->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookVideoCard()->setPrice(temp);
	system("cls");
	temp3->setNoteBookPrice();
	temp3->ShowDetails();
	}
	else if (select == 15) {
	mySetColor(4, 0);
	cout << "\t\tMemory Name->";
	string temp;
	getline(cin >> ws, temp);
	mySetColor(7, 0);
	temp3->getNoteBookMemory()->setMemoryName(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 16) {
	mySetColor(4, 0);
	cout << "\t\tMemory Gb ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookMemory()->setMemoryGb(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 17) {
	mySetColor(4, 0);
	cout << "\t\tMemory MHZ ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookMemory()->setMemoryMhz(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 18) {
	mySetColor(4, 0);
	cout << "\t\tMemory Price ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookMemory()->setPrice(temp);
	system("cls");
	temp3->setNoteBookPrice();
	temp3->ShowDetails();
	}
	else if (temp3->getIsSSD())
	{
		if (select == 19) {
			mySetColor(4, 0);
			cout << "\t\tSSD  Name->";
			string temp;
			getline(cin >> ws, temp);
			mySetColor(7, 0);
			temp3->getNoteBookSSD()->setSSDName(temp);
			system("cls");
			temp3->ShowDetails();
		}
		else if (select == 20) {
			mySetColor(4, 0);
			cout << "\t\tSSD Space ->";
			int temp;
			cin >> temp;
			mySetColor(7, 0);
			temp3->getNoteBookSSD()->setSSDSpace(temp);
			system("cls");
			temp3->ShowDetails();
		}
		else if (select == 21) {
			mySetColor(4, 0);
			cout << "\t\tSSD Price ->";
			int temp;
			cin >> temp;
			mySetColor(7, 0);
			temp3->getNoteBookSSD()->setPrice(temp);
			system("cls");
			temp3->setNoteBookPrice();
			temp3->ShowDetails();
		}
	}
	else if (select == 19) {
	mySetColor(4, 0);
	cout << "\t\HDD  Name->";
	string temp;
	getline(cin >> ws, temp);
	mySetColor(7, 0);
	temp3->getNoteBookHDD()->setHDDName(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 20) {
	mySetColor(4, 0);
	cout << "\t\tHDD Space ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookHDD()->setHDDSpace(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 21) {
	mySetColor(4, 0);
	cout << "\t\tHDD RPM ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookHDD()->setHDDRPM(temp);
	system("cls");
	temp3->ShowDetails();
	}
	else if (select == 22) {
	mySetColor(4, 0);
	cout << "\t\tHDD Price ->";
	int temp;
	cin >> temp;
	mySetColor(7, 0);
	temp3->getNoteBookHDD()->setPrice(temp);
	system("cls");
	temp3->ShowDetails();
	temp3->setNoteBookPrice();
	}
	else
	{
	throw Exception("Some things wrong", __LINE__, __FILE__, Taketime());
	}
}
int GuestMenuForNoteBook(int select = 1) {
	while (true) {
		system("cls");
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add Cart\n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Details\n";
		mySetColor(7, 0);
		if (select == 3) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Look Cart\n";
		mySetColor(7, 0);
		if (select == 4) {
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
int GuestMenuForComponent(int select = 1) {
	while (true) {
		system("cls");
		if (select == 1) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Add Cart\n";
		mySetColor(7, 0);
		if (select == 2) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Look Cart\n";
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
void UpdateMonitor(Monitor*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tMonitor Name ->";
		string cname;
		mySetColor(6, 0);
		getline(cin >> ws, cname);
		temp23->setMonitorName(cname);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tMonitor Inch ->";
		double inch;
		mySetColor(6, 0);
		cin >> inch;
		temp23->setMonitorInch(inch);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tMonitor Hz ->";
		int hz;
		mySetColor(6, 0);
		cin >> hz;
		temp23->setMonitorHz(hz);
		mySetColor(7, 0);
	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tMonitor Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 5) {
		mySetColor(2, 0);
		cout << "\t\tMonitor Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}
void UpdateHDD(HDD*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tHDD Name ->";
		string temp;
		mySetColor(6, 0);
		getline(cin >> ws, temp);
		temp23->setHDDName(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tHDD Space -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setHDDSpace(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tHDD RPM ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setHDDRPM(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tHDD Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 5) {
		mySetColor(2, 0);
		cout << "\t\tHDD Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}
void UpdateSSD(SSD*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tSSD Name ->";
		string temp;
		mySetColor(6, 0);
		getline(cin >> ws, temp);
		temp23->setSSDName(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tSSD Space -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setSSDSpace(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tSSD Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tSSD Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}
void UpdateMemory(Memory*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tMemory Name ->";
		string temp;
		mySetColor(6, 0);
		getline(cin >> ws, temp);
		temp23->setMemoryName(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tMemory Gb -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setMemoryGb(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tMemory MHZ -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setMemoryMhz(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tMemory Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 5) {
		mySetColor(2, 0);
		cout << "\t\tMemory Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}
void UpdateVideoCard(VideoCard*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tVideo Card Name ->";
		string temp;
		mySetColor(6, 0);
		getline(cin >> ws, temp);
		temp23->setVideoCardName(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tVideo Card  Gb -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setVideoCardMemory(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tVideo Card  Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tVideo Card  Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}
void UpdateCpu(Cpu*& temp23, const int select4) {
	if (select4 == 0) {
		auto temp2 = categories.CategorySelectForAdminShowAll();
		if (temp2 == -1)return;
		temp23->setCategoryId(temp2);
	}
	if (select4 == 1) {
		mySetColor(2, 0);
		cout << "\t\tCpu Name -> ";
		string temp;
		mySetColor(6, 0);
		getline(cin >> ws, temp);
		temp23->setCpuName(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tCpu GHz -> ";
		double temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setCpuHz(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tCpu Cores -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setCpuCores(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tCpu Thread -> ";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setCpuThread(temp);
		mySetColor(7, 0);
	}
	else if (select4 == 5) {
		mySetColor(2, 0);
		cout << "\t\tCpu  Price ->";
		int price;
		mySetColor(6, 0);
		cin >> price;
		temp23->setPrice(price);
		mySetColor(7, 0);

	}
	else if (select4 == 6) {
		mySetColor(2, 0);
		cout << "\t\tCpu  Quality ->";
		int quality;
		mySetColor(6, 0);
		cin >> quality;
		temp23->setQuality(quality);
		mySetColor(7, 0);
	}
	system("cls");
}


