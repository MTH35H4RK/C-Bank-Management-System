#ifndef BANK_FUNCTIONS_H
#define BANK_FUNCTIONS_H

struct BankAccount {
  int accountNumber;
  char accountName[50];
  float balance;
};

void credit(struct BankAccount *account, float amount);
void debit(struct BankAccount *account, float amount);
void checkBalance(struct BankAccount account);
void closeAccount(struct BankAccount *account);
void writeToFile(struct BankAccount account);
struct BankAccount readFromFile(int accountNumber);

#endif
