#include <iostream>
#include <cstddef>
using namespace std;

// Program Binary Tree
// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    return root == NULL;
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (!node) {
        cout << "\nNode parent tidak ditemukan!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    } else {
        baru = new Pohon();
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        baru->parent = node;
        node->left = baru;
        cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
        return baru;
    }
}

// Tambah Kanan
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (!node) {
        cout << "\nNode parent tidak ditemukan!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    } else {
        baru = new Pohon();
        baru->data = data;
        baru->left = NULL;
        baru->right = NULL;
        baru->parent = node;
        node->right = baru;
        cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
        return baru;
    }
}

// Ubah Data Tree
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ditemukan!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent) {
                cout << "Parent: (tidak punya parent)" << endl;
            } else {
                cout << "Parent: " << node->parent->data << endl;
            }
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) {
                cout << "Sibling: " << node->parent->left->data << endl;
            } else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) {
                cout << "Sibling: " << node->parent->right->data << endl;
            } else {
                cout << "Sibling: (tidak punya sibling)" << endl;
            }
            if (!node->left) {
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            } else {
                cout << "Child Kiri: " << node->left->data << endl;
            }
            if (!node->right) {
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            } else {
                cout << "Child Kanan: " << node->right->data << endl;
            }
        }
    }
}

// Tampilkan Child dari Node
void showChild(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "Child Kiri: " << (node->left ? node->left->data : ' ') << endl;
            cout << "Child Kanan: " << (node->right ? node->right->data : ' ') << endl;
        }
    }
}

// Tampilkan Descendants dari Node
void showDescendants(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            if (node->left) {
                cout << node->left->data << " ";
                showDescendants(node->left);
            }
            if (node->right) {
                cout << node->right->data << " ";
                showDescendants(node->right);
            }
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon* node) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon* node = root) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return (size(node->left) + size(node->right) + 1);
        }
    }
}

// Cek Height Tree
int height(Pohon* node = root) {
    if (!root) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (node == NULL) {
            return -1;
        } else {
            int kiri, kanan;
            kiri = height(node->left);
            kanan = height(node->right);
            return max(kiri, kanan) + 1;
        }
    }
}

// Cek rata-rata Node Tree
int average() {
    return size() / height();
}

int main() {
    init();
    int pil;
    do {
        cout << "\nMenu:";
        cout << "\n1. Buat Node Root";
        cout << "\n2. Tambah Node Kiri";
        cout << "\n3. Tambah Node Kanan";
        cout << "\n4. Ubah Data Node";
        cout << "\n5. Lihat Isi Data Node";
        cout << "\n6. Cari Data Node";
        cout << "\n7. Tampilkan Child dari Node";
        cout << "\n8. Tampilkan Descendants dari Node";
        cout << "\n9. PreOrder Traversal";
        cout << "\n10. InOrder Traversal";
        cout << "\n11. PostOrder Traversal";
        cout << "\n12. Hapus SubTree";
        cout << "\n13. Hapus Tree";
        cout << "\n14. Karakteristik Tree";
        cout << "\n0. Keluar";
        cout << "\nPilih menu: ";
        cin >> pil;
        
        switch (pil) {
            case 1:
                char data;
                cout << "\nMasukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                char dataKiri, parentKiri;
                cout << "\nMasukkan data untuk node kiri: ";
                cin >> dataKiri;
                cout << "Masukkan data parent: ";
                cin >> parentKiri;
                insertLeft(dataKiri, root);  // Asumsi parent adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 3:
                char dataKanan, parentKanan;
                cout << "\nMasukkan data untuk node kanan: ";
                cin >> dataKanan;
                cout << "Masukkan data parent: ";
                cin >> parentKanan;
                insertRight(dataKanan, root);  // Asumsi parent adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 4:
                char dataBaru, nodeUbah;
                cout << "\nMasukkan data baru: ";
                cin >> dataBaru;
                cout << "Masukkan data node yang ingin diubah: ";
                cin >> nodeUbah;
                update(dataBaru, root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 5:
                char nodeLihat;
                cout << "\nMasukkan data node yang ingin dilihat: ";
                cin >> nodeLihat;
                retrieve(root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 6:
                char nodeCari;
                cout << "\nMasukkan data node yang ingin dicari: ";
                cin >> nodeCari;
                find(root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 7:
                char nodeChild;
                cout << "\nMasukkan data node yang ingin dilihat child-nya: ";
                cin >> nodeChild;
                showChild(root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 8:
                char nodeDescendant;
                cout << "\nMasukkan data node yang ingin dilihat descendant-nya: ";
                cin >> nodeDescendant;
                showDescendants(root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 9:
                cout << "\nPreOrder Traversal:" << endl;
                preOrder(root);
                break;
            case 10:
                cout << "\nInOrder Traversal:" << endl;
                inOrder(root);
                break;
            case 11:
                cout << "\nPostOrder Traversal:" << endl;
                postOrder(root);
                break;
            case 12:
                char nodeSub;
                cout << "\nMasukkan data node yang ingin dihapus subtree-nya: ";
                cin >> nodeSub;
                deleteSub(root);  // Asumsi node adalah root. Perlu disesuaikan sesuai kebutuhan.
                break;
            case 13:
                clear();
                break;
            case 14:
                cout << "\nSize Tree: " << size() << endl;
                cout << "Height Tree: " << height() << endl;
                cout << "Average Node of Tree: " << average() << endl;
                break;
            case 0:
                cout << "\nKeluar dari program." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }
    } while (pil != 0);

    return 0;
}