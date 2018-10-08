Block::Block() { this->create(); }
Block::Block(Block *previousBlock) {
  this->create();
  this->index = previousBlock->index + 1;
  this->previousHash = previousBlock->hash;
}

void Block::create() { this->timestamp = utils::currentMillis(); }
void Block::setIndex(int index) { this->index = index; }
void Block::setNonce(int nonce) { this->nonce = nonce; }
void Block::setDifficulty(int difficulty) { this->difficulty = difficulty; }
void Block::setTimestamp(long timestamp) { this->timestamp = timestamp; }
void Block::setMinerAddress(std::string minerAddress) {
  this->minerAddress = minerAddress;
}
void Block::setPreviousHash(std::string previousHash) {
  this->previousHash = previousHash;
}
void Block::setHash(std::string hash) { this->hash = hash; }

std::string Block::calculateHash() {
  std::string index = std::to_string(this->index);
  std::string timestamp = std::to_string(this->timestamp);
  std::string nonce = std::to_string(this->nonce);
  std::string previousHash = std::string(this->previousHash.c_str());
  std::string minerAddress = std::string(this->minerAddress);

  std::string str =
      index + "" + timestamp + "" + nonce + previousHash + minerAddress;
  return utils::SHA256(str);
}
