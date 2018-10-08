class Keypair {
public:
  unsigned long long int p = 0;
  unsigned long long int q = 0;
  unsigned long long int n = 0;
  unsigned long long int totient = 0;
  unsigned long long int e = 0;
  unsigned long long int d = 0;

public:
  Keypair() {
    // p & q & n
    while (this->p == 0) {
      this->p = math::PRIMES[math::random(0, math::PRIMES_LENGTH - 1)];
    }
    while (this->q == 0) {
      this->q = math::PRIMES[math::random(0, math::PRIMES_LENGTH - 1)];
    }
    while (this->n == 0) {
      this->n = math::PRIMES[math::random(0, math::PRIMES_LENGTH - 1)];
    }

    // RSA totient
    this->totient = (p - 1) * (q - 1);

    // e - (takes too long to process)
    while (math::isCoprime(this->e, this->totient) == false) {
      this->e = math::PRIMES[math::random(0, math::PRIMES_LENGTH - 1)];
    }

    // d
    this->d = math::modinv(e, totient);
  }

public:
  int encrypt(int i) { return math::modinv(math::pow(i, this->e), this->n); }

  int decrypt(int i) { return math::modinv(math::pow(i, this->d), this->n); }

  int *encrypt(const char *str) {
    int length = utils::length(str);
    int *output = new int[length+1];
    output[0] = length;

    for (int i = 0; i < length; i++) {
      output[i+1] = this->encrypt(str[i]);
    }

    return output;
  }

  std::string decrypt(int* encrypted) {
    int length = encrypted[0];
    std::stringstream ss;

    for (int i = 1; i < length+1; i++) {
      ss<<(char)this->decrypt(encrypted[i]);
    }

    return ss.str();
  }
};
