#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
typedef struct
{
    int gun;
    int ay;
    int yil;
    int saat;
} Randevu;
typedef struct
{
    char *ad;
    int yas;
    int uzmanlik_alan_no;
    char cinsiyet;
    int doktor_id;
    int randevu_sayisi;
    Randevu randevular[24];
} Doktor;


typedef struct
{
    char *ad;
    int yas;
    int gidecegi_alan;
    char cinsiyet;
    char *sikayet_sebebi;
    int sectigi_doktor_id;
    int oda_no;
    Randevu randevu;
} Hasta;



#endif // STRUCTS_H_INCLUDED
