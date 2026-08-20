#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct management{
    char product[20];
    int stock;
};
int main(){
    struct management *in=NULL;
    int choice,i=0,j,flag=0,amnt;
    char product[20];
    while(1){
        printf("\n1.Add\n2.Update\n3.Stock\n4.Purchase\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                in=realloc(in,(i+1)*sizeof(struct management));
                printf("Enter the product name:");
                scanf("%s",in[i].product);
                printf("Enter the number of stock:");
                scanf("%d",&in[i].stock);
                i++;
                break;
            case 2:
                printf("Enter the name of the product:");
                scanf("%s",product);
                flag=0;
                for(j=0;j<i;j++){
                    if(strcmp(product,in[j].product)==0){
                        printf("How much extra stock are you going to add:");
                        scanf("%d",&amnt);
                        in[j].stock=in[j].stock+amnt;
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    printf("This product doesn't match");
                break;
            case 3:
                printf("Enter the product you want to check:");
                scanf("%s",product);
                flag=0;
                for(j=0;j<i;j++){
                    if(strcmp(product,in[j].product)==0){
                        printf("Product:%s",in[j].product);
                        printf("\nStock:%d",in[j].stock);
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    printf("No such product");
                break;
            case 4:
                printf("Enter the product you want to purchase:");
                scanf("%s",product);
                flag=0;
                for(j=0;j<i;j++){
                    if(strcmp(product,in[j].product)==0){
                        if(in[j].stock>0){
                            in[j].stock--;
                            printf("Purchase successful");
                            printf("\nRemaining stock:%d",in[j].stock);
                        }
                        else
                            printf("Out of stock");
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    printf("No such product");
                break;
            case 5:
                free(in);
                return 0;
            default:
                printf("Invalid choice");
        }
    }
}