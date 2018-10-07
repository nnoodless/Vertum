class Blockchain {
private:
  std::vector<Block *> chain{};

public:
  Blockchain() { std::cout << "Created Blockchain..." << std::endl; }

public:
  void addBlock(Block *block) {
    this->chain.emplace_back(block);
    std::cout << "Added Block: " << block << '\n';
  }

  void createGenesisBlock() {
    Block genesisBlock;
    genesisBlock.setHash(genesisBlock.calculateHash());
    this->addBlock(&genesisBlock);
  }

  void start

public:
  int getBlocks() { return this->chain.size(); }

public:
  bool isValid() {
    for (int i = 1; i < this->getBlocks(); i++) {
      Block *previousBlock = this->getBlock(i - 1);
      Block *currentBlock = this->getBlock(i);

      if (previousBlock->calculateHash() != currentBlock->previousHash) {
        return false;
      } else if (true) {
      }
    }
    return true;
  }

public:
  Block *getBlock(int index) { return this->chain[index]; }

  Block *getLatestBlock() { return this->getBlock(this->getBlocks() - 1); }
};
