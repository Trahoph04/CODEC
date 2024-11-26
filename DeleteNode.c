TTree FindMin(TTree T) {
    while (T->left != NULL) {
        T = T->left;
    }
    return T;
}

TTree DeleteNode(TTree root, TData key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->Data) {
        root->left = DeleteNode(root->left, key);
    } else if (key > root->Data) {
        root->right = DeleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            TTree temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TTree temp = root->left;
            free(root);
            return temp;
        }

        TTree temp = FindMin(root->right);
        root->Data = temp->Data;
        root->right = DeleteNode(root->right, temp->Data);
    }
    return root;
}