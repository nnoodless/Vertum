#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <openssl/sha.h>
#include <random>
#include <sstream>
#include <vector>

/* Utils */
#include "./Utils/utils.h"

/* Math */
#include "./Math/math.h"

/* RSA */
#include "./RSA/rsa.h"

/* Blockchain */
#include "./Blockchain/block.h"
#include "./Blockchain/blockchain.h"

int main() {
  Blockchain blockchain;
  blockchain.createGenesisBlock();

  return 0;
}

// gcc compile
// g++ vertum.cpp -lcrypto
