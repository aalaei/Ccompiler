#define alialaei 99
int fib(in)
{

    if(in==1 || in ==2)
    {
        return 1;
    }else{
        return fib(in-1)+fib(in-2);
    }
}