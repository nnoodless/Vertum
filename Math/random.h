unsigned long long int random(unsigned long long int lowest,
                              unsigned long long int highest) {
  std::random_device rd;
  std::map<unsigned long long int, unsigned long long int> hist;
  std::uniform_int_distribution<unsigned long long int> dist(lowest, highest);
  return dist(rd);
}
