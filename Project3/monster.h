/* Jonathon Harris - Project 3 - Monster bash 
 * This header file contains prototypes for Attribute - which 
 * is my superclass - Monster ABC, and all my monsters (Dragon,
 * bigfoot, Abominable_Snowman, Chupacabra), my ARR and the
 * ARRNodes that populate that ARR DLL.
 * 
 */
#include "string.h"

const int SIZE =2;//Size of my ARR ( 0 row for attacks, 1 row for defenses)
enum Weakness{FIRE,WATER};

class Attribute
{
    public:
        Attribute();//Default constructor
        Attribute(const Attribute &copy);//Copy constructor
        Attribute(String nme,int weak,int hlth, int defnse);//Parameterized constructor
        String return_name();
        int return_health();
        int return_armour();
        void change_health(int num);//TODO Probably don't need these get rid of them
        void change_nme(String name);
        void change_armour(int num);
        void change_weakness(int num);
        //int increase_health(int damage);//takes damage to health
        int increase_armour(class Monster *&, int damage);//takes damage to armour
        int decrease_armour(class Monster *&, int damage);//takes damage to armour
        void display_info();
        
        virtual ~Attribute();


    protected:
        String name;//Name of the monster
        int weakness;//weakness could represent 0 for fire or 1 for water
        int health;//represents the health of the monster
        int armour ;//Decrease armour first, once that runs out we attack health


};
class Monster : public Attribute
{
    //monster1->attack1(*monster2);
    //pass monster by ref, 
    public:
        Monster();
        Monster(const Monster &copy);
        virtual int Attack1() = 0;//will return an amount of damage
        virtual int Attack2() = 0;//will return an amount of damage
        virtual int Attack3() = 0;//will return an amount of damage
        virtual int Attack_special() = 0;//will return an amount of damage
        virtual int defense1() = 0;//will return an amount of health 
        virtual int defense2() = 0;//will return an amount of health 
        virtual int defense3() = 0;//will return an amount of health 
        virtual ~Monster();
        void display_all();
        //OVERLOADED OPERATORS FOR MY MONSTER
        Monster & operator+=(const Monster &op2);
        bool operator!=(const Monster &op2);
        Monster & operator-=(const Monster &op2);
        friend ostream &operator<<(ostream &, const Monster&);
        friend istream &operator>>(istream &, Monster&);
        Monster & operator++();
        Monster & operator--();
};
class Dragon : public Monster
{
    public:
        Dragon();
        Dragon(const Monster &copy);
        int Attack1();//will return an amount of damage
        int Attack2();//will return an amount of damage
        int Attack3();//will return an amount of damage
        int Attack_special();//will return an amount of damage
        int defense1();//will return an amount of health 
        int defense2();//will return an amount of health 
        int defense3();//will return an amount of health 
        ~Dragon();

};
class Bigfoot: public Monster
{
    public:
        Bigfoot();
        Bigfoot(const Monster &copy);
        int Attack1();//will return an amount of damage
        int Attack2();//will return an amount of damage
        int Attack3();//will return an amount of damage
        int Attack_special();//will return an amount of damage
        int defense1();//will return an amount of health 
        int defense2();//will return an amount of health 
        int defense3();//will return an amount of health 
        ~Bigfoot();

};
class Chupacabra: public Monster
{
    public:
        Chupacabra();
        Chupacabra(const Monster &copy);
        int Attack1();//will return an amount of damage
        int Attack2();//will return an amount of damage
        int Attack3();//will return an amount of damage
        int Attack_special();//will return an amount of damage
        int defense1();//will return an amount of health 
        int defense2();//will return an amount of health 
        int defense3();//will return an amount of health 
        ~Chupacabra();

};
class Abominable_Snowman: public Monster
{
    public:
        Abominable_Snowman();
        Abominable_Snowman(const Monster &copy);
        int Attack1();//will return an amount of damage
        int Attack2();//will return an amount of damage
        int Attack3();//will return an amount of damage
        int Attack_special();//will return an amount of damage
        int defense1();//will return an amount of health 
        int defense2();//will return an amount of health 
        int defense3();//will return an amount of health 
        ~Abominable_Snowman();

};




// Have an array with nodes that contain an integer which 
// represent which attack/defense is chosen. Attacks are array[0], Defenses are array[1]
class ARRNode
{
    public:
        ARRNode();
        ARRNode(int);
        ARRNode*& get_prev();
        ARRNode*& get_next();
        int get_pick();
        void set_next(ARRNode * connect);
        void set_prev(ARRNode * connect);
        ~ARRNode();

    protected:
        // pick represents an attack or defense that the user will choose
        // these will get selected/loaded at random to similate a deck of cards
        int pick; 
    private:
        ARRNode * prev;
        ARRNode * next;
};
//This is my Array of DLL, it holds random numbers that represent attacks and defenses
//Head[0] is attacks, Head[1] is defenses
class ARR
{
    public: 
        ARR();
        void insert_node(int value, int index);//inserts node into A
        int get_attack();
        void delete_all(ARRNode *current);
        int get_defense();
        int find_number(ARRNode * current, int num);//finds random number in list
        ~ARR();
    private:
        ARRNode **head;
}; 
