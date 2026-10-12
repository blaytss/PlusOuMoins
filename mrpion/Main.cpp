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
void IAchoice()
{
    int number;
    srand(time(NULL));

}

int MatchWin(int tab[])
{
    if (tab[1] == tab[2] && tab[2] == tab[3])
    {
        return 1;
    }
    if (tab[4] == tab[5] && tab[5] == tab[6])
    {
        return 1;
    }
    if (tab[7] == tab[8] && tab[8] == tab[9])
    {
        return 1;
    }
    if (tab[1] == tab[4] && tab[4] == tab[7])
    {
        return 1;
    }
    if (tab[2] == tab[5] && tab[5] == tab[8])
    {
        return 1;
    }
    if (tab[3] == tab[6] && tab[6] == tab[9])
    {
        return 1;
    }
} 

void printCell(int c)
{
    cout << "[";
    if (c == -1)
    {
        cout << "X";
    }
    else if (c == -2)
    {
        cout << "O";
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
            if ((i+1) % 3 == 0)
            {
                cout << endl;
            }
        }
        int size = 3;
        cout << "Choisir une ligne" << endl;
        int indexi = AskNumber(1, 3);
        cout << "Choisir une colonne" << endl;
        int indexj = AskNumber(1, 3);
        int index = (indexi-1) * size + (indexj-1);
        
        system("cls");
        tab[index] = -1;
        cout << "au tour de l ia " << endl;
        

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
        else
        {
            cout << "Vous avez perdu" << endl;
        }
    }

    return 0;
}
