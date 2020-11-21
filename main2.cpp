#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

int main (int argc,char* argv[]) {

    int buf_data;
    vector <int> _file;
    vector<int> flag;
    int _count = 0;
    int index = 0;
    ifstream fin(argv[1]);
    ofstream fout("output.txt");
    double Start,End;
    Start = clock();
    while(1){
        fin >> buf_data;
        _file.push_back(buf_data);
        ++_count;
        if(_count == 50000000){
            sort(_file.begin(), _file.end());
            ofstream buf;
            ostringstream tostr;
            tostr << index;
            string fina = tostr.str();
            fina.append(".txt");
            buf.open(fina.c_str());
            for(int i = 0; i < _count; ++i){
                buf << _file.at(i) << "\n";
            }
            ++index;
            _count = 0;
            vector<int>().swap(_file);
        }
        if(fin.eof()){
                sort(_file.begin(), _file.end());
                ofstream buf;
                ostringstream tostr;
                tostr << index;
                string fina = tostr.str();
                fina.append(".txt");
                buf.open(fina.c_str());
                for(int i = 0; i < _count; ++i){
                    buf << _file.at(i) << "\n";
                }
                ++index;
                vector<int>().swap(_file);
                break;
        }
    }
    vector <int> _data[index];
    ifstream buf[index];
    int ttt = 0;
    for(int i = 0; i < index; ++i){
        ostringstream tostr;
        tostr << i;
        string fina = tostr.str();
        fina.append(".txt");
        buf[i].open(fina.c_str());
    }
    int k =0;
    while(k < index){
        buf[k] >> ttt;
        _data[k].push_back(ttt);
        ++k;
    }
    int time = 0;
    while(1){
        int _min = 2147483647;
        int flag1 = 0;
        int flag2 = 0;
        int bd = 0;
        for(int i = 0;i< index; ++i){
            if(buf[i].eof()){
                ++time;
                if(time == 1){
                   flag.push_back(i);
                   buf[i].close();
                }
                else{
                    for(int j = 0; j < flag.size();++j){
                        if(i == flag.at(j) ){
                            break;
                        }
                        else if(j == flag.size() - 1){
                            flag.push_back(i);
                        }
                    }
                }
            }
        }
        if(flag.size() == index){
            break;
        }
        for(int i = 0; i < index;++i){
            for(int j = 0; j < flag.size();++j){
                    if(i == flag[j]){
                        flag2 = 1;
                    }
            }
            if(_data[i].at(0) <= _min && flag2 == 0){
                _min = _data[i].at(0);
                flag1 = i;
            }
            flag2 = 0;
        }
        fout << _min << "\n";
        _data[flag1].pop_back();
        buf[flag1] >> bd;
        _data[flag1].push_back(bd);
    }
    End = clock();
    cout << "Execution time= " << (End - Start)/CLOCKS_PER_SEC << "s" << endl;
    fin.close();
    fout.close();
    return 0;
}
