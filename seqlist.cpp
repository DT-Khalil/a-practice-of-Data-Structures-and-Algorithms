// 顺序表

#include <iostream>

const int LISTSIZE = 100;

using  ElemType = int;

typedef struct {
    ElemType data[LISTSIZE];
    int length;
}SeqList;

// 初始化
void InitList(SeqList *L){
  L->length = 0;
}
// 在尾追加
int appendElem(SeqList *L, ElemType e){
  if (L->length >= LISTSIZE){
     std::cout << "表已满" << std::endl;
     return 0;
    }
  L->data[L->length] = e;
  L->length ++;
  return 1;
}
// 遍历
void ListElem(SeqList *L){
  for(int i = 0; i < L->length; i++)
   std::cout << L->data[i] << std::endl;
}
// 插入
int insertElem(SeqList *L, int pos, ElemType e){
  if (L->length == LISTSIZE){
    std::cout << "表已满" << std::endl;
    return 0;
  }
 
  if (pos < 1 || pos > L->length){
    std::cout << "插入位置错误" << std::endl;
    return 0;
  }
  else{ 
   for(int i = L->length - 1; i < pos; i--)
     L->data[L->length] = L->data[L->length-1];
   L->data[pos-1] = e;
   L->length ++;
   return 1;
  }
}
// 删除
int deleteElem(SeqList *L, int pos, ElemType *e){
  if(L->length == 0){
    std::cout << "表为空" << std::endl;
    return 0;
  }
  if (pos < 1 || pos > L->length){
    std::cout << "删除位置错误" << std::endl;
    return 0;
   }
  else{
   *e = L->data[pos-1];
   for(int i = pos; i < L->length; i++)
     L->data[i-1] = L->data[i];
   L->length --;
   return 1;
  }
}
//查找
int FindElem(SeqList *L, ElemType e){
  for(int i = 0; i < L->length; i++){
   if(L->data[i] == e)
    return i+1;
  }
  return 0;
}
int main(){
  SeqList L;
  InitList(&L);
  appendElem(&L,1);
  appendElem(&L,2);
  appendElem(&L,4);
  insertElem(&L,3,3);
  ElemType delData;
  deleteElem(&L,2,&delData);
  std::cout << "被删除的元素为：" << delData << std::endl;
  ListElem(&L);
}