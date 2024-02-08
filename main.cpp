#include <iostream>
#include <vector>
#include <queue>

//BFS FOR 2D ARRAY

using namespace std;

//Dequeue elements one by one and print them
//Use a copy

void printQueue(queue<pair<int, int>>& q) {
    // Create a copy of the queue
    queue<pair<int, int>> temp = q;

    // Print each element of the queue
    while (!temp.empty()) {
        pair<int, int> current = temp.front();
        cout << " Currently in Queue: (" << current.first << "," << current.second << ") " << '\n';
        temp.pop();
    }
    cout << endl;
}

//Validates if an element is in bounds
bool isValid(int row, int col, const vector<vector<int>>& grid) {
    int numRows = grid.size();
    if (numRows == 0) return false;
    int numCols = grid[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}

void updateConnectedElement(vector<vector<int>>& inputMatrix, int xPosition, int yPosition) {
    // Defines possible movements
    int xDirection[] = {1, -1, 0, 0};
    int yDirection[] = {0, 0, 1, -1};

    // Queue is important to store the next element
    queue<pair<int, int>> neighbourQueue;

    vector<vector<bool>> visited(inputMatrix.size(), vector<bool>(inputMatrix[0].size(), false));
    visited[xPosition][yPosition] = true;


    neighbourQueue.push({xPosition, yPosition});

    int order = 1;


    while (!neighbourQueue.empty()) {
        // Dequeue a cell from the queue


        printQueue(neighbourQueue);

        pair<int, int> currentCell = neighbourQueue.front();
        int currentRow = currentCell.first;
        int currentCol = currentCell.second;
        neighbourQueue.pop();

        //cout << "(" << currentRow << "," << currentCol << ") ";

        inputMatrix[currentRow][currentCol] = order;
        order = order + 1;


        // 4 possible movements: up, down, left, right
        for (int i = 0; i < 4; ++i) {
            int newRow = currentRow + xDirection[i];
            int newCol = currentCol + yDirection[i];

            if (isValid(newRow, newCol, inputMatrix) && !visited[newRow][newCol]) {                // Enqueue neighbour
                neighbourQueue.push({newRow, newCol});


                visited[newRow][newCol] = true;
            }
        }
    }
    cout << '\n' ;
}

int main() {
    vector<vector<int>> matrix = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
    };

    updateConnectedElement(matrix, 1, 1);

    // Print the matrix
    for (const auto &row: matrix) {
        for (const auto &element: row) {
            cout << element << " ";
        }
        cout << '\n';
    }

    return 0;
}
