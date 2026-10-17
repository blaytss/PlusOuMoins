#include <iostream>

using namespace std;

int AskNumber(int min, int max, int tab[])
{
    int number;
    cin >> number;

    while (number < min || number > max || tab[number] == -1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Chiffre deja utilise ou hors des limites, veuillez rentrer un nombre entier entre " << min << " et " << max << " : ";
        cin >> number;
    }

    return number;
}


int MatchNull(int tab[])
{
	for (int i = 1; i < 10; i++)
	{
		if (tab[i] != -1)
		{
			return 0;
		}
	}
	return 1;
}

int MatchWin(int tab[])
{
    if (tab[1] == tab[2] && tab[2] == tab[3])
    {
        return 1;
    }
    else if (tab[4] == tab[5] && tab[5] == tab[6])
    {
		return 1;
	}
	else if (tab[7] == tab[8] && tab[8] == tab[9])
	{
		return 1;
	}
	else if (tab[1] == tab[4] && tab[4] == tab[7])
	{
		return 1;
	}
	else if (tab[2] == tab[5] && tab[5] == tab[8])
	{
		return 1;
	}
	else if (tab[3] == tab[6] && tab[6] == tab[9])
	{
		return 1;
	}
    else
    {
        return 0;
    }

}

void printCell(int c)
{
    cout << "[";
    if (c == -1)
    {
        cout << "X";
    }
    else
    {
        cout << c;
    }
    cout << "]";
}

int main()
{

    cout << "Bienvenue sur le Morpion" << endl;

    int i = 1;
    int tab[10];

    for (int i = 1; i < 10; i++)
    {
        tab[i] = i;
    }

    while (true)
    {
        for (int i = 1; i < 10; i++)
        {
            printCell(tab[i]);
            if (i % 3 == 0)
            {
                cout << endl;
            }
        }
        

        cout << "Choisir une case" << endl;
        int index = AskNumber(1, 9, tab);
        system("cls");
        tab[index] = -1;


		if (MatchWin(tab) == 1)
		{
			cout << "Vous avez gagne !" << endl;
			break;
		}


        else if (MatchNull(tab) == 1)
        {
            cout << "Match nul !" << endl;
            break;
        }
    }

    return 0;
}
