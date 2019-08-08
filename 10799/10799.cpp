#include<iostream>

using namespace std;

int main() {

    string tmp;
    int ret = 0, cur = 0;
    string::iterator it;
    getline(cin, tmp);

    for (it = tmp.begin(); it < tmp.end() - 1; it++) {
        if (*it == '(' && *(it + 1) == ')') {
            ret += cur;
            it++;
        } else if (*it == '(') {
            cur++;
        } else {
            cur--;
            ret++;
        }
    }

    if (it == tmp.end() - 1) {
        ret++;
    }

    printf("%d", ret);

    return 0;
}
