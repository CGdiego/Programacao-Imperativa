#include <stdio.h>

#define NUMERO_DE_SENSORES 4
typedef enum {JANELA, VENTILADOR, ILUMINACAO, PORTA} Sensor;
char* nome_do_sensor[] = {"JANELA", "VENTILADOR", "ILUMINACAO", "PORTA"};

int compor_mensagem(){
    int mensagem = 0, estado, i;

    for (i = 0; i < NUMERO_DE_SENSORES; i++){
        printf("Estado do sensor %s (0 ou 1): ", nome_do_sensor[i]);
        scanf("%d", &estado);

        if (estado)
            mensagem |= (1 << i);
    }

    return mensagem;
}

void exibir_mensagem(int estados){
    int bit, i;

    for (i = 0; i < NUMERO_DE_SENSORES; i++){
        bit = (estados >> i) & 1;

        switch (i){
            case JANELA:
            case PORTA:
                if (bit)
                    printf("%s: Aberta\n", nome_do_sensor[i]);
                else
                    printf("%s: Fechada\n", nome_do_sensor[i]);
                break;

            case VENTILADOR:
                if (bit)
                    printf("%s: Ligado\n", nome_do_sensor[i]);
                else
                    printf("%s: Desligado\n", nome_do_sensor[i]);
                break;

            case ILUMINACAO:
                if (bit)
                    printf("%s: Ligada\n", nome_do_sensor[i]);
                else
                    printf("%s: Desligada\n", nome_do_sensor[i]);
                break;

            default:
                printf("ERRO: Item não encontrado");
                break;
        }
    }
}

int main(){
    int mensagem = compor_mensagem();
    exibir_mensagem(mensagem);

    return 0;
}