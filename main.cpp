#include<iostream>
#include<fstream>
#include <string>
#include"Struktury.h"

using namespace std;
void menuStart();
void(*wskaznik_menu_start)() = menuStart;
int wartosc_do_dodania;
int indeks;

void menuTablica(Tablica& tablica)
{
	int wybor_Operacji;
	cout << "Wybrana struktura: Tablica\n";
	cout << "Wybierz operacje do wykonania:\n";
	cout << endl;
	cout << "[1] Wyswietl tablice\n";
	cout << "[2] Dodaj liczbe na poczatku tablicy\n";
	cout << "[3] Dodaj liczbe na koncu tablicy\n";
	cout << "[4] Wstaw liczbe na dana pozycje w tablicy\n";
	cout << "[5] Usun liczbe na poczatku tablicy\n";
	cout << "[6] Usun liczbe na koncu tablicy\n";
	cout << "[7] Usun liczbe na danej pozycji\n";
	cout << "[9] Powrot\n";
	cout << "[0] Wyjscie\n";
	cin >> wybor_Operacji;
	switch (wybor_Operacji)
	{
	case 1:
		tablica.wyswietl();
		menuTablica(tablica);
		break;
	case 2:
		cout << "Podaj wartosc do dodania w tablicy: ";
		cin >> wartosc_do_dodania;
		tablica.dodajPoczatek(wartosc_do_dodania);
		cout << "Dodano liczbe na poczatek tablicy\n\n";
		menuTablica(tablica);
		break;
	case 3:

		cout << "Podaj wartosc do dodania w tablicy: ";
		cin >> wartosc_do_dodania;
		tablica.dodaj(wartosc_do_dodania);
		cout << "Dodano liczbe na koniec tablicy\n\n";
		menuTablica(tablica);
		break;
	case 4:
		cout << "Podaj wartosc do wstawienia w tablicy: ";
		cin >> wartosc_do_dodania;
		cout << "Podaj indeks gdzie wstawic wartosc w tablicy: ";
		cin >> indeks;
		tablica.wstaw(wartosc_do_dodania, indeks);
		cout << "Wstawiono liczbe do tablicy\n\n";
		menuTablica(tablica);
		break;
	case 5:
		tablica.usunPoczatek();
		cout << "Usunieto liczbe z poczatku tablicy\n\n";
		menuTablica(tablica);
		break;
	case 6:
		tablica.usun();
		cout << "Usunieto liczbe z konca tablicy\n\n";
		menuTablica(tablica);
		break;
	case 7:
		cout << "Podaj indeks liczby do usuniecia z tablicy: ";
		cin >> indeks;
		tablica.usunIndex(indeks);
		cout << "Usunieto liczbe o podanym indeksie\n\n";
		menuTablica(tablica);
		break;
	case 9:
		menuStart();
		break;
	case 0:
		break;
	default:
		break;
	}
}

void menuStart()
{
	int wybor_Struktury;
	cout << "Wybierz strukture:\n";

	cout << "[1] Tablica\n";
	cout << "[2] Lista dwukierunkowa\n";
	cout << "[3] Kopiec maksymalny\n";
	cout << "[4] Drzewo czerwono-czarne\n";
	cout << "[0] Wyjscie\n";
	cin >> wybor_Struktury;
	cout << endl;
	switch (wybor_Struktury)
	{
	case 0:
		break;
	case 1:
	{
		Tablica tablica;
		menuTablica(tablica);
		break;
	}
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;

	default:
	{
		cout << "Wybrano zla opcje! Wybierz ponownie\n\n";
		menuStart();

	}

	}


}

int main() {

	cout << "Struktury danych i zlozonosc obliczeniowa - projekt\n";
	cout << "Autor: Wojciech Bednarczyk\n\n";
	menuStart();
	system("pause");
	return 0;
}
