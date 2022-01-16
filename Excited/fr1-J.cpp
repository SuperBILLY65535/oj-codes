#include <iostream>
#include <algorithm>

struct show {
    unsigned begin, end;
};

bool cmp(const show& show1, const show& show2) {
    if(show1.end == show2.end) {
        return (show1.begin > show2.begin);
    }
    else return (show1.end < show2.end);
}

int main() {
    unsigned num_show, cur, count;
    while(std::cin >> num_show) {
        if(num_show == 0) break;
        cur = count = 0;
        show *shows = new show[num_show];
        for(int i = 0; i < num_show; i++) {
            std::cin >> shows[i].begin >> shows[i].end;
        }
        std::sort(shows, shows + num_show, cmp);
        for(int i = 0; i < num_show; i++) {
            if(shows[i].begin >= cur) {
                cur = shows[i].end;
                count++;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}