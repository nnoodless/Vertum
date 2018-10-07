#include <chrono>
#include <ctime>
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

int main() {
  Keypair keypair;

  const char *message = "well hello there!";
  int *encrypted = keypair.encrypt(message);
  std::string decrypted = keypair.decrypt(encrypted);

  std::cout << "Encrypted (" << message << "): " << encrypted[0] << std::endl;
   std::cout << "Decrypted: " << decrypted << std::endl;

  return 0;
}
