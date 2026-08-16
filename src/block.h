#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include "sha256.h"

// Один блок в цепочке.
class Block {
public:
    int index;              // порядковый номер блока
    long timestamp;         // время создания (Unix-время)
    std::string data;       // полезные данные, напр. "Алиса -> Боб: 5 монет"
    std::string prevHash;   // хеш предыдущего блока
    int nonce;              // число для майнинга (пока не используется, этап 4)
    std::string hash;       // хеш этого блока

    // Конструктор: принимает номер, данные и хеш предыдущего блока.
    Block(int idx, const std::string& blockData, const std::string& previousHash)
        : index(idx),
          timestamp(std::time(nullptr)),
          data(blockData),
          prevHash(previousHash),
          nonce(0) {
        // Сразу считаем хеш блока при создании.
        hash = calculateHash();
    }

    // Считает хеш блока из всех его полей.
    // Склеиваем поля в одну строку и прогоняем через sha256.
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