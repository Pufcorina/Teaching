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
void afisareStudent(struct student s);
struct student updateGrupa(struct student s, int grupa);

void main()
{
	struct student s;
	s = citireStudent();
	afisareStudent(s);
	afisareStudent(updateGrupa(s, 917));

	_getch();
}

struct student citireStudent()
{
	struct student s;

	puts("\nIntroduceti numele studentului: ");
	scanf("%s", s.nume);

	puts("\nIntroduceti prenumele studentului: ");
	scanf("%s", s.prenume);

	puts("\nIntroduceti tara de provenienta a studentului: ");
	scanf("%s", s.tara);

	puts("\nIntroduceti grupa studentului: ");
	scanf("%d", &s.grupa);

	puts("\nIntroduceti anul nasterii al studentului: ");
	scanf("%d", &s.an);

	return s;
}

void afisareStudent(struct student s)
{
	printf("NUME: %s, PRENUME: %s, TARA: %s, GRUPA: %d, ANUL NASTERII: %d\n", s.nume, s.prenume, s.tara, s.grupa, s.an);
}

struct student updateGrupa(struct student s, int grupa)
{
	printf("Studentului %s %s i s-a modificat grupa in %d\n", s.nume, s.prenume, grupa);
	s.grupa = grupa;
	return s;
}