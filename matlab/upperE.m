%%Ux=y
function[x]=upperE(U,y)
n=size(U);
for j=n:-1:2
    y(j)=y(j)/U(j,j);
    y(1:j-1)=y(1:j-1)-y(j)*U(1:j-1,j);
end
x=y