class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int clx = max(x1, min(xc, x2));
        int cly = max(y1, min(yc, y2));
        
        int height = clx - xc;
        int base = cly - yc;

        return height*height + base*base <= radius*radius;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna