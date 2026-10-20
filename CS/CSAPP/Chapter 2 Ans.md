## Chapter Problems
- Skipped: 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.14, 2.16, 2.17, 2.18, 2.19, 2.20, 2.21, 2.22, 2.23, 2.24, 2.28, 2.29, 2.30, 2.33, 2.34, 2.36, 2.39, 2.45, 2.46, 2.47, 2.48, 2.49, 
- To be done: 2.35, 2.36, 2.37
- 2.10:
	- ![[Pasted image 20260923105724.png]]
	- step 1: a, a\^b
	- step 2: b, a\^b
	- step 3: b, a
- 2.11:
	- ![[Pasted image 20260924164335.png]]
	- A. 0, 2k
	- B. because it executes when both pointers are towards the middle, so when they xor each other it goes zero
	- C. just make the condition <
- 2.12:
	- ![[Pasted image 20260924164759.png]] ![[Pasted image 20260924164808.png]]
	- A. x & 0xFF
	- B. ~(x ^(x & 0xFF)) | (x & 0xFF)   OR (solution) x ^ ~0xFF
	- C. x | 0xFF
- 2.13:
	- ![[Pasted image 20260924170006.png]]
	- what bool_or does is it takes each bit that is set to 1 in either x or y and sets it to 1.. what if we do bis(x,y)? this will create a z where x is oned then additional oned bits in y are oned as well.. makes sense to me.. but is there an edge case? hmm.. i dunno.. let's just submit it
	- bool_or: bis(x,y)
	- what bool_xor does is it takes each bit in both x and y and clears it.. then adds the unique bits in each of them.. i think a good way to clear the unique bits is just bic, so i'll bis two bics
	- bool_xor: bis(bic(x,y), bic(y,x))
- 2.15:
	- ![[Pasted image 20260924171559.png]]
	- !(x^y)
- 2.25:
	- ![[Pasted image 20260930135146.png]]
	- It's because length-1 will equal 0-1 which in unsigned overflows to UMax.
	- We can solve it by multiple ways, the cleanest is doing i < length.
- 2.26:
	- ![[Pasted image 20260930135441.png]]![[Pasted image 20260930135450.png]]
	- A. It always shows that s is longer than t unless they're equal.
	- B. When s is smaller than t, their difference is a negative number which in unsigned overflows making it a positive number, so s can't be considered smaller than t.
	- C. Make it strlen(s) > strlen(t).
- 2.27:
	- ![[Pasted image 20260930142940.png]]
	- ```
‌	  int uadd_ok(unsigned x, unsigned y) {
‌		  return (x+y) >= x;
‌	  }
	  ```
- 2.31:
	- ![[Pasted image 20260930153727.png]]
	- Because two's complement numbers form an abelian group aka (x+y)-y will always equal x and vice versa.
-  2.32:
	- ![[Pasted image 20261003161427.png]]![[Pasted image 20261003161444.png]]
	- The answer is Tmin, since Tmin could be 1000, and negation means ~x+1, so it'll return to 1000, making y = -y in this case.. inducing errors. Also note that the range of signed numbers is x to -x-1, which has no positive counterpart.
- 2.38:
	- ![[Pasted image 20261007105833.png]]
	- 1, 2, 3, 4, 5, 8, 9
- 2.40:
	- ![[Pasted image 20261007110219.png]]
	- (x<<3)-x
	- (x<<4)+(x<<3)+(x<<2)+(x<<1)
	- (x<<5)-(x<<2)
	- (x<<6)-(x<<3)-x
- 2.41:
	- ![[Pasted image 20261007113659.png]]
	- If the number of operations in B is lower than that in A.
	- When n = m, use A, when n = m + 1, use either, when n > m + 1, use B.
- 2.42:
	- ![[Pasted image 20261014095635.png]]
	- ```
	  int div16(int x) {
		  int bias = (x >> 31) & 0xf;
		  int result = (x + bias) >> 4;
		  return result; 
	  }
	  ```
- 2.43:
	- ![[Pasted image 20261014102339.png]]
	- x is multiplied by 32 then an x is removed, so M is 31.
	- y is divided by 2^3 which is 8, so N is 8.
- 2.44:
	- ![[Pasted image 20261014102956.png]]
	- A. it's wrong cuz at T_Min it can negatively overflow when you reduce it by 1, and it's not greater than zero so it'll compute to 0.
	- B. the first statement could easily be false if x == 7, or in any case where x = 2^k+7 where k >=3, about the second one, it says that shifting left anything like that by 29 bits, assuming integers are 32 bits, will overflow.. that is correct, because that will make the most significant three bits 111 all the times where the first statement isn't correct. so this statement is always correct.
	- C. it is wrong in the range between T_Max and U_Max.
	- D. true
	- E. False due to T_min
	- F. true
	- G. true when we substitute ~y as -y-1
- 