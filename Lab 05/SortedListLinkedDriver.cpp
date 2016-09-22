#include "SortedListLinked.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

void addCDs(ListArray<CD>* list, SortedListLinked<CD>* sll)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while (iter->hasNext())
   {
      CD* item = iter->next();
      sll->add(item);
   }

   delete iter;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   
   delete iter;
}

//DO THIS
int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");

   SortedListLinked<CD>* list = new SortedListLinked<CD>();
      addCDs(cds, list);
      list->remove();
   
   cout << list->size() << endl;
      SortedListLinked<CD>* iter = list->iterator();
      while(iter->hasNext())
      {
         CD* cd = iter->next();
         cd->displayCD();
      }
	  
   deleteCDs(cds);
   delete iter;
   delete cds;
   delete list;
   
   return 0;
}
