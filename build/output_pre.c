int reza=2;
int fib(in)

{

if(in==1 || in ==2)

{

return 1;

}else{

return fib(in-1)+fib(in-2);

}

}




int main()
{
// int b=7;
// b=b+1;
// int a = b;
//return b/(4-3);
//int a=18/x(2,-2);
//int a=scan();
//int a=scan();
//print(a);
/*for(int i=10;i>1;i=i-2)
{
print(i);
}*/
int n=scan();
for(int i=1;i<=n;i++)
{
print(fib(i));
}




//x();


/*if(b<5)
return 1;
else
return -1;
*/
}

