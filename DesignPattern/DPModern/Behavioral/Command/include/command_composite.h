#pragma once
#include "command.h"
#include <vector>
#include <initializer_list>

// vector doesn't have virtual dtor, but who cares?
struct CompositeBankAccountCommand : std::vector<BankAccountCommand>, Command
{
  	CompositeBankAccountCommand(const std::initializer_list<value_type>& items)
    : std::vector<BankAccountCommand>(items)
  	{}

  	void call() override {
    	for (auto& cmd : *this)
      		cmd.call();
  	}

  	void undo() override {
    	for (auto it = rbegin(); it != rend(); ++it)
      		it->undo();
  	}
};

struct DependentCompositeCommand : CompositeBankAccountCommand
{
  	explicit DependentCompositeCommand(const std::initializer_list<value_type>& items)
    : CompositeBankAccountCommand{ items } {}

  	void call() override {
    	bool ok = true;
    	for (auto& cmd : *this) {
      		if (ok) {
        		cmd.call();
       			ok = cmd.succeeded;
      		} else {
        		cmd.succeeded = false;
      		}
    	}
  	}
};

struct MoneyTransferCommand : DependentCompositeCommand
{
  	MoneyTransferCommand(BankAccount& from,	BankAccount& to, int amount)
	: DependentCompositeCommand 
	{
      	BankAccountCommand{from, BankAccountCommand::withdraw, amount},
      	BankAccountCommand{to, BankAccountCommand::deposit, amount}
    } {}
};
