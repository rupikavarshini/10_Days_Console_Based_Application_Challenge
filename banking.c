#include <stdio.h>
#include <string.h>
struct bank {
    char name[10];
    int accntno;
    int balance;
};
void main() {
    struct bank b[50];
    int i = 0, accntno, amnt, flag = 0, j, choice;
    char name[10];
    while (1) {
        printf("\n1. Register");
        printf("\n2. Withdraw");
        printf("\n3. Deposit");
        printf("\n4. Check balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Register
                if (i < 50) {
                    printf("Enter your name: ");
                    scanf("%s", b[i].name);
                    printf("Enter your account no: ");
                    scanf("%d", &b[i].accntno);
                    printf("Enter your balance: ");
                    scanf("%d", &b[i].balance);
                    i++;
                }
                break;
            case 2:
                flag = 0;
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your account number: ");
                scanf("%d", &accntno);
                for (j = 0; j < i; j++) {
                    if ((strcmp(name, b[j].name) == 0) &&
                        (accntno == b[j].accntno)) {
                        printf("Enter the withdrawal amount: ");
                        scanf("%d", &amnt);
                        if (amnt <= b[j].balance) {
                            b[j].balance = b[j].balance - amnt;
                            printf("Withdrawal successful");
                            printf("\nRemaining balance: %d",
                                   b[j].balance);
                        } else {
                            printf("Insufficient balance");
                        }
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    printf("There is no such account registered");
                }
                break;
            case 3:
                flag = 0;
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your account number: ");
                scanf("%d", &accntno);
                for (j = 0; j < i; j++) {
                    if ((strcmp(name, b[j].name) == 0) &&
                        (accntno == b[j].accntno)) {
                        printf("Enter the deposit amount: ");
                        scanf("%d", &amnt);
                        if (amnt <= 50000) {
                            b[j].balance = b[j].balance + amnt;
                            printf("Deposit successful");
                            printf("\nNew balance: %d",
                                   b[j].balance);
                        } else {
                            printf("You can only deposit an amount "
                                   "less than or equal to 50000");
                        }
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    printf("There is no such account registered");
                }
                break;
            case 4:
                flag = 0;
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your account number: ");
                scanf("%d", &accntno);
                for (j = 0; j < i; j++) {
                    if ((strcmp(name, b[j].name) == 0) &&
                        (accntno == b[j].accntno)) {
                        printf("\nName: %s", b[j].name);
                        printf("\nAccount no: %d", b[j].accntno);
                        printf("\nBalance: %d", b[j].balance);
                        flag = 1;
                    }
                }
                if (flag == 0) {
                    printf("There is no such account registered");
                }
                break;
            case 5:
                return;
            default:
                printf("Invalid choice");
        }
    }
}