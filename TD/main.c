int a = 8;
int b;
int c = 0;

int fibo(int);


int main()
{
  return fibo(8);
}

int fibo(int n){
  switch (n)
  {
    case 1: return 1;
    case 2: return 1;
    default: return fibo(n-1) + fibo(n-2);
  }
}
