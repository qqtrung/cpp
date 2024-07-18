/*
    Ma trận đầu vào:
    int a[][10] = {
        {-1, -1, -1, 0, -1, -1},
        {0, 0, 0, 0, -1, -1}, 
        {-1, -1, 0, 0, -1, 0}, 
        {0, 0, 0, -1, 0, 0}, 
        {-1, 0, -1, -1, -1, 0}, 
        {0, 0, 0, 0, 0, 0, 0}, 
    }

    Ma trận đầu ra: 
    int a[][10] = {
        {-1, -1, -1, 0, -1, -1},
        {1, 2, 3, 0, -1, -1}, 
        {-1, -1, 4, 0, -1, 0}, 
        {0, 6, 5, -1, 0, 14}, 
        {-1, 7, -1, -1, -1, 13}, 
        {0, 8, 9, 10, 11, 12}, 
    }
*/

#include <iostream>
using namespace std; 

struct Point {
    int r;
    int c; 
}; 

void findPath(int a[6][6], int n, Point start, Point end, bool &found, int cnt)
{
    a[start.r][start.c] = cnt;

    if(start.r == end.r && start.c == end.c) {
        found = true; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j] << " "; 
            }
            cout << "\n"; 
        }
        return; 
    }

    int row[] = {1, -1, 0, 0}; 
    int col[] = {0, 0, -1, 1}; 

    for(int i = 0; i < 4; i++) {
        Point next{start.r + row[i], start.c + col[i]};

        if(next.r < 0 || next.r >= n || next.c < 0 || next.c >= n || a[next.r][next.c] == -1) 
            continue; 

        if(a[next.r][next.c] == 0) {
            findPath(a, n, next, end, found, cnt+1); 
        }   
    }

    a[start.r][start.c] = 0; 

    return; 
} 

int main()
{
    int a[6][6] = {
        {-1, -1, -1, 0, -1, -1},
        {0, 0, 0, 0, -1, -1}, 
        {-1, -1, 0, 0, -1, 0}, 
        {0, 0, 0, -1, 0, 0}, 
        {-1, 0, -1, -1, -1, 0}, 
        {0, 0, 0, 0, 0, 0},
    }; 

    Point start{1, 0}; 
    Point end{2, 5}; 
    bool found = false; 

    findPath(a, 6, start, end, found, 1); 

    if(!found) {
        cout << "Find not Found: " << "404" << "\n"; 
    }

    return 0; 
}
