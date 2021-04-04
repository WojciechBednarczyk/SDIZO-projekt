#include "Struktury.h"

using namespace std;

DrzewoRB::DrzewoRB()
{
	plik.open("dane.txt", ios::in);
	if (plik.good() == true)
	{
		plik >> rozmiar;
		while (getline(plik, linia))
		{
			cout << linia << endl;
		}
		plik.close();
	}
}