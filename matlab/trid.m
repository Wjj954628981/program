function x=trid(A,d)
%a对角线下方的元素，个数比A少一个
%b对角线元素
%c对角线上方的元素，个数比A少一个
%d为方程常数项
%A=[4 1 0 0 0
%    1 4 1 0 0
%    0 1 4 1 0
%    0 0 1 4 1
%    0 0 0 1 4]
%d=[1 0.5 -1 3 2]';
n=size(A,1);
a(1)=0;
b(1)=A(1,1);
c(1)=A(1,2);
for i=2:n-1
    a(i)=A(i+1,i);
    b(i)=A(i,i);
    c(i)=A(i,i+1);
end
a(n)=A(n,n-1);
b(n)=A(n,n);
c(n)=0;
r(1)=1/b(1);

for i=2:n
    r(i)=1/(b(i)-a(i)*r(i-1)*c(i-1));
end
y(1)=r(1)*d(1);
for i=2:n
    y(i)=r(i)*(d(i)-a(i)*y(i-1));
end
x(n)=y(n);
for i=n-1:-1:1
    x(i)=y(i)-r(i)*c(i)*x(i+1);
end

