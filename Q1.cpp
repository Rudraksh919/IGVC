#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix() {
    return {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 2, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 3, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 2, 2, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
}

void findStart(vector<vector<int>>& grid, int &x, int &y) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 3) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

void moveRobot(vector<vector<int>>& grid, int x, int y) {
    int dx[] = {-1, 0, 0}; // Up, Left, Right
    int dy[] = {0, -1, 1};
    
    while (true) {
        grid[x][y] = 9;
        bool moved = false;
        
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
                x = nx;
                y = ny;
                moved = true;
                break;
            }
        }
        
        if (!moved) break;
    }
}

void printMatrix(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = generateMatrix();
    int startX, startY;
    findStart(matrix, startX, startY);
    moveRobot(matrix, startX, startY);
    printMatrix(matrix);
    return 0;
}