// 顺序表

#include <iostream>

const int LISTSIZE = 100;

using  ElemType = int;

typedef struct {
    ElemType data[LISTSIZE];
    int length;
}SqeList;

//初始化
void InitList(SqeList *L){
  L-> length = 0;
}
//在尾部加入新元素
int appendElem(SqeList *L, ElemType e){
  if (L->length >= LISTSIZE){
     std::cout << "顺序表已满" << std::endl;
     return 0;
    }
  L->data[L->length] = e;
  L->length ++;
  return 1;
}
//插入
int insertElem(SqeList *L, int pos, ElemType e){
  if (L->length > LISTSIZE){
    std::cout << "表已满" << std::endl;
    return 1;
  }
  if (pos < 1 || pos > L->length + 1){
    std::cout << "插入位置错误" << std::endl;
    return 1;
  }
  for(int i = L->length - 1; i >= pos - 1; i--)
    L->data[i+1] = L->data[i];
  L->data[pos-1] = e;
  L->length++;
  return 0;
}

int main(){
  SqeList L;
  InitList(&L);
  appendElem(&L,1);
  appendElem(&L,2);
  appendElem(&L,4);
  insertElem(&L,3,3);
  for(int i = 0; i < L.length; i++)
    std::cout << L.data[i] << std::endl;
}