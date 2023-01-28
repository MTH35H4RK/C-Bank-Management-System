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
