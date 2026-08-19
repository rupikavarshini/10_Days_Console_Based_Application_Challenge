//employee record slary calculation /payslip
#include<stdio.h>
#include<string.h>

struct employee {
    int phone;
    char name[10];
    int salary;
};

void main() {
    struct employee e[20];
    int i=0,j,choice,phone,salary,days,flag=0;
    char name[10];

    while(1) {

        printf("\n1. Add employee");
        printf("\n2. View salary");
        printf("\n3. Salary calculation");
        printf("\n4. Payslip");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                if(i<20) {
                    printf("Enter your name: ");
                    scanf("%s",e[i].name);

                    printf("Enter your phone no: ");
                    scanf("%d",&e[i].phone);

                    printf("Enter your salary: ");
                    scanf("%d",&e[i].salary);

                    i++;
                }
                break;

            case 2:
                flag=0;

                printf("Enter your name: ");
                scanf("%s",name);

                printf("Enter your phone number: ");
                scanf("%d",&phone);

                for(j=0;j<i;j++) {

                    if((strcmp(name,e[j].name)==0) &&
                       (phone==e[j].phone)) {

                        printf("Salary: %d",e[j].salary);
                        flag=1;
                    }
                }

                if(flag==0) {
                    printf("Match not found");
                }

                break;

            case 3:
                flag=0;

                printf("Enter your name: ");
                scanf("%s",name);

                printf("Enter your phone number: ");
                scanf("%d",&phone);

                for(j=0;j<i;j++) {

                    if((strcmp(name,e[j].name)==0) &&
                       (phone==e[j].phone)) {

                        printf("Enter the no of days worked: ");
                        scanf("%d",&days);

                        e[j].salary=days*2000;

                        printf("Salary: %d",e[j].salary);

                        flag=1;
                    }
                }

                if(flag==0) {
                    printf("Match not found");
                }

                break;

            case 4:
                printf("Payslip feature coming soon");
                break;

            case 5:
                return;

            default:
                printf("Invalid choice");
        }
    }
}