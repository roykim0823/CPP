#pragma once
#include "bank_account.h"

struct Command
{
	bool succeeded;		// to deal with a failure in DependentCompositeCommand
  	virtual ~Command() = default;
  	virtual void call() = 0;
  	virtual void undo() = 0;
};

struct BankAccountCommand : Command
{
	bool withdrawal_succeeded;
  	BankAccount& account;
  	enum Action { deposit, withdraw } action;
  	int amount;

  	BankAccountCommand(BankAccount& account, 
    const Action action, const int amount)
    : account(account), action(action), amount(amount),
	  withdrawal_succeeded(false) {}

  	void call() override {
    	switch (action) {
    	case deposit:
      		account.deposit(amount);
      		break;
    	case withdraw: 
      		withdrawal_succeeded = account.withdraw(amount);
      		break;
    	default: break;
    	}
  	}

  	void undo() override {
    	switch (action) {
    	case withdraw:
      		if(withdrawal_succeeded)
				account.deposit(amount);
      		break;
    	case deposit:
      		account.withdraw(amount);
      		break;
    	default: break;
    	}
  	}
};
