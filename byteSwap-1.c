int byteSwap(int x, int n, int m)
{
  // mindex = m * 8;
  int m_index = m << 3;
  int n_index = n << 3;

  int mask_at_byte_m = 0xff << m_index;
  int mask_at_byte_n = 0xff << n_index;

  int value_at_m = ((mask_at_byte_n & x) >> n_index) << m_index;
  int value_at_n = ((mask_at_byte_m & x) >> m_index) << n_index;

  value_at_m = value_at_m & mask_at_byte_m;
  value_at_n = value_at_n & mask_at_byte_n;

  x = (x & (~mask_at_byte_m)) | value_at_m;
  x = (x & (~mask_at_byte_n)) | value_at_n;
  return x;
}
