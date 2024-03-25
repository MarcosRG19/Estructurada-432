//MARCOS RUIZ GONZALEZ
//20/03/24
//
//RGM_A08_PE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define C 4
void Menu(void);
int Msge(void);
void Llenar_vect(int vect1[], int m, int ri, int rf);
void Llenar_vect_alea(int vect2[], int m, int ri, int rf);
void Llenar_vect3(int vect1[],int vect2[],int vect3[],int m);
void Imp_vect(int vect1[],int vect2[],int vect3[],int m);
void Llena_mat(int vect1[],int vect2[],int mat[][C] ,int m,int n);
void Imp_mat(int mat[][C], int m, int n);
int Busqueda(int vect2[],int dato,int m);

int main()
{
    Menu();
}
void Menu(void)
{
    int op, vect1[N], vect2[N],vect3[N];
    int mat[4][4];
    op=1;
    while (op!=0)
    {
        op=Msge();
        switch (op)
        {
        case 1:
            Llenar_vect(vect1,N,30,70);
            break;
        case 2:
            Llenar_vect_alea(vect2,N,1,20);
            break;
        case 3:
            Llenar_vect3(vect1,vect2,vect3,N);
            break;
        case 4:
            Imp_vect(vect1,vect2,vect3,N);
            break;
        case 5:
            Llena_mat(vect1,vect2,mat,4,C);
            break;
        case 6:
            Imp_mat(mat,4,C);
            break;
        case 0:
            break;
        default:
            printf("INTRODUJO UN VALOR INVALIDO");
            break;
        }
    }
}
int Msge(void)
{
    int opc;
    printf("MENU\n");
    printf("1.- LLENAR VECTOR 1 MANUALMENTE\n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE\n");
    printf("3.- LLENAR VECTOR 3\n");
    printf("4.- IMPRIMIR VECTORES\n");
    printf("5.- LLENA MATRIZ 4X4\n");
    printf("6.- IMPRIMIR MATRIZ\n");
    printf("0.- SALIR\n");
    scanf("%d",&opc);
    return opc;
}
void Llenar_vect(int vect1[],int m, int ri, int rf)
{
    int i,rango;
    rango=(rf-ri)+1;
    for(i=0;i<m;i++)
    {
        do
        {
            scanf("%d",&vect1[i]);    
        } while (vect1[i]<ri or vect1[i]>rf);
    }
}
void Llenar_vect_alea(int vect2[], int m, int ri, int rf)
{
    int i, rango,num;
    i=0;
    rango=((rf-ri)+1);
    srand(time(NULL));
    while (i<m)
    {
        num=(rand()%rango)+ri;
        if(Busqueda(vect2,num,m) ==0)
        {
            vect2[i]=num;
        }
        else
        {
            continue;
        }
        i++;
    }
    
}
void Llenar_vect3(int vect1[],int vect2[],int vect3[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        vect3[i]=vect1[i]+vect2[i];
    }
}
void Imp_vect(int vect1[],int vect2[],int vect3[],int m)
{
    int i;
    printf("VECTOR 1\n");
    for (i=0;i<m;i++)
    {
        printf("%d --> [%d]\n",i,vect1[i]);
    }
    printf("VECTOR 2\n");
    for(i=0;i<m;i++)
    {
        printf("%d --> [%d]\n",i,vect2[i]);
    }
    printf("VECTOR 3\n");
    for (i=0;i<m;i++)
    {
        printf("%d --> [%d]\n",i,vect3[i]);
    }
}
int Busqueda(int vect2[],int dato,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(vect2[i]==dato)
        {
            return 1;
            break;
        }
    }
    return 0;
}
void Llena_mat(int vect1[],int vect2[],int mat[][C] ,int m,int n)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            mat[i][j]=vect1[i];
        }
    }
}
void Imp_mat(int mat[][C], int m, int n)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("[%d]",mat[i][j]);
        }
        printf("\n");
    }
}