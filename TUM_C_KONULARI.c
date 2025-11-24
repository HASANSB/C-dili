
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TumKodlar.h"
 //KENDİ KÜTÜPHANEN ICIN
 //sol üstte file / new file/ file../c hc++ headere tikla ve sonra fonksiyonlari yazdiktan sonra ctrl + s yap
    //#include "deneme.h" yaz ve çaliştir

int main()
{
    int secim;

    do{

    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("*                                     C PROGRAMLAMA DILI KONULARI                                          *\n");
    printf("*                                     ___________________________                                          *\n");
    printf("*   1-Adlandirma kurallari:                                                                                *\n");
    printf("*   2-Degiskenler & Veri Tipleri:                                                                          *\n");
    printf("*   3-Operatorler: Aritmetik, mantiksal, bitsel islemler                                                   *\n");
    printf("*   4-Kosul Ifadeleri: if-else, switch-case                                                                *\n");
    printf("*   5-Donguler: for, while, do-while                                                                       *\n");
    printf("*   6-Fonksiyonlar: Parametreler, return degerleri ve ozyineleme kavrami                                   *\n");
    printf("*   7-Diziler                                                                                              *\n");
    printf("*   8-Stringler: Null-terminated strings, strcpy/strcmp                                                    *\n");
    printf("*   9-Pointer Temelleri: Adres operatoru (&), dereferencing (*),dizi string ve fonksiyonla bagli pointerlar*\n");
    printf("*   10-Struct veri gruplama typedef kullanimi/union ve enum                                                *\n");
    printf("*   11-Dinamik Bellek Yonetimi: malloc, calloc, realloc, free                                              *\n");
    printf("*   12-Dosya Islemleri: fopen, fread, fwrite, fclose                                                       *\n");
    printf("*   13-Preprocessor Direktifleri: #define, #include, #ifdef                                                *\n");
    printf("*   14-Const ve Volatile Kavramlari                                                                        *\n");
    printf("*   15-Cikis                                                                                               *\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t LUTFEN HANGI KONU OZETINE BAKMAK ISTEDIGINIZI SECIN.");
    scanf("%d",&secim);
    system("cls");
    switch(secim)
    {
        case 1:AdlandirmaKurallari();break;
        case 2:Degiskenler_veriTipleri();break;
        case 3:Operatorler();break;
        case 4:Kosullar();break;
        case 5:Donguler();break;
        case 6:Fonksiyonlar(); break;
        case 7:Diziler();break;
        case 8: Stringler();break;
        case 9:pointerlar();
               pointerlar2();
               pointerlar_ve_String();break;
        case 10:struct_union_enum();break;
        case 11:Dinamik_Bellek_Yonetimi();break;
        case 12:Dosya_islemleri();break;
        case 13:Prepocessor_Direktifleri();break;
        case 14:Const_Volatile();break;
        case 15:return 0;break;
        default:printf("Lutfen 1 ve 14 arasi islem yapiniz");break;
}} while(1);

    return 0;
}



// Fonksiyon tanimi
void AdlandirmaKurallari() {
    printf("\n---------- Adlandirma Kurallari ----------\n");
    printf("1. camelCase        -> myGreatVariableName\n");
    printf("2. snake_case       -> my_great_variable_name\n");
    printf("3. PascalCase       -> MyGreatVariableName\n");
    printf("4. Cobra_Case       -> My_Great_Variable_Name\n");
    printf("5. UPPER_SNAKE_CASE -> MY_GREAT_VARIABLE_NAME\n\n");
    printf("->  Degisken ve fonksiyon isimlerinde genellikle snake_case,\n");
    printf("->  Sabitler ve makrolarda ise UPPER_SNAKE_CASE kullanilir.\n\n\n\n\n");
    printf("\nDevam etmek icin ENTER tusuna basin...\n");
    getchar(); // scanf'ten kalan '\n' temizlenir
    getchar(); // kullanici ENTER'a basar
}
void Degiskenler_veriTipleri(){
    printf("\n--- DEGISKENLER & VERI TIPLERI OZETI ---\n\n");

    // 1) INT (Tam Sayilar)
    int sayi = 42;
    printf("int sayi = 42 --> Degeri: %d (Bellekte 4 byte)\n", sayi);

    // 2) FLOAT (Virgullu sayilar - 6 basamak duyarlilik)
    float oran = 3.14159f;
    printf("float oran = 3.14159f  --> Degeri: %f (Bellekte 4 byte)\n", oran);

    // 3) DOUBLE (Daha hassas virgullu sayi - 15 basamak duyarlilik)
    double pi = 3.1415926535;
    printf("double pi = 3.1415926535  --> Degeri: %.10lf (Bellekte 8 byte)\n", pi);

    // 4) CHAR (Karakterler)
    char harf = 'A';
    printf("char harf = 'A'  --> Karakter: %c | ASCII Degeri: %d\n", harf, harf);

    //char dizisi tanimlama; cift tirnak kullanilir
    char karakter_dizisi1[]="Merhaba dunya\n";
    printf("%s\n",karakter_dizisi1);
    //tek tek karakter de tanimlayabiliriz ama sonuna{ \0} koyulmali
    //KOYULMAZSA yazdiracagin zaman/0 a kadar devam eder
    char karakter_dizisi2[]={'M','e','r','h','a','b','a',' ','d','u','n','y','a'};
    printf(" %s\n",karakter_dizisi2);
    //{ \0} KOYULURSA
    char karakter_dizisi3[]={'M','e','r','h','a','b','a',' ','d','u','n','y','a','\0'};
        printf(" %s\n",karakter_dizisi3);
    printf("\n Bu uc karakter dizisinin boyutu \n 1- karakter dizisi 1' in boyutu %lu \n 2- karakter dizisi 2nin boyutu = %lu \n 3- karakter dizsi 3'un boyutu %lu\n",sizeof(karakter_dizisi1),sizeof(karakter_dizisi2),sizeof(karakter_dizisi3) );
    // çşö gibi yazilimda olmayan harfler 2 karakterle belirtilir bu yuzden 2 karakterlik yerkaplarlar
    //eger dizi bos olmayip da [x] olarak boyut verilirse boyut x olur bos yerleri kendisi doldurur ve x ten fazla karakter almaz

    //strcat kodu: x ve y olarak 2 string alir ve y yi x in basina ekleyerek bunu x e kaydeder
    //strcat(karakter_dizisi1, karakter_dizisi3);
    //strcopy x ve y olarak 2 string deger alir y nin icerigini x e kopyalar
    //strcpy(karakter_dizisi1,karakter_dizisi2);
    //strcmp x ve y olarak 2 string alir ve aralarindaki karakter sayisi fark yazdirir
    //strcmp(karakter_dizisi1,karakter_dizisi2);
    //DIKKAT: Bu 3 fonksiyonda boyutlar onemlidir yoksa buffer olabilir.
    //string de kullanilan kodlar

    /*
    1-\n bir alt satira gecer
    2-\t tab tusuna basilmis gibi davranir
    3-\0 sonlandirma karakteri bundan sonraki karakteri algilamaz koyulmazsa bellekten rastgele karakter alir
    4-\" cift tirnak isareti ekler
    5-\' tek tirnak isareti ekler
    6-\% yuzde isareti ekler
    7-\\ "\" isareti ekler
    8-\a bir ses ekler
    */

    // HATA 1: Ondalik sayiyi int'e atama - veri kaybi
    float ondalik = 7.8;
    int hatali_int = ondalik;
    printf("HATA 1: Ondalik sayiyi int'e atama - veri kaybi=>float ondalik = 7.8  int hatali_int = ondalik  --> hatali_int: %d (7 olur, .8 kaybolur)\n", hatali_int);

    // HATA 2: float okurken %f yerine %d yazmak
    float input;
    printf("HATA 2: float okurken %f yerine %d yazmak=>Bir ondalikli sayi girin (nokta kullanin): ");
    scanf("%f", &input);
    printf("Girilen float degeri: %.2f\n", input);

    // HATA 3: char degere cift tirnak kullanmak
    char karakter = 'Z'; // Dogru: tek tirnak
    printf("HATA 3: char degere cift tirnak kullanmak=>Dogru char tanimi --> karakter: %c\n\n float sonuc2 = (float)x / y;  Dogru, 2.5\n", karakter);

    // HATA 4: Tam sayi bolme sonucu dikkatli kullanilmalidir
    printf("HATA 4: Tam sayi bolme sonucu dikkatli kullanilmalidir\n");
    int x = 5, y = 2;
    float sonuc1 = x / y;         // Yanlis, 2.5 degil 2
    float sonuc2 = (float)x / y;  // Dogru, 2.5

    printf("int/int sonucu: %f (Yanlis)\n", sonuc1);
    printf("(float)int/int sonucu: %f (Dogru)\n", sonuc2);

    printf("\n--- ONEMLI NOTLAR ---\n");
    printf("1. float sayilar icin scanf ve printf'te %f kullanin\n");
    printf("2. int/int bolme sonucu tamsayi olur, float yapmak icin cast kullanin\n");
    printf("3. char icin tek tirnak kullanin: char c = 'A';\n");
    printf("4. float yerine double daha dogru sonuc verir\n");
    printf("5. scanf'de tipler uyumlu olmalidir, aksi halde hata olur\n");

    printf("\nDevam etmek icin ENTER tusuna basin...\n");
    getchar(); // scanf'ten kalan '\n' temizlenir
    getchar(); // kullanici ENTER'a basar
}

void Operatorler(){
    int a = 5, b = 2;
    float x = 5.0, y = 2.0;
    int flag = 0;

    printf("----- Operatorler Ozeti ve Onemli Noktalar -----\n\n");

    // Aritmetik
    printf("Toplama: %d + %d = %d\n", a, b, a+b);

    printf("Cikarma: %d - %d = %d\n", a, b,a-b);

    printf("Carpma: %d * %d = %d\n", a, b, a*b);

    printf("Bolme (tam sayi): %d / %d = %d\n", a, b,a/b);

    printf("Modul (kalan): %d %% %d = %d\n", a, b, a%b);

    // NOT: Modül operatörü float/double ile kullanilamaz.
    // float mod = x % y; // HATA

    // Atama vs Karşilaştirma
    if (a == 5) {
        printf("a, 5'e esittir (== dogru kullanim).\n");
    }

    // if (a = 3) {  // DİKKAT: atama operatoru, asla if icinde kullanma!
    //    printf("Bu yanlis! atama yapar, sart degil.\n");
    //}

    // Artirma / Azaltma farklari
    printf("a su an %d\n", a);
    printf("Postfix artirma a++ : %d\n", a++);  // önce yazdirir sonra artirir
    printf("Simdi a: %d\n", a);
    printf("Prefix artirma ++a : %d\n", ++a);   // önce artirir sonra yazdirir
    printf("Simdi a: %d\n", a);

    // Mantiksal operatörler
    flag = (a > 5) && (b < 5); // true && true = true (1)
    printf("Mantiksal AND sonucu: %d\n", flag);

    flag = (a > 10) || (b < 5); // false || true = true (1)
    printf("Mantiksal OR sonucu: %d\n", flag);

    // Bitwise operatörler
    a = 5;  // 0101
    b = 3;  // 0011
    printf("Bitwise AND a & b: %d\n", a & b); // 0001 = 1
    printf("Bitwise OR a | b: %d\n", a | b);  // 0111 = 7
    printf("Bitwise XOR a ^ b: %d\n", a ^ b); // 0110 = 6
    printf("Bitwise NOT ~a: %d\n", ~a);       // tüm bitleri tersler

    // Kaydirma (shift) operatörleri
    printf("a << 1 (sola kaydirma): %d\n", a << 1); // 0101 -> 1010 (10 decimal)
    printf("a >> 1 (saga kaydirma): %d\n", a >> 1); // 0101 -> 0010 (2 decimal)

    printf("\nNot: Atama '=' ile karsilastirma '==' farklidir.\n");
    printf("Modul '%%' operatörü sadece tam sayilarla kullanilir.\n");
    printf("Artirma/Azaltma prefix/postfix farklarini dikkatli kullan.\n");
    printf("Bitwise '&' ile mantiksal '&&' karistirmayiniz.\n");

}
void Kosullar(){
    printf("\n--- KOSULLAR (IF-ELSE & SWITCH) OZETI ---\n\n");

    printf("1) If-Else:\n");
    printf("if (kosul) { ... } else { ... }\n");
    printf("Kosul TRUE ise if blogu, FALSE ise else blogu calisir.\n\n");

    printf("2) Else If:\n");
    printf("Birden fazla kosulu sirayla kontrol eder.\n\n");

    printf("3) Switch-Case:\n");
    printf("Degiskenin sabit degerlerine gore durumlari kontrol eder.\n");
    printf("break kullanilmazsa \"fall-through\" olur.\n\n");

    printf("4)Ternary\n");
    printf("Ternary ile atama====>>>int max = (a > b) ? a : b;");

    printf("5) Hatalar ve Dikkat Edilecekler:\n");
    printf("- '=' ve '==' karistirmayin.\n");
    printf("- Switch-case'de break unutmayin.\n");
    printf("- {} parantezlerini coklu satirlar icin kullanin.\n");
    printf("- Switch sadece int, char, enum ile kullanilir.\n");
    printf("- Kosullar 0 disi her seyi TRUE sayar.\n");

}
void Donguler(){

    printf("---------- DONGULER KONUSU OZETI VE SIK YAPILAN HATALAR ----------\n\n");

    // 1. For döngüsü temel yapisi
    printf("1. For dongusu ornegi:\n");
    printf("   for(int i = 0; i < 5; i++) { /* islem */ }\n\n");

    // En cok hata: Döngü kontrol koşulunun yanliş yazilmasi veya sonsuz döngü
    printf("   Hata: i <= 5 yazarsan 6 kez doner, bazen istenmeyen durum.\n");
    printf("   Sonsuz dongu ornegi:\n");
    printf("   for(int i = 0; i >= 0; i++) { /* sonsuz dongu */ }\n\n");

    // 2. While döngüsü ve hatalar
    printf("2. While dongusu ornegi:\n");
    printf("   int i = 0;\n");
    printf("   while(i < 5) {\n");
    printf("       /* islem */\n");
    printf("       i++; // Bunu unutma, yoksa sonsuz dongu olur!\n");
    printf("   }\n\n");

    printf("   Hata: i++ unutulursa, sonsuz dongu olusur.\n\n");

    // 3. Do-while döngüsü ve farki
    printf("3. Do-While dongusu ornegi:\n");
    printf("   int i = 0;\n");
    printf("   do {\n");
    printf("       /* islem */\n");
    printf("       i++;\n");
    printf("   } while(i < 5);\n\n");

    printf("   Not: Do-while en az bir kere calisir.\n\n");

    // 4. Döngüde index hatalari
    printf("4. Diziyle dongu ornegi ve hata:\n");
    printf("   int arr[5] = {1,2,3,4,5};\n");
    printf("   for(int i = 0; i <= 5; i++) {\n");
    printf("       printf(\"%%d\", arr[i]); // i <= 5 yerine i < 5 olmali!\n");
    printf("   }\n");
    printf("   Hata: i 5 olunca arr[5] sinir disi, bellek hatasi!\n\n");

    // 5. Break ve continue kullanimi
    printf("5. Break ve continue:\n");
    printf("   for(int i = 0; i < 10; i++) {\n");
    printf("       if(i == 5) break;    // donguyu sonlandirir\n");
    printf("       if(i % 2 == 0) continue; // cift sayilari atlar\n");
    printf("       printf(\"%%d \", i); // sadece tek sayilari yazdirir\n");
    printf("   }\n\n");

    printf("   Hata: continue'dan sonra kod varsa calismaz, dikkat!\n\n");

    // 6. Sonsuz döngüye dikkat
    printf("6. Sonsuz dongu ornegi:\n");
    printf("   while(1) {\n");
    printf("       // break kullanmazsan sonsuz dongu olur\n");
    printf("   }\n\n");

    printf("-----------------------------------------------------------------\n");
}
void Fonksiyonlar(){
    // Fonksiyonun genel yapisi:
// dönüş_tipi fonksiyon_adi(parametre_tipi parametre_adi, ...) {
//     // Fonksiyonun işlemleri
//     return deger;  // Eger dönüş tipi void degilse return zorunlu
// }

// Önemli noktalar:
// 1) Return: Fonksiyonun işlem sonucunu çagiran yere geri gönderir.
// 2) Parametreler: Fonksiyona dişaridan veri gönderilir, tür ve sayi uyumlu olmali.
// 3) Özyineleme (recursive): Fonksiyon kendini çagirir. Sonsuz çagri olmamasi için mutlaka "baz durum" olmali.

}
void Diziler(){

printf("---------- DIZILER KONUSU OZET VE HATALAR ----------\n");

    // :) Tanimlama ve Başlatma
    int sayilar1[5] = {1, 2, 3, 4, 5};         // dogru
    int sayilar2[]  = {10, 20, 30};            // boyut belirtmeden de olur
    int sayilar3[5] = {1};                     // 1. elemanı sen belirlersin(1 belirledin) digerleri 0 olur
    //   HATA: Aşagidaki hatalidir
    // int hataliDizi[3] = {1, 2, 3, 4};       // Fazla eleman

    // :) Elemanlara erişim
    printf("sayilar3[0] = %d\n", sayilar3[0]);   // 1. eleman
    printf("sayilar3[4] = %d\n", sayilar3[4]);   // son eleman

    //   HATA: Geçersiz indeks
    // printf("%d", sayilar1[5]);              // dizi boyutunu aşma (Undefined Behavior)

    // :) Dizi ile döngü
    for (int i = 0; i < 5; i++) {
        printf("sayilar1[%d] = %d\n", i, sayilar1[i]);
    }

    //   HATA: i <= 5 kullanirsan dizi dişina çikarsin!
    // for (int i = 0; i <= 5; i++) { ... }

    // :) Kullanicidan veri alma
    int input[3];
    for (int i = 0; i < 3; i++) {
        printf("Sayi giriniz: ");
        scanf("%d", &input[i]);
    }

    //   HATA: &input yerine input yazarsan yanliş olur!
    // scanf("%d", input[i]);  // HATA!

    // :) Dizileri fonksiyona parametre olarak geçirme
    void yazdir(int d[], int boyut);
    printf(sayilar1, 5);

    //   HATA: Boyutu fonksiyonda belirtmezsen karişiklik olur
    // Fonksiyona dizinin boyutunu da gönder!

    // :) Çok boyutlu diziler
    int matris[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("matris[1][2] = %d\n", matris[1][2]);  // 6

    //   HATA: matris[2][0] -> index taşmasi çünkü 2 ve 3 dahil degil


    // :) Diziler ve pointer ilişkisi
    int dizi[] = {100, 200, 300};
    int *ptr = dizi;
    printf("*(ptr+1) = %d\n", *(ptr+1));
    printf("ptr[1] = %d\n", ptr[1]);         // 200(aslında şu demek: *(ptr + 1))
    printf("*(ptr + 2) = %d\n", *(ptr + 2)); // 300

    //   HATA: Diziyi yanliş pointer ile degiştirme
    // ptr = ptr + 10; printf("%d", *ptr);   // geçersiz erişim 3 eleman var

    // :) Karakter dizileri (string)
    char isim[] = "hasan";
    printf("isim: %s\n", isim);

    //   HATA: Null karakteri (\0) unutma!
    char hataliIsim[5] = {'h', 'a', 's', 'a', 'n'}; // eksik: '\0' yok

    // :) Dizi kopyalama (string)
    char kopya[10];
    strcpy(kopya, isim);

    //   HATA: strcpy ile hedef dizinin boyutu yetersizse taşma olur!
    // char kucuk[3]; strcpy(kucuk, isim); // HATA

    // :) Dizi boyutu makrolarla tanimlanabilir
    #define BOYUT 4
    int d[BOYUT] = {1,2,3,4};

    //   HATA: Sabit olmayan boyutta dizi C89’da(eskis sürüm) tanimlanamaz
    // int n; scanf("%d", &n); int a[n];  // C99 sonrasi olur, ama C89’da geçersiz



    printf("---------------------------------------------------\n");}
void Stringler(){
    // 🔹 1. Null-terminated olmayan string hatasi
    char not_terminated[5] = {'H', 'e', 'l', 'l', 'o'}; // '\0' yok!
    printf("HATA-1 (Null yok): %s\n", not_terminated); // Tanimsiz davraniş

    // 🔹 2. String tanimi - Dogru tanim
    char proper1[] = "Merhaba";          // Otomatik '\0' eklenir
    char proper2[8] = "Merhaba";         // '\0' dahil 8 karakterlik yer
    char proper3[20];                    // Elle doldurulabilir

    // 🔹 3. strcpy hatasi - Yetersiz alan
    char target1[5];
    // strcpy(target1, "UzunKelime");   // HATA: Buffer overflow (komut satirinda çöker)

    // 🔹 4. strcpy dogru kullanim
    char target2[20];
    strcpy(target2, "Kisa");
    printf("Dogru strcpy: %s\n", target2);

    // 🔹 5. strcpy kendine kopyalama
    char example[20] = "Ornek";
    strcpy(example, example); // Geçerli ama gereksiz

    // 🔹 6. strcmp örnegi
    char a[] = "abc";
    char b[] = "abc";
    char c[] = "ABC";

    if (strcmp(a, b) == 0)
        printf("strcmp: a ve b eşit\n");
    else
        printf("strcmp: a ve b farkli\n");

    if (strcmp(a, c) == 0)
        printf("strcmp: a ve c eşit\n");
    else
        printf("strcmp: a ve c farkli (case-sensitive)\n");

    // 🔹 7. strcmp yerine strcasecmp (GNU)
    if (strcasecmp(a, c) == 0)
    printf("Buyuk-kucuk harf duyarsiz esitlik\n");

    // 🔹 8. fgets kullanimi ve '\n' temizleme
    char input[50];
    getchar();
    printf("Bir sey girin: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // '\n' varsa temizle
    printf("Girdiniz: %s\n", input);
    int temizle;
    while((temizle = getchar())!='\n'|| c!=EOF);//bu Yöntem en profesyonel yöntemdir.

    // 🔹 9. strcat hatali kullanim
    char dest[10] = "A";
    // strcat(dest, "UzunMetin"); // HATA: hedefte yeterli alan yok

    // 🔹 10. strcat dogru kullanim
    char full[20] = "Mer";
    strcat(full, "haba");
    printf("strcat sonucu: %s\n", full);

    // 🔹 11. strlen hatasi
    char s[] = "Kelime";
    printf("strlen: %zu\n", strlen(s)); // '\0' dahil degildir

    // 🔹 12. malloc ile string - Unutulan '\0'
    char *dyn = malloc(6); // "Hello" için 5 + 1
    strcpy(dyn, "Hello");
    printf("Dinamik: %s\n", dyn);
    free(dyn);

    // 🔹 13. strcpy ile self-overlap (Tanimsiz Davraniş)
    char overlap[10] = "abcdef";
    // strcpy(overlap+2, overlap); // Tanimsiz davraniş

}

double ptrilekareHEsapla( double *ptr)
{
return *ptr * *ptr;
}
void pointerlar(){//POINTERLAR
    int a=1,b=2,c=3,*ptr,top=0;

    ptr=&a;//ptr artık an  nın adresini gösterecek
    printf("a nin adresi %p\n",&a);
    printf("a nin degeri %d\n",a);
    printf("b nin adresi %p\n",&b);
    printf("b nin degeri %d\n",b);
    printf("c nin adresi %p\n",&c);
    printf("c nin degeri %d\n\n",c);
    printf("ptr nin adresi %p\n",&ptr);
    printf("ptr nin degeri %p\n",ptr);
    printf("ptr nin adresindeki deger %d\n",*ptr);

    b=*ptr;// b artık a ile aynı
    printf("\na nin adresi %p\n",&a);
    printf("a nin degeri %d\n",a);
    printf("b nin adresi %p\n",&b);
    printf("b nin degeri %d\n",b);
    printf("ptr nin adresi %p\n",&ptr);
    printf("ptr nin degeri %p\n",ptr);
    printf("ptr nin adresindeki deger %d\n\n",*ptr);

    *ptr=c; // ptrnin adresindeki deger artık c degeri ile aynı
    printf("a nin adresi %p\n",&a);
    printf("a nin degeri %d\n",a);
    printf("b nin adresi %p\n",&b);
    printf("b nin degeri %d\n",b);
    printf("c nin adresi %p\n",&c);
    printf("c nin degeri %d\n",c);
    printf("ptr nin adresi %p\n",&ptr);
    printf("ptr nin degeri %p\n",ptr);
    printf("ptr nin adresindeki deger %d\n\n",*ptr);

    ptr=&b;
    printf("a nin adresi %p\n",&a);
    printf("a nin degeri %d\n",a);
    printf("b nin adresi %p\n",&b);
    printf("b nin degeri %d\n",b);
    printf("c nin adresi %p\n",&c);
    printf("c nin degeri %d\n",c);
    printf("ptr nin adresi %p\n",&ptr);
    printf("ptr nin degeri %p\n",ptr);
    printf("ptr nin adresindeki deger %d\n\n",*ptr);

//-------------------------------------------------------------------------------------------------------------------------------------
//pointer kullanarak toplama işlemi
    top=*ptr+*ptr;
    printf("pointer ile toplama islemi (b+b) = %d\n",top);
//deger degistirme
    a=0;
    b=1;
    int *pa,*pb;
    pa=&a;
    pb=&b;
    printf("\n%d a\n%d b\n%d pa\n%d pb\n",a,b,*pa,*pb);
    int temp=*pa;
    *pa=*pb;
    *pb=temp;
    printf("\n%d a\n%d b\n%d pa\n%d pb\n",a,b,*pa,*pb);

    //pointerlara ekleme cikarma
    //pointerlara sadece toplama cikarma bir artirma ve bir eksiltme işlemleri yapilir(+,-,++,--)
    int nt=1,* ptrint;
    ptrint=&nt;
    char ch='k',*ptrchr;
    ptrchr=&ch;
    double dbl = 3.146766887668687678687687, *ptrdbl;
    ptrdbl = &dbl;

    printf("ptrint nin adresi%d\n",ptrint);
    printf("ptrchr nin adresi%d\n",ptrchr);
    printf("ptrdbl nin adresi%d\n",ptrdbl);
    printf("ptrint=%d\nptrchr=%c\nptrdbl=%lf\n",*ptrint,*ptrchr,*ptrdbl);
    ptrint++;
    ptrchr++;
    ptrdbl++;
    printf("++ sonrasi ptrint nin adresi%d\n",ptrint);//4 artti
    printf("++ sonrasi ptrchr nin adresi%d\n",ptrchr);//1 artti
    printf("++ sonrasi ptrdbl nin adresi%d\n",ptrdbl);//8 artti
    printf("ptrint=%d\nptrchr=%c\nptrdbl=%dl\n",*ptrint,*ptrchr,*ptrdbl);
    //-------------------------------------------------------------------------------------------------------------------------------------
    //NULL pointer
    ptr=NULL;

    //void pointer
    /*
    void pointerlarin belli bir türü yoktur bu yüzden bellekte ileriye veya geriye gidemezler ancak  her veri turunu gosterebilirler yazdirirken ise *(gosterilecektip*)ptr diye yazilmali
    */

    //sabit pointer
    /*
    const int *ptr = &a dedigimiz zaman a yi degistiremeyiz cunku const int onunde ama ptr baska adresi gosterebilir
    int *const ptr = &a dedigimiz zaman ptr yi degistiremeyiz cunku const ptr onunde ama a nin degeri degistirilebilir
    const int *const ptr=&a dedigimiz zaman hicbirini degistiremeyiz
    */
    //FOnksiyon pointer
    /*
    int (*fptr)(int, int);//fptr bir pointer’dır,int döndüren ve (int, int) alan bir fonksiyona işaret eder.
    fptr = topla;              // Fonksiyonu gösteren pointer'a atama
    printf("%d\n", fptr(3, 4));  // 7 — pointer ile fonksiyon çagırma
    //İstersen (*fptr)(3, 4) de yazabilirsin ama fptr(3, 4) daha yaygındır.

    örnek::
    double *ptrfonk (double *ptr);
    ptrfonk= ptrilekareHEsapla;
    */
    //-------------------------------------------------------------------------------------------------------------------------------------
    //POINTERLARI FONKSIYONDA KULLANMA
    printf("lutfen bir sayi giriniz:");
    scanf("%lf",&dbl);
    double result=ptrilekareHEsapla(&dbl);// dbl nin adresini almalıyız çünkü fonksiyon adres almak istiyor deger degil
    printf("sonuc=%.2f",result);
//-------------------------------------------------------------------------------------------------------------------------------------
    //DIZILER VE POINTERLAR
    //DIZIISMI[0] IN ADRESI = DIZIISMI IN ADRESI
    //DIZIISMI[2] IN ADRESI = DIZIISMI+2 IN ADRESI
    int dizi[5]={0,1,2,3,4};
    printf("\nilk elemanin adresi %x",&dizi[0]);
    printf("\nilk elemanin adresi %x",dizi);
    printf("\n2. elemanin adresi %x",&dizi[1]);
    printf("\n2. elemanin adresi %x",dizi+1);

    printf("\nilk elemanin degeri %d",dizi[0]);
    printf("\nilk elemanin degeri %d",*(dizi));
    printf("\n2. elemanin degeri %d",dizi[1]);
    printf("\n2. elemanin degeri %d",*(dizi+1));
    // buradan dizilerin de bir pointer oldugunu anlayabiliriz


    a=5;
    b=10;
    int dizi2[5]= {1,8,3,12,9};
    int matris[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int *psayi,*qsayi,*tsayi,*pdizi2,*pmat;
    psayi=&a;
    qsayi=&b;

    //Level 1
    printf("\nLevel-1 / SAYI \n");
    printf("---------------------------------------------------------------- \n");
    printf("a Deger: %d, b Deger:%d \n",a,b);
    printf("psayi Deger: %d, qsayi Deger:%d  \n",*psayi,*qsayi);
    printf("psayi Tuttugu Adres: %d, qsayi Tuttugu Adres:%d \n",psayi,qsayi);
    printf("psayi Deger: %d, qsayi Deger:%d \n",++*psayi,++*qsayi);// yıldızdan önce ise deger artar
    printf("a Deger: %d, b Deger:%d \n",a,b);
    printf("psayi Deger: %d, qsayi Deger:%d \n",*--psayi,*++qsayi);// ilk pointer bir sonraki veriye gidiyor 2. pointer bir önceki veriye gidiyor
    printf("psayi Deger: %d, qsayi Deger:%d \n",*psayi++,*qsayi--);//yukarıdakinin tam tersi
    printf("psayi Deger: %d, qsayi Deger:%d \n",*psayi,*qsayi);
    printf("--------------------------------------------------------------- \n");

    //Level 2
    pdizi2=dizi2;
    printf("Level-2/ DIZI \n");
    printf("---------------------------------------------------------------- \n");
    printf("dizi2 Tuttugu Adres: %d, pdizi2 Tuttugu Adres:%d  \n",dizi2,pdizi2);
    printf("dizi2 Deger:%d, pdizi2 Deger:%d \n",*dizi2,*pdizi2);
    printf("(dizi2+1) Tuttugu Adres: %d, (pdizi2+1) Tuttugu Adres:%d \n",dizi2+1,pdizi2+1);
    printf("(dizi2+1) Tuttugu Adres: %d, ++pdizi2 Tuttugu Adres:%d \n",dizi2+1,++pdizi2);
   // dizi2++ hata verir çünkü diziler conskttur ama pdizi2++ yaparsak buna izin verir ve artık pdizi2=dizi2[1] olur
    pdizi2=dizi2;
    printf("*(dizi2+3) Deger:%d, *(pdizi2+3) Deger:%d \n",*(dizi2+3),*(pdizi2+3));
    pdizi2=dizi2;
    printf("(*pdizi2++) Deger:%d \n",*pdizi2++);
    printf("(*pdizi2++) Deger:%d \n",*pdizi2);
    pdizi2=dizi2;
    printf("(*++pdizi2) Deger:%d \n",*++pdizi2);
    pdizi2=dizi2;
    printf("(++*pdizi2) Deger:%d \n",++*pdizi2);
    printf("---------------------------------------------------------------- \n");

    //Level 3
    printf("Level-3 / MATRIS \n");
    printf("---------------------------------------------------------------- \n");
    pmat=matris;
    printf("matris Tuttugu Adres: %d, pmat Tuttugu Adres:%d  \n",matris,pmat);
    printf("*matris Deger: %d(yine baslangıc adresi), *pmat Deger:%d  \n",*matris,*pmat);
    printf("**matris Deger: %d, *pmat Deger:%d  \n",**matris,*pmat);
    printf("matris+1 Tuttugu Adres: %d(matris[1][0]), pmat+1 Tuttugu Adres:%d  \n",matris+1,pmat+1);
    printf("*(matris+1) Tuttugu Adres: %d(&matris[1][0]), *(pmat+1) Deger:%d  \n",*(matris+1),*(pmat+1));
    printf("**(matris+1) Deger: %d(matris[1][0]), *(pmat+1) Deger:%d  \n",**(matris+1),*(pmat+1));
    printf("*(matris+1)+1 Tuttugu Adres: %d(&matris[1][1]), (pmat+1)+1 Tuttugu Adres:%d \n",*(matris+1)+1,(pmat+1)+1);
    printf("*(*(matris+1)+2) Deger: %d(matris[1][2]), *((pmat+1)+2) Deger:%d  \n",*(*(matris+1)+2),*((pmat+1)+2));
    printf("*(matris+1)+2 Tuttugu Adres: %d(&matris[1][2]), (pmat+3)+1 Tuttugu Adres:%d \n",*(matris+1)+2,(pmat+3)+1);
    printf("*(*(matris+2)+2) Deger: %d(&matris[2][2]), *(pmat+7) Deger:%d  \n",*(*(matris+2)+2),*(pmat+7));
    // matrislerde bir pointer
    /*
    pmat=matris;
    matris -> &matris[0] -> matrisin ilk satirinin adresi
    matris+1 -> &matris[1] -> ikinci satirin adresi
    *matris -> &matris[0][0] -> ilk elemanin adresi
    *(matris+1) -> &matris[1][0] -> 2.satir 1.eleman adres
    *(matris+1)+1 -> &matris[1][1]-> in adresi
    **matris -> matris[0][0] -> 1
    **(matris+1) -> matris[1][0] -> 4
    *(*(matris+1)+2)  -> matris[1][2] = 6
    *(*(matris+2)+2)  -> matris[2][2] = 9

    pmat   -> &matris[0][0] -> ilk elemanin adresi
    pmat+1   -> matris[0][1] -> ikinci elemana adresi
    (pmat+1)+1    -> &matris[0][2]->ucuncu eleman adresi
    (pmat+3)+1        -> &matris[0][4] -> yani matris[1][1] adresi
    *pmat   -> matris[0][0] yani 1
    *(pmat+1)   -> matris[0][1] -> 2
    *((pmat+1)+2)     -> matris[0][3] = 4
    *(pmat+7)         -> matris[2][1] = 8
    // yani * varsa degerlerde +1 * yoksa adreslerde +1 gider



    */
    //POINTERI FONKSIYON PARAMETRESI OLARAK KULLANMAK

    int x = 55;
    printf("x'in degeri,\n");
    printf("Fonksiyonlar cagirilmadan once: %d\n", x);

    // f1 fonksiyonu cagiriliyor
    f1(x);
    printf("f1 cagirildiktan sonra: %d\n", x);

    // f2 fonksiyonu cagiriliyor
    f2(&x);
    printf("f2 cagirildiktan sonra: %d\n", x);

    //FONKSIYONUN GERI DÖNÜŞ DEĞERI POINTER DE OLABILIR
    //ancak bunun icin f2*(int *); yazmaliydik
    // FONKSIYONLARDA DIZI KULLANIMI
    int sonuc;
    f2(dizi);
    for (int i=0;i<5;i++)
    {
        printf("\n%d.matris:%d",i,dizi[i]);
    }

}
//deger gecerek aktarim
void f1(int n)
{
    n = 66;
    printf("f1 fonksiyonu icinde : %d\n", n);
}

// Adres gecerek aktarim
void f2(int *n)
{
    *n = 77;
    printf("f2 fonksiyonu icinde : %d\n", *n);
}
void pointerlar2(){
    // ******** Temel pointer tanimlamalari ve örnekler ********
    int a = 5, b = 10, c = 3, *p1, *p2;

    // Temel pointer kullanimi - pointer degişkenleri degişkenlerin adresini tutar
    p1 = &a;
    p2 = &b;

    printf("\np1 adresi: %p, p1'in gosterdigi deger (a): %d\n", (void*)p1, *p1);
    printf("p2 adresi: %p, p2'nin gosterdigi deger (b): %d\n", (void*)p2, *p2);

    // Pointer üzerinden degişken degerini degiştirme
    *p1 = 20;
    printf("a'nin yeni degeri *p1 ile degistirildi: %d\n", a);

    // ******** Çok sik yapilan pointer hatalari ********
    // 1. Uninitialized pointer (tanimlamadan kullanmak) -> kesinlikle kaçinin!
    int *px;
    // *px = 100;  // HATA: px tanimsiz adresi gösteriyor, bu ciddi sorun!

    // 2. NULL pointer dereference
    int *pn = NULL;
    // *pn = 10;  // HATA! NULL pointer'a erişim sistem hatasina yol açar

    // 3. Dangling pointer (free'den sonra erişim)
    int *pd = malloc(sizeof(int));
    if (pd == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    *pd = 20;
    free(pd);
    // printf("%d\n", *pd); // HATA: artik pd geçersiz, kullanmayin

    // 4. Pointer aritmetiginde sinirlarin dişina çikmak
    int arr[3] = {1, 2, 3};
    int *pa = arr;
    printf("arr[1] = %d, *(pa+1) = %d\n", arr[1], *(pa + 1)); // dogru
    // printf("%d\n", *(pa + 3)); // HATA! dizinin dişina çikildi!

    // 5. Const pointer kullanimi
    const int *ptr1 = &a;    // ptr1'in gösterdigi deger degiştirilemez, ptr1 başka adres gösterebilir
    // *ptr1 = 6;            // HATA!
    int *const ptr2 = &a;    // ptr2 sabit adres, işaret ettigi deger degiştirilebilir
    *ptr2 = 6;               // OK
    // ptr2 = &b;            // HATA!

    const int *const ptr3 = &a; // adres ve deger sabit, hiçbiri degiştirilemez
    // *ptr3 = 9;             // HATA!
    // ptr3 = &b;             // HATA!

    // ******** Pointer ile deger geçirme - fonksiyon örnekleri ********
    int sayi = 4;
    f1(sayi);            // deger geçirme, etkisiz
    printf("sayi (f1 sonrasi) = %d\n", sayi); // hala 4
    f2(&sayi);           // adres geçirme, etkili
    printf("sayi (f2 sonrasi) = %d\n", sayi); // 8

    // ******** Void pointer (her türü gösterebilir ama işlem için cast gerekir) ********
    int val = 100;
    void *vptr = &val;
    printf("void pointer ile deger = %d\n", *(int*)vptr); // cast zorunlu

    // ******** Pointer ile diziler ve matris ********
    int dizi[] = {10, 20, 30};
    int *pdz = dizi;
    printf("dizi[0] = %d, *(pdz) = %d\n", dizi[0], *pdz);
    printf("dizi[1] = %d, *(pdz+1) = %d\n", dizi[1], *(pdz+1));

    int mat[2][2] = {{1, 2}, {3, 4}};
    int *pmat = &mat[0][0];
    printf("mat[1][1] = %d, *(pmat+3) = %d\n", mat[1][1], *(pmat+3));

    // ******** Pointerlar ile adres ve deger yazdirma - Detayli örnek ********
    int *ptr = &a;
    printf("\nAdres ve deger bilgileri (detayli):\n");
    printf("a'nin adresi: %p\n", (void*)&a);
    printf("a'nin degeri: %d\n", a);
    printf("ptr'nin adresi: %p\n", (void*)&ptr);
    printf("ptr'nin tuttugu adres: %p\n", (void*)ptr);
    printf("ptr'nin gösterdigi deger: %d\n", *ptr);

    // Pointer ile degişkenler arasi veri aktarimi
    b = *ptr;
    printf("\nPtr kullanarak b'nin yeni degeri: %d\n", b);

    // Pointer ile işaret edilen degeri degiştirme
    *ptr = c;
    printf("Ptr ile a'nin degeri degiştirilmiş: %d\n", a);

    // Pointer'i başka adrese yönlendirme
    ptr = &b;
    printf("Ptr artik b'nin adresini gösteriyor, ptr'nin gösterdigi deger: %d\n", *ptr);

    // ******** Pointer ile toplama işlemi ********
    int top = *ptr + *ptr;
    printf("Pointer ile toplama islemi: %d\n", top);

    // ******** Pointerlarin adres aritmetigi ve degişimi ********
    int nt = 1, *ptrint;
    ptrint = &nt;
    char ch = 'k', *ptrchr;
    ptrchr = &ch;
    double dbl = 3.146766887668687678, *ptrdbl;
    ptrdbl = &dbl;

    printf("ptrint adresi: %p\n", (void*)ptrint);
    printf("ptrchr adresi: %p\n", (void*)ptrchr);
    printf("ptrdbl adresi: %p\n", (void*)ptrdbl);

    printf("ptrint degeri: %d, ptrchr degeri: %c, ptrdbl degeri: %lf\n", *ptrint, *ptrchr, *ptrdbl);

    ptrint++;  // int için +4 byte artiş (örnek makinede)
    ptrchr++;  // char için +1 byte artiş
    ptrdbl++;  // double için +8 byte artiş

    printf("ptrint yeni adresi: %p\n", (void*)ptrint);
    printf("ptrchr yeni adresi: %p\n", (void*)ptrchr);
    printf("ptrdbl yeni adresi: %p\n", (void*)ptrdbl);

    // NOT: Bu pointerlarin yeni adreslerinde bilinmeyen veya rastgele deger olabilir.
    // *ptrint, *ptrchr, *ptrdbl dereferans etmeden önce dikkat!

    // ******** NULL pointer örnegi ********
    ptr = NULL;
    if (ptr == NULL) {
        printf("Pointer su an NULL, herhangi bir islem yapilamaz.\n");
    }

    // ******** Pointerlarin fonksiyonlarda kullanimi ********
    printf("\nBir sayi giriniz: ");
    scanf("%lf", &dbl);
    double result = ptrilekareHEsapla(&dbl);
    printf("Sayinin karesi (pointer ile hesaplandi): %.2f\n", result);

    // ******** Pointerlar ile dizilerde adres ve deger ilişkisi ********
    int dizi2[5] = {0, 1, 2, 3, 4};
    printf("Dizinin ilk elemaninin adresi: %p\n", (void*)&dizi2[0]);
    printf("Dizinin adresi (dizi2): %p\n", (void*)dizi2);
    printf("dizi2[2] = %d, *(dizi2 + 2) = %d\n", dizi2[2], *(dizi2 + 2));

    // ******** Pointer to pointer (iki seviyeli pointer) ********
    int var = 500;
    int *ptr_var = &var;
    int **ptr_ptr = &ptr_var;

    printf("var: %d\n", var);
    printf("*ptr_var: %d\n", *ptr_var);
    printf("**ptr_ptr: %d\n", **ptr_ptr);

    // ******** Pointer ile dinamik bellek yönetimi örnegi ********
    int *dinamik_dizi = malloc(5 * sizeof(int));
    if (dinamik_dizi == NULL) {
        perror("Dinamik bellek alloc failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 5; i++) {
        dinamik_dizi[i] = i * 10;
    }
    printf("Dinamik dizi elemanlari: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dinamik_dizi[i]);
    }
    printf("\n");
    free(dinamik_dizi);
}
void pointerlar_ve_String(){
// POINTER VE STRING KULLANIMI - TEMEL KAVRAMLAR & HATALAR

    // 1) Sabit string gösterimi - degiştirilemez, sadece okunabilir
    char *msgptr = "how are u today";
    int i = 0;
    printf("Pointer ile string karakter karakter yazdirma:\n");
    while (*(msgptr + i) != '\0')
    {
        printf("%c", *(msgptr + i));
        i++;
    }
    printf("\n");

    // HATA: msgptr[0] = 'H';  --> Bu hatalidir, çünki string literal read-only hafizadadir.
    // Derleme zamani hata vermez ama runtime'da crash olur.

    // 2) Hazir string fonksiyonlari kullanimi ve önemli detaylar
    char *alphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
    printf("String uzunlugu (strlen): %ld\n", strlen(alphabet)); // strlen unsigned long döner

    // 3) Dizi üzerinde string işlemleri
    char str1[20] = "AAA";
    char str2[20] = "BBB";

    // strcat: str1'in sonuna str2 ekler, str1'in yeterli kapasitesi olmali
    strcat(str1, str2);
    printf("strcat ile str1: %s\n", str1);
    printf("str2 degismedi: %s\n", str2);

    // HATA: Yetersiz alan varsa strcat buffer overflow yapar.
    // Örnek: char s[5]="ABC"; strcat(s,"DEFGH"); --> Bellek taşmasi, güvenlik açigi!

    // strcpy: str2 = str1 kopyalar, str2'nin boyutu yeterli olmali
    strcpy(str2, str1);
    printf("strcpy ile str2: %s\n", str2);

    // HATA: str2'nin alani küçükse strcpy yine buffer overflow yapar.

    // strcmp: iki string eşit ise 0 döner
    if (strcmp(str1, str2) == 0)
        printf("str1 ve str2 esit\n");
    else
        printf("str1 ve str2 farkli\n");

    // 4) Pointer ve array arasindaki fark
    char arr[] = "HELLO";
    char *ptr = arr;
    printf("arr dizisi: %s\n", arr);
    printf("ptr pointer: %s\n", ptr);

    // HATA: Pointer degişkenin işaret ettigi string'i degiştirmek mümkün, ama literal string pointer'i ile degişiklik yapilamaz

    // 5) Pointer ile string dizisine erişim ve degişiklik
    ptr[0] = 'h'; // arr dizisi degiştirilebilir çünkü dizi bellekte modifiye edilebilir alan
    printf("degistirilmis arr: %s\n", arr);

    // HATA: char *p = "HELLO"; p[0] = 'h';  --> Hatali, string literal degiştirilemez.

    // 6) NULL karakteri '\0' string sonlandiricidir, unutulmamali
    char example[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("example string: %s\n", example);

    // 7) Boşluklu input için gets kullanimi (tehlikeli!)
    // char input[10];
    // gets(input); // Güvenlik açigi, buffer overflow riski
    // Bunun yerine fgets kullan:
    // fgets(input, sizeof(input), stdin);

    // 8) Pointer ile diziler ve fonksiyonlarda kullanimi
    void printString(char *p)
    {
        while (*p)
        {
            putchar(*p);
            p++;
        }
        putchar('\n');
    }
    printString(arr);

    // 9) Diziler ve pointerlar karişabilir ama farklidir:
    // arr bir dizi adi, pointer sabit bir adresi gösterir.
    // &arr != &ptr
}
enum AYLAR {
    aylar,
    OCAK,
    SUBAT,
    MART,
    NISAN,
    MAYIS,
    HAZIRAN,
    TEMMUZ,
    AGUSTOS,
    EYLUL,
    EKIM,
    KASIM,
    ARALIK
};

// STRUCT tanimlari
//ogrenciler icin strukt tanımlama
struct Ogrenciler {
    char* isimSoyisim;
    int no;
    float puan;
    char sifre[20];
};
// okul icin struct tanımlama hem ogretmen var hem ogrenci var
struct okul {
    char* ogretmenisim;
    int ogretmenNo;
    struct Ogrenciler ogrenci;
};

// STRUCT gösterim fonksiyonlari
void showSTRUCT(struct Ogrenciler x) {
    printf("\nname: %s\n", x.isimSoyisim);
    printf("no: %d\n", x.no);
    printf("puan: %.2f\n", x.puan);
    printf("sifre: %s\n", x.sifre);
}

void showSTRUCTokul(struct okul d) {
    printf("\nOgretmen: %s\n", d.ogretmenisim);
    printf("No: %d\n", d.ogretmenNo);
    printf("Ogrenci Puan: %.2f\n", d.ogrenci.puan);
    printf("Ogrenci Sifre: %s\n", d.ogrenci.sifre);
}

// ASIL KODLARIN FONKSİYONLAŞTIRILMIŞ HALİ
void struct_union_enum() {
    // STRUCT ÖRNEKLERİ

    //basit struct
    struct Ogrenciler x;
    x.isimSoyisim = "Hasan Selman Bicer";
    x.no = 1;
    x.puan = 75.2;
    strcpy(x.sifre, "hasan123");
    printf("%s//%d//%.2f\n", x.isimSoyisim, x.no, x.puan);

    // struct degistirme
    x.isimSoyisim = "degisti";
    x.no = 1;
    x.puan = 80.2;
    strcpy(x.sifre, "hasan1234");
    printf("%s//%d//%.2f\n", x.isimSoyisim, x.no, x.puan);

    //direkt struct baslatma (initialize)
    struct Ogrenciler x2 = { "Ali talha Bicer", 2, 85.2, "ali 123" };

    //struct kopyalama
    struct Ogrenciler x3;
    x3 = x2;
    printf("%s//%d//%.2f\n", x3.isimSoyisim, x3.no, x3.puan);

    //struct dizisi
    struct Ogrenciler y[4];
    y[0].isimSoyisim = "hasansb";
    y[0].no = 3;
    y[0].puan = 43.0;
    strcpy(y[0].sifre, "hasansb123");

    y[1].isimSoyisim = "hasannn";
    y[1].no = 5;
    y[1].puan = 46.0;
    strcpy(y[1].sifre, "hasannn123");

    //dizinin ilk 2 elamanını yazdırma
    for (int i = 0; i < 2; i++) {
        printf("\n%d. ogrenci\n", i + 1);
        printf("%s//%d//%.2f//%s\n", y[i].isimSoyisim, y[i].no, y[i].puan, y[i].sifre);
    }

    //fonksiyonla struct
    showSTRUCT(x);

    //pointer ile struct
    struct Ogrenciler hasan;
    struct Ogrenciler *ptr = &hasan;

    ptr->isimSoyisim = "pointer";
    ptr->no = 2;
    ptr->puan = 35.0;
    strcpy(ptr->sifre, "pointer123");
    showSTRUCT(*ptr);

    // struct icinde struct
    struct okul d;
    d.ogretmenisim = "1234";
    d.ogretmenNo = 0;
    d.ogrenci.isimSoyisim = "hasanmudur";
    d.ogrenci.no = 12;
    d.ogrenci.puan = 34.0;
    strcpy(d.ogrenci.sifre, "mudursifre");
    showSTRUCTokul(d);

     // :) Dizi içinde struct da olabilir
    struct Nokta { int x, y; };
    struct Nokta noktalar[3] = {{1,2},{3,4},{5,6}};
    printf("noktalar[1].x = %d\n", noktalar[1].x);
    printf("noktalar[1].y = %d\n", noktalar[1].y);

    //   HATA: struct dizisinin boyutunu aşma
    // noktalar[3].x = 10; // Geçersiz

    // TYPEDEF KULLANIMI
    typedef long long int lli;
    typedef char name[30];

    name isim = "hasan de";
    lli sayi = 124242342342314;
// struct ile typdef kullanımı
    typedef struct {
        char* name;
        int no;
        float puan;
    } ogrenciler;

    ogrenciler x4 = { "hasan selman", 1, 43.3 };
    printf("\n%s//%d//%.2f", x4.name, x4.no, x4.puan);

    // ENUM ORNEGI
    enum AYLAR myConst[13];
    for (int i = 1; i <= 12; i++) {
        myConst[i] = i;
    }
    for (int i = 1; i <= 12; i++) {
        printf("\nAy %d: %d", i, myConst[i]);//(ocak subat  yazmaz sadece 1234 diye yazar)
    }

    // UNION ÖRNEKLERİ
    //union tüm verileri aynı anda saklamaz mesela aşaüıdaki en büyük byte lı veri 40 sa 40 lık bir alan açar ve hepsini o alanda saklar
    // ama sadece en son yazılan doğru sonucu verşr
    union unionS {
        char name[40];
        int age;
        float puan;
    } Ustudent;

    typedef struct {
        char name[40];
        int age;
        float puan;
    } srcstudent;

    printf("\n\nsize of union : %d", sizeof(Ustudent));
    printf("\nsize of struct: %d", sizeof(srcstudent));

    union unionS2 {
        char name;
        int age;
        float puan;
    } Ustudent2;

    Ustudent2.age = 99;
    printf("\nAge: %d", Ustudent2.age);
    printf("\nName (ASCII): %c\n", Ustudent2.name);
}

void Dinamik_Bellek_Yonetimi(){

//MALLOC :pointer kullanmak zorundayiz
    int* n=(int*)malloc(sizeof(int));
    int x;
    *n=7;
    printf("kac tane eleman gireceksin:");
    scanf("%d",&x);
    int*MlcArr=(int*)malloc(x*sizeof(int));
    if(MlcArr==NULL){
        printf("BELLEK AYRIMI BASARISIZ");
        return 1;
    }
    for(int i=0;i<x;i++)
    {
        printf("MlcArr[%d]=",i);
        scanf("%d",&MlcArr[i]);
    }
    for(int i=0;i<x;i++)
    {
        printf("\nMlcArr[%d]=%d",i,MlcArr[i]);
    }
    //Calloc // calloc ile malloc farki: 1)mallocta * ile boyutu carpiyoruz callocta (kac tane veri gireceksin,boyutu)
    //2)malloc ayirdigin bellekte deger varsa dokunmaz calloc ayirdigin bellekteki tum degerleri 0 a eşitler
    int*ClcArrRlc=(int*)calloc(n,sizeof(int));
    if (ClcArrRlc==NULL)
    {
        printf("BELLEK AYRIMI BASARISIZ");
    }
    free(MlcArr);
    printf("\n");
    for(int i=0;i<x;i++)
    {
        printf("\nBos MlcArr[%d]=%d",i,MlcArr[i]);
    }
    printf("\n");
    for(int i=0;i<x;i++)
    {
        printf("\nBos ClcArrRlc[%d]=%d",i,ClcArrRlc[i]);
    }
    printf("\n\n");
    for(int i=0;i<x;i++)
    {
        printf("ClcArrRlc[%d]=",i);
        scanf("%d",&ClcArrRlc[i]);
    }
    //REALLOC:Yeniden boyut vermeni saglar
    int new_size;
    printf("\n\nMevcut array:");
    for(int i=0;i<x;i++)
    {
        printf("\nClcArrRlc[%d]=%d",i,ClcArrRlc[i]);
    }
    printf("\n'yeni' kac eleman gireceksin:");
    scanf("%d",&new_size);
    ClcArrRlc=(int*)realloc(ClcArrRlc,new_size*sizeof(int));
    if(ClcArrRlc==NULL)
    {
        printf("BELLEK AYRIMI BASARISIZ");
    }
    for(int i=x;i<new_size;i++)
    {
        printf("ClcArrRlc[%d]=",i);
        scanf("%d",&ClcArrRlc[i]);
    }
    printf("\n\nRealloc sonrasi array:");
    for(int i=0;i<new_size;i++)
    {
        printf("\nClcArrRlc[%d]=%d",i,ClcArrRlc[i]);
    }
    //belleði serbest hale getirdi.
    free(MlcArr);
    free(ClcArrRlc);
    free(n);
}
void Dosya_islemleri(){


    FILE *fptr ,*fptrcopy;// yapacagimiz islemler icin dosya pointerlari ayarliyoruz.
    char ch;//komut blogundan tek karakter okumak icin.
    char stringOkumakIcin[100];

     // dosya islemi yapmak icin dosyayi aciyoruz !!Yolu kopyala yapistir yaptiktan sonra iki tane / isareti olmali
     //eger Dosya yolu kopyalamazsan kodun oldugu klasorde dosyayi arar.
     fptr=fopen("islemYapacagimDosya.txt","w+");
     fptrcopy=fopen("KopyalayacagimDosya.txt","w+");
     //Dosya acma modlari
        // w=BASTAN YAZMA dosya varsa acar yoksa olusturur.eger hic bir sey yazmazsan veriler kayboluyor
        // a=SONDAN YAZMA dosya varsa acar yoksa olusturur.eger hic bir sey yazmazsan bir şey değişmeden kapanır.
        // r=BASTAN OKUMA dosya varsa acar yoksa NULL DÖNDÜRÜR;
        // W+/R+/A+= OKUMA VE YAZMA IsLEMLERI
//-------------------------------------------------------------------------------------------------------------------------------
    //Dosya acilmasi durumunu belirtme ve acilamama durumunda uygulamayi kapatma
    if (fptr==NULL)//ACILMA KONTROLU ICIN 1.YOL
    {
        printf("Dosya Acilamadi Uygulama Kapaniyor");//HATA MESAJI 1. YOL
        exit(EXIT_FAILURE);
    }else if(!fptrcopy)////ACILMA KONTROLU ICIN 2.YOL
    {
        perror("Kopyalanacak Dosya Acilamadi Uygulama Kapaniyor");//HATA MESAJI 2. YOL
        exit(EXIT_FAILURE);
    }else{printf("Dosya acildi:)");}
//-------------------------------------------------------------------------------------------------------------------------------
    //Dosyaya koddan yazi yazma:
    //    |Fonksiyon	|Ne Icin Kullanilir? |	Avantaji	              |  Dezavantaji        |
    //---------------------------------------------------------------------------------------------
    //    |fprintf	    |Formatli veri yazmak|	Esnek, tum veri turleri	  |  Gorece daha yavas  |
    //    |fputs	    |Duz metin yazmak	 |  Basit ve hizli	          |  Sadece string yazar|
    //    |fwrite  	    |Ikili veri (binary) |	Hizli, dosya kopyalama	  |  Okumasi zordur     |
    //    |putc	        |Tek karakter yazmak |karakter kontrolu kolay     |Sadece tek karakter yazar,verimsiz
    //    |fputc        |Tek karakter yazmak |karakter kontrolu kolay     |Sadece tek karakter yazar,verimsiz--putc den kullanisli
    putc('p',fptr);//'' kullanilmalidir yoksa anlamsiz yazilara donusur
    fputc('f',fptr);//'' kullanilmalidir yoksa anlamsiz yazilara donusur
    fprintf(fptr,"\nFPRINTF=(%d) gibi Veri tipine gore dosyaya yazi yazabilir\n",1);
    fputs("Fputs ile yazilmistir: Tek satirlik yazilar,	Format kontrolu yapmaz, direkt yazi basar (bu da performans avantaji saglar)\n",fptr);

   /* int sayilar[]={1,2,3,4,5}; //fwrite ile yazmak icin
    size_t elemanSayisi = sizeof(sayilar) / sizeof(sayilar[0]);
    fwrite(sayilar,sizeof(int),elemanSayisi,fptr);//su an iasaretciyi okumak icin dogru yere koy
    fseek(fptr,-elemanSayisi * sizeof(int),SEEK_CUR);
    fread(sayilar,sizeof(int),elemanSayisi,fptr);
    for (int i=0;i<5;i++)
    {
        printf("\n%d",sayilar[i]);
    }
    fprintf(fptr,"\n");*/
//---------------------------------------------------------------------------------------------------------------------------------
 //Dosyaya komut blogundan yazi yazma
   //1- Komut blogundaki yazilari okuma
    //|Fonksiyon|Ne Icin Kullanilir?						|Avantaji				   		       	    |Dezavantaji        									|
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    //|getc		|Karakter okuma						        |Hizli karakter okuma					    |Sadece karakter okur, satir okuma yok			        |
    //|getchar	|Karakter okuma						        |Standart giristen karakter okur, basittir	|Yalnizca karakter okur, satir okuma yapamaz		    |
    //|gets		|Kullanicidan satir almak				    |Basittir								    |Guvensizdir, buffer overflow'a yol acar			    |
    //|scanf	|Formatli giris almak					    |Karmasik veri girisleri icin kullanilir	|Bosluk karakterlerine dikkat edilmesi gerekir		    |
    //|fgets	|Kullanicidan guvenli sekilde satir almak	|Buffer overflow'a karsi guvenli			|Satir sonundaki '' karakteri dosyaya yazilabilir	    |
    //|fscanf	|Dosyadan formatli giris almak			    |Dosya okuma sirasinda formatli veri alir	|Dosya okuma sirasinda format hatalari olabilir	        |
    //|fread	|Ikili veri okuma						    |Veriyi hizlica bloklar halinde okur		|Metin dosyalarinda karmasik olabilir			        |

   //2-Okunan degerleri yazma
    //|Fonksiyon| Ne İçin Kullanilir?                  | Avantaji                                   | Dezavantaji                                        | En Uygun Oldugu Senaryo                           |
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
  //| fprintf   | Formatli veriyi dosyaya yazmak       | Esnek, her veri türüyle uyumlu             | Format hatalari olabilir, karmaşik olabilir        | Sayi + metin + özel karakter karişik yazma        |
  //| fwrite    | İkili (binary) veriyi dosyaya yazmak | Hizli, çok veri bloklarini ayni anda yazar | Metin yazarken kontrol zordur, okunabilirlik düşer | Çok veri (örnegin struct dizisi) yazma            |
  //| putc      | Tek karakteri dosyaya yazmak         | Basit, hizli                               | Sadece karakter yazar, string yazamaz              | Sadece 1 karakter yazma                           |
  //| fputc     | Dosyaya karakter yazmak              | Standarttir, güvenilirdir                  | Sadece karakter yazar                              | Sadece 1 karakter yazma                           |
  //| fputs     | Dosyaya string (metin) yazmak        | Kolay kullanim, string için ideal          | Sadece null ile biten dizileri yazar, format yok   | String (metin) verisi yazma                       |

    //getc ile okuma
    printf("getc ile karakter oku:");
    ch=getc(stdin);

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // buffer temizleme
    //putc ile yazma (putc ve fputc neredeyse aynidir)
    putc(ch,fptr);
    rewind(stdin);

    //getchar ile okuma(komut blogunda tek karakter icin tercih)
    printf("getchar ile karakter oku:");
    ch=getchar();
    //fputc ile yazma
    fputc(ch,fptr);
    rewind(stdin);

    //gets ile satir okuma
    printf("gets ile satir oku bosluk dahil'char gerekli'(asla kullanilmamalidir):");
    gets(stringOkumakIcin);
    //fputs ile yazma
    fputs(stringOkumakIcin,fptr);
    rewind(stdin);

    //fgets ile okuma scanf ten hemen sonra okunursa bozulur ve hiç karakter okumamiş olur
    printf("fgets ile satir oku(en guvenilir secenek):");
    fgets(stringOkumakIcin,sizeof(stringOkumakIcin),stdin);
    //fputs ile yazma
    fputs(stringOkumakIcin,fptr);
    rewind(stdin);

    //scanf ile okuma
    printf("scanf ile formatli satir oku (bosluktan sonra biter)!!'[^\n]' yaptigin zaman bosluklari da okur:");
    scanf("%[^\n]s",stringOkumakIcin);//[^\n] yaptigin zaman bosluklari da okur ve &isRaretine gerek yoktur
    //fprintf ile yazma
    fprintf(fptr,"%s",stringOkumakIcin);
    rewind(stdin);

    //fscanf ile okuma
    printf("fscanf ile karakter oku:");
    fscanf(stdin,"%[^\n]s",stringOkumakIcin);
    //fprintf ile yazma
    fprintf(fptr,"%s",stringOkumakIcin);
    rewind(stdin);

    printf("\nfread ile karakter okuyamayiz cunku komut bloguna binary yazamiyoruzancak yazabilseydik boyle okunurdu");
    printf("\nsize_t bytesRead=fread(stringOkumakIcin,sizeof(char),sizeof(stringOkumakIcin),stdin);");
//------------------------------------------------------------------------------------------------------------------------------------------------------
    //4-dosyadan yazi okuma ve ekrana yazdirma
//| Fonksiyon                        | Amaç                                         |Dönüş Degeri                 | Ne Zaman Bitirir?                         | Yaygin Hatalar                              | Dikkat Edilmesi Gerekenler |
//|----------------------------------|----------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
//| getc(FILE *fp)                   | Dosyadan 1 karakter okur                     | Okunan karakter (int), EOF  | Dosya sonu (EOF)                          | int degil char ile karşilaştirmak (hatali) | EOF kontrolü yaparken int türü kullan |
//| fgets(str, size, FILE *fp)       | Güvenli satir okuma                          | char*, NULL                 | \n veya size-1 karakter okununca veya EOF | \n karakterini içerir                      | Dosya veya stdin fark etmez, NULL kontrolü yap |
//| fscanf(FILE *fp, "%s", str)      | Dosyadan formatli veri okur                  | Okunan öge sayisi           | Format uymadiginda veya EOF               | Format uyuşmazligi, boşlukla kesilme       | fscanf(fp, "%[^\n]", str) şeklinde kullanilabilir |
//| fread(ptr, size, count, FILE *fp)| Binary veri bloklarini okur                  | Okunan öge sayisi (size_t)  | Dosya sonu veya yetersiz veri             | Text dosyada anlamsiz veri olabilir        | Genelde struct gibi binary veri için kullanilir |
//|----------------------------------|----------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
 //Okunan degerleri yazma
//|Fonksiyon| Ne İçin Kullanilir?                    | Avantaji                                   | Dezavantaji                                        | En Uygun Oldugu Senaryo                           |
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//| fprintf   | Formatli veriyi dosyaya yazmak       | Esnek, her veri türüyle uyumlu             | Format hatalari olabilir, karmaşik olabilir        | Sayi + metin + özel karakter karişik yazma        |
//| fwrite    | İkili (binary) veriyi dosyaya yazmak | Hizli, çok veri bloklarini ayni anda yazar | Metin yazarken kontrol zordur, okunabilirlik düşer | Çok veri (örnegin struct dizisi) yazma            |
//| putc      | Tek karakteri dosyaya yazmak         | Basit, hizli                               | Sadece karakter yazar, string yazamaz              | Sadece 1 karakter yazma                           |
//| fputc     | Dosyaya karakter yazmak              | Standarttir, güvenilirdir                  | Sadece karakter yazar                              | Sadece 1 karakter yazma                           |
//| fputs     | Dosyaya string (metin) yazmak        | Kolay kullanim, string için ideal          | Sadece null ile biten dizileri yazar, format yok   | String (metin) verisi yazma                       |
//| puts	  |Stringi ekrana(stdout)yazdirir.otomatik\n ekler||Basit ve otomatik satir sonu ekler|	Sadece stdout'a yazar, dosyaya degil!	           |Terminale/ekrana tek satir metin bastirma          |



printf("----------------getc ve putc-------------------------------------------------------------------------------------------------------");
    //getc ve putc ile dosyayi okuyup yazmak
    rewind(fptr);
    while((ch = getc(fptr))!=EOF)
    {
    putc(ch,stdout);
    }
printf("----------------getc ve fputc-------------------------------------------------------------------------------------------------------");
    //getc ve fputc ile ekrana yazma
    rewind(fptr);
    while((ch = getc(fptr))!=EOF)// !feof(fptr) bu kodla son karakter iki kez okunabilir
    {
    fputc(ch,stdout);
    }
printf("----------------fgets ve puts-----------------------------------------------------------------------------------------------------");
    //fgets ve puts ile ekrana yazma// her yeni satirda bir \n birakir(puts ve fputs binary okumaz)
    rewind(fptr);
    while(fgets(stringOkumakIcin,sizeof(stringOkumakIcin),fptr)!=NULL)
    {
        puts(stringOkumakIcin);
    }
printf("----------------fgets ve fputs-------------------------------------------------------------------------------------------------------");
    //fgets ve fputs ile ekrana yazma(puts ve fputs binary okumaz)
    rewind(fptr);
    while(fgets(stringOkumakIcin,sizeof(stringOkumakIcin),fptr)!=NULL)
    {
        fputs(stringOkumakIcin,stdout);
    }

    //BİNARY OLDUGU İCİNBU İKİSİ HATALI
   /* printf("------------fscanf ve printf-------------------------------------------------------------------------------------------------------");
    //fscanf ve printf ile ekrana yazma(binaary gördügünde hata verir)
    rewind(fptr);
    while(fscanf(fptr,"%[^\n]\n",stringOkumakIcin))
    {
        printf("%s",stringOkumakIcin);
    }
    printf("------------fscanf ve fprintf-------------------------------------------------------------------------------------------------------");
    //fscanf ve fprintf ile ekrana yazma(binaary gördügünde hata verir)
    rewind(fptr);
    while(fscanf(fptr,"%[^\n]\n",stringOkumakIcin))
    {
        fprintf(stdout,"%s",stringOkumakIcin);
    }*/
    printf("----------------fread ve fwrite-------------------------------------------------------------------------------------------------------");

    rewind(fptr);
    size_t okunan;// binary okumak icin
    int i=0;
    char okunanlar[100];
    okunan = fread(okunanlar, sizeof(char), 100, fptr);
    for (int i = 0; i < okunan; i++)
        {
            printf("%d ", okunanlar[i]);
        }
    //6-konum işaretçileri
    //fseek(istedigiin kadar ileriye veya geriye götürmeni saglar)
            //SEEK_SET-Dosyanin baslangicina göre ileri geri gider
            //SEEK_CUR-imlecin bulundugu yere göre ileri geri gider
            //SEEK_END-dosyanin sonuna göre ileri geri gider,
        //ftell(fptr)"byte olarak nerede oldugunu görmeni saglar",
        //rewind(fptr) "konum göstergecini basa alir"
        //0
        rewind(fptr);
        long pozisyon = ftell(fptr); // Dosyanin isaretci konumu döner (son byte + 1)
        printf("imlecin byte'i %ld\n", pozisyon);
        //başlangiçtan itibaren+5
        fseek(fptr,5,SEEK_SET);
        pozisyon = ftell(fptr); // Dosyanin isaretci konumudöner (son byte + 1)
        printf("imlecin byte'i %ld\n", pozisyon);
        //bulunan konumdan -3
        fseek(fptr,-3,SEEK_CUR);
        pozisyon = ftell(fptr); // Dosyanin isaretci konumu döner (son byte + 1)
        printf("imlecin byte'i %ld\n", pozisyon);
        //sonundan -5
        fseek(fptr,-5,SEEK_END);
        pozisyon = ftell(fptr); // Dosyanin boyutunu döner (son byte + 1)
        printf("imlecin byte'i %ld\n", pozisyon);
    //7-dosya kopyalama
    rewind(fptr);
    while (fgets(stringOkumakIcin,100,fptr)!=NULL)
    {
        fputs(stringOkumakIcin,fptrcopy);
    }
    //İşlemler için dikkat eedilmesi gereken şeyler
    /* 1-dosyayi açarken kopyaladigimiz yolda bu şekilde :// iki tane slash olmali
     * 2-w bastan a sondan yazar r bastan okur.
     * 3-dosyanin acilip acilmadigin ikontrol etmek icin 2 yol var: fptr==NULL YADA !fptr
     * 4-acilmayan dosyadan cikmanin 2 yolu var : printf/ exit(EXIT_FAILURE) YADA perror /exit(EXIT_FAILURE)
     * 5-dosyaya koddan yazi yazacaksan ve yazi (formatliysa:fprintf / düz metinse :fputs / binaryse :fwrite / tekliyse :fputc)
     * 6-komut blogundaki yaziyi buffera okuma :scanf()Formatli okuma yapar / fgets() ✅	Güvenli ve satir okur / getchar()	Karakter karakter okur / read()binary okur
     * 7-Komut blogundan okunan yaziyi dosyaya yazma : fprintf()dosyaya formatli kaydeder/fputs() güvenli ve satir yazar/ fputc()karakter karakter yazar/fwrite()binary şekilde yazar
     * 7.1- fputs satir satir okur ve kendisi \n koyar/ fwrite ise hizli ve büyük veriler içindir.
     * 8-Dosyadan yaziyi alip ekrana yazmak     🔸 Hiz gerekiyorsa: fread() + fwrite() / Satir bazli iş yapilacaksa: fgets() + fputs()/  Gösterişli, nostaljik röportaj efekti gerekiyorsa: getc() + putc()
     * 9- dosya imleci için rewind basa alir /fseek imleci ileri geri hareket ettirmeni saglar / ftell ilecin kacinci byte ta ooldugunu söyler*/
    //Dosyalari kapatiyoruz
    fclose(fptr);
    fclose(fptrcopy);
    printf("Dosyalar kapatildi \n");
}

//#define "x" gördügun yere "y" yaz seklinde calisir
#define YAZDIR printf//komutun amaci bazi degerleri tanimlamaktir
//const ve define benzerdir ama const hafizada yer kaplar ayrica dizilerin boyut kismina const yazamazsin ama define yazabilirsin

//Kosullu define
#define MAX(x,y) (x>y)? x:y
#define MIN(x,y) (x<y)? x:y
#define Mynumber 10//if kismi icin
//pragma
#pragma message(">>>Derleyici Baslatiliyor Lutfen Bekleyin...")
void Prepocessor_Direktifleri(){//Kutuphane kodlari da bir onislemci komutudur

   //onislemci( Preprocessor ) komutlari: onislemci derlenmeden once kendisinden bir sey istiyor mu diye kontrol eder
    YAZDIR("4\n");//tanimladigimiz number1 calisiyor
    YAZDIR("max deger (5,10)= %d\n",MAX(5,10));
    YAZDIR("max deger (15,10)= %d\n",MAX(15,10));
    YAZDIR("min deger (5,10)= %d\n",MIN(5,10));
    YAZDIR("min deger (15,10)= %d\n",MIN(15,10));
    //#undef tanimli bir define in siler
    #undef YAZDIR
    //if elif else endif
    //#if kodu eger sarti sagliyorsa o satiri okur(endif koyulmak zorunda)
    #if Mynumber>10
    printf("Mynumber 10 dan buyuk=%d",Mynumber);
    // birden cok  bir makro if ifadesi vermek istersen bunu kullan
    #elif Mynumber<10
    printf("Mynumber 10 dan kucuk=%d",Mynumber);
    // eger makro ifadelerin uymadiginda baska islem yapmak iatersen bunu kullan
    #else
    printf("Mynumber 10 a esit=%d\n",Mynumber);
    // ifi bitirir
    #endif

    //ifdef x diye tanimli bir makro varsa icindeki kodu calistirir(endif koyulmak zorunda)
    #define DEBUG
    #ifdef DEBUG
        printf("Debug modu aktif\n");
            #endif

    //ifndef x diye tanimli bir makro yoksa icindeki kodu calistirir(endif koyulmak zorunda)
    #ifndef DEBUG
    // eger debug olmasaydi kod calismaz ve hata verirdi
        #error "DEBUG2 tanimlanmali!"

    #endif

    //line makro
    printf("%d,%c\n",__LINE__,__FILE__);

    #line 23 "dosyaadi.txt"
    printf("%d,%c\n",__LINE__,__FILE__);
    //MERAK EDERSEN ARASTIR(MESSAGE YUKARIDA YAZILDI)
    //pragma derleyiciye ozel komutlar verir
    //#pragma once	Dosya sadece bir kez dahil edilsin
    //#pragma warning	Uyarilari aç/kapat (MSVC)
    //#pragma GCC diagnostic	GCC/Clang uyarilarini bastir
    //#pragma pack(n)	Yapi hizalamasini degiştir
    //#pragma message	Derleme sirasinda mesaj yazdir
    //#pragma region	IDE’de kod katlama saglar
    //#pragma deprecated	Eskimiş fonksiyon uyarisi

}
void Const_Volatile() {
    // ------------------ CONST OZETI VE HATALAR ------------------

    // 1. const degiskenler: degeri sonradan degistirilemez
    const int sabitDeger = 10;
    // sabitDeger = 20; // HATA: const degisken degistirilemez

    // 2. const pointer (sabit veriyi gosteren pointer)
    const int veri = 5;
    const int *ptr1 = &veri; // ptr1 sadece veriyi okur
    // *ptr1 = 6; // HATA: const veri degistirilemez
    int b = 20;
    ptr1 = &b; // adres degisebilir, veri degismez

    // 3. pointer to const (veriyi degistiren ama adresi sabit olan pointer)
    int x = 100;
    int *const ptr2 = &x; // pointer sabit, veri degisebilir
    *ptr2 = 200; // veri degisebilir
    // int y = 300;
    // ptr2 = &y; // HATA: adres degistirilemez

    // 4. const pointer to const: veri ve adres sabit
    const int *const ptr3 = &veri;
    // *ptr3 = 8;  // HATA: veri degistirilemez
    // ptr3 = &x;  // HATA: adres degistirilemez

    // 5. const parametreli fonksiyon ornegi
    // C standardina gore fonksiyon icinde baska fonksiyon tanimlanamaz
    // void fonk1(const int p) { p = 10; } // HATA

    // 6. const ile array parametresi
    // void yazdir(const int dizi[], int boyut) { for(int i=0;i<boyut;i++) printf("%d ", dizi[i]); }

    // 7. struct icinde const kullanim
    struct Ogrenci {
        const int numara;
        char isim[20];
    };
    // struct Ogrenci ali = {123, "Ali"};
    // ali.numara = 456; // HATA: const alan degistirilemez

    // ------------------ EN YAYGIN const HATALARI ------------------
    int deg = 77;
    const int *pp = &deg; // olur cunku veri degistirilmeyecek
    int *const hatali = &deg; // pointer sabit, veri degisebilir

    // ------------------ VOLATILE OZETI VE HATALAR ------------------
    // derleyici bir sebepten dolayı degerin degismeyecegini düsünürse degeri ramdan alıp registerde saklayabilir(cünkü register daha hızlıdır) ör : led ısık bir veriyi degistiriyordur ama kod bunu bilmiyor
    // böyle veriler icin volatile girdiğinde derleyici veriyi registerden almak yerine ramdan alır(daha yavas alır)
    // 1. volatile degisken: derleyici bu degeri optimize etmez
    volatile int durum = 0;

    // Bu tip degiskenler donanim/sinyal/interrupt tarafindan degistirilebilir
    while (durum == 0) {
        // islemler
        // Eger volatile olmasaydi compiler bu while'i optimize edebilirdi
        sleep(1); // ornek bekleme
        durum = 1; // loop'u sonlandirmak icin
    }

    // 2. Donanim register ornegi
    volatile unsigned int *const port = (unsigned int *)0x40021000;
    // *port = 0x01; // donanima veri yazimi (ornek)

    // 3. ISR (interrupt) ile kullanilan degisken
    volatile int bayrak = 0;

    // ISR ornegi: fonksiyon disinda tanimlanmali
    // void ISR() { bayrak = 1; }

    while (!bayrak) {
        // main loop, bayrak 1 olana kadar bekleyecek
        sleep(1); // ornek bekleme
        bayrak = 1; // simule etmek icin ISR cagrisi
    }

    // ------------------ EN YAYGIN volatile HATALARI ------------------
    int hata = 0; // HATA: compiler optimize edebilir
    // void ISR2() { hata = 1; } // ISR fonksiyonu fonksiyon disinda olmalı
    // COZUM: volatile int hata = 0;

    // sadece volatile kullanmak yeterli degil, atomiclik kontrolu gerekir
    volatile int sayac = 0;
    // sayac++; // kritik section gerekli

    // -----------------------------------------------
}
