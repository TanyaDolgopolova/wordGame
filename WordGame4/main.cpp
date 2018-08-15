#include "FirstInteraction.h"
#include "Play.h"

int main()
{
	First_Interaction interaction;
	interaction.Greeting();
	char theme = interaction.ChooseTheme();
	interaction.Time();
	Play go(theme);
	string winner = go.Path();
	interaction.Mercy(winner);
	Sleep(4000);
	return 0;
}