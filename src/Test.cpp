/*
 * @file             Test.cpp
 * @description      Okuma islemleri ve listelerin karsilastirilmasi islemlerinin yapildigi dosya
 * @course           1.Ogretim A grubu
 * @assignment       1.Odev
 * @date             12.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "DoubleLinkedList.hpp"
#include "Node.hpp"

using namespace std;

string readFile(string);

DoubleLinkedList * groupBy(string);

void compare(DoubleLinkedList*,DoubleLinkedList*);

int main()
{  
    //Sayilar.txt dosyasi okunup line degiskenine atanir
    string line=readFile("doc\\Sayilar.txt");

    //# sembolunden sayi ikiye bolunur ve numbers1 ve numbers2 degiskenlerine atanir
    string numbers1=line.substr(0, line.find("#"));

    string numbers2=line.substr(line.find("#")+1, line.length());

    //sayilar ucerli gruplandirilik listeye atanir
    DoubleLinkedList *sayi1=groupBy(numbers1);

    DoubleLinkedList *sayi2=groupBy(numbers2);

    //karsilastirma fonksiyonu cagrilarak iki liste karsilastirilir
    compare(sayi1,sayi2);

    //listelerin son halleri ekrana yazdirilir
    cout<<"Sayi1: "<<*sayi1;

    cout<<"Sayi2: "<<*sayi2;

    //listeler silinir
    delete sayi1;
    delete sayi2;
  
    return 0;
}

//dosyayi okuyan fonksiyon
string readFile(string file_name)
{
    string text;

    ifstream inFile;

    //dosya acilir ve okunan deger text degiskenin aktarilir
    inFile.open(file_name);

    if(inFile.is_open())
    {
        while(!inFile.eof())
        {
            inFile>>text;
        }
    }

    inFile.close();

    return text;
}

//sayilari ucerli gruplara ayirip listeye atan fonksiyon
DoubleLinkedList * groupBy(string line)
{
    DoubleLinkedList * numbers=new DoubleLinkedList();
    
    for(int i=0;i<line.length()/3;i++)
    {    
        //ucerli ucerli parcalanir     
        string number_str=line.substr(3*i,3);

        //yuzler basamagi sifira esit ise bir ile degistiriir
        string zero_control="0";

        if(number_str[0]==zero_control[0])
        {
            number_str.replace(0,1,"1");
        }
        //int a donusturulur ve listeye eklenir.
        stringstream geek(number_str);

        int number=0;

        geek>>number; 

        numbers->add(number);     
    }

    return numbers;
}

//listedeki elemanlari tek tek karsilastirip buna gore islem yapan fonksiyon
void compare(DoubleLinkedList* list1,DoubleLinkedList *list2)
{
    //listelerin uzunlugu esit degil ise hata verir
    if(list1->count()!=list2->count()) throw "HATA";

    //listelerin tum elemanlari tek tek gezilir
    for(int i=0;i<list1->count();i++)
    {
        //liste1 de ki eleman liste2 de ki elemandan buyuk ise liste1 ters cevirilir
        if(list1->elementAt(i)>list2->elementAt(i))
        {
            list1->reversing();
        }

        //liste1 de ki eleman liste2 de ki elemana esit ise liste2 ters cevirilir
        else if(list1->elementAt(i)==list2->elementAt(i))
        {
            list2->reversing();
        }
        
        //liste1 de ki eleman liste2 de ki elemandan kucuk ise dugumler yer degistirir.
        else if(list1->elementAt(i)<list2->elementAt(i))
        {
            Node *list1_item=list1->PrevByPosition(i+1);
            Node *list1_next=list1->PrevByPosition(i+1)->next;
            Node *list1_prev=list1->PrevByPosition(i+1)->prev;

            Node *list2_item=list2->PrevByPosition(i+1);
            Node *list2_next=list2->PrevByPosition(i+1)->next;
            Node *list2_prev=list2->PrevByPosition(i+1)->prev;

            list1->swap(list2_item,list1_next,list1_prev,i);

            list2->swap(list1_item,list2_next,list2_prev,i);
        }
    } 
}