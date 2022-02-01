/* Jonathon Harris - Project 3 - Monster bash
 * This .cpp contains the defintions for the balanced tree
 * as well as the nodes that populate the tree. Each node has
 * a monster ABC *, This gets initialized to a particular monster
 * during the insert_node process. 
 */




#include "RedBlackTree.h"
//NODE FUNCTIONS ----------------------------------------------
//Node Default constructor
Node::Node()
{
    parent = left = right = NULL;
}
//Node constructor
Node::Node(Monster *to_add)
{
    ABC = to_add; 
    color = Red;
    left = right = parent = NULL;
}
//copy constructor that uses RTTI, to figure
//out which monster we need to copy
Node::Node(const Node & copy)
{
    if(copy.ABC)
    {
        Dragon * ptr = dynamic_cast<Dragon*>(copy.ABC);
        if(ptr)
           ABC = new Dragon(*copy.ABC);

        Chupacabra * ptr2 = dynamic_cast<Chupacabra*>(copy.ABC);
        if(ptr2)
           ABC = new Chupacabra(*copy.ABC);

        Bigfoot* ptr3 = dynamic_cast<Bigfoot*>(copy.ABC);
        if(ptr3)
           ABC = new Bigfoot(*copy.ABC);

        Abominable_Snowman* ptr4 = dynamic_cast<Abominable_Snowman*>(copy.ABC);
        if(ptr4)
           ABC = new Abominable_Snowman(*copy.ABC);
    }

    color = copy.color;
    parent = copy.parent;
    left = copy.left;
    right= copy.right;
}
//NODE SETTERS -------------------------------------------------
void Node::set_left(Node *connect)
{
    this->left = connect;
}
void Node::set_right(Node *connect)
{
    this->right= connect;
}
void Node::set_parent(Node *connect)
{
    this->parent= connect;
}
void Node::set_health(int num)
{
    this->ABC->change_health(num);
}
void Node::set_name(String name)
{
    this->ABC->change_nme(name);
}
void Node::set_color(int setColor)
{
    this->color= setColor;
}
//NODE GETTERS -------------------------------------------------
Node*& Node::get_left()
{
    return left;
}
Node*& Node::get_right()
{
    return right;
}
Node*& Node::get_parent()
{
    return parent;
}
Monster * Node::get_monster()
{
    return ABC;
}
String Node::get_name()
{
    return ABC->return_name();
}
int Node::get_health()
{
    return ABC->return_health();
}
int Node::get_color()
{
    return color;
}
void Node::display()
{
    ABC->display_all();
}
//NODE DESTRUCTOR-----------------------------------------------
Node::~Node()
{
    delete ABC;
    left = right = parent = NULL;
}
//TREE FUNCTIONS -------------------------------------------------
Tree::Tree()
{
    root = NULL;
}
Tree::~Tree()
{
    remove_all();
}
int Tree::getColor(Node *&current)
{
    if(root == NULL)
        return Black;
    return root->get_color();
}
void Tree::setColor(Node *&current, int color)
{
    if(current == NULL)
        return;
    current->set_color(color);
}
//We add mosters 
Node * Tree::insertBST(Node *&root, Node *&current)
{
    if(root == NULL)
        return current;

    if(current->get_name() < root->get_name())
    {
        root->get_left() = insertBST(root->get_left(), current);
        root->get_left()->get_parent() = root; 
    }
    else if(current->get_name() >= root->get_name())
    {
        root->get_right() = insertBST(root->get_right(),current);
        root->get_right()->get_parent() = root; 
    }
    return root;
}
//Wrapper function for my find monster function
Monster* Tree::find_monster(String name)
{
    if(!root)
        return NULL;
    return find_monster(root,name);
}
//This function takes a monster name then looks for it in 
//the tree, it will return the location of the monster back
//to main otherwise it will return NULL;
Monster* Tree::find_monster(Node *root, String name)
{
    if(!root)
        return NULL;
    if(root->get_name() == name)
        return root->get_monster();
    if(name > root->get_name())
        return find_monster(root->get_right(),name);
    if(name < root->get_name())
        return find_monster(root->get_left(),name);
    return root->get_monster();
}
//This acts as a wrapper to the insertBST function 
//user passes in 1-dragon 2-bigfoot 3-chupa 4-abominable
void Tree::insert_monster(int type)
{
    Monster *ptr;
    if(type == 1)
    {
        ptr = new Dragon;
    }
    else if(type == 2)
    {
        ptr = new Bigfoot;
    }
    else if(type == 3)
    {
        ptr = new Chupacabra;
    }
    else if(type == 4)
    {
        ptr = new Abominable_Snowman;
    }
    else 
    {
        cout << "No matching types." << endl;
        return;
    }


    Node *newNode = new Node(ptr);
    root = insertBST(root,newNode);
    fixInsert(newNode);
}
//This rotates the tree and reassigns 3 pointers so the 
//tree can be balanced
void Tree::rotateLeft(Node *&current)
{
    Node *rightPtr = current->get_right();
    //current->right = rightPtr->left
    current->set_right(rightPtr->get_left());
    if(current->get_right() != NULL)
        current->get_right()->get_parent() = current;

    rightPtr->get_parent() = current->get_parent();

    if(current->get_parent() == NULL)
        root = rightPtr;
    else if( current == current->get_parent()->get_left())
        current->get_parent()->get_left()= rightPtr;
    else
        current->get_parent()->get_right() = rightPtr;

    rightPtr->get_left() = current;
    current->get_parent() = rightPtr;
}
//This rotates the tree and reassigns 3 pointers so the 
//tree can be balanced
void Tree::rotateRight(Node *&current)
{
    Node *leftPtr = current->get_left();
    //current->right = leftPtr->left
    current->set_left(leftPtr->get_right());

    if(current->get_left() != NULL)
        current->get_left()->get_parent() = current;

    leftPtr->get_parent() = current->get_parent();

    if(current->get_parent() == NULL)
        root = leftPtr;
    else if( current == current->get_parent()->get_left())
        current->get_parent()->get_left()= leftPtr;
    else
        current->get_parent()->get_right() = leftPtr;

    leftPtr->get_right() = current;
    current->get_parent() = leftPtr;
}
//Goes through the tree and makes sure the colors are correct
//rearranges the colors if they need fixing
void Tree::fixInsert(Node *&current)
{
    Node *parent = NULL;
    Node *grandparent = NULL;

    while(current != root && getColor(current) == Red && getColor(current->get_parent()) == Red)
    {
        parent = current->get_parent();
        grandparent = parent->get_parent();
        if(parent == grandparent->get_left())
        {
            Node *uncle = grandparent->get_right();
            if(getColor(uncle) == Red)
            {
                setColor(uncle, Black);//Will this work?!
                setColor(parent, Black);
                setColor(grandparent, Red);
                current = grandparent;
            }
            else
            {
                if(current == parent->get_right())
                {
                    rotateLeft(parent);
                    current = parent;
                    parent = current->get_parent();
                }
                rotateRight(grandparent);
                int temp = parent->get_color();
                parent->set_color(grandparent->get_color()); 
                grandparent->set_color(temp); 
                current->get_parent();
            }
        }
        else
        {
            Node * uncle = grandparent->get_left();
            if(getColor(uncle) == Red)
            {
                setColor(uncle, Black);//Will this work?!
                setColor(parent, Black);
                setColor(grandparent, Red);
                current = grandparent;
            }
            else
            {
                if(current = parent->get_left())
                {
                    rotateRight(parent);
                    current = parent;
                    parent = current->get_parent();
                }
                rotateLeft(grandparent);
                int temp = parent->get_color();
                parent->set_color(grandparent->get_color()); 
                grandparent->set_color(temp); 
                //swap(parent->get_color(), grandparent->get_color());
                current = parent;
            }
        }
    }
    setColor(root,Black);
}
void Tree::fixDelete(Node *&current)
{
    if(current == NULL)
        return;
    if(current == root)
    {
        root = NULL;
        return;
    }
    if(getColor(current) == Red || getColor(current->get_left()) == Red || getColor(current->get_right()) == Red)
    {
        Node * child = current->get_left() != NULL ? current->get_left() : current->get_right();
        if(current == current->get_parent()->get_left())
        {
            current->get_parent()->get_left() = child;
            if(child != NULL)
                child->get_parent() = current->get_parent();
            setColor(child, Black);
            delete (current);
        }
    }
    else
    {
        Node * sibling = NULL;
        Node * parent = NULL;
        Node * ptr = current;
        setColor(ptr, Dbl_black);
        while(ptr != root && getColor(ptr) == Dbl_black)
        {
            parent = ptr->get_parent();
            if(ptr == parent->get_left())
            {
                sibling = parent->get_right();
                if(getColor(sibling) == Red)
                {
                    setColor(sibling, Black);
                    setColor(parent , Red);
                    rotateLeft(parent);
                }
                else
                {   
                    if(getColor(sibling->get_left())== Black && getColor(sibling->get_right()) == Black){
                        setColor(sibling, Red);
                        if(getColor(parent) == Red)
                            setColor(parent, Black);
                        else
                            setColor(parent,Dbl_black);
                        ptr = parent;
                    }
                    else
                    {
                        if(getColor(sibling->get_right()) == Black)
                        {
                            setColor(sibling->get_left(), Black);
                            setColor(sibling, Red);
                            rotateRight(sibling);
                            sibling = parent->get_right();
                        }
                        setColor(sibling, parent->get_color());
                        setColor(parent, Black);
                        setColor(sibling->get_right(), Black);
                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else
            {
                sibling = parent->get_left();
                if(getColor(sibling) == Red)
                {
                    setColor(sibling, Black);
                    setColor(parent, Red);
                    rotateRight(parent);
                }
                else
                {
                    if(getColor(sibling->get_left()) == Black && getColor(sibling->get_right()) == Black)
                    {
                        setColor(sibling, Red);
                        if(getColor(parent) == Red)
                            setColor(parent, Black);
                        else
                            setColor(parent, Dbl_black);
                        ptr = parent;
                    }
                    else
                    {
                        if(getColor(sibling->get_left()) == Black)
                        {
                            setColor(sibling->get_right(), Black);
                            setColor(sibling, Red);
                            rotateLeft(sibling);
                            sibling = parent->get_left();
                        }
                        setColor(sibling, parent->get_color());
                        setColor(parent, Black);
                        setColor(sibling->get_left(), Black);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if(current == current->get_parent()->get_left())
            current->get_parent()->get_left() = NULL;
        else
            current->get_parent()->get_right() = NULL;
        delete (current);
        setColor(root, Black);
    }
}
Node * Tree::deleteBST(Node *&root,String name)
{
    if(root == NULL)
        return root;
    if(name < root->get_name())
        return deleteBST(root->get_left(), name);
    if(name> root->get_name())
        return deleteBST(root->get_right(), name);
    if(root->get_left() == NULL || root->get_right() == NULL)
        return root;
    Node * temp = Find_min(root->get_right());
    root->set_name(temp->get_name());  
    return deleteBST(root->get_right(), temp->get_name());
}
//Acts as the wrapper function to deleteBST function
void Tree::delete_monster(String name)
{
    Node *delPtr = deleteBST(root, name);
    fixDelete(delPtr);
}
void Tree::inorder()
{
    return inorder(root);
}
void Tree::inorder(Node *current)
{
    if(current == NULL)
        return;
    inorder(current->get_left());
    current->display();
    inorder(current->get_right());
}
void Tree::preorder()
{
    return preorder(root);
}
void Tree::preorder(Node *current)
{
    if(current == NULL)
        return;
    current->display();
    inorder(current->get_left());
    inorder(current->get_right());
}
//Returns the minimum value location of the tree
Node* Tree::Find_min(Node *&current)
{
    Node *ptr = current;
    while(ptr->get_left() != NULL)
        ptr = ptr->get_left();
    return ptr;
}
//Returns the maximum value location of the tree
Node* Tree::Find_max(Node *&current)
{
    Node *ptr = current;
    while(ptr->get_right() != NULL)
        ptr = ptr->get_right();
    return ptr;
}
//returns the height of the black node
int Tree::get_black_height(Node *current)
{
    int blackHeight = 0;
    while(current != NULL)
    {
        if(getColor(current) == Black)
            ++blackHeight;
        current = current->get_left();
    }
    return blackHeight;
}
//Wrapper for remove all nodes
void Tree::remove_all()
{
    if(!root)
        return ;
    remove_all(root);
    root= NULL;
}
//Removes all nodes from tree, used in the destructor
void Tree::remove_all(Node *root)
{
    if(!root)
        return;
    remove_all(root->get_left());
    remove_all(root->get_right());
    delete root;
}
void Tree::clear()
{
    for(int i = 0; i<250; ++i)
        cout << '\n';
}
//menu for main, didn't end up using this
/*
void Tree::menu(int &user_in)
{
    cout << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add a node. " << endl
        << "2. Remove a node. " << endl
        << "3. Preorder display ." << endl
        << "4. Inorder display ." << endl
        << "5. Quit." << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl;
    cin >> user_in;
    cin.ignore(100, '\n');
    if(user_in <= 0 || user_in > 5)
    {
        cout << "--------Select a Valid option.---------- " << endl
            << "----------------------------------------- " << endl << endl
            << "Please select from the following options: " <<endl
            << "1. Add a node. " << endl
            << "2. Remove a node. " << endl
            << "3. Preorder display ." << endl
            << "4. Inorder display ." << endl
            << "5. Quit." << endl
            << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl;
    }
*/

