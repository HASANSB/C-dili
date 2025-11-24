#include <stdio.h>
#include <stdlib.h>

// TUM FONKSIYONLARIN DAHA KISA YAZILAN DAHA HIZLI DAHA AZ BELLEK HARCAYAN ŞEKLINDE VARYASYONLARINI BUL
// CONST GOTO GETCH PUTCH GETCHAR PUTCHAR STRUCT UNION ENUM POINTER VE DIZI
int algoritmaMenusu();
//Matematik Algoritmalari(dONGULERE KADAR OLAN KONULAR)
int SayilarToplamiHesapla();
int ikiSayiFarki();
int ikiSayiCarpimi();
int ikiSayiBolumu();
int SayiUssuHesapla();
int SayiFaktoriyelHesapla();
int BasamakSayisiHesapla();
int SayiBasamakToplamiHesapla();
int SayiTamBolenleriHesapla();
int FibonacciSayisiHesapla();
int AsalSayilaribul();
int ArmstrongSayisiHesapla();
int MukemmelsayilariHesapla();
int PalindromSayiHesapla();
int SayininAsalBolenleriHesapla();
int IkiSayininEbobEkokuHesapla();
int Decimalden2ve8likTabanHesapla();//16 lik icin diziler bilmelisin Cunku Harf var
//Diziler
int DiziElemanToplamlari(); //istedigin kadar sayiyi diziye ekler ve o sayilari toplar
int DizidekiElemanSayisi();// Dizide kac eleman var onu bulur
int DizidekiEnbuyukKucukEleman();//Selection sort
int DiziyiTersCevir();
int HerSatirdaHarfEkle();
int IkiDiziBirlestir();
int CarpimTablosu();
int SatirSutunBoyutHesapla();
int IkiMatrisArasiIslemler();
int SatirVeSutundakiDegerlerinAyriToplami();
int SatirTopSirala();
int MatrisDiagonalVeIzHesapla();
int MatrisTranspozHesapla();
int MatrisDondurme();
int SpiralMatris();//!!!!Çook zor!//
//FONKSIYONLAR

int RecursiveFonksiyonMenu();/*RECURSIVE IÇIN FAONKSIYON*/

int FaktoriyelRecursive(int num1);
int FibonacciRecursive(int num);
int DiziToplamiRecursive(int Sayidizisi[],int boyut);
int BasamakToplamiRecursive(int num);
int KombinasyonRecursive(int num1,int num2);
int PermutasyonRecursive();
int AsalKontrolRecursive(int num1,int num2);
int EbobHesapRecursive(int num1,int num2);
int EkokHesapRecursive(int num1,int num2);

//Dosyalar

void KullaniciVerisiniDosyayaYaz();
void DosyaSatirSayisiBul();



int main()
{
    //algoritma menusu
    while(algoritmaMenusu())
    {};
    return 0;

}


int algoritmaMenusu()
{

    int Uygulama_Numarasi;
    printf("                                                  Merhaba Hos Geldiniz :)");
    printf("\n------------------------------------- Kac numarali uygulamayi kullanmak istersiniz ------------------------------------- \n",Uygulama_Numarasi);
    printf("1- Istediginiz kadar sayinin toplamini bulan algoritma\n");
    printf("2- iki sayinin farkini bulan algoritma \n");
    printf("3- iki sayinin carpimini bulan algoritma \n");
    printf("4- iki sayinin bolumunu bulan algoritma\n");
    printf("5- Bir sayinin ussunu bulan algoritma\n");
    printf("6- Bir sayinin faktoryelini bulan algoritma\n");
    printf("7- Bir sayinin basamak sayisini bulan algoritma\n");
    printf("8- Bir sayinin basamaklari toplamini bulan algoritma\n");
    printf("9- Bir sayinin tam bolenlerini bulan algoritma\n");
    printf("10-Fibonacci sayisini bulan algoritma\n");
    printf("11-Istediginiz sayiya kadar olan asal sayilari bulan algoritma\n");
    printf("12-Armstrong (sayi=sayi^basamak sayisi) sayimi kontrol eden algoritma\n");
    printf("13-Mukemmel sayi mi(sayi*2=bolenler) kontrol eden algoritma\n");
    printf("14-Bir sayi palindrome mu kontrol eden algoritma\n");
    printf("15-Bir sayinin asal bolenlerini bulan algoritma\n");
    printf("16-Iki sayinin ebob ve ekokunu bulan algoritma\n");
    printf("17-10 luk tabandaki sayiyi istenilen tabana ceviren algoritma\n");
    printf("18-Tek boyutlu dizideki sayilarin toplamini bulan algoritma\n");
    printf("19-Dizideki eleman sayisini bulan algoritma\n");
    printf("20-Dizideki en buyuk ve en kucuk elemani bulan algoritma\n");
    printf("21-Dizideki elemanlari tersine ceviren algoritma\n");
    printf("22-Klavyeden girilen metni her satirda bir karakter ekleyerek ekrana yazan Algoritma\n");
    printf("23-Iki diziyi birlestiren algoritma\n");
    printf("24-Carpim tablosu algoritmasi\n");//2D array
    printf("25-Dizideki sutun satir ve dizideki toplam elemani hesaplayan algoritma\n");
    printf("26-Iki matris arasinda(+-*/) islemleri yapan algoritma\n");
    printf("27-Matristeki satir ve sutunlardaki degerleri ayri ayri toplayan algoritma\n");
    printf("28-Satir Toplamina gore matrisi siralayan algoritma\n" );
    printf("29-Matrisin diagonal, yan diagonal ve izini hesaplayan algoritma\n");
    printf("30-Matrisin Transpozunu Bulan Lgoritma\n");
    printf("31-Matrisi saat tonunde 90 derece donduren algoritma\n");
    printf("32-Matrisi spiral olarak duzenleyen algoritma\n");
    printf("33-Recursive fonksiyon Uygulamalar menusu\n");
    printf("34-Kullanicidan alinan verileri dosyaya yazma\n");
    printf("35-Dosyadaki Satir Sayisini Bul\n");


    printf("Lutfen yukaridaki uygulama numaralarindan birini secin:");
    scanf("%d",&Uygulama_Numarasi);
    system("cls");

    switch (Uygulama_Numarasi)

    {
    case 1:
        SayilarToplamiHesapla();
        break;
    case 2:
        ikiSayiFarki();
        break;
    case 3:
        ikiSayiCarpimi();
        break;
    case 4:
        ikiSayiBolumu();
        break;
    case 5:
        SayiUssuHesapla();
        break;
    case 6:
        SayiFaktoriyelHesapla();
        break;
    case 7:
        BasamakSayisiHesapla();
        break;
    case 8:
        SayiBasamakToplamiHesapla();
        break;
    case 9:
        SayiTamBolenleriHesapla();
        break;
    case 10:
        FibonacciSayisiHesapla();
        break;
    case 11:
        AsalSayilaribul();
        break;
    case 12:
        ArmstrongSayisiHesapla();
        break;
    case 13:
        MukemmelsayilariHesapla();
        break;
    case 14:
        PalindromSayiHesapla();
        break;
    case 15:
        SayininAsalBolenleriHesapla();
        break;
    case 16:
        IkiSayininEbobEkokuHesapla();
        break;
    case 17:
        Decimalden2ve8likTabanHesapla();
        break;
    case 18:
        DiziElemanToplamlari();
        break;
    case 19:
        DizidekiElemanSayisi();
        break;
    case 20:
        DizidekiEnbuyukKucukEleman();
        break;
    case 21:
        DiziyiTersCevir();
        break;
    case 22:
        HerSatirdaHarfEkle();
        break;
    case 23:
        IkiDiziBirlestir();
        break;
    case 24 :
        CarpimTablosu();
        break;
    case 25:
        SatirSutunBoyutHesapla();
        break;
    case 26:
        IkiMatrisArasiIslemler();
        break;
    case 27:
        SatirVeSutundakiDegerlerinAyriToplami();
        break;
    case 28:
        SatirTopSirala();
        break;
    case 29:
        MatrisDiagonalVeIzHesapla();
        break;
    case 30:
        MatrisTranspozHesapla();
        break;
    case 31:
        MatrisDondurme();
        break;
    case 32:
        SpiralMatris();
        break;
    case 33:
        RecursiveFonksiyonMenu();
        break;
    case 34:
        KullaniciVerisiniDosyayaYaz();
        break;
    case 35:
        DosyaSatirSayisiBul();
        break;

    default:
        printf("lutfen 1- ... arasi numara girin\n");
        break;
    }

    printf("Uygulamadan cikmak icin 0'a /Ana menuye donmek icin herhangi bir sayiya basin. ");
    scanf("%d",&Uygulama_Numarasi);
    system("cls");


    return Uygulama_Numarasi;
};



int SayilarToplamiHesapla()
{
    int num,sayiadedi,sonuc=0;
    printf("Kac sayi gireceksiniz:\n");
    scanf("%d",&sayiadedi);
    for(int i=0; i<sayiadedi; i++)
    {
        printf("Lutfen %d . sayiyi giriniz:",i+1);
        scanf("%d",&num);
        sonuc+=num;
    }
    printf("Iki sayinin toplami: %d \n",sonuc);
    return 1;
}
int ikiSayiFarki()
{

    int num1,num2,sonuc;
    printf("lutfen 2 tane sayi giriniz:\n");
    scanf("%d%d",&num1,&num2);
    sonuc = num1-num2;
    printf("Iki sayinin farki: %d \n",sonuc);
    return 1;
}

int ikiSayiCarpimi()
{

    int sonuc,num1,num2;
    printf("lutfen 2 tane sayi giriniz:\n");
    scanf("%d%d",&num1,&num2);
    sonuc = num1*num2;
    printf("Iki sayinin carpimi: %d \n",sonuc);
    return 1;
}

int ikiSayiBolumu()
{
    float sonuc,
    int bolen,bolunen;
    printf("Lutfen bolunen sayiyi giriniz\n");
    scanf("%d",&bolunen);
    for(;;)
    {
        printf("Lutfen bolen sayiyi giriniz:\n");
        scanf("%d",&bolen);
        if(bolen==0)
        {
            printf("bolen sayi 0 olamaz\n");
            continue;
        }
        else
        {
            break;
        }
    }
    sonuc=(float)bolunen/bolen;
    printf("%.2f\n",sonuc);
    return 1;
}

int SayiUssuHesapla()
{
    int num1,us,sonuc=1;
    printf("Lutfen bir sayi giriniz:");
    scanf("%d",&num1);
    printf("Lutfen hesaplanilacak ussu giriniz:");
    scanf("%d",&us);
    for (int i=0; i<us ; i++)
    {
        sonuc*=num1;
    }
    printf("%d\n",sonuc);
    return 1;
}

int SayiFaktoriyelHesapla()
{
    int num1,sonuc=1;
    printf("Lutfen bir sayi giriniz:");
    scanf("%d",&num1);
    for (int i=0; i<num1-1; i++)
    {
        sonuc*=num1-i;
    }
    printf("%d\n",sonuc);
}

int BasamakSayisiHesapla()
{
    int num1,basamakSayisi=1;
    printf("basamak sayisini hesaplamak istediginiz sayiyi giriniz:");
    scanf("%d",&num1);
    while(1)
    {
        num1/=10;
        basamakSayisi+=1;
        if (num1<10)
            break;
        else
            continue;
    }
    printf("Basamak sayisi=%d\n",basamakSayisi);
    return basamakSayisi;
}


int SayiBasamakToplamiHesapla()
{
    int num1,Basamaktoplami=0 ;
    printf("basamak toplamlarini hesaplamak istediginiz sayiyi giriniz:");
    scanf("%d",&num1);
    while(1)
    {
        if (num1<10)
        {
            Basamaktoplami+=num1;
            break;
        }
        else
        {
            Basamaktoplami+=num1%10;
            num1=num1/10;
        }
    }
    printf("Girdiginiz sayinin basamaklari toplami = %d\n",Basamaktoplami);
}

int SayiTamBolenleriHesapla()
{
    int num1;
    printf("Tam bolenlerini bulmak istediginiz sayiyi girin");
    scanf("%d",&num1);
    printf("Tam bolenler:");
    for(int i=2; i<=num1/2; i++)
    {
        if(num1%i==0)
        {
            printf("%d,",i);
        }
    }
}

int FibonacciSayisiHesapla()
{
    int Ustsinir,n0=0,n1=1,fibonacci=0;
    printf("Kacinci sayiya kadar fibonacci hesaplansin");
    scanf("%d",&Ustsinir);
    while(Ustsinir>fibonacci)
    {
        printf("%d \n",fibonacci);
        fibonacci=n0+n1;
        n0=n1;
        n1=fibonacci;
    }

}

int AsalSayilaribul()
{
    int Ustsinir=0,ctrl=0;
    printf("Lutfen kacinci sayiya kadar olan asal sayilari bulmak istediginizi yaziniz");
    scanf("%d",&Ustsinir);
    for(int i = 2; i<Ustsinir ; i++)
    {
        ctrl=0;
        for(int j = 2; j<=i/2; j++)
        {
            if (i%j==0)
            {
                ctrl=1;
                break;
            }
        }
        if (ctrl==0)
        {
            printf("%d bir asal sayidir\n",i);
        }

    }
}

int ArmstrongSayisiHesapla()//DÜZENLE
{
    int sayi,bassayisi=1,armstrong=0,uslertop,tempsayi2;
    printf("Bir sayi giriniz");
    scanf("%d",&sayi);
    int tempsayi=sayi;
    tempsayi2=sayi;
    while (tempsayi>10)
    {
        tempsayi=((tempsayi-(tempsayi%10))/10);
        bassayisi++;
    }
    while (sayi>=1)
    {
        uslertop=1;
        for (int i=0; i<bassayisi; i++)
        {
            uslertop=(sayi%10)*uslertop;
        }
        armstrong+=uslertop;
        sayi=(sayi-sayi%10)/10;
    }

    printf("Bu sayinin ustler toplami=%d.",armstrong);
    if (armstrong==tempsayi2)
    {
        printf("Bu bir armstrong sayisidir.\n");
    }
    else
    {
        printf("Bu bir armstrong sayisi degildir.\n");

    }
}

int MukemmelsayilariHesapla()
{
    int sayi,bolenlertoplami=0;
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    for(int i=1; i<=sayi/2; i++)
    {
        if(sayi%i==0)
        {
            bolenlertoplami+=i;
        }
    }
    printf("Bolenler Toplami=%d. ",bolenlertoplami);
    if(bolenlertoplami==sayi)
    {
        printf("Bu bir mukemmel sayidir.\n");
    }
    else
    {
        printf("Bu bir mukemmel sayi degildir.\n");
    }
}
int PalindromSayiHesapla()
{
    int sayi,tempsayi,kalan,palindromesayi=0i;
    printf("Lutfen bir sayi giriniz");
    scanf("%d",&sayi);
    tempsayi=sayi;
    while(sayi>=1)
    {
        kalan=sayi%10;
        palindromesayi=palindromesayi*10+kalan;
        sayi=(sayi-(sayi%10))/10;
    }
    printf("%d girdigin sayinin tersidir. ",palindromesayi);
    if(tempsayi==palindromesayi)
    {
        printf("girdigin sayi palindromedur.");
    }
    else
    {
        printf("girdigin sayi palindrome degildir.");
    }
}

int SayininAsalBolenleriHesapla()
{

    int sayi=0,ctrl=0;
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    for(int i=2; i<sayi/2; i++)
    {
        if(sayi%i==0)
        {
            ctrl=0;
            for (int j=2; j<i/2; j++)
            {
                if (i%j==0)
                {
                    ctrl=1;
                    break;
                }
            }
            if (ctrl==0)
            {
                printf("%d\n",i);
            }
        }
    }

}




int IkiSayininEbobEkokuHesapla()//Mukemmel taktir
{
    int sayi1,sayi2,tsayi1,tsayi2;
    printf("iki sayi giriniz:");
    scanf("%d %d",&sayi1,&sayi2);
    tsayi1=sayi1;
    tsayi2=sayi2;
    while(sayi1!=sayi2)
    {
        if (sayi1>sayi2)
        {
            sayi1-=sayi2;
        }
        else
        {
            sayi2-=sayi1;
        }
    }
    printf("%d Bu sayinin ebobudur\n",sayi1);

    printf("%d Bu sayinin ekokudur\n",(tsayi1*tsayi2)/sayi1);
}

int Decimalden2ve8likTabanHesapla()
{
    int tabannumber,onluksayi;
    printf("10 luk tabandan hangi tabana cevirmek istersiniz?\n1-2 lik(binary) taban\t2-8lik(oktal) taban:\n");
    scanf("%d",&tabannumber);

//Binarysayi
    if(tabannumber==1)
    {
        printf("Lutfen cevirmek 10 tabanli istediginiz sayiyi giriniz\n");
        scanf("%d",&onluksayi);
        int binaryhali=0,kalan,i=0;
        while(onluksayi!=0)
        {
            kalan=onluksayi%2;
            onluksayi=onluksayi/2;
            for(int j=0; j<i; j++)
            {
                kalan*=10;
            }
            i++;
            binaryhali+=kalan;
        }
        printf("%d\n",binaryhali);
    }
    else if(tabannumber==2)
    {
        printf("Lutfen cevirmek 10 tabanli istediginiz sayiyi giriniz\n");
        scanf("%d",&onluksayi);
        int oktalhali=0,kalan,i=0;
        while(onluksayi!=0)
        {
            kalan=onluksayi%8;
            onluksayi=onluksayi/8;
            for(int j=0; j<i; j++)
            {
                kalan*=10;
            }
            i++;
            oktalhali+=kalan;
        }
        printf("%d\n",oktalhali);
    }

    else
    {
        printf("Lutfen 1 veya 2 yi secin!\n");
    }

}

int DiziElemanToplamlari()
{
    int sayiadedi,num,top=0;
    printf("Kac sayi gireceksiniz\n");
    scanf("%d",&sayiadedi);
    int sayidizisi[sayiadedi];
    for (int i=0 ; i<sayiadedi; i++)
    {
        printf("%d .sayiyi giriniz",i+1);
        scanf("%d",&num);
        sayidizisi[i]=num;
    }
    for (int j=0 ; j<sayiadedi; j++)
    {
        top+=sayidizisi[j];
    }
    printf("sayilarin toplami:%d\n",top);
}

int DizidekiElemanSayisi()
{
    int sayiadedi;
    printf("Dizi boyutu kac olsun\n");
    scanf("%d",&sayiadedi);
    int dizi[sayiadedi];
    sayiadedi=sizeof(dizi) / sizeof(dizi[sayiadedi]);
    printf("Dizi boyutu:(Dizi buyuklugu/dizideki bir eleman buyuklugu)%d\n",sayiadedi);

}

int DizidekiEnbuyukKucukEleman()
{
    int sayiadedi,num,minsayi,maxsayi=0;
    printf("Kac sayi gireceksiniz\n");
    scanf("%d",&sayiadedi);
    int sayidizisi[sayiadedi];
    // Kullanicinin girdigi sayilar
    for (int i=0 ; i<sayiadedi; i++)
    {
        printf("%d .sayiyi giriniz",i+1);
        scanf("%d",&num);
        sayidizisi[i]=num;
    }
    for(int i=0 ; i<sayiadedi; i++)
    {
        if (minsayi>sayidizisi[i])
        {
            minsayi=sayidizisi[i];
        }
        if (maxsayi<sayidizisi[i])
        {
            maxsayi=sayidizisi[i];
        }
    }
    printf("En kucuk sayi=%d\nEn buyuk sayi=%d\n",minsayi,maxsayi);

}

int DiziyiTersCevir()
{
    int sayiadedi,num;
    printf("Kac sayi gireceksiniz\n");
    scanf("%d",&sayiadedi);
    int sayidizisi[sayiadedi],tempsayidizi[sayiadedi];
    // Kullanicinin girdigi sayilar(dizi tanimlama asamasi)
    for (int i=0 ; i<sayiadedi; i++)
    {
        printf("%d .sayiyi giriniz",i+1);
        scanf("%d",&num);
        sayidizisi[i]=num;
    }
    for (int i=0 ; i<sayiadedi; i++)
    {
        tempsayidizi[i]=sayidizisi[sayiadedi-1-i];
        printf("(%d .)sayi (Ters hali)=%d\n",i,tempsayidizi[i]);
    }

}

int HerSatirdaHarfEkle()
{
    char cumledizi[] = {"Hello world"}; //c de string yok char tanimla
    int diziboyut= sizeof(cumledizi)/sizeof(cumledizi[0]);
    for(int i=0; i<diziboyut; i++)
    {
        for(int j=0; j<i; j++)
        {

            printf("%c\n",cumledizi[j]);
        }
    }

}

int IkiDiziBirlestir()
{
    int dizi1[10]= {1,2,3,4,5,6,7,8,9,0},dizi2[10]= {1,2,3,34,5,6,67,7,8,9,0},dizitop[20];
    for (int i=0; i<10; i++)
    {
        dizitop[i]=dizi1[i];
        dizitop[10+i]=dizi2[i];
    }

    for (int i=0; i<20; i++)
    {

        printf("%d\n",dizitop[i]);
    }
    printf("Dizi birlestirildi\n");
}
int CarpimTablosu()
{
    int col,row;
    printf("Sutunu kacinci sayiya kadar carpmak istersiniz?");
    scanf("%d",&col);
    printf("satiri kacinci sayiya kadar carpmak istersiniz?");
    scanf("%d",&row);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%dx%d=%d\t",i+1,j+1,(i+1)*(j+1));
        }
        printf("\n");
    }
}
int SatirSutunBoyutHesapla()
{
    int col,row,diziboyut;
    printf("Sutunu kac olsun?");
    scanf("%d",&col);
    printf("satiri kac olsun?");
    scanf("%d",&row);
    int dizi[row][col];

    row=sizeof(dizi/*col*row*4byte*/)/sizeof(dizi/*col*4byte */[0]);
    //diziboyut=sizeof(dizi)/sizeof(row); boyut hesaplamada fakli teknik
    diziboyut=sizeof(dizi/*col*row*4byte*/)/sizeof(0/* 4byte(int) */);
    col=(diziboyut/row);/* 4byte()IRnt */;
    printf("sutun:%d/tsatir:%d/t dizide bulunan eleman sayisi:%d\n",col,row,diziboyut);

}
int IkiMatrisArasiIslemler()
{
    int Topmatris[2][4],FarkMatris[2][4],CarpimMatris[2][4];
    float BolumMatris[2][4],matris1[2][4],matris2[2][4];
    printf("Matrisler 2 satir ve 4 sutun icerir yani iki matris icin de 8 deger giriniz\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("1.Matris %d. satir ve %d. sira icin deger:",i+1,j+1);
            scanf("%f",&matris1[i][j]);
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("2.Matris %d. satir ve %d. sira icin deger:",i+1,j+1);
            scanf("%f",&matris2[i][j]);
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            Topmatris[i][j]=matris1[i][j]+matris2[i][j];
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            FarkMatris[i][j]=matris1[i][j]-matris2[i][j];
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            CarpimMatris[i][j]=matris1[i][j]*matris2[i][j];
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            BolumMatris[i][j]=matris1[i][j]/matris2[i][j];//float=int/int---> sonuc int;
        }
    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            //Eger alltaki satirda %f yerine %d yazarsak toplamaislemi vs nin de sonucu degisiyor.?       ↓ matrisler bellekte art arda siralanir %d yazarsam 32 bit yerine 4 bit kullandigi icin matris sirasi da bozulur ve anlamsiz degerler dondurur
            printf("%.3f ve %.3f\ntoplami:%d\nFarki:%d\nCarpimi:%d\nBolumu:%.3f\n",matris1[i][j],matris2[i][j],Topmatris[i][j],FarkMatris[i][j],CarpimMatris[i][j],BolumMatris[i][j]);
        }
    }

}
int SatirVeSutundakiDegerlerinAyriToplami()
{
    int matris1[2][4],satirtop=0,sutuntop=0;
    printf("Matris 2 satir ve 4 sutun icerir\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("1.Matris %d. satir ve %d. sira icin deger:",i+1,j+1);
            scanf("%d",&matris1[i][j]);
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d\t",matris1[i][j]);
            satirtop+=matris1[i][j];
        }
        printf("Satir Toplami:%d\n",satirtop);
        satirtop=0;
    }

    for(int i=0; i<4; i++)
    {

        printf("STNTOP|");
        satirtop=0;
    }
    printf("\n");

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<2; j++)
        {
            sutuntop+=matris1[j][i];
        }
        printf("%d\t",sutuntop);
        sutuntop=0;
    }
    printf("\n");
}
//Satira gor matris siralanacak toplamlarini karşilaştirabilmek icin diziye atadim devamina bak
int SatirTopSirala()
{
    int temp;
    int SatirTop[4],siralimatris[4][5],index[4]= {0,1,2,3};
    int Matris[4][5]=
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {1,1,1,1,1},
        {9,9,9,9,9}
    };
    //satir toplami
    for(int i=0; i<4; i++)
    {
        SatirTop[i]=0;
        for(int j=0; j<5; j++)
        {
            SatirTop[i]+=Matris[i][j];
        }
    }
    // indexleri satir toplamina gore sirala
    for(int i=0; i<4; i++)
    {

        for(int j=0; j<4; j++)
        {
            if(SatirTop[index[i]]>SatirTop[index[j]])
            {
                temp=index[i];
                index[i]=index[j];
                index[j]=temp;
            }
        }
    }
    // eski matrisi ve satir toplamlarini yazzdir
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d\t",Matris[i][j]);
        }
        printf("Satir toplamlari=%d",SatirTop[i]);
        printf("\n");
    }
    printf("\n\n\n\n");
    //yeni matrisi satir sirasina gore sirala
    for(int i=0; i<4; i++)
    {
        int Siralisatir = index[i];
        for(int j=0; j<5; j++)
        {
            siralimatris[i][j]=Matris[Siralisatir][j];
            printf("%d\t",siralimatris[i][j]);
        }
        printf("Satir toplamlari=%d",SatirTop[index[i]]);
        printf("\n");
    }
}
int MatrisDiagonalVeIzHesapla()
{
    int MatrisBoyutu,sayac=0,Matrisizi=0;
    printf("diagonal= soldan saga capraz degerler\nYan diagonal=sagdan sola capraz\niz= diagonal toplami\n");
    printf("Matrix alani=A X A olmali A yi giriniz:");
    scanf("%d",&MatrisBoyutu);
    int Matris[MatrisBoyutu][MatrisBoyutu];
    //Matrix olusturma ve yazdirma algoritmasi her hucreye 1 ekleyerek deger yazdirma
    for(int i=0; i<MatrisBoyutu; i++)
    {
        for(int j=0; j<MatrisBoyutu; j++)
        {
            sayac++;
            Matris[i][j]=sayac;
            printf("%d\t",Matris[i][j]);
        }
        printf("\n");
    }

    //Diagonal / yan diagonal bulma algoritmasi
    for(int i=0; i<MatrisBoyutu; i++)
    {
        printf("Ana diagonal Matris[%d][%d]=%d\n",i,i,Matris[i][i]);
        Matrisizi+=Matris[i][i];
    }
    printf("\n");
    for(int i=0; i<MatrisBoyutu; i++)
    {
        printf("Yan diagonal Matris[%d][%d]=%d\n",i,i,Matris[i][MatrisBoyutu-1-i]);
    }
    printf("Matris izi=%d\n",Matrisizi);

}
int MatrisTranspozHesapla()
{
    printf("Transpoz= matrisin satir ve sutun boyutunu yer degistirir\n");
    int col,row,sayac=0;
    printf("Sirayla satir ve sutun sayisini giriniz:");
    scanf("%d%d",&row,&col);
    int Matris[row][col],TersMatris[col][row];
    //Matrix olusturma ve yazdirma algoritmasi her hucreye 1 ekleyerek deger yazdirma
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            sayac++;
            Matris[i][j]=sayac;
            printf("%d\t",Matris[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //Matris Transpoz olusturma ve yazdirma
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            TersMatris[i][j]=Matris[j][i];
            printf("%d\t",TersMatris[i][j]);
        }
        printf("\n");
    }
}
int MatrisDondurme()
{
    int col,row,sayac=0;
    printf("Sirayla satir ve sutun sayisini giriniz:");
    scanf("%d%d",&row,&col);
    int Matris[row][col],DonenMatris[col][row];
    //Matrix olusturma ve yazdirma algoritmasi her hucreye 1 ekleyerek deger yazdirma
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            sayac++;
            Matris[i][j]=sayac;
            printf("%d\t",Matris[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //Matris Transpoz olusturma ve yazdirma
    for(int i=0; i<col; i++)
    {
        for(int j=0; j<row; j++)
        {
            DonenMatris[i][j]=Matris[row-1-j][i];
            printf("%d\t",DonenMatris[i][j]);
        }
        printf("\n");
    }
}
int SpiralMatris()
{
    int boyut;
    printf("Matris boyutunu girin (NxN icin N): ");
    scanf("%d", &boyut);

    int matris[boyut][boyut];
    int spiral[boyut][boyut];

    // Kullanicidan matris elemanlarini alma
    printf("Matrisin elemanlarini giriniz:\n");
    for (int i = 0; i < boyut; i++)
    {
        for (int j = 0; j < boyut; j++)
        {
            printf("Matris[%d][%d]: ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }

    // Spiral dizilim icin gerekli sinirlar ve yonler
    int basSatir = 0, sonSatir = boyut - 1;
    int basSutun = 0, sonSutun = boyut - 1;
    int sayac = 0;//----->dongu icinde (sayac/boyut)=satir(row)(sayac%boyut)=sutun(col)

    while (basSatir <= sonSatir && basSutun <= sonSutun)
    {
        // → saga git--MANTIK--> başlangic satiri sabit / sutun artiyor / baslangic satiri 1 artiyor
        for (int i = basSutun; i <= sonSutun; i++) //---> hangi sutundan başlayip hangisinde bitecegini belirliyor
            spiral[basSatir][i] = matris[sayac / boyut][sayac % boyut], sayac++;//-->soldan saga matris sirasi ile ilerliyor
        basSatir++;

        // ↓ aşagiya git--MANTIK-->  son sutun sabit / son satir artiyor / son sutun 1 azaliyor
        for (int i = basSatir; i <= sonSatir; i++)
            spiral[i][sonSutun] = matris[sayac / boyut][sayac % boyut], sayac++;
        sonSutun--;

        // ← sola git --MANTIK--> son satir sabit/ son sutun azaliyor /son satir 1 azaliyor
        if (basSatir <= sonSatir)
        {
            for (int i = sonSutun; i >= basSutun; i--)
                spiral[sonSatir][i] = matris[sayac / boyut][sayac % boyut], sayac++;
            sonSatir--;
        }

        // ↑ yukariya git--MANTIK--> baslangic sutunu sabit/ baslangic satiri artiyor/ baslangic sutunu 1 artiyor
        if (basSutun <= sonSutun)
        {
            for (int i = sonSatir; i >= basSatir; i--)
                spiral[i][basSutun] = matris[sayac / boyut][sayac % boyut], sayac++;
            basSutun++;
        }
    }

    // Spiral matrisi yazdir
    printf("\nSpiral Matris:\n");
    for (int i = 0; i < boyut; i++)
    {
        for (int j = 0; j < boyut; j++)
        {
            printf("%3d ", spiral[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int RecursiveFonksiyonMenu()
{
    int MenuNumber,Sayi,Sonuc,UygulamaNumarasi,Sayi2;
    int Dizisayisi=20;
    int Sayidizisi[20];
    while(UygulamaNumarasi!=0)
    {
        printf("1. Recursive Faktoriyel Hesapla\n.");
        printf("2. Recursive Olarak Fibonacci Serisini Hesapla\n");
        printf("3. Recursive Sekilde Dizinin Toplamini Hesapla\n");
        printf("4. Ozyinelemeli Olarak Bir Sayinin Basamaklarinin Toplamini Bul\n");
        printf("5. Recursive Olarak Kombinasyon (nCr) Hesapla\n");
        printf("6. Recursive Olarak Permutasyon (nPr) Hesapla\n");
        printf("7. Ozyinelemeli Asal Kontrolu Yap\n");
        printf("8. Ozyinelemeli Olarak EBOB Hesapla (Euclid Algoritmasi)\n");
        printf("9. Ozyinelemeli Olarak EKOK Hesapla (Euclid Algoritmasi)\n");

        printf("Lutfen sectiginiz numarayi giriniz:");
        scanf("%d",&MenuNumber);
        if(MenuNumber!=3)
        {
            printf("Hesaplamak istediginiz sayiyi giriniz:");
            scanf("%d",&Sayi);
            Sayi2=Sayi/2;
        }
        else if(MenuNumber==3)
        {

            printf("kac sayi girmek istersiniz(Max 20 olmali)");
            scanf("%d",&Dizisayisi);
            for (int i=0; i<Dizisayisi; i++)
            {
                printf("sayiyi giriniz:",i+1);
                scanf("%d",&Sayi);
                Sayidizisi[i]=Sayi;
            }
        }
        if(MenuNumber==5||MenuNumber==6||MenuNumber==8||MenuNumber==9)
        {
            printf("Ikinci sayiyi giriniz:");
            scanf("%d",&Sayi2);
        }

        switch(MenuNumber)
        {
        case 1:
            Sonuc = FaktoriyelRecursive(Sayi);
            break;
        case 2:
            Sonuc = FibonacciRecursive(Sayi);
            break;
        case 3:
            Sonuc = DiziToplamiRecursive(Sayidizisi,Dizisayisi);
            break;
        case 4:
            Sonuc=BasamakToplamiRecursive(Sayi);
            break;
        case 5:
            Sonuc=KombinasyonRecursive(Sayi,Sayi2);
            break;
        case 6:
            Sonuc=PermutasyonRecursive(Sayi,Sayi2);
            break;
        case 7:
            Sonuc=AsalKontrolRecursive(Sayi,Sayi2);
            break;
        case 8:
            Sonuc=EbobHesapRecursive(Sayi,Sayi2);
            break;
        case 9:
            Sonuc=EkokHesapRecursive(Sayi,Sayi2);
            break;
        default:
            printf("Lutfen 1 ve 8 arasinda bir sayi giriniz:");
            break;
        }
        printf("%d\n",Sonuc);
        printf("Ana menuye donmek icin 0'a /tekrar islem yapmak icin herhangi bir sayiya basiniz ");
        scanf("%d",&UygulamaNumarasi);
        system("cls");
    }
}
FaktoriyelRecursive(int num1)
{
    if (num1==0 || num1==1)
        return 1;
    else
    {
        return num1*FaktoriyelRecursive(num1-1);
    }


}
int FibonacciRecursive(int num1)
{
    if (num1==0)
        return 0;
    else if(num1==1)
        return 1;

    return FibonacciRecursive(num1-1)+FibonacciRecursive(num1-2);
}
int BasamakToplamiRecursive(int num1)
{
    if (num1<=0)
        return 0;
    else
    {
        return (num1%10+BasamakToplamiRecursive(num1/10));
    }
}

int KombinasyonRecursive(num1,num2)
{
    if (num2==0||num2==num1)
    {
        return 1;
    }
    else
    {
        return KombinasyonRecursive(num1-1,num2-1)+KombinasyonRecursive(num1-1,num2);
    }

}
int PermutasyonRecursive(num1,num2)
{
    return FaktoriyelRecursive(num1)/FaktoriyelRecursive(num1-num2);// Bunun recursive halini araştıracağim
}
int AsalKontrolRecursive(num1,asalctrl)
{
    if (num1%asalctrl!=0 && asalctrl>=1)
    {
        return printf("bu sayi asaldir");

    }
    else if(num1%asalctrl==0 && asalctrl>=1)
    {
        return puts("Bu sayi Asal degildir");
    }
    else
    {
        return AsalKontrolRecursive(num1,asalctrl-1);
    }
}
int DiziToplamiRecursive(int Sayidizisi[],int boyut)
{
    if(boyut==0)
        return 0;
    return Sayidizisi[boyut-1]+DiziToplamiRecursive(Sayidizisi,boyut-1) ;

}

int EbobHesapRecursive(num1,num2)
{
    if (num2==0)
    {
        return num1;
    }
    else
    {
        return EbobHesapRecursive(num2,num1%num2);
    }
}
int EkokHesapRecursive(num1,num2)
{
    return num1*num2/EbobHesapRecursive(num1,num2);

}

void KullaniciVerisiniDosyayaYaz()
{
    FILE * fptr;
    fptr=fopen("KullaniciVerileri.txt","w+");

    if(!fptr)
    {
        perror("Dosya Acilamadi Uygulama Kapaniyor:");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Dosya Acildi.");
    }
    int KullaniciSayisi;
    char kullaniciAdi[50];
    char KullaniciYasi[10];
    char KullaniciSifre[20];
    printf("Kac kisilik veri girmek istersiniz:");
    scanf("%d", &KullaniciSayisi);
    while (getchar() != '\n');  // Buffer temizleme

    for (int i = 1; i <= KullaniciSayisi; i++)
    {
        fprintf(fptr, "%d . kullanici \n{\n", i);

        printf("\nKullanici adi giriniz:");
        fprintf(fptr, "İsim=");
        fgets(kullaniciAdi, sizeof(kullaniciAdi), stdin);
        kullaniciAdi[strcspn(kullaniciAdi, "\n")] = '\0';
        fputs(kullaniciAdi, fptr);

        printf("Kullanici Yasini giriniz (Max 3 Basamaklı):");
        fprintf(fptr, "\nYas=");
        fgets(KullaniciYasi, sizeof(KullaniciYasi), stdin);
        KullaniciYasi[strcspn(KullaniciYasi, "\n")] = '\0';
        fputs(KullaniciYasi, fptr);

        printf("Kullanici sifresi giriniz (Max 8 Basamaklı):");
        fprintf(fptr, "\nSifre=");
        fgets(KullaniciSifre, sizeof(KullaniciSifre), stdin);
        KullaniciSifre[strcspn(KullaniciSifre, "\n")] = '\0';
        fputs(KullaniciSifre, fptr);

        fprintf(fptr, "\n}\n");
    }

    fclose(fptr);
}

void DosyaSatirSayisiBul()
{
    char ch;
    int satirSayisi = 0;
    FILE * fptr;
    fptr=fopen("KullaniciVerileri.txt","r");

    if(!fptr)
    {
        perror("Dosya Acilamadi Uygulama Kapaniyor:");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Dosya Acildi.");
    }
    while((ch=fgetc(fptr))!=EOF)
    {
        if (ch=='\n')
        {
            satirSayisi++;
        }

    }
    printf("satir sayisi = %d",satirSayisi);
    fclose(fptr);
}
