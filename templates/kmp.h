#include <cstring>

bool kmp_basic(const char *src, const char *key) {
    if(std::strlen(src) < std::strlen(key)) return false;

    size_t cur = 0, len = 0;
    while(cur < strlen(src)) {
        if(len = strlen(key)) return true;
        if(src[cur] == key[len]) {  // expand length
            len++;
            cur++;
        } else {
            while(len > 0) {
                if(
                    src[cur] == key[len] 
                    && std::strncmp(src + cur - len, key, len)
                ) break; // post end equivalence
                else len--;
            }
            if(len == 0) {

            }
        }
    }
}