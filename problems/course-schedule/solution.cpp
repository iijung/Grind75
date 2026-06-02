// https://leetcode.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indgree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (const auto& edge:  prerequisites) {
            const int& v_curr = edge[0]; // current course
            const int& u_prev = edge[1]; // prerequisite course
            graph[u_prev].push_back(v_curr);
            indgree[v_curr]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indgree[i] == 0) q.push(i);
        }
        for (int i = 0; i < numCourses; i++) {
            if (q.empty()) return false;

            const int u_prev = q.front();
            q.pop();

            for (int i = 0; i < graph[u_prev].size(); i++) {
                indgree[graph[u_prev][i]]--;
                if (indgree[graph[u_prev][i]] == 0)
                    q.push(graph[u_prev][i]);
            }
        }
        return true;
    }
};
