#include"Struktury.h"
#include<string>
#include<sstream>
using namespace std;

int* tablica;
int* tablica_pomocnicza;
Tablica::Tablica()
{
	plik.open("dane.txt", ios::in);
	getline(plik, linia);
	stringstream napis(linia);
	napis >> rozmiar;
	int licznik = 0;
	tablica = new int[rozmiar];
	while (getline(plik, linia))
	{
		stringstream napis(linia);
		napis >> tablica[licznik];
		licznik++;
	}
	plik.close();
}
void Tablica::wyswietl()
{	
	if (rozmiar == 0)
		cout << "Tablica nie istnieje!\n";
	else
	{
		for (int i = 0; i < rozmiar; i++)
		{
			cout << "Indeks tablicy[" << i << "]	Wartosc:" << tablica[i]<<endl;
		}
	}
	
}
void Tablica::dodaj(int wartosc)
{
	tablica_pomocnicza = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica_pomocnicza[i] = tablica[i];
	}
	delete[] tablica;
	rozmiar++;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar-1; i++)
	{
		tablica[i] = tablica_pomocnicza[i];
	}
	tablica[rozmiar - 1] = wartosc;
	delete[] tablica_pomocnicza;
}
void Tablica::usun()
{
	rozmiar--;
	tablica_pomocnicza = new int[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		tablica_pomocnicza[i] = tablica[i];
	}
	delete[] tablica;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = tablica_pomocnicza[i];
	}
	delete[] tablica_pomocnicza;
}

void Tablica::dodajPoczatek(int wartosc)
{
	tablica_pomocnicza = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica_pomocnicza[i] = tablica[i];
	}
	delete[] tablica;
	rozmiar++;
	tablica = new int[rozmiar];
	tablica[0] = wartosc;
	for (int i = 1; i < rozmiar; i++)
	{
		tablica[i] = tablica_pomocnicza[i - 1];
	}
	delete[] tablica_pomocnicza;
}

void Tablica::usunPoczatek()
{
	
	tablica_pomocnicza = new int[rozmiar-1];
	rozmiar--;
	for (int i = 0; i < rozmiar; i++)
	{
		tablica_pomocnicza[i] = tablica[i+1];
	}
	delete[] tablica;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = tablica_pomocnicza[i];
	}
	delete[] tablica_pomocnicza;
}

void Tablica::wstaw(int wartosc, int index)
{
	rozmiar++;
	tablica_pomocnicza = new int[rozmiar];
	for (int i = 0; i < index; i++)
	{
		tablica_pomocnicza[i] = tablica[i];
	}
	tablica_pomocnicza[index] = wartosc;
	for (int i = index + 1; i < rozmiar; i++)
	{
		tablica_pomocnicza[i] = tablica[i - 1];
	}
	delete[] tablica;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = tablica_pomocnicza[i];
	}
	delete[] tablica_pomocnicza;
}

void Tablica::usunIndex(int index)
{
	tablica_pomocnicza = new int[rozmiar - 1];
	for (int i = 0; i < index; i++)
	{
		tablica_pomocnicza[i] = tablica[i];
	}
	for (int i = index + 1; i < rozmiar; i++)
	{
		tablica_pomocnicza[i - 1] = tablica[i];
	}
	delete[] tablica;
	rozmiar--;
	tablica = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = tablica_pomocnicza[i];
	}
	delete[] tablica_pomocnicza;
}
