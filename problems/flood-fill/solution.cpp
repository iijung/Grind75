// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        const int original_color = image[sr][sc];

        const int max_sr = image.size() - 1;
        const int max_sc = image[sr].size() - 1;
        image[sr][sc] = color;
        if (sr > 0 && original_color == image[sr - 1][sc])
            floodFill(image, sr - 1, sc, color);
        if (sr < max_sr && original_color == image[sr + 1][sc])
            floodFill(image, sr + 1, sc, color);
        if (sc > 0 && original_color == image[sr][sc - 1])
            floodFill(image, sr, sc - 1, color);
        if (sc < max_sc && original_color == image[sr][sc + 1])
            floodFill(image, sr, sc + 1, color);
        return image;
    }
};
