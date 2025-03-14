#include <iostream>
using namespace std;

void print(int cnt) {
    if (cnt == 0) {
        return;
    }
    else {
        cout << "A" << endl;
        print(cnt - 1);
    }

}

int main() {
    print(5);
    return 0;
}