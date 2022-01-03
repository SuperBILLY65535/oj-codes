#include <cstdio>
using namespace std;
const int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool leap(int year) {
    if(year % 4 != 0) {
        return false;
    }
    else {
        if(year % 100 != 0) {
            return true;
        }
        else {
            if(year % 400 != 0) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}
int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    if((m == 2) && (leap(y))) {
        printf("29");
    }
    else {
        printf("%d", day[m]);
    }
    return 0;
}