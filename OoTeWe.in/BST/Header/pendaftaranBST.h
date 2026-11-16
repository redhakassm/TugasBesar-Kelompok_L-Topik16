#ifndef PENDAFTARANBST_H_INCLUDED
#define PENDAFTARANBST_H_INCLUDED

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct InfotypeBST {
    int jumlah_peserta; // Key BST
    string nama_peserta;
    string id_penyelenggara;
    string id_destinasi;
    string id_paket;
    double total_biaya;
    string status_pembayaran;
};

typedef struct NodeBST* adrBST;

struct NodeBST {
    InfotypeBST info;
    adrBST left;
    adrBST right;
};

void createTree(adrBST &root);
adrBST createElementBST(InfotypeBST x);
void insertBST(adrBST &root, adrBST P);
adrBST searchBST(adrBST root, int jumlah_peserta);
adrBST findMinBST(adrBST root);
adrBST findMaxBST(adrBST root);
void deleteBST(adrBST &root, int jumlah_peserta);
void inOrder(adrBST root);
void preOrder(adrBST root);
void postOrder(adrBST root);
int countNodes(adrBST root);
int getTreeHeight(adrBST root);

#endif // PENDAFTARANBST_H_INCLUDED
