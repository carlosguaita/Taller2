#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char Id[5][10];
    char nombre[5][30], aux[10];
    int stock[5];
    float precio[5];
    float total_ganacia;
    float venta;
    int opc1, opc2, cont=0, len=0;


    do{
        printf("1. Registrar producto\n");
        printf("2. Ver productos\n");
        printf("3. Vender Producto\n");
        printf("4. Reabastecer producto\n");
        printf("5. Ver ganancias totales\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opc1);
        switch (opc1)
        {
        case 1:
            printf("Ingrese el ID del producto %d: ",cont);
            fflush(stdin);
            scanf("%s",&Id[cont]);
            printf("Ingrese el nombre del producto %d: \n",cont);
            fflush(stdin);
            fgets(nombre[cont],30,stdin);
            
            len = strlen(nombre[cont]) - 1;
            nombre[cont][len]='\0';

            printf("Ingrese el stock del producto %d\n",cont);
            scanf("%d",&stock[cont]);
            printf("Ingrese el precio del producto %d\n",cont);
            scanf("%f",&precio[cont]);
            cont++;
            break;
        case 2:
            printf("ID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i=0; i<cont; i++){
                printf("%s\t\t%s\t\t%d\t\t%.2f\n",Id[i],nombre[i],stock[i],precio[i]);
            }
            break;
        case 3:
            int cantidad = 0;
            printf("Ingrese el Id del producto a vender: ");
            scanf("%s",&aux);
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(Id[i],aux)==0)
                {
                    printf("Producto encontrado\n");
                    printf("Ingrese el numero de elementos a vender: ");
                    scanf("%d",&cantidad);
                    venta = cantidad * precio[i];
                    printf("La venta es: %f\n",venta);
                    stock[i]-=cantidad;
                    total_ganacia+=venta; 
                }
                
            }
            
            
            break;
        default:
            break;
        }
    }while(opc1 != 6);

    return 0;
}