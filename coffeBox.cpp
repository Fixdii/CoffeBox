#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

string const PASS = "7998";
int cups = 7;
double balance = 0.0;
double const ESPRESSO = 1.80;
double const CAPPUCCINO = 2.30;
double const AMERICANO = 1.80;

void userMenu();
void adminMenu();
bool authorization();
void showBalance();
void loading(int index);
void getProceeds();
void showCups();
void cupsChecker();
void printReady();
void printNotEnough();
void addCups();
void coinMenu();
double addCoin(double coin);
void orderEspresso();
void orderCappuccino();
void orderAmericano();

int main()
{
	userMenu();
	return 0;
}

bool authorization()
{	
	int counter = 0;
	int ch = 0;
	string pass = "";

	while (pass != PASS)
	{
		system("cls");
		cout << "Please, enter the password: ";	
		
		while (true)                
		{			
			ch = _getch();        
			if (ch == 13)         
			{
				break;         
			}		
			if (ch == 8)     
			{
				cout << (char)8 << ' ' << char(8);				

				if (!pass.empty()) {
					pass.erase(pass.length() - 1);
				}					
				
			}
			else
			{
				cout << '*';            
				pass += (char)ch;       
			}
			
		}

		if (counter == 2) {
			cout << endl << "Error! CoffeeBox is blocked";
			return false;
		}
		
		counter++;	
	}
}

void userMenu()
{
	system("cls");

	int num = 0;

	cout << "\tMenu";
	cout << "\t" << balance << " BYN" << endl;
	cout << "1 - Add a coin" << endl;
	cout << "2 - Order an espresso (1.80)" << endl;
	cout << "3 - Order a cappuccino (2.30)" << endl;
	cout << "4 - Order an americano (1.80)" << endl;
	cout << "5 - Service menu" << endl;
	cout << "Enter the number: ";

	cin >> num;

	switch (num)
	{
	case 1:
		cupsChecker();
		coinMenu();
		break;
	case 2:
		cupsChecker();
		orderEspresso();
		break;
	case 3:
		cupsChecker();
		orderCappuccino();
		break;
	case 4:
		cupsChecker();
		orderAmericano();
		break;
	case 5:
		if (authorization())
		{
			adminMenu();
		}
		break;
	default:
		cout << "Error! Wrong number";
		break;
	}
}

void adminMenu()
{
	while (true) {
		system("cls");

		int num = 0;

		cout << "\tAdmin menu" << endl;
		cout << "1 - View balance" << endl;
		cout << "2 - Withdrawal of proceeds" << endl;
		cout << "3 - View the number of empty cups" << endl;
		cout << "4 - Add empty cups" << endl;
		cout << "5 - Return to main menu" << endl;
		cout << "Enter the number: ";

		cin >> num;

		switch (num)
		{
		case 1:
			showBalance();
			break;
		case 2:
			getProceeds();
			break;
		case 3:
			showCups();
			break;
		case 4:
			addCups();
			break;
		case 5:
			userMenu();
			break;
		default:
			cout << "Error! Wrong number";
			break;
		}
	}
}

void showBalance()
{
	system("cls");
	cout << "Current balance: " << balance << " BYN" << endl;
	_getch();
}

void showCups()
{
	system("cls");
	cout << cups << " cups left" << endl;
	_getch();
}

void addCups()
{
	system("cls");

	int cup = 0;

	cout << "How many cups have been added? ";
	cin >> cup;

	if ((cups + cup) <= 700) {	
		cups += cup;

		cout << "Now there are " << cups << " cups in CoffeeBox";
		_getch();
	}
	else {
		cout << "Too many cups, add less!";
		_getch();
	}
}

void getProceeds()
{
	system("cls");

	showBalance();

	cout << "Wait, the money is being loaded" << endl;
	loading(6);

	balance = 0;

	cout << endl << "Upload completed, current balance: " << balance << " BYN" << endl;
	_getch();
}

void loading(int index)
{
	for (int i = 0; i < index; i++) {

		cout << "\b\b\b\b\b\b\b\b\b\bWaiting" << flush;
		Sleep(100); 
		cout << "\b\b\b\b\b\b\b\b\b\bWAiting" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaIting" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaiTing" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaitIng" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaitiNg" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaitinG" << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaiting." << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaiting.." << flush;
		Sleep(100);
		cout << "\b\b\b\b\b\b\b\b\b\bWaiting..." << flush;
		Sleep(100);
	}
}

void cupsChecker()
{
	if (cups == 0)
	{
		system("cls");
		cout << "Sorry, the cups are out.";
		Sleep(1000);
		userMenu();
	}
	else if (cups < 5)
	{
		system("cls");
		cout << "Attention: less than 5 cups left." << endl;
		Sleep(1000);
	}
	else
	{
		cout << endl;
	}
}

void coinMenu()
{
	system("cls");
	int num = 0;

	cout << "1 - 0.10 BYN" << endl;
	cout << "2 - 0.20 BYN" << endl;
	cout << "3 - 0.50 BYN" << endl;
	cout << "4 - 1 BYN" << endl;
	cout << "5 - 2 BYN" << endl;
	cout << "Enter the number: ";

	cin >> num;

	switch (num)
	{
	case 1:
		addCoin(0.10);
		break;
	case 2:
		addCoin(0.20);
		break;
	case 3:
		addCoin(0.50);
		break;
	case 4:
		addCoin(1);
		break;
	case 5:
		addCoin(2);
		break;
	default:
		cout << "Error! Wrong number.";
		break;
	}
	userMenu();
}

double addCoin(double coin)
{
	balance += coin;
	return balance;
}

void printReady()
{
	system("cls");
	loading(6);
	system("cls");
	cout << "Your coffee is ready!" << endl;
	Sleep(2500);
	cout << "Take your coffee";
	Sleep(3500);
}

void printNotEnough()
{
	system("cls");
	cout << "Not enough money";
	Sleep(600);
}

void orderEspresso()
{
	if (balance >= ESPRESSO)
	{
		printReady();
		balance -= ESPRESSO;
		cups--;
		userMenu();
	}
	else
	{
		printNotEnough();
		userMenu();
	}
}

void orderCappuccino()
{
	if (balance >= CAPPUCCINO)
	{
		printReady();
		balance -= CAPPUCCINO;
		cups--;
		userMenu();
	}
	else
	{
		printNotEnough();
		userMenu();
	}
}

void orderAmericano()
{
	if (balance >= AMERICANO)
	{
		printReady();
		balance -= AMERICANO;
		userMenu();
		cups--;
	}
	else
	{
		printNotEnough();
		userMenu();
	}
}