void liberar(Planeta* p) {
    Planeta* proximo;

    while (p != NULL) {
        proximo = p->proximo;
        free(p);
        p = proximo;
    }
}