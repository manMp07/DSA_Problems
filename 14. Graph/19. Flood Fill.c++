#include<bits/stdc++.h>
using namespace std;

//Que.- An image is represented by a 2-D array of integers, each integer representing the
//      pixel value of the image. Given a coordinate (sr, sc) representing the starting pixel
//      (row and column) of the flood fill, and a pixel value newColor, "flood fill" the
//      image.
//      To perform a "flood fill", consider the starting pixel, plus any pixels connected
//      4-directionally to the starting pixel of the same colour as the starting pixel, plus
//      any pixels connected 4-directionally to those pixels (also with the same colour as
//      the starting pixel), and so on. Replace the colour of all of the aforementioned
//      pixels with the newColor.

/***Using BFS***/
//Time : O(N*M*4) ~ O(N*M)
//Space : O(N*M)

vector<vector<int>> floodFill(vector<vector<int>> &image, int srcX, int srcY, int newColor){
    if(image[srcX][srcY] == newColor)
        return image;

    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> pixels;
    pixels.push({srcX, srcY});

    int targetColor = image[srcX][srcY];
    image[srcX][srcY] = newColor;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!pixels.empty()){
        int x = pixels.front().first;
        int y = pixels.front().second;
        pixels.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(image[nx][ny] == targetColor){
                image[nx][ny] = newColor;
                pixels.push( {nx, ny} );
            }
        }
    }

    return image;
}