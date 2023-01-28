#include <string.h>
#include <stdio.h>

struct BankAccount {
  int accountNumber;
  char accountName[50];
  float balance;
};

void credit(struct BankAccount *account, float amount) {
  account->balance += amount;

}

void debit(struct BankAccount *account, float amount) {
  if (account->balance >= amount) {
    account->balance -= amount;
  } else {
    printf("Insufficient balance\n");
  }
}

void checkBalance(struct BankAccount account) {
  printf("Account Name: %s\n", account.accountName);
  printf("Account Balance: %.2f\n", account.balance);
}

void closeAccount(struct BankAccount *account) {
  account->balance = 0;
  account->accountNumber = -1;
  strcpy(account->accountName, "");
}

void writeToFile(struct BankAccount account) {
  FILE *fp;
  fp = fopen("bank_accounts.dat", "ab");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }
  fwrite(&account, sizeof(struct BankAccount), 1, fp);
  fclose(fp);
}

struct BankAccount readFromFile(int accountNumber) {
  struct BankAccount account;
  FILE *fp;
  fp = fopen("bank_accounts.dat", "rb");
  if (fp == NULL) {
    printf("Error opening file\n");
    account.accountNumber = -1;
    return account;
  }
  while (fread(&account, sizeof(struct BankAccount), 1, fp)) {
    if (account.accountNumber == accountNumber) {
      fclose(fp);
      return account;
    }
  }
  fclose(fp);
  account.accountNumber = -1;
  return account;
}


int main() {
  int choice;
  int account_number;
  float amount;

  printf("1. Credit\n");
  printf("2. Debit\n");
  printf("3. Check balance\n");
  printf("4. Close account\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter account number: ");
      scanf("%d", &account_number);
      printf("Enter amount: ");
      scanf("%f", &amount);
      // code to credit account with error handling for invalid account number
      credit();
      break;
    case 2:
      printf("Enter account number: ");
      scanf("%d", &account_number);
      printf("Enter amount: ");
      scanf("%f", &amount);
      // code to debit account with error handling for insufficient balance and invalid account number
      debit();
      break;
    case 3:
      printf("Enter account number: ");
      scanf("%d", &account_number);
      // code to check balance with error handling for invalid account number
      checkBalance();
      break;
    case 4:
      printf("Enter account number: ");
      scanf("%d", &account_number);
      // code to close account with error handling for invalid account number
      closeAccount();
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}
