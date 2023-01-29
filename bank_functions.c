#include <string.h>
#include <stdio.h>
#include "bank_functions.h"

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
