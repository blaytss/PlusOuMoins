#include <iostream>

using namespace std;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"
int CheckWin(const char word[], const char guess[])
{
	for (int i = 0; i < 6; i++)
	{
		if (guess[i] != word[i])
		{
			return 0;
		}
	}
	return 1;
}

void VerifyWord(const char word[], const char guess[])
{
	cout << "Le mot a deviner est: ";
	for (int i = 0; i < 6; i++)
	{
		if (guess[i] == word[i])
		{	
				cout << GREEN <<" " << word[i] <<" " << DEFAULT;
		}
		else 
		{
			cout << " _ ";
		}
	}
}

void Print_word_said(const char word[], const char guess[])
{
	cout << "Le mot que vous avez dit est: ";
	for (int i = 0; i < 6; i++)
		if (guess[i] == word[i])
		{
			cout << GREEN << guess[i] << DEFAULT;
		}
		else
		{
			cout << RED << guess[i] << DEFAULT;
		}
	cout << endl;
}

int main()
{
	const char word[] = "table";
	char guess[6];

	cout << "Bienvenue dans Wordle!" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << "Entrez un mot de 6 lettres: " << endl;
		cin >> guess;

		VerifyWord(word, guess);
		Print_word_said(word,guess);
		if (CheckWin(word, guess))
		{
			cout << "bravo vous avez trouvez le mot" << endl;
			cout << "le mot etait: " << word << endl;
			break;
		}
		else
		{
			cout << "Vous n'avez pas trouvé le mot, essayez encore!" << endl;
			cout << "le mot etait: " << word << endl;
			break;
		}
	}
	return 0;
}
