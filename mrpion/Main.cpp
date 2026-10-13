#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N = 20;          
const int Size = N * N;   
int currentSize = 9;
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
    currentSize++;
    if (currentSize <= Size)
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (tab[i] >= 0)
            {
                return 0;
            }
        }
        return 1;
    }
    
}

int GettIAchoice(int tab[])
{
    int freecells[Size];
    int freecount = 0;
    for (int i = 0; i < Size; i++)
    {
        if (tab[i] >= 0)
        {
            freecells[freecount] = i;
            freecount++;
        }
    }

    int randomIndex = rand() % freecount;
    if (randomIndex >currentSize)

    return freecells[randomIndex];
}


int HasWon(int tab[], int player)
{
    //colon et ligne 
    for (int i = 0; i < N; i++)
    {
        bool row = true;
        bool col = true;
        for (int j = 0; j < N; j++)
        {
            if (tab[i * N + j] != player)
            {
                row = false;
			}   
            if (tab[j * N + i] != player) 
            {
                col = false;
            }
        }
        if (row || col)
        {
            return 1;
        }
    }
    //diag
    bool diag1 = true;
    bool diag2 = true;
    for (int j = 0; j < N; j++)
    {
        if (tab[j * N + j] != player)
        {
            diag1 = false;
        }
        if (tab[j * N + (N -1 -j)] != player)
        {
            diag2 = false;
        }
    }
    if (diag1 || diag2)
    {
        return 1;
    }

    return 0;
}

int MatchWin(int tab[])
{
    return HasWon(tab, -1);
}

int Matchloose(int tab[])
{
    return HasWon(tab, -2);
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
    cout << "Bienvenue sur le Morpion (" << N << "x" << N << ")" << endl;
    int o = 1;
    int tab[Size];

    for (int i = 0; i < Size; i++)
    {
        tab[i] = i;
    }

    while (true)
    {
        for (int i = 0; i < currentSize; i++)
        {
            printCell(tab[i]);
            if ((i + 1) % 3 == 0)
            {
                cout << endl;
            }
        }

        if (o == 1)
        {
            int index;
            while (true)
            {
                cout << "Choisir une ligne" << endl;
                int indexi = AskNumber(1, currentSize);
                cout << "Choisir une colonne" << endl;
                int indexj = AskNumber(1, currentSize);
                index = (indexi - 1) * currentSize + (indexj - 1);

                if (tab[index] >= 0)
                    break;
                cout << "Case deja prise !" << endl;
            }

            system("cls");
            tab[index] = -1;
        }
        else
        {
            cout << "au tour de l ia " << endl;
            int ia = GettIAchoice(tab);
            tab[ia] = -2;
        }

        if (MatchWin(tab) == 1 || Matchloose(tab) == 1 || matchnull(tab) == 1)
        {
            for (int i = 0; i < Size; i++)
            {
                printCell(tab[i]);
                if ((i + 1) % N == 0)
                {
                    cout << endl;
                }
            }

            if (MatchWin(tab) == 1)
                cout << "Vous avez gagne ! " << endl;
            else if (Matchloose(tab) == 1)
                cout << "Vous avez perdu" << endl;
            else
                cout << "Match nul !" << endl;
            break;
        }

        o = 3 - o;
    }

    return 0;
}