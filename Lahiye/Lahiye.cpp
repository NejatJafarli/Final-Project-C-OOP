#include"DataBase.h"
void readGuest() {
	ifstream fin("Guests.txt", ios::in);
	if (fin.is_open()) {
		int id;
		string name;
		while (!fin.eof())
		{
			fin >> id;
			fin >> name;


		}
		mySetColor(7, 0);
	}
	fin.close();
}
class FakeMain {
public:

		static void main() {

			try
			{
				DataServer Db;
				Admin* Adm = new Admin("admin", "admin");
				Guest* gues = new Guest("nicat", Taketime());
				Guest* guest = new Guest("n", Taketime());
				Db.admins.add(Adm);
				Db.guest.add(gues);
				Db.guest.add(guest);
				string name = "Asus Strix ROG G 17";
				Monitor m(" ",17.3, 300, 450, 0);
				Cpu c(500, "AMD Ryzen 7 5800H", 8, 4.4, 16, 0);
				VideoCard v("Nvidia GeForce RTX3070", 8, 1000,0);
				Memory me("HyperX", 16, 3000, 400, 0);
				SSD s("kingstone",1000, 350, 0);
				HDD h;
				Notebook Asus(1, name, m, c, v, me, h, s, 1,3);
				Db.PcItems.add(&Asus);
				Notebook Asus1(1, "hahaha", m, c, v, me, h, s, 3,3);
				Db.PcItems.add(&Asus1);
				Notebook Asus2(1, "hahdddaha", m, c, v, me, h, s, 1,3);
				Db.PcItems.add(&Asus2);
				Cpu compo(500, "AMD Ryzen 9 5900HX", 8, 4.4, 16, 2);
				Cpu com3po(500, "AMD Ryzen 9 5900HX", 8, 4.4, 16, 2);
				VideoCard v2("Nvidia GeForce rtx 2070", 16, 1000, 2);
				Memory me2("HyperxX", 16, 3000, 400, 2);
				SSD s2("ki44ngstone",1500, 950, 2);
				HDD h2("samsung", 1650, 10000, 1800, 2);
				Monitor m3("Asus Rog", 17.3, 300, 450, 3);
			

				Phone A80("Samsung A80", 3600, 6, 48, 1200,3);

				Db.PcItems.addCompo(&A80);
				Db.PcItems.addCompo(&compo);
				Db.PcItems.addCompo(&com3po);
				Db.PcItems.addCompo(&v2);
				Db.PcItems.addCompo(&me2);
				Db.PcItems.addCompo(&s2);
				Db.PcItems.addCompo(&h2);
				Db.PcItems.addCompo(&m3);
				//Memory me3("yperX", 16, 3000, 400, 10);
				//SSD s1("kingst33one",1900, 450, 10);
				//Cpu compo2(500, "Intel i7-9900k", 8, 5.7, 16, 5);
				//HDD h1("Crucial", 350, 7200, 500,5);
				//
				//Monitor m4("msi Offical", 15.6, 244, 850, 10);
				while (true)
				{
					int select = login(1);
					if (select == 1)
					{
						string fullname;
						cout << "Enter your FullName: ";
						getline(cin >> ws, fullname);
						cout << "\n";
						auto id = Db.guest.SearchByUsername(fullname);
						if (id == -1)throw Exception("Wrong Username", __LINE__, __FILE__, Taketime());

						auto g = Db.guest.getItem(id);
						if (g->getUsername() == fullname)
						{
							g->setConnected_date(Taketime());
							Db.admins.getItem(Db.admins.SearchByUsername("admin"))->addNotification(0, g, "Guest Logged In", Taketime());
							while (true)
							{
								int select2 = categories.CategorySelect();
								if (select2 == -1)break;
								else if (select2 == -5)LookCart(Db,*g);
								else
								{
									while (true)
									{
										auto temp = Db.PcItems.ShowAndSelectForGuestByCategoryId(select2);
										if (temp == -1)break;
										auto test = dynamic_cast<Notebook*>(Db.PcItems.getItem(temp));
										int temp23;
										if (test) temp23 = GuestMenuForNoteBook();
										else  temp23 = GuestMenuForComponent();
										if (temp23 == 1)
										{
											mySetColor(4, 0);
											cout << "\t\t Quality->";
											int quality;
											cin >> quality;
											if (Db.PcItems.getItem(temp)->getQuality() < quality)cout << "\t\t We Have Not " << quality << " Units " << Db.PcItems.getItem(temp)->getUsername() << " Component. We Have only " << Db.PcItems.getItem(temp)->getQuality() << " units\n";
											else
											{
												cout << "Okey You Add Cart " << quality << " units " << Db.PcItems.getItem(temp)->getUsername() << " Component \n";
												Db.Cart.addCart(Db.PcItems.getItem(temp), quality);
											}
										}
										else if (temp23 == 2 && test)test->ShowDetails();
										else if (temp23 == 2)Db.Cart.Show();
										else if (temp23 == 3)break;
									}
								}
							}
						}
					}
					else if (select == 2)
					{
						string username;
						string password;
						cout << "Enter Admin Username: ";
						getline(cin >> ws, username);
						cout << "Enter Admin Password: ";
						getline(cin >> ws, password);
						auto id = Db.admins.SearchByUsername(username);
						if (id == -1)throw Exception("Wrong Username", __LINE__, __FILE__, Taketime());
						auto a = Db.admins.getItem(id);
						if (a->getUsername() == username &&
							a->getPassword() == password)
						{
							cout << "\n\t\t\tEntered Control Panel\n";
							while (true)
							{
								int select2 = AdminPanel("Product");
								if (select2 == 9)break;
								else if (select2 == 1) {
									int select3 = categories.CategorySelectForAdminShowAll();
									if (select3 == -1)break;
									else
									{
										Db.PcItems.ShowForAdminbyCategory(select3);
									}
								}
								else if (select2 == 2) {
									while (true) {
										auto select3 = SelectWhatDoYouAdd("Add");// her yeni Product Gelende Bura Elave edirsen!
										if (select3 == -1)break;
										else if(select3==1)
										{
											mySetColor(6, 0);
											cout << "\t\tSelect Notebook Category\n";
											auto temp2 = categories.CategorySelectForAdminShowAll();
											if (temp2 == -1)break;
											auto g = CreateNotebook();
											g->setCategoryId(temp2);
											Db.PcItems.add(g);
										}
										else if (select3 == 2) {
											auto select4 = ComponentSelect();
											if (select4 == 1)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect Cpu Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												auto NewCpu = CreateCpu();
												mySetColor(6, 0);
												cout << "\t\tCpu Quality ->";
												int temp;
												mySetColor(2, 0);
												cin >> temp;
												NewCpu->setCategoryId(temp2);
												NewCpu->setQuality(temp);
												Db.PcItems.add(NewCpu);
												mySetColor(7, 0);
											}
											else if (select4 == 2)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect Monitor Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												mySetColor(2, 0);
												cout << "\t\tMonitor Name ->";
												string name;
												mySetColor(6, 0);
												getline(cin >> ws, name);
												auto NewMonitor = CreateMonitor();
												mySetColor(2, 0);
												cout << "\t\tMonitor Quality ->";
												int temp;
												mySetColor(6, 0);
												cin >> temp;
												NewMonitor->setCategoryId(temp2);
												NewMonitor->setMonitorName(name);
												NewMonitor->setQuality(temp);
												Db.PcItems.add(NewMonitor);
											}
											else if (select4 == 3)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect Video Card Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												auto newVideoCard = CreateVideoCard();
												mySetColor(6, 0);
												cout << "\t\tVideo Card Quality ->";
												int temp;
												mySetColor(2, 0);
												cin >> temp;
												newVideoCard->setCategoryId(temp2);
												newVideoCard->setQuality(temp);
												Db.PcItems.add(newVideoCard);
											}
											else if (select4 == 4)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect Memory  Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												auto newMemory = CreateMemory();
												mySetColor(2, 0);
												cout << "\t\tMemory Quality ->";
												int temp;
												mySetColor(6, 0);
												cin >> temp;
												newMemory->setCategoryId(temp2);
												newMemory->setQuality(temp);
												Db.PcItems.add(newMemory);
											}
											else if (select4 == 5)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect SSD Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												auto newSSD = CreateSSD();
												mySetColor(6, 0);
												cout << "\t\tSSD Quality ->";
												int temp;
												mySetColor(2, 0);
												cin >> temp;
												newSSD->setCategoryId(temp2);
												newSSD->setQuality(temp);
												Db.PcItems.add(newSSD);
											}
											else if (select4 == 6)
											{
												mySetColor(6, 0);
												cout << "\t\tSelect HDD Category\n";
												auto temp2 = categories.CategorySelectForAdminShowAll();
												auto newHDD = CreateHDD();
												mySetColor(2, 0);
												cout << "\t\tHDD Quality ->";
												int temp;
												mySetColor(6, 0);
												cin >> temp;
												newHDD->setCategoryId(temp2);
												newHDD->setQuality(temp);
												Db.PcItems.add(newHDD);
											}
										}
										else if (select3 == 3) {
										auto temp = CreatePhone();
										Db.PcItems.add(temp);
										}
									}
								}
								else if (select2 == 3) {
								{
									while (true)
									{
										auto temp3 = categories.CategorySelectForAdmin();
										if (temp3 == -1)break;
										while (true)
										{
											auto temp = Db.PcItems.ShowAndSelectForGuestByCategoryIdForAdmin(temp3);
											if (temp == -1)break;
											Db.PcItems.deleteByid(temp);
											mySetColor(4, 0);
											system("cls");
											cout << "\t\tDELETED ITEM\n";
											cout << "\t\tDELETED ITEM\n";
											cout << "\t\tDELETED ITEM\n";
											mySetColor(7, 0);
										}
									}
								}
}
								else if (select2 == 4) {
									while (true)
									{
										auto temp2 = categories.CategorySelectForAdminShowAll();
										if (temp2 == -1)break;

										while (true)
										{
											auto temp = Db.PcItems.ShowAndSelectForGuestByCategoryIdForAdmin(temp2);
											if (temp == -1)break;
											while (true)
											{

												auto tempNotebook = dynamic_cast<Notebook*>(Db.PcItems.getItem(temp));
												int temp4;
												if (tempNotebook)
												{
													temp4 = tempNotebook->ShowDetailsAndSelect();
												}
												else {
												temp4 = Db.PcItems.getItem(temp)->ShowSelectAndUpdate();
												if (temp4 == -1)break;
												}
												auto tempCpu = dynamic_cast<Cpu*>(Db.PcItems.getItem(temp));
												auto tempVideoCard = dynamic_cast<VideoCard*>(Db.PcItems.getItem(temp));
												auto tempMemory = dynamic_cast<Memory*>(Db.PcItems.getItem(temp));
												auto tempSSD = dynamic_cast<SSD*>(Db.PcItems.getItem(temp));
												auto tempHDD = dynamic_cast<HDD*>(Db.PcItems.getItem(temp));
												auto tempMonitor = dynamic_cast<Monitor*>(Db.PcItems.getItem(temp));
												auto tempPhone = dynamic_cast<Phone*>(Db.PcItems.getItem(temp));

												if (tempNotebook)
												{
													if (tempNotebook->getIsSSD())
													{
														if (temp4 == 22)break;
													}
													else
													{
														if (temp4 == 23)break;
													}
													system("cls");
													UpdateNoteBook(tempNotebook, temp4);
												}
												else if (tempMonitor) {
												
													UpdateMonitor(tempMonitor, temp4);
												}
												else if (tempHDD) {
												
													UpdateHDD(tempHDD, temp4);
												}
												else if (tempSSD) {
												
													UpdateSSD(tempSSD, temp4);
												}
												else if (tempMemory) {
												
													UpdateMemory(tempMemory, temp4);
												}
												else if (tempVideoCard) {
												
													UpdateVideoCard(tempVideoCard, temp4); 
												}
												else if (tempCpu) { 
												
													UpdateCpu(tempCpu, temp4);
												}
												else if (tempPhone) {
													UpdatePhone(tempPhone, temp4);
												}
											}
										}
									}
								}
								else if (select2 == 5) {
								ReadNot();
								}
								else if (select2 == 6) {
									mySetColor(6, 0);
									cout << "\t\t\tEnter New Category Name ->";
									string temp;
									mySetColor(2, 0);
									getline(cin >> ws, temp);
									Category* temp3 = new Category(temp);
									categories.addCategory(temp3);
								}
								else if (select2 == 7) {
									auto temp3 = categories.CategorySelectForAdmin();
									if (temp3 == -1)break;
									categories.deleteCategory(temp3);
									Db.PcItems.changeCategoryIdForProducts(temp3, -5);
								}
								else if (select2 == 8) {
									auto temp3 = categories.CategorySelectForAdmin();
									if (temp3 == -1)break;
									mySetColor(4, 0);
									cout << "\t\t\tEnter New Name ->";
									string temp635;
									mySetColor(2, 0);
									getline(cin >> ws, temp635);
									categories.changeCategoryName(temp3,temp635);
									mySetColor(7, 0);
								}
							}
						}
						else
						{
							throw Exception("Wrong Password", __LINE__, __FILE__, Taketime());
						}
					}
					else if (select == 3) {
						cout << "Enter Your FullName ->";
						string name;
						getline(cin >> ws, name);
						Guest* temp = new Guest(name, Taketime());
						Db.guest.add(temp);
						Db.admins.getItem(Db.admins.SearchByUsername("admin"))->addNotification(0, temp, "Guest Singup", Taketime());

					}
				}
			}
			catch (const Exception ex)
			{
				Product::_id = 0;
				Category::size = 0;
				ex.printMsg();
				FakeMain::main();
			}
		}
};



int main()
{
	categories.addCategory(aa);
	categories.addCategory(bb);
	categories.addCategory(cc);

	FakeMain::main();

	
}

