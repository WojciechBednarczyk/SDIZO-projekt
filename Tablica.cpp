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
	cout << "Dodano liczbe na koniec tablicy\n\n";
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
	cout << "Usunieto liczbe z konca tablicy\n\n";
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
	cout << "Dodano liczbe na poczatek tablicy\n\n";
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
	cout << "Usunieto liczbe z poczatku tablicy\n\n";
}

void Tablica::wstaw(int wartosc, int indeks)
{
	if (indeks > rozmiar-1 || indeks<0)
	{
		cout << "Podano nieprawidlowy indeks!\n\n";
	}
	else
	{
		rozmiar++;
		tablica_pomocnicza = new int[rozmiar];
		for (int i = 0; i < indeks; i++)
		{
			tablica_pomocnicza[i] = tablica[i];
		}
		tablica_pomocnicza[indeks] = wartosc;
		for (int i = indeks + 1; i < rozmiar; i++)
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
		cout << "Wstawiono liczbe do tablicy\n\n";
	}
	}

void Tablica::usunIndex(int indeks)
{
	if (indeks > rozmiar-1 || indeks < 0)
	{
		cout << "Nieprawidlowy indeks!\n\n";
	}
	else
	{
		tablica_pomocnicza = new int[rozmiar - 1];
		for (int i = 0; i < indeks; i++)
		{
			tablica_pomocnicza[i] = tablica[i];
		}
		for (int i = indeks + 1; i < rozmiar; i++)
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
		cout << "Usunieto liczbe o podanym indeksie\n\n";
	}
	}
