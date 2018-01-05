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

void afisareValoare(struct student s);
void afisareReferinta(struct student* s);

void main()
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

	afisareValoare(s);
	afisareReferinta(&s);

	_getch();
}

void afisareValoare(struct student s)
{
	printf("Prin valoare: NUME: %s, PRENUME: %s, TARA: %s, GRUPA: %d, ANUL NASTERII: %d\n", s.nume, s.prenume, s.tara, s.grupa, s.an);
}

void afisareReferinta(struct student* s)
{
	printf("Prin referinta: NUME: %s, PRENUME: %s, TARA: %s, GRUPA: %d, ANUL NASTERII: %d\n", s->nume,
		s->prenume, s->tara, s->grupa, s->an);
}
