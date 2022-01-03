#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const double p=3.141593;
int main() {
    int t;
    cin >> t;
    if(t==1) {
        cout << "I love Luogu!";
    } else if(t==2) {
        printf("6 4");
    } else if(t==3) {
        printf("3\n12\n2");
    } else if (t==4) {
        cout << "166.667";
    } else if (t==5) {
        cout << "15";
    } else if (t==6) {
        cout << sqrt(pow(6,2)+pow(9,2));
    } else if (t==7) {
        printf("110\n90\n0");
    } else if (t==8) {
        cout<<5.0*2.0*p<<endl<<25.0*p<<endl<<4.0*pow(5,3)*p/3;
    } else if (t==9) {
        cout<<"22";
    } else if (t==10) {
        cout<<"9";
    } else if (t==11) {
        cout<<1.0*100/3;
    } else if (t==12) {
        printf("%d\n%c", (int)('m'-'a'+1), (const char*)(17+'A'));
    } else if (t==13) {
        cout<<(int)(exp(log((4.0/3)*(4*4*4+10*10*10)*p)/3.0));
    } else if(t == 14){
        cout<<50;
    }
    return 0;
}