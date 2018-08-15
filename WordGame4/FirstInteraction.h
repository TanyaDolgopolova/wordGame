#ifndef FIRSTINTERACTION_H
#define FIRSTINTERACTION_H
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

class First_Interaction
{
private:
	char m_ans;
	bool m_check;
	HANDLE hConsole;
public:
	First_Interaction();
	void Greeting();
	void help();
	char ChooseTheme();
	void Time();
	void Mercy(string);
};
#endif