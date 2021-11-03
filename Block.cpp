#include <stdio.h>
#include <string>
#include "Block.h"
#include "TransactionData.h"
int Block::getIndex()
{
    return index;
}
size_t Block::generate_hash()
{
    string toHashS = to_string(transaction_data.amount) + transaction_data.receiverKey + transaction_data.senderKey + to_string(transaction_data.timestamp);
    hash<string> tDataHash;
    hash<string> prevHash;

    return tDataHash(toHashS) ^ (prevHash(to_string(previous_hash)) << 1);
}
Block::Block(int index, TransactionData data, size_t prev_hash)
{
this->index = index;
this->transaction_data = data;
this->previous_hash = prev_hash;
this->block_hash = generate_hash();
}
size_t Block::getBlockHash()
{
    return block_hash;
}
size_t Block::getPreviousHash()
{
    return previous_hash;
}

bool Block::isHashValid()
{
    return generate_hash() == getBlockHash();
}
