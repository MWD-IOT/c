/*#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct {
	string no;
	string name;
	int score;
}student;
typedef  struct {
	student* elem;     //指向数据元素的基地址
	int  length;       //线性表的当前长度                                                           
}SqList;
bool initList(SqList &L) { //构造顺序表
	L.elem = new student[MAXSIZE];
	if (!L.elem) return false;
	L.length = 0;
	return true;
}
bool getElem(SqList L, int i, student &stu) { //取值
	if (i<1 || i>L.length) return false;
	stu = L.elem[i - 1];
	return true;
}
void locateElemByname(SqList L, string name) { //查找，给定学生姓名查找
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i].name == name) {
			cout << "学号：" << L.elem[i].no << " 姓名" 
				<< L.elem[i].name << " 成绩：" << L.elem[i].score << endl;
		}
	}
}
bool listDelete(SqList L,int i) { //删除，删除i位置上的元素
	if (i<1 || i>L.length) return false;
	for (int j = i; i < L.length; j++) {
		L.elem[j - 1] = L.elem[j]; //i位置之后的元素前移
	}
	return true;
}
bool listInsert(SqList &L, int i, student stu) { //插入
	if (i<1 || i>L.length+1) return false;
	if (L.length == MAXSIZE) return false;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j]; //i位置之后的元素后移
	}
	L.elem[i - 1] = stu; //在i位置上插入学生s
	return true;
}
int main() {
	SqList L;
	student stu;
	string name;
	int i,temp;
	cout << "1. 建立\n";
	cout << "2. 输入\n";
	cout << "3. 查找\n";
	cout << "4. 取值\n";
	cout << "5. 插入\n";
	cout << "6. 删除\n";
	cout << "7. 输出\n";
	cout << "0. 退出\n\n";
	int choose = -1, flag = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose){
		case 1:
			if (initList(L))
				cout << "建立顺序表成功！" << endl << endl;
			else
				cout << "建立顺序表失败！" << endl << endl;
			break;
		case 2:
			cout << "请输入学生个数：" << endl;
			int n;
			cin >> n;
			cout <<endl<< "请录入学生信息：" << endl;
			for (int i = 0; i < n; i++) {
				cout << "请输入第" << i + 1 << "个学生的信息：" << endl;
				cout << "  学号：";
				cin >> L.elem[i].no;
				cout << "  姓名：";
				cin >> L.elem[i].name;
				cout << "  成绩：";
				cin >> L.elem[i].score;
				L.length++;
			}cout << endl;
			break;
		case 3:
			cout << "请输入你要查询的学生姓名：";
			cin >> name;
			locateElemByname(L, name);
			cout << endl;
			break;
		case 4:
			cout << "请输入一个位置用于取值：";
			cin >> i;
			if (getElem(L, i, stu)) {
				cout << "第" << i << "个位置的学生信息为：" << endl;
				cout << "学号：" << stu.no;
				cout << "姓名：" << stu.name;
				cout << "成绩：" << stu.score;
			}
			cout << endl;
			break;
		case 5:
			cout << "请输入你要插入的位置：";
			cin >> i;
			cout << "请输入学生信息："<<endl;
			cout << "  学号：";
			cin >> stu.no;
			cout << endl;
			cout << "  姓名：";
			cin >> stu.name;
			cout << endl;
			cout << "  成绩：";
			cin >> stu.score;
			cout << endl;
			if (listInsert(L, i, stu))
				cout << "插入成功！" << endl;
			else
				cout << "插入失败！" << endl;
			cout << endl;
			break;
		case 6:
			cout << "请输入你要删除的位置：";
			cin >> i;
			if (listDelete(L, i))
				cout << "删除成功！" << endl;
			else
				cout << "删除失败！" << endl;
			cout << endl;
			break;
		case 7:
			cout << "当前所有学生信息：" << endl;
			for (i = 0;i < L.length;i++) {
				cout << "  学号：" << L.elem[i].no << "  姓名：" << L.elem[i].name 
					<< "  成绩：" << L.elem[i].score << endl;
			}
			cout << endl;
			break;
		default: cout << "请正确输入！" << endl;break;
		}
	}
	return 0;
}

*/
#include<iostream>
using namespace std;
#define MAXSIZE 100
int length;
typedef struct{
	string name;
	string no;
	string score;
}Student;

typedef struct LNode{
	Student data;//结点的数据域
	struct LNode* next;//结点的指针域 
}LNode,*LinkList;//LinkList是指向LNode这个结构体的指针

bool InitLink_L(LinkList &L){//初始化链表
	L = new LNode;
	L->next = NULL;
	return true; 	
} 

bool CreateList_H(LinkList &L)//前插法创建单链表 
{
	LinkList p;
	int n;
	L = new LNode;
	L->next = NULL;//先建立一个带有头结点的空链表
	cout<<"请输入学生个数"<<endl;
	cin>>n;
	cout<<"请输入学生信息"<<endl;
	for(int i = 0;i<n;i++){
		cout<<"请输入第"<<i+1<<"个学生信息："<<endl;
		p = new LNode;
		cout << "姓名：";
		cin>>p->data.name;
		cout<<"学号：";
		cin>>p->data.no;
		cout<<"成绩：";
		cin>>p->data.score;
		p->next=L->next;
		L->next=p;//p插到头结点L之后 
		length++;
		 } 
		 return true;
	 }
	 bool LocateElem_L(LinkList L,string e)
	 {
	 	LinkList p;
	 	p = L->next;
	 	while(p&&p->data.name!=e)//顺着链域向后扫描，直到p为空或者p所指结点的数据域等于
		  p = p->next;//p指向下一个结点
		  cout<<"学号："<<p->data.no<<"\t分数："<<p->data.score<<endl;
		  return true;
		  } 
	bool GetElem_L(LinkList L,int i)
	{
		int j;
		LinkList p;
		p = L->next;
		j = 1;//初始化，p指向第一个结点，j为计数器
		while(j<i&&p)//顺链域向后扫描，直到p指向第i个元素或p为空 
		{
			p=p->next;
			++j;
		 } 
		 if(!p||j>i)
		 return false;
		 cout<<"姓名:"<<p->data.name<<"\t学号："<<p->data.no<<"\t分数："<<"p->data.score"<<endl;
		 return true;
	}
	bool ListInsert_L(LinkList&L,int i)
	{
		int j;
		LinkList p,s;
		p = L; 
		j = 0;
		while(p&&j<i-1)
		{
			p=p->next;
			++j;
		 } 
		 if(!p||j>i-1)
		 return false;
		 s= new LNode;//生成新结点*s
		 cin>>s->data.name>>s->data.no>>s->data.score;
		 s->next=p->next;
		 p->next=s;
		 ++length;
		 return true;
		  }
bool ListDelete_L(LinkList& L,int i)
{
	LinkList p,q;
	int j;
	p=L;
	j=0; 
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		++j;	
	}
	if(!(p->next)||(j>i-1))
	return false;
	q=p->next;
	p->next=q->next;
	delete p;
	--length;
	return true;
}
void print(LinkList L){
	LinkList p;
	p=L->next;
	while(p!=NULL)
	{
		cout<<"姓名："<<p->data.name<<"\t学号："<<p->data.no<<"\t分数："<<p->data.score<<endl;
		p = p->next;
	}cout<<endl;
	}
int main(){

	int choose,i,k,p,flag = 0;
	LinkList L= NULL;
	string e;
	cout<<"1、建立"<<endl;
	cout<<"2、输入"<<endl;
	cout<<"3、输出"<<endl;
	cout<<"4、查找"<<endl;
	cout<<"5、取值"<<endl;
	cout<<"6、插入"<<endl;
	cout<<"7、删除"<<endl;
	cout<<"8、统计"<<endl;
	cout<<"0、退出"<<endl;
	choose=-1; 
	while(choose!=0)
	{
		cout<<"请选择："<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				if(InitLink_L(L))
				{
					cout<<"初始化成功!"<<endl;
					flag = 1; 
				}
				else cout<<"初始化失败！"<<endl;
				break;
				case 2:
				if(flag != 1)
				cout<<"程序还没有初始化！"<<endl;
				else{
					if(CreateList_H(L))
					cout<<"输入完成"<<endl;
					else cout<<"输入失败请继续完成输入操作"<<endl;
				}break;
				case 3:
					print(L);
					break;
				case 4:
					cout<<"请输入姓名:"<<endl;
					cin>>e;
					if(LocateElem_L(L,e));
					else cout <<"查询失败！"<<endl;
					break;
				case 5:
				cout<<"请输入第几个元素:"<<endl;
				cin>>i;
				GetElem_L(L,i);
				break;
				case 6:
					cout<<"请输入插入的位置:"<<endl;
					cin>>k;
					cout<<"请依次输入学生的姓名，学号，成绩:"<<endl;
					ListInsert_L(L,k);
					break;
				case 7:
						cout <<"请输入删除的位置:"<<endl;
						cin>>p;
						ListDelete_L(L,p);
						break;
				case 8:
					cout <<"学生总人数:"<<length<<endl;
					break;
				}
			}
			return 0;
		}
			 


