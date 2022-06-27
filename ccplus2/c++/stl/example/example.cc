#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Person{
public:
        Person(std::string name, int score){
                this->m_name = name;
                this->m_score = score;
        }

public:
        std::string m_name;
        int m_score;
};

void createPerson(std::vector<Person>& v){
        std::string nameSeed = "ABCDE";
        for (size_t i = 0; i < 5; i++) {
                std::string name = "play";
                name += nameSeed[i];
                int score = 0;

                Person p(name, score);
                v.push_back(p);
        }
}

void setScore(std::vector<Person>&v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::deque<int> d;
                for(int i = 0; i < 10; i++){
                        int score = rand() % 41 + 60;
                        d.push_back(score);
                }

                //排序
                sort(d.begin(), d.end());

                //去掉最高和最低分
                d.pop_back();
                d.pop_front();

                //取平均分
                int sum = 0;
                for(auto dit = d.begin(); dit != d.end(); dit++){
                        sum += *dit; //累加每个评委的分数 
                }

                int avg = sum / d.size();
                it->m_score  = avg;
        }
}

void showScore(std::vector<Person> v){
        for (auto it = v.begin(); it != v.end(); it++) {
                std::cout << "姓名:" << (*it).m_name << ", 分数: " << (*it).m_score  << endl;
        }
}

int main(){
        //创建五名选手
        std::vector<Person> v;
        createPerson(v);

        //给五名选手打分
        setScore(v);
        //显示最后的得分
        showScore(v);
        return 0;
}