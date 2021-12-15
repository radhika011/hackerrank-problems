/*
People in Chefland have three different eye colors, namely brown, blue, and green. green is the rarest of the eye colors whereas brown is most common.

The eye color of the child of two people is most likely to be the most common eye color between them.

You are given two characters denoting the eye colors of two people in Chefland. The character R denotes bRown color, B denotes Blue color, and G denotes Green color.

Determine the most likely eye color of their child. (Print R, B or G denoting bRown, Blue or Green respectively).





*/




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char p1,p2;
    cin>>p1>>p2;
    unordered_map<char,int> umap;
    umap['B'] = 2;
    umap['R'] = 3;
    umap['G'] = 1;
    int ans = max(umap[p1],umap[p2]);
    char child;
    if(ans==1) child = 'G';
    else if(ans==2) child = 'B';
    else child = 'R';
    cout<<child<<endl;
    return 0;
}
