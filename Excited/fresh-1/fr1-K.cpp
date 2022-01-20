#include <iostream>
#include <cstdio>
#include <algorithm>

struct person {
    char name[10];
    unsigned acNum, penalty;
};

bool cmp(const person& lhs, const person& rhs) {
    if(lhs.acNum == rhs.acNum) {
        return (lhs.penalty < rhs.penalty);
    }
    else {
        return (lhs.acNum > rhs.acNum);
    }
}

int main() {
    int inputs, nop, named;
    person people[1000];
    std::cin >> inputs;
    while(inputs--) {
        std::cin >> nop >> named;
        for(int i = 0; i < nop; i++) {
            std::scanf("%s %d %d", 
                people[i].name,
                &people[i].acNum,
                &people[i].penalty);
        }
        std::sort(people, people + nop, cmp);
        for(int i = 0; i < named; i++) {
            std::printf("%s %d %d\n",
                people[i].name,
                people[i].acNum,
                people[i].penalty);
        }
        std::printf("\n");
    }
    return 0;
}