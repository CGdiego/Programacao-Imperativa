/* Programa para criptografar e descriptografar
o primeiro nome e o sobrenome de uma pessoa, sendo que
ambos podem ser nomes compostos */

#include <stdio.h>

const char LF = 10; // caracter de fim de linha (Line Feed)

void ler_string(char destino[], int max_letras);
void deslocar_caracteres(char destino[], const char origem[], int shift);

int main(void)
{
    const int MAX_LETRAS = 9;
    const int TAMANHO_BUFFER = MAX_LETRAS + 1;
    const int PRIMEIRO_NOME_SHIFT = 1;
    const int SOBRENOME_SHIFT = 2;
    char primeiro_nome[TAMANHO_BUFFER];
    char sobrenome[TAMANHO_BUFFER];

    // LEITURA DO PRIMEIRO NOME:
    printf("Digite o primeiro nome e tecle ENTER: ");
    ler_string(primeiro_nome, MAX_LETRAS);
    printf("Primeiro nome armazenado: %s\n", primeiro_nome);

    // LEITURA DO SOBRENOME:
    printf("Digite o sobrenome e tecle ENTER: ");
    ler_string(sobrenome, MAX_LETRAS);
    printf("Sobrenome armazenado: %s\n", sobrenome);

    // CRIPTOGRAFIA DO PRIMEIRO NOME:
    char primeiro_nome_criptografado[TAMANHO_BUFFER];
    deslocar_caracteres(primeiro_nome_criptografado, primeiro_nome, PRIMEIRO_NOME_SHIFT);
    
    // CRIPTOGRAFIA DO SOBRENOME:
    char sobrenome_criptografado[TAMANHO_BUFFER];
    deslocar_caracteres(sobrenome_criptografado, sobrenome, SOBRENOME_SHIFT);
    
    // RESULTADOS DA CRIPTOGRAFIA:
    printf("Primeiro nome criptografado: %s\n", primeiro_nome_criptografado);
    printf("Sobrenome criptografado: %s\n", sobrenome_criptografado);

    // DESCRIPTOGRAFIA DO PRIMEIRO NOME:
    char primeiro_nome_descriptografado[TAMANHO_BUFFER];
    deslocar_caracteres(primeiro_nome_descriptografado, primeiro_nome_criptografado, -PRIMEIRO_NOME_SHIFT);
    
    // DESCRIPTOGRAFIA DO SOBRENOME:
    char sobrenome_descriptografado[TAMANHO_BUFFER];
    deslocar_caracteres(sobrenome_descriptografado, sobrenome_criptografado, -SOBRENOME_SHIFT);

    // RESULTADOS DA DESCRIPTOGRAFIA:
    printf("Primeiro nome descriptografado: %s\n", primeiro_nome_descriptografado);
    printf("Sobrenome descriptografado: %s\n", sobrenome_descriptografado);

    return 0;
}

void ler_string(char destino[], int max_letras)
{
    int i = 0;
    int nao_fim_linha = 1;
    while (i < max_letras && nao_fim_linha)
    {
        char c = getchar();
        if (c == LF) // verifica se é fim de linha
        {
            nao_fim_linha = 0;
        }
        else
        {
            destino[i] = c;
            i++;
        }
    }
    destino[i] = '\0'; // termina a string
    while (nao_fim_linha) // descarta tudo até o fim da linha
    {
        char c = getchar();
        if (c == LF) // verifica se é fim de linha
        {
            nao_fim_linha = 0;
        }
    }
}

void deslocar_caracteres(char destino[], const char origem[], int shift)
{
    int i = 0;
    while (origem[i]) // enquanto não for fim da string
    {
        destino[i] = origem[i] + shift; // criptografa/descriptografa o caracter
        i++;
    } 
    destino[i] = '\0'; // termina a string
}