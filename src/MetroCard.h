#ifndef METROCAD_H
#define METROCARD_H
#include <string>

using namespace std;

class MetroCard
{
private:
    string id;
    double balance;
public:
    MetroCard(string id);
    ~MetroCard();

    double getBalance();
};
#endif