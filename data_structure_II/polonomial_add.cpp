// Include header file
#include <iostream>
using namespace std;
/*
    C++ program
    Add of two polynomials using array
*/
class Addition
{
	public:
		// Display polynomial sequence
		void printPolynomial(int polynomial[], int n)
		{
			for (int i = 0; i < n; ++i)
			{
				if (i != 0)
				{
					cout << " + " << polynomial[i] << "x^" << i;
				}
				else
				{
					cout << polynomial[i];
				}
			}
			cout << "\n";
		}
	int maxLength(int a, int b)
	{
		if (a > b)
		{
			return a;
		}
		return b;
	}
	void addPolynomials(int x[], int y[], int a, int b)
	{
		// Display polynomial
		this->printPolynomial(x, a);
		this->printPolynomial(y, b);
		// Get max length
		int n = this->maxLength(a, b);
		// Use to collect result element
		int z[n];
		for (int i = 0; i < n; ++i)
		{
			if (i < a && i < b)
			{
				// Case ➀ : When have both polynomials element exists
				z[i] = x[i] + y[i];
			}
			else if (i < a)
			{
				// Case ➁ : When have x polynomial element exists
				z[i] = x[i];
			}
			else
			{
				// Case ➂ : When have y polynomial element exists
				z[i] = y[i];
			}
		}
		// Display calculated result
		this->printPolynomial(z, n);
	}
};
int main()
{
	Addition *task = new Addition();
	// Given polynomials
	int x[] = {7 , 8 , 0,0,0,6 , 1 , 3};
	int y[] = {5 , 1 , 0,3 , 2};
	// Get the size
	int a = sizeof(x) / sizeof(x[0]);
	int b = sizeof(y) / sizeof(y[0]);
	// Test
	task->addPolynomials(x, y, a, b);
	return 0;
}