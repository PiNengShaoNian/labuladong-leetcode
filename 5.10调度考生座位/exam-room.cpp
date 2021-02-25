#include <set>

using namespace std;

class ExamRoom {
    int n;
    set<int> s;

   public:
    ExamRoom(int N) { n = N; }

    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        }
        int pos = 0, pre = -1, maxDist = 0;
        for (int cur : s) {
            int dist = (cur - pre) / 2;
            if (dist > maxDist) {
                pos = pre == -1 ? 0 : pre + dist;
                maxDist = dist;
            }
            pre = cur;
        }
        if (n - pre - 1 > maxDist) pos = n - 1;
        s.insert(pos);
        return pos;
    }

    void leave(int p) { s.erase(p); }
};

int main() { return 0; }