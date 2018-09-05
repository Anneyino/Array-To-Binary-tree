#include<iostream>
using namespace std;

typedef struct BTnode {
	int data;
	BTnode* Lchild;
	BTnode* Rchild;
};

BTnode* BTtransform(int A[],int n) {
	BTnode* btArray = new BTnode[n];
	BTnode** btArrayP = new BTnode*[n];
	for (int k = 0; k < n; k++) {
		btArrayP[k] = &btArray[k];
		btArrayP[k]->data = A[k];
		btArrayP[k]->Lchild = nullptr;
		btArrayP[k]->Rchild = nullptr;
	}
		for (int i = 0; i < n; i++) {
			if (2 * i + 1 < n) {
				btArrayP[i]->Lchild = btArrayP[2 * i + 1];
			}
			if (2 * i + 2 < n) {
				btArrayP[i]->Rchild = btArrayP[2 * i + 2];
			}
		}

	
	return btArrayP[0];
}

int main() {
	int A[7] = { 0,1,2,3,4,5,6 };
	int value = BTtransform(A, 7)->Rchild->data;
	cout << "Test an array like {0,1,2,3,4,5,6},the root node's right child is: ";
	cout << value << endl;
	system("pause");
}