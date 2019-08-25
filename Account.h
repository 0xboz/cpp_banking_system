//
// Created by 0xboz on 8/24/19.
//

#ifndef CPP_BANKING_SYSTEM_ACCOUNT_H
#define CPP_BANKING_SYSTEM_ACCOUNT_H

#include <vector>
#include <string>
using namespace std;

class Account {
private:
    static long cumulative_acct_num;
    long acct_num;
    string first_name;
    string last_name;
    long acct_amt;

public:
    static vector<Account *> v_list;

    Account(string first_name, string last_name, long acct_amt);

    Account(long account_num, string first_name, string last_name, long acct_amt);

    Account() : Account(getAccountNumber(), "", "", 0L) {};

    Account(Account &a);

    void setFirstName(string f_name);

    void setLastName(string l_name);

    void setAccountAmount(long account_amt);

    long getAccountNumber();

    string getFirstName();

    string getLastName();

    long getAccountAmount();

    static long getLastAccountNumber(); // Retrieve account info and get the latest account number
    static vector<Account *> getAll();

    friend ifstream &operator>>(ifstream &ifs, vector<Account *> &v_list);

    friend ostream &operator<<(ostream &out, Account &a);

    friend ofstream &operator<<(ofstream &ofs, Account &a);

    static void open();

    static bool compareAccountNumber(Account *acct_ptr, long acct_num) {
        return (*acct_ptr).getAccountNumber() == acct_num;
    }

    static Account *searchByAccountNumber(long acct_num);

    static void balance();

    static void ledgerDump();

    static void deposit();

    static void withdraw();

    static void close();

    static void showAll();

    ~Account();
};


#endif //CPP_BANKING_SYSTEM_ACCOUNT_H
