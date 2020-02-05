int x;

int func(a)
{
	return a;
}

int main()
{
	int n=4;
	int a[5];
	a[1] = func(n+2);	
	print(a[1]);
}
