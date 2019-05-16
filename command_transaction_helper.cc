#include <iostream>
#include <stack>

using namespace std;

namespace NM_0
{
class Account
{
    int acct_id;
    int amount;
public:
    Account(int id, int amt) : acct_id(id), amount(amt)
    {
        
    }
    int GetAccountId() const
    {
        return acct_id;
    }
    int GetBalance() const
    {
        return amount;
    }
    void Withdraw(size_t amt)
    {
        amount -= amt;
    }
    void Deposit(size_t amt)
    {
        amount += amt;
    }
};

class Command
{
protected:
    size_t transaction_amount = 0;
public:
    Command(size_t amount) : transaction_amount(amount){}
    virtual void Execute(Account &acc) = 0;
    virtual void UnExecute(Account &acc) = 0;
};

class WithdrawCommand : public Command
{
public:    
    WithdrawCommand(size_t amount) : Command(amount){}
    virtual void Execute(Account &acc)
    {
        acc.Withdraw(transaction_amount);
    }
    virtual void UnExecute(Account &acc)
    {
        acc.Deposit(transaction_amount);
    }
};

class DepositCommand : public Command
{
public:
    DepositCommand(size_t amount) : Command(amount){}
    virtual void Execute(Account &acc)
    {
        acc.Deposit(transaction_amount);
    }
    virtual void UnExecute(Account &acc)
    {
        acc.Withdraw(transaction_amount);
    }
};

class CommandRepository
{
    stack<Command*> command_repository;
    public:
    void AddCommand(Command* cmd)
    {
        command_repository.push(cmd);
    }
    Command* LastCommand()
    {
        Command* cmd = command_repository.top();
        command_repository.pop();
        return cmd;
    }
};

class TransactionHelper
{
    Account &acc;
    CommandRepository cmd_repo;
public:
    TransactionHelper(Account& acc) : acc(acc){}

    void Deposit(size_t amount)
    {
        Command *cmd = new DepositCommand(amount);
        cmd->Execute(acc);
        cmd_repo.AddCommand(cmd);
    }
    void Withdraw(size_t amount)
    {
        Command *cmd = new WithdrawCommand(amount);
        cmd->Execute(acc);
        cmd_repo.AddCommand(cmd);
    }
    size_t GetBalance() const
    {
        return acc.GetBalance();
    }
    void Undo()
    {
        Command* cmd = cmd_repo.LastCommand();
        cmd->UnExecute(acc);
    }
};

int main()
{
    Account acc(101, 5000);
    TransactionHelper helper(acc);
#if 0
    cout<<acc.GetBalance()<<endl; 
    acc.Withdraw(1000);
    acc.Withdraw(500);
    acc.Deposit(2000);
    acc.Withdraw(500);
    acc.Deposit(700); 
    cout<<acc.GetBalance()<<endl;   
#endif
    helper.Withdraw(1000);
    helper.Deposit(10000);
    cout<<helper.GetBalance()<<endl;
    helper.Undo();
    cout<<helper.GetBalance()<<endl;
}
}

/*
    One can directly perform operation on Account and just register undo commands such type of implementation are known as compensation
*/
