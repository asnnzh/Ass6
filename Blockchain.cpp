#include <stdio.h>
#include <ctime>
#include <string>
#include "Blockchain.h"
#include <vector>
Blockchain::Blockchain()
{
    Block  firstBlock = createFistBlock();
    chain.push_back(firstBlock);
}
vector<Block> Blockchain::getChain() {
    return chain;
}
Block Blockchain::createFistBlock()
{
    time_t current;

    TransactionData dataFirstBlock(0, " FirstBlock ", "FirstBlock", time(&current));
    Block firstBlock(0, dataFirstBlock, 0);
    return  firstBlock;
}
void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    size_t previousHash = getLatestBlock()->getBlockHash();
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}
bool Blockchain::isBlockchainValid()
{
    vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.getBlockHash())
            {
                return false;
            }
        }
    }

    return true;
}

void Blockchain::printBlockchain(){
    std::vector<Block>::iterator iterator;

    for (iterator = chain.begin(); iterator != chain.end(); ++iterator)
    {
        Block currentBlock = *iterator;
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.transaction_data.amount);
        printf("\nSenderKey: %s", currentBlock.transaction_data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.transaction_data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.transaction_data.timestamp);
        printf("\nHash: %zu", currentBlock.getBlockHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}