//Phoenix_RK


/*


https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also. Examples :

Input  : x = 10, y = 13, l = 2, r = 3
Output : x = 14

x = 1010
y = 1101

length = r-l+1 = 3-2+1 = 2
 
0001<<length => 0100 -1 = 3 (0011)

mask = (0011)<<(1) = 0110 &
		     1101
--------------------------
                     0110
                 x=  1010
--------------------------
		 x=  1110

Binary representation of 10 is 1010 and 
that of y is 1101. There is one set bit
in y at 3’rd position (in given range). 
After we copy this bit to x, x becomes 1110
which is binary representation of 14.

Input  : x = 8, y = 7, l = 1, r = 2
Output : x = 11



*/



int main()
{
int T;
cin>>T;

while(T--)
{

int x,y,l,r;
cin>>x>>y>>l>>r;

int length = (1<<(r-l+1))-1; // this gives the no of bits to be considered ....that many no of 1 s are generated

//to place it in the correct position shifting is done as per the left position given => (length)<<(l-1)

//now performing & will give the set bits in y ..now or operation with x can set bits that are set in y

int mask = ((length)<<(l-1))&y;
cout<<x|mask<<endl; 


}


return 0;
}


