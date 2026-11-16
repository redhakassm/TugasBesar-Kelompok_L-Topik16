#include "../Header/pendaftaranBST.h"

void createTree(adrBST &root) {
    root = NULL;
}

adrBST createElementBST(InfotypeBST x) {
    adrBST P = new NodeBST;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertBST(adrBST &root, adrBST P) {
    if (root == NULL) {
        root = P;
    } else if (P->info.jumlah_peserta < root->info.jumlah_peserta) {
        insertBST(root->left, P);
    } else {
        insertBST(root->right, P);
    }
}

adrBST searchBST(adrBST root, int jumlah_peserta) {
    if (root == NULL || root->info.jumlah_peserta == jumlah_peserta) {
        return root;
    }
    if (jumlah_peserta < root->info.jumlah_peserta) {
        return searchBST(root->left, jumlah_peserta);
    }
    return searchBST(root->right, jumlah_peserta);
}

adrBST findMinBST(adrBST root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

adrBST findMaxBST(adrBST root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

void deleteBST(adrBST &root, int jumlah_peserta) {
    if (root == NULL) return;

    if (jumlah_peserta < root->info.jumlah_peserta) {
        deleteBST(root->left, jumlah_peserta);
    } else if (jumlah_peserta > root->info.jumlah_peserta) {
        deleteBST(root->right, jumlah_peserta);
    } else {
        // Node dengan 0 atau 1 child
        if (root->left == NULL) {
            adrBST temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == NULL) {
            adrBST temp = root->left;
            delete root;
            root = temp;
        } else {
            // Node dengan 2 child (cari minimum di right subtree)
            adrBST temp = findMinBST(root->right);
            root->info = temp->info;
            deleteBST(root->right, temp->info.jumlah_peserta);
        }
    }
}

void inOrder(adrBST root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << "  - [" << root->info.jumlah_peserta << " orang] Peserta: " << root->info.nama_peserta
             << " | Paket: " << root->info.id_paket
             << " | Total: Rp " << root->info.total_biaya
             << " | Status: " << root->info.status_pembayaran << endl;
        inOrder(root->right);
    }
}

void preOrder(adrBST root) {
    if (root != NULL) {
        cout << "  - [" << root->info.jumlah_peserta << " orang] Peserta: " << root->info.nama_peserta
             << " | Paket: " << root->info.id_paket << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(adrBST root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "  - [" << root->info.jumlah_peserta << " orang] Peserta: " << root->info.nama_peserta
             << " | Paket: " << root->info.id_paket << endl;
    }
}

int countNodes(adrBST root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int getTreeHeight(adrBST root) {
    if (root == NULL) return 0;
    return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
}
