int evenBits(void)
{
  return 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
}
