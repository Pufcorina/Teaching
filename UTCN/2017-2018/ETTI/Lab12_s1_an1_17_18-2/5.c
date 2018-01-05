#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> // pt. getch()
#include <stdlib.h> // pt. exit(int)
#include <string.h>

struct data_calendar {
	int ziua;
	char luna[11];
	int anul;
};

char *tab[] = { "ian", "feb", "mar", "apr", "mai", "iun", "iul",
				"aug", "sep", "oct", "noi", "dec" };

struct angajat {
	char nume[16];
	char prenume[20];
	struct data_calendar dataNasterii;
	char cnp[20];
	struct data_calendar dataAngajarii;
};

void puts_getch_exit(char *);
struct data_calendar citireData();

struct angajat citireAngajat();
int comparaDate(struct data_calendar d1, struct data_calendar d2);
void sortareAngajati(struct angajat* lista_angajati, int lungime);
void afisareAngajati(struct angajat lista_angajati[3000], int lungime);

void main()
{
	struct angajat lista_angajati[3000];
	int length = 0;

	int n;

	printf("Introdu numarul de angajati: \n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		lista_angajati[length] = citireAngajat();
		length++;
	}

	sortareAngajati(lista_angajati, length);
	afisareAngajati(lista_angajati, length);

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

	puts("\nIntroduceti prenumele angajatului: ");
	scanf("%s", s.prenume);

	puts("\nIntroduceti anul nasterii al angajatului: ");
	s.dataNasterii = citireData();

	puts("\nIntroduceti cnp angajatului: ");
	scanf("%s", s.cnp);

	puts("\nIntroduceti anul angajarii al angajatului: ");
	s.dataAngajarii = citireData();

	return s;
}

struct data_calendar citireData()
{
	struct data_calendar dc;
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

void afisareAngajati(struct angajat lista_angajati[3000], int lungime)
{
	for (int i = 0; i < lungime; i++)
			printf("NUME: %s, PRENUME: %s, DATA NASTERII: %d %s %d, CNP: %s, DATA ANGAJARII: %d %s %d\n", 
				lista_angajati[i].nume, lista_angajati[i].prenume,
				lista_angajati[i].dataNasterii.ziua, lista_angajati[i].dataNasterii.luna, lista_angajati[i].dataNasterii.anul,
				lista_angajati[i].cnp,
				lista_angajati[i].dataAngajarii.ziua, lista_angajati[i].dataAngajarii.luna, lista_angajati[i].dataAngajarii.anul);
}

void puts_getch_exit(char *ptr) {
	puts(ptr);// printf(ptr); -- de asemenea e OK
	_getch();
	exit(0);
}
void sortareAngajati(struct angajat* lista_angajati, int lungime)
{
	struct angajat aux;
	for(int i = 0; i < lungime; i++)
		for(int j = i + 1; j < lungime; j++)
			if (comparaDate(lista_angajati[i].dataAngajarii, lista_angajati[j].dataAngajarii) == 1)
			{
				aux = lista_angajati[i];
				lista_angajati[i] = lista_angajati[j];
				lista_angajati[j] = aux;
			}

}

int month(char m[20])
{
	for (int i = 0; i < 12; i++)
		if (_strcmpi(tab[i], m) == 0)
			return i;
	return -1;
}

int comparaDate(struct data_calendar d1, struct data_calendar d2)
{
	if (d1.anul > d2.anul)
		return 1;
	if (d1.anul < d2.anul)
		return 0;

	int m1 = month(d1.luna);
	int m2 = month(d2.luna);

	if (m1 > m2)
		return 1;
	if (m1 < m2)
		return 0;

	if (d1.ziua > d2.ziua)
		return 1;
	return 0;
}