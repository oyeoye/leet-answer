#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
class Solution1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()<1) return false;
        char s=word[0];
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==s&&DFS(board,i,j,1,word))
                    return true;
            }
        return false;
    }
private:
    bool DFS(vector<vector<char>> &board,int row,int clomn,int index,string word){
        if(index==word.size()) return true;
        char s=word[index];

        if(row>0&&board[row-1][clomn]==s&&DFS(board,row-1,clomn,index+1,word))
                return true;

        if(row<board.size()-1&&board[row+1][clomn]==s&&DFS(board,row+1,clomn,index+1,word))
                return true;

        if(clomn>0&&board[row][clomn-1]==s&&DFS(board,row,clomn-1,index+1,word))
                return true;

        if(clomn<board[0].size()-1&&board[row][clomn+1]==s&&DFS(board,row,clomn+1,index+1,word))
                return true;

        return false;
    }
};
*/

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        int last[255];
        int start=0,end=0;
        const int n=s.size();
        int maxlen=0;
        fill(last,last+255,-1);
        int temp;
        while(start<n&&end<n){
            if(last[s[end]]==-1)
                last[s[end]]=end;
            else if(last[s[end]]>=start){
                temp=last[s[end]];
                maxlen=max(maxlen,max(end-start,end-last[s[end]]));
                start=last[s[end]]+1;
                last[s[end]]=end;
            }
            else
                last[s[end]]=end;
            end++;
        }
        if(start==0) return n;
        maxlen=max(maxlen,end-start);
        return maxlen;
    }
};

//triangle
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int n=triangle.size();
        if(n<1) return 0;
        vector<int> sump(n,0);
        for(int i=0;i<n;i++)
            for(int j=i;j>=0;j--){
                if(j==0){
                    sump[j]+=triangle[i][0];
                }
                else if(j==i)
                    sump[j]+=(triangle[i][j]+sump[j-1]);
                else{
                    sump[j]=(triangle[i][j]+min(sump[j],sump[j-1]));
                }
            }
        int minpath=1000000;
        for(int i=0;i<n;i++)
            minpath=min(minpath,sump[i]);
        return minpath;
    }
};

//Palindrome Partitioning II
class Solution3 {
public:
    int minCut(string s) {

    }
};

//max rectangle
class Solution4 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()<1) return 0;
        const int n=matrix[0].size();
        vector<int> H(n,0);
        vector<int> L(n,0);
        vector<int> R(n,n);
        int maxarea=0;

        for(int i=0;i<matrix.size();i++){ //按照每一行递归的往下的思路来 用柱状图的思路来理解 左右遍历
            int left=0,right=n;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    H[j]++;
                    L[j]=max(L[j],left);
                    //更新左边最大蔓延距离 只有在原来的距离内出现了断点才更新
                }
                else{
                    H[j]=0;
                    left=j+1;
                    L[j]=0;R[j]=n; //对等于0的项进行初始化
                }
            }
            for(int j=n-1;j>=0;j--){ //从右往左计算蔓延长度 更新最大面积
                if(matrix[i][j]=='1'){
                    R[j]=min(R[j],right);
                    //R[j]中记录的是该柱体右边的第一个为0的位置 所以下面运算时不需要再加减1
                    maxarea=max(maxarea,H[j]*(R[j]-L[j]));
                }
                else{
                    right=j;
                }

            }
        }

        return maxarea;
    }
};
int main()
{
    cout << "Hello World!" << endl;
    /*
    Solution1 sol1;
    string s{"abcb"};
    cout<<sol1.lengthOfLongestSubstring(s)<<endl;
    */
    /*
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution2 sol2;
    cout<<sol2.minimumTotal(triangle)<<endl;
    */
    vector<vector<char>> matrix{{'1','1','1','0'},{'1','1','0','1'},{'1','1','1','1'}};
    Solution4 sol4;
    cout<<sol4.maximalRectangle(matrix)<<endl;
    cout<<"Output over"<<endl;
    getchar();
    return 0;
}

