#pragma once
#include"Exception.h"


class Category {
	int categoryId;
	string cName;
public:
	static int size;
	Category()
	{
		setId();
	}
	Category(const string& cname)
	{
		setId();
		setCategoryName(cname);
	}
	void setId() {
		categoryId=++size;
	}
	int getSize()const {
		return size;
	}
	int getId()const {
		return categoryId;
	}
	void setId(const int categoryId) {
		this->categoryId = categoryId;
	}
	void setCategoryName(const string& name) {
		if (name == "")throw Exception("Category Name Is Empty", __LINE__, __FILE__, Taketime());
		this->cName = name;
	}
	string getUsername() {
		return cName;
	}
	string getCategoryName() {
		return cName;
	}
	void ShowA(const int number)const {
		if (number == 1) {
			mySetColor(4, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Category Name ->" << cName << endl;
		mySetColor(7, 0);
	}
};
int Category::size = 0;
class Categories {
	Category** categories;
	int categories_size;
public:
	Categories() :categories(),categories_size() {}
	void addCategory(Category* item) {
		for (int i = 0; i < categories_size; i++)
		{
			if (item->getId()==categories[i]->getId())throw Exception("Your Category Already Have", __LINE__, __FILE__, Taketime());
			if (item->getUsername()==categories[i]->getUsername())throw Exception("Your Category Name Already Have", __LINE__, __FILE__, Taketime());
		}
		auto newC = new Category * [categories_size + 1]{};
		for (int i = 0; i < categories_size; i++)
		{
			newC[i] = categories[i];
		}
		newC[categories_size] = item;
		delete[] categories;
		categories_size++;

		categories = newC;
		newC = nullptr;
	}
	void deleteCategory(const int id) {
		int count=0;
		for (int i = 0; i < categories_size; i++)
		{
			if (id != categories[i]->getId()) {
				count++;
			}
		}
		if (count==categories_size)throw Exception("Your Category Already Have not", __LINE__, __FILE__, Taketime());
		int index = 0;
		for (int i = 0; i < categories_size; i++)
		{
			if (categories[i]->getId() == id) {
				index = i;
				break;
			}
		}
		if (categories_size - 1 != 0)
		{
			auto newFiles = new Category * [categories_size - 1]{};
			for (int i = 0, k = 0; i < categories_size; i++)
			{
				if (i != index)
				{
					newFiles[k++] = categories[i];
				}
			}
			categories_size--;
			delete[] categories;
			categories = newFiles;
			newFiles = nullptr;
		}
		else
		{

			categories_size--;
			delete[] categories;
			categories = nullptr;
		}
	}
	void changeCategoryName(const int id,const string& name) {
		int count = 0;
		for (int i = 0; i < categories_size; i++)
		{
			if (id != categories[i]->getId()) {
				count++;
			}
		}
		if (count == categories_size)throw Exception("Your Category Already Have not", __LINE__, __FILE__, Taketime());
		int index = 0;
		for (int i = 0; i < categories_size; i++)
		{
			if (categories[i]->getId() == id) {
				index = i;
				break;
			}
		}
		categories[index]->setCategoryName(name);
	}
	int getCategoriesSize()const {
		return categories_size;
	}
	int CategorySelect()const {
		int* selects = new int[categories_size+2] {};
		int index = 0;
		selects[index] = 1;
		while (true)
		{
			for (int i = 0; i < categories_size; i++)
			{
				categories[i]->ShowA(selects[i]);
				cout << "\n";
			}
			if (selects[categories_size] == 1) {
				mySetColor(4, 0);
				cout << "\t\t\t-->>";
			}
			else cout << "\t\t\t";
			cout << "Look Cart\n\n";
			mySetColor(7, 0);
			if (selects[categories_size+1] == 1) {
				mySetColor(4, 0);
				cout << "\t\t\t-->>";
			}
			else cout << "\t\t\t";
			mySetColor(1, 0);
			cout << "Exit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						system("cls");
						selects[index] = 0;
						selects[--index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = categories_size+1;
						selects[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != categories_size+1) {
						system("cls");
						selects[index] = 0;
						selects[++index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = 0;
						selects[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == categories_size+1)
				{
					return -1;
				}
				else if (index == categories_size)
				{
					return -5;
				}
				else
				{
					return categories[index]->getId();;

				}
			}
			system("cls");
		}
	}
	int CategorySelectForAdmin()const {
		int* selects = new int[categories_size + 2]{};
		int index = 0;
		selects[index] = 1;
		while (true)
		{
			for (int i = 0; i < categories_size; i++)
			{
				categories[i]->ShowA(selects[i]);
				cout << "\n";
			}
			if (selects[categories_size] == 1) {
				mySetColor(4, 0);
				cout << "\t\t\t-->>";
			}
			else cout << "\t\t\t";
			mySetColor(1, 0);
			cout << "Exit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						system("cls");
						selects[index] = 0;
						selects[--index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = categories_size;
						selects[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != categories_size) {
						system("cls");
						selects[index] = 0;
						selects[++index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = 0;
						selects[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == categories_size)
				{
					return -1;
				}
				else
				{
					return categories[index]->getId();;

				}
			}
			system("cls");
		}
	}
	int CategorySelectForAdminShowAll()const {
		int* selects = new int[categories_size + 2]{};
		int index = 0;
		selects[index] = 1;
		while (true)
		{
			for (int i = 0; i < categories_size; i++)
			{
				categories[i]->ShowA(selects[i]);
				cout << "\n";
			}
			if (selects[categories_size] == 1) {
				mySetColor(4, 0);
				cout << "\t\t\t-->>";
			}
			else cout << "\t\t\t";
			cout << "None Category Products\n\n";
			mySetColor(7, 0);
			if (selects[categories_size+1] == 1) {
				mySetColor(4, 0);
				cout << "\t\t\t-->>";
			}
			else cout << "\t\t\t";
			mySetColor(1, 0);
			cout << "Exit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						system("cls");
						selects[index] = 0;
						selects[--index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = categories_size+1;
						selects[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != categories_size+1) {
						system("cls");
						selects[index] = 0;
						selects[++index] = 1;
						continue;
					}
					else
					{
						system("cls");
						selects[index] = 0;
						index = 0;
						selects[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == categories_size+1)
				{
					return -1;
				}
				else if (index == categories_size)
				{
					return -5;
				}
				else
				{
					return categories[index]->getId();;
				}
			}
			system("cls");
		}
	}
};

Category* aa = new Category("NoteBooks");
Category* bb = new Category("Components");
Category* cc = new Category("Phones");
Categories categories;

class Product {
	int price;
	int quality;
	int Buyed;
	int categoryId;
public:
	int id;
	static int _id;
	Product() :price(), quality(),categoryId(), Buyed(),id(){}
	Product(const int price,const int categoryId, const int quality=1,const int buyed=0)
	{
		setPrice(price);
		setQuality(quality);
		setBuyed(buyed);
		setCategoryId(categoryId);
	}

	void setCategoryId(const int cId) {
		categoryId = cId;
	}
	virtual string getUsername()const = 0;
	virtual void ShowA()const = 0;
	virtual void ShowAll()const = 0;
	virtual void ShowAll(int select)const {}
	virtual void ShowAllForGuest(int select)const = 0;
	virtual void ShowAllForCart(int select)const = 0;
	virtual int ShowSelectAndUpdate(int select = 0)const = 0;
	int getId()const { return id; }
	int getPrice()const { return price; }
	int getQuality()const { return quality; }
	int getBuyed()const { return Buyed; }
	int getCategoryId()const { return categoryId; }

	void setId() {
		id = ++_id;
	}
	void setBuyed(const int Buyed) {
		if (Buyed < 0)throw Exception("Buyed Must be Greater or Equal Zero", __LINE__, __FILE__, Taketime());
		this->Buyed = Buyed;
	}
	void setQuality(const int quality) {
		if (quality < 0)throw Exception("Quality Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->quality = quality;
	}
	void setPrice(const int price) {
		if (price <= 0)throw Exception("Price Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->price = price;
	}
};
int Product::_id = 0;

class Phone:public Product {
private:
	string name;
	int bateryCapacity;
	int ram;
	int cameraMP;
public:
	Phone():name(),bateryCapacity(),ram(),cameraMP(){}
	Phone(const string& name,const int baterycap, const int ram, const int cameraMP,const int price,const int categoryid=-5, const int quality = 1)
		:Product(price,categoryid,quality),name(name),bateryCapacity(baterycap), ram(ram), cameraMP(cameraMP) {
		setId();
	}
	int getBateryCapacity()const { return bateryCapacity; }
	int getRam()const { return ram; }
	int getCameraMP()const { return cameraMP; }

	void setPhoneName(const string& name) {
		if (name == "")throw Exception("Phone Name Is Empty", __LINE__, __FILE__, Taketime());
		this->name = name;
	}
	void setRam(const int& ram) {
		if (ram < 0)throw Exception("Ram must Be Greater Zero", __LINE__, __FILE__, Taketime());
		this->ram = ram;
	}
	void setBateryCapacity(const int& bateryCapacity) {
		if (bateryCapacity < 0)throw Exception("bateryCapacity must Be Greater Zero", __LINE__, __FILE__, Taketime());
		this->bateryCapacity = bateryCapacity;
	}
	void setCameraMP(const int& cameraMP) {
		if (cameraMP < 0)throw Exception("CameraMP must Be Greater Zero", __LINE__, __FILE__, Taketime());
		this->cameraMP = cameraMP;
	}

	string getUsername()const override { return name; }
	void ShowA()const override {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tPhone ID -> " << getId() << endl;
		mySetColor(2, 0);
		cout << "\t\tPhone Name -> " << name << endl;
		cout << "\t\tPhone Batery Capacity -> " << bateryCapacity << endl;
		cout << "\t\tPhone Ram -> " << ram << endl;
		cout << "\t\tPhone Camera -> " << cameraMP << endl;
		mySetColor(6, 0);
		cout << "\t\tPhone Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tPhone Quality ->" << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const override {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tPhone ID -> " << getId() << endl;
		mySetColor(2, 0);
		cout << "\t\tPhone Name -> " << name << endl;
		cout << "\t\tPhone Batery Capacity -> " << bateryCapacity << endl;
		cout << "\t\tPhone Ram -> " << ram << endl;
		cout << "\t\tPhone Camera -> " << cameraMP << endl;
		mySetColor(6, 0);
		cout << "\t\tPhone Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tPhone Quality ->" << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForGuest(int select)const override{
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tPhone ID -> " << getId() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Name -> " << name << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Batery Capacity -> " << bateryCapacity << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Ram -> " << ram << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Camera -> " << cameraMP << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tPhone Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tPhone Quality ->" << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const override {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tPhone ID -> " << getId() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Name -> " << name << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Batery Capacity -> " << bateryCapacity << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Ram -> " << ram << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tPhone Camera -> " << cameraMP << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tPhone Price -> " << getPrice()*getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tPhone Quality ->" << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	int ShowSelectAndUpdate(int select = 0)const override {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(6, 0);
			cout << "\t\tPhone Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(2, 0);
			cout << "\t\tPhone Name -> " << name << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(2, 0);
			cout << "\t\tPhone Batery Capacity -> " << bateryCapacity << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(2, 0);
			cout << "\t\tPhone Ram -> " << ram << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(2, 0);
			cout << "\t\tPhone Camera -> " << cameraMP << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(6, 0);
			cout << "\t\tPhone Price -> " << getPrice() << endl;
			if (select == 6)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else
			mySetColor(4, 0);
			cout << "\t\tPhone Quality ->" << getQuality() << endl;
			if (select == 7)
			{
				mySetColor(1, 0);
				cout << " ---->  ";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
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
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 7)
				{
					system("cls");
					return -1;
				}
				else
				{
					system("cls");
					return select;
				}
			}
			system("cls");
		}
	}
};
Phone* CreatePhone() {
	mySetColor(4, 0);
	cout << "\t\t SELECT CATEGORY \n";
	auto temp2 = categories.CategorySelectForAdminShowAll();
	mySetColor(6, 0);
	cout << "\t\tPhone name ->";
	string name;
	mySetColor(2, 0);
	getline(cin >> ws, name);
	cout << "\t\tPhone Batery Capacity ->";
	int Batery;
	mySetColor(6, 0);
	cin >> Batery;
	mySetColor(2, 0);
	cout << "\t\tPhone ram ->";
	int ram;
	mySetColor(6, 0);
	cin >> ram;
	cout << "\t\tPhone Camera mpx ->";
	int mpx;
	mySetColor(2, 0);
	cin >> mpx;
	cout << "\t\tPhone Price ->";
	int price;
	mySetColor(6, 0);
	cin >> price;
	cout << "\t\tPhone quality ->";
	mySetColor(6, 0);
	int quality;
	cin >> quality;
	Phone* P = new Phone(name,Batery,ram, mpx,price);
	P->setCategoryId(temp2);
	return P;
}
void UpdatePhone(Phone*&temp23,const int select4){
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
		temp23->setPhoneName(temp);
		mySetColor(7, 0);
	}
	if (select4 == 2) {
		mySetColor(2, 0);
		cout << "\t\tPhone Batery Capacity ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setBateryCapacity(temp);
		mySetColor(7, 0);
	}
	if (select4 == 3) {
		mySetColor(2, 0);
		cout << "\t\tPhone Ram ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setRam(temp);
		mySetColor(7, 0);
	}
	if (select4 == 4) {
		mySetColor(2, 0);
		cout << "\t\tPhone Camera Mega Pixels ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setCameraMP(temp);
		mySetColor(7, 0);
	}
	if (select4 == 5) {
		mySetColor(2, 0);
		cout << "\t\tPhone Price ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setPrice(temp);
		mySetColor(7, 0);
	}
	if (select4 == 6) {
		mySetColor(2, 0);
		cout << "\t\tPhone Quality ->";
		int temp;
		mySetColor(6, 0);
		cin >> temp;
		temp23->setQuality(temp);
		mySetColor(7, 0);
	}
}

class Cpu :public Product {

	int cpu_cores;
	double cpu_hz;
	int cpu_thread;
	string cpuName;
public:
	Cpu() {
	}
	Cpu(const int price, const string cpuName, const int cpu_cores, const double cpu_hz, const int cpu_thread,const int categoriId=-5, const int quality = 1) :Product(price, categoriId, quality) {
		setId();
		setCpuName(cpuName);
		setCpuCores(cpu_cores);
		setCpuHz(cpu_hz);
		setCpuThread(cpu_thread);
	}
	Cpu& operator=(const Cpu& other) {
		setCpuName(other.getCpuName());
		setCpuCores(other.getCpuCores());
		setCpuHz(other.getCpuHz());
		setCpuThread(other.getCpuThread());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	int getCpuCores()const { return cpu_cores; }
	int getCpuThread()const { return cpu_thread; }
	double getCpuHz()const { return cpu_hz; }
	string getCpuName()const { return cpuName; }
	string getUsername()const { return cpuName; }
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tCpu ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << cpuName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tCpu Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tCpu Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tCpu ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << cpuName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tCpu Price -> " << getPrice()*getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tCpu Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tCpu ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << getCpuName() << endl;
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		mySetColor(6, 0);
		cout << "\t\tCpu Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tCpu Quality ->" << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tCpu ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << getCpuName() << endl;
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		mySetColor(6, 0);
		cout << "\t\tCpu Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tCpu Quality ->" << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void Show()const {
		cout << "\t\tCpu Name -> " << getCpuName() << endl;
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << getCpuName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tCpu Card Price -> " << getPrice() << endl;
		mySetColor(7, 0);
	}
	void ShowAndSelect(int select)const {
		if (select == 7)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Name -> " << getCpuName() << endl;
		if (select == 8)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
		if (select == 9)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
		if (select == 10)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
		if (select == 11)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tCpu Price -> " << getPrice() << endl;
	}
	int ShowSelectAndUpdate(int select = 0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu Name -> " << getCpuName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu GHz -> " << getCpuHz() << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu Cores -> " << getCpuCores() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu Thread -> " << getCpuThread() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tCpu Card Price -> " << getPrice() << endl;
			if (select == 6)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tCpu Card Quality -> " << getQuality() << endl;
			if (select == 7)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
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
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 7)
				{
					system("cls");
					return -1;
				}
				else
				{
					system("cls");
					return select;
				}
			}
			system("cls");
		}
	}
	void setCpuName(const string& cpuName) {
		if (cpuName == "")throw Exception("Cpu Name Is Empty", __LINE__, __FILE__, Taketime());
		this->cpuName = cpuName;
	}
	void setCpuCores(const int cpu_cores) {
		if (cpu_cores <= 0)throw Exception("Cpu Cores Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->cpu_cores = cpu_cores;
	}
	void setCpuHz(const double hz) {
		if (hz <= 0)throw Exception("Cpu Hz Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->cpu_hz = hz;
	}
	void setCpuThread(const int cpu_thread) {
		if (cpu_thread <= 0)throw Exception("Cpu thread Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->cpu_thread = cpu_thread;
	}
};
class VideoCard :public Product {
	string VideoCardName;
	int Memory;

public:
	VideoCard()
	{
	}
	VideoCard(const string& VideoCardName, const int Memory, const int price, const int categoriId, const int quality=1) :Product(price, categoriId, quality) {
		setId();
		setVideoCardName(VideoCardName);
		setVideoCardMemory(Memory);
	}
	VideoCard& operator=(const VideoCard& other) {
		setVideoCardName(other.getVideoCardName());
		setVideoCardMemory(other.getVideoCardMemory());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	int getVideoCardMemory()const { return Memory; }
	string getVideoCardName()const { return VideoCardName; }
	void Show()const {
		cout << "\t\tVideo Card Name -> " << getVideoCardName() << endl;
		cout << "\t\tVideo Card Memory -> " << getVideoCardMemory() << endl;
		cout << "\t\tVideo Card  Price -> " << getPrice() << endl;
	}
	string getUsername()const { return VideoCardName; }
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tVideoCard ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << Memory << " GB" << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tVideoCard Name -> " << VideoCardName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tVideoCard Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tVideoCard Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tVideoCard ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << Memory << " GB" << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tVideoCard Name -> " << VideoCardName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tVideoCard Price -> " << getPrice() * getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tVideoCard Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const  {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tVideoCard ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << Memory <<" GB"<< endl;
		cout << "\t\tVideoCard Name -> " << VideoCardName << endl;
		mySetColor(6, 0);
		cout << "\t\tVideoCard Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tVideoCard Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tVideoCard ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << Memory << " GB" << endl;
		cout << "\t\tVideoCard Name -> " << VideoCardName << endl;
		mySetColor(6, 0);
		cout << "\t\tVideoCard Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tVideoCard Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAndSelect(int select)const {
		if (select == 12)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tVideo Card Name -> " << getVideoCardName() << endl;
		if (select == 13)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << getVideoCardMemory() << endl;
		if (select == 14)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tVideo Card  Price -> " << getPrice() << endl;
	
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tVideo Card Name -> " << getVideoCardName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tVideo Card Memory -> " << getVideoCardMemory() << " GB" << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tVideo Card Price -> " << getPrice() << endl;
		mySetColor(7, 0);
	}
	int ShowSelectAndUpdate(int select = 0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tVideo Card Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tVideo Card Name -> " << getVideoCardName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tVideo Card Memory -> " << getVideoCardMemory()<<" GB" << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tVideo Card Price -> " << getPrice() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tVideo Card Quality -> " << getQuality() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
						system("cls");
						select--;
						continue;
					}
					else {
						system("cls");
						select = 5;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (select + 1 != 6) {
						system("cls");
						select++;
						continue;
					}
					else {
						system("cls");
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 5)
				{
					system("cls");
					return -1;
				}
				else
				{
					system("cls");
					return select;
				}
			}
			system("cls");
		}
	}
	void setVideoCardName(const string& VideoCardName) {
		if (VideoCardName == "")throw Exception("Video Card Name Is Empty", __LINE__, __FILE__, Taketime());
		this->VideoCardName = VideoCardName;
	}
	void setVideoCardMemory(const int memory) {
		if (memory <= 0)throw Exception("Video Card Memory Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->Memory = memory;
	}

};
class Memory :public Product {
	string MemoryName;
	int Gb;
	int mhz;
public:
	Memory()
	{
	}
	Memory(const string& name, const int Gb, const int mhz, const int price, const int categoriId, const int quality = 1) :Product(price, categoriId, quality)
	{
		setId();
		setMemoryGb(Gb);
		setMemoryMhz(mhz);
		setMemoryName(name);
	}
	Memory& operator=(const Memory& other) {
		setMemoryGb(other.getMemoryGb());
		setMemoryMhz(other.getMemoryMhz());
		setMemoryName(other.getMemoryName());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	string getUsername()const { return MemoryName; }
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMemory ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << MemoryName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Gb -> " << Gb << " GB" << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Mhz -> " << mhz << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMemory Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tMemory Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tMemory ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << MemoryName << endl;
		cout << "\t\tMemory Gb -> " << Gb << " GB" << endl;
		cout << "\t\tMemory Mhz -> " << mhz << endl;
		mySetColor(6, 0);
		cout << "\t\tMemory Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tMemory Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tMemory ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << MemoryName << endl;
		cout << "\t\tMemory Gb -> " << Gb << " GB" << endl;
		cout << "\t\tMemory Mhz -> " << mhz << endl;
		mySetColor(6, 0);
		cout << "\t\tMemory Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tMemory Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMemory ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << MemoryName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Gb -> " << Gb << " GB" << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMemory Mhz -> " << mhz << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMemory Price -> " << getPrice() * getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tMemory Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	int getMemoryGb()const { return Gb; }
	int getMemoryMhz()const { return mhz; }
	string getMemoryName()const { return MemoryName; }

	void Show()const {
		cout << "\t\tMemory Name -> " << getMemoryName() << endl;
		cout << "\t\tMemory Gb -> " << getMemoryGb() << endl;
		cout << "\t\tMemory MHZ -> " << getMemoryMhz() << endl;
		cout << "\t\tMemory Price -> " << getPrice() << endl;
	}
	
	void ShowAndSelect(int select)const {
		if (select == 15)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << getMemoryName() << endl;
		if (select == 16)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory Gb -> " << getMemoryGb() << endl;
		if (select == 17)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory MHZ -> " << getMemoryMhz() << endl;
		if (select == 18)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory Price -> " << getPrice() << endl;
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory Name -> " << getMemoryName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory Gb -> " << getMemoryGb() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMemory MHZ -> " << getMemoryMhz() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tMemory Price -> " << getPrice() << endl;
		mySetColor(7,0);
	}
	int ShowSelectAndUpdate(int select = 0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMemory Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMemory Name -> " << getMemoryName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMemory Gb -> " << getMemoryGb() << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMemory MHZ -> " << getMemoryMhz() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMemory Price -> " << getPrice() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tMemory Quality -> " << getQuality() << endl;
			if (select == 6)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
						system("cls");
						select--;
						continue;
					}
					else {
						system("cls");
						select = 6;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (select + 1 != 7) {
						system("cls");
						select++;
						continue;
					}
					else {
						system("cls");
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 6)
				{
					system("cls");
					return -1;
				}
				else
				{
					system("cls");
					return select;
				}
			}
			system("cls");
		}
	}
	void setMemoryName(const string& MemoryName) {
		if (MemoryName == "")throw Exception("Memory Name Is Empty", __LINE__, __FILE__, Taketime());
		this->MemoryName = MemoryName;
	}
	void setMemoryGb(const int Gb) {
		if (Gb <= 0)throw Exception("Memmory Gb Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->Gb = Gb;
	}
	void setMemoryMhz(const int mhz) {
		if (mhz <= 0)throw Exception("Memmory mhz Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->mhz = mhz;
	}
};
class SSD :public Product {
	string SSDName;
	int space;
public:
	SSD()
	{
	}
	SSD(const string& ssdname,const int space, const int price, const int categoriId, const int quality=1) :Product(price, categoriId, quality) {
		setId();
		setSSDSpace(space);
		setSSDName(ssdname);
	}
	SSD& operator=(const SSD& other) {
		setSSDName(other.getSSDName());
		setSSDSpace(other.getSSDSpace());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	void setSSDName(const string& SSDName) {
		if (SSDName == "")throw Exception("SSD Name Is Empty", __LINE__, __FILE__, Taketime());
		this->SSDName = SSDName;
	}
	void setSSDSpace(const int space) {
		if (space <= 0)throw Exception("SSD Space Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->space = space;
	}
	string getUsername()const { return SSDName; }
	int getSSDSpace()const { return space; }
	string getSSDName()const { return SSDName; }

	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tSSD ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << SSDName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tSSD Space -> " << space << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tSSD Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tSSD Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tSSD ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << SSDName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tSSD Space -> " << space << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tSSD Price -> " << getPrice() * getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tSSD Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tSSD ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << SSDName << endl;
		cout << "\t\tSSD Space -> " << space << endl;
		mySetColor(6, 0);
		cout << "\t\tSSD Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tSSD Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tSSD ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << SSDName << endl;
		cout << "\t\tSSD Space -> " << space << endl;
		mySetColor(6, 0);
		cout << "\t\tSSD Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tSSD Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void Show()const {
		cout << "\t\tSSD Name -> " << getSSDName() << endl;
		cout << "\t\tSSD Space -> " << getSSDSpace() << endl;
		cout << "\t\tSSD Price -> " << getPrice() << endl;
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << getSSDName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tSSD Space -> " << getSSDSpace() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tSSD Price -> " << getPrice() << endl;
		mySetColor(7, 0);
	}
	int ShowSelectAndUpdate(int select = 0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tSSD Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tSSD Name -> " << getSSDName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tSSD Space -> " << getSSDSpace() << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tSSD Price -> " << getPrice() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tSSD Quality -> " << getQuality() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
						system("cls");
						select--;
						continue;
					}
					else {
						system("cls");
						select = 5;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (select + 1 != 6) {
						system("cls");
						select++;
						continue;
					}
					else {
						system("cls");
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select==5)
				{
					system("cls");
					return -1;
				}
				else
				{
					system("cls");
					return select;
				}
			}
			system("cls");
		}
	}
	void ShowAndSelect(int select)const {
		if (select == 19)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tSSD Name -> " << getSSDName() << endl;
		if (select == 20)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tSSD Space -> " << getSSDSpace() << endl;
		if (select == 21)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tSSD Price -> " << getPrice() << endl;
	}
};
class HDD :public Product {
	string HDDName;
	int space;
	int RPM;
public:
	HDD()
	{
	}
	HDD(const string&hddname,const int space, const int RPM, const int price, const int categoriId, const int quality = 1) :Product(price, categoriId, quality) {
		setId();
		setHDDSpace(space);
		setHDDRPM(RPM);
		setHDDName(hddname);
	}

	HDD& operator=(const HDD other) {
		setHDDRPM(other.getHDDRPM());
		setHDDSpace(other.getHDDSpace());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tHDD ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << HDDName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD Space -> " << space << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD RPM -> " << RPM << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tHDD Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tHDD Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tHDD ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << HDDName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD Space -> " << space << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tHDD RPM -> " << RPM << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tHDD Price -> " << getPrice() * getBuyed() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tHDD Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tHDD ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << HDDName << endl;
		cout << "\t\tHDD Space -> " << space << endl;
		cout << "\t\tHDD RPM -> " << RPM << endl;
		mySetColor(6, 0);
		cout << "\t\tHDD Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tHDD Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tHDD ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << HDDName << endl;
		cout << "\t\tHDD Space -> " << space << endl;
		cout << "\t\tHDD RPM -> " << RPM << endl;
		mySetColor(6, 0);
		cout << "\t\tHDD Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tHDD Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	string getUsername()const { return HDDName; }
	void setHDDName(const string& HDDName) {
		if (HDDName == "")throw Exception("HDD Name Is Empty", __LINE__, __FILE__, Taketime());
		this->HDDName = HDDName;
	}
	string getHDDName()const { return HDDName; }
	int getHDDSpace()const { return space; }
	int getHDDRPM()const { return RPM; }

	void Show()const {
		cout << "\t\tHDD Name -> " << getHDDName() << endl;
		cout << "\t\tHDD Space -> " << getHDDSpace() << endl;
		cout << "\t\tHDD RPM -> " << getHDDRPM() << endl;
		cout << "\t\tHDD Price -> " << getPrice() << endl;
	}

	void ShowAndSelect(int select)const {
		if (select == 19)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << getHDDName() << endl;
		if (select == 20)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD Space -> " << getHDDSpace() << endl;
		if (select == 21)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD RPM -> " << getHDDRPM() << endl;
		if (select == 22)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD Price -> " << getPrice() << endl;
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD Name -> " << getHDDName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD Space -> " << getHDDSpace() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tHDD RPM -> " << getHDDRPM() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tHDD Price -> " << getPrice() << endl;
		mySetColor(7, 0);

	}
	int ShowSelectAndUpdate(int select = 0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tHDD Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tHDD Name -> " << getHDDName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tHDD Space -> " << getHDDSpace() << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tHDD RPM -> " << getHDDRPM() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(6, 0);
			cout << "\t\tHDD Price -> " << getPrice() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tHDD Quality -> " << getQuality() << endl;
			if (select == 6)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
						system("cls");
						select--;
						continue;
					}
					else {
						system("cls");
						select = 6;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (select + 1 != 7) {
						system("cls");
						select++;
						continue;
					}
					else {
						system("cls");
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 6)
				{
					system("cls");
					return -1;
				}
				system("cls");
				return select;
			}
			system("cls");
		}
	}
	void setHDDSpace(const int space) {
		if (space <= 0)throw Exception("HDD Space Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->space = space;
	}
	void setHDDRPM(const int RPM) {
		if (RPM <= 0)throw Exception("HDD RPM Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->RPM = RPM;
	}
};
class Monitor :public Product {
	string MonitorName;
	double Inch;
	int MonitorHz;
public:
	Monitor() {
	}
	Monitor(const string& monitorname,const double Inch, const int MonitorHz, const int price, const int categoriId, const int quality = 1) :Product(price, categoriId, quality) {
		setId();
		setMonitorInch(Inch);
		setMonitorHz(MonitorHz);
		setMonitorName(monitorname);
	}
	Monitor& operator=(const Monitor& other) {
		setMonitorInch(other.getMonitorInch());
		setMonitorHz(other.getMonitorHz());
		setPrice(other.getPrice());
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	int getMonitorHz()const { return MonitorHz; }
	double getMonitorInch()const { return Inch; }
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMonitor ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Name -> " << MonitorName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tMonitor Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMonitor ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Name -> " << MonitorName << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tMonitor Quality -> " << getBuyed() * getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tMonitor ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tMonitor Name -> " << MonitorName << endl;
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		mySetColor(6, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tMonitor Quality -> " << getBuyed() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tMonitor ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tMonitor Name -> " << MonitorName << endl;
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		mySetColor(6, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
		mySetColor(4, 0);
		cout << "\t\tMonitor Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	string getUsername()const { return MonitorName; }
	void setMonitorName(const string& MonitorName) {
		if (MonitorName == "")throw Exception("Monitor Name Is Empty", __LINE__, __FILE__, Taketime());
		this->MonitorName = MonitorName;
	}
	string getMonitorName()const { return MonitorName; }

	void Show()const {
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
	}
	void ShowAndSelect(int select)const {
		if (select == 4)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		if (select == 5)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		if (select == 6)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
	}
	void ShowAndUpgradeOrDowngradeSelect(const int& select)const {
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Name -> " << getMonitorName() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(2, 0);
		cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
		if (select == 1)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		else mySetColor(6, 0);
		cout << "\t\tMonitor Price -> " << getPrice() << endl;
		mySetColor(7, 0);
	}
	int ShowSelectAndUpdate(int select=0)const {
		while (true)
		{
			if (select == 0)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMonitor Category Id -> " << getCategoryId() << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMonitor Name -> " << getMonitorName() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMonitor Inch -> " << getMonitorInch() << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tMonitor Hz -> " << getMonitorHz() << endl;
			if (select == 4)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(6, 0);
			cout << "\t\tMonitor Price -> " << getPrice() << endl;
			if (select == 5)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tMonitor Quality -> " << getQuality() << endl;
			if (select == 6)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(4, 0);
			cout << "\t\tExit This Panel " << endl;
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (select - 1 != -1) {
						system("cls");
						select--;
						continue;
					}
					else {
						system("cls");
						select = 6;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (select + 1 != 7) {
						system("cls");
						select++;
						continue;
					}
					else {
						system("cls");
						select = 0;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (select == 6)
				{
					system("cls");
					return -1;
				}
				system("cls");
				return select;
			}
			system("cls");
		}
	} 
	void setMonitorInch(const double Inch) {
		if (Inch <= 0)throw Exception("Monitor Inch Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->Inch = Inch;
	}
	void setMonitorHz(const int MonitorHz) {
		if (MonitorHz <= 0)throw Exception("MonitorHz Must be Greater Zero", __LINE__, __FILE__, Taketime());
		this->MonitorHz = MonitorHz;
	}
};
class Notebook:public Product {
	string name;
	Monitor monitor;

	Cpu processor;
	VideoCard videoCard;
	Memory memory;
	bool isSSD;
	SSD ssd;
	HDD hdd;
	int price;
public:
	bool operator==(Notebook& other)
	{
		if (name != other.name)return 0;
		if (isSSD != other.isSSD)return 0;
		if (price != other.price)return 0;
		if (id != other.id)return 0;

		return 1;
	}
	Notebook():processor(), videoCard(), memory(), isSSD(), ssd(), hdd(), price()
	{
		setId();
	}
	Notebook(const bool isSSD, const string& name, const Monitor& M, const Cpu& C, const VideoCard& V, const Memory& me, const HDD& h, const SSD& s, const int categoriId, const int quality)
	{
		if (name == "")throw Exception("NoteBook Name is Empty", __LINE__, __FILE__, Taketime());
		else if (&M == nullptr)throw Exception("NoteBook Monitor is nullptr", __LINE__, __FILE__, Taketime());
		else if (&C == nullptr)throw Exception("NoteBook Cpu is nullptr", __LINE__, __FILE__, Taketime());
		else if (&V == nullptr)throw Exception("NoteBook Video Card is nullptr", __LINE__, __FILE__, Taketime());
		else if (&me == nullptr)throw Exception("NoteBook Memory is nullptr", __LINE__, __FILE__, Taketime());
		if (isSSD)if (&s == nullptr)throw Exception("NoteBook SSD is nullptr", __LINE__, __FILE__, Taketime());
		else {
			if (&h == nullptr)throw Exception("NoteBook HDD is nullptr", __LINE__, __FILE__, Taketime());
		}
		setId();
		setNotebookName(name);
		this->isSSD = isSSD;
		setNoteBookMonitor(M);
		setNoteBookVideoCard(V);
		setNoteBookCpu(C);
		setNoteBookMemory(me);
		if (this->isSSD)setNoteBookSSD(s);
		else setNoteBookHDD(h);
		setNoteBookPrice();
		setQuality(quality);
		setCategoryId(categoriId);
	}
	Notebook& operator=( Notebook& other) {
		setNotebookName(other.getUsername());
		this->isSSD = other.getIsSSD();
		setNoteBookMonitor(*other.getNoteBookMonitor());
		setNoteBookVideoCard(*other.getNoteBookVideoCard());
		setNoteBookCpu(*other.getNoteBookCpu());
		setNoteBookMemory(*other.getNoteBookMemory());
		if (this->isSSD)setNoteBookSSD(*other.getNoteBookSSD());
		else setNoteBookHDD(*other.getNoteBookHDD());
		setNoteBookPrice();
		setQuality(other.getQuality());
		setCategoryId(other.getCategoryId());
		return *this;
	}
	Monitor* getNoteBookMonitor() { return &monitor; }
	Cpu* getNoteBookCpu() { return &processor; }
	VideoCard* getNoteBookVideoCard() { return &videoCard; }
	Memory* getNoteBookMemory() { return &memory; }
	SSD* getNoteBookSSD() { return &ssd; }
	HDD* getNoteBookHDD() { return &hdd; }
	string getUsername()const override { return name; }

	void setNoteBookMonitor(const Monitor& M) {
		if (&M==NULL)throw Exception("Monitor Is Empty", __LINE__, __FILE__, Taketime());
		monitor = M;
	}
	void setNoteBookCpu(const Cpu& C) {
		if (&C == NULL)throw Exception("Cpu Is Empty", __LINE__, __FILE__, Taketime());
		processor = C;
	}
	void setNoteBookVideoCard(const VideoCard& V) {
		if (&V == NULL)throw Exception("VideoCard Is Empty", __LINE__, __FILE__, Taketime());
		videoCard = V;
	}
	void setNoteBookMemory(const Memory& me) {
		if (&me == NULL)throw Exception("Memory Is Empty", __LINE__, __FILE__, Taketime());
		memory = me;
	}
	void setNoteBookSSD(const SSD& s) {
		if (&s == NULL)throw Exception("SSD Is Empty", __LINE__, __FILE__, Taketime());
		ssd = s;
	}
	void setNoteBookHDD(const HDD& h) {
		if (&h == NULL)throw Exception("HDD Is Empty", __LINE__, __FILE__, Taketime());
		hdd = h;
	}
	void setNotebookName(const string& name) {
		if (name == "")throw Exception("Notebook Name Is Empty", __LINE__, __FILE__, Taketime());
		this->name = name;
	}
	bool getIsSSD()const { return isSSD; }
	int ShowSelectAndUpdate(int select = 0)const override { return -1; }
	void setNoteBookPrice() {
		price = monitor.getPrice() + processor.getPrice() + videoCard.getPrice() + memory.getPrice();
		if (isSSD) price += ssd.getPrice();
		else price += hdd.getPrice();
		setPrice(price);
	}
	void ShowAll()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		mySetColor(4, 0);
		cout << "\t\tNote Book Quality -> " << getBuyed()<< endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowA()const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		mySetColor(4, 0);
		cout << "\t\tNote Book Quality -> " << getQuality() << endl;
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForGuest(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tNote Book Quality -> " << getQuality() << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tNote Book Price -> " << getPrice()<< endl;
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowAllForCart(int select)const {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(4, 0);
		cout << "\t\tNote Book Quality -> " << getBuyed()<< endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tNote Book Price -> " << getPrice()*getBuyed()<< endl;
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void Show(int select) {
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		if (select == 1)
		{
			mySetColor(9, 0);
			cout << " ---->  ";
		}
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowDetails()const {
		system("cls");
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tNote Book ID -> " << id << endl;
		mySetColor(2, 0);
		cout << "\t\tNote Book Name -> " << name << endl;
		cout << "\t\tNote Quality -> " << getQuality() << endl;
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(2, 0);
		monitor.Show();
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(2, 0);
		processor.Show();
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(2, 0);
		videoCard.Show();
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(2, 0);
		memory.Show();
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(2, 0);
		if (isSSD)ssd.Show();
		else hdd.Show();
		mySetColor(6, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(6, 0);
		cout << "\t\tNote Book Price -> " << price << endl;
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	void ShowForUpgradeOrDowngrade(int select) {
		ShowAll();
		mySetColor(6, 0);
		cout << "\t\tNote Book Price -> " << price << endl;
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
		monitor.ShowAndUpgradeOrDowngradeSelect(0);
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
		if (select == 1)processor.ShowAndUpgradeOrDowngradeSelect(1);
		else processor.ShowAndUpgradeOrDowngradeSelect(0);
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
		if (select == 2)videoCard.ShowAndUpgradeOrDowngradeSelect(1);
		else videoCard.ShowAndUpgradeOrDowngradeSelect(0);
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
		if (select == 3)memory.ShowAndUpgradeOrDowngradeSelect(1);
		else memory.ShowAndUpgradeOrDowngradeSelect(0);
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
		if (isSSD)
		{
		if (select == 4)ssd.ShowAndUpgradeOrDowngradeSelect(1);
		else ssd.ShowAndUpgradeOrDowngradeSelect(0);
		}
		else
		{
			if (select == 4)hdd.ShowAndUpgradeOrDowngradeSelect(1);
			else hdd.ShowAndUpgradeOrDowngradeSelect(0);
		}
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		if (select == 5)
		{
			mySetColor(1, 0);
			cout << "\t\t -->";
		}
		cout << "\t\t Exit this panel\n";
		mySetColor(4, 0);
		cout << "-----------------------------------------------------\n";
		mySetColor(7, 0);
	}
	int ShowDetailsAndSelect(int select = 1) {
		while (true)
		{
			mySetColor(4, 0);
			cout << "-----------------------------------------------------\n";
			mySetColor(6, 0);
			cout << "\t\tNote Book ID -> " << id << endl;
			if (select == 1)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tNotebook Category Id ->" << getCategoryId() << endl;
			if (select == 2)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tNote Book Name -> " << name << endl;
			if (select == 3)
			{
				mySetColor(1, 0);
				cout << "\t\t -->";
			}
			else mySetColor(2, 0);
			cout << "\t\tNote Quality -> " << getQuality() << endl;
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			monitor.ShowAndSelect(select);
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			processor.ShowAndSelect(select);
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			videoCard.ShowAndSelect(select);
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			memory.ShowAndSelect(select);
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			if (isSSD)ssd.ShowAndSelect(select);
			else hdd.ShowAndSelect(select);
			mySetColor(6, 0);
			cout << "-----------------------------------------------------\n";
			mySetColor(6, 0);
			cout << "\t\tNote Book Price -> " << price << endl;
			mySetColor(4, 0);
			cout << "-----------------------------------------------------\n";
			if (isSSD)
			{
			    if (select == 22)
			    {
			    	mySetColor(1, 0);
			    	cout << "\t\t -->";
			    }
				else mySetColor(2, 0);
			}
			else
			{
				if (select == 23)
				{
					mySetColor(1, 0);
					cout << "\t\t -->";
				}
				else mySetColor(2, 0);
			}
			cout << "\t\tExit Update Panel"<<endl;
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
						if (isSSD)
						{
							system("cls");
							select=22;
							continue;
						}
						else
						{
							
							system("cls");
							select=23;
							continue;
							
						}
					}
				}
				else if (key == DOWN)
				{
					if (isSSD)
					{
						if (select + 1 != 23) {
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
					else
					{
						if (select + 1 != 24) {
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
			}
			else if (key == ENTER)
			{
				system("cls");
				return select;
			}
			system("cls");
		}
	}
};
