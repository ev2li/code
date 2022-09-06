#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool isUnique(std::string input){
    std::bitset<256> hashMap;

    for(int i = 0;i < input.length();i++){
        if(hashMap[(int)input[i]]){
            return false;
        }
        hashMap[(int)input[i]] = 1;
    }
    return true;
}

int main(){
    
    return 0;
}