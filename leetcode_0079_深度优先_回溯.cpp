class Solution
{
private:
  vector<vector<int>> vv{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size();
    int n = board[0].size();
    int cnt[128] = {0};
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cnt[board[i][j]]++;
      }
    }
    for (char c : word)
    {
      cnt[c]--;
      if (cnt[c] < 0)
      {
        return false;
      }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (DFS(board, word, visited, 0, i, j))
        {
          return true;
        }
      }
    }
    return false;
  }
  bool DFS(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int index, int x, int y)
  {
    if (word.length() == index)
    {
      return true;
    }
    if (x < 0 || x == board.size() || y < 0 || y == board[0].size() || visited[x][y] || word[index] != board[x][y])
    {
      return false;
    }
    for (int i = 0; i < 4; i++)
    {
      vector<int> v = vv[i];
      visited[x][y] = true;
      if (DFS(board, word, visited, index + 1, x + v[0], y + v[1]))
      {
        return true;
      }
      visited[x][y] = false;
    }
    return false;
  }
};