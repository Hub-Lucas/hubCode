/* 
    int w[5] = {200,300,600,100,500}; 价格
    int a[5] = {2 , 3 , 5 ,1 , 4};           cpu
    int b[5] = {3 , 5 , 4 , 2 , 1};          内存

   输出最高收益900
*/
#include <iostream>

 using namespace std ; 

 const int x = 8 ;                             //cpu数目 

 const int y = 10 ;                             //内存数目 

 const int n = 5 ;                             //报价条数 

 

 int f[x+1][y+1] ;                      //定义二位数组
 int w[n] = {200,300,600,100,500};                       

 int a[n] = {2 , 3 , 5 ,1 , 4};            

 int b[n] = {3 , 5 , 4 , 2 , 1};

 int INF = -66666  ;

 int max(int a, int b)
{
if (a>b)
return a;
else
return b;
}
   

 int get_max()

 {

    for(int i = 1 ; i <= x ;i++) 
	
      for(int j = 1 ; j <= y ;j++)

	  
		  f[i][j] = INF ;    

      

      f[0][0] = 0 ; 

    

    for(int k = 0 ; k < n ; k++)

    {

      for(int u = x ; u >= a[k] ;u--) 

         {         

           for(int v = y ; v >= b[k] ;v--)                           

              f[u][v] = max(f[u-a[k]][v-b[k]] + w[k] , f[u][v])  ;

         }                 

    }

    return f[x][y] ;        

 }

 

 int main()

 {

      

   int temp = get_max() ;   

   cout<<temp<<endl     ;   

   return 0 ;    

 }