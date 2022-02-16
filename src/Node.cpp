/*
 * @file             Node.cpp
 * @description      Node sinifinin bulundugu dosya
 * @course           1.Ogretim A grubu
 * @assignment       1.Odev
 * @date             12.08.2021
 * @author           Muhammet Cagatay-muhammet.cagatay1@ogr.sakarya.edu.tr 
*/

#include "Node.hpp"
#include <iostream>

Node::Node(int item,Node* next,Node* prev)
{
    this->item=item;
    this->next=next;
    this->prev=prev;   
}