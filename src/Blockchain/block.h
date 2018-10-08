class Block {
public:
  int index = 0;
  int nonce = 0;
  int difficulty = 5;
  long timestamp = 0;
  std::string minerAddress = "";
  std::string previousHash = "";
  std::string hash = "";

public:
  Block();
  Block(Block *previousBlock);

  void create();
  void setIndex(int index);
  void setNonce(int nonce);
  void setDifficulty(int difficulty);
  void setTimestamp(long timestamp);
  void setMinerAddress(std::string minerAddress);
  void setPreviousHash(std::string previousHash);
  void setHash(std::string hash);

  std::string calculateHash();
};
