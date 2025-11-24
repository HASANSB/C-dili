int phoneList(){
    Record currentRecord;
    FILE* fptr;
    fptr=fopen("TelefonRehberi.txt","r");
    if(fptr==NULL){return -1;}
    printf("\n\nISIM\t\t\tSOYISIM\t\t\tTELEFON NUMARASI");
    printf("\n----\t\t\t-------\t\t\t----------------");
    while (fscanf(fptr, " \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", currentRecord.name, currentRecord.lastname, currentRecord.phone) == 3) {
    printf("\n%s\t\t\t%s\t\t\t%s", currentRecord.name, currentRecord.lastname, currentRecord.phone);
}

    fclose(fptr);
    return 0;
}
