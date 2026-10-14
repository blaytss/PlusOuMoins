#include <iostream>
using namespace std;

void division(int dividende, int diviseur, int* adresquotient, int* adresreste)
{
	*adresquotient = dividende / diviseur;
	*adresreste = dividende % diviseur;


}
void ConvertSeconds(int totalesec, int* heures, int* minutes, int* secondes)
{
	*minutes = totalesec % 60;
	*heures = *minutes / 60;
	*secondes = totalesec % 60;

}

int main()
{
	//division
	cout << "dividende ?" << endl;
	int dividende = 0;
	cin >> dividende;
	cout << "diviseur ?" << endl;
	int diviseur = 0;
	cin >> diviseur;

	int resultatquotient;
	int resultatreste;
	division(dividende, diviseur, &resultatquotient, &resultatreste);

	cout << "Quotient " << resultatquotient << endl;
	cout << "Reste " << resultatreste << endl;

	//convert seconde
	cout << " Totale seconde ? " << endl;
	int totalesecondes = 0;
	cin >> totalesecondes;

	int resultheures;
	int resultminutes;
	int resultsec;
	ConvertSeconds(totalesecondes, &resultheures, &resultminutes, &resultsec);
	
	cout << "tu as passe :" << resultheures << "H" << resultminutes << "minutes" ;
	cout << resultsec << "sec";





	//le max avec un int (32bits)
	int x = 1;
	x++;
	char i = 'a'; 
	cout <<"adresse de x :" << &x << endl;
	cout << "adresse de i :" << &i << endl;



	//pointeurs
	int* pi = &x;
	cout << "l'adresse de x :" << pi << endl;
	*pi = 5;
	cout << "l'adresse de x :" << x << endl;
	//recupere
	int j = *pi;


	cout << j << endl;



	
	return 0;
}