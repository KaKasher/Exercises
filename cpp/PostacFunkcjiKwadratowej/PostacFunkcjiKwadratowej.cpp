#define NOMINMAX

#include <iostream>
#include <limits>
#include <ios>
#include <Windows.h>
#include "qfunc.h"

void displayResults(qfunc &func);
void displaySelection();
char inputSelection();
void postacOgolna();
void postacKanoniczna();
void postacIloczynowa();

int main()
{
	do {
		displaySelection();
	} while (inputSelection() != '4');
	
	return 0;
}

void displaySelection()
{
	system("cls");
	std::cout << "Jaki wzor funkcji kwadratowej posiadasz:\n";
	std::cout << "1. Postac ogolna: f(x) = ax^2 + bx + c\n";
	std::cout << "2. Postac kanoniczna: f(x) = a(x - p)^2 + q\n";
	std::cout << "3. Postac iloczynowa: f(x) = a(x - x1)(x - x2)\n";
	std::cout << "4. Wyjdz\n\n";
	std::cout << "Wybor: ";
}

char inputSelection()
{
	char menuSelection{ ' ' };


		std::cin >> menuSelection;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (menuSelection)
		{
		case '1':
			postacOgolna();
			break;
		case '2':
			postacKanoniczna();
			break;
		case'3':
			postacIloczynowa();
			break;
		case'4':
			return '4';
		default:
			std::cout << "Zly wybor! Prosze wybrac jeszcze raz.\n";
			system("pause");
		}
		return ' ';
}

void postacOgolna()
{
	system("cls");
	std::cout << "Postac ogolna f(x) = ax^2 + bx + c\n";
	std::cout << "Wprowadz a, b, c oddzielone spacja: " << std::flush;

	double a, b, c;
	std::cin >> a >> b >> c;

	qfunc func;
	func.setExpandedForm(a, b, c);

	func.expandedToVertex();
	func.expandedToFactored();

	displayResults(func);
}

void postacKanoniczna()
{
	system("cls");
	std::cout << "Postac kanoniczna f(x) = a(x - p)^2 + q\n";
	std::cout << "Wprowadz a, p, q oddzielone spacja: " << std::flush;

	double a, p, q;
	std::cin >> a >> p >> q;

	qfunc func;
	func.setVertexForm(a, p, q);

	func.vertexToExpanded();
	func.vertexToFactored();

	displayResults(func);
}

void postacIloczynowa()
{
	system("cls");
	std::cout << "Postac iloczynowa f(x) = a(x - x1)(x - x2)\n";
	std::cout << "Wprowadz a, x1, x2 oddzielone spacja: " << std::flush;

	double a, x1, x2;
	std::cin >> a >> x1 >> x2;

	qfunc func;
	func.setFactoredForm(a, x1, x2);

	func.factoredToExpanded();
	func.factoredToVertex();

	displayResults(func);
}

void displayResults(qfunc &func)
{
	system("cls");
	std::cout << "Postac ogolna: " << func.getExpandedForm() << std::endl;
	std::cout << "Postac kanoniczna: " << func.getVertexForm() << std::endl;
	std::cout << "Postac iloczynowa: " << func.getFactoredForm() << std::endl;
	system("pause");
}