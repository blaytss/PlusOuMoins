#include <iostream>

using namespace std;
int main() 
{

	srand(time(NULL));
	while (true) 
	{
		cout << " bienvenue dans le jeu du plus ou moins !" << endl;
		cout << "choisi un nombre :";
		int nb_mystere = rand() % 101;
		int gess;
		int nb_essaie = 0;
		int moretry;
		
		while (true)
		{
			if (nb_essaie < 10)
			{
				nb_essaie = nb_essaie + 1;
				cin >> gess;
				cout << "il te reste " << nb_essaie << " essaie" << endl;
				if (nb_mystere == gess)
				{
					cout << "gg" << endl;

					break;
				}
				if (nb_mystere < (gess+25))
				{
					cout << "c'est un peu plus" << endl;

				}
				if (nb_mystere < gess )
				
					cout << "c'est un peu moins" << endl;

				}

				if (nb_mystere < gess)
				{
					cout << "c'est moins" << endl;

				}
				else
				{
					cout << "c'est plus " << endl;

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
			break;
			}


			
		}
	}
	
	
}