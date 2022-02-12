#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Izbornik(void) {
	int izbor;
	CLAN* Upis = NULL;
	CLAN* Pregled = NULL;



	system("color 6");
	printf("\n\n\t\t\t\tASTRONOMSKO DRUSTVO 'ORION'");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DOBRODOSLI U GLAVNI IZBORNIK \xB2\xB2\xB2\xB2\xB2\xB2\xB2");


	printf("\n\n\nOdaberite jednu od iducih opcija:\n");
	printf("\t1. Dodavanje novih clanova\n");
	printf("\t2. Pregledaj upisane clanove\n");
	printf("\t3. Odjava iz programa\n");
	printf("\t4. Izlaz iz programa\n");

	scanf("%d", &izbor);
	system("cls");
	switch (izbor)
	{
	case 1:
		Upis_clana(Upis);

		break;
	case 2:
		Pregled_clana(Pregled);

		break;
	case 3:
		Odjava();
		
		break;
	case 4:
		Izlaz();

		break;

	default:
		printf("\nNepostojeci izbor!");
		_getch();
		system("cls");
		Izbornik();
		break;
	}

}



void Prijava(void) {
	int lozinka;


	system("color 6");


	printf("\n\n\t\t\t\t\tASTRONOMSKO DRUSTVO 'ORION'");
	printf("\n\n\t\t\t\t\t\t\t\tLozinka: 251207\n");

	printf("\n\n\nUnesite lozinku za nastavak: ");
	scanf("%d", &lozinka);


	if (lozinka != 251207) {
		printf("\n\n\tNetocna lozinka!\n");
		printf("Pritisnite tipku za nastavak...\n");
		_getch();
		system("cls");
		Prijava();

	}


	printf("\n\n\t\a Dobrodosli u sustav");
	_getch();
	system("cls");

	Izbornik();

}





void Upis_clana(CLAN* Upis) {
	int n;
	int i;
	int test = 0;

	Upis = (CLAN*)calloc(1, sizeof(CLAN));

	FILE* pu = NULL;
	pu = fopen("Clanovi.txt", "w");
	if (pu == NULL) {
		printf("Problem s datotekom!\n");
		_getch();
		system("cls");
		Izbornik();

	}

	printf("Unesite broj novih clanova koje zelite upisati: ");
	scanf("%d", &n);
	system("cls");
	for (i = 0; i < n; i++) {
		printf("Unesite ime %d. clana: ", i + 1);
		scanf("%19s", Upis->ime);
		printf("Unesite prezime %d. clana: ", i + 1);
		scanf("%24s", Upis->prezime);
		printf("Unesite OIB za %d. clana: ", i + 1);
		scanf("%11s", Upis->OIB);
		printf("Unesite dan rodjenja za %d. clana: ", i + 1);
		scanf("%hu", &Upis->Datum_rodjenja.dan);
		printf("Unesite mjesec rodjenja za %d. clana: ", i + 1);
		scanf("%hu", &Upis->Datum_rodjenja.mjesec);
		printf("Unesite godinu rodjenja za %d. clana: ", i + 1);
		scanf("%hu", &Upis->Datum_rodjenja.godina);
		fprintf(pu, "%s\t %s\t %s\t %02hu %02hu %4hu\n", Upis->ime, Upis->prezime, Upis->OIB, Upis->Datum_rodjenja.dan, Upis->Datum_rodjenja.mjesec, Upis->Datum_rodjenja.godina);
		test++;
	}

	if (test == 0) {
		printf("Nemoguce dodati clana!\n");
		_getch();
		system("cls");
		Izbornik();
	}


	printf("\n\nClanovi uspjesno dodani!\n");
	fclose(pu);

	
	FILE* fp = NULL;
	fp = fopen("Broj_clanova.txt", "w");
	if (fp == NULL) {
		printf("Problem s datotekom!\n");
		_getch();
		system("cls");
		Izbornik();
	}
	fprintf(fp, "%d", n);
	fclose(fp);

	free(Upis);
	_getch();
	system("cls");
	Izbornik();
}



void Pregled_clana(CLAN* Pregled) {


	int i;
	int m;
	int test = 0;


	Pregled = (CLAN*)calloc(1, sizeof(CLAN));



	FILE* pok = NULL;
	pok = fopen("Broj_clanova.txt", "r");
	if (pok == NULL) {
		printf("Problem s datotekom!\n");
		_getch();
		system("cls");
		Izbornik();
	}
	fscanf(pok, "%d", &m);
	fclose(pok);


	FILE* fp = NULL;
	fp = fopen("Clanovi.txt", "r");
	if (fp == NULL) {
		printf("Problem s datotekom!\n");
		_getch();
		system("cls");
		Izbornik();
	}


	for (i = 0; i < m; i++) {
		fscanf(fp, "%s %s %s %02hu %02hu %4hu", Pregled->ime, Pregled->prezime, Pregled->OIB, &Pregled->Datum_rodjenja.dan, &Pregled->Datum_rodjenja.mjesec, &Pregled->Datum_rodjenja.godina);
		printf("Ime: %s \tPrezime: %s \tOIB: %s \tDatum rodjenja: %02hu %02hu %4hu\n", Pregled->ime, Pregled->prezime, Pregled->OIB, Pregled->Datum_rodjenja.dan, Pregled->Datum_rodjenja.mjesec, Pregled->Datum_rodjenja.godina);
		test++;
	}

	if (test == 0) {
		printf("Nema upisanih clanova!\n");
		_getch();
		system("cls");
		Izbornik();
	}

	fclose(fp);
	free(Pregled);

	_getch();
	system("cls");
	Izbornik();


}



void Odjava(void) {
	int odabir;

	printf("Zelite li se odjaviti iz programa?\n");
	printf("\n\t1. Da\n\t2. Ne\n");
	scanf("%d", &odabir);
	if (odabir == 1) {
		system("cls");
		Prijava();
	}
	else if (odabir == 2) {
		system("cls");
		Izbornik();
	}
	else {
		printf("Nepostojeci izbor!\n");
		_getch();
		system("cls");
		Odjava();
	}
}




void Izlaz(void) {
	int izbor;
	printf("Da li zelite izaci iz programa?\n\n");
	printf("\t1. DA\n\t2. NE\n");
	scanf("%d", &izbor);

	if (izbor == 1) {
		exit(EXIT_SUCCESS);
	}
	else if (izbor == 2) {
		system("cls");
		Izbornik();
	}
	else {
		printf("Nemoguci odabir!\n");
		_getch();
		system("cls");
		Izlaz();
		
	}
}