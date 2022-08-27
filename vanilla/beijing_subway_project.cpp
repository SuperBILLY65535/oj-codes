#include <iostream>
#include <string>
#include <map>

struct station {
    std::string name;
    int number;
};

struct edge {
    int A, B;
    size_t len;
    edge *A_next, *B_next;
    edge(const int &a, const int &b, const size_t &c) {
        A = a;
        B = b;
        len = c;
    }
    edge() = default;
};

int main() {
    edge* start = nullptr, *curr = nullptr;
    int name1, name2;
    size_t len;
    size_t n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> name1 >> name2 >> len;
        curr = new edge(name1, name2, len);
        if(start == nullptr) {

        }
    }
}