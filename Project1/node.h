/* Jonathon Harris- Project 1 Relief Catalogue - CS202
//This .h holds all my different nodes: clothing node, food node, shelter node
//CLL Manager LIST, and History class. 
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include "class.h"
#ifndef NODE_H
#define NODE_H
class List
{
    protected:
        class f_Node * f_rear;
        class c_Node * c_rear;
        class s_Node * s_rear;
    public:
        List();//default constructor
        ~List();//default destructor
        int add_food_node(f_Node *to_add);
        int add_clothing_node(c_Node *to_add);
        int add_shelter_node(s_Node *to_add);
        int display_all_food() const;
        int display_all_clothing() const;
        int display_all_shelter() const;
        int remove_food_node(char * name);
        int remove_clothing_node(char * name);
        int remove_shelter_node(char * name);
        int search_food(char * name) const; //TODO Make sure these const make sense
        int search_clothing(char * name) const;
        int search_shelter(char * name) const;
        int destroy_fList();//wrapper for destroy food list
        int destroy_sList();//wrapper for destroy shelter list
        int destroy_cList();//wrapper for destroy clothing list
        int food_retrieve(char * name, List &newList) const;  
        int shelter_retrieve(char * name, List &newList) const; 
        int clothing_retrieve(char * name, List &newList) const; 

        void clear();
        void menu(int &user_in);
    private: 
        int add_food_node(f_Node *& f_rear, f_Node *to_add);
        int add_clothing_node(c_Node *& c_rear, c_Node *to_add);
        int add_shelter_node(s_Node *& s_rear, s_Node *to_add);
        int display_all_food(f_Node *f_rear) const;
        int display_all_clothing(c_Node *c_rear) const;
        int display_all_shelter(s_Node *s_rear) const;
        int remove_food_node(f_Node *& f_rear,f_Node *prev, char * name);
        int remove_clothing_node(c_Node *& c_rear,c_Node *prev,  char * name);
        int remove_shelter_node(s_Node *& s_rear,s_Node *prev,  char * name);
        int search_food(f_Node * f_rear, char * name) const ;
        int search_clothing(c_Node * c_rear, char * name) const ;
        int search_shelter(s_Node * s_rear, char * name) const ;
        int destroy_fList(f_Node *&f_rear);
        int destroy_cList(c_Node *&c_rear);
        int destroy_sList(s_Node *&s_rear);
        int food_retrieve(f_Node *f_rear, List &newList, char * name) const;  
        int clothing_retrieve(c_Node *c_rear, List &newList, char * name) const; 
        int shelter_retrieve(s_Node *s_rear, List &newList, char * name) const; 

};
//FOOD NODE
class f_Node : public Food
{
    public:
        f_Node();//default constructor
        f_Node(char *nme, int quant, char * expir, char * allerg);
        f_Node(const f_Node &copy); 
        ~f_Node();//default destructor
        f_Node *& get_next();//getter
        void set_next(f_Node *connect);//setter
    protected:
        f_Node * next;

};
//CLOTHING NODE
class c_Node : public Clothing
{
    public:
        c_Node();//default constructor
        c_Node(char *nme, int quant, char * expir, char * allerg);
        c_Node(const c_Node &copy); 
        ~c_Node();//default destructor
        c_Node *& get_next();//getter
        void set_next(c_Node *connect);//setter
    protected:
        c_Node * next;
};
//SHELTER NODE
class s_Node : public Shelter
{
    public:
        s_Node();//default constructor
        s_Node(char *nme, int quant, char * duration, bool bath, bool pets); 
        s_Node(const s_Node &copy); 
        ~s_Node();//default destructor
        s_Node *& get_next();//getter
        void set_next(s_Node *connect);//setter
    protected:
        s_Node * next;

};
//NODE FOR HISTORY LLL
class Node
{
    public: 
        Node();
        Node(char * nme);
        Node *& get_next();
        void set_next(Node * connect);
        char * get_name();
        char * node_name;
        Node* newNode(char *nme);
        Node(const Node &copy);
        ~Node();
    protected:
        Node * next;
};
//HISTORY LIST MANAGER
class History
{
    public:
        History();
        ~History();
        //int add_history(char * name);
        int add_node(char * name);
        int display_history() const;
        int delete_all();
        Node* add(char * name);
    protected: 
        int add_node(Node *&head, char * name);
        int display_history(Node * head) const;
        int delete_all(Node *& head);
    private:
        Node * head;
};
        


#endif
