#pragma once
#include"Component Functions.h"
class Person {
public:
	static int id;
	Person(){id++;}
};
int Person::id = 0;

class Guest :public Person {
	int _id;
	string fullname;
	string connected_date; //tarix saat
public:
	Guest() {}
	Guest(const string& fullname, const string& connected_date) {
		setFullname(fullname);
		setConnected_date(connected_date);
		_id = id;
	}
	Guest& operator=(Guest& other) {
		setFullname(other.getFullname());
		setConnected_date(other.getConnected_date());
		_id = other.id;
		return *this;
	}
	Guest(Guest& other) {
		setFullname(other.getFullname());
		setConnected_date(other.getConnected_date());
		_id = other.id;
	}
	void setConnected_date(const string& connected_date) {
		this->connected_date = connected_date;
	}
	void setFullname(const string& fullname) {
		this->fullname = fullname;
	}
	string getConnected_date()const { return connected_date; }
	string getUsername()const { return fullname; }
	string getFullname()const { return fullname; }
	int getId()const { return _id; }
};

class Notification {
	bool isRead; 
	Guest* guest;
	string text;
	string datetime;
public:
	bool getIsRead()const { return isRead; }
	Notification() :isRead(), guest(), text(), datetime() {}
	Notification(const bool isRead, Guest* guests, const string& text, const string& datetime) {
		this->isRead = isRead;
		this->text = text;
		guest = new Guest(*guests);
		this->datetime = datetime;
	}
	void ShowNotification() {
		cout << "\nIs Read ->" << boolalpha << isRead << endl;
		cout << "Guest Name ->" << guest->getFullname() << endl;
		cout << "Guest Connected Date ->" << guest->getConnected_date();
		cout << "Text ->" << text << endl;
		cout << "Notification Date Time ->" << datetime << endl;
		cout << "\n";
	}
	void isReaded() {
		isRead = 1;
	}
};
class Admin :public Person {
	Notification* Noti;
	int notificationCount = 0;
	int _id;
	string username;
	string password;
public:
	void addNotification(const bool isRead, Guest* guests, const string& text, const string& datetime) {
		if (Noti == nullptr)
		{
			notificationCount++;
			Noti = new Notification[notificationCount]{};
			Notification temp(isRead, guests, text, datetime);
			Noti[notificationCount - 1] = temp;
			ofstream fout("not.txt", ios::app);
			if (fout.is_open())
			{
				
				string guestName="Guest Name -> ";
				guestName += guests->getFullname();
				int temp2 = guests->getId();
				string connectedDate = "Notification Date Time -> ";
				connectedDate += guests->getConnected_date();
				string text1 = "Text -> ";
				text1 += text;

				fout << "****Notifications****"<<"\n";
				fout << "Guest Id -> "<<temp2<<"\n";
				fout << guestName <<"\n";
				fout << connectedDate <<"\n";
				fout << text1 <<"\n\n";
			}
			fout.close();
		}
		else
		{
			ofstream fout("not.txt", ios::app);
			if (fout.is_open())
			{

				string guestName = "Guest Name -> ";
				guestName += guests->getFullname();
				int temp2 = guests->getId();
				string connectedDate = "Date Time -> ";
				connectedDate += guests->getConnected_date();
				string text1 = "Text -> ";
				text1 += text;

				fout << "****Notifications****" << "\n";
				fout << "Guest Id -> " << temp2 << "\n";
				fout << guestName << "\n";
				fout << connectedDate << "\n";
				fout << text1 << "\n\n";
			}
			fout.close();
			Notification temp(isRead, guests, text, datetime);
			auto temp2 = new Notification[notificationCount + 1]{};
			for (int i = 0; i < notificationCount; i++)
			{
				temp2[i] = Noti[i];
			}
			temp2[notificationCount] = temp;
			notificationCount++;
			delete[]Noti;
			Noti = temp2;
			temp2 = nullptr;
		}
	}
	void ShowUnReadNotification() {
		for (int i = 0; i < notificationCount; i++)
		{
			if (!Noti[i].getIsRead())
			{

				Noti[i].ShowNotification();
				Noti[i].isReaded();
			}
		}
	}
	void ShowAllNotification() {
		for (int i = 0; i < notificationCount; i++)
		{
			Noti[i].ShowNotification();
			Noti[i].isReaded();
		}
	}
	Admin(const string& username, const string& password) {
		setUsername(username);
		setPassword(password);
		_id = id;
	}
	Admin(Admin& other) {
		setUsername(other.username);
		setPassword(other.password);
		_id = other.id;
	}
	Admin& operator=(Admin& other) {
		setUsername(other.username);
		setPassword(other.password);
		_id = other.id;
		return *this;
	}
	void setPassword(const string& password) {
		this->password = password;
	}
	void setUsername(const string& name) {
		this->username = name;
	}
	int getId()const { return _id; }
	string getUsername()const { return username; }
	string getPassword()const { return password; }
};

template<typename T>
class DbSet {
	T** items = nullptr;
	int items_count = 0;
public:
	void add(T* item) {
		if (isExistsItemByUsername(item->getUsername()))throw Exception("Your Username Already Have", __LINE__, __FILE__, Taketime());
		auto newT = new T * [items_count + 1]{};
		for (int i = 0; i < items_count; i++)
		{
			newT[i] = items[i];
		}
		newT[items_count] = item;
		items_count++;
		delete[]items;
		items = newT;
		newT = nullptr;
	}
	void addCompo(T* item) {
		int index=-1;
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getUsername() == item->getUsername()) {
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			auto newT = new T * [items_count + 1]{};
			for (int i = 0; i < items_count; i++)
			{
				newT[i] = items[i];
			}
			newT[items_count] = item;
			items_count++;
			delete[]items;
			items = newT;
			newT = nullptr;
		}
		else
		{
			items[index]->setQuality(items[index]->getQuality() + item->getQuality());
		}
	}
	void addCart(T* item,int quality) {
		//if (isExistsItem(item->getId()))throw Exception("Your Item Already Have Cart", __LINE__, __FILE__, Taketime());
	
		int index= items_count;
		bool isTrue=true;
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == item->getId()) {

				index = i;
				isTrue = false;
				break;
			}
			else
			{
				index = items_count;
				isTrue = true;
			}
		}
		if (isTrue)
		{
			auto newT = new T * [items_count + 1]{};
			for (int i = 0; i < items_count; i++)
			{
				newT[i] = items[i];
			}
			auto temp = dynamic_cast<Notebook*>(item);
			if (temp)
			{
				Notebook* temp23 = new Notebook();
				*temp23 = *temp;
				temp23->id = temp->getId();
				newT[index] = temp23;
			}
			else {
				newT[index] = item;
			}
			item->setQuality(item->getQuality() - quality);
			newT[index]->setBuyed(newT[index]->getBuyed() + quality);
			items_count++;
			delete[]items;
			items = newT;
			newT = nullptr;
		}
		else
		{
			items[index]->setQuality(items[index]->getQuality() - quality);
			items[index]->setBuyed(items[index]->getBuyed() + quality);
		}
	}
	void deleteByid(const int& id) {
		if (!isExistsItem(id))throw Exception("We Cant Find Your Item", __LINE__, __FILE__, Taketime());
		int index = 0;
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == id) {
				index = i;
				break;
			}
		}
		if (items_count - 1 != 0)
		{
			auto newFiles = new T * [items_count - 1]{};
			for (int i = 0, k = 0; i < items_count; i++)
			{
				if (i != index)
				{
					newFiles[k++] = items[i];
				}
			}
			items_count--;
			delete[]items;
			items = newFiles;
			newFiles = nullptr;
		}
		else
		{
			items_count--;
			delete[]items;
			items = nullptr;
		}
	}
	void deleteByidNoExp(const int& id) {
		int index = 0;
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == id) {
				index = i;
				break;
			}
		}
		if (items_count - 1 != 0)
		{
			auto newFiles = new T * [items_count - 1]{};
			for (int i = 0, k = 0; i < items_count; i++)
			{
				if (i != index)
				{
					newFiles[k++] = items[i];
				}
			}
			items_count--;
			delete[]items;
			items = newFiles;
			newFiles = nullptr;
		}
		else
		{

			items_count--;
			delete[]items;
			items = nullptr;
		}
	}
	void deleteByUsername(const string& name) {
		if (!isExistsItemByUsername(name))throw Exception("We Cant Find Your Item", __LINE__, __FILE__, Taketime());
		int index = 0;
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getUsername() == name) {
				index = i;
				break;
			}
		}
		if (items_count - 1 != 0)
		{
			auto newFiles = new T * [items_count - 1]{};
			for (int i = 0, k = 0; i < items_count; i++)
			{
				if (i != index)
				{
					newFiles[k++] = items[i];
				}
			}
			items_count--;
			delete[]items;
			items = newFiles;
			newFiles = nullptr;
		}
		else
		{

			items_count--;
			delete[]items;
			items = nullptr;
		}
	}
	bool isExistsItemByUsername(const string& name) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getUsername() == name) {
				return true;
			}
		}
		return false;
	}
	bool isExistsItem(const int& id) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == id) {
				return true;
			}
		}
		return false;
	}
	bool itemEmpty()const {
		if (items_count > 0)return true;
		else return false;
	}
	int SearchByUsername(const string& username) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getUsername() == username) {
				return items[i]->getId();
			}
		}
		return -1;
	}
	T* SearchAndGetById(const int& id) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == id) {
				return items[i];
			}
		}
		return nullptr;
	}
	T* getItem(const int& id) {
		if (!isExistsItem(id))throw Exception("We Cant Find Your Item or User", __LINE__, __FILE__, Taketime());
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getId() == id) {
				return items[i];
			}
		}
	}
	int ShowAndSelectDetails(Notebook* temp)const {
		int select = 1;
		while (true)
		{
			temp->ShowForUpgradeOrDowngrade(select);
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
	void Show() {
		for (int i = 0; i < items_count; i++)
		{
			items[i]->ShowAll();
			cout << "\n";
		}
	}
	void ShowForAdmin() {
		for (int i = 0; i < items_count; i++)
		{
			items[i]->ShowA();
			cout << "\n";
		}
	}
	void ShowForAdminbyCategory(const int id) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getCategoryId() == id) {
				items[i]->ShowA();
				cout << "\n";
			}
		}
	}
	int ShowCartAndSelect() {
		int* select = new int[items_count] {};
		int index = 0;
		select[index] = 1;
		while (true)
		{
			for (int i = 0; i < items_count; i++)
			{
			
				items[i]->ShowAllForCart(select[i]);
				cout << "\n";
				
			}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						system("cls");
						select[index] = 0;
						select[--index] = 1;
						continue;
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						system("cls");
						select[index] = 0;
						select[++index] = 1;
						continue;
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = 0;
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == items_count)
				{
					return -1;
				}
				else
				{
					return items[index]->getId();;

				}
			}
			system("cls");
		}
	}
	int ShowAndSelect() {
		int* select = new int[items_count]{};
		int index = 0;
		select[index] = 1;
		while (true)
		{
			for (int i = 0; i < items_count; i++)
			{
				items[i]->Show(select[i]);
				cout << "\n";
			}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						system("cls");
						select[index]=0;
						select[--index]=1;
						continue;
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						system("cls");
						select[index] = 0;
						select[++index] = 1;
						continue;
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = 0;
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index==items_count)
				{
					return -1;
				}
				else
				{
				return items[index]->getId();;

				}
			}
			system("cls");
		}
	}
	int ShowAndSelectForGuest(int temp32=0) {
		if (temp32 == 0) {
			int count1=0;
			for (int i = 0; i < items_count; i++)
			{
				if (items[i]->getQuality() <= 0) {
					count1++;
				}
			}
			if (count1 == items_count)return -1;
		}
		int* select = new int[items_count+1] {};
		int* showed = new int[items_count+1] {};
		int index = 0;
		select[index] = 1;
		while (true)
		{
			if (temp32==0)
			{
				for (int i = 0; i < items_count; i++)
				{
					if (items[i]->getQuality() > 0) {
						items[i]->ShowAllForGuest(select[i]);
						showed[i] = 1;
						cout << "\n";
					}
				}
			}
			else
			{
				for (int i = 0; i < items_count; i++)
				{
						items[i]->ShowAllForGuest(select[i]);
						showed[i] = 1;
						cout << "\n";
				}
			}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						if (showed[index-1] == 1)
						{
							system("cls");
							select[index] = 0;
							select[--index] = 1;
							continue;
						}
						else
						{
							int count = 0;
							for (int i = index-1; count < items_count; i--)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index-1-count<0)
							{
								system("cls");
								select[index] = 0;
								index = items_count;
								select[index] = 1;
								continue;
							}
							else {
							system("cls");
							select[index] = 0;
							index =index-1-count;
							select[index] = 1;
							continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						if (index==items_count-1)
						{
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 1) {
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 0) {
							int count = 0;
							for (int i = index + 1; i < items_count; i++)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index + 1 + count > items_count)
							{
								system("cls");
								select[index] = 0;
								index = 0;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index + 1 + count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						for (int i = 0; i < items_count; i++)
						{
							if (showed[i] == 1) {
								index = i;
								break;
							}
						}
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == items_count)
				{
					return -1;
				}
				else
				{
					if (temp32==0)
					{
						if (items[index]->getQuality() > 0) {

							return items[index]->getId();;
						}
					}
					else
					{
						return items[index]->getId();;
					}
				}
			}
			system("cls");
		}
	}
	template<typename T>
	T* ShowAndSelectForGuest(int count5) {
			int count1 = 0;
			for (int i = 0; i < items_count; i++)
			{
				if (items[i]->getQuality() < count5) {
					count1++;
				}
			}
			if (count1 == items_count)return NULL;
		int* select = new int[items_count + 1]{};
		int* showed = new int[items_count + 1]{};
		int index = 0;
		select[index] = 1;
		while (true)
		{
				for (int i = 0; i < items_count; i++)
				{
					if (items[i]->getQuality() >= count5) {
						auto temp53 = dynamic_cast<T*>(items[i]);
						if (temp53)
						{
							items[i]->ShowAllForGuest(select[i]);
							showed[i] = 1;
							cout << "\n";
						}
					}
				}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						if (showed[index - 1] == 1)
						{
							system("cls");
							select[index] = 0;
							select[--index] = 1;
							continue;
						}
						else
						{
							int count = 0;
							for (int i = index - 1; count < items_count; i--)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index - 1 - count < 0)
							{
								system("cls");
								select[index] = 0;
								index = items_count;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index - 1 - count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						if (index == items_count - 1)
						{
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 1) {
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 0) {
							int count = 0;
							for (int i = index + 1; i < items_count; i++)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index + 1 + count > items_count)
							{
								system("cls");
								select[index] = 0;
								index = 0;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index + 1 + count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						for (int i = 0; i < items_count; i++)
						{
							if (showed[i] == 1) {
								index = i;
								break;
							}
						}
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == items_count)
				{
					return NULL;
				}
				else
				{
					if (items[index]->getQuality() >= count5) {

						auto t = dynamic_cast<T*>(items[index]);
						return t;
					}
				}
			}
			system("cls");
		}
	}
	int ShowAndSelectForGuestByCategoryId(const int categoryid) {
			int count1 = 0;
			for (int i = 0; i < items_count; i++)
			{
				if (items[i]->getQuality() <= 0) {
					count1++;
				}
			}
			if (count1 == items_count)return -1;
		int* select = new int[items_count + 1]{};
		int* showed = new int[items_count + 1]{};
		int index = 0;
		select[index] = 1;
		while (true)
		{
				for (int i = 0; i < items_count; i++)
				{
					if (items[i]->getQuality() > 0&& items[i]->getCategoryId()==categoryid) {
						items[i]->ShowAllForGuest(select[i]);
						showed[i] = 1;
						cout << "\n";
					}
				}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						if (showed[index - 1] == 1)
						{
							system("cls");
							select[index] = 0;
							select[--index] = 1;
							continue;
						}
						else
						{
							int count = 0;
							for (int i = index - 1; count < items_count; i--)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index - 1 - count < 0)
							{
								system("cls");
								select[index] = 0;
								index = items_count;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index - 1 - count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						if (index == items_count - 1)
						{
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 1) {
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 0) {
							int count = 0;
							for (int i = index + 1; i < items_count; i++)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index + 1 + count > items_count)
							{
								system("cls");
								select[index] = 0;
								index = 0;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index + 1 + count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						for (int i = 0; i < items_count; i++)
						{
							if (showed[i] == 1) {
								index = i;
								break;
							}
						}
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
				if (index == items_count)
				{
					return -1;
				}
				else
				{
					if (items[index]->getQuality() > 0 && items[index]->getCategoryId() == categoryid) {

						return items[index]->getId();;
					}
					else
					{
						system("cls");
						continue;
					}
				}
			}
			system("cls");
		}
	}
	void changeCategoryIdForProducts(const int categoryid,const int newCid) {
		for (int i = 0; i < items_count; i++)
		{
			if (items[i]->getCategoryId() == categoryid) {
				items[i]->setCategoryId(newCid);
			}
		}
	}
	int ShowAndSelectForGuestByCategoryIdForAdmin(const int categoryid) {
		int* select = new int[items_count + 1]{};
		int* showed = new int[items_count + 1]{};
		int index = 0;
		select[index] = 1;
		while (true)
		{
			for (int i = 0; i < items_count; i++)
			{
				if (items[i]->getCategoryId() == categoryid) {
					items[i]->ShowAllForGuest(select[i]);
					showed[i] = 1;
					cout << "\n";
				}
			}
			mySetColor(4, 0);
			if (select[items_count] == 1)
			{
				mySetColor(9, 0);
				cout << " ---->  ";
			}
			cout << "\t\tExit\n";
			mySetColor(7, 0);
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				if (key == UP)
				{
					if (index != 0) {
						if (showed[index - 1] == 1)
						{
							system("cls");
							select[index] = 0;
							select[--index] = 1;
							continue;
						}
						else
						{
							int count = 0;
							for (int i = index - 1; count < items_count; i--)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index - 1 - count < 0)
							{
								system("cls");
								select[index] = 0;
								index = items_count;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index - 1 - count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						index = items_count;
						select[index] = 1;
						continue;
					}
				}
				else if (key == DOWN)
				{
					if (index != items_count) {
						if (index == items_count - 1)
						{
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 1) {
							system("cls");
							select[index] = 0;
							select[++index] = 1;
							continue;
						}
						else if (showed[index + 1] == 0) {
							int count = 0;
							for (int i = index + 1; i < items_count; i++)
							{
								if (showed[i] == 0)count++;
								else break;
							}
							if (index + 1 + count > items_count)
							{
								system("cls");
								select[index] = 0;
								index = 0;
								select[index] = 1;
								continue;
							}
							else {
								system("cls");
								select[index] = 0;
								index = index + 1 + count;
								select[index] = 1;
								continue;
							}
						}
					}
					else
					{
						system("cls");
						select[index] = 0;
						for (int i = 0; i < items_count; i++)
						{
							if (showed[i] == 1) {
								index = i;
								break;
							}
						}
						select[index] = 1;
						continue;
					}
				}
			}
			else if (key == ENTER)
			{
			if (index == items_count)
			{
				return -1;
			}
			else if (items[index]->getCategoryId() != categoryid) {
				system("cls");
				continue;
			}
			else return items[index]->getId();
			}
			system("cls");
		}
	}
};
class DataServer {
public:
	DbSet<Admin>admins;
	DbSet<Guest>guest;
	DbSet<Product>Cart;
	DbSet<Product>PcItems;
	DataServer() {}
};
int CartMenu(int select = 1) {
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
		cout << "Details\n";
		mySetColor(7, 0);
		if (select == 4) {
			mySetColor(2, 0);
			cout << "\t\t\t-->>";
		}
		else cout << "\t\t\t";
		cout << "Upgrade Or Downgrade\n";
		mySetColor(7, 0);
		if (select == 5) {
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

void LookCart(DataServer& Db,Guest& gues) {
	while (true)
	{
		if (!Db.Cart.itemEmpty())break;
		auto temp = Db.Cart.ShowCartAndSelect();
		if (temp == -1)break;
		auto temp32 = dynamic_cast<Notebook*>(Db.Cart.getItem(temp));
		if (temp32)
		{
			while (true)
			{
				auto temp23 = CartMenu();
				if (temp23 == 5)break;
				else if (temp23 == 3)
				{
					temp32->ShowDetails();
				}
				else if (temp23 == 1)
				{
					string buyedItem = "Guest Buyyed ";
					buyedItem += to_string(Db.Cart.getItem(temp)->getBuyed());
					buyedItem += " Unit ";
					buyedItem += Db.Cart.getItem(temp)->getUsername();
					buyedItem += " Item";
					Db.admins.getItem(Db.admins.SearchByUsername("admin"))->addNotification(0, &gues, buyedItem, Taketime());
					int a = Db.Cart.getItem(temp)->getPrice();
					int b = Db.Cart.getItem(temp)->getBuyed();
					AddPrice(a * b);

					Db.Cart.getItem(temp)->setBuyed(0);
					Db.Cart.deleteByid(temp);
					system("cls");
					break;

				}
				else if (temp23 == 2) {

					try
					{
					if (temp32->getNoteBookCpu()->getCpuName() != static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookCpu()->getCpuName()) {
						auto temp92 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(temp32->getNoteBookCpu()->getCpuName()));
						temp92->setQuality(temp92->getQuality() + temp32->getBuyed());
						auto temp29 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookCpu()->getCpuName()));
						temp29->setQuality(temp29->getQuality() - temp32->getBuyed());
					}
					if (temp32->getNoteBookVideoCard()->getVideoCardName() != static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookVideoCard()->getVideoCardName()) {
						auto temp92 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(temp32->getNoteBookVideoCard()->getVideoCardName()));
						temp92->setQuality(temp92->getQuality() + temp32->getBuyed());
						auto temp29 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookVideoCard()->getVideoCardName()));
						temp29->setQuality(temp29->getQuality() - temp32->getBuyed());
					}
					if (temp32->getNoteBookMemory()->getMemoryName() != static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookMemory()->getMemoryName()) {
						auto temp92 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(temp32->getNoteBookMemory()->getMemoryName()));
						temp92->setQuality(temp92->getQuality() + temp32->getBuyed());
						auto temp29 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookMemory()->getMemoryName()));
						temp29->setQuality(temp29->getQuality() - temp32->getBuyed());
					}
					if (temp32->getIsSSD())
					{
						if (temp32->getNoteBookSSD()->getSSDName() != static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookSSD()->getSSDName()) {
							auto temp92 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(temp32->getNoteBookSSD()->getSSDName()));
							temp92->setQuality(temp92->getQuality() + temp32->getBuyed());
							auto temp29 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookSSD()->getSSDName()));
							temp29->setQuality(temp29->getQuality() - temp32->getBuyed());
						}
					}
					else {
						if (temp32->getNoteBookHDD()->getHDDName() != static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookHDD()->getHDDName()) {
							auto temp92 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(temp32->getNoteBookHDD()->getHDDName()));
							temp92->setQuality(temp92->getQuality() + temp32->getBuyed());
							auto temp29 = Db.PcItems.getItem(Db.PcItems.SearchByUsername(static_cast<Notebook*>(Db.PcItems.getItem(temp))->getNoteBookHDD()->getHDDName()));
							temp29->setQuality(temp29->getQuality() - temp32->getBuyed());
						}
					}
					
					static_cast<Notebook*>(Db.PcItems.getItem(temp))->setQuality(Db.Cart.getItem(temp)->getBuyed() + static_cast<Notebook*>(Db.PcItems.getItem(temp))->getQuality());
					Db.Cart.deleteByid(temp);
					system("cls");
					break;
					}
					catch (const Exception& Ex)
					{
						Db.Cart.deleteByidNoExp(temp);
						system("cls");
						break;
					}
				}
				else if (temp23 == 4) {
					while (true)
					{
						auto select = Db.PcItems.ShowAndSelectDetails(temp32);
						if (select == 5)break;
						else if (select == 1)
						{
							auto NoteBookCpu = temp32->getNoteBookCpu();
							system("cls");
							auto BuyedCpu = Db.PcItems.ShowAndSelectForGuest<Cpu>(temp32->getBuyed());
							if (BuyedCpu)
							{
								Cpu* OldCpu = new Cpu(1, " ", 1, 1, 1, 0);
								*OldCpu = *NoteBookCpu;
								Cpu* NewCpu = new Cpu(1, " ", 1, 1, 1, 0);
								*NewCpu = *BuyedCpu;
								NewCpu->setQuality(1);
								OldCpu->setCategoryId(-5);
								OldCpu->setQuality(temp32->getBuyed());
								Db.PcItems.addCompo(OldCpu);
								BuyedCpu->setQuality(BuyedCpu->getQuality() - temp32->getBuyed());
								temp32->setNoteBookCpu(*NewCpu);
							}
						}
						else if (select == 2) {
							auto NoteBookVideoCard = temp32->getNoteBookVideoCard();
							system("cls");
							auto BuyedVideoCard = Db.PcItems.ShowAndSelectForGuest<VideoCard>(temp32->getBuyed());
							if (BuyedVideoCard)
							{
								VideoCard* OldVideoCard = new VideoCard(" ",1,1, 0);
								*OldVideoCard = *NoteBookVideoCard;
								VideoCard* NewVideoCard = new VideoCard(" ", 1, 1, 0);
								*NewVideoCard = *BuyedVideoCard;
								NewVideoCard->setQuality(1);
								OldVideoCard->setCategoryId(-5);
								OldVideoCard->setQuality(temp32->getBuyed());

								Db.PcItems.addCompo(OldVideoCard);
								BuyedVideoCard->setQuality(BuyedVideoCard->getQuality() - temp32->getBuyed());
								temp32->setNoteBookVideoCard(*NewVideoCard);
							}
						}
						else if (select == 3) {
							auto NoteBookMemory = temp32->getNoteBookMemory();
							system("cls");
							auto BuyedMemory = Db.PcItems.ShowAndSelectForGuest<Memory>(temp32->getBuyed());
							if (BuyedMemory)
							{
								Memory* OldMemory = new Memory(" ", 1, 1,1, 0);
								*OldMemory = *NoteBookMemory;
								Memory* NewMemory = new Memory(" ", 1, 1,1, 0);
								*NewMemory = *BuyedMemory;
								NewMemory->setQuality(1);
								OldMemory->setCategoryId(-5);
								OldMemory->setQuality(temp32->getBuyed());

								Db.PcItems.addCompo(OldMemory);
								BuyedMemory->setQuality(BuyedMemory->getQuality() - temp32->getBuyed());
								temp32->setNoteBookMemory(*NewMemory);
							}
						}
						else if (select == 4) {
							cout << "SSD  HDD";
							if (temp32->getIsSSD()) {
								auto NoteBookSSD = temp32->getNoteBookSSD();
								system("cls");
								auto BuyedSSD = Db.PcItems.ShowAndSelectForGuest<SSD>(temp32->getBuyed());
								if (BuyedSSD)
								{
									SSD* OldSSD = new SSD(" ", 1, 1, 0);
									*OldSSD = *NoteBookSSD;
									SSD* NewSSD = new SSD(" ", 1, 1, 0);
									OldSSD->setCategoryId(-5);
									OldSSD->setQuality(temp32->getBuyed());
									*NewSSD = *BuyedSSD;
									NewSSD->setQuality(1);
									Db.PcItems.addCompo(OldSSD);
									BuyedSSD->setQuality(BuyedSSD->getQuality() - temp32->getBuyed());
									temp32->setNoteBookSSD(*NewSSD);
								}
							}
							else
							{
								auto NoteBookHDD = temp32->getNoteBookHDD();
								system("cls");
								auto BuyedHDD = Db.PcItems.ShowAndSelectForGuest<HDD>(temp32->getBuyed());
								if (BuyedHDD)
								{
									HDD* OldHDD = new HDD(" ",1,1,1, 0);
									*OldHDD = *NoteBookHDD;
									HDD* NewHDD = new HDD(" ", 1, 1, 1, 0);
									OldHDD->setCategoryId(-5);
									*NewHDD = *BuyedHDD;
									NewHDD->setQuality(1);
									OldHDD->setQuality(temp32->getBuyed());

									Db.PcItems.addCompo(OldHDD);
									BuyedHDD->setQuality(BuyedHDD->getQuality() - temp32->getBuyed());
									temp32->setNoteBookHDD(*NewHDD);
								}
							}
						}
					}
				}
			}
		}
		else
		{
			while (true)
			{
				auto temp23 = CartMenuForComponent();
				if (temp23 == 3)break;
				else if (temp23 == 1) {
					string buyedItem = "Guest Buyyed ";
					buyedItem += to_string(Db.Cart.getItem(temp)->getBuyed());
					buyedItem += " Unit ";
					buyedItem += Db.Cart.getItem(temp)->getUsername();
					buyedItem += " Item";
					Db.admins.getItem(Db.admins.SearchByUsername("admin"))->addNotification(0, &gues, buyedItem, Taketime());
					int a = Db.Cart.getItem(temp)->getPrice();
					int b = Db.Cart.getItem(temp)->getBuyed();
					AddPrice(a*b);
					Db.Cart.getItem(temp)->setBuyed(0);
					Db.Cart.deleteByid(temp);
					break;
				}
				else if (temp23 == 2) {
					Db.Cart.getItem(temp)->setQuality(Db.Cart.getItem(temp)->getBuyed() + Db.Cart.getItem(temp)->getQuality());
					Db.Cart.getItem(temp)->setBuyed(0);
					Db.Cart.deleteByid(temp);
					break;

				}
			}
		}
	}
}
