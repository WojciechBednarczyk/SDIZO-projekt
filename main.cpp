#include<iostream>
#include<fstream>
#include <string>
#include"Struktury.h"

using namespace std;
void menuStart();
void(*wskaznik_menu_start)() = menuStart;
int wartosc_do_dodania;
int indeks;
int wybor_Operacji;
void menuKopiec(KopiecMaksymalny& kopiecMaksymalny)
{
	cout << "Wybrana struktura: Kopiec maksymalny\n";
	cout << "Wybierz operacje do wykonania:\n\n";
	cout << "[1] Wyswietl kopiec \n";
	cout << "[2] Dodaj liczbe\n";
	cout << "[3] Usun korzen\n";
	cout << "[9] Powrot\n";
	cout << "[0] Wyjscie\n";
	cin >> wybor_Operacji;
	switch (wybor_Operacji)
	{
	case 1:
		kopiecMaksymalny.wyswietl();
		menuKopiec(kopiecMaksymalny);
		break;
	case 2:
		cout << "Podaj liczbe do dodania:";
		cin >> wartosc_do_dodania;
		kopiecMaksymalny.dodaj(wartosc_do_dodania);
		menuKopiec(kopiecMaksymalny);
		break;
	case 3:
		kopiecMaksymalny.usun();
		menuKopiec(kopiecMaksymalny);
		break;
	case 9:
		menuStart();
		break;
	case 0:
		break;
	default:
		cout << "Wybrano zla opcje! Wybierz ponownie \n\n";
		menuKopiec(kopiecMaksymalny);
		break;
	}
}
void menuLista(ListaDwukierunkowa& lista)
{
	cout << "Wybrana struktura: Lista dwukierunkowa\n";
	cout << "Wybierz operacje do wykonania:\n\n";
	cout << "[1] Wyswietl liste \n";
	cout << "[2] Dodaj liczbe na poczatku listy\n";
	cout << "[3] Dodaj liczbe na koncu listy\n";
	cout << "[4] Wstaw liczbe na dana pozycje w liscie\n";
	cout << "[5] Usun liczbe na poczatku listy\n";
	cout << "[6] Usun liczbe na koncu listy\n";
	cout << "[7] Usun liczbe na danej pozycji\n";
	cout << "[9] Powrot\n";
	cout << "[0] Wyjscie\n";
	cin >> wybor_Operacji;
	switch (wybor_Operacji)
	{
	case 1:
		lista.wyswietl();
		menuLista(lista);
		break;
	case 2:
		cout << "Podaj wartosc do dodania: ";
		cin >> wartosc_do_dodania;
		lista.dodajPoczatek(wartosc_do_dodania);
		menuLista(lista);
		break;
	case 3:
		cout << "Podaj wartosc do dodania: ";
		cin >> wartosc_do_dodania;
		lista.dodaj(wartosc_do_dodania);
		menuLista(lista);
		break;
	case 4:
		cout << "Podaj wartosc do wstawienia: ";
		cin >> wartosc_do_dodania;
		cout << "Podaj indeks gdzie wstawic wartosc: ";
		cin >> indeks;
		lista.wstaw(wartosc_do_dodania, indeks);
		menuLista(lista);
		break;
	case 5:
		lista.usunPoczatek();
		menuLista(lista);
		break;
	case 6:
		lista.usun();
		menuLista(lista);
		break;
	case 7:
		cout << "Podaj indeks gdzie usunac wartosc: ";
		cin >> indeks;
		lista.usunIndex(indeks);
		menuLista(lista);
		break;
	case 9:
		menuStart();
		break;
	case 0:
		break;
	default:
		cout << "Wybrano zla opcje! Wybierz ponownie \n\n";
		menuLista(lista);
		break;
	}
}

void menuTablica(Tablica& tablica)
{
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
		menuTablica(tablica);
		break;
	case 3:

		cout << "Podaj wartosc do dodania w tablicy: ";
		cin >> wartosc_do_dodania;
		tablica.dodaj(wartosc_do_dodania);
		menuTablica(tablica);
		break;
	case 4:
		cout << "Podaj wartosc do wstawienia w tablicy: ";
		cin >> wartosc_do_dodania;
		cout << "Podaj indeks gdzie wstawic wartosc w tablicy: ";
		cin >> indeks;
		tablica.wstaw(wartosc_do_dodania, indeks);
		menuTablica(tablica);
		break;
	case 5:
		tablica.usunPoczatek();
		menuTablica(tablica);
		break;
	case 6:
		tablica.usun();
		menuTablica(tablica);
		break;
	case 7:
		cout << "Podaj indeks liczby do usuniecia z tablicy: ";
		cin >> indeks;
		tablica.usunIndex(indeks);
		menuTablica(tablica);
		break;
	case 9:
		menuStart();
		break;
	case 0:
		break;
	default:
		cout << "Wybrano zla opcje! Wybierz ponownie\n\n";
		menuTablica(tablica);
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
	{
		ListaDwukierunkowa lista;
		menuLista(lista);
		break;
	}
	case 3:
	{
		KopiecMaksymalny kopiecMaksymalny;
		menuKopiec(kopiecMaksymalny);
		break;
	}
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
