#include <stdio.h>

int main() {
    int n, m;
    long long int totalAlunos = 0;

    scanf("%d %d", &n, &m);

    int turmaMax[1005] = {0};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int valor;
            scanf("%d", &valor);

            if (valor > turmaMax[j])
                turmaMax[j] = valor;
        }
    }

    for (int j = 0; j < m; j++){
        if (turmaMax[j] < 1)
            turmaMax[j] = 1;
        
        totalAlunos += turmaMax[j];
    }

    printf("%lld\n", totalAlunos);

    return 0;
}