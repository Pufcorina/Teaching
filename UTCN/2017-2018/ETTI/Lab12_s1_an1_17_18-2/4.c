#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> // pt. getch()
#include <stdlib.h> // pt. exit(int)
#include <string.h>

struct data_nasterii {
	int ziua;
	char luna[11];
	int anul;
};

char *tab[] = { "ian", "feb", "mar", "apr", "mai", "iun", "iul",
				"aug", "sep", "oct", "noi", "dec" };

struct angajat {
	char nume[16];
	char prenume[20];
	char ocupatia[30];
	struct data_nasterii dataNasterii;
	char sectie[100];
};

void puts_getch_exit(char *);
struct data_nasterii citireData();

struct angajat citireAngajat();
void printMeniu();
void afisareIngineri(struct angajat lista_angajati[3000], int lungime);

void main()
{
	struct angajat lista_angajati[3000];
	int length = 5;
	struct angajat s;

	struct data_nasterii d;
	d.anul = 1997;
	strcpy(d.luna, "ian");
	d.ziua = 13;

	//1
	strcpy(s.nume, "Buhai");
	strcpy(s.prenume, "Alex");
	strcpy(s.ocupatia, "inginer");
	s.dataNasterii = d;
	strcpy(s.sectie, "1234");

	lista_angajati[0] = s;

	//2
	strcpy(s.nume, "Iova");
	strcpy(s.prenume, "Rares");
	strcpy(s.ocupatia, "inginer");
	s.dataNasterii = d;
	strcpy(s.sectie, "1234");

	lista_angajati[1] = s;

	//3
	strcpy(s.nume, "Cifor");
	strcpy(s.prenume, "Andreea");
	strcpy(s.ocupatia, "inginer");
	s.dataNasterii = d;
	strcpy(s.sectie, "1234");

	lista_angajati[2] = s;

	//4
	strcpy(s.nume, "Bilc");
	strcpy(s.prenume, "Irina");
	strcpy(s.ocupatia, "ingin6er");
	s.dataNasterii = d;
	strcpy(s.sectie, "1234");

	lista_angajati[3] = s;

	//5
	strcpy(s.nume, "Todoran");
	strcpy(s.prenume, "Corina");
	strcpy(s.ocupatia, "inginer3");
	s.dataNasterii = d;
	strcpy(s.sectie, "1234");

	lista_angajati[4] = s;

	int command;

	while (1)
	{
		printMeniu();
		scanf("%d", &command);

		switch (command)
		{
		case 1:
			lista_angajati[length] = citireAngajat();
			length++;
			break;
		case 2:
			afisareIngineri(lista_angajati, length);
			break;
		default:
			printf("Comanda invalida\n");
			break;
		}
	}

	_getch();
}

void printMeniu()
{
	printf("1. Adaugare angajat nou\n");
	printf("2. Afisare ingineri\n");
	printf("Intorduceti numarul comenzii\n");
}

struct angajat citireAngajat()
{
	struct angajat s;

	puts("\nIntroduceti numele angajatului: ");
	scanf("%s", s.nume);

	if (_stricmp(s.nume, "AAA") == 0)
		exit(0);

	puts("\nIntroduceti prenumele angajatului: ");
	scanf("%s", s.prenume);

	puts("\nIntroduceti ocupatia angajatului: ");
	scanf("%s", s.ocupatia);

	puts("\nIntroduceti sectia angajatului: ");
	scanf("%s", s.sectie);

	puts("\nIntroduceti anul nasterii al angajatului: ");
	s.dataNasterii = citireData();

	return s;
}

struct data_nasterii citireData()
{
	struct data_nasterii dc;
	int i, luna = 0; // acest luna e alt spatiu de nume decat dc.luna

	puts("\nIntroduceti data curenta: ");

	printf("\n\t ziua (1,2,...31): ");
	scanf("%d", &dc.ziua);
	if ((dc.ziua <= 0) || (dc.ziua > 31))
		puts_getch_exit("\nZiua incorecta !");

	printf("\n\t luna (ian, feb...): ");
	scanf("%s", dc.luna);
	for (i = 0; i <12; i++) {
		if (_stricmp(dc.luna, tab[i]) == 0) {
			luna = i + 1;
			break;
		}
	}
	if (luna == 0) 
		puts_getch_exit("\nLuna incorecta !");

	printf("\n\t anul : ");
	scanf("%d", &dc.anul);
	if (dc.anul <= 0)
		puts_getch_exit("\nAnul incorect (negativ)!");

	return dc;
}

void afisareIngineri(struct angajat lista_angajati[3000], int lungime)
{
	for (int i = 0; i < lungime; i++)
		if (_strcmpi(lista_angajati[i].ocupatia, "inginer") == 0)
			printf("NUME: %s, PRENUME: %s, OCUPATIA: %s, DATA: %d %s %d, SECTIA: %s\n", 
				lista_angajati[i].nume, lista_angajati[i].prenume, lista_angajati[i].ocupatia,
				lista_angajati[i].dataNasterii.ziua, lista_angajati[i].dataNasterii.luna, lista_angajati[i].dataNasterii.anul,
				lista_angajati[i].sectie);
}

void puts_getch_exit(char *ptr) {
	puts(ptr);// printf(ptr); -- de asemenea e OK
	_getch();
	exit(0);
}