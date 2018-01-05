#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> // pt. getch()
#include <stdlib.h> // pt. exit(int)
#include <string.h>

struct student {
	char nume[16];
	char prenume[20];
	char tara[30];
	int grupa;
	int an;
};

struct student citireStudent();
void printMeniu();
void afisareStudenti(struct student lista_studenti[3000], int lungime);
int maxStudenti(struct student lista_studenti[3000], int lungime);
int studentiStrini(struct student lista_studenti[3000], int lungime, int grupa);

void main()
{
	struct student lista_studenti[3000];
	int length = 5;
	struct student s;
	//1
	strcpy(s.nume, "Buhai");
	strcpy(s.prenume, "Alex");
	strcpy(s.tara, "Romania");
	s.an = 1997;
	s.grupa = 922;

	lista_studenti[0] = s;

	//2
	strcpy(s.nume, "Iova");
	strcpy(s.prenume, "Rares");
	strcpy(s.tara, "Romania");
	s.an = 1997;
	s.grupa = 224;

	lista_studenti[1] = s;

	//3
	strcpy(s.nume, "Cifor");
	strcpy(s.prenume, "Andreea");
	strcpy(s.tara, "Franta");
	s.an = 1997;
	s.grupa = 1;

	lista_studenti[2] = s;

	//4
	strcpy(s.nume, "Bilc");
	strcpy(s.prenume, "Irina");
	strcpy(s.tara, "America");
	s.an = 1997;
	s.grupa = 921;

	lista_studenti[3] = s;

	//5
	strcpy(s.nume, "Todoran");
	strcpy(s.prenume, "Corina");
	strcpy(s.tara, "Romania");
	s.an = 1997;
	s.grupa = 921;

	lista_studenti[4] = s;

	int command;
	int grupa;

	while (1)
	{
		printMeniu();
		scanf("%d", &command);

		switch (command)
		{
		case 1:
			lista_studenti[length] = citireStudent();
			length++;
			break;
		case 2:
			afisareStudenti(lista_studenti, length);
			break;
		case 3:
			printf("Grupa cu cei mai multi studenti este: %d\n\n", maxStudenti(lista_studenti, length));
			break;
		case 4:
			printf("Introduceti numarul grupei dorite:\n");
			scanf("%d", &grupa);
			printf("Numarul de studenti straini din grupa %d este: %d\n", grupa, studentiStrini(lista_studenti, length, grupa));
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
	printf("1. Adaugare student nou\n");
	printf("2. Afisare studenti\n");
	printf("3. Grupa cu cei mai multi studenti\n");
	printf("4. Numarul de studenti straini dintr-o grupa\n");
	printf("Intorduceti numarul comenzii\n");
}

struct student citireStudent()
{
	struct student s;

	puts("\nIntroduceti numele studentului: ");
	scanf("%s", s.nume);

	if (_stricmp(s.nume, "AAA") == 0)
		exit(0);

	puts("\nIntroduceti prenumele studentului: ");
	scanf("%s", s.prenume);

	puts("\nIntroduceti tara de provenienta a studentului: ");
	scanf("%s", s.tara);

	puts("\nIntroduceti grupa studentului: ");
	scanf("%d", &s.grupa);

	puts("\nIntroduceti anul nasterii al studentului: ");
	scanf("%d", &s.an);
}

void afisareStudenti(struct student lista_studenti[3000], int lungime)
{
	for (int i = 0; i < lungime; i++)
		printf("NUME: %s, PRENUME: %s, TARA: %s, GRUPA: %d, ANUL NASTERII: %d\n", lista_studenti[i].nume,
			lista_studenti[i].prenume, lista_studenti[i].tara, lista_studenti[i].grupa, lista_studenti[i].an);
}

int maxStudenti(struct student lista_studenti[3000], int lungime)
{
	struct grupa
	{
		int nume;
		int studenti;
	};

	struct grupa grupe[100];
	int lg = 0;
	int ok;
	struct grupa g;
	g.studenti = 1;

	for (int i = 0; i < lungime; i++)
	{
		ok = 0;
		for (int j = 0; j < lg; j++)
			if (grupe[j].nume == lista_studenti[i].grupa)
			{
				grupe[j].studenti++;
				ok = 1;
			}
		if (ok == 0)
		{
			g.nume = lista_studenti[i].grupa;
			grupe[lg] = g;
			lg++;
		}
	}

	int max = -1;
	int maxGrupa;

	for(int i = 0; i < lg; i++)
		if (grupe[i].studenti > max)
		{
			max = grupe[i].studenti;
			maxGrupa = grupe[i].nume;
		}

	return maxGrupa;
}

int studentiStrini(struct student lista_studenti[3000], int lungime, int grupa)
{
	int contor = 0;

	for (int i = 0; i < lungime; i++)
		if (lista_studenti[i].grupa == grupa && _strcmpi(lista_studenti[i].tara, "Romania") != 0)
			contor++;

	return contor;
}