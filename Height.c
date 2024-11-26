int Height(TTree T) {
    // Nếu cây rỗng, chiều cao là 0
    if (T == NULL) {
        return 0;
    }

    // Tính chiều cao của cây con trái và cây con phải
    int leftHeight = Height(T->left);
    int rightHeight = Height(T->right);

    // Chiều cao của cây là 1 + chiều cao của cây con cao nhất
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}