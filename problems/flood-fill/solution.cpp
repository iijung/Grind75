// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;

        const int original_color = image[sr][sc];
        image[sr][sc] = color;

        const vector<pair<const int, const int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < directions.size(); ++i) {
            const int new_sr = sr + directions[i].first;
            const int new_sc = sc + directions[i].second;
            if (new_sr < 0 || new_sr >= image.size())
                 continue;
            if (new_sc < 0 || new_sc >= image[new_sr].size())
                 continue;
            if (image[new_sr][new_sc] != original_color)
                 continue;
            floodFill(image, new_sr, new_sc, color);
        }
        return image;
    }
};
