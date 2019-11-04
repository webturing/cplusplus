//
// Created by jal on 2018/6/20 0020.
//
#include <bits/stdc++.h>
using namespace std;
int m,n;
struct Image{
    vector<vector<int>>matrix;
    int row;
    int column;

    Image A(){
        Image ret;
        ret.row = column;
        ret.column = row;
        ret.matrix.resize(ret.row);
        for(auto & i : ret.matrix){
            i.resize(ret.column);
        }
        for(int i = 0; i < ret.row; i++){
            for(int j = 0; j < ret.column; j++){
                ret.matrix[i][j] = matrix[row-1-j][i];
            }
        }
        return ret;
    }
    Image B(){
        Image ret;
        ret.row = column;
        ret.column = row;
        ret.matrix.resize(ret.row);
        for(auto & i : ret.matrix){
            i.resize(ret.column);
        }
        for(int i = 0; i < ret.row; i++){
            for(int j = 0; j < ret.column; j++){
                ret.matrix[i][j] = matrix[j][column-i-1];
            }
        }
        return ret;
    }

    Image C(){
        Image ret;
        ret.row = row;
        ret.column = column;
        ret.matrix.resize(ret.row);
        for(auto & i : ret.matrix){
            i.resize(ret.column);
        }
        for(int i = 0; i < ret.row; i++){
            for(int j = 0; j < ret.column; j++){
                ret.matrix[i][j] = matrix[i][column-j-1];
            }
        }
        return ret;
    }

    Image D(){
        Image ret;
        ret.row = row;
        ret.column = column;
        ret.matrix.resize(ret.row);
        for(auto & i : ret.matrix){
            i.resize(ret.column);
        }
        for(int i = 0; i < ret.row; i++){
            for(int j = 0; j < ret.column; j++){
                ret.matrix[i][j] = matrix[row-i-1][j];
            }
        }
        return ret;
    }

    void print(){
        //cout << row << " " << column <<endl;
        for(auto i: matrix){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void clone(Image that) {
        row = that.row;
        column = that.column;
        for(auto &i : matrix){
            i.resize(column);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                matrix[i][j] = that.matrix[i][j];
            }
        }
    }
};
int main(){
    Image a;
    cin>>a.row>>a.column;
    a.matrix.resize(a.row);
    for(auto& i:a.matrix){
        i.resize(a.column);
    }
    for(int i = 0; i < a.row; i++){
        for(int j = 0; j < a.column; j++){
            cin>>a.matrix[i][j];
        }
    }
    string str;
    cin>>str;
    Image result = a, temp = a;
    for(auto ch : str){
        switch (ch){
            case 'A':
                temp=result.A();
                result = temp;
                break;
            case 'B':
                temp=result.B();
                result = temp;
                break;
            case 'C':
                temp=result.C();
                result = temp;
                break;
            case 'D':
                temp=result.D();
                result = temp;
                break;

        }
    }
    result.print();
}
