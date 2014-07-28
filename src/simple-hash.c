enum {
    HASH_MULTIPLER = 0x9e370001,
};

unsigned long hash_long(unsigned long val, unsigned int bits)
{
    unsigned long hash = val * HASH_MULTIPLER;
    return hash >> (32 - bits);
}
