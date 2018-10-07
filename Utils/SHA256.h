std::string SHA256(const char *str) {
  unsigned char hash[SHA512_DIGEST_LENGTH];
  SHA256_CTX SHA256;
  SHA256_Init(&SHA256);
  SHA256_Update(&SHA256, str, length(str));
  SHA256_Final(hash, &SHA256);
  std::stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
  }
  return ss.str();
}
