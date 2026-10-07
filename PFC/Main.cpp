#include <iostream>

using namespace std;
int playerscore = 0;
int botscore = 0;
int maxround = 3;

int AskInt(int min, int max)
{
	int value;
	while (true)
	{
		cin >> value;
		if (value >= min && value <= max)
			break;
		cout << "Erreur saisie " << endl;
	}
	return value;
}

void PrintChoice(int indice)
{
	if (indice == 1)
	{
		cout << "Pierre" ;

	}
	else if (indice == 2)
	{
		cout << "Feuille" ;

	}
	else
	{
		cout << " Ciseau" ;

	}
}
void MancheWin()
{

}
void GameWin()
{
	if (playerscore == botscore+2)
	{
		cout << "la partie est gagner " << endl;

	}
	else if (botscore == playerscore + 2)
	{
		cout << "la partie est perdu" << endl;
	}
}

int main()
{
	
	
	cout << "bienvenue sur le jeu du Pierre ,Feuille, Ciseaux" << endl;

	while ( playerscore != maxround )
	{


		cout << "tu as :" << playerscore << " de score" << endl;
		cout << "le bot as :" << botscore << " de score" << endl;


		srand(time(NULL));

		cout << "Pierre (1), Feuille (2), Ciseau (3) :";
		maxround++;
		int playerChoice = AskInt(1, 3);
		int botChoice = (rand() % 3) + 1;
		PrintChoice(playerChoice);
		cout << " VS ";
		PrintChoice(botChoice);
		cout << endl;

			if (playerChoice == 1)
			{
				if (botChoice == 1)
				{
					cout << "Egalite" << endl;
				}
				else if (botChoice == 2)
				{
					cout << "Perdu" << endl;
					botscore++;
				}
				else
				{
					cout << "Gagner " << endl;
					playerscore++;

				}

			}
			else if (playerChoice == 2)
			{
				if (botChoice == 1)
				{
					cout << "gagner" << endl;
					playerscore++;

					
				}
				else if (botChoice == 2)
				{
					cout << "Egalite" << endl;

				}
				else
				{
					cout << "perdu " << endl;
					botscore++;

					
				}
			}
	}
	return 0;
}