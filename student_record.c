#include <stdio.h>
#include <string.h>
struct student {
    char name[10];
    int rollno;
    int eng;
    int phy;
    int mat;
};
int main(){
    struct student s[30];
    int i=0,rollno,j,flag,choice,k,subchoice;
    char name[10];
    while(1){
        printf("\n\n1. Register");
        printf("\n2. Edit");
        printf("\n3. Remove");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    if(i<30){
                    printf("\nEnter your name: ");
                    scanf("%s", s[i].name);
                    printf("Enter your roll no: ");
                    scanf("%d",&s[i].rollno);
                    printf("Enter your English mark: ");
                    scanf("%d",&s[i].eng);
                    printf("Enter your Physics mark: ");
                    scanf("%d",&s[i].phy);
                    printf("Enter your Maths mark: ");
                    scanf("%d",&s[i].mat);
                    i++;
                    printf("\nStudent registered successfully!");
                } else {
                    printf("\nNo more students can be registered.");
                }
                break;
            case 2:
                flag=0;
                printf("\nEnter the name of the student you want to edit: ");
                scanf("%s",name);
                printf("Enter the roll no: ");
                scanf("%d",&rollno);
                for(j=0;j<i;j++){
                    if (strcmp(s[j].name,name)==0 && s[j].rollno==rollno){
                        printf("\nWhich subject do you want to edit?");
                        printf("\n1. English");
                        printf("\n2. Physics");
                        printf("\n3. Maths");
                        printf("\nEnter your choice: ");
                        scanf("%d", &subchoice);
                        if(subchoice==1){
                            printf("Enter the new mark: ");
                            scanf("%d",&s[j].eng);
                        }
                        else if(subchoice==2){
                            printf("Enter the new mark: ");
                            scanf("%d",&s[j].phy);
                        }
                        else if(subchoice==3){
                            printf("Enter the new mark: ");
                            scanf("%d",&s[j].mat);
                        }
                        else {
                           printf("Invalid subject choice.");
                        }
                        flag=1;
                        break;
                   }
                }
                if(flag==0){
                    printf("\nThere is no such student registered.");
                }
                break;
            case 3:
                flag=0;
                printf("\nEnter the name of the student you want to remove: ");
                scanf("%s",name);
                printf("Enter the roll no: ");
                scanf("%d",&rollno);
                for(j=0;j<i;j++){
                    if(strcmp(s[j].name,name)==0&&s[j].rollno==rollno){
                        for(k=j;k<i-1;k++){
                            s[k]=s[k+1];
                        }
                        i--;
                        flag=1;
                        printf("\nStudent removed successfully.");
                        break;
                    }
                }
                if (flag==0){
                    printf("\nThere is no such student registered.");
                }
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice.");
        }
    }
    return 0;
}