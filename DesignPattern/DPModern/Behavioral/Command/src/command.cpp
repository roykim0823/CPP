#include "command_composite.h"
#include <algorithm> 	// for for_each

using namespace std;

void command()	
{
  	BankAccount ba;

	// use vector to compose a list of commands
  	vector<BankAccountCommand> commands
    {
      BankAccountCommand{ba, BankAccountCommand::deposit, 100},
      BankAccountCommand{ba, BankAccountCommand::withdraw, 200}
    };

  	cout << "Balance = " << ba.balance << endl;

  	for (auto& cmd : commands)
    	cmd.call();

  	cout << "Balance = " << ba.balance << endl;
  	
	for (auto it = commands.rbegin(); it != commands.rend(); ++it)
  	{
    	it->undo();
  	}

  	cout << "Balance = " << ba.balance << endl;
	cout << endl;
}

void command_composite()
{
  BankAccount ba;
  /*vector<BankAccountCommand> commands{*/
  CompositeBankAccountCommand commands {
    BankAccountCommand{ba, BankAccountCommand::deposit, 100},
    BankAccountCommand{ba, BankAccountCommand::withdraw, 200}
  };

  cout << "Balance = " << ba.balance << endl;

  // apply all the commands
  // same as 
  // commands.call();
  /*
  for (auto& cmd : commands)
  {
    cmd.call();
  }
  */
  commands.call();

  cout << "Balance = " << ba.balance << endl;

  /*
  // same as commands.undo()
  for_each(commands.rbegin(), commands.rend(),
    [](BankAccountCommand& cmd) { cmd.undo(); });
  */
  commands.undo();

  cout << "Balance = " << ba.balance << endl;
  cout << endl;
}

void command_transfer() {
	BankAccount ba1, ba2;
  	CompositeBankAccountCommand commands {
    	BankAccountCommand{ba1, BankAccountCommand::deposit, 800},
    	BankAccountCommand{ba2, BankAccountCommand::deposit, 300}
  	};

	commands.call();
  	cout << "Balance1 = " << ba1.balance << " ";
  	cout << "Balance2 = " << ba2.balance << endl;

	MoneyTransferCommand transfer(ba1, ba2, 400);

	transfer.call();
  	cout << "Balance1 = " << ba1.balance << " ";
  	cout << "Balance2 = " << ba2.balance << endl;
}


int main() {
	cout << "command()..." << endl;
	command();
	cout << "command_composite()..." << endl;
	command_composite();
	cout << "command_transfer()..." << endl;
	command_transfer();

	return 0;
}
