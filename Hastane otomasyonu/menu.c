#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED
#include "Menu.h"
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // <-- ekle
//bu kisim tema icin
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
//

int menu(int* islem_no)
{
    while(*islem_no!=0)
    {


        system("cls");
        char ch;//\n icin
        printf("\n\t\t\tSehir Hastanesi'ne hos geldiniz\n\t\t\t Lutfen yapmak istediginiz islemi seciniz=");
        printf("\n\t\t\t----------------------------------------------------------------------------");
        printf("\n\t\t\t1-Admin Giris");
        printf("\n\t\t\t2-Doktor giris");
        printf("\n\t\t\t3-Randevu al");
        printf("\n\t\t\t4-Cikis");
        printf("\n\t\t\t----------------------------------------------------------------------------\n\t\t\t");
        scanf("%d",islem_no);
        while((ch=getchar())!='\n'&& ch!= EOF) {}

        switch(*islem_no)
        {
        case 1:
            if (admin_giris_kontrol ()!=0)
                printf("Admin Girisi Basarisiz!!!");
            break;
        case 2:
            if (doktor_giris()!=0)
                printf("Doktor Girisi Basarisiz!!!");
            break;
        case 3:
            if(randevu_al()!=0)
                printf("Randevu alma Basarisiz!!!");
            break;
        case 4:
            *islem_no=0;
            break;
        default:
            printf("\nGecersiz secim");
            break;
        }
    }
    return 1;
}
int admin_giris_kontrol()
{
    system("cls"); // Windows'ta çalisir, Linux için "clear" kullanilabilir

    char admin_giris_panel[50];
    char txt_admin_kullanici_adi[50];
    char txt_admin_sifre[50];
    char sifre_input[50];
    char ch;
    int hak = 0;

    FILE *fptr = fopen("kullanici.txt", "r");
    if (!fptr)
    {
        printf("kullanici.txt acilamadi!\n");
        return 1;
    }

    while (hak < 5)
    {
        printf("Kullanici adi giriniz: ");
        scanf("%49[^\n]", admin_giris_panel);
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        int bulundu = 0;
        rewind(fptr);

        // Okuma formati: "kullanici adi" sifre
        while (fscanf(fptr, "\"%49[^\"]\" %49[^\n]\n",
                      txt_admin_kullanici_adi, txt_admin_sifre) == 2)
        {

            if (strcmp(admin_giris_panel, txt_admin_kullanici_adi) == 0)
            {
                bulundu = 1;
                int sifre_hakki = 0;

                while (sifre_hakki < 5)
                {
                    printf("Sifre giriniz: ");
                    scanf("%49[^\n]", sifre_input);
                    while ((ch = getchar()) != '\n' && ch != EOF) {}


                    if (strcmp(sifre_input, txt_admin_sifre) == 0)
                    {
                        printf("Giris basarili!\nDevam etmek icin enter'a basiniz...");
                        getchar();
                        fclose(fptr);
                        admin_giris_menu(txt_admin_kullanici_adi);
                        return 0;
                    }
                    else
                    {
                        hak++;
                        sifre_hakki++;
                        if (hak == 5)
                        {
                            printf("\nHaklariniz bitti. Ana menuye donmek icin enter'a basiniz...\n");
                            getchar();
                            fclose(fptr);
                            return 1;
                        }
                        printf("Sifre yanlis! %d hakkiniz kaldi\n", 5 - hak);
                    }
                }
                break;
            }
        }

        if (!bulundu)
        {
            hak++;
            if (hak == 5)
            {
                printf("\nHaklariniz bitti. Ana menuye donmek icin enter'a basiniz...\n");
                getchar();
                break;
            }
            printf("Kullanici adi bulunamadi! %d hakkiniz kaldi\n", 5 - hak);
        }
    }

    fclose(fptr);
    return 1;
}



int admin_giris_menu(char* admin_isim)
{
    int islem_no=-1;
    while (islem_no!=0)
    {
        system("cls");
        char ch;//\n icin
        printf("\n\t\t\tHos geldiniz sayin %s.Yapmak istediginiz islemi secin:",admin_isim);
        printf("\n\t\t\t----------------------------------------------------------------------------");
        printf("\n\t\t\t1-Doktor Ekle");
        printf("\n\t\t\t2-Doktor Sil");
        printf("\n\t\t\t3-Doktorlari listele");
        printf("\n\t\t\t4-Ayarlar");
        printf("\n\t\t\t5-Cikis");
        printf("\n\t\t\t----------------------------------------------------------------------------\n\t\t\t");
        scanf("%d",&islem_no);
        while((ch=getchar())!='\n'&& ch!= EOF) {}

        switch(islem_no)
        {
        case 1:
            if (doktor_ekle ()!=0)
                printf("\nDoktorekleme Basarisiz!!!");
            break;
        case 2:
            if (doktor_sil()!=0)
                printf("\nDoktor silme Basarisiz!!!");
            break;
        case 3:
            if(doktor_listele()!=0)
                printf("\nDoktor Listeleme Basarisiz!!!");
            break;
        case 4:
            if(admin_ayarlar()!=0)
                printf("\nistediginiz islem gerceklestirilemiyor!");
            break;
        case 5 :
            islem_no=0;
            printf("Ana menuye donmek icin enter'a basiniz...\n");
            getchar();
            break;
        default:
            printf("\nGecersiz secim.");
            printf("\n\t\t\tDevam etmek icin enter'a basin\n");
            getchar();
            break;
        }
    }
    return 0;
}


int doktor_ekle()
{
    int doktor_sayisi=0,yas,uzmanlik_alani,en_kucuk_bos_id;
    char *isim,cinsiyet,ch,*sifre;
    isim=malloc(50);
    sifre=malloc(50);
    if(!isim) return 1;
    if(!sifre) return 1;
    system("cls");//ekran temizleme
    //dosya acma
    FILE *fptr;
    fptr=fopen("doktorlar.txt","r+");
    if(!fptr)
        return 1;

    // txt dosyasinin en basinda doktor sayisi var bunu dosyadan aliyoruz
    fscanf(fptr,"%d\n",&doktor_sayisi);
    //max doktor sayisi 10 olmali kontrol ediyoruz
    if(doktor_sayisi >= 20)
    {
        printf("\n\t\t\tMax doktor sayisina ulasildi.Daha fazla doktor ekleyemezsiniz..");
        free(isim);
        free(sifre);
        fclose(fptr);
        return 1;
    }
    doktor_sayisi++;//doktor sayisi artti

    // isretci dosya basina tekrar donuyor ve dosyadaki doktor sayisi 1 artiyor
    fseek(fptr,0,SEEK_SET);
    fprintf(fptr,"%d\n",doktor_sayisi);

    //Dktor ekleme menusu
    printf("\n\t\t\t---------------------------");
    printf("\n\t\t\tDoktor ekleme menusu.");
    printf("\n\t\t\t---------------------------");
    en_kucuk_bos_id=bos_id_bul();
    if(en_kucuk_bos_id == -1)
    {
        printf("Bos ID yok, doktor eklenemiyor veya dosya hatasi!\n");
        free(isim);
        free(sifre);
        fclose(fptr);
        return 1;
    }
    printf("\n\t\t\tDoktor id'si=%d",en_kucuk_bos_id);
    printf("\n\t\t\tLutfen Doktor ismini giriniz:");
    scanf("%49[^\n]",isim);
    while((ch=getchar())!='\n' && ch!=EOF) {}
    printf("\n\t\t\tLutfen Doktorun yasini giriniz:");
    scanf("%d",&yas);
    printf("\n\t\t\tLutfen Doktorun Uzmanlik alanina ait numarayi yazin:");
    printf("\n\t\t\t1-Dahiliye(Ic Hastaliklari)");
    printf("\n\t\t\t2-Noroloji(Beyin,Omurilik,Sinir sistemi hastaliklari)");
    printf("\n\t\t\t3-Psikiyatri (zihinsel duygusal ve davranis bozukluklari )");
    printf("\n\t\t\t4-Pediatri(Cocuk hastaliklari) ");
    printf("\n\t\t\t5-Dermatoloji (Deri hastaliklari)");
    printf("\n\t\t\t=");
    scanf("%d",&uzmanlik_alani);
    printf("\n\t\t\tLutfen Doktorun cinsiyetini yazin:(e:Erkek k:Kadin)");
    scanf(" %c",&cinsiyet);
    getchar();
    printf("\n\t\t\tLutfen Doktor sifresini giriniz:");
    scanf("%49[^\n]",sifre);
    while((ch=getchar())!='\n' && ch!=EOF) {}
    fseek(fptr,0,SEEK_END);
    fprintf(fptr,"%d \"%s\" %d %d %c \"%s\" \n",en_kucuk_bos_id,isim,yas,uzmanlik_alani,cinsiyet,sifre);
    free(isim);
    free(sifre);
    fclose(fptr);
    return 0;
}
int bos_id_bul()
{
    FILE *f = fopen("doktorlar.txt", "r");
    if (!f) return -1; // dosya yoksa 1’den baslariz

    int id_dolu_mu[11] = {0}; // 1-10 arasi ID
    int id;
    char ad[50],sifre[50];
    int yas, uzmanlik;
    char cinsiyet;
    int doktor_sayisi;

    fscanf(f, "%d\n", &doktor_sayisi); // ilk satiri atla

    // Dosyadan doktorlari sirayla oku
    while (fscanf(f, "%d \"%49[^\"]\" %d %d %c \"%49[^\"]\" ",
                  &id, ad, &yas, &uzmanlik, &cinsiyet,sifre) == 6)
    {
        if (id >= 1 && id <= 10)
            id_dolu_mu[id] = 1;
    }

    fclose(f);

    // 1–10 arasi ilk bos olan ID'yi bul
    for (int i = 1; i <= 10; i++)
    {
        if (id_dolu_mu[i] == 0)
            return i;
    }

    return -1; // hiç bos id yok
}


int doktor_sil()
{
    system("cls");

    int sil_id,doktor_sayisi,yeni_sayi,bulundu=0,id, yas, uzmanlik;
    char cinsiyet, *ad,*sifre;
    ad=malloc(50);
    sifre=malloc(50);
    if(!ad) return 1;
    if(!sifre)
        {
            free(ad);
            return 1;
        }
    printf("\n\t\t\tSilmek istediginiz doktor ID'sini girin: ");
    scanf("%d", &sil_id);

    FILE *fptr = fopen("doktorlar.txt", "r");
    if (!fptr)
    {
        free(ad);
        free(sifre);
        return 1;
    }


    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        fclose(fptr);
        free(ad);
        free(sifre);
        return 1;
    }
    fscanf(fptr, "%d", &doktor_sayisi);
    yeni_sayi = doktor_sayisi - 1;
    if (yeni_sayi < 0) yeni_sayi = 0;

    fprintf(temp, "%d\n", yeni_sayi); // güncel doktor sayisi


    while (fscanf(fptr, "%d \"%49[^\"]\" %d %d %c \"%49[^\"]\" ",
                  &id, ad, &yas, &uzmanlik, &cinsiyet,sifre ) == 6 )
    {
        if (id == sil_id)
        {
            bulundu = 1;   // bu doktoru atliyoruz → silmis oluyoruz
            continue;
        }

        fprintf(temp, "%d \"%s\" %d %d %c  \"%s\"\n",
                id, ad, yas, uzmanlik, cinsiyet,sifre);
    }

    fclose(fptr);
    fclose(temp);

    remove("doktorlar.txt");
    rename("temp.txt", "doktorlar.txt");

    if (!bulundu)
    {
        printf("\n\t\t\tBu ID'ye sahip doktor bulunamadi.\n");
        free(ad);
        free(sifre);
        fclose(fptr);
        fclose(temp);
        return 1;
    }

    printf("\n\t\t\tDoktor basariyla silindi.\n");
    printf("\n\t\t\tDevam etmek icin enter'a basin\n");
    getchar();
    getchar();
    return 0;

}

int doktor_listele()

{
    // degiskenler
    int doktor_sayisi=0,id,yas,uzmanlik;
    char *ad,cinsiyet,*uzmanlik_str,*sifre;
    ad=malloc(50);
    sifre=malloc(50);

    if(!ad || !sifre)
    {
        free(ad);
        free(sifre);
        return 1;
    }
    // ekran temizleme
    system("cls");
      // dosya acma

    FILE *fptr;

    fptr=fopen("doktorlar.txt","r");
    if(!fptr)
    {
        free(ad);
        free(sifre);
        return 1;
    }

    fscanf(fptr,"%d\n",&doktor_sayisi);//doktor sayisini listeye eklememesi icin
    //menu basligi
    printf("\n\t\t\t---------------");
    printf("\n\t\t\tDoktor Listesi");
    printf("\n\t\t\t---------------\n");

    while(fscanf(fptr, "%d \"%49[^\"]\" %d %d %c \"%49[^\"]\" ",
                 &id, ad, &yas, &uzmanlik, &cinsiyet,sifre ) == 6)// doktorlari okuma ve dongu
    {

        switch(uzmanlik)
        {
        case 1:
            uzmanlik_str = "Dahiliye (Ic Hastaliklari)";
            break;
        case 2:
            uzmanlik_str = "Noroloji (Beyin, Omurilik, Sinir sistemi)";
            break;
        case 3:
            uzmanlik_str = "Psikiyatri (Zihinsel, duygusal, davranis bozukluklari)";
            break;
        case 4:
            uzmanlik_str = "Pediatri (Cocuk hastaliklari)";
            break;
        case 5:
            uzmanlik_str = "Dermatoloji (Deri hastaliklari)";
            break;
        default:
            uzmanlik_str = "Bilinmiyor";
            break;
        }
        printf("\n\t\t\tDoktor id=%d \n\t\t\tDoktor ismi=\"%s\" \n\t\t\tDoktor yasi=%d \n\t\t\tDoktor Uzmanlik alani=%s \n\t\t\tDoktor cinsiyeti=%s \n",
               id, ad, yas, uzmanlik_str, cinsiyet=='e'?"Erkek":"Kadin");
        printf("\n\t\t\t-----------------------------\n");

    }
    free(ad);
    free(sifre);
    fclose(fptr);
    printf("\n\t\t\tDevam etmek icin enter'a basin\n");
    getchar();
    return 0;
}

int admin_ayarlar()
{
    //veriler
    int secim_menu,secim;
    char admin_isim[50], admin_sifre[50],ch,txt_admin_kullanici_adi[50], txt_admin_sifre[50];
    system("cls");//ekran temizleme
    //menu
    printf("\n\t\t\t---------");
    printf("\n\t\t\t Ayarlar");
    printf("\n\t\t\t---------");
    printf("\n\t\t\t1-Tema degistir");
    printf("\n\t\t\t2-Yeni admin ekle-admin sil");
    printf("\n\t\t\tLutfen istediginiz islemin numarasini yazin:");
    scanf("%d",&secim_menu);

    if(secim_menu==1)
    {
        printf("\n\t\t\t--- TEMA MENUSU ---\n");
        printf("\n\t\t\t1) Acik Pastel\n");
        printf("\n\t\t\t2) Koyu Pastel\n");
        printf("\n\t\t\t3) Tehlike\n");
        printf("\n\t\t\t4) Doga\n");
        printf("\n\t\t\t5) Acik Klasik\n");
        printf("\n\t\t\t6) Koyu Klasik\n");
        printf("\n\t\t\tSeçim (1-6): ");
        scanf("%d", &secim);

        if (secim < 1 || secim > 6) secim = 6;

        FILE *f = fopen("config.txt", "w");
        if (f)
        {
            fprintf(f, "%d", secim);
            fclose(f);
        }

        switch(secim)
        {
        case 1:
            ANSI_ACIK_PASTEL;
            break;
        case 2:
            ANSI_KOYU_PASTEL;
            break;
        case 3:
            ANSI_TEHLIKE;
            break;
        case 4:
            ANSI_DOGA;
            break;
        case 5:
            ANSI_ACIK_KLASIK;
            break;
        case 6:
            ANSI_KOYU_KLASIK;
            break;
        }

    }
    if(secim_menu == 2)
    {

        printf("\n\t\t\t1-Yeni admin ekle \n\t\t\t2-Admin sil\n\t\t\tSeciminizi giriniz: ");
        int secim;
        scanf("%d", &secim);
        getchar(); // enter temizleme

        switch(secim)
        {
        case 1:
        {
            FILE *fptr = fopen("kullanici.txt", "a");
            if(!fptr)
                return 1;
            char admin_isim[50], admin_sifre[50];

            printf("\n\t\t\tEklemek istediginiz adminin ismini giriniz (En fazla 49 karakter): ");
            scanf("%49[^\n]", admin_isim);
            getchar(); // enter temizleme

            printf("\n\t\t\tEklemek istediginiz adminin sifresini giriniz (En fazla 49 karakter): ");
            scanf("%49[^\n]", admin_sifre);
            getchar(); // enter temizleme

            fprintf(fptr, "\n\"%s\" %s", admin_isim, admin_sifre);

            printf("\n\t\t\tAdmin basariyla eklendi!\n");
            fclose(fptr);
            break;
        }
        case 2:
        {
            printf("\n\t\t\tSilmek istediginiz adminin kullanici adini girin: ");
            char admin_isim[50];
            scanf("%49[^\n]", admin_isim);
            while ((ch = getchar()) != '\n' && ch != EOF) {}

            FILE *fptr = fopen("kullanici.txt", "r");
            if (!fptr)
            {
                printf("Dosya acilamadi!\n");
                break;
            }

            FILE *temp = fopen("temp.txt", "w");
            if (!temp)
            {
                printf("Temp dosya acilamadi!\n");
                fclose(fptr);
                break;
            }

            char txt_admin_kullanici_adi[50], txt_admin_sifre[50];
            char line[200];
            int bulundu = 0;

            // Satir satir oku
            while (fgets(line, sizeof(line), fptr) != NULL)
            {
                if (sscanf(line, "\"%49[^\"]\" %49[^\n]", txt_admin_kullanici_adi, txt_admin_sifre) == 2)
                {
                    if (strcmp(admin_isim, txt_admin_kullanici_adi) == 0)
                    {
                        bulundu = 1; // silinecek admin, yazma
                        continue;
                    }

                    // silinmeyecekleri temp dosyasina yaz
                    fprintf(temp, "\"%s\" %s\n", txt_admin_kullanici_adi, txt_admin_sifre);
                }
            }

            fclose(fptr);
            fclose(temp);

            if (bulundu)
            {
                remove("kullanici.txt");
                rename("temp.txt", "kullanici.txt");
                printf("\n\t\t\tAdmin basariyla silindi!\n");
            }
            else
            {
                printf("\n\t\t\tBoyle bir kullanici adi yok!\n");
                remove("temp.txt");
            }

            printf("\n\t\t\tDevam etmek icin enter'a basin\n");
            getchar();

            break;
        }


        default:
            printf("Gecersiz secim!\n");
        }
    }

}




void ansi_renkleri_aktif_et()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Konsol Ciktisinin Handle ini alir. (HANDLE = Windows’un bir nesneyi isaret etmek için verdiği “kimlik numarasi”dir.)
    DWORD dwMode = 0;//Alt satir ile birlikte Konsolun hangi özelliklerinin aktif olduğunu öğrenir (örneğin echo, line input vs.)ve
    GetConsoleMode(hOut, &dwMode);//Bitwise OR (|=) ile mevcut moda bu özellik eklenir.
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;//Windows’un ANSI kaçis dizilerini yorumlamasini sağlar.
    SetConsoleMode(hOut, dwMode);//artik konsol renk kodlarini ve diğer vt100 escape kodlarini düzgünce okur,
#endif
    // config.txt'den eski temayi yükle
    FILE *f = fopen("config.txt", "r");
    int id = 1; // varsayilan tema
    if (f)
    {
        fscanf(f, "%d", &id);
        fclose(f);
        if (id < 1 || id > 6) id = 6;
    }

    switch(id)
    {
    case 1:
        ANSI_ACIK_PASTEL;
        break;
    case 2:
        ANSI_KOYU_PASTEL;
        break;
    case 3:
        ANSI_TEHLIKE;
        break;
    case 4:
        ANSI_DOGA;
        break;
    case 5:
        ANSI_ACIK_KLASIK;
        break;
    case 6:
        ANSI_KOYU_KLASIK;
        break;
    }


    return 0;
}


int doktor_giris()
{
    system("cls");

    int id_input, hak = 0;
    int doktor_sayisi = 0;
    int id, yas, uzmanlik;
    char ad[50], sifre[50], sifre_deneme[50];
    char cinsiyet;
    int ch;

    FILE *fptr = fopen("doktorlar.txt", "r");
    if (!fptr)
    {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    fscanf(fptr, "%d\n", &doktor_sayisi);

    printf("\n\t\t\t--------------");
    printf("\n\t\t\tDOKTOR GIRIŞI");
    printf("\n\t\t\t--------------");

    printf("\n\t\t\tLutfen doktor ID giriniz: ");
    scanf("%d", &id_input);

    // \n temizle
    while ((ch = getchar()) != '\n' && ch != EOF);

    int bulundu = 0;

    // doktorlari tara
    while (fscanf(fptr, "%d \"%49[^\"]\" %d %d %c \"%49[^\"]\"",
                  &id, ad, &yas, &uzmanlik, &cinsiyet, sifre) == 6)
    {
        if (id == id_input)
        {
            bulundu = 1;
            break;
        }
    }

    fclose(fptr);

    if (!bulundu)
    {
        printf("\n\t\t\tBoyle bir doktor ID yok!\n");
        return 1;
    }

    // Şifre kontrolü
    while (hak < 5)
    {
        printf("\n\t\t\tSifreyi giriniz: ");
        scanf("  %[^\n]", sifre_deneme);

        if (strcmp(sifre, sifre_deneme) == 0)
        {
            printf("\n\t\t\tGiris basarili! Devam etmek icin enter'a basiniz...");
            getchar(); // zaten önceki scanf'in \n'i burada alinir
            getchar(); // enter bekler
            return doktor_giris_menu(ad, id);
        }
        else
        {
            hak++;
            printf("\n\t\t\tYanlis sifre. Kalan hak: %d\n", 5 - hak);
        }
    }

    printf("\n\t\t\tHakkiniz bitti. Ana menuye donuluyor...\n");
    return 1;
}

int doktor_giris_menu(char *ad, int id)
{
    system("cls");
    int secim;

    printf("\n\t\t\t ------------------------");
    printf("\n\t\t\t Hos geldiniz Sayin %s", ad);
    printf("\n\t\t\t ------------------------");

    printf("\n\n\t\t\t 1 - Hastalarimi listele");
    printf("\n\t\t\t 2 - Hasta taburcu et");
    printf("\n\t\t\t 3 - Hastayi odaya yatir");
    printf("\n\t\t\t 4 - Cikis");
    printf("\n\n\t\t\t Lutfen bir islem seciniz: ");

    scanf("%d", &secim);

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // \n temizle

    switch (secim)
    {
    case 1:
        hastalari_listele(id);
        break;
    case 2:
        hasta_taburcu(id);
        break;
    case 3:
        hasta_odaya_yatir(id);
        break;
    case 4:
        return 0;
    default:
        printf("\n\t\t\tGecersiz secim!\n");
        break;
    }

    printf("\n\t\t\tDevam etmek icin enter'a basiniz...");
    getchar();
    return doktor_giris_menu(ad, id); // tekrar menüye dön
}
void hastalari_listele(int doktor_id)
{
    system("cls");

    FILE *fhasta = fopen("hastalar.txt", "r");
    if (!fhasta)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    // Hasta belleği olustur
    Hasta *h1 = malloc(sizeof(Hasta));
    if (!h1)
    {
        fclose(fhasta);
        return;
    }

    h1->ad = malloc(50);
    h1->sikayet_sebebi = malloc(200);
    if (!h1->ad || !h1->sikayet_sebebi)
    {
        fclose(fhasta);
        free(h1);
        return;
    }

    int i = 1;

    while (fscanf(fhasta,
                  "\"%49[^\"]\" %d %c %d \"%199[^\"]\" %d %d %d %d %d %d",
                  h1->ad,
                  &h1->yas,
                  &h1->cinsiyet,
                  &h1->gidecegi_alan,
                  h1->sikayet_sebebi,
                  &h1->sectigi_doktor_id,
                  &h1->randevu.yil,
                  &h1->randevu.ay,
                  &h1->randevu.gun,
                  &h1->randevu.saat,
                  &h1->oda_no) == 11)
    {
        if (h1->sectigi_doktor_id == doktor_id)
        {
            printf("\n\t%d) Hasta Adi: %s | Yas: %d | Cinsiyet: %s\n",
                   i,
                   h1->ad,
                   h1->yas,
                   h1->cinsiyet == 'e' ? "Erkek" : "Kadin");

            printf("\t   Sikayet: %s\n", h1->sikayet_sebebi);

            printf("\t   Randevu: %04d-%02d-%02d %02d:00\n",
                   h1->randevu.yil,
                   h1->randevu.ay,
                   h1->randevu.gun,
                   h1->randevu.saat);

            printf("\t   Oda No: %d\n\n", h1->oda_no);

            i++;
        }
    }

    fclose(fhasta);
    free(h1->ad);
    free(h1->sikayet_sebebi);
    free(h1);
}


void hasta_taburcu(int doktor_id)
{
    system("cls");

    FILE *fhasta = fopen("hastalar.txt", "r");
    if (!fhasta)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        fclose(fhasta);
        printf("Gecici dosya acilamadi!\n");
        return;
    }

    // Hasta belleği olustur
    Hasta *h1 = malloc(sizeof(Hasta));
    if (!h1)
    {
        fclose(fhasta);
        fclose(temp);
        return;
    }

    h1->ad = malloc(50);
    h1->sikayet_sebebi = malloc(200);
    if (!h1->ad || !h1->sikayet_sebebi)
    {
        fclose(fhasta);
        fclose(temp);
        free(h1);
        return;
    }

    // Hastalari göster
    printf("\n\t\t--- HASTA LISTESI ---\n\n");
    hastalari_listele(doktor_id);

    int hasta_no;
    printf("\nSilmek istediginiz hastanin numarasini giriniz: ");
    scanf("%d", &hasta_no);
    getchar(); // \n temizle

    int i = 1;               // tüm satirlari sayar
    int doktor_hasta_index = 1; // sadece doktor hastalarini sayar

    while (fscanf(fhasta,
                  "\"%49[^\"]\" %d %c %d \"%199[^\"]\" %d %d %d %d %d %d",
                  h1->ad,
                  &h1->yas,
                  &h1->cinsiyet,
                  &h1->gidecegi_alan,
                  h1->sikayet_sebebi,
                  &h1->sectigi_doktor_id,
                  &h1->randevu.yil,
                  &h1->randevu.ay,
                  &h1->randevu.gun,
                  &h1->randevu.saat,
                  &h1->oda_no) == 11)
    {
        if (h1->sectigi_doktor_id == doktor_id)
        {
            if (doktor_hasta_index == hasta_no)
            {
                // bu satiri yazma → hasta silindi
                doktor_hasta_index++;
                i++;
                continue;
            }
            doktor_hasta_index++;
        }

        // diğer tüm satirlari temp'e yaz
        fprintf(temp,
                "\"%s\" %d %c %d \"%s\" %d %d %d %d %d %d\n",
                h1->ad,
                h1->yas,
                h1->cinsiyet,
                h1->gidecegi_alan,
                h1->sikayet_sebebi,
                h1->sectigi_doktor_id,
                h1->randevu.yil,
                h1->randevu.ay,
                h1->randevu.gun,
                h1->randevu.saat,
                h1->oda_no);
        i++;
    }

    fclose(fhasta);
    fclose(temp);

    remove("hastalar.txt");
    rename("temp.txt", "hastalar.txt");

    printf("\nHasta basariyla taburcu edildi!\n");

    free(h1->ad);
    free(h1->sikayet_sebebi);
    free(h1);
}

void hasta_odaya_yatir(int doktor_id)
{
    system("cls");

    FILE *fhasta = fopen("hastalar.txt", "r");
    if (!fhasta)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (!temp)
    {
        fclose(fhasta);
        printf("Gecici dosya acilamadi!\n");
        return;
    }

    // Hasta belleği olustur
    Hasta *h1 = malloc(sizeof(Hasta));
    if (!h1)
    {
        fclose(fhasta);
        fclose(temp);
        return;
    }

    h1->ad = malloc(50);
    h1->sikayet_sebebi = malloc(200);
    if (!h1->ad || !h1->sikayet_sebebi)
    {
        fclose(fhasta);
        fclose(temp);
        free(h1);
        return;
    }

    // Hastalari göster ve numarala
    printf("\n\t\t--- HASTA LISTESI ---\n\n");
    hastalari_listele(doktor_id);

    int hasta_no, oda_no;
    printf("\nYatirmak istediginiz hastanin numarasini giriniz: ");
    scanf("%d", &hasta_no);
    getchar(); // \n temizle

    printf("Oda numarasini giriniz: ");
    scanf("%d", &oda_no);
    getchar(); // \n temizle

    int i = 1;               // tüm satirlari sayar
    int doktor_hasta_index = 1; // sadece doktor hastalarini sayar

    while (fscanf(fhasta,
                  "\"%49[^\"]\" %d %c %d \"%199[^\"]\" %d %d %d %d %d %d",
                  h1->ad,
                  &h1->yas,
                  &h1->cinsiyet,
                  &h1->gidecegi_alan,
                  h1->sikayet_sebebi,
                  &h1->sectigi_doktor_id,
                  &h1->randevu.yil,
                  &h1->randevu.ay,
                  &h1->randevu.gun,
                  &h1->randevu.saat,
                  &h1->oda_no) == 11)
    {
        if (h1->sectigi_doktor_id == doktor_id && doktor_hasta_index == hasta_no)
        {
            // Seçilen hastanin oda numarasini güncelle
            h1->oda_no = oda_no;
            doktor_hasta_index++;
        }
        else if (h1->sectigi_doktor_id == doktor_id)
        {
            doktor_hasta_index++;
        }

        // Tüm satirlari temp dosyaya yaz
        fprintf(temp,
                "\"%s\" %d %c %d \"%s\" %d %d %d %d %d %d\n",
                h1->ad,
                h1->yas,
                h1->cinsiyet,
                h1->gidecegi_alan,
                h1->sikayet_sebebi,
                h1->sectigi_doktor_id,
                h1->randevu.yil,
                h1->randevu.ay,
                h1->randevu.gun,
                h1->randevu.saat,
                h1->oda_no);
        i++;
    }

    fclose(fhasta);
    fclose(temp);

    remove("hastalar.txt");
    rename("temp.txt", "hastalar.txt");

    printf("\nHasta basariyla odaya yatirildi! Oda numarasi: %d\n", oda_no);

    free(h1->ad);
    free(h1->sikayet_sebebi);
    free(h1);
}


int randevu_al()
{
    system("cls");

    // Hasta için bellek
    Hasta *h1 = malloc(sizeof(Hasta));
    if (!h1) return 1;

    h1->ad = malloc(50);
    h1->sikayet_sebebi = malloc(200);
    if (!h1->ad || !h1->sikayet_sebebi)
    {
        printf("bellek alani dolu");
        return 1;
    }

    int doktor_sayisi = 0, id, yas, uzmanlik ;
    char ad[50], cinsiyet, sifre[50];
    char *uzmanlik_str = NULL;

    FILE* fhasta = fopen("hastalar.txt","a+");
    FILE* fdoktor = fopen("doktorlar.txt","r");
    FILE* frandevu = fopen("randevular.txt","a");
    if(!fhasta || !fdoktor || !frandevu)
        return 1;

    printf("\n\t\t\t ----------");
    printf("\n\t\t\t Randevu");
    printf("\n\t\t\t ----------");

    printf("\n\t\t\tLutfen Adinizi ve Soyadinizi giriniz:");
    scanf(" %[^\n]", h1->ad);

    printf("\n\t\t\tLutfen yasinizi giriniz:");
    scanf("%d", &h1->yas);

    printf("\n\t\t\tCinsiyet (e/k): ");
    scanf(" %c", &h1->cinsiyet);
    // cinsiyetten sonra newline temizle
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

// güvenli okuma
    printf("\n\t\t\tSikayet sebebi: ");
    fgets(h1->sikayet_sebebi, 200, stdin);

// newline varsa kaldir
    size_t len = strlen(h1->sikayet_sebebi);
    if (len > 0 && h1->sikayet_sebebi[len-1] == '\n')
        h1->sikayet_sebebi[len-1] = '\0';


    printf("\n\t\t\t1-Dahiliye(Ic Hastaliklari)");
    printf("\n\t\t\t2-Noroloji(Beyin,Omurilik,Sinir sistemi hastaliklari)");
    printf("\n\t\t\t3-Psikiyatri (zihinsel duygusal ve davranis bozukluklari )");
    printf("\n\t\t\t4-Pediatri(Cocuk hastaliklari) ");
    printf("\n\t\t\t5-Dermatoloji (Deri hastaliklari)");
    printf("\n\t\t\t=");
    printf("\n\t\t\tPoliklinik numarasi: ");
    scanf("%d", &h1->gidecegi_alan);

    printf("\n\t\t\tDoktorlar listeleniyor...\n\n");
    Sleep(3000);

    rewind(fdoktor);

    char satir[256];

// İlk satir: doktor sayisi

    fscanf(fdoktor, "%d\n", &doktor_sayisi);

// Doktor satirlarini güvenle oku
   while(fscanf(fdoktor, "%d \"%49[^\"]\" %d %d %c \"%49[^\"]\" ",
                 &id, ad, &yas, &uzmanlik, &cinsiyet,sifre ) == 6)// doktorlari okuma ve dongu
    {

        if (uzmanlik != h1->gidecegi_alan) continue;


        switch(uzmanlik)
        {
        case 1:
            uzmanlik_str = "Dahiliye (Ic Hastaliklari)";
            break;
        case 2:
            uzmanlik_str = "Noroloji";
            break;
        case 3:
            uzmanlik_str = "Psikiyatri";
            break;
        case 4:
            uzmanlik_str = "Pediatri";
            break;
        case 5:
            uzmanlik_str = "Dermatoloji";
            break;
        default:
            uzmanlik_str = "Bilinmiyor";
            break;
        }

        printf("\n\t\t\tDoktor ID=%d | %s | Yas=%d | Uzmanlik=%s | Cinsiyet=%s |",
               id, ad, yas, uzmanlik_str,
               cinsiyet=='e'?"Erkek":"Kadin");
    }

    printf("\n\t\t\tLutfen sectiginiz doktor ID girin: ");
    scanf("%d", &h1->sectigi_doktor_id);

    doktor_randevularini_goster(h1->sectigi_doktor_id);

    printf("\n\t\t\tRandevu tarihi (YYYY AA GG SS): ");
    scanf("%d %d %d %d",
          &h1->randevu.yil,
          &h1->randevu.ay,
          &h1->randevu.gun,
          &h1->randevu.saat);

    // randevular.txt'ye doktor id + tarih/saat yaz
    fprintf(frandevu, "%d %d %d %d %d\n",
            h1->sectigi_doktor_id,
            h1->randevu.yil,
            h1->randevu.ay,
            h1->randevu.gun,
            h1->randevu.saat);

    h1->oda_no=0;
    // Dosyaya yaz — 11 placeholder ile uyumlu
    fprintf(fhasta,
            "\"%s\" %d %c %d \"%s\" %d %d %d %d %d %d\n",
            h1->ad,
            h1->yas,
            h1->cinsiyet,
            h1->gidecegi_alan,
            h1->sikayet_sebebi,
            h1->sectigi_doktor_id,
            h1->randevu.yil,
            h1->randevu.ay,
            h1->randevu.gun,
            h1->randevu.saat,
            h1->oda_no// oda durumu
           );

    fclose(fhasta);
    fclose(fdoktor);
    fclose(frandevu);

    return 0;
}

void doktor_randevularini_goster(int doktor_id)
{
    FILE *frandevu = fopen("randevular.txt", "r");
    if (!frandevu)
    {
        printf("Randevular dosyasi acilamadi!\n");
        return;
    }

    int id, yil, ay, gun, saat;
    int bulundu = 0;

    printf("\n\t\t\tDoktor ID=%d icin dolu randevular:\n", doktor_id);
    while (fscanf(frandevu, "%d %d %d %d %d", &id, &yil, &ay, &gun, &saat) == 5)
    {
        if (id == doktor_id)
        {
            printf(" \n\t\t\t- Tarih: %04d-%02d-%02d Saat: %02d:00\n", yil, ay, gun, saat);
            bulundu = 1;
        }
    }

    if (!bulundu)
        printf("\n\t\t\tBu doktora ait randevu bulunamadi.\n");

    fclose(frandevu);
}


#endif // MENU_C_INCLUDED
