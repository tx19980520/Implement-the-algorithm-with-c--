#include<iostream>
using namespace std;
int n;
int m;
int **re;
int *choose;
int *image_choose;
int *visit;
bool rechoose(int index)
 {
	for(int j=1;j <= m; ++j)
    {
    	if (re[index][j] == 1 && visit[j] != 1)
        {
        	if(image_choose[j] == 0)
            {
            	image_choose[j] = index;
            	return true;
            }
            else{
            	int tmp = image_choose[j];
       			image_choose[j] = index;
       			visit[j] = 1;
         		 return rechoose(tmp);
               }
        }
	}
    return false;
 }
 void chosen( int index)
 {
 	if (index == n+1)
 	{
 		return;
	}
   for(int i=1; i <= m; ++i)
   {
     if(re[index][i] == 1)
     {
       if(choose[i] == 0)
       {
         choose[i] = index;
         break;
       }
       else{
       	int tmp = choose[i];
       	for(int f = 1;f <= m;++f)
       	{
       		visit[f] = 0;
       		image_choose[f] =choose[f];
		}
		image_choose[i] = index;
       	visit[i] = 1;
        if(rechoose(tmp))
        {
        	for(int j= 1;j <= m;++j)
         	choose[j] = image_choose[j];
         	for(int j=1;j<=m;++j)
         	break;
		}
       }
     }
   }
   chosen(index+1);
 }

int main()
{
  cout << "n:";
  cin >> n;
  cout << endl;
  cout << "m:";
  cin >> m;
  visit = new int[m+1];
  re = new int *[n+1];
  choose = new int [m+1];
  image_choose = new int [m+1];
  for(int i=1;i <= n; ++i)
  {
    re[i] = new int [m+1];
  }
  for(int i=1;i<=m;++i)
  {
  	 choose[i] = 0;
    image_choose[i] = 0;
    visit[i] = 0;
  }
  for(int i= 1;i <= n; ++i)
  {
    for(int j=1;j <= m; ++j)
    {
      re[i][j] = 0;
    }
  }
  re[1][1] = re[1][2] = re[1][4]= re[2][2]= re[2][5] = re[3][4] = re[3][1]=re[3][7]=re[4][3] = re[4][4] = re[4][6] = 1;
  re[5][4] = re[6][4] = 1;
  chosen(1);
  for(int i=1;i <= m; ++i)
  {
    cout << i << "    " << choose[i] << endl;
  }
  return 0;
}
