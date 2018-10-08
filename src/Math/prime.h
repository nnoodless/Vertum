bool isPrime(unsigned long long int n) {
  if (n > 1) {
    for (unsigned long long int i = 2; i < sqrt(n); i++) {
      if (n % i == 0) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

bool isCoprime(unsigned long long int x, unsigned long long int y) {
  if (x < 1 || y < 1) {
    return false;
  } else {
    return gcd(x, y) == 1;
  }
}
