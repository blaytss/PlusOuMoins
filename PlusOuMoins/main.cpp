#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	while (true)
	{
		cout << " bienvenue dans le jeu du plus ou moins !" << endl;
		cout << "ince de proximiter oui :1 ou non :autre";
		int choice;
		cin >> choice;
		cout << " quel niveau tu veux ? 1 2 ou autre  ";
		int niv;
		cin >> niv;
		cout << "choisi un nombre :";
		int nb_mystere = 0;
		if (niv == 1)
		{
			nb_mystere = rand() % 21;
		}
		else if (niv == 2)
		{
			nb_mystere = rand() % 101;
		}
		else
		{
			nb_mystere = rand() % 501;
		}
		int gess;
		int nb_essaie = 0;
		int moretry;

		while (true)
		{
			if (nb_essaie < 10)
			{
				nb_essaie = nb_essaie + 1;
				cin >> gess;
				cout << "il te reste " << 10 - nb_essaie << " essaie" << endl;
				if (nb_mystere == gess)
				{
					cout << "gg" << endl;
					cout << " veux tu rejouer : (1:oui , 2:non)";
					cin >> moretry;
					if (moretry == 1)
					{
						cout << "alors go ";
					}
					else
					{
						cout << "a plus pour une prochaine partie !";
					}
					break;
				}

				if (gess < nb_mystere)
				{
					if (choice == 1)
					{



						if (nb_mystere - gess >= 50)
						{
							cout << "c'est beaucoup plus" << endl;

						}


						else if (nb_mystere - gess <= 10)
						{
							cout << "c'est un peu plus" << endl;

						}


						else
						{
							cout << "c'est plus" << endl;

						}
					}
					else
					{
						cout << "c'est plus ";
					}
				}
				else
				{
					if (choice == 1)
					{
						if (gess - nb_mystere >= 50)
						{
							cout << "c'est beaucoup moins" << endl;
						}


						else if (gess - nb_mystere <= 10)
						{
							cout << "c'est un peu moins" << endl;
						}


						else
						{
							cout << "c'est moins" << endl;
						}
					}
					else
					{
						cout << " c'est moins ";
					}
				}

			}

			else
			{
				cout << " veux tu rejouer : (1:oui , 2:non)";
				cin >> moretry;
				if (moretry == 1)
				{
					cout << "alors go ";
				}
				else
				{
					cout << "a plus pour une prochaine partie !";
					break;

				}
			}
		}
		break;
	}
}


