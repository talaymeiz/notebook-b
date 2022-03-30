#include <string>
#include <iostream>
#include<bits/stdc++.h> 
#include "Direction.hpp"
#include<tr1/unordered_map>

#ifndef MY_HHEDER
#define MY_HHEDER

using namespace std;

namespace ariel{

    class Notebook{
        private:
            // unordered_map<int, unordered_map<string, int> p> n;
            std::tr1::unordered_map<int, std::tr1::unordered_map<int, std::string>> n;

        public:
            // Notebook();
            void write(int page, int row, int col, Direction dir, std::string msg);
            string read (int page, int row, int col, Direction dir , int len);
            void erase (int page, int row, int col, Direction dir, int len);
            void show (int page);
    };
}

#endif