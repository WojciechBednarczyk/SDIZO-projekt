#include "Struktury.h"
#include<fstream>
#include<sstream>
using namespace std;

int* tablicaKopiec;
int* tablicaKopiecPomocnicza;
bool naprawione;
void zamiana(int* tablicaKopiec, int indeks1, int indeks2)
{
	int temp;
	temp = tablicaKopiec[indeks1];
	tablicaKopiec[indeks1] = tablicaKopiec[indeks2];
	tablicaKopiec[indeks2] = temp;
}

void naprawa_kopca(int* tablicaKopiec, int dlugosc_tablicy)
{
	int ostatni_rodzic = (dlugosc_tablicy / 2) - 1;
	int wiekszy_potomek;
	int indeks_wiekszego_syna;
	int licznik_zmian = 0;
	for (int i = ostatni_rodzic; i >= 0; i--)
	{
		//nie wyjdziemy poza zakres bo ostatni rodzic zawsze bedzie mial lewego syna
		wiekszy_potomek = tablicaKopiec[i * 2 + 1];
		indeks_wiekszego_syna = i * 2 + 1;
		//sprawdzanie czy nie wychodzimy poza zakres tablicy
		if (i * 2 + 2 < dlugosc_tablicy)
		{
			if (tablicaKopiec[i * 2 + 2] > wiekszy_potomek)
			{
				wiekszy_potomek = tablicaKopiec[i * 2 + 2];
				indeks_wiekszego_syna = i * 2 + 2;
			}

		}
		if (wiekszy_potomek > tablicaKopiec[i])
		{
			zamiana(tablicaKopiec, i, indeks_wiekszego_syna);
			licznik_zmian++;
		}
	}
	if (licznik_zmian != 0)
		naprawa_kopca(tablicaKopiec, dlugosc_tablicy);
}

KopiecMaksymalny::KopiecMaksymalny()
{
	plik.open("dane.txt", ios::in);
	getline(plik, linia);
	stringstream napis(linia);
	napis >> rozmiar;
	tablicaKopiec = new int[rozmiar];
	int indeks = 0;
	while (getline(plik, linia))
	{
		stringstream napis(linia);
		napis >> tablicaKopiec[indeks];
		indeks++;
	}
	plik.close();
	naprawa_kopca(tablicaKopiec, rozmiar);
}



void KopiecMaksymalny::wyswietl()
{
	int ilosc_poziomow = 0;

	if (rozmiar == 0)
		cout << "Kopiec nie istnieje!\n";
	else
	{
		int pierwszy_indeks = 0;
		int rozmiar_temp = rozmiar;
		int ilosc_elementow = 0;
		int ilosc_synow = 0;
		while (true)
		{

			ilosc_poziomow++;
			rozmiar_temp /= 2;
			if (rozmiar_temp <= 1)
			{
				break;
			}

		}
		if (rozmiar!=1)
		{
			ilosc_poziomow++;
		}
		
		cout << "Poziom kopca[0]	Wartosci:" << tablicaKopiec[0] << endl;
		ilosc_elementow++;
		for (int i = 1; i < ilosc_poziomow; i++)
		{
			ilosc_synow = 0;
			pierwszy_indeks = pierwszy_indeks * 2 + 1;
			cout << "Poziom kopca[" << i << "]	Wartosci:";
			for (int j = pierwszy_indeks; j < (pierwszy_indeks * 2) + 1; j++)
			{
				cout << tablicaKopiec[j] << " ";
				ilosc_elementow++;
				ilosc_synow++;
				if (ilosc_synow == 2)
				{
					cout << "| ";
					ilosc_synow = 0;
				}
				if (ilosc_elementow == rozmiar)
				{
					break;
				}
			}
			cout << endl;
		}
	}
}

void KopiecMaksymalny::dodaj(int wartosc)
{
	rozmiar++;
	tablicaKopiecPomocnicza = new int[rozmiar];
	for (int i = 0; i < rozmiar - 1; i++)
	{
		tablicaKopiecPomocnicza[i] = tablicaKopiec[i];
	}
	tablicaKopiecPomocnicza[rozmiar - 1] = wartosc;
	delete[] tablicaKopiec;
	tablicaKopiec = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablicaKopiec[i] = tablicaKopiecPomocnicza[i];
	}
	delete[] tablicaKopiecPomocnicza;
	naprawa_kopca(tablicaKopiec, rozmiar);
	cout << "Dodano liczbe\n\n";
}

void KopiecMaksymalny::usun()
{
	if (rozmiar <= 0)
		cout << "Kopiec nie istnieje!\n";
	else
	{
		//nie mozemy wstawic 0 poniewaz typem danych jest liczba calkowita ze znakiem dlatego wstawiamy ostatni lisc 
		tablicaKopiec[0] = tablicaKopiec[rozmiar - 1];
		rozmiar--;
		tablicaKopiecPomocnicza = new int[rozmiar];
		for (int i = 0; i < rozmiar; i++)
		{
			tablicaKopiecPomocnicza[i] = tablicaKopiec[i];
		}
		delete[] tablicaKopiec;
		tablicaKopiec = new int[rozmiar];
		for (int i = 0; i < rozmiar; i++)
		{
			tablicaKopiec[i] = tablicaKopiecPomocnicza[i];
		}
		naprawa_kopca(tablicaKopiec, rozmiar);
		cout << "Usunieto korzen\n\n";
	}

}
