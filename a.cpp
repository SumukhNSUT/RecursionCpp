#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct InputData {
    int rows, cols, num_words;
    vector<vector<char>> board;
    vector<string> words;
};

InputData read_input() {
    InputData data;
    cin >> data.rows >> data.cols;
    data.board.assign(data.rows, vector<char>(data.cols));
    for (int i = 0; i < data.rows; ++i)
        for (int j = 0; j < data.cols; ++j)
            cin >> data.board[i][j];
    cin >> data.num_words;
    data.words.resize(data.num_words);
    for (int i = 0; i < data.num_words; ++i)
        cin >> data.words[i];
    return data;
}

bool dfs(const vector<vector<char>>& board, string& word, int x, int y, int idx, vector<vector<bool>>& visited) {
    if (idx == word.size()) return true;
    int m = board.size(), n = board[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y] != word[idx])
        return false;
    visited[x][y] = true;
    // Explore 8 directions
    for (int dx = -1; dx <= 1; ++dx)
        for (int dy = -1; dy <= 1; ++dy)
            if (dx != 0 || dy != 0)
                if (dfs(board, word, x + dx, y + dy, idx + 1, visited))
                    return visited[x][y] = false, true;
    visited[x][y] = false;
    return false;
}

void solve_problem(const InputData& data) {
    set<string> found;
    int m = data.rows, n = data.cols;
    for (const string& word : data.words) {
        bool exists = false;
        for (int i = 0; i < m && !exists; ++i)
            for (int j = 0; j < n && !exists; ++j)
                if (data.board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if (dfs(data.board, const_cast<string&>(word), i, j, 0, visited))
                        exists = true;
                }
        if (exists) found.insert(word);
    }
    if (found.empty()) {
        cout << "0\n";
    }
    else {
        cout << found.size() << "\n";
        for (const string& w : found)
            cout << w << "\n";
    }
}

int main() {
    InputData input_data = read_input();
    solve_problem(input_data);
    return 0;
}
