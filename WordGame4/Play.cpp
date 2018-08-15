#include "Play.h"

Play::Play(char theme)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream in;
	char buff[35];
	switch(theme)
	{
		case('c'):
		{
			in.open("city.txt");
			break;
		}
		case('n'):
		{
			in.open("name.txt");
			break;
		}
		case('p'):
		{
			in.open("natu.txt");
			break;
		}
	}
	while (!in.eof())
	{
		in.getline(buff, 35);
		dictionary.insert(pair<string, bool>(buff, true));
	}
	in.close();
}

string Play::Path()
{
	string ans, botword, next;
	int conversions = 1;
	auto it = dictionary.begin();
	botword = it->first;
	it->second = false;
	SetConsoleTextAttribute(hConsole, 1);
	cout << "\nMy word: " << botword;
	while (true)
	{
		if (conversions % 5 == 0)
		{
			cout << "\nContinue?(y/n)";
			next = _getch();
			if (next == "n")
				return "none";
		}
		SetConsoleTextAttribute(hConsole, 9);
		cout << "\nYour word: ";
		getline(cin, ans);
		if (ans == "STOP")
			return "bot";
		if (CheckAnswer(ans, botword))
		{
			botword = SetAnswer(ans);
			if (botword == "STOP")
				return "player";
			SetConsoleTextAttribute(hConsole, 1);
			cout << "\nMy word: " << botword;
		}
			
		conversions++;
	}
}

bool Play::CheckAnswer(string answer, string botword)
{
	SetConsoleTextAttribute(hConsole, 12);
	botword[botword.length() - 1] = toupper(botword[botword.length() - 1]);
	if (islower(answer[0]))
		answer[0] = toupper(answer[0]);
	if (answer == "HELP")
	{
		go.help();
		return false;
	}
	if (answer[0] == botword[botword.length() - 1])
	{
		auto it = dictionary.find(answer);
		if (it != dictionary.end())
		{
			if (it->second != false)
			{
				it->second = false;
				return true;
			}
			else
			{
				cout << "\nThis word was used before, please retry.";
				return false;
			}
		}
		else cout << "\nI am sorry, but I do not know this word, please retry.";
	}
	else cout << "\nYou enter wrong word, please retry. Enter HELP for more information.";
	return false;
}

string  Play::SetAnswer(string userAnswer)
{
	userAnswer[userAnswer.length() - 1] = toupper(userAnswer[userAnswer.length() - 1]);
	auto it = dictionary.begin();
	while (true)
	{
		if (it->first[0] == userAnswer[userAnswer.length() - 1] && it->second != false)
		{
			it->second = false;
			return it->first;
		}
		else it++;
		if (it == dictionary.end())
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\nAll words beginning with this letter have already ended.";
			return "STOP";
		}
		
	}
}