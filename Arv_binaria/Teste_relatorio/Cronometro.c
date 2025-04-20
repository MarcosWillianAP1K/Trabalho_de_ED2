#include "Cronometro.h"

clock_t cronometro_iniciar()
{
    return clock();
}

clock_t cronometro_finalizar(clock_t inicio)
{
    clock_t fim = clock();
    
    return fim - inicio;
}


double converter_para_segundos(clock_t tempo)
{
    return ((double)tempo) / CLOCKS_PER_SEC;
}

double converter_para_milisegundos(clock_t tempo)
{
    return ((double)tempo) / (CLOCKS_PER_SEC / 1000.0);
}

char *converter_para_string(clock_t tempo, char *buffer, size_t tamanho_buffer, double (*converter)(clock_t))
{
    if (buffer == NULL || tamanho_buffer == 0)
    {
        return NULL;
    }
    
    if (converter == NULL)
    {
        return NULL;
    }
    
    buffer[0] = '\0';
    double segundos = converter(tempo);
    snprintf(buffer, tamanho_buffer, "%.10f", segundos);
    
    return buffer;
}
