/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
  return ~((~x) & (~y));
}
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
  return 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
  return ~0;
}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
  int evenBit = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
  return !((evenBit & x) + ~evenBit + 1);
}
/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{
  int evenBit = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24);
  return !!(x & (~evenBit));
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
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
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int addOK(int x, int y)
{
  // get first bit of x and y
  int firstBitX = (x >> 31) & 1;
  int firstBitY = (y >> 31) & 1;
  
  int sum = x + y;
  
  // get the first bit of sum
  int firstBitSum = (sum >> 31) & 1;

  // firstBitSum is 0 -> sum >= 0, but firstBitX = FirstBitY = 1 (<0)
  int isOverFlowAdd2Negative = firstBitX & firstBitY & (!firstBitSum);

  // the same as above
  int isOverFlowAdd2Positive = (!firstBitX) & (!firstBitY) & firstBitSum;
  return !(isOverFlowAdd2Negative | isOverFlowAdd2Positive);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  // if x
  // set tmp to 0 or 1 depend of x
  int tmp, maskX, maskY;

  tmp = !!x;
  // set all bit to 1 or 0
  tmp = (tmp << 31) >> 31;

  // tmp & y will be 0 or y
  maskX = tmp & y;

  // if not x
  tmp = !x;
  // set all bit to 1 or 0;
  tmp = (tmp << 31) >> 31;

  // tmp & z will be 0 or z
  maskY = tmp & z;
  return maskX | maskY;
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  int tmp;
  int isGreaterThan0x30;
  int isLessThan0x39;

  // check if x <= 0x39
  // calculate x - 0x39 <= 0 <=> x - 0x3a < 0 <-> firstBit is 1
  tmp = x + (~(0x3a)) + 1;
  isLessThan0x39 = (tmp >> 31) & 1;

  // check if 0x30 <= x <=> 0x2f < x <=> 0x2f - x < 0
  // calculate 0x2f - x = 0x2f + (-x) 
  tmp = 0x2f + ((~x)) + 1;
  isGreaterThan0x30 = (tmp >> 31) & 1;

  return isLessThan0x39 & isGreaterThan0x30;
}
/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
  int mask;
  int byte_index;
  int res;
  byte_index = n << 3; // n * 8;

  mask = 0xff << byte_index;

  res = x & (~mask);
  c = c << byte_index;

  res = res | c;
  return res;
}
/*
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n)
{
  int mask;
  int saved;
  int res;

  // (1 << n) - 1 = 2^n - 1
  mask = (1 << n) + (~0);

  // save n rightest most bit
  saved = (x & mask);

  // move saved bit and mask to the rightest position
  // saved >>= 32 - n = 32 + ((~n) + 1) = 33 + (~n)
  saved = saved << (33 + (~n));
  mask = mask << (33 + (~n));

  // unset bit at where rorated bit is placed
  res = (x >> n) & (~mask);

  // place rotated bit
  res = res | saved;

  return res;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value (Tmax), and when negative overflow occurs,
 *          it returns minimum negative value (Tmin)
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
  // get first bit of x and y
  int firstBitX = (x >> 31) & 1;
  int firstBitY = (y >> 31) & 1;
  
  int sum = x + y;
  
  // get the first bit of sum
  int firstBitSum = (sum >> 31) & 1;

  // firstBitSum is 0 -> sum >= 0, but firstBitX = FirstBitY = 1 (<0)
  int isOverFlowAdd2Negative = firstBitX & firstBitY & (!firstBitSum);

  // the same as above
  int isOverFlowAdd2Positive = (!firstBitX) & (!firstBitY) & firstBitSum;
  int addOK = !(isOverFlowAdd2Negative | isOverFlowAdd2Positive);

  // when negative overflow occur
  int int_min = 1 << 31;
  // when positive overflow occur
  int int_max = ~int_min;

  int res;

  // if isOverFlowAdd2Negative:
  // if isOverFlowAdd2Negative, set all bit of x is 1, otherwise 0
  isOverFlowAdd2Negative = (isOverFlowAdd2Negative << 31) >> 31;
  
  // so the res will be int_min
  res = int_min & isOverFlowAdd2Negative;

  // if isOverFlowAdd2Positive:
  // if isOverFlowAdd2Negative, set all bit of x is 1, otherwise 0
  isOverFlowAdd2Positive = (isOverFlowAdd2Positive << 31) >> 31;

  // so the res will be int_max
  res = res | (int_max & isOverFlowAdd2Positive);

  // is addOK
  addOK = (addOK << 31) >> 31;

  res = res | (sum & addOK);

  return res;
}
/*
 * Extra credit
 */
/*
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */


unsigned float_abs(unsigned uf)
{
  unsigned mask_value = 0x007fffffu;
  unsigned mask_expo = 0x7f800000u;
  unsigned mask_sign = 0x80000000u;

  unsigned expo = uf & mask_expo;
  unsigned value = uf & mask_value;

  // if expo = 255
  // left-most-bit is 1, then expo = 1
  expo = (expo + 0x00800000u) & mask_sign;
  
  if (expo && value)
  {
    return uf;
  }
  else 
  {
    return uf & (~mask_sign);
  }
}

/*
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf)
{
  unsigned sign = uf >> 31;
  unsigned expo = (uf >> 23) & 0xFF;
  unsigned value =(uf & 0x7FFFFF);
  unsigned bias = 0x7F;
  unsigned res;
  
  // NaN and +-Inf
  if (expo == 0xFF) 
    return 0x80000000u;
  
  // denormalized floating point number
  // or the expo is less than bias -> the value of casted int is 0
  if (expo < bias)
    return 0;
  
  // normalized floating point number
  expo = expo - bias;
  
  // overflow
  // the largest integer a int variable can store is 2^31 - 1 
  if (expo >= 31)
    return 0x80000000u;
  
  // get integer result after shift corresponding bits
  if (expo > 22) 
    res = value << (expo - 23);
  else 
    res = value >> (23 - expo);

  // add 1 << exp for normalized case: 
  // because: normalized case value is: (-1)^sign * 2^(expo-bias) * 1.value
  res = res + (1 << expo);
  
  // if the original value is negative, change result to negative number
  if (sign)
    res = -res;
  
  return res;
}

/*
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf)
{
  unsigned sign = uf & 0x80000000u;
  unsigned expo = (uf >> 23) & 0xFF;
  unsigned value =(uf & 0x7FFFFF);
  
  // NaN or inf
  // return uf
  if (expo == 0xFF)
    return uf;

  // expo = 0
  if (!expo)
  {
    // Denomalized
    // round up
    if (!((value & 0x3) - 0x3))
      value = value + 1; 

    // shift value to right 1 time
    value = (value) >> 1;
    return (sign) | value;
  }

  // Normalized
  if (expo != 1)
  {
    // decrease expo by 1: the value will be /2
    expo -= 1;
    return (sign) | (expo << 23) | value; 
  }
  else
  {
    // special case: 0xffffff -> 0x800000
    // special case: 0x80ffffff -> 0x80800000
    if (value == 0x7fffff)
      return sign | 1 << 23;

    // round up
    if (!((value & 0x3) - 0x3))
      value = value + 1;

    // the expo becomes 0, shift value (frac) to right 1 time, and set the first bit of it.
    value = (value >> 1) | 1 << 22;
    return (sign) | value;
  }
}
