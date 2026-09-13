#include <stdio.h>

// MESES DO ANO
typedef enum Mes {
    JANEIRO,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

// DIAS DA SEMANA
typedef enum Dia {
    SEGUNDA, // segunda-feira
    TERCA,   // terça-feira
    QUARTA,  // quarta-feira
    QUINTA,  // quinta-feira
    SEXTA,   // sexta-feira
    SABADO,  // sábado
    DOMINGO  // domingo
} Dia;

const char * const meses[] = { 
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" 
};

const char * const dias_da_semana[] = { 
    "Segunda-feira", "Terça-feira", "Quarta-feira",
    "Quinta-feira", "Sexta-feira", "Sábado", "Domingo" 
};

Mes selecionar_mes();
Dia selecionar_dia();
void decidir_rotina(Mes mes, Dia dia);

int main() 
{
    // SELEÇÃO DO MÊS DO ANO:
    Mes mes_selecionado = selecionar_mes();

    // SELEÇÃO DO DIA DA SEMANA:
    Dia dia_selecionado = selecionar_dia();

    // TOMADA DE DECISÃO:
    decidir_rotina(mes_selecionado, dia_selecionado);

    return 0;
}

Mes selecionar_mes() 
{
    puts("Meses do ano: ");
    
    for (int m = JANEIRO; m <= DEZEMBRO; m++) 
    {
        printf("\t(%2d) %s\n", m, meses[m]);
    }

    int input;
    puts("Selecione um mês pelo seu número: ");
    scanf("%d", &input);

    if (input < JANEIRO || input > DEZEMBRO) 
    {
        puts("Entrada inválida! Assumindo Janeiro por padrão.");
        input = JANEIRO;
    }

    printf("Mês selecionado: %s\n", meses[input]);
    return (Mes)input;
}

Dia selecionar_dia() 
{
    putchar('\n');
    puts("Dias da semana: ");

    for (int d = SEGUNDA; d <= DOMINGO; d++) 
    {
        printf("\t(%2d) %s\n", d, dias_da_semana[d]);
    }

    int input;
    puts("Selecione um dia pelo seu número: ");
    scanf("%d", &input);

    if (input < SEGUNDA || input > DOMINGO) 
    {
        puts("Entrada inválida! Assumindo Segunda-feira por padrão.");
        input = SEGUNDA;
    }

    printf("Dia selecionado: %s\n", dias_da_semana[input]);
    return (Dia)input;
}

void decidir_rotina(Mes mes, Dia dia) 
{
    putchar('\n');

    if (mes == JANEIRO || dia == DOMINGO) 
    {
        puts("Descansar!\n");
    } 
    else 
    {
        puts("Trabalhar!\n");
    }
}