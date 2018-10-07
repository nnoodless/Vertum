class Block {
public:
  int index = 0;
  int nonce = 0;
  int difficulty = 0;

  long timestamp = 0;

  std::string previousHash = "";
  std::string hash = "";

public:
  void create() { this->timestamp = currentMillis(); }

public:
  Block() { this->create(); }

  Block(Block *previousBlock) {
    this->create();
    this->index = previousBlock->index + 1;
    this->previousHash = previousBlock->hash;
  }

public:
  std::string calculateHash() {
    std::stringstream ss;
    ss << toString(this->index);
    ss << toString(this->timestamp);
    ss << toString(this->nonce);
    ss << this->previousHash;
    return SHA512(ss.str().c_str());
  }

public:
  void setIndex(int index) { this->index = index; }
  void setNonce(int nonce) { this->nonce = nonce; }
  void setDifficulty(int difficulty) { this->difficulty = difficulty; }

  void setTimestamp(long timestamp) { this->timestamp = timestamp; }

  void setPreviousHash(std::string previousHash) {
    this->previousHash = previousHash;
  }
  void setHash(std::string hash) { this->hash = hash; }
};
