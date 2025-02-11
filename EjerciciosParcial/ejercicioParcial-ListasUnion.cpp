void UnionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC){
    int valor;

    while(listaA!=NULL){
        valor = eliminarPrimero(listaA);
        agregarPrimero(listaC,valor);
    }
    while(listaB!=NULL){
        valor=eliminarPrimero(listaB);
        agregarPrimero(listaC,valor);
    }
}