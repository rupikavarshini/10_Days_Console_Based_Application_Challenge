#include<stdio.h>
#include<string.h>

struct patient{
    char name[10];
    int phone;
    int payment;
    int joined;
    int discharge;
    int doctor;
};

struct doctor{
    char name[20];
    int phone;
};

int main(){
    struct doctor d[20];
    struct patient p[70];
    int i=0,k=0,j,l,choice,phone,amount;
    char name[10];

    for(j=0;j<70;j++){
        p[j].payment=0;
    }

    while(1){
        printf("\n\n1. Add patient");
        printf("\n2. Add doctor");
        printf("\n3. Billing");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                if(i<70){
                    printf("Enter your name: ");
                    scanf("%s",p[i].name);

                    printf("Enter your phone number: ");
                    scanf("%d",&p[i].phone);

                    printf("Enter your date of joining: ");
                    scanf("%d",&p[i].joined);

                    printf("Enter the doctor number: ");
                    scanf("%d",&p[i].doctor);

                    printf("Do your payment to continue further\n");
                    printf("1. Yes\n2. No\n");
                    scanf("%d",&choice);

                    if(choice==1){
                        printf("Enter the amount: ");
                        scanf("%d",&p[i].payment);
                    }

                    i++;
                }
                else{
                    printf("Patient limit reached");
                }
                break;

            case 2:
                if(k<20){
                    printf("Enter your name: ");
                    scanf("%s",d[k].name);

                    printf("Enter your phone number: ");
                    scanf("%d",&d[k].phone);

                    k++;
                }
                else{
                    printf("Doctor limit reached");
                }
                break;

            case 3:
                printf("Enter the name: ");
                scanf("%s",name);

                printf("Enter your phone number: ");
                scanf("%d",&phone);

                for(j=0;j<i;j++){

                    if(strcmp(name,p[j].name)==0 && phone==p[j].phone){

                        printf("Enter the date of discharge: ");
                        scanf("%d",&p[j].discharge);

                        amount=(p[j].discharge-p[j].joined)*25000;

                        printf("Total amount: %d",amount);

                        for(l=j;l<i-1;l++){
                            p[l]=p[l+1];
                        }

                        i--;
                        break;
                    }
                }

                if(j==i){
                    printf("Patient not found");
                }

                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}