#ifndef HEADER_H
#define HEADER_H




struct datum {
	unsigned short dan;
	unsigned short mjesec;
	unsigned short godina;
};


typedef struct clan
{
	char ime[20];
	char prezime[25];
	char OIB[12];
	struct datum Datum_rodjenja;

}CLAN;

void Prijava(void);
void Upis_clana(CLAN*);
void Pregled_clana(CLAN*);
void Odjava(void);
void Izlaz(void);

#endif
