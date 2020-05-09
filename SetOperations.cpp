#include<iostream>
#define size 20
using namespace std;
class MyClass
{
	int badmintonCount,cricketCount,arrCricket[20],arrBadminton[20],bothCount=0, uni[10];
	int arrOnlyCricket[10];
    int onlyCricketCount=0;
    int arrOnlyBadminton[10];
    int onlyBadmintonCount=0;


	public:
		void getData()
		{

            for(int i=0;i<10;i++)
			{
				arrOnlyCricket[i]=0;
				arrOnlyBadminton[i]=0;
				uni[i]=0;
			}
			cout<<"\nEnter the number of students who plays Badminton : ";
			cin>>badmintonCount;
			cout<<"\nEnter roll number of Badminton players :";
			for(int i=0;i<badmintonCount;i++)
			{
				cin>>arrBadminton[i];
			}
			cout<<"\nEnter the number of students who plays Cricket : ";
			cin>>cricketCount;
			cout<<"\nEnter roll number of Cricket players : ";
			for(int i=0;i<cricketCount;i++)
			{
				cin>>arrCricket[i];
			}
		}
		void myUnion()
		{
			for(int i=0;i<badmintonCount;i++)
			{
				for(int j=0;j<cricketCount;j++)
				{
					if(arrBadminton[i]==arrCricket[j])
					{
						uni[bothCount]=arrBadminton[i];
						bothCount++;
					}
				}
			}
			cout<<"\\n\nRoll No. of students who play both Cricet & Badminton ar5e : ";

			for(int i=0;i<bothCount;i++)
			{
				cout<<uni[i]<<"  ";
			}
		}
		void onlyCricket()
		{

			for(int i=0;i<cricketCount;i++)
			{
			    int temp=arrCricket[i];
			    int tempCounter=0;
				for(int j=0;j<bothCount;j++)
                {
                    if(temp==uni[j])
                    {
                        break;
                    }
                    else
                    {
                        tempCounter++;
                    }
                }
                if(tempCounter==bothCount)
                {
                    arrOnlyCricket[onlyCricketCount]=arrCricket[i];
                    onlyCricketCount++;
                }
			}
			cout<<"\n\nRoll No. of students who play only Cricket : ";
			for(int i=0;i<onlyCricketCount;i++)
			{
				cout<<arrOnlyCricket[i]<<"  ";
			}
		}
		void onlyBadminton()
		{
			for(int i=0;i<badmintonCount;i++)
			{
			    int temp=arrBadminton[i];
			    int tempCounter=0;
				for(int j=0;j<bothCount;j++)
                {
                    if(temp==uni[j])
                    {
                        break;
                    }
                    else
                    {
                        tempCounter++;
                    }
                }
                if(tempCounter==bothCount)
                {
                    arrOnlyBadminton[onlyBadmintonCount]=arrBadminton[i];
                    onlyBadmintonCount++;
                }
			}
			cout<<"\n\nRoll No. of students who play only Badminton : ";
			for(int i=0;i<onlyBadmintonCount;i++)
			{
				cout<<arrOnlyBadminton[i]<<"  ";
			}
		}

};
int main()
{
	MyClass obj;
	obj.getData();
	obj.myUnion();
	obj.onlyCricket();
    obj.onlyBadminton();
    cout<<"\n\n";
}
