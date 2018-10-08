#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <openssl/sha.h>
#include <random>
#include <sstream>
#include <string>
#include <vector>

/* Utils */
#include "./Utils/utils.h"

/* Math */
#include "./Math/math.h"

/* RSA */
#include "./RSA/rsa.h"

/* Block | Blockchain */
#include "./Blockchain/block.h"
#include "./Blockchain/block.cpp"

#include "./Blockchain/blockchain.h"
#include "./Blockchain/blockchain.cpp"

int main() {
  long long start = utils::currentMillis();

  Blockchain blockchain;
  blockchain.createGenesisBlock();

  blockchain.mineBlock("Noodles");

  std::cout << "took: " << utils::currentMillis() - start << " ms" << std::endl;
  return 0;
}

// gcc compile
// g++ vertum.cpp -lcrypto
