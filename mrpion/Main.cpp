#include <iostream>

using namespace std;

int AskNumber(int min, int max)
{
    int number;
    cin >> number;

    while (number < min || number > max)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Mauvais type veuillez rentrer un nombre entier entre " << min << " et " << max << " : ";
        cin >> number;
    }

    return number;
}
void PrintTab()
{
    

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
    
    while (true)
    {

        for (int i = 1; i < 10; i++)
        {
            tab[i] = i;
            cout << "[" << tab[i] << "]";
            if (i % 3 == 0)
            {
                cout << endl;
            }
        }

        cout << "Choisir une case" << endl;
        int index = AskNumber(1, 9);
        system("cls");
        tab[index - 1] = -1;
    }

    return 0;
}
