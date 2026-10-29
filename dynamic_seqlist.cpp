// À≥–Ú±Ì

#include <iostream>

using  ElemType = int;

const int InitSize = 100;

typedef struct {
    ElemType *data;
    int length;
    int LISTSIZE;
}SeqList;

// ≥ı ºªØ
SeqList* InitList()
{
    SeqList *L = new SeqList;
    L->data = new(std::nothrow) ElemType[InitSize];
    if(L->data == nullptr){
        delete L;
        return nullptr;
    }
    L->length = 0;
    L->LISTSIZE = InitSize;
    return L;
}
//¿©»›
bool ExpandList(SeqList *L){
  ElemType *newData = new(std::nothrow) ElemType[2* L->LISTSIZE];
  if(newData == nullptr)
      return false;
  for (int i = 0; i < L->length; i++)
    newData[i] = L->data[i];
  delete[] L->data;
  L->data = newData;
  L->LISTSIZE *= 2;
  
  return true;
}
// ‘⁄Œ≤◊∑º”
int appendElem(SeqList *L, ElemType e){
  if (L->length >= L->LISTSIZE){
     if(!ExpandList(L)){
            std::cout << "¿©»› ß∞‹" << std::endl;
            return 0;
        }
    }
  L->data[L->length] = e;
  L->length ++;
  return 1;
}
// ±È¿˙
void ListElem(SeqList *L){
  for(int i = 0; i < L->length; i++)
   std::cout << L->data[i] << std::endl;
}
// ≤Â»Î
int insertElem(SeqList *L, int pos, ElemType e){
  
  if (pos < 1 || pos > L->length + 1){
    std::cout << "≤Â»ÎŒª÷√¥ÌŒÛ" << std::endl;
    return 0;
  }
  if (L->length == L->LISTSIZE)
     if(!ExpandList(L)){
            std::cout << "¿©»› ß∞‹" << std::endl;
            return 0;
        } 
   for(int i = L->length - 1; i >= pos - 1; i--)
     L->data[i+1] = L->data[i];
   L->data[pos-1] = e;
   L->length ++;
   return 1;
  
}
// …æ≥˝
int deleteElem(SeqList *L, int pos, ElemType *e){
  if(L->length == 0){
    std::cout << "±ÌŒ™ø’" << std::endl;
    return 0;
  }
  if (pos < 1 || pos > L->length){
    std::cout << "…æ≥˝Œª÷√¥ÌŒÛ" << std::endl;
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
//≤È’“
int FindElem(SeqList *L, ElemType e){
  for(int i = 0; i < L->length; i++){
   if(L->data[i] == e)
    return i+1;
  }
  return 0;
}
//œ˙ªŸ
void DestroyList(SeqList* &L){
  delete[] L->data;
  delete L;
   L = nullptr;
}
int main(){
  SeqList* L =  InitList();
  appendElem(L,1);
  appendElem(L,2);
  appendElem(L,4);
  insertElem(L,3,3);
  ElemType delData;
  deleteElem(L,2,&delData);
  std::cout << "±ª…æ≥˝µƒ‘™ÀÿŒ™£∫" << delData << std::endl;
  ListElem(L);
}