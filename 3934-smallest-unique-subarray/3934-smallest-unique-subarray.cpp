class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int N = n + 1; // Add a sentinel smaller than every input value.

        vector<int> a(N, 0);
        for (int i = 0; i < n; ++i) a[i] = nums[i];

        // Build suffix array for a, including the sentinel suffix.
        vector<int> sa(N), cls(N);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int x, int y) {
            return a[x] < a[y];
        });

        int classes = 1;
        for (int i = 1; i < N; ++i) {
            if (a[sa[i]] != a[sa[i - 1]]) ++classes;
            cls[sa[i]] = classes - 1;
        }

        vector<int> shifted(N), nextCls(N), count(N);

        for (int len = 1; len < N && classes < N; len <<= 1) {
            for (int i = 0; i < N; ++i)
                shifted[i] = (sa[i] - len + N) % N;

            fill(count.begin(), count.begin() + classes, 0);
            for (int x : shifted) ++count[cls[x]];
            for (int i = 1; i < classes; ++i) count[i] += count[i - 1];

            for (int i = N - 1; i >= 0; --i) {
                int x = shifted[i];
                sa[--count[cls[x]]] = x;
            }

            nextCls[sa[0]] = 0;
            int newClasses = 1;
            for (int i = 1; i < N; ++i) {
                int cur = sa[i], prev = sa[i - 1];
                if (cls[cur] != cls[prev] ||
                    cls[(cur + len) % N] != cls[(prev + len) % N])
                    ++newClasses;
                nextCls[cur] = newClasses - 1;
            }
            cls.swap(nextCls);
            classes = newClasses;
        }

        // Drop the sentinel suffix.
        sa.erase(sa.begin());

        // Kasai LCP: lcp[r] is the LCP of sa[r] and sa[r + 1].
        vector<int> rank(n), lcp(max(0, n - 1), 0);
        for (int r = 0; r < n; ++r) rank[sa[r]] = r;

        int common = 0;
        for (int i = 0; i < n; ++i) {
            int r = rank[i];
            if (r == n - 1) {
                common = 0;
                continue;
            }
            int j = sa[r + 1];
            while (i + common < n && j + common < n &&
                   nums[i + common] == nums[j + common])
                ++common;
            lcp[r] = common;
            if (common > 0) --common;
        }

        int answer = n;
        for (int r = 0; r < n; ++r) {
            int longestMatch = 0;
            if (r > 0) longestMatch = max(longestMatch, lcp[r - 1]);
            if (r < n - 1) longestMatch = max(longestMatch, lcp[r]);

            int start = sa[r];
            int needed = longestMatch + 1;
            if (start + needed <= n)
                answer = min(answer, needed);
        }
        return answer;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna