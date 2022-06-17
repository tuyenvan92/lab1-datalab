int anyOddBit(int x)
{
  int evenBit = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
  return !!(x & (~evenBit));
}
