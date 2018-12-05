
//list or node creating
void* list_genList(void); //generating a Linked List : This must be called once for using a Linked List //반드시 써야한다 한번 불러온다 반환하는 값이 포인터이다 리스트의 실체를 만든다. 
int list_addTail(void* obj, void* list); //add a node at the end of the list 노드를 만들어서 붙이는 것이다.  꼬리에다 다는 것 이다. 영화정보데이터 구조체 포인터로 넘겨야된다. 오브젝트 = 영화정보를갖고있는 구조체 포인터 
int list_addNext(void* obj, void* nd); //add a node at the next of the input node  특정 뒤쪽에다가 달 노드 포인터 두가지중 하나를 잘 써라  영화정보를 한번 딱 읽으면 함수 호출 후 링크더 리스트에 하나씩 추가 

//check the property of the list/node
int list_isEndNode(void* nd); //tell if the node is the end node (0 : it is NOT the end node, 1 : it is the end node) 노드가 몇개냐 = 데이터가 몇개냐 데이터반환  nd 포인터를 넣어준다 마지막놈인지 아닌지 0인지 1인지 뱉는다 
int list_len(void* list); //returns the number of nodes in the list  

//get the node pointer
void* list_getNextNd(void* nd); //get the next node of the input node 
void* list_getNdObj(void* nd); //returns the object of the node 구조체의 데이터를 뽑아내는 것이다 

//processing the list
int list_repeatFunc(int (*func)(void* obj, void* arg), void* arg, void* list); //repeat processing func for each node objects
//이거를 잘쓰면 이함수를 잘 불러야하고 이함수가 중요하다
// 저 함수를 잘 ㅣㅅㄹ행을 하면 모든 링크를 불러준다.  
