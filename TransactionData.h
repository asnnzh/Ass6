#ifndef UNTITLED8_TRANSACTIONDATA_H
#define UNTITLED8_TRANSACTIONDATA_H
#include <ctime>
#include <vector>
#include <cstddef>
#include <string>
using namespace std;
struct TransactionData
{
    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;

    TransactionData(){};

    TransactionData(double amount, string senderKey, string receiverKey, time_t timetamp)
    {
        this->amount = amount;
        this->senderKey = senderKey;
        this->receiverKey = receiverKey;
        this->timestamp = timetamp;
    };
};


#endif //UNTITLED8_TRANSACTIONDATA_H
