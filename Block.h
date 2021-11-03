#ifndef UNTITLED8_BLOCK_H
#define UNTITLED8_BLOCK_H
#include "TransactionData.h"
class Block
{
private:
    int index;
    size_t block_hash;
    size_t previous_hash;
    size_t generate_hash();

public:
    Block(int idx, TransactionData d, size_t prevHash);

    int getIndex();
    size_t getBlockHash();
    size_t getPreviousHash();
    TransactionData transaction_data;
    bool isHashValid();
};

#endif //UNTITLED8_BLOCK_H
