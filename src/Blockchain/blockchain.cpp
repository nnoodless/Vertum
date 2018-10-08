Blockchain::Blockchain() { std::cout << "Created Blockchain..." << std::endl; }

void Blockchain::addBlock(Block *block) {
  // block->hash = utils::toHex(block->hash);
  this->currentDifficulty = block->difficulty;
  this->chain.emplace_back(block);
  std::cout << "Added Block: " << block->hash << std::endl;
}

void Blockchain::createGenesisBlock() {
  Block genesisBlock;
  genesisBlock.setHash(genesisBlock.calculateHash());
  std::cout << "Created Genesis Block: " << genesisBlock.hash << std::endl;
  this->addBlock(&genesisBlock);
}

void Blockchain::mineBlock(const char *minerAddress) {
  std::cout << "Mining Block (difficulty: " << this->currentDifficulty << ")..."
            << std::endl;

  std::string startStr = "";

  Block block(this->getLatestBlock());
  block.minerAddress = minerAddress;

  long latestAddedBlock = 0;

  do {
    Block *latestBlock = this->getLatestBlock();

    // check string
    if (startStr.size() != this->currentDifficulty) {
      startStr = utils::generateStr('0', this->currentDifficulty);
    }

    if (latestAddedBlock != latestBlock->timestamp) {
      block.previousHash = latestBlock->hash;
      latestAddedBlock = latestBlock->timestamp;
    }

    block.setHash(block.calculateHash());
    block.setNonce(block.nonce + 1);
  } while (block.hash.substr(0, this->currentDifficulty) != startStr);

  std::cout << "Mined Block (miner: " << block.minerAddress
            << "): " << block.hash << std::endl;
  this->addBlock(&block);
}

int Blockchain::getBlocks() { return this->chain.size(); }

bool Blockchain::isValid() {
  for (int i = 1; i < this->getBlocks(); i++) {
    Block *previousBlock = this->getBlock(i - 1);
    Block *currentBlock = this->getBlock(i);

    if (previousBlock->calculateHash() != currentBlock->previousHash) {
      return false;
    }
  }
  return true;
}

Block *Blockchain::getBlock(int index) { return this->chain[index]; }

Block *Blockchain::getLatestBlock() {
  return this->getBlock(this->getBlocks() - 1);
}
