#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "menu.h"
#include "phoneAdd.h"
#include "phoneList.h"
#include "phoneSearch.h"


int main()
{
    int choice=0;
    char searchName[30];
    int SearchResult=0;
    do{
        menu();
        printf("\n\n Secim Yapin:");
        scanf("%d",&choice);
                    system("cls");

        switch (choice){

        case 1:
            if(phoneAdd()==0){printf("\nTelefon Numaralari Basarili Bir Sekilde Eklendi\n");}
            else{printf("\nTelefon Numaralari Eklenirken Hata Olustu\n");}
            break;

        case 2:
            if(phoneList()==0){printf("\nTelefon Numarasi Basarili Bir Sekilde Listelendi\n");}
            else{printf("\nTelefon Numarasi Listelenirken Hata Olustu\n");}
            break;

        case 3:
            printf("Lutfen Aranacak ismi giriniz(max 20 karakter):");
            getchar();
            scanf("%[^\n]",searchName);
            SearchResult=phoneSearch(searchName);
            if(SearchResult==0){printf("\nAranilan Kayit Bulunamadi!\n");}
            else{printf("\nToplam %d kayit bulundu:)\n",SearchResult);}
            break;

        case 4:
            printf("\nCikis Yaptiniz Hoscakalin\n");
            return 0;
            break;

        default:printf("\nLutfen 1 ve 4 arasi bir secim yapiniz\n");
            break;

        }

    }while(choice!=4);
    return 0;
}
