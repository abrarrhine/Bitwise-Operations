
/**
     PID          Name
   -----------------------------------------------------
1: abrarr18       Abrar Islam
2: camilaarb      Camila Arbaiza
**/ 

// On our honor:
//
// - We have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants 
// assigned to this course.
//
// - We have not used C language code obtained from another student, 
// the Internet, or any other unauthorized source, either modified
// or unmodified. 
//
// - If any C language code or documentation used in our program 
// was obtained from an authorized source, such as a text book or
// course notes, that has been clearly noted with a proper citation
// in the comments of our program.
//
// - We have not designed this program in such a way as to defeat or
// interfere with the normal operation of the Curator System.
//
// <Abrar Islam>    <Camila Arbaiza> 
// <abrarr18>       <camilaarb>

/* 
 * CS:APP Data Lab 
 * 
 * <Abrar Islam (abrarr18)>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 * 
 *   Explanation of analysis:
 * 
 *   We first create the word, then create 4 variables that represent the bytes starting 
 *   from the right. Each byte has 1's on every third bit position and it is shifted to
 *   the left to represent the whole 32 bits. The byte variables are then added together, 
 *   this creates the binary 32 bit integer that has 1's every third bit (continuously). 
 *   Then we OR the sum with the 'word' variable to modify the bits in "word" that are located 
 *   at the same position of the 1's in the "sum" variable. 
 * 
 */
int thirdBits(void) {
	int x =0; 
	int byte1 = 73;
	int byte2 = 146 << 8; 
	int byte3 = 36 << 16; 
	int byte4 = 73 << 24; 
	
	int sum = byte1+ byte2+ byte3 + byte4;
	
	return x|sum; 
	/**
	int x = 0;
	int y = 1;
	for (int i =0; i <32; i+= 3){
		x = x|y;
		y= y<<3;
	}
  return x;
  **/
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 * 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 * 
 *   Explanation of analysis:
 * 
 *   First we created a mask with a 1 at the location of the sign bit (32nd location) 
 *   then we AND the mask with the X variable that way we keep only the sign bit 
 *   we shifted the result 31 bits to the right, that way we have this value in the 
 *   LSB location, then we inverted the value and added one to get the answer. 
 *   This works because in case the value is 0 this doesn't change the sign of 0, 
 *   and in case the value is -1, it changes it to 1. 
 * 
 */
int isNegative(int x) {
	int mask = 1 << 31; 
	int comp = ( mask & x) >> 31; 
	comp = (~comp) + 1; 
	return comp; 
	/**
	int mask = 1<<31;
	
	if ((x & (1 <<31)) != 0){
		return 1;
	}
  return 0;
  **/ 
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 * 
 *   Explanation of analysis:
 * 
 *   First we found the quotient of x/8 by shifting 3 bits to the right 
 *   (since 2 to the power 3 is 8). Then we stored the remainder of x/8 
 *   by anding x with 7 (0000...0111). Then we obtain x/2 (or 4x/8) by shifting q 2 bits 
 *   to the right, then we add q because x/8 + 4x/8 = 5x/8. 
 *   Finally we handled the overflow by shifting x to the right 31 bits and keeping the 
 *   sign bit by anding it with 7, then adding that to the remainder, the remainder shifted 
 *   2 bits to the left, and the division we got earlier (5x/8). 
 * 
 */
int multFiveEighths(int x) {
	int q = x>> 3; 
	int rem = x & 7; 
	int division = q + (q << 2); 
	
	return division + (rem + (rem << 2)+ (x>> 31 & 7) >> 3);
	
	//x = (x >> 3) + (x >> 1) + 3;
	/**int total = x>>3; 
	int rem = x & 7; 
	total += total <<2;
	total += rem; 
	
	return total; 
    **/
  //return x;
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 * 
 *   Explanation of analysis:
 * 
 *   So, we moved odd bits to the position of even bits and vice versa. Then we swapped 
 *   consecutive pairs. Then we swapped fourths where the fourths are a group of 4 bits. 
 *   Then we swapped bytes where bytes are a group of 2 fourths and finally we swapped 
 *   pairs of bytes. 
 * 
 */
int bitReverse(int x) {
	
	int _0x5555 = (0x55 << 8) + 0x55; 
	int _0x3333 = (0x33 << 8) + 0x33; 
	int _0x0F0F = (0x0F << 8) + 0x0f; 
	
	int bits = (_0x5555 << 16) + _0x5555;
	int pairs = (_0x3333 << 16) + _0x3333; 
	int fourths = (_0x0F0F << 16) + _0x0F0F; 
	int bytes = (0xFF << 16) + 0xFF; 
	int longP = (0xFF << 8) + 0xFF;
	
	x = ((x >> 1) & bits) | (( x & bits) << 1); 
	x = ((x >> 2) & pairs) | (( x & pairs) << 2); 
	x = ((x >> 4) & fourths) | (( x & fourths) << 4); 
	x = ((x >> 8) & bytes) | (( x & bytes) << 8); 
	x = ((x >> 16) & longP) | ( x << 16 ); 
	
	return x; 
	
	/**
	x = ((x & 0x55555555) << 1) | (( x & 0xAAAAAAAA) >> 1); 
	x = ((x & 0x33333333) << 2) | (( x & 0xCCCCCCCC) >> 2); 
	x = ((x & 0x0F0F0F0F) << 4) | (( x & 0xF0F0F0F0) >> 4); 
	x = ((x & 0X00FF00FF) << 8) | (( x & 0xFF00FF00) >> 8);
	x = ((x & 0x0000FFFF) << 16) | (( x & 0xFFFF0000) >> 16);
	
	return x;
	**/   
	  
}
