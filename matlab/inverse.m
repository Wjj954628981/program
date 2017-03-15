function [ v, c ] = inverse()

A=[10,-7,0;-3,2,6;5,-1,5];
[L,U]=PLU(A);

U=U';
n=length(L);
c=zeros(n,1);c(1)=1;
v=zeros(n,1);v(1)=1/U(1,1);



for i=2:n
    for j=1:i-1
        s=0;
        s=U(i,j)*v(j)+s;  
        if i==3
            fprintf(' s=%f \n', s);
        end
    end
    c(i)=-sign(s);
    v(i)=(c(i)-s)/U(i,i);
end

c=c
v=v


