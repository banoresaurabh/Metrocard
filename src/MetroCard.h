#ifndef METROCARD_H
#define METROCARD_H

#include <string>

using namespace std;

class MetroCard
{
private:
    string id;
    double balance;

    static unordered_map<string, MetroCard*> metroCardInstances;
public:
    MetroCard(string id);
    ~MetroCard();

    double getBalance();
    void setBalance(double balance);
    static MetroCard* getInstance(string id);
};
#endif
