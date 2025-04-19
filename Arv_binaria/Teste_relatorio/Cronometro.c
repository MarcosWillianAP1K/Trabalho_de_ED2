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

char *converter_para_string(clock_t tempo, char *buffer, size_t tamanho_buffer)
{
    buffer[0] = '\0';
    double segundos = converter_para_segundos(tempo);
    snprintf(buffer, tamanho_buffer, "%.10f segundos", segundos);
    
    return buffer;
}