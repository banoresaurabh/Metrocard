#ifndef METROCARD_H
#define METROCARD_H

#include <string>

class MetroCard
{
private:
    std::string id;
    double balance;

    static std::unordered_map<std::string, MetroCard*> metroCardInstances;
public:
    MetroCard(std::string id);
    ~MetroCard();

    double getBalance();
    void setBalance(double balance);
    static MetroCard* getInstance(std::string id);
};
#endif
