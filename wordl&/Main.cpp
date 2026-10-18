
#include <iostream>

using namespace std;

#define GREEN "\033[32m"
#define YELLOW "\033[33m"

#define RED "\033[31m"
#define DEFAULT "\033[0m"

int lenght_guess(const char* guess)
{
	int llenght = 0;
	while (guess[llenght] != '\0')
		llenght++;
	return llenght;
}

int Lenght_Word(const char* chooseword)
{
	int llenght = 0;
	while (chooseword[llenght] != '\0')
		llenght++;
	return llenght;
}

bool CheckWin(const char chooseword[], const char guess[])
{
	int i = 0;
	while (true)
	{
		if (chooseword[i] != guess[i])
		{
			return false;
		}
		if (chooseword[i] == '\0')
		{
			break;
		}
		i++;
	}
	return true;

}

void VerifyWord(const char chooseword[], const char guess[])
{
	cout << "Le mot a deviner est: ";
	for (int i = 0; i < 6; i++)
	{
		if (guess[i] == chooseword[i])
		{
			cout << GREEN << " " << chooseword[i] << " " << DEFAULT;
		}
		else
		{
			cout << " _ ";
		}
	}
}

void Print_word_said(const char chooseword[], const char guess[])
{
	cout << "Le mot que vous avez dit est: ";
	for (int i = 0; i < 6; i++)
		if (guess[i] == chooseword[i])
		{
			cout << GREEN << guess[i] << DEFAULT;
		}
		else if (chooseword[0] == guess[i] || chooseword[1] == guess[i] || chooseword[2] == guess[i] || chooseword[3] == guess[i] || chooseword[4] == guess[i])
		{
			cout << YELLOW << guess[i] << DEFAULT;
		}
		else
		{
			cout << RED << guess[i] << DEFAULT;
		}

	cout << endl;
}

int main()
{


	srand(time(NULL));

	int numbernumber = rand() % 3;
	const char* word[] =
	{
		"table", "burger", "chaise"
	};
	const char* chooseword = word[numbernumber];
	int maxsize = Lenght_Word(chooseword);
	char guess[60];

	cout << "Bienvenue dans Wordle!" << endl;
	for (int i = 0; i < maxsize; i++)
	{
		cout << "Entrez un mot de " << maxsize << " lettres: " << endl;
		cin >> guess;
		int lenght = lenght_guess(guess);
		if (lenght != maxsize)
		{
			cout << "Le mot que vous avez entrez n'est pas de la bonne taille, essayez encore!" << endl;
			i--;
			continue;
		}
		

		VerifyWord(chooseword, guess);
		Print_word_said(chooseword, guess);
		cout << "il te reste : " << 5 - i << " essais" << endl;
		if ((CheckWin(chooseword, guess)) == true)
		{
			cout << "bravo vous avez trouvez le mot" << endl;
			cout << "le mot etait: " << chooseword << endl;
			return 0;
		}



	}
	if ((CheckWin(chooseword, guess)) == false)
	{
		cout << "Vous n'avez pas trouve le mot, essayez encore!" << endl;
		cout << "le mot etait: " << chooseword << endl;

	}
	return 0;
}
