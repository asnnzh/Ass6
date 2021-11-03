//#include <iostream>
//#include "TransactionData.h"
//#include "Block.h"
//#include "Blockchain.h"
//using namespace std;
//int main() {
//    Blockchain Awesome;
//    TransactionData data1;
//    time_t data1Time;
//    data1.amount = 1.5;
//    data1.receiverKey = "Nazira";
//    data1.senderKey = "Sallly";
//    data1.timrstamp = time(&data1Time);
//     Awesome.addBlock(data1);
//     cout << "Is chain valid?" << endl;
//    cout  << Awesome.isChainValid() << endl;
//
//
//}
#include <iostream>
#include <ctime>
#include "Blockchain.h"
using namespace std;

int main()
{
    Blockchain coin;
    time_t firstdatatime;
    TransactionData first_data(2.5, "Aruzhan", "Omar", time(&firstdatatime));
    coin.addBlock(first_data);

    time_t seconddatatime;
    TransactionData seconddata(1.2, "Amira", "Askar", time(&firstdatatime));
    coin.addBlock(seconddata);
    coin.printBlockchain();
    cout << "\nIs chain still valid? %d\n", coin.isBlockchainValid();
    Block *hackBlock =coin.getLatestBlock();
    hackBlock->transaction_data.amount = 50000;
    hackBlock->transaction_data.receiverKey = "Alan";
    coin.printBlockchain();
    cout <<"\nIs chain still valid? %d\n", coin.isBlockchainValid();
    return 0;
}