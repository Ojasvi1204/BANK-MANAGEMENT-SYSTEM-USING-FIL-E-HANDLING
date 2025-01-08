#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_management {
    char user_name[30];
    int user_DOB;
    int user_age; 
    int house_no;
    char apartment_name[40];
    char city[30];
    char country[30];
    double aadhaar_number;
    int account_number;
    int account_balance;
};

void save_to_file(struct bank_management *bank, int count) {
    FILE *file = fopen("bank_accounts.dat", "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    fwrite(bank, sizeof(struct bank_management), count, file);
    fclose(file);
}

int load_from_file(struct bank_management *bank) {
    FILE *file = fopen("bank_accounts.dat", "rb");
    if (!file) {
        return 0;
    }
    int count = fread(bank, sizeof(struct bank_management), 50, file);
    fclose(file);
    return count; 
}

int main() {
    struct bank_management bank[50];
    int i = load_from_file(bank);
    int account_number = (i > 0) ? bank[i - 1].account_number + 1 : 110000;
    
    while (1) {
        int choice;
        printf("\n\n1. Open a new bank account\n");
        printf("2. Deposit money into your bank account\n");
        printf("3. Withdraw money from your bank account\n");
        printf("4. Check balance\n");
        printf("5. View your bank account details\n");
        printf("6. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (i >= 50) {
                    printf("Account limit reached! Cannot open more accounts.\n");
                    break;
                }
                printf("\nEnter your personal details\n");
                printf("Enter your name: ");
                scanf(" %[^\n]%*c", bank[i].user_name);
                printf("Enter your DOB (YYYYMMDD): ");
                scanf("%d", &bank[i].user_DOB);
                printf("Enter your age: ");
                scanf("%d", &bank[i].user_age);
                printf("Enter your house number: ");
                scanf("%d", &bank[i].house_no);
                printf("Enter your apartment name: ");
                scanf(" %[^\n]%*c", bank[i].apartment_name);
                printf("Enter your city: ");
                scanf(" %[^\n]%*c", bank[i].city);
                printf("Enter your country: ");
                scanf(" %[^\n]%*c", bank[i].country);
                printf("Enter your Aadhaar number: ");
                scanf("%lf", &bank[i].aadhaar_number);
                
                bank[i].account_number = account_number++;
                bank[i].account_balance = 0; 
                printf("\nYour records are stored.");
                printf("\nYour account number is: %d\n", bank[i].account_number);
                i++;
                save_to_file(bank, i); 
                break;
                 
            case 2: {
                int acc_num, amount;
                printf("Enter your account number: ");
                scanf("%d", &acc_num);
                
                for (int j = 0; j < i; j++) {
                    if (bank[j].account_number == acc_num) {
                        printf("Enter amount in rupees to deposit: ");
                        scanf("%d", &amount);
                        bank[j].account_balance += amount;
                        printf("Your new balance is: %d\n", bank[j].account_balance);
                        save_to_file(bank, i); 
                        break;
                    }
                }
                break;
            }
                    
            case 3: {
                int acc_num, amount;
                printf("Enter your account number: ");
                scanf("%d", &acc_num);
                
                for (int j = 0; j < i; j++) {
                    if (bank[j].account_number == acc_num) {
                        printf("Enter amount to withdraw: ");
                        scanf("%d", &amount);
                        if (amount > bank[j].account_balance) {
                            printf("Insufficient funds!\n");
                        } else {
                            bank[j].account_balance -= amount;
                            printf("Your new balance is: %d\n", bank[j].account_balance);
                            save_to_file(bank, i); 
                        }
                        break;
                    }
                }
                break;
            }
                
            case 4: {
                int acc_num;
                printf("Enter your account number: ");
                scanf("%d", &acc_num);
                
                for (int j = 0; j < i; j++) {
                    if (bank[j].account_number == acc_num) {
                        printf("Your current account balance is: %d\n", bank[j].account_balance);
                        break;
                    }
                }
                break;
            }
                
            case 5: {
                int acc_num;
                printf("Enter your account number: ");
                scanf("%d", &acc_num);
                
                for (int j = 0; j < i; j++) {
                    if (bank[j].account_number == acc_num) {
                        printf("\nYour account details are: ");
                        printf("\nYour name is: %s", bank[j].user_name);
                        printf("\nYour DOB is: %d", bank[j].user_DOB);
                        printf("\nYour age is: %d", bank[j].user_age);
                        printf("\nYour house no is: %d ", bank[j].house_no);
                        printf("\nYour apartment name is: %s", bank[j].apartment_name);
                        printf("\nYour city is: %s", bank[j].city);
                        printf("\nYour country is: %s", bank[j].country);
                        printf("\nYour Aadhaar number is: %lf", bank[j].aadhaar_number);
                        printf("\nYour balance is: %d\n", bank[j].account_balance);
                        break;
                    }
                }
                break;
            }
                
            case 6:
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
    }

    return 0;
}
