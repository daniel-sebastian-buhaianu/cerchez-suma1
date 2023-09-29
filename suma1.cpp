#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct
{ 
	int nr, st;
} Solutie;

int main()
{
	int n;

	cout << "n = "; cin >> n;

	if (n <= 0)
	{
		cout << "Eroare valoare n\n";
		return 1;
	}
	
	int s[n+1], i;

	s[0] = 0;

	for (i = 1; i <= n; i++)
	{
		s[i] = s[i-1] + i;
	}

	int k = 0;

	Solutie *sol = (Solutie*)malloc((k+1)*sizeof(Solutie));

	if (!sol)
	{
		cout << "Eroare alocare memorie *sol\n";
		return 2;
	}

	sol[k].nr = 2*n;
	sol[k++].st = (n-1)*(-1);

	int j;

	for (i = 0; i <= n-2; i++)
	{
		for (j = i+2; j <= n && s[j]-s[i] <= n; j++)
		{
			if (s[j]-s[i] == n)
			{
				sol = (Solutie*)realloc(sol, (k+1)*sizeof(Solutie));

				if (!sol)
				{
					cout << "Eroare realocare memorie *sol\n";
					return 3;
				}
				
				sol[k].nr = j-i;
				sol[k++].st = i+1;

				if (i == 0)
				{
					sol = (Solutie*)realloc(sol, (k+1)*sizeof(Solutie));

					if (!sol)
					{
						cout << "Eroare realocare memorie *sol\n";
						return 3;
					}
					
					sol[k].nr = j;
					sol[k++].st = 0;
				}
			}
		}	
	}

	ofstream fout("sume.out");

	fout << k << "\n";

	for (i = 0; i < k; i++)
	{
		fout << sol[i].nr << " " << sol[i].st << "\n";
	}

	fout.close();

	free(sol);

	return 0;
}
