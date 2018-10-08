class Blockchain {
private:
  std::vector<Block *> chain{};
  int currentDifficulty = 0;

public:
  Blockchain();

  void addBlock(Block *block);
  void createGenesisBlock();
  void mineBlock(const char* minerAddress);

  int getBlocks();

  bool isValid();

  Block *getBlock(int index);
  Block *getLatestBlock();
};
