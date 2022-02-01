/*Jonathon Harris - Project 3 - monster bash
 * This header contains all the prototypes for my 
 * balanced tree and the nodes that populate that tree.
 * Many of the functions aren't used in main since the 
 * tree is preloaded. But I still implemented the functions. 
 */


#include "monster.h"

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

enum Color {Red, Black, Dbl_black};

class Node
{

    public:
        Node();
        Node(Monster *); 
        Node(const Node &); 
        //NODE GETTERS
        Node *& get_left();
        Node *& get_right();
        Node *& get_parent();
        String get_name();
        int get_health();
        int get_color();
        Monster *get_monster();
        //NODE SETTERS
        void set_left(Node * connect);
        void set_right(Node * connect);
        void set_parent(Node * connect);
        void set_color(int color);
        void set_data(int data);
        void set_health(int num);
        void set_name(String name);
        //void set_Dragon();
        //void set_Bigfoot();
        //void set_Chupacabra();
        //void set_Abominable();
        void display();
        ~Node();
    protected:
        Monster *ABC;
        int color;
        Node * parent;
        Node * left;
        Node * right;
};
//RED AND BLACK TREE
class Tree
{
    public:
        Tree();//default constructor
        ~Tree();//destructor
        //void check_monster(const Monster & to_add);
        void insert_monster(int type);
        Monster *find_monster(String name);
        void delete_monster(String to_find);
        void inorder();//Wrapper function for inorder display
        void preorder();//Wrapper function for preorder display
        void remove_all();
        void clear();//clears screen with new lines
        //void menu(int &user_in);//Menu for user
    protected: 
        int get_black_height(Node *current);//return the height of black nodes
        void setColor(Node *&current,int);//Sets the color of the node
        int getColor(Node *&current);//return the color of the node (0 - red, 1- black, 2-double black)
        void preorder(Node *current);//preorder display
        void inorder(Node *current);//inorder display
        void fixDelete(Node *&current);//
        void fixInsert(Node *&current);
        void rotateLeft(Node *&current);//Shifts the tree to the left, balancing the tree
        void rotateRight(Node *&current);//Shifts the tree to the right, balancing the tree
        Node* Find_min(Node *&current);//Returns the location of the node with the smallest value
        Node* Find_max(Node *&current);//Returns the location of the node with the largestvalue
        Node* insertBST(Node *&root, Node *&current);//inserts a node in our tree
        Monster* find_monster(Node *root,String name);
        Node* deleteBST(Node *&current, String);//Deletes a node in our tree
    private:
        void remove_all(Node *root);
        Node * root;

};




