#include <iostream>

using namespace std;
int playerscore = 0;
int botscore = 0;
int draw = 0;


void PrintStatswin()
{
	cout << "tu as gagner :"<<playerscore<<" fois, tu as fait :"<<draw<<" d'egalite et tu as perdu :"<<botscore<<" fois";
}
void PrintStatsloose()
{
	cout << "tu as perdu :" << botscore << " fois, tu as fait :" << draw << " d'egalite et tu as gagner :" << playerscore << " fois";
}


int IA(int playerChoice)
{
	int rock = 0;
	int paper = 0;
	int scissor = 0;
	if (playerChoice == 1)
	{
		rock++;
		if (rock > paper && rock > scissor)
		{
			int botchoice = 3;
			return botchoice;
		}
	}
	else if (playerChoice == 2)
	{
		paper++;
		if (paper > rock && paper > scissor)
		{
			int botchoice = 1;
			return botchoice;
		}

	}
	else if (playerChoice == 3)
	{
		scissor++;
		if (scissor > rock && scissor > paper)
		{
			int botchoice = 2;
			return botchoice;
		}
	}
	return playerChoice;

}



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
int Getdistance()
{
	int distance = playerscore - botscore;
	if (distance < 0)
	{
		distance = distance * -1;
		if (distance >= 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (distance >= 2)
	{
		return true;
	}
	else if (distance < 2)
	{
		return false;
	}
}

void PrintChoice(int indice)
{
	if (indice == 1)
	{
		cout << "Pierre";

	}
	else if (indice == 2)
	{
		cout << "Feuille";

	}
	else
	{
		cout << " Ciseau";

	}
}

int main()
{
	
	int maxround = 3;

	cout << "bienvenue sur le jeu du Pierre ,Feuille, Ciseaux" << endl;

	while (true)
	{


		cout << "tu as :" << playerscore << " de score" << endl;
		cout << "le bot as :" << botscore << " de score" << endl;


		srand(time(NULL));
		cout << "Pierre (1), Feuille (2), Ciseau (3) :" << endl;
		int playerChoice = IA(AskInt(1, 3));
		system("cls");
		int botChoice =  1;
		PrintChoice(playerChoice);
		cout << " VS ";
		
		PrintChoice(botChoice);
		cout << endl;


		
		if (playerChoice == 1)
		{
			if (botChoice == 1)
			{
				cout << "Egalite" << endl;
				draw++;
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
				cout << "Gagne" << endl;
				playerscore++;


			}
			else if (botChoice == 2)
			{
				cout << "Egalite" << endl;
				draw++;
			}
			else
			{
				cout << "Perdu " << endl;
				botscore++;


			}
		}
		else if (playerChoice == 3)
		{
			if (botChoice == 1)
			{
				cout << "Perdu" << endl;
				botscore++;


			}
			else if (botChoice == 2)
			{
				cout << "Gagne" << endl;
				playerscore++;
			}
			else
			{
				cout << "Egalite " << endl;
				draw++;
			}
				


			


		}
		Getdistance();

		if (playerscore >= 10 && Getdistance() == true)
		{
			cout << "la partie est gagne"<<endl;
			PrintStatswin();
			break;
		}
		else if (botscore >= 10 && Getdistance() == true)
		{
			cout << "la partie est perdue" <<endl;
			PrintStatsloose();
			break;
		}

	}
	return 0;
}