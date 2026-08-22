#include<stdio.h>
#include<string.h>
struct people{
    int roomno;
    char name[10];
    int phonenumber;
    int checkin;
    int checkout;
    float checkinT;
    float checkoutT;
};
void main(){
    FILE *fp;
    struct people p[20];
    int i=0,j,choice,phonenumber,roomno,flag,k,amnt;
    char name[10];
    fp=fopen("stay.txt","a+");
    if(fp==NULL){
        printf("File cannot be opened");
        return;
    }
    for(j=0;j<20;j++){
        p[j].roomno=0;
    }
    while(1){
        printf("\n\n1.Room booking");
        printf("\n2.Checkout");
        printf("\n3.Customer record");
        printf("\n4.Billing");
        printf("\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(i<20){
                    printf("\nEnter your name: ");
                    scanf("%s",p[i].name);
                    printf("Enter your phone number: ");
                    scanf("%d",&p[i].phonenumber);
                    printf("Enter your room number: ");
                    scanf("%d",&roomno);
                    flag=0;
                    for(j=0;j<i;j++){
                        if(p[j].roomno==roomno){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        printf("\nThis room is already occupied");
                        break;
                    }
                    p[i].roomno=roomno;
                    printf("Enter your check in date: ");
                    scanf("%d",&p[i].checkin);
                    printf("Enter your check out date: ");
                    scanf("%d",&p[i].checkout);
                    printf("Enter your check in time: ");
                    scanf("%f",&p[i].checkinT);
                    printf("Enter your checkout time: ");
                    scanf("%f",&p[i].checkoutT);
                    printf("\nRoom available and booked successfully");
                    fprintf(fp,"\n\nName: %s",p[i].name);
                    fprintf(fp,"\nPhone number: %d",p[i].phonenumber);
                    fprintf(fp,"\nRoom no: %d",p[i].roomno);
                    fprintf(fp,"\nCheck in date: %d",p[i].checkin);
                    fprintf(fp,"\nCheck out date: %d",p[i].checkout);
                    fprintf(fp,"\nCheck in time: %.2f",p[i].checkinT);
                    fprintf(fp,"\nCheck out time: %.2f",p[i].checkoutT);
                    i++;
                }
                else{
                    printf("\nNo rooms available");
                }
                break;
            case 2:
                printf("\nEnter your name: ");
                scanf("%s",name);
                printf("Enter your phone number: ");
                scanf("%d",&phonenumber);
                printf("Enter your room no: ");
                scanf("%d",&roomno);
                flag=0;
                for(j=0;j<i;j++){
                    if((strcmp(name,p[j].name)==0) &&
                       (phonenumber==p[j].phonenumber) &&
                       (roomno==p[j].roomno)){
                        for(k=j;k<i-1;k++){
                            p[k]=p[k+1];
                        }
                        i--;
                        flag=1;
                        printf("\nCheckout successful");
                        break;
                    }
                }
                if(flag==0){
                    printf("\nCustomer record not found");
                }
                break;
            case 3:
                printf("\nEnter your name: ");
                scanf("%s",name);
                printf("Enter your phone number: ");
                scanf("%d",&phonenumber);
                printf("Enter your room no: ");
                scanf("%d",&roomno);
                flag=0;
                for(j=0;j<i;j++){
                    if((strcmp(name,p[j].name)==0) &&
                       (phonenumber==p[j].phonenumber) &&
                       (roomno==p[j].roomno)){
                        printf("\nName: %s",p[j].name);
                        printf("\nPhone number: %d",p[j].phonenumber);
                        printf("\nRoom no: %d",p[j].roomno);
                        printf("\nCheck in date: %d",p[j].checkin);
                        printf("\nCheck out date: %d",p[j].checkout);
                        printf("\nCheck in time: %.2f",p[j].checkinT);
                        printf("\nCheck out time: %.2f",p[j].checkoutT);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("\nCustomer record not found");
                }
                break;
            case 4:
                printf("\nEnter your name: ");
                scanf("%s",name);
                printf("Enter your phone number: ");
                scanf("%d",&phonenumber);
                printf("Enter your room no: ");
                scanf("%d",&roomno);
                flag=0;
                for(j=0;j<i;j++){
                    if((strcmp(name,p[j].name)==0) &&
                       (phonenumber==p[j].phonenumber) &&
                       (roomno==p[j].roomno)){
                        amnt=(p[j].checkout-p[j].checkin)*1000;
                        printf("\nName: %s",p[j].name);
                        printf("\nRoom no: %d",p[j].roomno);
                        printf("\nAmount to be paid: %d",amnt);
                        fprintf(fp,"\nAmount to be paid: %d",amnt);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("\nCustomer record not found");
                }
                break;
            case 5:
                fclose(fp);
                return;
            default:
                printf("\nInvalid choice");
        }
    }
}