#include <iostream>
#define MAX_SIZE 100
using namespace std;

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
			cout << "error: ��ȭ����" << endl;
			exit(-1);
		}
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = item;
	}

	BinaryNode* dequeue() {
		if (isEmpty()) {
			cout << "error: �������" << endl;
			exit(-1);
		}
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}

	BinaryNode* peek() {
		if (isEmpty()) {
			cout << "error: �������" << endl;
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
protected:
	BinaryNode* root;
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


	//Ʈ���� ��� ����
	int getCount(BinaryNode* node);
	//�ܸ������ ����
	int getLeafCount(BinaryNode* node);
	//Ʈ���� ����(�ִ� ����)
	int getHeight(BinaryNode* node);
	//��ȭ ����
	bool isFull(BinaryNode* node);
	int calcLevel(BinaryNode* node, int n, int level);

	//Ʈ�� ��ȸ
	void inorder() { printf(" \n inorder: "); inorder(root); }
	void preorder() { printf("\n preorder: "); preorder(root); }
	void postorder() { printf("\n postorder: "); postorder(root); }
	void levelorder();
};

int BinaryTree::getCount(BinaryNode* node) {
	if (node == NULL)
		return 0;
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
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

bool BinaryTree::isFull(BinaryNode* node) {
	if (node == NULL) return true;
	if (node->left == NULL && node->right == NULL) return true;
	if (node->left != NULL && node->right != NULL)
		return isFull(node->left) && isFull(node->right);
	else return false;
}

//n�� ��ġ�ϴ� ����� ���� ��ȯ
int BinaryTree::calcLevel(BinaryNode* node, int n, int level) {
	if (node == NULL) return 0;
	if (node->data == n) return level;
	//���� ���� Ʈ�� Ž��
	int ll = calcLevel(node->left, n, level + 1);
	if (ll != 0) return ll;
	//������ ���� Ʈ�� Ž��
	ll = calcLevel(node->right, n, level + 1);
	return ll;
}

//���� ��ȸ
void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL)
			inorder(node->getLeft());
		printf(" [%d] ", node->getData());
		if (node->getRight() != NULL)
			inorder(node->getRight());
	}
}

//���� ��ȸ
void BinaryTree::preorder(BinaryNode* node) {
	if (node != NULL) {
		printf(" [%d] ", node->getData());
		if (node->getLeft() != NULL)
			preorder(node->getLeft());
		if (node->getRight() != NULL)
			preorder(node->getRight());
	}
}

void BinaryTree::postorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL)
			postorder(node->getLeft());
		if (node->getRight() != NULL)
			postorder(node->getRight());
		printf(" [%d] ", node->getData());
	}
}

void BinaryTree::levelorder() {
	CircularQueue q;
	printf("\n levelorder: ");
	if (!isEmpty()) {
		q.enqueue(root); //��Ʈ ��� ����
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				printf(" [%d] ", n->getData()); //ť ���� ��� ���
				q.enqueue(n->getLeft()); //�ش� ����� ���� ��� ����
				q.enqueue(n->getRight()); //�ش� ����� ������ ��� ����
			}
		}
	}
	cout << endl;
}

class BinSrchTree : public BinaryTree {
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}

	BinaryNode* search(int key);
	BinaryNode* search(BinaryNode* n, int key); //recursion
	
	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);
	
	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

BinaryNode* BinSrchTree::search(int key) {
	BinaryNode* node = search(root, key);
	if (node != NULL) {
		cout << "Ž�� ����: Ű ���� " << node->getData()
			<< " �� ���=0x" << node << endl;
	}
	else
		cout << "Ž�� ����: Ű ���� " << key << "�� ��� ����" << endl;
	return node;
}

//recursion
BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL)
		return NULL;
	if (key == n->getData())
		return n;
	else if (key < n->getData()) //Ű ���� ��Ʈ���� ������
		return search(n->getLeft(), key); //���� ���� Ʈ�� Ž��
	else  //Ű ��>��Ʈ
		return search(n->getRight(), key); //������ ���� Ʈ�� Ž��
}


void BinSrchTree::insert(BinaryNode* n) {
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}


//recursion
//��Ʈ���, �����Ϸ��� ���
void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return;
	else if (n->getData() < r->getData()) { //���� ���<��Ʈ���
		if (r->getLeft() == NULL)
			r->setLeft(n);
		else
			insert(r->getLeft(), n);
	}
	else { //���Գ��> ��Ʈ���
		if (r->getRight() == NULL)
			r->setRight(n);
		else insert(r->getRight(), n);
	}
}

void BinSrchTree::remove(int key) {
	if (isEmpty()) return;
	BinaryNode* parent = NULL;
	BinaryNode* node = root;
	//key���� ���� ��� Ž��
	while (node != NULL && node->getData() != key) {
		parent = node;
		//Ű�� ��Ʈ ����� ũ�� ���Ͽ� Ž�� ���� ����
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}
	//�ܸ����� �����ߴµ��� key�� �� ã�� ���
	if (node == NULL) {
		printf(" ����: Ű�� Ʈ���� �����ϴ�.\n");
	}
	else remove(parent, node);
}
void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {
	// i) ���� ��尡 �ܸ����
	if (node->isLeaf()) {
		if (parent == NULL)
			root = NULL;
		else { //�θ� ��尡 ������ ��
			if (parent->getLeft() == node) //������ ��尡 �θ��� ���� �ڽ�
				parent->setLeft(NULL); //���� ����
			else  //�����Ϸ��� ��尡 �θ��� ������ �ڽ�
				parent->setRight(NULL);
		}
	}
	// ii) ���� ��忡 ���� �ڽ� Ȥ�� ������ �ڽ� ����
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		BinaryNode* child = (node->getLeft() != NULL) ?
			node->getLeft() : node->getRight(); //�ڽ� ��� ����
		// �����Ϸ��� ��尡 ��Ʈ���
		if (node == root)
			root = child;
		else {
			if (parent->getLeft() == node) //�θ��� ���ʿ� ��� ����
				parent->setLeft(child); //�θ�� �ڼ� ����
			else //�θ��� �����ʿ� ��� ����
				parent->setRight(child);
		}
	}
	// iii) ���� ��尡 2���� ����Ʈ�� ����
	else {
		BinaryNode* succp;
		BinaryNode* succ;

		BinaryNode* Lsuccp = node;
		BinaryNode* Lsucc = node->getRight();
		//�� �� ���������� ���� ��� �������� ���� leftmost node
		//leftmost node: ������ ����Ʈ�� �� ���� ������ ���
		while (Lsucc->getLeft() != NULL) {
			Lsuccp = Lsucc;
			Lsucc = Lsucc->getLeft();
		}

		BinaryNode* Rsuccp = node;
		BinaryNode* Rsucc = node->getLeft();
		//�� �� �������� ���� ��� ���������� ���� rightmost node
		while (Rsucc->getRight() != NULL) {
			Rsuccp = Rsucc;
			Rsucc = Rsucc->getRight();
		}
		
		// 2. ����
		//leftmost�� rightmost �� �����Ϸ��� ���� ���� �� ���� ��� ��
		if (Lsucc->getData() - node->getData() <= node->getData() - Rsucc->getData()) {
			succp = Lsuccp;
			succ = Lsucc;
			//leftmost ��尡 �θ����� ���ʿ� ����
			if (succp->getLeft() == succ)
				//leftmost�� �θ�� �ڽ� ����
				succp->setLeft(succ->getRight());//leftmost ����̹Ƿ� ������ �ڽĳ��ۿ� ����

			else //leftmost ��尡 �θ����� �����ʿ� ����
				succp->setRight(succ->getRight());
		}
		else {
			succp = Rsuccp;
			succ = Rsucc;
			if (succp->getLeft() == succ) //succp ���� �ڽĿ� rightmost ��尡 ���� ���(������ �ڽ� ����)
				succp->setLeft(succ->getLeft());
			else //succp ������ �ڽĿ� rightmost��尡 ���� ��� (���� �ڽ� ���� �� ����)
				succp->setRight(succ->getLeft());
				
		}

		// 3. ����
		//ȿ���� ���� ������ ����� ������ ���� �ٲ�
		//(�ڽ� �����͸� ���)
		node->setData(succ->getData());
		node = succ;
	}
	//4. ����
	//�� ������ �� ����
	delete node;
}

int main() {
	BinSrchTree tree;
	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));
	printf("\n <Original BST> : ");
	tree.levelorder();
	printf(" ����: case 1 ==> ���  3 ���� :");
	tree.remove(3);
	tree.levelorder();
	printf(" ����: case 2 ==> ��� 68 ���� : ");
	tree.remove(68);
	tree.levelorder();
	printf(" ����: case 3 ==> ��� 18 ���� : ");
	tree.remove(18);
	tree.levelorder();
	printf(" ����: case 3 ==> ��� 35 ���� (��Ʈ ��� ����) :  ");
	tree.remove(35);
	tree.levelorder();


	// ���� Ʈ�� ���� ���
	printf("\n <���� BST ���� ���> \n");
	printf(" ����� ���� = %d\n", tree.getCount());
	printf(" �ܸ��� ���� = %d\n", tree.getLeafCount());
	printf(" Ʈ���� ���� = %d\n", tree.getHeight());
}