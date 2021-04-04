#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class Struktura
{
	

public:
	ifstream plik;
	int rozmiar;
	string linia;
	virtual void wyswietl()=0;
	virtual void dodaj(int wartosc)=0;
	virtual void usun()=0;
		
};
class Tablica :public Struktura
{
public:
	Tablica();
	void wyswietl();
	void dodaj(int wartosc); //dodawanie na koniec
	void usun();			 //usuwanie z konca	
	void dodajPoczatek(int wartosc);
	void usunPoczatek();
	void wstaw(int wartosc, int index);
	void usunIndex(int index);
	//dopisac wyszukanie
};
class ListaDwukierunkowa :public Struktura
{	
	ListaDwukierunkowa();
	struct Element
	{
		int dane;
		Element* poprzedniElement;
		Element* nastepnyElement;
		Element();
	};

	void dodajPoczatek();
	void dodajKoniec();
	void usunPoczatek();
	void usunKoniec();
	void wstaw(int index);
	void usunIndex(int index);
};

class KopiecMaksymalny :public Struktura
{
	KopiecMaksymalny();
	struct Wezel
	{
		int wartosc;
		Wezel* lewyPotomek;
		Wezel* prawyPotomek;
		Wezel* rodzic;
		Wezel();
	};

};
class DrzewoRB :public Struktura
{
	DrzewoRB();
	struct Wezel
	{
		int wartosc;
		int kolor; //0 - kolor czerwony, 1 - kolor czarny
		Wezel* lewyPotomek;
		Wezel* prawyPotomek;
		Wezel* rodzic;
		Wezel();
	};
};