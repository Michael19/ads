#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <string>
#include <vector>
#include <sstream>

namespace dynamic_pr {

using  namespace std;

//! TODO change
vector<string> split(const string& s, vector<char> p){


    vector<string> out;
    int j_prev = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if(i + 1 == s.size())
        {
            out.push_back(s.substr(j_prev, s.size()-j_prev));
        }
        for (int j = 0; j < p.size(); ++j) {
            if(p.at(j) == c ){
                out.push_back(s.substr(j_prev, i - j_prev));
                j_prev = i+1;
                break;
            }
        }
    }
    return out;
}

int NOD(int a, int b){
    return b ==0 ? a : NOD(b, a%b);
}



std::string parse(const std::string& s){

    vector<string> vec = split(s,{'+', '/'});
    if(vec.size() != 4)
        return "";



    int a = std::atoi(vec.at(0).c_str());
    int b = std::atoi(vec.at(1).c_str());
    int c = std::atoi(vec.at(2).c_str());
    int d = std::atoi(vec.at(3).c_str());

    int x = a*d + b*c;
    int y = b*d;
    int nod = NOD(x,y);

    x /= nod;
    y /= nod;

    std::stringstream ss;
    ss << x <<"/"<<y;

    return ss.str();
}

int xtree(int number)
{
    int n = number;
    int odx = 0;

    int tree[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            tree[i][j] =++odx;
            std::cout << tree[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = n-1; i > 0; --i) {
        for (int j = 0; j <= i; ++j) {
            int max_el = std::max(tree[i][j], tree[i][j+1]);
            tree[i-1][j] +=max_el;
        }
    }

    return tree[0][0];
}

int** map = nullptr;

void walk(int x, int y, int size){

    if(x < 0 || x >= size)return;
    if(y < 0 || y >= size)return;
    if(!(map[x][y]))return;
    map[x][y] = 0;

    walk(x-1,y,size);
    walk(x+1,y,size);
    walk(x,y-1,size);
    walk(x,y+1,size);

}

int calc_islands(int size){

   map = new int*[size];

    for (int i = 0; i < size; ++i) {
        map[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < 2 * size * size / 3; ++i) {
        int x = std::rand() % size;
        int y = std::rand() % size;

        map[x][y] = 1;
    }

    int count = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;

    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(map[i][j]){
                count++;
                walk(i,j,size);
            }
        }
    }

//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            std::cout << map[i][j] << " ";
//        }
//        std::cout << std::endl;

//    }

    return count;

}


}

#endif // DYNAMIC_H
