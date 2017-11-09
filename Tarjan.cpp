#include <iostream>
#include <stack>
using namespace std;
static stack<int> s;
int **re;
int n;
int *now_in;
int *had_in;
int *step;
int *deep;
int *visit;
int count = 0;
bool visitall()
{
  for(int i=1;i<=n;++i)
  {
    if(visit[i] !=1)
    return false;
  }
  return true;
}
void dfs(int index)
{
  count += 1;
  step[index] = count;
  deep[index] = step[index];
  now_in[index] = 1;
  visit[index] = 1;
  s.push(index);
  for(int i=1;i <= n; ++i)
  {
    if(re[index][i] !=-1 && had_in[i] != 1)//两者有关系，且曾经没进过栈
    {
      if(now_in[i] == 0)//has already in the stack
      {
        dfs(i);
      }
      if(deep[index] > deep[i])
      {
        deep[index] = deep[i];
      }
    }
  }
  if(deep[index] == step[index])//根据画图的得到的经验是，pop到该元素出栈为止
  {
    cout<< "a strongly connected component:" << endl;
    while(s.top() != index)
    {
        int tmp = s.top();
        cout << tmp << "  ";
        s.pop();
        had_in[tmp] = 1;
        now_in[tmp] = 0;
    }
    int tmp = s.top();
    cout << tmp << "  " << endl;
    s.pop();
    had_in[tmp] = 1;
    now_in[tmp] = 0;
  }
  return;
}
int main()
{
  cout << "input the num"<<endl;
  cin >> n;
  visit = new int [n+1];
  step = new int [n+1];
  now_in = new int [n+1];
  deep = new int [n+1];
  had_in = new int [n+1];
  for(int i=1;i<=n;++i)
  {
    deep[i] = 0;
    step[i] = 0;
    now_in[i] = 0;
    had_in[i] = 0;
  }
  re =new int* [n+1];
  for(int i=1;i<=n;++i)
  {
    re[i] = new int [n+1];
    visit[i] = 0;
  }
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=n;++j)
    {
      re[i][j] = -1;
    }
  }
  for(int i=1;i<=n;++i)
  {
  	for(int j=1;j<=n;++j)
  	{
  		cout << i<<"  "<<j<<endl;
  		cin >> re[i][j];
	}
  }
  int tmp;
  while(!visitall())
  {
    for(int i=1;i<=n;++i)
    {
      if(visit[i] == 0)
      tmp = i;
    }
    dfs(tmp);
  }
  return 0;
}
