/*
    Miguel Veloso Garcia
    169.036
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1040
#define QUEUE_SIZE (MAX * MAX)

char grid[MAX][MAX];

typedef struct {
    int x, y;
} Point;

Point queue[QUEUE_SIZE];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    if (rear < QUEUE_SIZE) {
        queue[rear++] = (Point){x, y};
    }
}

Point dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void bfs(int startX, int startY) {
    enqueue(startX, startY);
    grid[startX][startY] = 'o';

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!isEmpty()) {
        Point current = dequeue();
        int x = current.x;
        int y = current.y;

        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newX >= 1 && newX < MAX && newY >= 1 && newY < MAX && grid[newX][newY] == '.') {
                grid[newX][newY] = 'o';
                enqueue(newX, newY);
            }
        }
    }
}

int main() {
    int n, m, c = 0;
    scanf("%d %d", &n, &m);
    memset(grid, '0', sizeof grid);

    for (int i = 1; i <= n; i++) {
        scanf("%s", &grid[i][1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.') {
                bfs(i, j);
                c++;
            }
        }
    }

    printf("%d\n", c);
    return 0;
}