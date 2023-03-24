#include <stdio.h>
#include <stdlib.h>

int checkOuterSquare(int v, int *point, int nd, int ndl, int gameArr[], int *s1)
{
    int found=0;
    for(int point1=2*nd+1; point1<=(int)pow(ndl,2)-2*nd; point1+=2)
    {
        if((point1-2)%(ndl)==0 && gameArr[point1-1]==v && gameArr[point1-2]>20)
        {
            *point=point1-2; *s1=point1-1; found=1;  return found; break;
        }else if((point1)%(ndl)==(2*nd-2) && gameArr[point1-1]==v && gameArr[point1]>20)
        {
            *point=point1; *s1=point1-1; found=1;  return found; break;
        }else if((point1-1)/(ndl)==1 && gameArr[point1-1]==v && gameArr[point1-2*nd]>20)
        {
            *point=point1-2*nd; *s1=point1-1; found=1;  return found; break;
        }else if((point1-1)/(ndl)==2*nd-3 && gameArr[point1-1]==v && gameArr[point1+2*nd-2]>20)
        {
            *point=point1+2*nd-2; *s1=point1-1; found=1;  return found; break;
        }
        if((point1+1)%(ndl)==0)
            point1+=2*nd;
    }
    return found;
}

int checkSquares(int v1, int v2, int *point, int nd, int ndl, int gameArr[], int *s1, int *s2)
{
    int found=0;
    for(int point1=2*nd; point1<=(int)pow(ndl,2); point1+=2)
    {
        if((point1+2)%(ndl)!=0)
        {
            if(gameArr[point1+ndl]>20&&((gameArr[point1]==v1 && gameArr[point1+4*nd-2]==v2) || (gameArr[point1]==v2 && gameArr[point1+4*nd-2]==v1)))
            {
                *point=point1+ndl; *s1=point1; *s2=point1+4*nd-2; found=1;  return found; break;
            }
            else if(gameArr[point1+1]>20&&((gameArr[point1]==v1 && gameArr[point1+2]==v2) || (gameArr[point1]==v2 && gameArr[point1+2]==v1)))
            {
                *point=point1+1; *s1=point1; *s2=point1+2; found=1;  return found; break;
            }
        }
        else
        {
            if(gameArr[point1+ndl]>20&&((gameArr[point1]==v1 && gameArr[point1+4*nd-2]==v2) || (gameArr[point1]==v2 && gameArr[point1+4*nd-2]==v1)))
            {
                *point=point1+ndl; *s1=point1; *s2=point1+4*nd-2; found=1;  return found; break;
            }
        }
    }
    return found;
}

void computerGuide(int *computerScore, int nd, int ndl, int *input, int gameArr[], int *flag, int *s1, int *s2)
{
    sleep(1);
    int point; int index1=0; int index2=0;
    if(checkSquares(3,3,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkSquares(3,2,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkOuterSquare(3,&point,nd,ndl,gameArr,&index1));
    else if(checkSquares(3,1,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkSquares(3,0,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkSquares(1,1,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkOuterSquare(1,&point,nd,ndl,gameArr,&index1));
    else if(checkSquares(0,1,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkSquares(0,0,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkOuterSquare(0,&point,nd,ndl,gameArr,&index1));
    else if(checkSquares(0,2,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkSquares(1,2,&point,nd,ndl,gameArr,&index1,&index2));
    else if(checkOuterSquare(2,&point,nd,ndl,gameArr,&index1));
    else if(checkSquares(2,2,&point,nd,ndl,gameArr,&index1,&index2));
    *input=(point+1)/2; *s1=index1; *s2=index2;
    gameArr[point]=12; gameArr[index1]++;
    if(index2)
        gameArr[index2]++;
    if(gameArr[index1]==4)
    {
        ++*flag; ++*computerScore;
    }
    if(gameArr[index2]==4){++*flag; ++*computerScore;}
}
