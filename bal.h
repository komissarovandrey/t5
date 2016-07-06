#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ret return
#define nil NULL
/*============================================max==========================================*/
int max (int i,int j)
{
    ret ((i>j)*i+(i<=j)*j);
}
/*============================================max==========================================*/
/*============================================print========================================*/
int print(struct tree*az)
{
    if (az!=nil)
    {
        print(az->l);
        int i;
        for (i=0;i<az->lv;i++)
        {
            putchar('-');
        }
        printf("%d-%s-\n",az->lv,az->st);
        print(az->r);
    }
    ret 0;
}
/*============================================print========================================*/
int fix(struct tree*az);
int g(struct tree*az);
/*============================================g============================================*/
int g(struct tree*az)
{
    if (az!=nil)
    {
        if (az->lv==0)
        {
            fix(az);
        }
        ret az->lv;
    }
    ret -1;
}
/*============================================g============================================*/
/*============================================fix==========================================*/
int fix(struct tree*az)
{
    if (az!=nil)
    {
        int i=fix(az->l);
        int j=fix(az->r);
        int k=max(i,j)+1;
        ret az->lv=k;
    }
    ret 0;
}
/*============================================fix==========================================*/
/*============================================roter_r======================================*/
struct tree* roter_r(struct tree*az)
{
    if (az==nil)
    {
        ret az;
    }
    struct tree*az0=az->l;
    if (az0==nil)
    {
        ret az;
    }
    struct tree*a=az0->l;
    struct tree*b=az0->r;
    struct tree*c=az ->r;
    
    az0->r=az;
    az0->l=a;
    az ->l=b;
    az ->r=c;
    ret az0;
}
/*============================================roter_r======================================*/
/*============================================roter_l======================================*/
struct tree* roter_l(struct tree*az)
{
    if (az==nil)
    {
        ret az;
    }
    struct tree*az0=az->r;
    if (az0==nil)
    {
        ret az;
    }
    struct tree*a=az0->r;
    struct tree*b=az0->l;
    struct tree*c=az ->l;
    
    az0->l=az;
    az0->r=a;
    az ->r=b;
    az ->l=c;
    
    az0->lv++;
    az ->lv--;
    ret az0;
}
/*============================================roter_l======================================*/
/*============================================bal==========================================*/
struct tree*bal(struct tree*az)
{
    if (az!=nil)
    {
        az->l=bal(az->l);
        az->r=bal(az->r);
        int i=g(az->l);
        i=(i!=-1)*i;
        int j=g(az->r);
        j=(j!=-1)*j;
        if ((i-j)>1)
        {
            az=roter_r(az);
        }
        else
        {
            if ((i-j)<-1)
            {
                az=roter_l(az);
            }
        }
    }
    ret az;
}
/*============================================bal==========================================*/
/*============================================balance======================================*/
struct tree*balance(struct tree*az)
{
    fix(az);
    az=bal(az);
    /*
    fix(az); // фиксим, чтобы вывод нашего дерева нормальненький получился
    print(az);
    //*/
    ret az;
}
/*============================================balance======================================*/