function[L,U,P]=PLU(A)
A=[1 2 -3 4
    4 8 12 -8
    2 3 2 1
    -3 -1 1 -4];
[n,n]=size(A);
p=(1:n)';
for k=1:n-1 
    [r,m]=max(abs(A(k:n,k))); %返回行向量r和m,r向量记录A的每列的最大值,m向量记录每列最大值的行号.
    m=m+(k-1); 
    if (A(m,k)~=0)
        if(m~=k)
          A([k,m],:)=A([m,k],:);%进行行行交换 
          p([k,m])=p([m,k]); 
        end
        i=k+1:n;
        A(i,k)=A(i,k)/A(k,k);
        j=k+1:n;
        A(i,j)=A(i,j)-A(i,k)*A(k,j);
    end
end

L=tril(A,-1)+eye(n)
U=triu(A)
P=p



