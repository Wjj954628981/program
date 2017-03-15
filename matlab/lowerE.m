%%Ly=b
function[y]=lowerE(L,b)
n=size(L);
for j=1:n-1
    b(j)=b(j)/L(j,j);
    b(j+1:n)=b(j+1:n)-b(j)*L(j+1:n,j);
end
y=b
