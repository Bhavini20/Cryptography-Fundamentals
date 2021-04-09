#include<iostream>
#include<math.h>
using namespace std;
float en[3][1], de[3][1], a[3][3], b[3][3], msg[3][1], m[3][3];
void getKeyMatrix() { 
   int i, j;
   cout<<"Enter 3x3 matrix for key (should have inverse):\n";
   for(i = 0; i < 3; i++)
   for(j = 0; j < 3; j++) {
      cin>>a[i][j];
      m[i][j] = a[i][j];
   }
}
void encrypt(){
    char mes[3];
    int i,j, k;
   cout<<"\nEnter a string of 3 letter(use A through Z): ";
   cin>>mes;
   for(i = 0; i < 3; i++)
   msg[i][0] = mes[i] - 65;
   
   for(i = 0; i < 3; i++)
   for(j = 0; j < 1; j++)
   for(k = 0; k < 3; k++)
   en[i][j] = en[i][j] + a[i][k] * msg[k][j];
   cout<<"\nEncrypted string is: ";
   for(i = 0; i < 3; i++)
   cout<<(char)(fmod(en[i][0], 26) + 65);  
}
int main() {
   getKeyMatrix();
   int l;
   cout<<"Enter the no of times input required";
   cin>>l;
   for(int i=0;i<l;i++){
   encrypt();
   }
}
