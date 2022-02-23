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

//n과 일치하는 노드의 레벨 반환
int BinaryTree::calcLevel(BinaryNode* node, int n, int level) {
	if (node == NULL) return 0;
	if (node->data == n) return level;
	//왼쪽 서브 트리 탐색
	int ll = calcLevel(node->left, n, level + 1);
	if (ll != 0) return ll;
	//오른쪽 서브 트리 탐색
	ll = calcLevel(node->right, n, level + 1);
	return ll;
}

//중위 순회
void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL)
			inorder(node->getLeft());
		printf(" [%d] ", node->getData());
		if (node->getRight() != NULL)
			inorder(node->getRight());
	}
}

//전위 순회
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
		q.enqueue(root); //루트 노드 삽입
		while (!q.isEmpty()) {
			BinaryNode* n = q.dequeue();
			if (n != NULL) {
				printf(" [%d] ", n->getData()); //큐 안의 노드 출력
				q.enqueue(n->getLeft()); //해당 노드의 왼쪽 노드 삽입
				q.enqueue(n->getRight()); //해당 노드의 오른쪽 노드 삽입
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
		cout << "탐색 성공: 키 값이 " << node->getData()
			<< " 인 노드=0x" << node << endl;
	}
	else
		cout << "탐색 실패: 키 값이 " << key << "인 노드 없음" << endl;
	return node;
}

//recursion
BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL)
		return NULL;
	if (key == n->getData())
		return n;
	else if (key < n->getData()) //키 값이 루트보다 작으면
		return search(n->getLeft(), key); //왼쪽 서브 트리 탐색
	else  //키 값>루트
		return search(n->getRight(), key); //오른쪽 서브 트리 탐색
}


void BinSrchTree::insert(BinaryNode* n) {
	if (n == NULL) return;
	if (isEmpty()) root = n;
	else insert(root, n);
}


//recursion
//루트노드, 삽입하려는 노드
void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return;
	else if (n->getData() < r->getData()) { //삽입 노드<루트노드
		if (r->getLeft() == NULL)
			r->setLeft(n);
		else
			insert(r->getLeft(), n);
	}
	else { //삽입노드> 루트노드
		if (r->getRight() == NULL)
			r->setRight(n);
		else insert(r->getRight(), n);
	}
}

void BinSrchTree::remove(int key) {
	if (isEmpty()) return;
	BinaryNode* parent = NULL;
	BinaryNode* node = root;
	//key값을 갖는 노드 탐색
	while (node != NULL && node->getData() != key) {
		parent = node;
		//키와 루트 노드의 크기 비교하여 탐색 방향 결정
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}
	//단말까지 도달했는데도 key를 못 찾은 경우
	if (node == NULL) {
		printf(" 오류: 키가 트리에 없습니다.\n");
	}
	else remove(parent, node);
}
void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {
	// i) 삭제 노드가 단말노드
	if (node->isLeaf()) {
		if (parent == NULL)
			root = NULL;
		else { //부모 노드가 존재할 때
			if (parent->getLeft() == node) //삭제할 노드가 부모의 왼쪽 자식
				parent->setLeft(NULL); //연결 끊음
			else  //삭제하려는 노드가 부모의 오른쪽 자식
				parent->setRight(NULL);
		}
	}
	// ii) 삭제 노드에 왼쪽 자식 혹은 오른쪽 자식 존재
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		BinaryNode* child = (node->getLeft() != NULL) ?
			node->getLeft() : node->getRight(); //자식 노드 설정
		// 삭제하려는 노드가 루트노드
		if (node == root)
			root = child;
		else {
			if (parent->getLeft() == node) //부모의 왼쪽에 노드 존재
				parent->setLeft(child); //부모와 자손 연결
			else //부모의 오른쪽에 노드 존재
				parent->setRight(child);
		}
	}
	// iii) 삭제 노드가 2개의 서브트리 가짐
	else {
		BinaryNode* succp;
		BinaryNode* succ;

		BinaryNode* Lsuccp = node;
		BinaryNode* Lsucc = node->getRight();
		//한 번 오른쪽으로 가고 계속 왼쪽으로 가면 leftmost node
		//leftmost node: 오른쪽 서브트리 중 가장 왼쪽의 노드
		while (Lsucc->getLeft() != NULL) {
			Lsuccp = Lsucc;
			Lsucc = Lsucc->getLeft();
		}

		BinaryNode* Rsuccp = node;
		BinaryNode* Rsucc = node->getLeft();
		//한 번 왼쪽으로 가고 계속 오른쪽으로 가면 rightmost node
		while (Rsucc->getRight() != NULL) {
			Rsuccp = Rsucc;
			Rsucc = Rsucc->getRight();
		}
		
		// 2. 연결
		//leftmost와 rightmost 중 삭제하려는 노드와 차이 더 적은 노드 고름
		if (Lsucc->getData() - node->getData() <= node->getData() - Rsucc->getData()) {
			succp = Lsuccp;
			succ = Lsucc;
			//leftmost 노드가 부모노드의 왼쪽에 있음
			if (succp->getLeft() == succ)
				//leftmost의 부모와 자식 연결
				succp->setLeft(succ->getRight());//leftmost 노드이므로 오른쪽 자식노드밖에 없음

			else //leftmost 노드가 부모노드의 오른쪽에 있음
				succp->setRight(succ->getRight());
		}
		else {
			succp = Rsuccp;
			succ = Rsucc;
			if (succp->getLeft() == succ) //succp 왼쪽 자식에 rightmost 노드가 있을 경우(오른쪽 자식 없음)
				succp->setLeft(succ->getLeft());
			else //succp 오른쪽 자식에 rightmost노드가 있을 경우 (왼쪽 자식 있을 수 있음)
				succp->setRight(succ->getLeft());
				
		}

		// 3. 복사
		//효율을 위해 삭제할 노드의 데이터 값만 바꿈
		//(자식 데이터를 덮어씀)
		node->setData(succ->getData());
		node = succ;
	}
	//4. 삭제
	//값 복사한 후 삭제
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
	printf(" 삭제: case 1 ==> 노드  3 삭제 :");
	tree.remove(3);
	tree.levelorder();
	printf(" 삭제: case 2 ==> 노드 68 삭제 : ");
	tree.remove(68);
	tree.levelorder();
	printf(" 삭제: case 3 ==> 노드 18 삭제 : ");
	tree.remove(18);
	tree.levelorder();
	printf(" 삭제: case 3 ==> 노드 35 삭제 (루트 노드 삭제) :  ");
	tree.remove(35);
	tree.levelorder();


	// 최종 트리 정보 출력
	printf("\n <최종 BST 정보 출력> \n");
	printf(" 노드의 개수 = %d\n", tree.getCount());
	printf(" 단말의 개수 = %d\n", tree.getLeafCount());
	printf(" 트리의 높이 = %d\n", tree.getHeight());
}