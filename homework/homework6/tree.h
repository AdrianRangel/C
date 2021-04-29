typedef struct nodo{
        char* username;
        struct nodo *sig;

}
user;

user* userlist(user *list){
    list = NULL;
    return list;

}

user *addUser(user *list, char *username){
    user *newUser, *aux;
    newUser = (user*)malloc(sizeof(user));
    newUser->username = username;
    newUser->sig = NULL;
    if(list == NULL){
        list = newUser;
        }else{
            aux = list;
            while(aux->sig !=NULL){
                aux = aux->sig;

            }
            aux->sig = newUser;
        }
        return list;
}
