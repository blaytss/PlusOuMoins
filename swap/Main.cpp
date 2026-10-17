#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
	int box = *x;

	*x = *y;
	*y = box;



}
int main()
{
	int x = 0;
	cout << "quelle valeurs voulez vous pour x ?";
	cin >> x;
	
	int y = 0;
	cout << "quelle valeurs voulez vous pour y ?";
	cin >> y;

	swap(&x, &y);

	cout << " x = " << x;
	cout << "y = " << y;

}