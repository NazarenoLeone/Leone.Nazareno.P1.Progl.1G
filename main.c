#include <stdio.h>
#include <stdlib.h>
#define TAM 25

typedef struct
{
    int id;
    char procesador[TAM];
    char marca[TAM];
    float precio;
} Notebook;

int sacarPorcentaje(float x, float y);
int contarCaracteres();
int ordenar(Notebook vec[], int tam);

int main()
{
    float numeroIngresado;
    float porcentaje;
    Notebook lista[TAM];
    sacarPorcentaje(numeroIngresado, porcentaje);
    contarCaracteres();
    ordenar(lista,TAM);


    return 0;
}

int ordenar(Notebook vec[], int tam)
{
    int todoOk = 0;
    Notebook auxNotebook;

    Notebook notebooks[TAM] =
    {
        {1000, "Ryzen 5", "AMD", 500000},
        {1001, "Ryzen 3", "AMD", 570000},
        {1002, "Ryzen 5", "Philips", 780000},
        {1003, "Ryzen 3", "AMD", 715000},
        {1004, "Ryzen 9", "Philips", 150000},
        {1005, "Ryzen 5", "Samsung", 650000},
        {1006, "Ryzen 5", "Samsung", 459000},
        {1007, "Ryzen 5", "Samsung", 440000},
        {1008, "Ryzen 7", "HDC", 487000},
        {1009, "Ryzen 7", "HDC", 590000}
    };

    if( vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if(strcmp(vec[i].marca, vec[j].marca) > 0 )
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                    if(strcmp(vec[i].marca, vec[j].marca) > 0 )
                    {
                        auxNotebook = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxNotebook;
                        printf("%d %s %s %f ", vec[i].id, vec[i].marca, vec[i].procesador, vec[i].precio);
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int contarCaracteres()
{
    char CadCar[TAM] = "Buenas Noches";
    char car = 'e';
    int acum = 0;
    int todoOk = 0 ;

    for(int i = 0; i < TAM; i++)
    {
        if(CadCar[i] == 'e')
        {
            acum++;
            todoOk = 1;
        }
    }
    printf("%d\n\n", acum++);
    return todoOk;
}

int sacarPorcentaje(float x, float y)
{
    int  todoOk =1;
    float porcentaje;
    float descuento;

    printf("Ingrese un numero: ");
    scanf("%f", &x);

    porcentaje=(x * 5)/100;
    descuento= x - porcentaje;
    printf("%.2f\n\n", descuento);

    return porcentaje;
}
