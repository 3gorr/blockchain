#include <iostream>
#include "block.h"

int main() {
    Block block(1, "Alice -> Bob: 5 coins", "0");

    std::cout << "index:     " << block.index     << "\n";
    std::cout << "timestamp: " << block.timestamp << "\n";
    std::cout << "data:      " << block.data      << "\n";
    std::cout << "prevHash:  " << block.prevHash  << "\n";
    std::cout << "nonce:     " << block.nonce     << "\n";
    std::cout << "hash:      " << block.hash      << "\n\n";

    std::cout << "Пересчёт совпадает с сохранённым хешем? "
              << (block.calculateHash() == block.hash ? "да" : "нет") << "\n";

    return 0;
}