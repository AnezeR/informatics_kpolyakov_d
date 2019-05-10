#include <iostream>

using namespace std;

/*
4
a b 12.03.2003
b c 03.04.2002
c d 15.03.2002
d e 15.03.2002
*/

int main() {

    int N, oldestCount = 1, oldestYear = 4000, oldestMonth = 100, oldestDay = 100;
    string oldest;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string s, buf, tmp;
        cin >> s >> buf;
        s += ' ' + buf;

        cin >> buf;

        int m, d, y;

        tmp = buf.substr(0, 1);
        if (tmp == "0"){
            d = stoi(buf.substr(1, 2));
        } else {
            d = stoi(buf.substr(0, 2));
        }

        tmp = buf.substr(3, 4);
        if (tmp == "0"){
            m = stoi(buf.substr(4, 5));
        } else {
            m = stoi(buf.substr(3, 5));
        }

        y = stoi(buf.substr(6, 10));

        if (y < oldestYear){
            oldest = s;
            oldestCount = 1;

            oldestYear = y;
            oldestMonth = m;
            oldestDay = d;

        } else if (y == oldestYear){
            if (m < oldestMonth){
                oldest = s;
                oldestCount = 1;

                oldestMonth = m;
                oldestDay = d;
            } else if (m == oldestMonth){
                if (d < oldestDay){
                    oldest = s;
                    oldestCount = 1;

                    oldestDay = d;
                } else if (d == oldestDay){
                    oldestCount++;
                }
            }
        }
    }

    if (oldestCount == 1)
        cout << oldest << ' ' << (oldestDay < 10 ? "0" : "") <<  oldestDay  << '.' << (oldestMonth < 10 ? "0" : "")
             << oldestMonth << '.' << oldestYear;
    else
        cout << oldestCount;

    return 0;
}