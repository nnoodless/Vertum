unsigned long long int gcd(unsigned long long int x, unsigned long long int y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
