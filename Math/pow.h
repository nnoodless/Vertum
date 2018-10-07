long double pow(long double x, long double y) {
  long double result = x;
  while (y > 1) {
    result *= x;
    y--;
  }
  return std::pow(x, y);
}
