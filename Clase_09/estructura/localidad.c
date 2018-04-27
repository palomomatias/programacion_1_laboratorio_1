#include "localidad.h"
/*void loc_MostrarUno(eLocalidad aux)
{

}
*/
void loc_MostrarListado(eLocalidad listado [],int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {

    if (eLocalidad[i].id!=0)
    {
 printf("\n%s",listado[i].nombreLocalidad);
    }
    }
    }

void loc_Alta(eLocalidad listado [],int largo)
 {
    int i;
    for(i=0;i<largo;i++)
    {
        printf("ingrese su nuevo id\n");
        scanf("%d",listado[i].id);
        printf("ingrese su localidad\n");
        gets(listado[i].nombreLocalidad);
    }
 }
void loc_Baja(eLocalidad listado [],int largo,int idParaBorrar)
{
    int i;
    for(i=0;i<largo;i++)
    {
        printf("ingrese el id que quiere mostrar")
        scanf("%d",idParaBorrar);
        if(listado[i].id==idParaBorrar)
        {
            listado[i].id=0;
            printf("se a dado de baja");
        }
    }
}
void loc_Modificacion(eLocalidad listado [],int largo,int idParamodificar)
{
    int i;
    int opcion;
    loc_MostrarListado;
    printf("ingrese el id que quiere modificar");
    scanf("%d",idParamodificar);// falta validar esto
    for(i=0;i<largo;i++)
    {
    if(listado[i].id==idParamodificar)
    {
        printf("que desea modificar 1 estado 2 localidad");
        scanf("%d",opcion);
        switch(opcion)
        {
        case 1:
            printf("ingrese su nuevo estado")
            gets(listado[i].estado);
            break;
        case 2:
            printf("ingrese su nueva localidad");
            gets(listado[i].nombreLocalidad);
            break;
        }

    }

    }
}
void loc_ordenarDescPorNombre(eLocalidad listado [],int largo)
{
    int i;
    int j;
    char auxLocalidad[30];
     for(i=0;i<largo;i--)
     {

         for(i=0;i>largo;i--)
         {

             if(strcmp(listado[i].nombreLocalidad,listado[j].nombreLocalidad)>0)
             strcpy(auxLocalidad,listado[i].nombreLocalidad);
             strcpy(listado[i].nombreLocalidad,listado[j].nombreLocalidad);
             strcpy(listado[j].nombreLocalidad,auxLocalidad);

            strcpy(auxLocalidad,listado[i]);
             strcpy(listado[i],listado[j]);
             strcpy(listado[j],auxLocalidad);


         }

     }

}
void loc_ordenarDescPorID(eLocalidad listado [],int largo)
{
    int i;
    int j;
    int auxId;
     for(i=0;i<largo;i--)
     {

         for(i=0;i>largo;i--)
         {

             if(listado[i].id>listado[j].id)

           {

                auxId=listado[i];
                listado[i]=listado[j];
                listado[j]=auxId;
             }
         }

     }

}
