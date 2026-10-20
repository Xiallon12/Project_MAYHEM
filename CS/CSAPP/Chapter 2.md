# Representing and Manipulating Information

#### Introduction
- Computers use binary digits or bits to represent numbers.
- There are three main binary representations:
	1. Unsigned. (U)
	2. Two's-complement. (T)
	3. Floating-point. (F)
- Integral representations (U and T) represent a limited range accurately, while F represents a wider range approximately.
- Integral operations are associative and commutative, F operations aren't.

#### 2.1
- Bytes are blocks of 8 bits.
- ![[Pasted image 20260923101047.png]]
- Hexadecimal notation is 0 through F corresponding to 0 to 15 in decimal, preceded by 0x (where letters can be either case).
- Each hex character corresponds to 4 bits, so 0101 is 5, and 1111 is F.
- ![[Pasted image 20260923101438.png]]
- ![[Pasted image 20260923101653.png]]
- To convert decimal to hex, repeatedly divide by 16 putting the remainder in the result going RTL.
- *Word size* is the max size of the virtual address space.
- Windows, Linux, IOS, and Android, are little-endian, while the Internet is big-endian.
- ![[Pasted image 20260923105424.png]]
- Logical operations in C are: ||, && and !
	- They are equivalent to logical OR, AND, and NOT respectively.
	- They consider 0 to be false, and anything else to be true.
	- Their results are only 0 or 1.
- There are 4 shift operations in C:
	1. Logical Left Shift <<, shifts bits to the left, filling the right with 0s.
	2. Arithmetic Left Shift <<, same as the logical one.
	3. Logical Right Shift >>, shifts bits to the right, filling the left with 0s.
	4. Arithmetic Right Shift >>, shifts bits to the right, copying the sign bit to the left.
- Most compilers use arithmetic shifts for signed numbers.

#### 2.2 
- ![[Pasted image 20260924173052.png]]

- ![[Pasted image 20260924173211.png]]
- ![[Pasted image 20260924173232.png]]
- Unsigned values are the literal interpretation of bits, as each bit is considered a positive power of 2.
- ![[Pasted image 20260924173538.png]]
- ![[Pasted image 20260924173617.png]]
- Bijection means a one-to-one function.
- Two's Complement values consider the most significant bit to be the sign bit, where when it's 0 the number is positive, and when it's 1 the number is negative.
- ![[Pasted image 20260924173830.png]]
- ![[Pasted image 20260924173928.png]]
  
- ![[Pasted image 20260924174128.png]]
- Conversion between Unsigned and Two's Complement preserves bit representation in most C implementations.
- ![[Pasted image 20260924174940.png]]
- ![[Pasted image 20260924175155.png]]
  
- ![[Pasted image 20260924175202.png]]
- ![[Pasted image 20260924175243.png]]
- To specify a number as unsigned in C you use the suffix u or U. like 123U.
- With printf, you can use specifiers %d, %u, and %x for signed decimal, unsigned decimal, and hexadecimal.
- To expand an unsigned number, add leading zeroes.
- ![[Pasted image 20260927151856.png]]
- To expand a two's complement number, add leading copies of the sign bit.
- ![[Pasted image 20260927151935.png]]
- Truncation removes the most significant bits of the number till it reaches the target length.
- ![[Pasted image 20260930134354.png]]
- ![[Pasted image 20260930134444.png]]
  
- ![[Pasted image 20260930134519.png]]
- ![[Pasted image 20260930134530.png]]

#### 2.3
- Unsigned addition overflows when the sum uses more bits than word length, making the sum equal to sum % 2^w, or basically subtracting 2^w from the sum.
- ![[Pasted image 20260930141957.png]]
- ![[Pasted image 20260930142348.png]]
- If an overflow happens, the result will be smaller than the two variables.
- ![[Pasted image 20260930142515.png]]
- ![[Pasted image 20260930142701.png]]

- Subtraction in unsigned arithmetic is basically adding the unsigned additive inverse of a number, as per the following equation:
- ![[Pasted image 20260930143712.png]]
- ![[Pasted image 20260930143726.png]]

- In two's complement addition, results can be either too big (positive) or too small (negative), in case of positive overflow it's typical to that of unsigned, in case of negative it's also a modular operation or simply adding 2^w to the result, as per the equation:
- ![[Pasted image 20260930144503.png]]
- You can detect two's complement overflow if the sign of the sum is different than the two variables (if they're similar).
- ![[Pasted image 20260930152033.png]]
- ![[Pasted image 20260930152207.png]]
  
- The negation of each number is its negative except Tmin, as its negation is itself.
- ![[Pasted image 20261004005226.png]]
- ![[Pasted image 20261004005342.png]]

- Multiplication of two w-sized words results in a word of size up to 2w, so C just takes the lower w bits.
- ![[Pasted image 20261005002928.png]]
- ![[Pasted image 20261005003423.png]]
- ![[Pasted image 20261005003448.png]]
- Multiplication used to use many cycles, so computers now optimize by multiplying by powers of 2, and other constants.
- ![[Pasted image 20261007100336.png]]
- ![[Pasted image 20261007100626.png]]
- This means that shift operations are equivalent to multiplying and dividing by powers of 2.
- ![[Pasted image 20261007100748.png]]
- ![[Pasted image 20261007100822.png]]
- Division is mostly even slower than multiplication.
- Division use logical right shift and arithmetic right shift for U and T respectively.
- Division is rounded down for positive numbers and up for negatives, aka always towards 0.
- ![[Pasted image 20261014093823.png]]
- ![[Pasted image 20261014094852.png]]
- ![[Pasted image 20261014095505.png]]
- Thus integer arithmetic performed by computers is mostly modular arithmetic.

#### 2.4
- ![[Pasted image 20261015072610.png]]
- Rational numbers are in the form $V = (-1)^s * x * 2^y$, which is called IEEE floating point representation.
- Floating point is simply considering numbers to the right of the 'point' as the numeric place value (1 or 0 in case of binary) multiplied by a negative power of 2, starting 1.
- Format Structure: Floating-point values encode numbers in scientific form as $(-1)^s \times M \times 2^E$, divided into three fields: a Sign bit ($s$), an Exponent field ($\text{exp}$), and a Fraction field ($\text{frac}$).
- Normalized Values (Standard Case): Occur when $\text{exp}$ is neither all zeros nor all ones. The real exponent is decoded with a bias as $E = e - \text{Bias}$ (where $\text{Bias} = 127$ for single precision), and the significand has an implicit leading one ($M = 1 + f$), yielding an extra bit of precision for free.
- **Denormalized Values (Near Zero)**: Occur when $\text{exp}$ is all zeros. The exponent is fixed to $E = 1 - \text{Bias}$, and the implicit leading one is dropped ($M = f$), enabling the representation of exact $\pm 0.0$ and providing gradual underflow for numbers between $0$ and $2^{-126}$.
- **Special Values (Infinity and Errors)**: Occur when $\text{exp}$ is all ones. If $\text{frac}$ is all zeros, the value represents $\pm\infty$ (overflow or division by zero); if $\text{frac}$ is non-zero, it represents $\text{NaN}$ (invalid operations like $\sqrt{-1}$).
- **Exponent Biasing Purpose**: Exponents are shifted by an offset ($\text{Bias}$) rather than stored in two's complement so that positive and negative powers can be sorted and compared using standard, fast unsigned integer comparison logic.
  
  (AI-generated notes)

