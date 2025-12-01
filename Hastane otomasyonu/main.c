#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Structs.h"


//Hasan Selman Bicer
//23100011021

///MAIN
int main()
{
    ansi_renkleri_aktif_et();


    int islem_no=-1;
    while(islem_no!=0)
        menu(&islem_no);

    return 0;
}
