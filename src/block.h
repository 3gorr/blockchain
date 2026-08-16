#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include "sha256.h"

class Block {
public:
    int index;
    long timestamp;
    std::string data;
    std::string prevHash;
    int nonce;
    std::string hash;

    Block(int idx, const std::string& blockData, const std::string& previousHash)
        : index(idx),
          timestamp(std::time(nullptr)),
          data(blockData),
          prevHash(previousHash),
          nonce(0) {
        hash = calculateHash();
    }

    std::string calculateHash() const {
        std::string toHash = std::to_string(index)
                           + std::to_string(timestamp)
                           + data
                           + prevHash
                           + std::to_string(nonce);
        return sha256(toHash);
    }
};

#endif // BLOCK_H