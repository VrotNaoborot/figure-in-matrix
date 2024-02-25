#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

Point getStartPoint(const char(&a)[12][12]) {
    int ln = sizeof(a[0]) / sizeof(a[0][0]);
    Point start;
    for (int i = 0; i < ln; i++) {
        for (int j = 0; j < ln; j++) {
            if (a[i][j] == '*') {
                start.x = i;
                start.y = j;
                return start;
            }
        }
    }
    return start;
}

int main() {
    char matrix[12][12] = {
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*', ' ', ' '},
            {' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', '*', ' '},
            {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '},
            {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
            {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*'},
            {' ', ' ', '*', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', ' '},
            {' ', ' ', '*', '*', ' ', '*', ' ', ' ', ' ', '*', '*', ' '},
            {' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' '}
    };

    vector<Point> a;

    Point start = getStartPoint(matrix);
    a.push_back(start);


    int previous_x = -1;
    int previous_y = -1;

    while (true) {
        Point lastEl = a.back();
        int currentX = lastEl.x;
        int currentY = lastEl.y;

        Point coord;



        if (matrix[currentX][currentY+1] == '*' and not(currentX == previous_x and currentY+1 == previous_y)) {
            coord.x = currentX;
            coord.y = currentY+1;
        }
        else if (matrix[currentX+1][currentY+1] == '*' and not(currentX+1 == previous_x and currentY+1 == previous_y)) {
            coord.x = currentX+1;
            coord.y = currentY+1;
        }
        else if (matrix[currentX-1][currentY] == '*' and not(currentX-1 == previous_x and currentY == previous_y)) {
            coord.x = currentX-1;
            coord.y = currentY;
        }
        else if (matrix[currentX+1][currentY-1] == '*' and not(currentX+1 == previous_x and currentY-1 == previous_y)) {
            coord.x = currentX+1;
            coord.y = currentY-1;
        }
        else if (matrix[currentX][currentY-1] == '*' and not(currentX == previous_x and currentY-1 == previous_y)) {
            coord.x = currentX;
            coord.y = currentY-1;
        }
        else if (matrix[currentX-1][currentY-1] == '*' and not(currentX-1 == previous_x and currentY-1 == previous_y)) {
            coord.x = currentX-1;
            coord.y = currentY-1;
        }
        else if (matrix[currentX-1][currentY] == '*' and not(currentX-1 == previous_x and currentY == previous_y)) {
            coord.x = currentX-1;
            coord.y = currentY;
        }
        else if (matrix[currentX-1][currentY+1] == '*' and not(currentX-1 == previous_x and currentY+1 == previous_y)) {
            coord.x = currentX-1;
            coord.y = currentY+1;
        }

        a.push_back(coord);

        if (coord.x == start.x and coord.y == start.y) {
            break;
        }

        previous_x = currentX;
        previous_y = currentY;
    }

    for (int c = 0; c < a.size() - 1; c++) {
        printf(" Coord: X - %d, Y - %d\n", a[c].x, a[c].y);
    }


}