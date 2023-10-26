#include <bits/stdc++.h>
using namespace std;

int placeCol[10], cnt;


bool safe(int r, int c){
    for(int i=1; i<=8; ++i){
        if(placeCol[i] == r) return false; // same row
    }

    for(int cc=1; cc<=8; ++cc){
        if(placeCol[cc] == 0) continue; 
        if(abs(cc - c) == abs(placeCol[cc] - r)) return false; // same diagonal
    }
    

    return true;
}


void backtrack(int col){ // traverse through columns
    if(col > 8){
        for(int i=1; i<=8; ++i) printf("%d ", placeCol[i]);
        printf("\n");
        return ;
    }
    
    if(placeCol[col]){
        backtrack(col + 1);
        return ;
    }

    for(int row=1; row<=8; ++row){ // check every rows
        if(safe(row, col)){
            placeCol[col] = row; // choose
            backtrack(col + 1); // recursive
            placeCol[col] = 0; // unchoose
        }
    }
}


int main(){
    int n; scanf("%d", &n);

    while(n--){
        int r, c; scanf("%d %d", &r, &c);

        placeCol[c] = r; // fixed a queen
        backtrack(1);
        placeCol[c] = 0;
        printf("\n");
    }

    return 0;
}
