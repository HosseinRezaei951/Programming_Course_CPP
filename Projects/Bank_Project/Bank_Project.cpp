#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;


// struct of birthday:
struct birthday
{
	char year[5];
	char month[3];
	char day[3];

};

// chang the char to number:
int change(char *num)
{
	int len = strlen(num);
	int number = 0;
	int count = 1;
	for (int i = 0;i < len;i++)
	{
		number = number + (int(num[i]) - int('0'))*(pow(10, len - count));
		count++;
	}
	return number;
};

// class of Customer:
class User
{
	friend class Account;
	friend class Bank;

private:
	char name[20];
	char family[20];
	char gender[2];                             //M for male or F for female
	birthday _birthday;
	char N_code[20];                      //N_code is National Code

public:
	void set_details();
	
};


// class of Bank_Data:
class Account

{
	friend class User;
	friend class Bank;
private:
	long account_number;
	char ID[20];
	long cash;

public:
	
	void set_details_Acc(long acc_num, char* id);
	void set_empty_account(long acc_num, char* id);


};


// class of Bank:
class Bank
{
	friend class Account;
private:
	User *P_User;
	Account *P_Acc;

	long  population = 0;
	long Acc_number = 0;

public:
	Bank();

	long get_population();
	long get_Acc_number();

	void Add_New_User();
	void Add_New_Acc_For_User();
	bool Have_this_User(char* N_code);

	void Open_User();
	void Open_Acc();

	void Show_All_Users();
	void Show_All_Accounts();
	void Show_All_Accounts_With_This_ID(char *ID);
	void Show_All_Users_With_This_ID(char *ID);
	void Show_User_information();
	void Show_Account_With_This_Accnum(long n);

	void Delete_All_Accounts_With_Same_ID(char* ID);
	void Delete_User();
	void Delete_Acc_For_User();
	
	bool User_Place(char* N_code, int &n);
	bool Acc_Place(char* N_code, int &n);

	bool Search_User2(char* N_code);
	bool Search_Acc2(char* N_code);
	bool Search_Acc3(long n,int &place);
	
	void Deposit();
	void Withdrawal();

	void Edit();

	void Save_Users();
	void Save_Accs();
	
};


/* =======================================================================================================================*/


Bank::Bank()
{
	Open_Acc();
	Open_User();
}

long Bank::get_Acc_number()
{
	return Acc_number;
}

long Bank::get_population()
{
	return population;
}
void Bank::Open_Acc()
{

	ifstream Acc_file;
	Acc_file.open("F:\\programming\\C++\\poroje\\bank\\files\\Account.txt");
	if (!Acc_file) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}

	int tmp_ACCnum;				/* tmp_ACCnum is temp Acc_number */
	Acc_file >> tmp_ACCnum;
	Acc_number = tmp_ACCnum;
	if (tmp_ACCnum > 0)
	{
		P_Acc = new Account[Acc_number];
		for (int i = 0;i <Acc_number;i++)
		{
			Acc_file >> P_Acc[i].account_number;
			Acc_file >> P_Acc[i].ID;
			Acc_file >> P_Acc[i].cash;
		}
	}
	
	Acc_file.close();
}

void Bank::Open_User()
{
	ifstream User_file;
	User_file.open("F:\\programming\\C++\\poroje\\bank\\files\\User.txt");
	if (!User_file) {
		cout << "Error in reading";
		_getch();
		exit(0);
	}
	int tmp_PP;				/* tmp_PP is temp population */
	User_file >> tmp_PP;
	if (tmp_PP > 0)
	{
		P_User = new User[tmp_PP + population];
		for (int i = 0;i < tmp_PP;i++)
		{
			User_file >> P_User[i].name;
			User_file >> P_User[i].family;
			User_file >> P_User[i].gender;
			User_file >> P_User[i]._birthday.year;
			User_file >> P_User[i]._birthday.month;
			User_file >> P_User[i]._birthday.day;
			User_file >> P_User[i].N_code;
		}
	}
	population = population + tmp_PP;
	User_file.close();
}

void Bank::Save_Users()
{
	ofstream User_file;
	User_file.open("F:\\programming\\C++\\poroje\\bank\\files\\User.txt");
	User_file << population << endl;
	for (int i = 0;i < population;i++)
	{
		User_file << P_User[i].name << " ";
		User_file << P_User[i].family << " ";
		User_file << P_User[i].gender << " ";
		User_file << P_User[i]._birthday.year << " ";
		User_file << P_User[i]._birthday.month << " ";
		User_file << P_User[i]._birthday.day << " ";
		User_file << P_User[i].N_code << " " << endl;
	}
	User_file.close();
	cout << "\t << save users well done. >>" << endl;
}

void Bank::Save_Accs()
{
	ofstream Acc_file;
	Acc_file.open("F:\\programming\\C++\\poroje\\bank\\files\\Account.txt");
	Acc_file << Acc_number << endl;
	for (int i = 0;i <Acc_number;i++)
	{
		Acc_file << P_Acc[i].account_number << " ";
		Acc_file << P_Acc[i].ID << " ";
		Acc_file << P_Acc[i].cash << endl;
	}
	Acc_file.close();
	cout << "\t <<save accounts well done. >>" << endl;
}

void Bank::Withdrawal()
{
	long n = 0;
	int place;

	cout << "\n\t\t\t ************* Withdrawal From Account *************" << endl;
	cout << "\n At the first plz enter the account number : ";
	cin >> n;
	while (Search_Acc3(n, place) == false)
	{
		cout << "\n\t\t <This account number doesnt have any account in the bank> " << endl;
		cout << "Plz enter another account number: ";
		cin >> n;
	}
	cout << "\n account information: \n";
	Show_Account_With_This_Accnum(n);

	cout << "\n\t ============================================== \n";
	long tmp_cash;
	cout << " How much money you want to  withdrawal: ";
	cin >> tmp_cash;
	while (tmp_cash>P_Acc[place].cash)
	{
		cout << "\n\t\t <This money is more than your cash in your account in the bank> " << endl;
		cout << "Plz enter another money you want to  withdrawal: ";
		cin >> tmp_cash;
	}
	P_Acc[place].cash = P_Acc[place].cash - tmp_cash;
}

void Bank::Deposit()
{
	long n;
	int place;
	
	cout << "\n\t\t\t ************* Deposit Money To Account *************" << endl;
	cout << "\n At the first plz enter account number : ";
	cin >> n;
	while (Search_Acc3(n, place) == false)
	{
		cout << "\n\t\t <There isnt any account with this account number in the bank> " << endl;
		cout << " Plz enter another account number: ";
		cin >> n;
	}
	cout << "\n account information: \n";
	Show_Account_With_This_Accnum(n);
	
	cout << "\n\t ============================================== \n";
	long tmp_cash;
	cout << " How much money you want to deposit: ";
	cin >> tmp_cash;
	P_Acc[place].cash = P_Acc[place].cash + tmp_cash;
}

void Bank::Show_User_information()
{
	long n;
	char ID[20];
	cout << "\n\t\t\t ************* Show User Information *************" << endl;
	cout << "\n At the first plz enter the ID(National Code): ";
	cin >> ID;
	while (Search_User2(ID) == false)
	{
		cout << "\n\t\t <This National Code doesnt have any account in the bank> " << endl;
		cout << "Plz enter another National Code: ";
		cin >> ID;
	}
	cout << "\n user information: \n";
	Show_All_Users_With_This_ID(ID);

	cout << "\n\t ============================================== \n";
	if (Search_User2(ID) == true)
	{
		cout << "\n account information: \n";
		Show_All_Accounts_With_This_ID(ID);
	}
	else
		return;
}
void Bank::Show_All_Users_With_This_ID(char* ID)
{
	for (int i = 0; i<population;i++)
	{
		if (strcmp(P_User[i].N_code, ID) == 0)
		{
			cout << "User (" << i + 1 << "): " << endl;
			cout << "\t" << " name: " << P_User[i].name << endl;
			cout << "\t" << " family: " << P_User[i].family << endl;
			cout << "\t" << " gender: " << P_User[i].gender << endl;
			cout << "\t" << " birthday: " << P_User[i]._birthday.year << "/" << (P_User[i]._birthday).month << "/" << (P_User[i]._birthday).day << endl;
			cout << "\t" << " National Code(ND): " << P_User[i].N_code << endl;
		}
	}
}
void Bank::Show_Account_With_This_Accnum(long n)
{
	for (int i = 0;i < Acc_number;i++)
	{
		if (P_Acc[i].account_number == n)
		{
			cout << "Account (" << i+1 << "): " << endl;
			cout << "\t" << " account number: " << P_Acc[i].account_number << endl;
			cout << "\t" << " ID: " << P_Acc[i].ID << endl;
			cout << "\t" << " cash: " << P_Acc[i].cash << endl;
			break;
		}
	}
}

void Bank::Show_All_Accounts_With_This_ID(char* ID)
{
	int count = 1;
	for(int i=0; i<Acc_number;i++)
	{
		if (strcmp(P_Acc[i].ID, ID) == 0)
		{
			cout << "Account (" << count << "): " << endl;
			cout << "\t" << " account number: " << P_Acc[i].account_number << endl;
			cout << "\t" << " ID: " << P_Acc[i].ID << endl;
			cout << "\t" << " cash: " << P_Acc[i].cash << endl;
			count++;
		}
	}
}

void Bank::Show_All_Accounts()
{
	cout << "\n\t\t\t ************* Show All Accounts *************" << endl;
	if (Acc_number>0)
	{
		for (int i = 0;i < Acc_number;i++)
		{
			cout << "Account (" << i + 1 << "): " << endl;
			cout << "\t" << " account number: " << P_Acc[i].account_number << endl;
			cout << "\t" << " ID: " << P_Acc[i].ID << endl;
			cout << "\t" << " cash: " << P_Acc[i].cash << endl;
		}
	}
	else
		cout << "\n\t\t <There isnt any user in the bank> " << endl;	
}

void Bank::Show_All_Users()
{
	cout << "\n\t\t\t ************* Show All Users *************" << endl;

	if (population > 0) {
		for (int i = 0;i < population;i++)
		{
			cout << "User (" << i + 1 << "): " << endl;
			cout << "\t" << " name: " << P_User[i].name << endl;
			cout << "\t" << " family: " << P_User[i].family << endl;
			cout << "\t" << " gender: " << P_User[i].gender << endl;
			cout << "\t" << " birthday: " << P_User[i]._birthday.year << "/" << (P_User[i]._birthday).month << "/" << (P_User[i]._birthday).day << endl;
			cout << "\t" << " National Code(ND): " << P_User[i].N_code << endl;
		}
	}
	else
		cout << "\n\t\t <There isnt any account in the bank> " << endl;
}

void Bank::Edit
()
{
	char ND[20];
	cout << "\n\t\t\t ************* Edit Users Profile & Account *************" << endl;
	cout << "\n At the first plz enter the ID(National Code): ";
	cin >> ND;
	
	while (Have_this_User(ND) != true)
	{
		cout << "\n\t\t <This National code dosent have any account in the bank> " << endl;
		cout << "Plz enter another National Code: ";
		cin >> ND;
	}
	cout << "\n\t\t <its OK, there is a user with this National Code. So,you can edit user profile> " << endl;
	cout << "\n user information: \n";
	Show_All_Users_With_This_ID(ND);
	cout << "\n\t ============================================== \n";

	int n,m;
	User_Place(ND, n);
	cout << "\n plz enter users new information: \n";
	P_User[n].set_details();
	
	while (Acc_Place(ND, m))
	{
		strcpy_s(P_Acc[m].ID, P_User[n].N_code);
	}
	cout << "\n\t\t <OK, every thing changed.> " << endl;
}

bool Bank::Have_this_User(char* N_code)
{
	char temp[20];
	for (int i = 0; i < population; i++)
	{

		strcpy_s(temp, P_User[i].N_code);
		if (strcmp(temp, N_code) == 0)
		{
			return true;
		}
	}
	return false;
}

void Bank::Add_New_Acc_For_User()
{
	char ND[20];
	cout << "\n\t\t\t ************* Add New Account For User *************" << endl;
	cout << "\n At the first plz enter the ID(National Code) : ";
	cin >> ND;
	Acc_number++;

	while (Search_Acc2(ND)==false)
	{
		cout << "\n\t\t <This National Code doesnt have any account in the bank> " << endl;
		cout << "Plz enter another National Code: ";
		cin >> ND;
	}


	Account *tmp2;
	tmp2 = new Account[Acc_number];
	for (int i = 0;i < Acc_number - 1;i++)
	{
		tmp2[i].account_number = P_Acc[i].account_number;
		strcpy_s(tmp2[i].ID, P_Acc[i].ID);
		tmp2[i].cash = P_Acc[i].cash;
	}
	char Q;
	cout << "\n\t\t <Do you want to consider cash for user>(y for yes or n for no): ";
	cin >> Q;

	if (Q == 'n' || Q == 'N')
	{
		tmp2[Acc_number - 1].set_empty_account(Acc_number, ND);
	}
	else if (Q == 'y' || Q == 'Y')
	{
		tmp2[Acc_number - 1].set_details_Acc(Acc_number, ND);
	}

	P_Acc = new Account[Acc_number];
	for (int i = 0;i < Acc_number;i++)
	{
		P_Acc[i].account_number = tmp2[i].account_number;
		strcpy_s(P_Acc[i].ID, tmp2[i].ID);
		P_Acc[i].cash = tmp2[i].cash;
	}
	delete[] tmp2;
}

void Bank::Add_New_User()
{
	char ND[20];
	cout << "\n\t\t\t ************* Add New User *************" << endl;

	cout << "\nTo find out is there another person with the same National Code.\n At the first plz enter the National Code : ";
	cin >> ND;
	while (Have_this_User(ND) == true)
	{
		cout << "\n\t\t <This National Code has another account in the bank> " << endl;
		cout << "Plz enter another National Code: ";
		cin >> ND;
	}
	cout << "\n\t\t <its OK, there is not any user with the same National Code. So,you can add new user> " << endl;
	population++;
	Acc_number++;

	User *tmp;
	tmp = new User[population];
	for (int i = 0;i < population-1;i++)
	{
		strcpy_s(tmp[i].name, P_User[i].name);
		strcpy_s(tmp[i].family, P_User[i].family);
		strcpy_s(tmp[i].gender, P_User[i].gender);
		strcpy_s(tmp[i]._birthday.day, P_User[i]._birthday.day);
		strcpy_s(tmp[i]._birthday.month, P_User[i]._birthday.month);
		strcpy_s(tmp[i]._birthday.year, P_User[i]._birthday.year);
		strcpy_s(tmp[i].N_code, P_User[i].N_code);
	}

	tmp[population-1].set_details();
	
	P_User = new User[population];
	for (int i = 0;i < population ;i++)
	{
		strcpy_s(P_User[i].name, tmp[i].name);
		strcpy_s(P_User[i].family, tmp[i].family);
		strcpy_s(P_User[i].gender, tmp[i].gender);
		strcpy_s(P_User[i]._birthday.day, tmp[i]._birthday.day);
		strcpy_s(P_User[i]._birthday.month, tmp[i]._birthday.month);
		strcpy_s(P_User[i]._birthday.year, tmp[i]._birthday.year);
		strcpy_s(P_User[i].N_code, tmp[i].N_code);
	}
	delete[] tmp;

	
	Account *tmp2;
	tmp2 = new Account[Acc_number];
	for (int i = 0;i < Acc_number - 1;i++)
	{
		tmp2[i].account_number = P_Acc[i].account_number;
		strcpy_s(tmp2[i].ID, P_Acc[i].ID);
		tmp2[i].cash = P_Acc[i].cash;
	}
	char Q;
	cout << "\n\t\t <Do you want to consider cash for user>(y for yes or n for no): ";
	cin >> Q;
	
	if (Q == 'n')
	{
		tmp2[Acc_number-1].set_empty_account(Acc_number, P_User[population-1].N_code);
	}
	else if (Q == 'y')
	{
		tmp2[Acc_number-1].set_details_Acc(Acc_number, P_User[population-1].N_code);
	}
	P_Acc = new Account[Acc_number];
	for (int i = 0;i < Acc_number;i++)
	{
		P_Acc[i].account_number = tmp2[i].account_number;
		strcpy_s(P_Acc[i].ID, tmp2[i].ID);
		P_Acc[i].cash = tmp2[i].cash;
	}
	delete[] tmp2;

}

void Account::set_details_Acc(long acc_num, char* id) {
	account_number = 110+acc_num;
	strcpy_s(ID, id);
	long tmpcash;
	cout << " How much money you want to put in your account: ";
	cin >> tmpcash;
	cash = tmpcash;
}
void Account::set_empty_account(long acc_num, char* id)
{
	account_number = 110+acc_num;
	strcpy_s(ID, id);
	cash = 0;
}

void User::set_details()
{

	cout << " enter name: ";
	cin >> name;

	cout << " enter family: ";
	cin >> family;

	char g[10];
	cout << " enter gender(M for male or F for female): ";
	cin >> g;

	while (strlen(g)>1)
	{
		cout << " WRONG!!! <gender most be one character>" << endl;
		cout<<"\t enter gender again(M for male or F for female): ";
		cin >> g;
	}
	strcpy_s(gender, g);

	cout << " enter birthday: \n";


	char* tmp;
		
	cout << "\t day: ";
	tmp = new char[10];
	cin >> tmp;
	
	while (strlen(tmp)>2 || (change(tmp))>31)
	{
		cout << " WRONG!!! <day most be Two-digit number and smaller than 32>"<<endl;
		cout<<"\t enter day again: ";
		cin >> tmp;
	}
	strcpy_s(_birthday.day,tmp);


	cout << "\t month: ";
	tmp = new char[10];
	cin >> tmp;
	
	while (strlen(tmp)>2 || change(tmp)>12)
	{
		cout << " WRONG!!! <month most be Two-digit number and smaller than 13>" << endl;
		cout << "\t enter month again: ";
		cin >> tmp;
	}
	strcpy_s(_birthday.month, tmp);


	cout << "\t year: ";
	tmp = new char[10];
	cin >> tmp;
	while (strlen(tmp)>4 && change(tmp)>2017)
	{
		cout << " WRONG!!! <year most be Four-digit number and smaller than 2018>" << endl;
		cout << "\t enter year again: ";
		cin >> tmp;
	}
	strcpy_s(_birthday.year, tmp);
	
	delete[] tmp;

	cout << " enter National Code: ";
	cin >> N_code;
}

bool Bank::User_Place(char *N_code, int &n)
{
	int flag = 0;
	for (int i = 0;i < population;i++)
	{
		if (strcmp(P_User[i].N_code, N_code) == 0)
		{
			n = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n there isnt any usere with this ID(National Code)" << endl;
		return false;
	}
	else if (flag == 1)
	{
		return true;
	}
}

bool Bank::Acc_Place(char *N_code, int &n)
{
	for (int i = 0;i < Acc_number;i++)
	{
		if (strcmp(P_Acc[i].ID, N_code) == 0)
		{
			n = i;
			return true;
		}
	}
	return false;
}

bool Bank::Search_User2(char *N_code)
{
	int flag = 0;
	for (int i = 0;i < population;i++)
	{
		if (strcmp(P_User[i].N_code, N_code) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n there isnt any usere with this ID(National Code)" << endl;
		return false;
	}
	else if (flag == 1)
	{
		return true;
	}
}

bool Bank::Search_Acc3(long n,int &place)
{
	int flag = 0;
	for (int i = 0;i < Acc_number;i++)
	{
		if (P_Acc[i].account_number==n)
		{
			flag = 1;
			place=i;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n there isnt any account with this account number" << endl;
		return false;
	}
	else if (flag == 1)
	{
		return true;
	}
}

bool Bank::Search_Acc2(char *N_code)
{
	int flag = 0;
	for (int i = 0;i < Acc_number;i++)
	{
		if (strcmp(P_Acc[i].ID, N_code) == 0)
		{
			flag=1;	
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n there isnt any account with this ID(National Code)" << endl;
		return false;
	}
	else if (flag==1)
	{
		return true;
	}	
}


void Bank::Delete_Acc_For_User()
{
	char ND[20];
	cout << "\n\t\t\t ************* Delete Account For User *************" << endl;
	cout << "\n At the first plz enter the ID(National Code): ";
	cin >> ND;
	if (Search_Acc2(ND) == false)
	{
		return;
	}
	Show_All_Accounts_With_This_ID(ND);
	long tmp_ND;
	cout << "\n plz enter the account number that you want to delete that: ";
	cin >> tmp_ND;
	while (Search_Acc2(ND)==true)
	{
		for (int i = 0;i < Acc_number;i++)
		{
			if (P_Acc[i].account_number == tmp_ND)
			{
				Acc_number--;
				Account *tmp;

				tmp = new Account[Acc_number];

				for (int j = 0;j < i;j++)
				{
					tmp[j].account_number = P_Acc[j].account_number;
					strcpy_s(tmp[j].ID, P_Acc[j].ID);
					tmp[j].cash = P_Acc[j].cash;
				}

				for (int k = i;k < Acc_number;k++)
				{

					tmp[k].account_number = P_Acc[k+1].account_number;
					strcpy_s(tmp[k].ID, P_Acc[k+1].ID);
					tmp[k].cash = P_Acc[k+1].cash;
				}
				P_Acc = new Account[Acc_number];
				for (int i = 0;i < Acc_number;i++)
				{
					P_Acc[i].account_number = tmp[i].account_number;
					strcpy_s(P_Acc[i].ID, tmp[i].ID);
					P_Acc[i].cash = tmp[i].cash;
				}
				delete[] tmp;
				break;
			}
		}
		char ans;
		cout << "\n do you want to delete another account with that ID (y for yes or n for no): ";
		cin >> ans;
		if (ans == 'y')
		{
			if (Search_Acc2(ND) == true)
			{
				Show_All_Accounts_With_This_ID(ND);
				cout << "\n plz enter the account number that you want to delete that: ";
				cin >> tmp_ND;
			}
			else
				return;
		}
		else if ( ans == 'n')
		{
			return;
		}
	}
		
}

void Bank::Delete_All_Accounts_With_Same_ID(char* ID)
{
	for (int i = 0;i < Acc_number;i++)
	{
		
		if (strcmp(P_Acc[i].ID, ID) == 0)
		{
			Acc_number--;
			Account *tmp;

			tmp = new Account[Acc_number];

			for (int j = 0;j < i;j++)
			{
				tmp[j].account_number = P_Acc[j].account_number;
				strcpy_s(tmp[j].ID, P_Acc[j].ID);
				tmp[j].cash = P_Acc[j].cash;
			}

			for (int k = i;k < Acc_number;k++)
			{

				tmp[k].account_number = P_Acc[k + 1].account_number;
				strcpy_s(tmp[k].ID, P_Acc[k + 1].ID);
				tmp[k].cash = P_Acc[k + 1].cash;
			}
			P_Acc = new Account[Acc_number];
			for (int i = 0;i < Acc_number;i++)
			{
				P_Acc[i].account_number = tmp[i].account_number;
				strcpy_s(P_Acc[i].ID, tmp[i].ID);
				P_Acc[i].cash = tmp[i].cash;
			}
			delete[] tmp;
			
		}
	}
	cout << "\n\t\t <OK,all accounts with this ID have been deleted.> " << endl;
}	

void Bank::Delete_User()
{
	char ND[20];
	cout << "\n\t\t\t ************* Delete User *************" << endl;
	cout << "\n At the first plz enter the ID(National Code) : ";
	cin >> ND;
	while (Have_this_User(ND) == false)
	{
		cout << "\n\t\t <Thers isnt any user with this ID(National Code) in the bank> " << endl;
		cout << "Plz enter another ID(National Code): ";
		cin >> ND;
	}
	Delete_All_Accounts_With_Same_ID(ND);
	

	population--;
	User *tmp;
	tmp = new User[population];
	int i = 0;
	while (strcmp(P_User[i].N_code,ND)!=0)
	{
		strcpy_s(tmp[i].name, P_User[i].name);
		strcpy_s(tmp[i].family, P_User[i].family);
		strcpy_s(tmp[i].gender, P_User[i].gender);
		strcpy_s(tmp[i]._birthday.day, P_User[i]._birthday.day);
		strcpy_s(tmp[i]._birthday.month, P_User[i]._birthday.month);
		strcpy_s(tmp[i]._birthday.year, P_User[i]._birthday.year);
		strcpy_s(tmp[i].N_code, P_User[i].N_code);
		i++;
	}
	for (int j = i;j < population;j++)
	{
		strcpy_s(tmp[j].name, P_User[j+1].name);
		strcpy_s(tmp[j].family, P_User[j+1].family);
		strcpy_s(tmp[j].gender, P_User[j+1].gender);
		strcpy_s(tmp[j]._birthday.day, P_User[j+1]._birthday.day);
		strcpy_s(tmp[j]._birthday.month, P_User[j+1]._birthday.month);
		strcpy_s(tmp[j]._birthday.year, P_User[j+1]._birthday.year);
		strcpy_s(tmp[j].N_code, P_User[j+1].N_code);
	}

	P_User = new User[population];
	for (int i = 0;i < population;i++)
	{
		strcpy_s(P_User[i].name, tmp[i].name);
		strcpy_s(P_User[i].family, tmp[i].family);
		strcpy_s(P_User[i].gender, tmp[i].gender);
		strcpy_s(P_User[i]._birthday.day, tmp[i]._birthday.day);
		strcpy_s(P_User[i]._birthday.month, tmp[i]._birthday.month);
		strcpy_s(P_User[i]._birthday.year, tmp[i]._birthday.year);
		strcpy_s(P_User[i].N_code, tmp[i].N_code);
	}
	cout << "\n\t\t <OK,user with this ID has been deleted.> " << endl;
	delete[] tmp;
}

int main() {
	Bank hossein;
	
	cout << "\n\t\t\t************************** Welcome to your BANK **************************" << endl;
	cout << "\n" << endl;
	char n[2] = { NULL };
	cout << "(1): show all users " << endl;
	cout << "(2): show all accounts " << endl;
	cout << "(3): add new user " << endl;
	cout << "(4): add new account for user " << endl;
	cout << "(5): delete user " << endl;
	cout << "(6): delete account for user " << endl;
	cout << "(7): show population & account number " << endl;
	cout << "(8): edit " << endl;
	cout << "(9): deposit money to account " << endl;
	cout << "(10): withdrawal from account" << endl;
	cout << "(11): show user information" << endl;
	cout << "(12): save users" << endl;
	cout << "(13): save accounts" << endl;
	cout << "(-1): exit " << endl;
	cout << "\n Plz enter number that you want function: ";
	cin >> n;
	int flag = 0;
	while (flag != 1)
	{
		if (strcmp("1", n) == 0)
		{
			hossein.Show_All_Users();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}

		else if (strcmp("2", n) == 0)
		{
			hossein.Show_All_Accounts();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("3", n) == 0)
		{
			hossein.Add_New_User();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("4", n) == 0)
		{
			hossein.Add_New_Acc_For_User();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("5", n) == 0)
		{
			hossein.Delete_User();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("6", n) == 0)
		{
			hossein.Delete_Acc_For_User();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("7", n) == 0)
		{
			cout << "population: " << hossein.get_population() << endl;
			cout << "Account number: " << hossein.get_Acc_number() << endl;
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("8", n) == 0)
		{
			hossein.Edit();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("9", n) == 0)
		{
			hossein.Deposit();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("10", n) == 0)
		{
			hossein.Withdrawal();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("11", n) == 0)
		{
			hossein.Show_User_information();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("12", n) == 0)
		{
			hossein.Save_Users();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");
		}
		else if (strcmp("13", n) == 0)
		{
			hossein.Save_Accs();
			cout << "\n\tPress any key to return to home ..." << endl;
			_getch();
			system("cls");

		}

		else if (strcmp("-1", n) == 0)
		{
			cout << "\n\t\t\t************************** Good Bye **************************" << endl;
			flag = 1;
			
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t************************** Wrong Number **************************" << endl;
			
		}
		if (strcmp("-1", n) != 0)
		{
			cout << "\n";
			cout << "***************************************************************************************************" << endl;
			cout << "\n" << endl;
			cout << "(1): show all users " << endl;
			cout << "(2): show all accounts " << endl;
			cout << "(3): add new user " << endl;
			cout << "(4): add new account for user " << endl;
			cout << "(5): delete user " << endl;
			cout << "(6): delete account for user " << endl;
			cout << "(7): show population & account number " << endl;
			cout << "(8): edit " << endl;
			cout << "(9): deposit money to account " << endl;
			cout << "(10): withdrawal from account" << endl;
			cout << "(11): show user information" << endl;
			cout << "(12): save users" << endl;
			cout << "(13): save accounts" << endl;
			cout << "(-1): exit " << endl;
			cout << "\n Plz enter number that you want function: ";
			cin >> n;
		}
		
	}
	
	_getch();
	return 0;
}