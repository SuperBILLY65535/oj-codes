#include <cstdio>
using namespace std;
bool f1(int x) {
    return !(x%2);
}
bool f2(int x) {
    return (4<x) && (x<=12);
}
void t() {
    printf("1");
}
void f() {
    printf("0");
}
void s() {
    printf(" ");
}
int main() {
    int x;
    scanf("%d", &x);
    if(f1(x)&&f2(x)) {t(); s();}
    else{f(); s();}
    if(f1(x) || f2(x)) {t(); s();}
    else{f(); s();}
    if((f1(x)&&f2(x) != f1(x)||f2(x))) {t(); s();}
    else {f(); s();}
    if(!(f1(x)&&f2(x))) {t();}
    else {s();}
    return 0;
}