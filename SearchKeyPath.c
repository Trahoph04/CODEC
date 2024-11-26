int SearchKeyAndPath(TTree T, int key, char* path) {

    if (T == NULL) {
        return 0;
    }
    
    if (T->data == key) {
        printf("Found key %d at path: %s\n", key, path);
        return 1;
    }

    int len = strlen(path);
    path[len] = 'L'; 
    path[len + 1] = '\0'; 
    if (SearchKeyAndPath(T->left, key, path)) {
        return 1;
    }
    path[len] = '\0'; 


    path[len] = 'R'; 
    path[len + 1] = '\0'; 
    if (SearchKeyAndPath(T->right, key, path)) {
        return 1;
    }
    path[len] = '\0'; 

    return 0;
}