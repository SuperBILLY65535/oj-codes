#include <cstdio>
#include <cstring>
using namespace std;

int main() 
{
    char c[256];
    scanf("%s", c);
    for (int i=strlen(c)-1; i>=0; i--) {
        printf("%c", c[i]);
    }
    return 0;
}