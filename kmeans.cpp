#include <bits/stdc++.h>
#include <cmath>
#include<conio.h>
using namespace std;

struct value
{
    double x, y;
};


int main()
{
    double t1,t2,t3,t4,sum,sum1;
    int i1,i2,i3;

    int n=30;

    value arr[n],clust1[n],clust2[n],clust3[n];
    value m1,m2,m3;
    value nm1,nm2,nm3,om1,om2,om3;

    arr[0].x = 1;
    arr[0].y = 1;
    arr[1].x = 0;
    arr[1].y = 1;
    arr[2].x = 1;
    arr[2].y = 0;

    arr[3].x = 11;
    arr[3].y = 12;
    arr[4].x = 11;
    arr[4].y = 13;
    arr[5].x = 13;
    arr[5].y = 13;

    arr[6].x=12;
    arr[6].y=8.5;
    arr[7].x=13;
    arr[7].y=8;
    arr[8].x = 13;
    arr[8].y = 9;

    arr[9].x = 13;
    arr[9].y = 7;
    arr[10].x = 11;
    arr[10].y = 7;
    arr[11].x=8;
    arr[11].y=2;

    arr[12].x=9;
    arr[12].y=2;
    arr[13].x = 10;
    arr[13].y = 1;
    arr[14].x=7;
    arr[14].y=13;

    arr[15].x=5;
    arr[15].y=9;
    arr[16].x = 16;
    arr[16].y = 16;
    arr[17].x=11.5;
    arr[17].y=8;

    arr[18].x=13;
    arr[18].y=10;
    arr[19].x = 12;
    arr[19].y = 13;
    arr[20].x=14;
    arr[20].y=12.5;

    arr[21].x=14.5;
    arr[21].y=11.5;
    arr[22].x = 15;
    arr[22].y = 10.5;
    arr[23].x=15;
    arr[23].y=9.5;

    arr[24].x=12;
    arr[24].y=9.5;
    arr[25].x = 10.5;
    arr[25].y = 11;
    arr[26].x=10;
    arr[26].y=10.5;

    arr[27].x=9;
    arr[27].y=3;
    arr[28].x = 9;
    arr[28].y = 4;
    arr[29].x=9;
    arr[29].y=5;




    cout<<"\n Enter initial mean 1:";
    cin>>m1.x;
    cin>>m1.y;
    cout<<"\n Enter initial mean 2:";
    cin>>m2.x;
    cin>>m2.y;
    cout<<"\n Enter initial mean 3:";
    cin>>m3.x;
    cin>>m3.y;


    om1.x=om2.x=om1.y=om2.y=om3.x=om3.y=0;
    nm1.x=m1.x;
    nm1.y=m1.y;

    nm2.x=m2.x;
    nm2.y=m2.y;

    nm3.x=m3.x;
    nm3.y=m3.y;
    while(nm1.x!=om1.x && nm1.y!=om1.y && nm2.x!=om2.x && nm2.y!=om2.y && nm3.x!=om3.x && nm3.y!=om3.y)
    {
        clust1[n]= {0};
        clust2[n]= {0};
        clust3[n]= {0};
        i1=i2=i3=0;
        sum=sum1=0;
        for(int i=0; i<30; i++)
        {

            t1 =abs(sqrt((arr[i].x - nm1.x) * (arr[i].x - nm1.x) + (arr[i].y - nm1.y) * (arr[i].y - nm1.y)));

            t2= abs(sqrt((arr[i].x - nm2.x) * (arr[i].x - nm2.x) + (arr[i].y - nm2.y) * (arr[i].y - nm2.y)));

            t3= abs(sqrt((arr[i].x - nm3.x) * (arr[i].x - nm3.x) + (arr[i].y - nm3.y) * (arr[i].y - nm3.y)));

            t4=min(t1, std::min(t2, t3));
            if(t1==t4)
            {
                clust1[i1].x=arr[i].x;
                clust1[i1].y=arr[i].y;
                i1++;
            }
            else if(t2==t4)
            {
                clust2[i2].x=arr[i].x;
                clust2[i2].y=arr[i].y;
                i2++;
            }
            else
            {
                clust3[i3].x=arr[i].x;
                clust3[i3].y=arr[i].y;
                i3++;
            }

        }

        om1.x=nm1.x;
        om1.y=nm1.y;

        om2.x=nm2.x;
        om2.y=nm2.y;

        om3.x=nm3.x;
        om3.y=nm3.y;



        for(int i=0; i<i1; i++)
        {
            sum =sum+clust1[i].x;
            sum1=sum1+clust1[i].y;
        }

        nm1.x=nm1.y=0;
        nm1.x=sum/i1;
        nm1.y=sum1/i1;

        sum=sum1=0;
        for(int i=0; i<i2; i++)
        {
            sum =sum+clust2[i].x;
            sum1=sum1+clust2[i].y;
        }

        nm2.x=nm2.y=0;
        nm2.x=sum/i2;
        nm2.y=sum1/i2;

        sum=sum1=0;
        for(int i=0; i<i3; i++)
        {
            sum =sum+clust3[i].x;
            sum1=sum1+clust3[i].y;
        }

        nm3.x=nm3.y=0;
        nm3.x=sum/i3;
        nm3.y=sum1/i3;


    }

    printf("*************************Final Cluster************************************\n");

    printf("mean start\n");
        printf("%lf   %lf\n",nm1.x,nm1.y);
        printf("%lf   %lf\n",nm2.x,nm2.y);
        printf("%lf   %lf\n",nm3.x,nm3.y);
        printf("mean close\n");

        printf("\n \n");

    printf("Final 1st cluster\n");
    for(int i=0; i<i1; i++)
    {
        printf("%.1lf  ,  %.1lf\n",clust1[i].x,clust1[i].y);

    }
    printf("Final 2nd cluster\n");

    for(int i=0; i<i2; i++)
    {
        printf("%.1lf  ,  %.1lf\n",clust2[i].x,clust2[i].y);

    }

    printf("Final 3rd cluster\n");

    for(int i=0; i<i3; i++)
    {
        printf("%.1lf  ,  %.1lf\n",clust3[i].x,clust3[i].y);

    }



    getch();
}
