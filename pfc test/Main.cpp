#include <iostream>

using namespace std;
int playerscore = 0;
int botscore = 0;
int draw = 0;
int playerchoice;


void PrintStatswin()
{
	cout << "tu as gagner :"<<playerscore<<" fois, tu as fait :"<<draw<<" d'egalite et tu as perdu :"<<botscore<<" fois";
}
void PrintStatsloose()
{
	cout << "tu as perdu :" << botscore << " fois, tu as fait :" << draw << " d'egalite et tu as gagner :" << playerscore << " fois";
}


int GetIAChoice(int rock, int paper, int scissor)
{
	int iachoice;
	if (playerchoice == 1 )
	{
		
		if (rock > paper && rock > scissor)
		{
			iachoice = 2;
			return iachoice;
		}
		else
		{
			iachoice = (rand() % 3) + 1;
			return iachoice;
		}
		rock++;
	}
	else if (playerchoice == 2)
	{
		
		if (paper > rock && paper > scissor)
		{
			iachoice = 3;
			return iachoice;
		}
		
		else
		{
			iachoice = (rand() % 3) + 1;
			return iachoice;
		}
		paper++;
	}
	else if (playerchoice == 3)
	{
		
		if (scissor > rock && scissor > paper)
		{
			iachoice = 1;
			return iachoice;
		}
		else
		{
			iachoice = (rand() % 3) + 1;
			return iachoice;
		}
		scissor++;
	}
	return playerchoice;
	

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
		playerchoice = AskInt(1, 3);
		GetIAChoice(1,2,3);
		system("cls");
		PrintChoice(playerchoice);
		cout << " VS ";
		
		PrintChoice(GetIAChoice(1, 2, 3));
		cout << endl;


		
		if (playerchoice == 1)
		{
			if (GetIAChoice(1, 2, 3) == 1)
			{
				cout << "Egalite" << endl;
				draw++;
			}
			else if (GetIAChoice(1, 2, 3) == 2)
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
		else if (playerchoice == 2)
		{
			if (GetIAChoice(1, 2, 3) == 1)
			{
				cout << "Gagne" << endl;
				playerscore++;


			}
			else if (GetIAChoice(1, 2, 3) == 2)
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
		else if (playerchoice == 3)
		{
			if (GetIAChoice(1, 2, 3) == 1)
			{
				cout << "Perdu" << endl;
				botscore++;


			}
			else if (GetIAChoice(1, 2, 3) == 2)
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