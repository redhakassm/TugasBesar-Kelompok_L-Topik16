#include "pendaftaranBST.h"

void createTree(adrBST &root) {
    root = NULL;
}

adrBST createElementBST(InfotypeBST x) {
    adrBST newNode = new NodeBST;
    if (newNode != NULL) {
        newNode->info = x;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void insertBST(adrBST &root, adrBST P) {
    if (root == NULL) {
        root = P;
        return;
    }

    adrBST curr = root;
    adrBST parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (P->info.jumlah_peserta < curr->info.jumlah_peserta) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (P->info.jumlah_peserta < parent->info.jumlah_peserta) {
        parent->left = P;
    } else {
        parent->right = P;
    }
}

adrBST searchBST(adrBST root, int jumlah_peserta) {
    adrBST curr = root;
    while (curr != NULL) {
        if (jumlah_peserta == curr->info.jumlah_peserta) {
            return curr;
        }
        curr = (jumlah_peserta < curr->info.jumlah_peserta) ? curr->left : curr->right;
    }
    return NULL;
}

adrBST findMinBST(adrBST root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findMinBST(root->left);
}

adrBST findMaxBST(adrBST root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findMaxBST(root->right);
}

void deleteBST(adrBST &root, int jumlah_peserta) {
    if (root == NULL) return;

    if (jumlah_peserta < root->info.jumlah_peserta) {
        deleteBST(root->left, jumlah_peserta);
    } else if (jumlah_peserta > root->info.jumlah_peserta) {
        deleteBST(root->right, jumlah_peserta);
    } else {
        adrBST target = root;
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            delete target;
        } else if (root->left == NULL) {
            root = root->right;
            delete target;
        } else if (root->right == NULL) {
            root = root->left;
            delete target;
        } else {
            adrBST maxLeft = findMaxBST(root->left);
            root->info = maxLeft->info;
            deleteBST(root->left, maxLeft->info.jumlah_peserta);
        }
    }
}

void tampilkanData(const InfotypeBST &data) {
    cout << "[" << data.jumlah_peserta << " Peserta] "
         << data.nama_peserta << " | Penyelenggara: " << data.id_penyelenggara
         << " | Destinasi: " << data.id_destinasi << " | Paket: " << data.id_paket
         << " | Biaya: Rp" << data.total_biaya << " (" << data.status_pembayaran << ")" << endl;
}

void inOrder(adrBST root) {
    if (root == NULL) return;
    inOrder(root->left);
    tampilkanData(root->info);
    inOrder(root->right);
}

void preOrder(adrBST root) {
    if (root == NULL) return;
    tampilkanData(root->info);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(adrBST root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    tampilkanData(root->info);
}

int countNodes(adrBST root) {
    return (root == NULL) ? 0 : (countNodes(root->left) + countNodes(root->right) + 1);
}

int getTreeHeight(adrBST root) {
    if (root == NULL) return 0;
    int kiri = getTreeHeight(root->left);
    int kanan = getTreeHeight(root->right);
    return (kiri > kanan ? kiri : kanan) + 1;
}

