#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
 
#define ret return
#define nil NULL

#include "tree.h"
#include "load.h"
#include "bal.h"

#define EXIT_CODE "exit"
#define YES "YES\n"
#define NO "NO\n"

/**
 что это такое и как оно работает (в общем):
 задача: получить имя файла и проверить, есть ли в нем строки, которые даются нам на stdin.
 как это решается:
 открываем файл на чтение и запрашиваем у юзера первую строку. 
 достаем из файла строки до тех пор, пока не найдем такую же, либо файл не кончится. 
 попутно сохраняем в дереве. 
 как только однозначно можем сказать, есть ли такая строка в файле, говорим юзеру об этом и балансируем дерево.
 затем просим новую строку и проделываем все тоже самое, разве что сначала проверяем, есть ли уже такая строка в нашем дереве.
 в один прекрасный момент весь файл будет загружен в АВЛ-дерево, и поиск будет проходить куда быстрее, чем в массиве или каждый раз проверять весь файл от начала до конца без загрузки в оп.
 
 алгоритм балансировки дерева:
 если левое и правое поддеревья имеют разность высот по модулю больше единицы, то в этом узле меняем пару элементов так, что разность сокращается на единицу.
 обойдя так все узлы получим сбалансированное дерево.
 
 */

/*============================================run==========================================*/
int run(int fe)
{
    int i=0;
    struct tree*az=(struct tree*)malloc(sizeof(struct tree));
    az->lv=0;
    az->st=nil;
    az->l=az->r=nil;
    char*st=nil,*st0=nil; // st - строка из файла, st0 - строка юзера
    while (strcmp(st0=readstr(0),EXIT_CODE)!=0)
    {
        i=find(az,st0); // ищет st0 в az. вернет 1, если найдет
        if (i==0)
        {
        	while (i==0) // выйдет либо при i==1 (нашли), либо при i==-1 (файл закончился)
        	{
           		st=readstr(fe);
           		if (st==nil)
            	{
            	    i=-1;
            	}
            	else
            	{
            	    add(az,st); // запихивает в память новую строку
            	    i=strcmp(st,st0)==0;
            	}
            }
            // тут хорошо было бы слегка побалансировать деревце, чтобы удобнее было в нем искать
	        az=balance(az);
        }
        if (i>0)
        {
            printf(YES);
        }
        else
        {
            printf(NO);
        }
        free(st0);
        
    }
    del(az);// возращает память
    ret 0;
}
/*============================================run==========================================*/
/*============================================main=========================================*/
int main(int c,char**stt)
{
    if (c==1)
    {
        ret 1;
    }
    
    int fe=open(stt[1],O_RDONLY);
    if (fe<1)
    {
        ret 1;
    }
    
    run(fe);
    
    close(fe);
    ret 0;
}
/*============================================main=========================================*/