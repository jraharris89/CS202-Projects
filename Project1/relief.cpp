/* Jonathon Harris- Project 1 Relief Catalogue - CS202
 * relief.cpp contains my relief type class definitions  as well as the different 
 * relief node functions associated with them. This also has History class which
 * contains a Node * head that keeps track of the differents names the user searches
 * for.
 */ 
#include "node.h"
//-----------------------------------------------------------INFO FUNCTIONS
//Default constructor
Info::Info()
{
    name = NULL;
    quantity = 0;
}
//Parameterized Constructor
Info::Info(char *nme, int quan)
{
    
    if(nme)
    {
        name = new char[strlen(nme)+1];
        strcpy(name,nme);
    }
    quantity = quan;
}
//Info Copy constructor
Info::Info(const Info & copy_from)
{

    if(copy_from.name)
    {
        name = new char[strlen(copy_from.name)+1];
        strcpy(name, copy_from.name);
    }
    else
        name = NULL;

    quantity = copy_from.quantity;
}
bool Info::compare_name(char * nme)
{
    if(strcmp(nme, name)==0)
        return true;
    else
        return false;
}
int Info::Info_display() const
{
    if(!name)
        return 0;
    cout << "Name: " << name << endl;
    cout << "Quantity: " << quantity << endl;
    return 0;
}
//Info Destructor
Info::~Info()
{
    if(name)
        delete [] name;

    quantity = 0;
}
//-------------------------------------------------------FOOD FUNCTIONS
//Default food constructor 
Food::Food()
{
    expiration = NULL;
    allergies = NULL;
}
//Parameterized constructor for Food
Food::Food(char *nme, int quan,char * expir, char *allerg): Info(nme,quan)
{

    if(expir)
    {
        expiration = new char[strlen(expir) + 1];
        strcpy(expiration, expir);
    }
    else
        expiration = NULL;
    if(allerg)
    {
        allergies = new char[strlen(allerg) + 1];
        strcpy(allergies, allerg);
    }
    else
        allergies = NULL;
}
//Food Copy Constructor 
Food::Food(const Food &copy_from) : Info(copy_from)
{
    if(expiration)
        delete [] expiration;
    if(allergies)
        delete [] allergies;

    if(copy_from.expiration)
    {
        expiration = new char[strlen(copy_from.expiration) + 1];
        strcpy(expiration, copy_from.expiration);
    }
    else
        expiration = NULL;

    if(copy_from.allergies)
    {
        allergies = new char[strlen(copy_from.allergies) + 1];
        strcpy(allergies, copy_from.allergies);
    }
    else
        allergies = NULL;
}
//Food edit info
int Food::food_display() const
{
    Info::Info_display();
    if(!expiration)
        return 0;
    else
        cout << "Expiration date: " << expiration<< endl;
    if(!allergies)
        return 0;
    else
        cout << "Allergies: " << allergies<< endl;
    cout << '\n' << '\n';
    return 1;
}

//Food destructor
Food::~Food()
{
    if(expiration)
        delete [] expiration;
    if(allergies)
        delete [] allergies;
}
//-----------------------------------------------------------CLOTHING FUNCTIONS
Clothing::Clothing()
{
    size = NULL;
    sex = NULL;
}
//parameterized constructor
Clothing::Clothing(char *nme, int quan,char * sze, char *sx) : Info(nme, quan)
{
    if(sze)
    {
        size = new char[strlen(sze) + 1];
        strcpy(size, sze);
    }
    else
        size = NULL;
    if(sx)
    {
        sex = new char[strlen(sx) + 1];
        strcpy(sex, sx);
    }
    else
        sex = NULL;
}
//Clothing copy constructor
Clothing::Clothing(const Clothing &copy_from) : Info(copy_from)
{
    if(sex)
        delete [] sex;
    if(size)
        delete [] size;

    if(copy_from.sex)
    {
        sex = new char[strlen(copy_from.sex) + 1];
        strcpy(sex, copy_from.sex);
    }
    else
        sex = NULL;

    if(copy_from.size)
    {
        size = new char[strlen(copy_from.size) + 1];
        strcpy(size, copy_from.size);
    }
    else
        size = NULL;
}
int Clothing::clothing_display() const
{
    Info::Info_display();
    cout << "Size: " << size << endl;
    cout << "Sex: " << sex << endl;
    cout << '\n' << '\n';
    return 1;
}
Clothing::~Clothing()
{
    if(size)
        delete [] size;
    if(sex)
        delete [] sex;
}
//-----------------------------------------------------------SHELTER FUNCTIONS
Shelter::Shelter()
{
    duration = NULL;
    bathroom = false;
    pets_allowed = false;
}
//parameterized constructor
Shelter::Shelter(char *nme, int quan,char * dur, bool bath, bool pets) : Info(nme, quan)
{
    if(dur)
    {
        duration= new char[strlen(dur) + 1];
        strcpy(duration, dur);
    }
    else
        duration= NULL;
    bath = false;
    pets = false;
}
//Shelter copy constructor
Shelter::Shelter(const Shelter &copy_from): Info(copy_from)
{
    if(duration)
        delete [] duration;

    if(copy_from.duration)
    {
        duration= new char[strlen(copy_from.duration) + 1];
        strcpy(duration, copy_from.duration);
    }
    else
        duration = NULL;
    
    bathroom = copy_from.bathroom;
    pets_allowed = copy_from.pets_allowed;
}
//edit clothing info
int Shelter::shelter_display() const
{
    Info::Info_display();
    cout << "Duration: " << duration<< endl;
    cout << "Bathrooms available: ";
    if(bathroom)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << "Pets allowed: ";
    if(pets_allowed)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << '\n' << '\n';
    return 1;
}
//Shelter destructor
Shelter::~Shelter()
{
    if(duration)
        delete [] duration;
    bathroom = false;
    pets_allowed = false;
}
//---------------------------------------------------------FOOD NODE FUNCTIONS
//Food node destructor 
f_Node::~f_Node()
{
    next = NULL;
}
//food node setter
void f_Node::set_next(f_Node *connect)
{
    next = connect;
}
//f_Node constructor
f_Node::f_Node()
{
    next = NULL;
}
//f_Node parameterized constructor
f_Node::f_Node(char *nme, int quan, char *expir, char * allerg) : Food(nme,quan,expir,allerg)
{
    next = NULL;
}
//f_Node copy constructor
f_Node::f_Node(const f_Node &copy) : Food(copy)
{
    next = NULL;
}
//f_Node get_next
f_Node*& f_Node::get_next()
{
    return next;
}
//---------------------------------------CLOTHING NODE FUNCTIONS
c_Node::c_Node()
{
    next = NULL;
}
//c_Node destructor 
c_Node::~c_Node()
{
    next = NULL;
}
c_Node::c_Node(char *nme, int quan, char *sze, char * sx) : Clothing(nme,quan,sze,sx)
{
    next = NULL;
}
c_Node::c_Node(const c_Node &copy) : Clothing(copy)
{
    next = NULL;
}
//clothing get next pointer
c_Node*& c_Node::get_next()
{
   return next; 
}
//clothing node setter
void c_Node::set_next(c_Node *connect)
{
    next = connect;
}
//---------------------------------------SHELTER NODE FUNCTIONS
//Shelter node destructor 
s_Node::~s_Node()
{
    next = NULL;
}
//Shelter node setter
void s_Node::set_next(s_Node *connect)
{
    next = connect;
}
//Shelter constructor
s_Node::s_Node()
{
    next = NULL;
}
//Shelter parameterized constructor
s_Node::s_Node(char *nme, int quant, char * duration, bool bath, bool pets) : Shelter(nme,quant,duration,bath,pets)
{
    next = NULL;
}
//Shelter copy constructor
s_Node::s_Node(const s_Node &copy) : Shelter(copy)
{
    next = NULL;
}
//Shelter get_next
s_Node*& s_Node::get_next()
{
    return next;
}
//---------------------------------------NODE (FOR HISTORY)  FUNCTIONS
Node::Node()
{
    next = NULL;
    node_name = NULL;
}
Node::Node(char * nme)
{
    if(nme)
    {
        node_name = new char[strlen(nme) + 1];
        strcpy(node_name,nme);
    }
    else
        nme = NULL;
}
Node::~Node()
{
    if(node_name)
        delete [] node_name;
}
Node*& Node::get_next()
{
    return next;
}
char * Node::get_name()
{
    return node_name;
}
void Node::set_next(Node * connect)
{
    next = connect;
}
Node::Node(const Node &copy)
{
    if(copy.node_name)
    {
        node_name = new char[strlen(copy.node_name) + 1];
        strcpy(node_name,copy.node_name);
    }
    else
        node_name= NULL;
    next = NULL;
}

//---------------------------------------HISTORY LIST FUNCTIONS
History::History()
{
    head = NULL;
}
History::~History()
{
    head = NULL;
}
int History::add_node(char * name)
{
    return add_node(head, name);
}
int  History::add_node(Node *&head, char * name)
{
    if(!head)
    {
        Node * newNode = new Node(name);
        head = newNode;
    }
    else
    {
        Node * temp = new Node(name);
        temp->set_next(head);
        head = temp; 
    }
    return 1;
}
int History::display_history() const
{
    int count = 0;
    count = display_history(head);
    return count;
}
int History::display_history(Node *head) const
{
    if(!head)
        return 0;
    int count = 0;
    cout << head->get_name()<< '\t';
    count += display_history(head->get_next()) + 1;
    return count;
}
int History::delete_all()
{
    if(!head)
        return 0;

    int count = delete_all(head);
    return count;
}
int History::delete_all(Node *&head)
{
    int count = 0;
    if(!head)
        return 0;
    count += 1 + delete_all(head->get_next());
    delete head;
    head = NULL;
    return count;
}
