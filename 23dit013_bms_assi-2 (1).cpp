
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <windows.h>
#include <vector>

using namespace std;

class account
{
    int birth1;
    int birth2;
    int birth3;
    int birth12;
    int acno;
    char name[50];
    int deposit;
    char type;
public:
    void create_account(); // function to get data from user
    void show_account() const; // function to show data on screen
    void modify(); // function to add new data
    void dep(int); // function to accept amount and add to balance amount
    void draw(int); // function to accept amount and subtract from balance amount
    void report() const; // function to show data in tabular format
    int retacno() const; // function to return account number
    int retdeposit() const; // function to return balance amount
    char rettype() const; // function to return type of account
};
void account::create_account()
{
    rep1:
    system("cls");
    cout << "\n\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Your Birth Date (DD) : -";
    cin>>birth1;
    if(birth1>=31 && birth1<=1)
    {
        cout<<"Not Found!!!!!! ";
        goto rep1;
    }
    cout<<"Your Birth Date (MM) : -";
    cin>>birth2;
    if(birth2>12 && birth2<=1)
    {
        cout<<"Not Found!!!!!! ";
        goto rep1;
    }
    else
    {
        if(birth2==2)
        {
            if(birth1>29)
            {
                cout<<"Date Not found ";
                goto rep1;
            }
        }
        else if(birth2%2==0)
        {
            if(birth1>30)
            {
                cout<<"\nDate Not found ";
                goto rep1;
            }
        }
    }
    cout<<"Your Birth Date (YYYY) : -";
    cin>>birth3;
    if(birth3>2024 && birth3<1900)
    {
        cout<<"Date Not Found ";
        goto rep1;
    }
    birth12=2024-birth3;
    cout<<"YOUR AGE IS "<<birth12;
    if(birth12>=18)
    {
        cout<<"\nYOUR AC IS MEJOR ";
    }
    else
    {
        cout<<"\nYOUR AC IS MINOR";
    }
    acno=(birth1*1000000)+(birth2*10000)+(birth3);
    cout<<"\n Your Ac Number is "<<acno;
    cout << "\nEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
    cin >> deposit;
    if(type=='C')
    {
        if(deposit<500)
        {
            cout<<"Amount is Less Try Again !! ";
            goto rep1;
        }
    }
    else if(type=='S')
    {
        if(deposit<1000)
        {
            cout<<"Amount is Less Try again !! ";
            goto rep1;
        }
    }
    else
    {
        cout<<"You Choose Wrong Type !! ";
        goto rep1;
    }
    cout << "\n\n\nAccount Created..";
    cout<<"\n\n \t\t\t Thanks For Opening Your Ac In DGFB ";
}

void account::show_account() const
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : ";
    cout << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}

void account::modify()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\nModify Balance amount : ";
    cin >> deposit;
}

void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();
void logo()
{
    system("cls");
    cout<<"\n\n\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------- ***********     ****************************** -----------------";
    cout<<"\n\t\t\t-------- *           *                                  -----------------";
    cout<<"\n\t\t\t-------- *           *                ***************** -----------------";
    cout<<"\n\t\t\t-------- *           *       **********                 -----------------";
    cout<<"\n\t\t\t-------- *           *                *                 -----------------";
    cout<<"\n\t\t\t--------            *   *           *                   -----------------";
    cout<<"\n\t\t\t-------- **********      ***********                    -----------------";
    cout<<"\n\t\t\t--------                                                -----------------";
    cout<<"\n\t\t\t-------- BANK             MANAGEMENT              SYSTEM ----------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\t\t\t-------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\t\t\t\t DGFB CREATED BY DHARMIK GOHIL FILM  ";
    Sleep(1000);
    system("cls");
    cout << "\n\n\n\n\n\n\n\t\t\t\t WELCOME TO DGFB BANK MANAGMENT SYSTEM ";
    cout<<"\n\n\t\t\t\t PLEASE WAIT . ";
    for (int i = 0; i <= 5; i++)
    {
        cout << " . ";
        Sleep(300);
    }

}

int main()
{
    //rep2:
    rep:
    int i;
    logo();
    system("cls");
    cout<<"\n\n \t You Are BankStaff or User (BankStaff Press 1 or User Press 2 ) : - ";
    cin>>i;
    int pass=123, pass1;
    if(i==1)
    {

        cout<<"\n\n\t\tEnter Password To Open Staff Page ";
        cout<<"\n\n\t\tEnter password :- ";
        cin>>pass1;

        if(pass1==pass)
        {
            cout<<"\n\t\t WELCOME TO DGFB STAFF PAGE "<<endl<<endl;
            char ch;
            int num;
            do
            {
                system("cls");
                cout << "\n\n\n\tMAIN MENU";
                cout << "\n\n\t01. BALANCE ENQUIRY";
                cout << "\n\n\t02. ALL ACCOUNT HOLDER LIST";
                cout << "\n\n\t03. CLOSE AN ACCOUNT";
                cout << "\n\n\t04. MODIFY AN ACCOUNT";
		cout << "\n\n\t05. EXIT";
		cout << "\n\n\t06. ENTER LOBY";
		cout << "\n\n\tSelect Your Option (1-5) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			display_sp(num);
			break;
		case '2':
			display_all();
		break;
		case '3':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			delete_account(num);
			break;
		case '4':
			cout << "\n\n\tEnter The account No. : ";
			cin >> num;
			modify_account(num);
			break;
		case '5':
			cout << "\n\n\tThanks for using bank managemnt system";
			cin.ignore();
		cin.get();
			 exit(0);
			break;
         case '6':
            cout<<"\n Goto Loby ";
            goto rep;
		default:
			cout << "\a";
		}
		cin.ignore();
		cin.get();
	}
    while (ch != '5');
    }
        }

else if(i!=2)
{
    cout<<"\n\t\tYour PassWord is Wrrong !! ";
    cin.get();
    cout<<"Sorry";
    goto rep;
}

 if(i==2)
{
    cout<<"\n\t\t WELCOME TO DGFB LOGIN PAGE "<<endl<<endl;
    char ch;
    int num;
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. NEW ACCOUNT";
        cout << "\n\n\t02. DEPOSIT AMOUNT";
        cout << "\n\n\t03. WITHDRAW AMOUNT";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\t05. ENTER LOBY";
        cout << "\n\n\tSelect Your Option (1-5) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);

        case '4':
            cout<<"\n\n\tThanks for using bank managemnt system";
            cin.ignore();
            cin.get();
            exit(0);
            break;
        case '5':
            cout<<" Goto Loby ";
            goto rep;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '4');
}

    else
    {
        cout<<"\n\n\t\t You Choose Wrong ";
         cin.ignore();
        cin.get();
        goto rep;
    }
    return 0 ;
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("Temp.txt", "account.txt");
	cout << "\n\n\tRecord Deleted ..";
}
void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.txt", ios::binary | ios::app);

    if (!outFile)
    {
        cout << "Error: Could not open file for writing." << endl;
        return;
    }

    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\tTO DEPOSITE AMOUNT ";
				cout << "\n\nEnter The amount to be deposited";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tTO WITHDRAW AMOUNT ";
				cout << "\n\nEnter The amount to be withdraw";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout<<"\n\n Record Not Found ";
}
void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\nBALANCE DETAILS\n";

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist";
}
void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}
void modify_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\nEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}
// Modify the display_sp function to pass the account number to display_transaction_history


// Modify the display_transaction_history function to use the accountNumber parameter
