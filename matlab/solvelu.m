%A=input('Enter a matrix A=')
%b=input('Enter a vector b=')
function x=solvelu(A,b)
[L,U]=LU(A);
y=lowerE(L,b);
x=upperE(U,y);

