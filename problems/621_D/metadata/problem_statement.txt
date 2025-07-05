Wet Shark asked Rat Kwesh to generate three positive real numbers x, y and z, from 0.1 to 200.0, inclusive. Wet Krash wants to impress Wet Shark, so all generated numbers will have exactly one digit after the decimal point.

Wet Shark knows Rat Kwesh will want a lot of cheese. So he will give the Rat an opportunity to earn a lot of cheese. He will hand the three numbers x, y and z to Rat Kwesh, and Rat Kwesh will pick one of the these twelve options:

  1. a1 = xyz; 
  2. a2 = xzy; 
  3. a3 = (xy)z; 
  4. a4 = (xz)y; 
  5. a5 = yxz; 
  6. a6 = yzx; 
  7. a7 = (yx)z; 
  8. a8 = (yz)x; 
  9. a9 = zxy; 
  10. a10 = zyx; 
  11. a11 = (zx)y; 
  12. a12 = (zy)x. 



Let m be the maximum of all the ai, and c be the smallest index (from 1 to 12) such that ac = m. Rat's goal is to find that c, and he asks you to help him. Rat Kwesh wants to see how much cheese he gets, so he you will have to print the expression corresponding to that ac.

Input

The only line of the input contains three space-separated real numbers x, y and z (0.1 ≤ x, y, z ≤ 200.0). Each of x, y and z is given with exactly one digit after the decimal point.

Output

Find the maximum value of expression among xyz, xzy, (xy)z, (xz)y, yxz, yzx, (yx)z, (yz)x, zxy, zyx, (zx)y, (zy)x and print the corresponding expression. If there are many maximums, print the one that comes first in the list. 

xyz should be outputted as x^y^z (without brackets), and (xy)z should be outputted as (x^y)^z (quotes for clarity). 

Examples

Input

1.1 3.4 2.5


Output

z^y^x


Input

2.0 2.0 2.0


Output

x^y^z


Input

1.9 1.8 1.7


Output

(x^y)^z