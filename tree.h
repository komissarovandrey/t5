#include <stdlib.h>
#include <string.h>

#define ret return
#define nil NULL
struct tree
{
    struct tree*l,*r;   // ясно-понятно
    int lv;             // уровень узла
    char*st;            // ключ
};
/*============================================find=========================================*/
int find(struct tree*az,char*st) // ищет st в az. вернет 1, если найдет
{
    if (az==nil)
    {
        ret 0;
    }
    if (az->st==nil)
    {
        ret 0;
    }
    int i=0;
    while (1)
    {
        if ((i=strcmp(st,az->st))>0)
        {
            if (az->r!=nil)
            {
                az=az->r;
            }
            else
            {
                ret 0;
            }
        }
        else
        {
            if (i<0)
            {
                if (az->l!=nil)
                {
                    az=az->l;
                }
                else
                {
                    ret 0;
                }
            }
            else
            {
                ret 1;
            }
        }
    }
    ret 0;
}
/*============================================find=========================================*/
/*============================================add==========================================*/
int add (struct tree*az,char*st)
{
    if (az==nil)
    {
        ret 1;
    }
    if (az->st==nil)
    {
        az->st=st;
        az->lv=0;
        ret 0;
    }
    else
    {
        int i=0;
        while (1)
        {
            if ((i=strcmp(st,az->st))>0)
            {
                if (az->r!=nil)
                {
                    az->lv=0;
                    az=az->r;
                }
                else
                {
                    az->r=(struct tree*)malloc(sizeof(struct tree));
                    az=az->r;
                    az->r=az->l=nil;
                    az->st=st;
                    az->lv=0;
                    ret 0;
                }
            }
            else
            {
                if (i<0)
                {
                    if (az->l!=nil)
                    {
                        az->lv=0;
                        az=az->l;
                    }
                    else
                    {
                        az->l=(struct tree*)malloc(sizeof(struct tree));
                        az=az->l;
                        az->r=az->l=nil;
                        az->st=st;
                        az->lv=0;
                        ret 0;
                    }
                }
                else
                {
                    ret 1;
                }
            }
        }
    }
    ret 0;
}
/*============================================add==========================================*/
/*============================================del==========================================*/
int del (struct tree*az)
{
    if (az==nil)
    {
        ret 0;
    }
    del(az->r);
    del(az->l);
    if (az->st!=nil)
    {
        free(az->st);
    }
    free(az);
    ret 0;
}
/*============================================del==========================================*/