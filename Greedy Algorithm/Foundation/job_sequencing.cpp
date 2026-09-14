// you are given n jobs.
// Each job has:
// id
// deadline → job must be completed on or before this time
// profit → earned if the job is completed

// Condition: Each job takes exactly 1 unit of time.

// Goal:
// > Maximize total profit
// > Find the maximum number of jobs that can be completed.

// Example:
// | Job | Deadline | Profit |
// | --- | -------: | -----: |
// | A   |        2 |    100 |
// | B   |        1 |     50 |
// | C   |        2 |     40 |

// Intuition:
// Har job ko 1 hour lagta hai.

// Available slots:
// Slot 1    Slot 2
//   _         _

// Step 1: Sabse zyada profit wali job pehle
// A ka profit = 100
// A ki deadline = 2
// A ko slot 2 mein daal do:
// Slot 1    Slot 2
//   _         A

// Lekin slot 2 kyun?
// A ko slot 1 ya 2, dono mein kar sakte ho.
// Hum slot 2 choose karenge, kyunki:
// Slot 1 ko kisi aisi job ke liye bachana hai jiska deadline chhota hai.

// Step 2: B
// B ki deadline = 1
// Isliye B ko sirf slot 1 mein kar sakte hain:
// Slot 1    Slot 2
//   B         A
// Profit: 50 + 100 = 150

// Step 3: C
// C ki deadline = 2
// Woh slot 1 ya 2 mein ja sakti hai.
// Lekin dono occupied hain:
// Slot 1    Slot 2
//   B         A

// So C ko skip.

// Actual intuition :-
// Har baar sabse profitable job uthao.
// Phir us job ko deadline ke sabse last available slot mein rakho.
// Why? - Because early slots ko unnecessarily occupy nahi karna hai.

// Example:
// Deadline = 3
// Slots:
// 1   2   3
// _   _   _

// Agar job ko slot 1 mein daal diya:
// A   _   _

// toh tumne ek valuable early slot waste kar diya.
// Instead:
// _   _   A

// Ab slot 1 aur 2 dono future jobs ke liye available hain.

// Ek line mein yaad rakho
// Profit bada hai toh pehle lo, aur deadline ke andar jitna late ho sake utna late schedule karo.
// Bas “high profit + latest possible slot” hi Job Sequencing ka poora greedy logic hai.
// jobs[i][0] = id
// jobs[i][1] = deadline
// jobs[i][2] = profit

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& jobs) {

        // Sort jobs by profit: highest profit first
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        });

        // Find maximum deadline
        int maxDeadline = 0;
        for(int i = 0; i < jobs.size(); i++) {
            maxDeadline = max(maxDeadline, jobs[i][1]);
        }

        // slot[j] = job placed at time slot j
        vector<int> slot(maxDeadline + 1, -1);

        int count = 0;
        int totalProfit = 0;

        // Take jobs one by one
        for(int i = 0; i < jobs.size(); i++) {

            int deadline = jobs[i][1];
            int profit = jobs[i][2];

            // Find latest free slot before deadline
            for(int j = deadline; j >= 1; j--) {

                if(slot[j] == -1) {

                    // Put job here
                    slot[j] = i;

                    count++;
                    totalProfit += profit;

                    break;
                }
            }
        }

        return {count, totalProfit};
    }
};