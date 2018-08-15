#ifndef PLAYH
#define PLAYH

#include "FirstInteraction.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class Play
{
private:
	map <string, bool> dictionary;
	First_Interaction go;
	HANDLE hConsole;
public:
	Play(char);
	string Path();
	bool CheckAnswer(string, string);
	string SetAnswer(string);
};

#endif // !PLAYH