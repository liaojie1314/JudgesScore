#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;
	int m_Score;
};
void createPerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string nameSeed = "ABCDE";
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		//将创建的Person对象放入vector容器
		v.push_back(p);
	}
}
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 41 + 60;//60~100
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		//去除最高、最低分
		d.pop_back();
		d.pop_front();
		//平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//将平均分赋值给选手
		it->m_Score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "选手 " << it->m_Name << " 最终得分: " << it->m_Score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建5名选手
	vector<Person>v;
	createPerson(v);
	//给5名选手打分
	setScore(v);
	//显示得分
	showScore(v);
	system("pause");
	return 0;
}