#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <time.h>
using namespace std;
float variations = 0.9;
int n = 13;
struct unit {
	short int bit[13];
	float num;
	float value;
	double probability;
	double pro_pos;
};
vector<unit> races;
vector<unit> copys;
void bitodec(unit &a)
{
	int tmp = 1;
	float u = 0.0;
	for(int i=0; i<n; ++i)
	{
		u += a.bit[i]*tmp;
		tmp *= 2;
	}
	u = u/1000.0;
	a.num = u;
	a.value = 10*sin(5*u)+7*abs(u-5)+10;
}

void crosschange(unit a,unit b)
{
	unit c;
	default_random_engine generator;
	generator.seed(time(NULL));
	uniform_int_distribution<int> dis(0,10);
	auto dice= std::bind(dis,generator);
	for(int i=0; i<n; ++i)
	{
		int tmp = dice();
		if(tmp <= 3)
		{
			c.bit[i] = a.bit[i];
		}
		else{
			c.bit[i] = b.bit[i];
		}
	}
	bitodec(c);
	races.push_back(c);
}

void variation(unit &a)
{
	default_random_engine generator;
	uniform_int_distribution<int> pis(0,100);
	generator.seed(time(NULL));
	auto nice= bind(pis,generator);
	for(int i=0; i<n; ++i)
	{
		if(nice()/100.0<variations)
		{
			a.bit[i] = (a.bit[i]+1)%2;
		}
	}
	bitodec(a);
}

unit find(float tmp)
{
	int m = copys.size();
	for(int i=0; i<m; ++i)
	{
		if(copys[i].pro_pos >= tmp)
			return copys[i];
	}
}

void die()
{
	default_random_engine generator;
	uniform_real_distribution<float> mis(0,1);
	generator.seed(time(NULL));
	auto mice= bind(mis,generator);
	int sum = 0;
	int m = races.size();
	for(int i=0;i<m; ++i)
	{
		sum += races[i].value;
	}
	for(int i=0; i<races.size(); ++i)
	{
		races[i].probability =races[i].value/sum;
		if(i == 0)
		{
			races[i].pro_pos = races[i].probability;
		}
		else{
			races[i].pro_pos = races[i-1].pro_pos+races[i].probability;
		}
	}
	for(int i=0; i<races.size(); ++i)
	{
		copys.push_back(races[i]);
		races.pop_back();
	}
	float tmp;
	for(int i=0; i<100; ++i)
	{
		tmp = mice();
		races.push_back(find(tmp));
	}
	copys.clear();
}
void breed()
{
	default_random_engine generator;
	uniform_int_distribution<int> b(0,100);
	generator.seed(time(NULL));
	auto r= bind(b,generator);
	float max = -10000;
	int pos = -1;
	for(int i=0; i<races.size(); ++i)
	{
		if(races[i].value > max)
		{
			max = races[i].value;
			pos = i;
		}
	}
	cout << races[pos].num << "  " << races[pos].value << endl;
	for(int i=0; i<races.size(); ++i)
	{
		if(pos==i)
		continue;
		variation(races[i]);

	}
	for(int i=0;i<100; ++i)
	{
		crosschange(races[r()],races[r()]);
	}
	die();
}
int main()
{
	default_random_engine generator;
	uniform_int_distribution<int> p(0,1);
	generator.seed(time(NULL));
	auto hall= bind(p,generator);
	for(int i=0; i<100; ++i)
	{
		unit tmp;
		for(int i=0; i<n; ++i)
		{
			tmp.bit[i] = hall();
		}
		races.push_back(tmp);
	}
	int e = 0;
	while(e < 100000)
	{
		++e;
		breed();
	}
}
