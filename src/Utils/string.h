std::string generateStr(char c, int length) {
  char str[length + 1];
  for (int i = 0; i < length; i++) {
    str[i] = c;
  }
  str[length] = '\0';
  return std::string(str);
}
