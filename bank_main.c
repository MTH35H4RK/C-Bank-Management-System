#include <stdio.h>
#include <stdlib.h>
#include "bank_functions.h"

int main() {
  int choice;
  int exit = 0;
  while (!exit) {
    printf("Welcome to Bank System\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        create_account();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        check_balance();
        break;
      case 5:
        exit = 1;
        break;
      default:
        printf("Invalid option. Try again.\n");
    }
  }
  return 0;
}
