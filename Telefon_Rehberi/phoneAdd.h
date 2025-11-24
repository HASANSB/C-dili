int phoneAdd(){
    Record newRecord;
    FILE *fptr;
    fptr=fopen("TelefonRehberi.txt","a");
    if (fptr==NULL){return -1;}
    printf("\n\n");
    getchar();
    printf("Isim Giriniz (Max 30 Karakter):");
    scanf("%29[^\n]",newRecord.name);getchar();
    printf("SoyIsim Giriniz (Max 30 Karakter):");
    scanf("%29[^\n]",newRecord.lastname);getchar();
    printf("Telefon Numarasi Giriniz (Max 11 Karakter):");
    scanf("%10[^\n]",newRecord.phone);getchar();
    fprintf(fptr, "\"%s\" \"%s\" \"%s\"\n",newRecord.name,newRecord.lastname,newRecord.phone );
    fclose(fptr);
    return 0;
}
