#PARN PRATAP SINGH 2K20/MC/094
#include <bits/stdc++.h>
using namespace std;
int randbin[10],deceq,randdec,wins=0;
string bineq;
class mode{
   public:
   int play()
{
    srand(time(0));
     int x=rand()%2;
      
    if (x==0)
{
    for(int i=1;i<=6;i++)
    {
    	randbin[i]=rand()%2;
	}

	printf(" ==============================\n");
	printf(" ");
	for(int j=1;j<=6;j++)
	{   
		printf("| %d |",randbin[j]);
	}
	printf("\n ==============================");
	printf("\nENTER THE DECIMAL EQUIVALENT:");
	scanf("%d",&deceq);
	check(deceq);
}
 else if (x==1)   
 
 {
 	 randdec=rand()%64;
    
   
	printf(" ==============================\n");
	printf(" ");
	for(int i=1;i<=6;i++)
	{   
		printf("| 0 |");
	}
	printf("\n ==============================");
	printf("\n\n-------------| %d |-------------\n",randdec);
	printf("\nENTER THE BINARY EQUIVALENT:");
	cin>>bineq;
    check(bineq);
 }
}
int check(int deceq)
{
	int sum=0,base=1;
	for(int i=6;i>=1;i--)
    {
    	sum+=(randbin[i])*base;
    	base*=2;
	}
	if (sum==deceq)
	{
	printf("CORRECT ANSWER    WELL DONE");
	wins=wins+1;
    }
	else
	{
	printf("WRONG ANSWER    ");
	printf("CORRECT ANSWER IS %d",sum);
    }

}

int check(string bineq)
{    
     int checkarr1[10],checkarr2[10];
     string s;
    int i=0,x,base=1,sum=0;
    while(randdec>0)
          {
          	 checkarr1[i]=randdec%2;
          	 randdec/=2;
          	 i++;
		  }
		 
		  x=i;
		  for(int j=0;j<x;j++)
		  {
		  	checkarr2[j]=checkarr1[i-1];
		  	i--;
		  }
	for (int i=0;i<=x-1;i++)
	{
        int l;
			
        if(checkarr2[i]==1)
        l=49;
        else
        {
            l=48;
        }
        char k=l;
        s.push_back(k);	
	}
	if(s.size()==0){
        s.push_back('0');
    }
	if (s==bineq)
	{
	printf("CORRECT ANSWER    WELL DONE");
	wins=wins+1;
    }
    else
    { 
   	printf("WRONG ANSWER     CORRECT ANSWER IS:");
   	
    cout<<s;
	}
}
};

class playeasy : public mode
{
    public:
    void help(){
	printf("   32   16   8    4    2    1\n");
}
};

class playhard : public mode
{
   
};
int main()
{   system("color 3b");
    printf("WELCOME TO THE BINARY NUMBER GAME\n\n");
    int i=1,eh;
    choose:
    printf("PRESS 1 FOR EASY MODE , 2 FOR HARD MODE AND 3 FOR INSTRUCTIONS:");
    scanf("%d",&eh);
    clock_t start,end;
    double time=0;
    start=clock();
    playeasy e;
    if (eh==1)
    {
	  while(i<=5) 
	    {
	    	e.help();
	       e.play();
	       
	        i++;
	        printf("\n\n\n");
	     
         } 
     printf("YOUR SCORE IS %d / 5",wins);
    }
    else if (eh==2)
    {
        playhard h;
	  while(i<=5) 
	    {
	       h.play();
	       
	        i++;
	        printf("\n\n\n");
	     
         } 
     printf("YOUR SCORE IS %d / 5",wins);
    }
    else if (eh==3)
	{
    	printf("FOR EASY MODE:-\nFor binary to decimal- just add the numbers corresponding to 1 written above to calculate the decimal equivalent.");
    	printf("\nFor decimal to binary- find the number just lower than the decimal number and write 1 in its place. Now subtract this from the original number and repeat the steps. Insert 0's in between. ");
    	printf("\n\nFOR HARD MODE:-\n Now imagine the numbers to be written above as in easy mode and proceed in the same way.\n");
    	goto choose;
	}
    else
       {
       	printf("INVALID MODE\n");
       	goto choose;
	   }
	end=clock();
	time=((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken to complete : %f seconds",time);
}
