#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
//ѡ����
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
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		//��������Person�������vector����
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
		//����
		sort(d.begin(), d.end());
		//ȥ����ߡ���ͷ�
		d.pop_back();
		d.pop_front();
		//ƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//��ƽ���ָ�ֵ��ѡ��
		it->m_Score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "ѡ�� " << it->m_Name << " ���յ÷�: " << it->m_Score << endl;
	}
}
int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//����5��ѡ��
	vector<Person>v;
	createPerson(v);
	//��5��ѡ�ִ��
	setScore(v);
	//��ʾ�÷�
	showScore(v);
	system("pause");
	return 0;
}