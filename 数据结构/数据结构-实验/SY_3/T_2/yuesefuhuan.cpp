#include <stdio.h>
#include <stdlib.h>
typedef struct personNode{
   int num;                //人员编号
   struct personNode *next;
}personNode,*personList;    //人员结点类型与结点针指类型
void Josephus(int n, int m, int k){ 
   //求解由n个人组成的约瑟夫环问题；初始从第k个人开始，数到m就出列
   int i,j;
   personList r, p;   
   r=NULL;   //先用r作为循环链表的尾指针来创建链表；初始为空链表
   if(n>0) {   //创建第1个结点
      r=(personList)malloc(sizeof(personNode));
      r->num=1;  r->next=r;
   }
   for(i=2;i<=n;i++){   //以r作为尾指针，依次在循环链表尾端插入其余结点;
      p=(personList)malloc(sizeof(personNode));
      p->num=i;
      p->next=r->next; r->next=p; r=p;   //在r结点后插入p结点，并修改r
   }
   p=r->next;  //p指向第1个人员结点
   for(i=1; i<k; i++){   //寻找第k个结点；p指向第k个结点，而r指向其前驱结点
      r=p; p=p->next;
   }
   for(i=1; i<n; i++){   //循环求得前n-1个出列结点，并输出其人员编号
      for(j=1; j<m; j++){   //向后计数找到出列结点并由p指向该结点，而r指向其前驱
         r=p; p=p->next;
      }
      printf("%d ",p->num);  //输出人员编号   
      r->next=p->next; free(p);  //从链表中删除结点
      p=r->next;   //下一计数为1的结点
   }
   printf("%d\n", r->num);               //输出最后出列人员编号
   free(r);  //删除最后一个结点
}
int main(){
   //用于求解约瑟环问题的测试主函数
   int n, m, k;
   printf("  *********约瑟夫环问题*********\n");
   printf("  输入n, m, k：");
   scanf("%d,%d,%d", &n, &m, &k);
   printf("  出列的人员顺序为：");
   Josephus(n, m, k);
   system("pause");
   return 0;
}
