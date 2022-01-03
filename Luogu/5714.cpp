#include <cstdio> 
#include <iostream>
#include <cmath>
using namespace std;
int main() {
   double m,h;
   cin>>m>>h;
   double bmi = (m/h/h);
   if(bmi < 18.5) {
       printf("Underweight");
   }
   else {
       if(bmi < 24) {
           printf("Normal");
       }
       else {
           cout << bmi << endl << "Overweight";
       }
   }
   return 0;
}