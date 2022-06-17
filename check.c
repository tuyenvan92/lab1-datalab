#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}



unsigned float_half(unsigned uf)
{
  unsigned sign = uf & 0x80000000u;
  unsigned expo = (uf >> 23) & 0xFF;
  unsigned value =(uf & 0x7FFFFF);
  
  // NaN or inf
  if (expo == 0xFF)
    return uf;

  if (!expo)
  {
    // Denomalized
    if (!((value & 0x3) - 0x3))
      value = value + 1; // round up
    value = (value) >> 1;
    return (sign) | value;
  }

  // Normalized
  if (expo != 1)
  {
    expo -= 1;
    return (sign) | (expo << 23) | value; 
  }
  else
  {

    if (value == 0x7fffff)
      return sign | 1 << 23;

    if (!((value & 0x3) - 0x3))
      value = value + 1; // round up
    value = (value >> 1) | 1 << 22;
    return (sign) | value; //expo = 0
  }
}

unsigned test_float_half(unsigned uf) {
  float f = u2f(uf);
  float hf = 0.5*f;
  if (isnan(f))
    return uf;
  else
    return f2u(hf);
}

int main()
{
  #if 1
    unsigned ori = 0x80800001u;
    unsigned f = float_half(ori);
    unsigned tf = test_float_half(ori);

    printf("ori: %x \nflo: %x \ntes: %x\n", ori, f, tf);

    for (unsigned i = 0; i < 0xfffffffe; ++i)
    {
      ori = i;
      f = float_half(ori);
      tf = test_float_half(ori);
      if (f != tf)
      {
        printf("ori: %x \nflo: %x \ntes: %x\n", ori, f, tf);
      }
    }

    #else

    int first = 0x80000000;
    int second = 0x80000000;
    printf("%d %d\n", addOK(first, second), test_addOK(first, second));
    long long sum = (long long ) first + second;
    printf("%lld %d\n\n", sum, (int)sum);
    printf("%llx %x\n\n", sum, (int)sum);
    printf("%d\n\n", sum == (int)sum);
    long long uu = (long long) first;
    printf("%llx", uu);
    #endif


    
    return 0;
}