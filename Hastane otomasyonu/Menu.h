
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Structs.h"

//öndirektifler
#define ANSI_RESET_TEMA   printf("\033[0m");
#define ANSI_ACIK_PASTEL printf("\033[1;38;2;180;140;200;48;2;200;220;255m");   // bold + pastel renk
#define ANSI_KOYU_PASTEL printf("\033[1;38;2;240;220;150;48;2;60;40;80m");      // bold + koyu pastel
#define ANSI_TEHLIKE     printf("\033[1;6;4;38;2;255;255;0;48;2;200;0;0m");       // bold + underline
#define ANSI_DOGA        printf("\033[1;38;2;80;40;10;48;2;140;190;130m");
#define ANSI_ACIK_KLASIK printf("\033[1;38;2;0;0;0;48;2;240;240;240m");
#define ANSI_KOYU_KLASIK printf("\033[0;38;2;255;255;255;48;2;0;0;0m");
int menu(int*islem_no);

int admin_giris_menu(char * txt_admin_kullanici_adi);
int admin_giris_kontrol();
int doktor_giris();
int randevu_al();
int doktor_ekle();
int doktor_sil();
int doktor_listele();
int admin_ayarlar();
int bos_id_bul();
void ansi_renkleri_aktif_et();

//tema fonksiyonlarý

typedef enum {
    TEMA_ACIK_PASTEL = 1,
    TEMA_KOYU_PASTEL,
    TEMA_TEHLIKE,
    TEMA_DOGA,
    TEMA_ACIK_KLASIK,
    TEMA_KOYU_KLASIK
} TemaID;





#endif // MENU_H_INCLUDED
