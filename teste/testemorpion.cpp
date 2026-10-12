#include <iostream>;
using namespace std;
int main()
{
	int i = 1;
	int tab[10];
	while (i < 10)
	{
		tab[i] = i;
		cout <<"["<< tab[i]<<"]";
		i++;
		if (i % 3 -1== 0)
		{
			cout << endl;
		}
	}
	return 0;
}