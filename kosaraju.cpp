#include <iostream>
#include <stack>
#include <vector>
//我们为了写得简单点还是使用邻接矩阵
using namespace std;
int n;
int **re;
int count;
stack <int> s;
int *deep;
int *visit;
vector<int> scc;
bool visitall()
{
  for(int i=1;i<=n;++i)
  {
    if(visit[i] != 1)
    return false;
  }
  return true;
}
void later_dfs(int index)
{
  visit[index] = 1;
  for(int i=1;i<=n;++i)
  {
    if(re[index][i] != 0 && visit[i] != 1)//index can arrive at i
    {
      later_dfs(i);
    }
  }
  ++count;
  deep[index] = count;
  s.push(index);
}
void regra()//如果脑容量够大的话是不需要真的把图的矩阵转置的，你只交换下两个参数的位置
{
  int **copy = new int *[n+1];
  for(int i =1;i<=n;++i)
  {
    copy[i] = new int [n+1];
  }
  for(int i=1;i<=n;++i)
  {
    for(int j = 1;j<=n;++j)
    {
      copy[i][j] = re[i][j];
    }
  }
  for(int i = 1;i<=n;++i)
  {
    for(int j=1;j<=n;++j)
    {
      re[i][j] = copy[j][i];
    }
  }
  return;
}
void redfs( int index)
{
  visit[index] = 1;
  scc.push_back(index);
  for(int i=1;i<=n;++i)
  {
    if(re[index][i] ==1 && visit[i] != 1)
    {
      redfs(i);
    }
  }
  return;
}
int main()
{
  n = 6;
  count = 0;
  visit = new int [n+1];
  deep = new int [n+1];
  re = new int *[n+1];
  for(int i=1;i<=n;++i)
  {
    re[i] = new int [n+1];
  }
  for(int i=1;i<=n;++i)
  {
    for(int j =1;j<=n;++j)
    {
      re[i][j] = 0;
    }
    visit[i] = 0;
    deep[i] = 0;
  }
    for(int i=1;i<=n;++i)
    {
      for(int j=1;j<=n;++j)
      {
        cout << i << "  " << j << endl;
        cin >> re[i][j];
      }
    }
    int tmp;
  //add some static data for test
  while(!visitall())
  {
      for(int i=1;i<=n;++i)
      {
        if(visit[i] == 0)
        {
          tmp = i;
          break;
        }
      }
      later_dfs(tmp);
  }
  regra();
  for(int i=1;i<=n;++i)
  visit[i] = 0;//把这数据清理干净，我们开始准备进行下面的操作

  int top = s.top();
  while(!s.empty())
  {
    if(visit[top] ==1)
    {
      s.pop();
      top = s.top();
      continue;
    }
    redfs(top);
    cout<< "There is an scc:" << endl;
    for(int i=0;i<scc.size();++i)
    {
      cout<< scc[i]<<" ";
    }
    cout << endl;
    scc.clear();
    s.pop();
    top = s.top();
  }
}
