#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include <time.h>
#include "clui.h"
using namespace std;

//int n[100][100];
struct id
{
    char name[100];

    int score;
} id1[20];
int load[5][201][201];
int tedad[5];
int bomb[5];
int cow[5];

int f,col,coi;
//int r,c;

int menu()
{
    char n;
    change_color_rgb(255, 255, 255);
    cout<<"enter number"<<endl<<endl<<endl;
    change_color_rgb(252, 3, 78);
    cout<<"1_New Game"<<endl<<endl;
    cout<<"2_Load Game"<<endl<<endl;
    cout<<"3_Change Name"<<endl<<endl;
    cout<<"4_Leaderboard"<<endl<<endl;
    cout<<"5_Quit"<<endl;
    cin>>n;
    reset_color();
    return (n-48);

}


int leader_bord_bubble()
{
    int swap_score;

    char swap_name[100];

    int l1,l2,l3;
    char n;

    for(int i=1 ; i<=coi ; i++)
    {
        for(int j=1 ; j<=coi; j++)
        {
            if(id1[i].score>id1[j].score)
            {
                l1=0;

                l2=0;

                l3=0;

                swap_score=id1[j].score;

                id1[j].score=id1[i].score;

                id1[i].score=swap_score;

                while(id1[j].name[l1]!='\0')
                {
                    l1++;
                }

                for(int u=0; u<=l1; u++)
                {
                    swap_name[u]=id1[j].name[u];
                }

                while(id1[i].name[l2]!='\0')
                {
                    l2++;
                }

                for(int u=0; u<=l2; u++)
                {
                    id1[j].name[u]=id1[i].name[u];
                }

                while(swap_name[l3]!='\0')
                {
                    l3++;
                }

                for(int u=0; u<=l3; u++)
                {
                    id1[i].name[u]=swap_name[u];
                }
            }
        }
    }

    for(int i=1; i<=coi; i++)
    {
        cout<<id1[i].name<<"                 "<<id1[i].score;

        cout<<endl;
    }
    cout<<"if you want back to menu  enter 'Q'"<<endl;
    cin>>n;
    return (n-48);

}
int newg_level()
{
    char n;
    change_color_rgb(255, 255, 255);
    cout<<"enter number"<<endl<<endl<<endl;
    change_color_rgb(97, 251, 45);
    cout<<"1_Easy"<<endl<<endl;
    change_color_rgb(94, 19, 230);
    cout<<"2_Normal"<<endl<<endl;
    change_color_rgb(255, 13, 19);
    cout<<"3_Hard"<<endl<<endl;
    change_color_rgb(255, 255, 255);
    cout<<"4_Make your game"<<endl;
    cin>>n;
    reset_color();
    return (n-48);
}

int which_load()
{
    char n;
    change_color_rgb(255, 255, 255);
    cout<<"enter number"<<endl<<endl<<endl;
    change_color_rgb(252, 3, 78);
    cout<<"1_first  save"<<endl<<endl;
    cout<<"2_second save"<<endl<<endl;
    cout<<"3_third  save"<<endl<<endl;
    cout<<"4_fourth save"<<endl<<endl;
    cin>>n;
    reset_color();
    return (n-48);
}
void bombnist(int** n,int a,int b,int rt)
{
    int sum,x,y;
    sum=0;

    for(x=a-1; x<=a+1; x++)
    {
        for(y=b-1; y<=b+1; y++)
        {
            if(x<rt && y<rt && x>=0 && y>=0)
            {
                if(n[x][y]==-1)
                {
                    //cout<<"aaaa"<<endl;
                    sum++;
                }
            }
        }
    }
    if(sum>0)
    {
        n[a][b]=sum;
    }
    else
    {
        n[a][b]=0;
        for(x=a-1; x<=a+1; x++)
        {
            for(y=b-1; y<=b+1; y++)
            {
                if(x<a && y<b && x>=0 && y>=0)
                {
                    if(n[x][y]==-2)
                        bombnist(n,x,y,rt);

                }
            }
        }

    }



}

void chap (int** n,int a, int x,int y,int** nf)
{
    int fc;
    fc=0;

    cout<<endl;

    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
        {
            change_color_rgb(97, 251, 45);
            cout<<" ----- ";

        }

        cout<<endl;

        for(int j=0; j<a; j++)
        {
            if (i==x && j==y)
            {
                change_color_rgb(255, 13, 19);
                fc=1;
            }

            switch(n[i][j])
            {
            case -1:
                if(f==0)
                {
                    if(fc==0)
                        change_color_rgb(97, 251, 45);


                    cout<<" | "<<"B"<<" | ";
                }
                else
                {
                    if(fc==0)
                        change_color_rgb(97, 251, 45);
                    if(nf[i][j]==1)
                    {
                        cout<<" | "<<"F"<<" | ";
                    }
                    if(nf[i][j]==0)
                    {
                        cout<<" | "<<"*"<<" | ";
                    }
                }
                break;

            case -2:
                if(fc==0)
                    change_color_rgb(97, 251, 45);
                if(nf[i][j]==1)
                {
                    cout<<" | "<<"F"<<" | ";
                }
                if(nf[i][j]==0)
                {
                    cout<<" | "<<"*"<<" | ";
                }
                break;

            case 0:
                if(fc==0)
                    change_color_rgb(10, 100, 15);
                cout<<" | "<<" "<<" | ";
                break;

            default:
                if(fc==0)
                    change_color_rgb(97, 251, 45);

                cout<<" | "<< n[i][j] <<" | ";

            }

            reset_color();
            fc=0;


        }

        cout<<endl;
    }
}
void loadgame (int** n,int a,int b,int countp)
{

    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
        {
            load[col][i][j]=n[i][j];
        }
    }
    tedad[col]=a;
    bomb[col]=b;
    cow[col]=countp;

}

void wsad(int** n,int a,int& i,int& j,int& countp,int ne,int& d,int* p1,int* p2,int** nf,int& fq)
{

    char c[10];
    int ib,jb,rr,cc,fff,b;
    bool fw;
    fff=fq=0;

    cin.getline(c,2);
    //clear_screen();
    if(c[0]=='w')
    {
        ib=i;
        i--;
        if(i>0)
        {
            clear_screen();
            chap(n,a,i,j,nf);
        }
        if(i<0)
        {
            i=ib;
            clear_screen();
            chap(n,a,i,j,nf);
        }
    }
    if(c[0]=='s')
    {
        ib=i;
        i++;
        if(i<a)
        {
            clear_screen();
            chap(n,a,i,j,nf);
        }
        if(i>=a)
        {
            i=ib;
            clear_screen();
            chap(n,a,i,j,nf);
        }
    }
    if(c[0]=='a')
    {
        jb=j;
        j--;
        if(j>0)
        {
            clear_screen();
            chap(n,a,i,j,nf);
        }
        if(j<0)
        {
            j=jb;
            clear_screen();
            chap(n,a,i,j,nf);
        }

    }
    if(c[0]=='d')
    {
        jb=j;
        j++;
        if(j<a)
        {
            clear_screen();
            chap(n,a,i,j,nf);
        }
        if(j>=a)
        {
            j=jb;
            clear_screen();
            chap(n,a,i,j,nf);
        }

    }
    if(c[0]==' ')
    {
        rr=i;
        cc=j;
        if( rr<=a && cc<=a && rr>=0 && cc>=0 )
        {
            fw=true;

            for(int g=0; g<201; g++)
            {
                if(p1[g]==rr && p2[g]==cc)
                {
                    fw=false;

                    break;
                }
            }

            if(fw==true)
            {
                // cout<<"shemord"<<endl;
                //cout<<"ezaf shod";
                countp++;
            }
            //cout<<"countp= "<<countp<<endl;
            //cout<<"ne= "<<ne<<endl;


            p1[d]=rr;
            p2[d]=cc;
            d++;
            //cout<<"rikhte shod"<<endl;
            //cout<<"co= "<<countp<<endl;
            //cout<<"d= "<<d<<endl;
            // cout<<"ne= "<<ne<<endl;

        }
        if(n[rr][cc]!=-1)
        {
            bombnist(n,rr,cc,a);
        }
        clear_screen();
        if(n[rr][cc]==-1)
        {
            cout<<"_____GAME OVER_____"<<endl;
            f=0;
        }
        if((countp)==ne)
        {
            cout<<"______YOU WON______"<<endl;
            f=0;
        }


        chap(n,a,rr,cc,nf);

    }
    if(c[0]=='Q')
    {
        fq=1;
    }
    if(c[0]=='F')
    {
        rr=i;
        cc=j;
        if(nf[i][j]==0)
        {
            nf[i][j]=1;
            fff=1;
            //cout<<"lll"<<endl;
        }
        if(nf[i][j]==1 && fff==0)
            nf[i][j]=0;
        //cout<<nf[i][j];
        clear_screen();
        chap(n,a,rr,cc,nf);

    }
    if(c[0]=='O')
    {
        col++;
        if(col>4)
        {
            clear_screen();
            cout<<"sorry! I can't save your game. the number of your saved game is too much , please continue. "<<endl;
            chap(n,a,i,j,nf);
        }

        else
        {

            b=(a*a)-ne;
            id1[coi].score=(countp);
            loadgame(n,a,b,countp);
            fq=1;
        }

    }


}

int gametime_load(int flo,int a,int b,int countp)
{
    int rr,cc,nt,nb,ne,coo,cooo,nbb,again,ii,d,dw,jj,fq;
    char ans,type;
    again=1;
    ii=jj=cooo=0;
    bool fw;



    while(again==1)
    {
        int** n;
        n=new int*[a];
        for (int l = 0; l < a; l++)
            n[l] = new int[a];

        int** nf;
        nf=new int*[a];
        for (int l = 0; l < a; l++)
            nf[l] = new int[a];

        int* p1=new int[201];
        int* p2=new int[201];
        for(int i=0; i<201; i++)
        {
            p1[i]=1000;
            p2[i]=1000;
        }
        d=0;
        dw=0;


        f=1;
        //countp=0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                n[i][j]=load[flo][i][j];
            }
        }

        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                nf[i][j]=0;
            }
        }

        nt=a*a;
        nb=b;
        ne=nt-nb;

        do
        {
            clear_screen();
            cout<<"wich type you want to play  1_WSAD  2_decarti"<<endl;
            cin>>type;
            clear_screen();
            type-=48;
        }
        while(type<1 || type>2);

        if(cooo==0 && type==1)
        {
            clear_screen();
            chap(n,a,0,0,nf);
        }
        cooo++;

        while(f!=0)
        {


            if(type==1)
            {
                //cout<<"he he"<<endl;

                wsad(n,a,ii,jj,countp,ne,dw,p1,p2,nf,fq);
                if(fq==1)
                    break;
            }
            // cout<<"he he"<<endl;

            if(type==2)
            {
                do
                {
                    //clear_screen();
                    cout<<"enter row & column"<<endl;
                    cin>>rr>>cc;
                    clear_screen();
                    //clc system("cls");
                    if(rr>=a || cc>=a || rr<0 || cc<0)
                        chap(n,a,rr,cc,nf);
                    rr--;
                    cc--;
                }
                while(rr>=a || cc>=a || rr<0 || cc<0);

                if( rr<=a && cc<=a && rr>=0 && cc>=0 )
                {
                    fw=true;

                    for(int g=0; g<201; g++)
                    {
                        if(p1[g]==rr && p2[g]==cc)
                        {
                            fw=false;

                            break;
                        }
                    }

                    if(fw==true)
                    {
                        countp++;
                        // cout<<"ezaf shod";
                    }

                }

                p1[d]=rr;
                p2[d]=cc;
                d++;

                if(n[rr][cc]!=-1)
                {
                    bombnist(n,rr,cc,a);
                }
                if(n[rr][cc]==-1)
                {
                    cout<<"_____GAME OVER_____"<<endl;
                    f=0;
                }

                if(countp==ne)
                {
                    cout<<"______YOU WON______"<<endl;
                    f=0;
                }


                chap(n,a,rr,cc,nf);

            }
            if(f==0)
            {
                delete[] p1;
                delete[] p2;
            }


        }
        for (int i = 0; i < a; i++)
        {

            delete[] n[i];
            delete[] nf[i];
        }
        delete[] n;
        delete[] nf;
        if(fq==0)
        {
            cout<<"DO YOU PLAY AGAIN ?"<<endl;
            cout<<"PLEASE TYPE 'Y' OR 'N' ."<<endl;
            cin>>ans;
            clear_screen();

            if(ans=='Y')
            {
                again=1;
                f=1;
                cooo=0;
            }
            else
                again=0;
        }
        if(fq==1)
        {
            break;
        }



    }
}


int gametime(int a,int b)
{
    int rr,cc,nt,nb,ne,countp,coo,cooo,nbb,again,ii,d,dw,jj,fq,fdf;
    char ans,type;
    again=1;
    ii=jj=cooo=fdf=0;
    bool fw;
    coi++;
    cout<<"first enter your name"<<endl;
    cin.getline(id1[coi].name,100);


    //clear_screen();

    while(again==1)
    {
        int** n;
        n=new int*[a];
        for (int l = 0; l < a; l++)
            n[l] = new int[a];

        int** nf;
        nf=new int*[a];
        for (int l = 0; l < a; l++)
            nf[l] = new int[a];

        int* p1=new int[201];
        int* p2=new int[201];
        for(int i=0; i<201; i++)
        {
            p1[i]=1000;
            p2[i]=1000;
        }
        d=0;
        dw=0;


        f=1;
        countp=0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                n[i][j]=-2;
            }
        }

        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                nf[i][j]=0;
            }
        }
        fdf=1;
        srand(time(NULL));
        nt=a*a;
        nb=b;
        nbb=nb;
        for(int h=0; h<nbb; h++)
        {
            coo=0;
            int randr = rand() % a ;
            int randc = rand() % a ;
            if(n[randr][randc]==-1)
            {
                coo++;
            }
            n[randr][randc]=-1;
            nbb=nbb+coo;

        }
        ne=nt-nb;
        if(fdf==1)
        {

            do
            {
                cout<<"wich type you want to play  1_WSAD  2_decarti"<<endl;
                cin>>type;
                clear_screen();
                type-=48;
            }
            while(type<1 || type>2);

        }

        if(cooo==0 && type==1)
        {
            chap(n,a,0,0,nf);
        }
        cooo++;

        while(f!=0)
        {


            if(type==1)
            {
                //cout<<"he he"<<endl;

                wsad(n,a,ii,jj,countp,ne,dw,p1,p2,nf,fq);
                if(fq==1)
                    break;
            }
            // cout<<"he he"<<endl;

            if(type==2)
            {
                do
                {

                    //clear_screen();
                    cout<<"enter row & column"<<endl;
                    cin>>rr>>cc;
                    clear_screen();
                    rr--;
                    cc--;
                    if(rr>=a || cc>=a || rr<0 || cc<0)
                        chap(n,a,rr,cc,nf);

                }
                while(rr>=a || cc>=a || rr<0 || cc<0);

                if( rr<=a && cc<=a && rr>=0 && cc>=0 )
                {
                    fw=true;

                    for(int g=0; g<201; g++)
                    {
                        if(p1[g]==rr && p2[g]==cc)
                        {
                            fw=false;

                            break;
                        }
                    }

                    if(fw==true)
                    {
                        //cout<<"ezaf shod";
                        countp++;
                    }


                }

                p1[d]=rr;
                p2[d]=cc;
                d++;

                if(n[rr][cc]!=-1)
                {
                    bombnist(n,rr,cc,a);
                }
                if(n[rr][cc]==-1)
                {
                    cout<<"_____GAME OVER_____"<<endl;
                    f=0;
                }
                if(countp==ne)
                {
                    cout<<"______YOU WON______"<<endl;
                    f=0;
                }
                id1[coi].score=(countp);



                chap(n,a,rr,cc,nf);

            }
            if(f==0)
            {
                delete[] p1;
                delete[] p2;
            }


        }
        for (int i = 0; i < a; i++)
        {

            delete[] n[i];
            delete[] nf[i];
        }
        delete[] n;
        delete[] nf;
        if(fq==0)
        {
            cout<<"DO YOU PLAY AGAIN ?"<<endl;
            cout<<"PLEASE TYPE 'Y' OR 'N' ."<<endl;
            cin>>ans;
            clear_screen();


            if(ans=='Y')
            {
                again=1;
                f=1;
                cooo=0;
            }
            else
                again=0;
        }
        if(fq==1)
        {
            break;
        }



    }
}

void Easy()
{
    int a,b;
    a=5;
    b=4;
    gametime(a,b);
}
void Normal()
{
    int a,b;
    a=12;
    b=28;
    gametime(a,b);
}
void Hard()
{
    int a,b;
    a=20;
    b=96;
    gametime(a,b);
}
void Custom()
{
    int a,b,a2;

    do
    {
        cout<<"enter one number for make your area(n  ---->  n*n)"<<endl;
        cin>>a;
    }
    while(a<5 || a>20);
    clear_screen();
    do
    {
        cout<<"enter number of bomb"<<endl;
        cin>>b;
    }
    while(b<1 || b>(a*a));
    clear_screen();

    gametime(a,b);
}

int main()
{
    int f1,f2,fs,fm,flo,al,bl,cl,fh;
    f1=f2=1;

    init_clui();

    while(true)
    {


        clear_screen();

        fm=0;
        fm=menu();
        if(fm==1)
        {
            clear_screen();

            //clc
            do
            {
                fs=newg_level();
                if(fs==1)
                {
                    clear_screen();
                    Easy();
                    f2=1;
                }
                else if(fs==2)
                {
                    clear_screen();
                    Normal();
                    f2=1;
                }
                else if(fs==3)
                {
                    clear_screen();
                    Hard();
                    f2=1;
                }
                else if(fs==4)
                {

                    clear_screen();
                    Custom();
                    f2=1;
                }
                else
                {
                    f2=0;
                    clear_screen();
                    cout<<"Please enter the numbers that exist"<<endl;
                }


            }
            while(f2==0);
        }

        if(fm==2)
        {
            clear_screen();
            if(col<1)
                continue;
            do
            {
                clear_screen();
                flo=which_load();

                al=tedad[flo];
                bl=bomb[flo];
                cl=cow[flo];
            }
            while(flo<1 || flo>4 || flo>col);
            clear_screen();
            gametime_load(flo,al,bl,cl);

        }

        if(fm==4)
        {
            while(true)
            {

                clear_screen();
                fh=leader_bord_bubble();
                if(fh==33)
                    break;

            }


        }

        if(fm==5)
        {
            clear_screen();
            break;
        }


        else
        {
            //clc
            cout<<"Please enter the numbers that exist"<<endl;
        }


    }


    return 0;
}
