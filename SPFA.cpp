#include <iostream>
#include <deque>//最开始用的queue后来使用了slf改进，改为了deque，如果要入队的元素小于队头元素的距离，则插入队头，否则插入队尾
using namespace std;
int main()
{
  cout << "confirm your the num of your node"<<endl;
  int n;
  cin >> n;
  int *now_in = new int [n+1];
  int *push_time = new int [n+1];
  int *final = new int [n+1];
  int **dis = new int *[n+1];
  for(int i=1;i <= n; ++i)
  {
    dis[i] = new int [n+1];
    final[i] = 1000000;
    now_in[i] = 0;
    push_time[i] = 0;
  }
  push_time[1] = 1;
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=n;++j)
    {
      dis[i][j] = 1000000;
    }
  }
  for(int i=1;i<=n;++i)
  {
    dis[i][i] = 0;
  }
  cout << "input your distance."<<endl;
  int mark = 0;
  int start,end,distance;
  while(mark !=-1)
  {
    cout << "start"<<endl;
    cin >> start;
    cout << "end"<<endl;
    cin >> end;
    cout << "distance"<<endl;
    cin >> distance;
    dis[start][end] = distance;
    cout <<"if you complete it, input -1"<<endl;
    cin >> mark;
  }
  deque<int> q;
  q.push_back(1);
  while(!q.empty())
  {
    int front = q.front();
    q.pop_front();
    now_in[front] = 0;
    for(int i = 1;i <= n; ++i)
    {
      if (dis[1][front]+dis[front][i] < final[i])//如过能松弛，则正常松弛，与dijstra一样
      {
        final[i] = dis[1][front]+dis[front][i];//这个地方单独拿出来了final后来细想貌似就在矩阵里操作就好了
        dis[1][i] = final[i];
        if(now_in[i] != 1)
        {
          now_in[i] = 1;
          push_time[i] += 1;
          if(!q.empty())
          {
            int tmp = q.front();
            if (final[i]<final[tmp])
            {
              q.push_front(i);
            }
            else {q.push_back(i);}
          }
          else q.push_back(i);
        }
        if(push_time[i] == n)
        {
          cout << "it has a negative weight circle which includes " << i << "!" << endl;
          return 0;
        }
      }
    }
  }
  for(int i=1;i <= n; ++i)
  {
    cout << "1 to " << i <<":   " << final[i] << endl;
  }
  return 0;
}
