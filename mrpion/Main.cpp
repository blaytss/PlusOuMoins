#include <iostream>

using namespace std;

int AskNumber(int min, int max)
{
    int number;
    while (true)
    {
        cin >> number;
        if (number >= min && number <= max)
            break;
        cout << "Erreur saisie " << endl;
    }
    return number;
}
int matchnull(int tab[])
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i] != 1)
        {
            return 0;
        }
    }
}
int GettIAchoice()

{
    int freecells[9];
    int freecount = 0;

    int index = (indexi - 1) * size + (indexj - 1);

    return index;
}
int MatchWin(int tab[])
{
    for (int i = 0; i < 3;i++)
    {
        int index = i * 3;
        if (tab[index] == tab[index + 1] && tab[index + 1] == tab[index + 2])
        {
            return 1;
        }
        else if (tab[i] == tab[i + 3] && tab[i +3] == tab[i+6])
        {
            return 1;
        }
    }
}
int Matchloose(int tab[])
{
    for (int i = 0; i < 3;i++)
    {
        int index = i * 3;
        if (tab[index] == tab[index + 1] && tab[index + 1] == tab[index + 2])
        {
            return 1;
        }
        else if (tab[i] == tab[i + 3] && tab[i + 3] == tab[i + 6])
        {
            return 1;
        }
    }
}
void printCell(int c)
{
    cout << "[";
    if (c == -1)
    {
        cout << " X ";
    }
    else if (c == -2)
    {
        cout << " O ";
    }
    else
    {
        cout << " - ";
    }
    cout << "]";
}

int main()
{
    srand(time(NULL));
    cout << "Bienvenue sur le Morpion" << endl;
    int o = 1;
    int i = 0;
    int tab[9];
    
    for (int i = 0; i < 9; i++)
    {
        tab[i] = i;
    }

    while (true)
    {
        for (int i = 0; i < 9; i++)
        {
            printCell(tab[i]);
            if ((i + 1) % 3 == 0)
            {
                cout << endl;
            }
        }
        if (o == 1)
        {
            
            int size = 3;
            cout << "Choisir une ligne" << endl;
            int indexi = AskNumber(1, 3);
            cout << "Choisir une colonne" << endl;
            int indexj = AskNumber(1, 3);
            int index = (indexi - 1) * size + (indexj - 1);

            system("cls");
            tab[index] = -1;
           
        }
        else
        {
           
            cout << "au tour de l ia " << endl;
            int ia = GettIAchoice();
        
            
        }

        if (matchnull(tab) == 1)
        {
            cout << "Match nul !" << endl;
            break;
        }

        else if (MatchWin(tab) == 1)
        {
            cout << "Vous avez gagne ! " << endl;
            break;
        }
        else if (Matchloose(tab) == 1)
        {
            cout << "Vous avez perdu" << endl;
            break;
        }

        o = 3 - o;
    }

    return 0;
}
