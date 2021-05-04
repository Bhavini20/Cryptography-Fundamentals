#include<stdio.h>
#include<math.h>

long long int power(long long int a, long long int b,
									long long int P)
{
	if (b == 1)
		return a;

	else
		return (((long long int)pow(a, b)) % P);
}


int main()
{
	long long int q, G, x, a, y, b, ka, kb;
    printf("Enetr the value of q : ");
	scanf("%lld",&q);

    printf("Enetr the value of G (primitive root) : ");
	scanf("%lld",&G);

    printf("Enetr the value of private key of A : ");
	scanf("%lld",&a);
	x = power(G, a, q); 
	
	b = 3; 
    printf("Enetr the value of private key of B: ");
    scanf("%lld",&b);
	y = power(G, b, q); // gets the generated key

	
	ka = power(y, a, q); // Secret key for Alice
	kb = power(x, b, q); // Secret key for Bob
	printf("\n");
	printf("Secret key for the Alice is : %lld\n", ka);
	printf("Secret Key for the Bob is : %lld\n", kb);
    printf("\n");
    if(ka==kb)
      printf("Encryption was successful!");
    else
       printf("Encryption failed! ");
	
	return 0;
}
