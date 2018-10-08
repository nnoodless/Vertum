std::string toHex(std::string str) {
  std::stringstream ss;
  ss << "0x";
  for (int i = 0; i < str.size(); i++) {
    ss << std::hex << (int)str[i];
  }
  return ss.str();
}
