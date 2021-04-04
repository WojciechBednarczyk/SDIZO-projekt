#include "Struktury.h"
#include <fstream>

using namespace std;

//konstruktor
ListaDwukierunkowa::ListaDwukierunkowa()
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