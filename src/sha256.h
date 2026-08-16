#ifndef SHA256_H
#define SHA256_H

#include <string>
#include "picosha2.h"

inline std::string sha256(const std::string& input) {
    return picosha2::hash256_hex_string(input);
}

#endif // SHA256_H