#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;


//def de_bruijn(k, n: int)->str:
//"""de Bruijn sequence for alphabet k
//and subsequences of length n.
//"""
//try :
//    # let's see if k can be cast to an integer;
//# if so, make our alphabet a list
//    _ = int(k)
//    alphabet = list(map(str, range(k)))
//    except(ValueError, TypeError) :
//    alphabet = k
//    k = len(k)
//
//    a = [0] * k * n
//    sequence = []
//
//    def db(t, p) :
//    if t > n:
//if n% p == 0 :
//    sequence.extend(a[1:p + 1])
//else :
//    a[t] = a[t - p]
//    db(t + 1, p)
//    for j in range(a[t - p] + 1, k) :
//        a[t] = j
//        db(t + 1, t)
//
//        db(1, 1)
//        return "".join(alphabet[i] for i in sequence)
//

class Solution {
public:
    string crackSafe(int n, int k) {
        vector<int> v(n * k, 0);
        vector<int> sequence;
        db(1, 1, n, k,v,sequence);
        return "";
    }

    void db(int t, int p, int n, int k, vector<int>& a, vector<int>& sequence) {


        if (t > n) {
            if (n % p == 0) {
                for (int i = 1; i < p + 1; i++)
                    sequence.push_back(a[i]);
            }
        }
        else {
            a[t] = a[t - p];
            db(t + 1, p, n, k, a, sequence);
            for (int j = a[t - p]+1; j < k; j++) {
                a[t] = j;
                db(t + 1, t, n, k, a, sequence);

            }

        }
        return;
    }

    
};
//
//        print(de_bruijn(2, 3))
//        print(de_bruijn("abcd", 2))
//
//




int main() {
    Solution mysolu;
    string res = mysolu.crackSafe(4, 2);
	return 0;
}