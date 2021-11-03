#ifndef UNTITLED8_BLOCKCHAIN_H
#define UNTITLED8_BLOCKCHAIN_H
#include "TransactionData.h"
#include "Block.h"
#include <ctime>
#include <vector>
#include <cstddef>
class Blockchain
{
private:
    Block createFistBlock();
    vector<Block> chain;

public:
    Blockchain();
    vector<Block> getChain();
    Block *getLatestBlock();
    bool isBlockchainValid();
    void addBlock(TransactionData data);
    void printBlockchain();
};


#endif //UNTITLED8_BLOCKCHAIN_H
