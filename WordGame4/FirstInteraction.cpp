#include "FirstInteraction.h"

First_Interaction::First_Interaction()
{
	m_ans = 'y';
	m_check = true;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void First_Interaction::Greeting()
{
	SetConsoleTextAttribute(hConsole, 11);
	cout << setw(65) << "~Game word~\n";
	Sleep(1000);
	cout << setw(70) << "~Welcome to the game~\n";
	Sleep(1000);
	SetConsoleTextAttribute(hConsole, 7);
	cout << "If you do not remember the rules of the game enter HELP\n";
	cout << "Do you want to learn the rules of the game now?(y/n) ";
	while (m_check)
	{
		m_ans = _getch();
		switch (m_ans)
		{
		case 'y': m_check = false; help(); break;
		case 'n': m_check = false;cout << "\nOkay, then let's start playing!\n"; break;
		default: cout << "\nPlease enter the letter in English without numbers or symbols: "; break;
		}
	}
	m_check = true;
}

void First_Interaction::help()
{
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\n\n"
		"1. Players play in turn (the first word is given by the game bot)\n"
		"2. The first word  must be 'A' if the game is began\n"
		"3. The last letter of the player's word is the first letter of the next player\n"
		"4. If all words beginning with this letter have already ended. The player is won."
		"5. If you do not know word which begin on this letter, write STOP. The player is lose."
		<< "\n\n";
}

char First_Interaction::ChooseTheme()
{
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\nEnter the first letter of the theme: \n ";
	SetConsoleTextAttribute(hConsole, 2);
	cout << "c - cities (easy) ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "n - names(medium) ";
	SetConsoleTextAttribute(hConsole, 4);
	cout << "p - plants(hard) ";
	SetConsoleTextAttribute(hConsole, 7);
	while (m_check)
	{
		m_ans = _getch();
		switch (m_ans)
		{
		case 'c':m_check = false;	return m_ans = 'c';
		case 'p':m_check = false; return m_ans = 'p';
		case 'n':m_check = false; return m_ans = 'n';
		default:
			cout << "\nPlease enter the letter in English without numbers or symbols: "; break;
		}
	}
	m_check = true;
}

void First_Interaction::Time()
{
	SetConsoleTextAttribute(hConsole, 3);
	int variable = 3;
	while (true)
	{
		system("cls");//очистка консоли
		cout << setw(68) << "Start the game through... ";
		cout << setw(110) << variable--;
		Sleep(970);//задержка в 1 секунду
		if (variable == 0)
		{
			system("cls");
			break;
		}
	}
}

void First_Interaction::Mercy(string winner)
{
	SetConsoleTextAttribute(hConsole, 11);
	if (winner == "none")
	{
		cout << "\nWhat a pity that you're leaving. It remains a little before my victory ...";
	}
	if (winner == "player")
	{
		cout << "\nDo you know that they do not sell containers at the store? Capacities that can accommodate my sadness!"
			<< "\nYou won!";
	}
	if (winner == "bot")
	{
		cout << "\nThere is nothing more joyful than winning."
			<<"\nYou lose!";
	}
}