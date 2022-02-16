/*
 * @file             DoubleLinkedList.cpp
 * @description      DoubleLinkedList sinifinin bulundugu dosya
 * @course           1.Ogretim A grubu
 * @assignment       1.Odev
 * @date             12.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/
#include "DoubleLinkedList.hpp"
#include <iostream>

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    //liste olusturulunca head degiskeni null atanir ve liste bos olustugu icin size degiskenine 0 atanir
    head=NULL;
    size=0;
}

//gonderilen indexden bir onceki dugumu donduren fonksiyon
Node* DoubleLinkedList::PrevByPosition(int position)
{
    //gelen index degerinin listenin uzunlugundan buyuk ise hata verir
    if(position<0 || position>size) throw  "HATA";

    Node* temp=head;

    int index=1;

    //istenilen indexten bir onceki dugume kadar doner
    while(temp->next!=NULL && index!=position)
    {
        temp=temp->next;
        index++;
    }
    //istenilen indexten bir onceki dugumun dondurulmesi
    return temp;
}

//liste uzunlugunu donduren fonksiyon
int DoubleLinkedList::count()const
{
    return size;
}

//listenin bos olup olmadigini donduren fonksiyon
bool DoubleLinkedList::isEmpty()const
{
    return size==0;
}

//listenin sonuna eleman ekleyen fonksiyon
void DoubleLinkedList::add(const int& item)
{
    //insert fonksiyonuna index olarak size degeri gonderilerek listenin sonuna eklenmis olur
    insert(item,size);
}

//listenin istenilen indexine eleman ekleyen fonksiyon
void DoubleLinkedList::insert(const int& item,int index)
{
    //gelen index degerinin listenin uzunlugundan buyuk ise hata verir
    if(index<0 || index>size) throw "HATA";

    /*
    index degeri sıfıra esit ise listenin head degerin eklenecek dugum gelir
    ve onceki head degeri de nextine gelir.
    */
    if(index==0)
    {
        head=new Node(item,head);

        if(head->next!=NULL) head->next->prev=head;
    }

    /*
    oncelikle index degerinden onceki dugumu bulur ve o dugumun nextine yeni dugumu ekler
    */
    else
    {
        Node* prev=PrevByPosition(index);

        prev->next=new Node(item,prev->next,prev);

        if(prev->next->next!=NULL) prev->next->next->prev=prev->next;
    }
    //listeye eleman eklendigi icin size degerini bir arttirir.
    size++;
}

//listenin ilk elemanini donduren fonksiyon
const int& DoubleLinkedList::first()
{
    //liste bos ise hata dondurur
    if(isEmpty()) throw "HATA";

    return head->item;
}

//listenin son elemanini donduren fonksiyon
const int& DoubleLinkedList::last()
{
    //liste bos ise hata dondurur
    if(isEmpty()) throw "HATA";

    Node* temp=PrevByPosition(size);

    return temp->item;
}

//listede istenilen elemanin indexini donduren fonksiyon
int DoubleLinkedList::indexOf(const int& item)
{
    int index=0;

    Node* temp=head;

    /*
    tum dugumleri tek tek gezip gelen item degeriyle karsilastirir ve esit ise o indexi dondurur
    */
    while(temp!=NULL)
    {
        if(temp->item==item) return index;
        index++;
        temp=temp->next;
    }
    //listede o item yoksa hata dondurur
    throw "HATA";
}

//listeden istenilen elemani cikaran fonksiyon
void DoubleLinkedList::remove(const int& item)
{
    //silinecek itemin indexini bulur removeAt fonksiyonu ile o dugumu siler
    int index=indexOf(item);

    removeAt(index);
}

//listenin istenilen indexindeki elemani silen fonksiyon
void DoubleLinkedList::removeAt(int index)
{
    //gelen index degerinin listenin uzunlugundan buyuk ise hata verir
    if(index<0 || index>size) throw "HATA";

    /*
    index degeri sifira esit ise head degerine head in nextini atar
    */
    if(index==0)
    {
        Node * del=head;

        if(head->next!=NULL)
        {
            head=head->next;

            head->prev=NULL;
        }
        else
        {
            head=NULL;
        }

        delete del;
    }

    /*
    oncelikle silinecek dugumden onceki dugumu bulur ve silinecek dugumun nextiyle cift yonlu baglanti 
    kurulup aradaki dugum silinir
    */
    else
    {
        Node * prev=PrevByPosition(index);

        Node * del=prev->next;

        if(prev->next->next!=NULL)
        {
            prev->next=prev->next->next;

            prev->next->prev=prev;
        }

        else
        {
            prev->next=NULL;
        }

        delete del;
    }
    //listeden eleman silindigi icin size degeri bir azaltilir
    size--;
}

//parametre olarak gonderilen elemanin listede olup olmadigini kontrol eden fonksiyon
bool DoubleLinkedList::find(const int& item)
{
    Node * temp=head;

    /*
    tum dugumler tek tek gezilir ve gelen item degeri dugumlerden birine esit ise
    true dondurulur
    */
    while(temp!=NULL)
    {
        if(temp->item==item) return true;

        temp=temp->next;
    }

    return false;
}

//verilen indexdeki elemani donduren fonksiyon
const int& DoubleLinkedList::elementAt(int index)
{
    //gelen index degerinin listenin uzunlugundan buyuk ise hata verir
    if(index<0 || index>size) throw "HATA";

    //index degeri 0 a esit ise head dugumunun itemi dondurulur
    if(index==0) return head->item;

    //PrevByPosition fonksiyonu ile bir onceki dugum bulunur ve onun next dugumundeki item degeri dondurulur
    return PrevByPosition(index)->next->item;
}

//listeyi ters ceviren fonksiyon
void DoubleLinkedList::reversing()
{  
    //son dugum yedeklenir
    Node * last_item=PrevByPosition(size);

    Node * head_item=last_item;

    /*
    son dugumden baslanarak tum dugumlerin next ve prev degerleri yer degistirilir
    */
    while(last_item!=NULL)
    {   
        Node * prev_item=last_item->prev;

        Node * next_item=last_item->next;

        last_item->next=prev_item;

        last_item->prev=next_item;

        last_item=prev_item;
    }
    //head degerine son dugum atanir
    head=head_item;
}

//listeyi temizleyen fonksiyon
void DoubleLinkedList::clear()
{
    //liste bos olana kadar removeAt fonksiyonu cagirilarak liste temizlenir
    while(!isEmpty()) removeAt(0);

    //liste temizlendigi icin size degeri 0 olur
    size=0;
}

//listeler arasi eleman degistiren fonksiyon
void DoubleLinkedList::swap(Node * item,Node* next,Node* prev,int index)
{
    //index degeri sifira esit ise head dugumleri yer degistirilir
    if(index==0)
    {
        head=item;

        head->next=next;

        if(next!=NULL) next->prev=head;          
    }
    //dugumlerin next leri ve prev degerleri yer degistirilir
    else
    {
        item->next=next;

        if(next!=NULL) next->prev=item;

        item->prev=prev;

        if(prev!=NULL) prev->next=item;
    }
}

//listenin elemanlarini ekrana yazidran fonksiyon
ostream & operator << (ostream &output, DoubleLinkedList &obj){

    Node* temp=obj.head;

    while (temp!=NULL)
    {
        cout<<temp->item;
        temp=temp->next;
    }
    cout<<endl;

}

//yikici fonksiyon
DoubleLinkedList::~DoubleLinkedList()
{
    clear();

    delete head;
}