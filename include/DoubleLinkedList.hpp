/*
 * @file             DoubleLinkedList.hpp
 * @description      Aciklama
 * @course           1.Ogretim A grubu
 * @assignment       1.Odev
 * @date             12.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef DOUBLE_LINKEDLIST
#define DOUBLE_LINKEDLIST

#include <iostream>
#include "Node.hpp"

using namespace std;

class DoubleLinkedList
{
    private:

        Node * head;
        int size;
    
    public:
        //kurucu fonksiyon
        DoubleLinkedList();

        //gonderilen indexden bir onceki dugumu donduren fonksiyon
        Node * PrevByPosition(int);   

        //liste uzunlugunu donduren fonksiyon
        int count()const;

        //listenin bos olup olmadigini donduren fonksiyon
        bool isEmpty()const;

        //listenin sonuna eleman ekleyen fonksiyon
        void add(const int&);

        //listenin istenilen indexine eleman ekleyen fonksiyon
        void insert(const int& ,int);

        //listenin ilk elemanini donduren fonksiyon
        const int& first();

        //listenin son elemanini donduren fonksiyon
        const int& last();

        //listede istenilen elemanin indexini donduren fonksiyon
        int indexOf(const int&);

        //listeden istenilen elemani cikaran fonksiyon
        void remove(const int&);

        //listenin istenilen indexindeki elemani silen fonksiyon
        void removeAt(int);

        //parametre olarak gonderilen elemanin listede olup olmadigini kontrol eden fonksiyon
        bool find(const int&);

        //verilen indexdeki elemani donduren fonksiyon
        const int& elementAt(int);

        //listeyi ters ceviren fonksiyon
        void reversing();

        //listeyi temizleyen fonksiyon
        void clear();

        //listeler arasi eleman degistiren fonksiyon
        void swap(Node*,Node *,Node *,int);

        //listenin elemanlarini ekrana yazidran fonksiyon
        friend ostream & operator << (ostream&,DoubleLinkedList&);

        //yikici fonksiyon
        ~DoubleLinkedList();
};
#endif