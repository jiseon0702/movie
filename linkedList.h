
//list or node creating
void* list_genList(void); //generating a Linked List : This must be called once for using a Linked List //�ݵ�� ����Ѵ� �ѹ� �ҷ��´� ��ȯ�ϴ� ���� �������̴� ����Ʈ�� ��ü�� �����. 
int list_addTail(void* obj, void* list); //add a node at the end of the list ��带 ���� ���̴� ���̴�.  �������� �ٴ� �� �̴�. ��ȭ���������� ����ü �����ͷ� �Ѱܾߵȴ�. ������Ʈ = ��ȭ�����������ִ� ����ü ������ 
int list_addNext(void* obj, void* nd); //add a node at the next of the input node  Ư�� ���ʿ��ٰ� �� ��� ������ �ΰ����� �ϳ��� �� ���  ��ȭ������ �ѹ� �� ������ �Լ� ȣ�� �� ��ũ�� ����Ʈ�� �ϳ��� �߰� 

//check the property of the list/node
int list_isEndNode(void* nd); //tell if the node is the end node (0 : it is NOT the end node, 1 : it is the end node) ��尡 ��� = �����Ͱ� ��� �����͹�ȯ  nd �����͸� �־��ش� ������������ �ƴ��� 0���� 1���� ��´� 
int list_len(void* list); //returns the number of nodes in the list  

//get the node pointer
void* list_getNextNd(void* nd); //get the next node of the input node 
void* list_getNdObj(void* nd); //returns the object of the node ����ü�� �����͸� �̾Ƴ��� ���̴� 

//processing the list
int list_repeatFunc(int (*func)(void* obj, void* arg), void* arg, void* list); //repeat processing func for each node objects
//�̰Ÿ� �߾��� ���Լ��� �� �ҷ����ϰ� ���Լ��� �߿��ϴ�
// �� �Լ��� �� �Ӥ������� �ϸ� ��� ��ũ�� �ҷ��ش�.  
