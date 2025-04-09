

#ifndef SEGURANCA_H
#define SEGURANCA_H


void limpar_buffer();

void limpar_tela();

void pausar_tela();

void mensagem_erro(char *mensagem);

void mensagem_sucesso(char *mensagem);

void verificar_alocacao(void *ponteiro);

void verificar_realocacao(void *ponteiro);

char *digitar_string();

short int digitar_short_int();

char digitar_um_caracter();

#endif