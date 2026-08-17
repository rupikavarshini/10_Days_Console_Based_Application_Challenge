
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct book {
    char name[10];
    char author[20];
    char holdername[10];
    int duedate;
    int phone;
};
int main() {
    FILE *fp;
    struct book *b=NULL;
    int i=0,j,choice,flag;
    int phone,duedate;
    char name[10],authorname[20],holdername[10];
    fp=fopen("library.txt","w");
    if(fp==NULL) {
        printf("File cannot be opened");
        return 1;
    }
    while(1){
        printf("\n\n1. Add book");
        printf("\n2. Return");
        printf("\n3. Search");
        printf("\n4. Due record");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                b=realloc(b,(i+1)*sizeof(struct book));
                printf("\nEnter book name: ");
                scanf("%s",b[i].name);
                printf("Enter book author name: ");
                scanf("%s",b[i].author);
                printf("Enter holder name: ");
                scanf("%s",b[i].holdername);
                printf("Enter phone number: ");
                scanf("%d",&b[i].phone);
                printf("Enter due date: ");
                scanf("%d",&b[i].duedate);
                fprintf(fp,"\nBook: %s",b[i].name);
                fprintf(fp,"\nAuthor: %s",b[i].author);
                fprintf(fp,"\nHolder: %s",b[i].holdername);
                fprintf(fp,"\nPhone: %d",b[i].phone);
                fprintf(fp,"\nDue date: %d\n",b[i].duedate);
                i++;
                printf("\nBook added successfully!");
                break;
            case 2:
                flag=0;
                printf("\nEnter the book name: ");
                scanf("%s",name);
                printf("Enter the author name: ");
                scanf("%s",authorname);
                printf("Enter your name: ");
                scanf("%s",holdername);
                for(j=0;j<i;j++){
                    if (strcmp(name, b[j].name) == 0 && strcmp(authorname, b[j].author)==0 && strcmp(holdername, b[j].holdername)==0){
                        b[j].holdername[0]='\0';
                        b[j].phone=0;
                        b[j].duedate=0;
                        flag=1;
                        printf("\nBook returned successfully!");
                        break;
                    }
                }
                if(flag==0){
                    printf("\nNo information found.");
                }
                break;
            case 3:
                flag=0;
                printf("\nEnter the book name: ");
                scanf("%s",name);
                printf("Enter the author name: ");
                scanf("%s",authorname);
                for(j=0;j<i;j++){
                    if (strcmp(name,b[j].name)==0 && strcmp(authorname,b[j].author)==0){
                        printf("\nHolder name: %s",b[j].holdername);
                        printf("\nHolder phone: %d",b[j].phone);
                        printf("\nDue date: %d",b[j].duedate);
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("\nBook not found.");
                }
                break;
            case 4:
                printf("\nDue records:\n");
                for(j=0;j<i;j++){
                    if(b[j].duedate!=0){
                        printf("\nBook: %s",b[j].name);
                        printf("\nHolder: %s",b[j].holdername);
                        printf("\nDue date: %d\n",b[j].duedate);
                    }
                }
                break;
            case 5:
                free(b);
                fclose(fp);
                printf("\nProgram ended.");
                return 0;
            default:
                printf("\nInvalid choice.");
        }
    }
}