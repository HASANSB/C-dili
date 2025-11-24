typedef struct {
    char name[30];
    char lastname[30];
    char phone[12];

}Record;

void menu();
int phoneAdd();
int phoneList();
int phoneSearch(char *);
