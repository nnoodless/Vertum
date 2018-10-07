unsigned long long int modinv(unsigned long long int a,
                              unsigned long long int m) {
  a = a % m;
  for (unsigned long long int x = 1; x < m; x++) {
    if ((a * x) % m == 1) {
      return x;
    }
  }
  return 0;
}
