#include<iostream>
#define size 20
using namespace std;
class MyClass
{
	int badmin,cric,cricket[20],badm[20],count=0, uni[5];
	public:
		void getData()
		{
			cout<<"\n Enter the number of students who plays the badminton.";
			cin>>badmin;
			cout<<"\n Enter the roll no. of studets who play badminton :";
			for(int i=0;i<badmin;i++)
			{
				cin>>badm[i];
			}
			cout<<"\n Enter the number of students who plays the cricket.";
			cin>>cric;
			cout<<"\n Enter the roll no. of students who plays cricket. ";
			for(int i=0;i<cric;i++)
			{
				cin>>cricket[i];
			}
		
			
		}
		void myUnion()
		{
			for(int i=0;i<5;i++)
			{
				uni[i]=0;
			}
			for(int i=0;i<badmin;i++)
			{
				for(int j=0;j<cric;j++)
				{
					if(badm[i]==cricket[j])
					{
						uni[count]=badm[i];
						count++;
					}
				}
			}
			cout<<"\n set of students who play both cricket and badminton is:";
		
		
			for(int i=0;i<count;i++)
			{
				cout<<"\n"<<uni[i];
			}
		}
		void onlyCric()
		{
			int onlycri[10];
			int count1=0;
			for(int i=0;i<10;i++)
			{
				onlycri[i]=0;
			}
			for(int i=0;i<cric;i++)
			{
				for(int j=0;j<count;j++)
				{
					if(cricket[i]==uni[j]){
						break;
					}
					else
					{
						onlycri[count1]=cricket[i];
						count1++;
						break;
					}
				}
			}
			cout<<"\n Set of students who play only cricket";
			for(int i=0;i<count1;i++)
			{
				cout<<"\n"<<onlycri[i];
			}
		}
		/*void onlyBad()
		{
			int onlybad[10],count1=0;
			for(int i=0;i<10;i++)
			{
				onlybad[i]=0;
			}
			for(int i=0;i<badmin;i++)
			{
				for(int j=0;j<count;j++)
				{
					if(badm[i]!=uni[j])
					{
						onlybad[count1]=badm[i];
						count1++;
					}
				}
			}
			cout<<"\n Set of students who play only cricket";
			for(int i=0;i<count1;i++)
			{
				cout<<"\n"<<onlybad[i];
			}
		}*/
		
};
int main()
{
	MyClass obj;
	obj.getData();
	obj.myUnion();
	obj.onlyCric();

}
