/*
 * @file             Node.hpp
 * @description      Aciklama
 * @course           1.Ogretim A grubu
 * @assignment       1.Odev
 * @date             12.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node
{
    public:
        int item;

        Node *next;

        Node *prev;
        
        //kurucu fonksiyon
        Node(int item=int(),Node* next=NULL,Node* prev=NULL);
};

#endif