#include<iostream>
#include<unordered_set>
#include<math.h>
using namespace std;
bool isPrimeNumber(int n) {
   if (n <= 1) return false;
   if (n <= 3) return true;
   if (n%2 == 0 || n%3 == 0) return false;
   for (int i=5; i*i<=n; i=i+6)
      if (n%i == 0 || n%(i+2) == 0)
         return false;
   return true;
}
int power(int x, unsigned int y, int p) {
   int res = 1;
   x = x % p;
   while (y > 0){
      if (y & 1)
      res = (res*x) % p;
      y = y >> 1;
      x = (x*x) % p;
   }
   return res;
}
void GeneratePrimes(unordered_set<int> &s, int n) {
   while (n%2 == 0){
      s.insert(2);
      n = n/2;
   }
   for (int i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         s.insert(i);
         n = n/i;
      }
   }
   if (n > 2)
   s.insert(n);
}
int findPrimitiveRoot(int n) {
   unordered_set<int> s;
   if (isPrimeNumber(n)==false)
   return -1;
   int ETF = n-1;
   GeneratePrimes(s, ETF);
   for (int r=2; r<=ETF; r++){
      bool flag = false;
      for (auto it = s.begin(); it != s.end(); it++){
         if (power(r, ETF/(*it), n) == 1){
            flag = true;
            break;
         }
      }
      if (flag == false)
      return r;
   }
   return -1;
}
int main()
{
    cout<<"Enter the large prime number (p): ";
    int p;cin>>p;
    cout<<"\nChecking if the value entered is prime . . .\n";
    if(isPrimeNumber(p))
    {
        cout<<"\nInput p="<<p<<" is a prime number.";
    }
    else
    {
        cout<<"\nInput p="<<p<<" is not a prime number.\nRe-enter p : ";cin>>p;
    }
    int e1=findPrimitiveRoot(p);
    cout<<"\nSmallest primitive root for given p-value are : "<<e1;
    cout<<"\nEnter private key value (D): ";
    int D;cin>>D;
    int e2=((int)pow(e1,D))%p;
    cout<<"\nCorresponding e1(private key)="<<e1<<" & e2(public key)="<<e2;
    cout<<"\n.\nEncryption. . .\n.";
    cout<<"\nEnter random integer value 'r' : ";int r;cin>>r;
    int c1=((int)pow(e1,r))%p;
    int m;cout<<"\nEnter plain text : ";cin>>m;
    int c2=(m*(int)pow(e2,r))%p;
    cout<<"\nCorresponding (C1,C2) value = ("<<c1<<","<<c2<<")";
    cout<<"\n.\nDecryption. . .\n.";
    cout<<"\nCalculating plain text back from (C1,C2) pair sent. . .\n";
    //int m1=(c2*modInverse((pow(c1,D)),p))%p;
    int m1=(c2*((int)pow(c1,p-D)))%p;
    cout<<"Plain Text after encryption = "<<m1;
    cout<<"\nPlain Text which was encrypted(Decrypted) = "<<m;
}