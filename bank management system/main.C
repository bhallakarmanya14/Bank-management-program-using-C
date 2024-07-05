/*
 * This file is part of Bank management program structure using C.
 *
 * Copyright (C) 2024 karmanya bhalla
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#define maxacc 100

typedef struct {
    int accNum;
    long long int bal;
    int pwd;
    char name[50];
    char dob[15];
    char citizenship_number[20];
    char address[100];
    char phone_number[15];

}Account;


Account accounts[maxacc];
static int numAccounts = 0;

void createAccount() {
	if (numAccounts == maxacc) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    char name[50];
    char dob[15];
    char citizenship_number[20];
    char address[100];
    char phone_number[15];
    
    int balance;
    int pwd;
    accounts[numAccounts].accNum = numAccounts + 1;
	printf("Enter name: ");
    scanf("%s", &accounts[numAccounts].name);
    printf("Enter DOB: ");
    scanf("%s", &accounts[numAccounts].dob);
    printf("Enter citizenship number: ");
    scanf("%s", &accounts[numAccounts].citizenship_number);
    printf("Enter address: ");
    scanf("%s", &accounts[numAccounts].address);
    printf("Enter phone no. : ");
    scanf("%s", &accounts[numAccounts].name);
	printf("Enter initial balance: ");
    scanf("%d", &accounts[numAccounts].bal);
	printf("Enter password: ");
    scanf("%d", &accounts[numAccounts].pwd);
    printf("Account created successfully. %d \n",accounts[numAccounts].accNum);
    numAccounts++;
}

void update() {
	int acc_num;
    printf("Enter account number to update: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accNum == acc_num) {
        	
            printf("Enter new address: ");
            scanf("%s",&accounts[i].address);
            printf("Enter new phone number: ");
            scanf("%s", &accounts[i].phone_number);
            printf("Information updated successfully.\n");
            break;
        }else{
        	printf("account not found !!");
		}
	}
}
void remove_acc() {
    int acc_num;
    int pwd;
	printf("Enter account number to remove: ");
    scanf("%d", &acc_num);
    printf("Enter account password: ");
    scanf("%d", &pwd);
    
    for (int i = 0; i < numAccounts; ++i){
        if (accounts[i].accNum == acc_num)
		{if (accounts[i].pwd == pwd) 
			{printf("Welcome, %d\n", accounts[i].accNum);
			printf("Account removed successfully.\n");
			break;
        }
    }else{
        printf("Account not found.\n");
        break;
   		}
	}
}
/*void loginf(){
	int accountNumber;
    int balance;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter account password: ");
    scanf("%d", &pwd);
    for (int i = 0; i < numAccounts; ++i){                                    breaks certain functions so removed this code snippet
		if (accounts[i].accNum == acc_num){
			if (accounts[i].pwd == pwd){
				printf("Welcome, %d\n", accounts[i].accNum);
				return true;
        }  
	} 
}
}*/
void add_balance(){
	int accountNumber;
    int balance;
    int bal;
    int pwd;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0;i < numAccounts; ++i) {
        if (accounts[i].accNum == accountNumber) {
            printf("Enter amount to add : \n");
            scanf("%d",&bal);
        pww:
            printf("Enter password: ");
            scanf("%d",&pwd);
            if (accounts[i].pwd == pwd){
            	accounts[i].bal += bal;
            	printf("balance succesfully updated");
				printf("%d",accounts[i].bal);
            }
			else{
            	goto pww;
			}
            
        }
    }  
} 

void transfer(){
	int accountNumber, balance, pwd, acs;
    long long int amt;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0;i < numAccounts;++i) {
        if (accounts[i].accNum == accountNumber) {
            printf("Enter amount to transfer : \n");
            scanf("%lld",&amt);
            printf("Enter account to transfer to : \n");
            scanf("%d",&acs);
        pww:
            printf("Enter password: ");
            scanf("%d",&pwd);
            if (accounts[i].pwd == pwd){
            	accounts[acs].bal += amt;
            	accounts[i].bal -= amt;
            	printf("amount succesfully transferred to %d ",acs);
				printf("%d",accounts[i].bal);
            }
			else{
            	goto pww;
			}
            break;
        }  
    }    
}


void see() {
    int acc_num;
    printf("Enter account number to see details: ");
    scanf("%d", &acc_num);

    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accNum == acc_num) {
            printf("\nAccount Details:\n");
            printf("Account Number: %d\n", accounts[i].accNum);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %lld \n", accounts[i].bal);
            printf("citizenship number : %s \n", accounts[i].citizenship_number);
            printf(".....");
            break;
		}else{
			printf("account not found !!");
		}
	}
}

void Information() {
	
    printf("\nBanking Activities Menu:\n");
    printf("1. Open Account\n");
    printf("2. EDIT/UPDATE account details\n");
    printf("3. Perform Transactions\n");
    printf("4. Add balance \n");
    printf("5. Remove Account\n");
    printf("6. See Account Details\n");
    printf("7. Exit\n");
}

int main(){
    int choice;
    do {
        Information();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                update();
                break;
            case 3:
                transfer();
                break;
            case 4:
                add_balance();
                break;
            case 5:
                remove_acc();
                break;
            case 6:
                see();
                break;
            case 7:
            	printf("exiting");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

}
