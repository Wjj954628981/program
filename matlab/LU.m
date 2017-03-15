function [L,U]=LU(A)%A=LU
[n,n]=size(A);
L=eye(n);
for i=1:n-1
    for j=i+1:n
        L(j,i)=A(j,i)/A(i,i);
        A(j,:)=A(j,:)-(A(j,i)/A(i,i))*A(i,:);
    end
end
U=A%A becomes U matrix after Gauss elimination
L