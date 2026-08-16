#ifndef SHA256_H
#define SHA256_H

#include <string>
#include "picosha2.h"

// Простая обёртка над PicoSHA2.
// Принимает строку, возвращает её SHA-256 хеш в виде hex-строки (64 символа).
inline std::string sha256(const std::string& input) {
    return picosha2::hash256_hex_string(input);
}

#endif // SHA256_H