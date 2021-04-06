#include "Struktury.h"
#include <fstream>
#include<sstream>

using namespace std;

struct Element
{
	int dane;
	Element* poprzedniElement, * nastepnyElement;
	Element();
};
Element::Element()
{

}
Element* glowa, * ogon;
Element* element;
Element* nowyElement;
int licznik;
//konstruktor
ListaDwukierunkowa::ListaDwukierunkowa()
{
	plik.open("dane.txt", ios::in);
	getline(plik, linia);
	stringstream napis(linia);
	napis >> rozmiar;
	glowa = nullptr;
	ogon = nullptr;
	while (getline(plik, linia))
	{
		stringstream napis(linia);
		nowyElement = new Element;
		if (glowa == nullptr)
		{
			glowa = nowyElement;
			ogon = nowyElement;
			nowyElement->nastepnyElement = nullptr;
			nowyElement->poprzedniElement = nullptr;
			napis >> nowyElement->dane;
		}
		else
		{
			ogon->nastepnyElement = nowyElement;
			nowyElement->poprzedniElement = ogon;
			ogon = nowyElement;
			nowyElement->nastepnyElement = nullptr;
			napis >> nowyElement->dane;
		}
	}
	plik.close();
}
	

void ListaDwukierunkowa::dodaj(int wartosc)
{
	nowyElement = new Element;
	nowyElement->poprzedniElement = ogon;
	nowyElement->nastepnyElement = nullptr;
	nowyElement->dane = wartosc;
	ogon->nastepnyElement = nowyElement;
	ogon = nowyElement;
}

void ListaDwukierunkowa::usunPoczatek()
{
	element = glowa;
	glowa->nastepnyElement->poprzedniElement = nullptr;
	glowa = glowa->nastepnyElement;
	delete element;
}

void ListaDwukierunkowa::usun()
{
	element = ogon;
	ogon->poprzedniElement->nastepnyElement = nullptr;
	ogon = ogon->poprzedniElement;
	delete element;
}

void ListaDwukierunkowa::wstaw(int wartosc,int indeks)
{
	//dopisac przypadek kiedy indeks = 0;
	nowyElement = new Element;
	nowyElement->dane = wartosc;
	element = glowa;
	for (int i = 0; i < indeks; i++)
	{
		element = element->nastepnyElement;
	}
	nowyElement->poprzedniElement = element->poprzedniElement;
	nowyElement->nastepnyElement = element;
	element->poprzedniElement->nastepnyElement = nowyElement;
	element->poprzedniElement = nowyElement;
}

void ListaDwukierunkowa::usunIndex(int indeks)
{
	element = glowa;
	for (int i = 0; i < indeks; i++)
	{
		element = element->nastepnyElement;
	}
	element->poprzedniElement->nastepnyElement = element->nastepnyElement;
	element->nastepnyElement->poprzedniElement = element->poprzedniElement;
	delete element;
}

void ListaDwukierunkowa::dodajPoczatek(int wartosc)
{
	nowyElement = new Element;
	nowyElement->dane = wartosc;
	nowyElement->poprzedniElement = nullptr;
	nowyElement->nastepnyElement = glowa;
	glowa->poprzedniElement = nowyElement;
	glowa = nowyElement;
}

void ListaDwukierunkowa::wyswietl()
{
	cout << endl;
	element = glowa;
	while (element->nastepnyElement != nullptr)
	{
		cout << element->dane << endl;
		element = element->nastepnyElement;
	}
	cout << element->dane << endl<<endl;
}