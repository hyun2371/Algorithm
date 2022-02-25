#include <iostream>
using namespace std;
#define MAX_SIZE 100

class BinaryNode {
public:
	int data;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) {
		data = val; left = l; right = r;
	}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	//단말 노드 여부
	bool isLeaf() { return left == NULL && right == NULL; }
};

class CircularQueue {
	int front;
	int rear;
	BinaryNode* data[MAX_SIZE];
public:
	CircularQueue() { front = rear = 0; }

	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return front == (rear + 1) % MAX_SIZE;
	}

	void enqueue(BinaryNode* item) {
		if (isFull()) {
			cout << "error: 포화상태" << endl;
			exit(-1);
		}
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = item;
	}

	BinaryNode* dequeue() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
			exit(-1);
		}
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}

	BinaryNode* peek() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
		}
		else {
			return data[(front + 1) % MAX_SIZE];
		}
	}
	void display() {
		int maxi = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
class BinaryTree {
	BinaryNode* root; //루트 노드
	void inorder(BinaryNode* node);
	void preorder(BinaryNode* node);
	void postorder(BinaryNode* node);
	
public:
	BinaryTree() :root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	int getCount() {
		return isEmpty() ? 0 : getCount(root);
	}
	int getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}
	int getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}
	int isFull() {
		return isEmpty() ? true : isFull(root);
	}
	int calcLevel(int n) {
		return isEmpty() ? 0 : calcLevel(root, n, 1);
	}


	//트리의 노드 개수
	int getCount(BinaryNode* node);
	//단말노드의 개수
	int getLeafCount(BinaryNode* node);
	//트리의 높이(최대 레벨)
	int getHeight(BinaryNode* node);
	//포화 여부
	bool isFull(BinaryNode* node);
	int calcLevel(BinaryNode* node, int n, int level);

	//트리 순회
	void inorder() { printf(" \n inorder: "); inorder(root); }
	void preorder() { printf("\n preorder: "); preorder(root); }
	void postorder() { printf("\n postorder: "); postorder(root); }
	void levelorder();
};


int BinaryTree::getCount(BinaryNode* node) {
	if (node == NULL) return 0;
	return 1 + getCount(node->getLeft()) + getCount(node->getRight());
}

int BinaryTree::getLeafCount(BinaryNode* node) {
	if (node == NULL) return 0;
	if (node->isLeaf()) return 1;
	else
		return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
}

int BinaryTree::getHeight(BinaryNode* node) {
	if (node == NULL) return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? 1 + hLeft : 1 + hRight;
}

bool BinaryTree::isFull(BinaryNode* node) {
	if (node == NULL) return true;
	if (node->left == NULL && node->right == NULL) return true;
	if (node->left != NULL && node->right != NULL)
		return isFull(node->left) && isFull(node->right);
	else return false;
}

int BinaryTree::calcLevel(BinaryNode* node, int n, int level) {
	if (node == NULL) return 0;
	if (node->data == n) return level;
	int ll = calcLevel(node->left, n, level + 1);
	if (ll != 0) return ll;
	//왼쪽에서 못 찾았을 경우, 오른쪽 서브트리에서 탐색
	ll = calcLevel(node->right, n, level + 1);
	return ll;
}

//중위 순회(왼, 루트, 오)
void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL)
			inorder(node->getLeft());
		printf(" [%c] ", node->getData());
		if (node->getRight() != NULL)
			inorder(node->getRight());
	}
}

//전위 순회(루트, 왼, 오)
void BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		printf(" [%c] ", node->getData());
		if (node->getLeft() != NULL)
			preorder(node->getLeft());
		if (node->getRight() != NULL)
			preorder(node->getRight());
	}
}
//후위 순회(왼->오->루트)
void BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL)
			postorder(node->getLeft());
		if (node->getRight() != NULL)
			postorder(node->getRight());
		printf(" [%c] ", node->getData());
	}
}

void BinaryTree::levelorder() {
	CircularQueue q;
	printf(" \n levelorder: ");
	if (!isEmpty()) {
		q.enqueue(root);
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				printf(" [%c] ", n->getData());
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	cout << endl;
}
int main() {
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', NULL, NULL);
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* g = new BinaryNode('G', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', f, g);
	BinaryNode* a = new BinaryNode('A', b, c);

	tree.setRoot(a);

	cout << " 노드의 개수= " << tree.getCount() << endl;
	cout << " 단말의 개수= " << tree.getLeafCount() << endl;
	cout << " 트리의 높이= " << tree.getHeight() << endl;

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.levelorder();
}