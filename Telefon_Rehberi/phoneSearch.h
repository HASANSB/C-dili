
int phoneSearch(char *ptSearch)
{
    Record currentRecord;
    int i=0;
    FILE* fptr;
    fptr=fopen("TelefonRehberi.txt","r");
    if(fptr==NULL){return -1;}

    while (fscanf(fptr, " \"%[^\"]\" \"%[^\"]\" \"%[^\"]\"", currentRecord.name, currentRecord.lastname, currentRecord.phone) == 3)
    {   if (strstr(currentRecord.name,ptSearch)!=NULL)
            {
                printf("\n%s\t\t\t%s\t\t\t%s", currentRecord.name, currentRecord.lastname, currentRecord.phone);
                i++;
            }


    }
    fclose(fptr);
return i;
}
