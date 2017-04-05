%function Q=TwoDpde()
clc
clear
x=0:1/160:1;y=0:1/160:1;t=0:0.001:0.004;
delta_x=x(2)-x(1);
delta_y=y(2)-y(1);
delta_t=t(2)-t(1);
Jx=1/delta_x;Jy=1/delta_y;
N=length(t);
miu_x=(delta_t)/(delta_x)^2;miu_y=(delta_t)/(delta_y)^2;
%initial condition
%delta_x=delta_y=1/160
U0=zeros(Jx+1,Jy+1);
U0(61:101,61:101)=ones(41,41);
r=1:Jx+1;
s=1:Jy+1;
%u0(i,j,k)=u(i,j,k+1/2)
%u0�����м�ʱ���ĺ���
u0(r,s,1)=0;
%boundary condition
for n=1:N
for s=1:Jy+1
U(1,s,n)=0;
U(Jx+1,s,n)=0;
end
for r=1:Jx+1
U(r,1,n)=0;
U(r,Jy+1,n)=0;
end
end
%u0=zeros(Jx+1,Jy+1,N);
%U=zeros(Jx+1,Jy+1,N);
for n=1:N   %�̶���tʱ���
     a=(1+miu_x)*ones(1,Jx-1);
     b=-0.5*miu_x*ones(1,Jx-2);
     A=diag(a)+diag(b,-1)+diag(b,1);    
   for s=2:Jy-1
    %s=s0
    %�ȹ̶�һ��s0����һ��Jx-1�׵����Խ�
    %create the coefficient matrix    
    %trid() solve the equalities
    for r=2:Jx
     U(r,s,1)=U0(r,s);
     d(r)=U(r,s,n)+0.5*miu_y*(U(r,s+1,n)-2*U(r,s,n)+U(r,s-1,n));
    end
     u0(2:Jx,s,n)=trid(A,d(2:Jx)');
   end
   %���������˵�n�㵽��n+1����м���ȫ������ֵ
     for r=2:Jx
   %����̶�ĳ��r0�����һ��Jy-1�׵����ԽǷ���
     for s=2:Jy
     a1=(1+miu_y)*ones(1,Jy-1);
     b1=-0.5*miu_y*ones(1,Jy-2);
     B=diag(a1)+diag(b1,-1)+diag(b1,1);
     e(s)=0.5*miu_x*(u0(r+1,s,n)+u0(r-1,s,n))+(1-miu_x)*u0(r,s,n);
     end
     U(r,2:Jy,n+1)=trid(B,e(2:Jy)');
     end
end
%%   
figure
mesh(x,y,U(:,:,3))
