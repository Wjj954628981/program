function[L,U,P]=PLU(A)
[n,n]=size(A);
p=(1:n)';
for k=1:n-1 
    [r,m]=max(abs(A(k:n,k))); %����������r��m,r������¼A��ÿ�е����ֵ,m������¼ÿ�����ֵ���к�.
    m=m+(k-1); 
    if (A(m,k)~=0)
        if(m~=k)
          A([k,m],:)=A([m,k],:);%�������н��� 
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



