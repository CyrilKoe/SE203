int a = 8;
int b = 0;
int c = 0;

int fibo(int);


int main()
{
  b++;
  c = fibo(a);
  return c;
}

int fibo(int n){
  if(n>=2)
    return fibo(n-1) + fibo(n-2);
  else
    return 1;
}
