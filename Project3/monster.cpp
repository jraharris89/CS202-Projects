/*Jonathon Harris - Project3 - Monster bash
 * This .cpp file has the definitions for my Monster ABC,
 * Attribute (which is my superclass), My monsters (Dragon,
 * bigfoot, Chupacabra, Abominable snowman), The ARR, and
 * finally the nodes that populate the ARR. When a monster is
 * created their name, health, armour and weakness is initialized
 * to the appropriate 
 *
 * You will find the Overloaded Operators defined in this file.
 * Each Moster attack/defense has a sentence stating what 
 * action they did and it will return a number, which we 
 * use later for figuring out how much damage or armour to
 * add/decrease from the opponent. I used dynamic binding so
 * I didn't use any operators that returned R-Values.
 *
 */



#include "monster.h"
//--------------------------------------------------Monster (ABC) functions ------------------------------------------------
Monster::Monster(){}
Monster::Monster(const Monster &copy) : Attribute(copy){}
void Monster::display_all()
{
    display_info();
}
Monster& Monster::operator+=(const Monster &op2)
{
    health += op2.health;
    armour += op2.armour;
    return *this;
}
bool Monster::operator!=(const Monster &op2)
{
    if(this->name == op2.name)
        return false;
    return true;
}
Monster& Monster::operator-=(const Monster &op2)
{
    health -= op2.health;
    armour -= op2.armour;
    return *this;
}
ostream& operator<<(ostream &out, const Monster&obj)
{
    out << obj.name << '\n';
    out << obj.health<< '\n';
    out << obj.armour<< '\n';
    out << obj.weakness<< '\n';
    return out;
}
istream& operator>>(istream &in, Monster&obj)
{
    cout << "Enter the name of your monster: " << endl;
    in >> obj.name;
    cout << "Enter the health of your monster: " << endl;
    in >> obj.health;
    cout << "Enter the armour of your monster: " << endl;
    in >> obj.armour;
    cout << "Enter the weakness of your monster (0-fire,1-water):: " << endl;
    in >> obj.weakness;
    return in;
}
Monster& Monster::operator++()
{
    ++health;
    ++armour;
    return *this;
}
Monster& Monster::operator--()
{
    --health;
    --armour;
    return *this;
}


Monster::~Monster(){}
//--------------------------------------------------ATTRIBUTE (Superclass) ------------------------------------------------
Attribute::Attribute()
{
}
Attribute::Attribute(const Attribute &copy) : name(copy.name)
{
    if(copy.weakness)
        weakness = copy.weakness;
    else
        weakness = 0;

    if(copy.health)
        health= copy.health;
    else
        health= 0;

    if(copy.armour)
        armour = copy.armour;
    else
        armour = 0;
};
Attribute::Attribute(String nme, int weak, int hlth, int armor)
{
    name = nme;

    if(weak)
        weakness = weak;
    else
        weakness = 0;
    if(hlth)
        health = hlth;
    else
        health = 0;
    if(armor)
        armour = armor;
    else
        armour =  0;
}
String Attribute::return_name()
{
    return name;
}
int Attribute::return_health()
{
    return health;
}
int Attribute::return_armour()
{
    return armour;
}
void Attribute::change_health(int num)
{
    this->health = num;
    return;
}
void Attribute::change_nme(String name)
{
    this->name = name;
    return; 
}
void Attribute::change_armour(int num)
{
    this->armour = num;
}
void Attribute::change_weakness(int num)
{
    this->weakness = num;
}
void Attribute::display_info()
{
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Armour: " << armour << endl;
    if(weakness == 0)
        cout << "Weakness: FIRE" << endl;
    else
        cout << "Weakness: WATER" << endl;
    cout << '\n' << '\n';
}
/*
int Attribute::increase_health(int increase)
{
    if(increase + health >= 100)
    {
        health = 100;
        return health;
    }
    else
    {
        health += increase;
        return health;
    }
}
*/
int Attribute::increase_armour(Monster *&obj, int increase)
{
    if(increase + armour>= 100)
    {
        armour = 100;
        return armour;
    }
    else
    {
        armour += increase;
        return health;
    }
}
int Attribute::decrease_armour(Monster *&obj, int damage)
{
    if(armour <= 0)//no armour left, take away health
    {
        if(damage >= health)
        {
            health = armour =  0;
            String nme = return_name();
            cout << nme << " died!!!!!" << endl;
        }
        else
        {
            health -= damage;
            return health;
        }
    }
    if(damage > armour)
    {
        int leftover = damage - armour ;
        armour = 0;
        health -= leftover;
        if(health <=0)
        {
            cout << "You died." << endl;
            health = armour = 0;
            return 0;
        }
        return health;
    }
    else
    {
        armour -= damage;
        return armour;
    }
}
Attribute::~Attribute()
{
}
//--------------------------------------------------Dragon Functions--------------------------------------------------------
Dragon::Dragon()
{
    char name[] = "Dragon";
    change_nme(name);
    change_health(100);
    change_armour(100);
    change_weakness(1);

}
Dragon::Dragon(const Monster &copy) : Monster(copy){}
int Dragon::Attack1()
{
    cout << "The dragon scratched the monster with his super long scary nails (level 1 attack) 15 damage." << endl;
    return 15;
}
int Dragon::Attack2()
{
    cout << "The dragon whipped the monster with his girthy tail (level 2 attack) 25 damage." << endl;
    return 25;
}
int Dragon::Attack3()
{
    cout << "The dragon flew the monster in the air and dropped him (level 3 attack)30 damage." << endl;
    return 30;
}
int Dragon::Attack_special()
{
    cout << "SPECIAL ATTACK!!! SPICY FIRE BREATH, SO MUCH DAMAGE 50 DAMAGE!!!!." << endl;
    return 50;
}
int Dragon::defense1()
{
    cout << "You picked up some raggedy bandages (Defense booster 1) +15 health " << endl;
    return 15;
}
int Dragon::defense2()
{
    cout << "You picked up some kombucha at whole foods(Defense booster 2) +20 health " << endl;
    return 20;
}
int Dragon::defense3()
{
    cout << "Finally something useful you got a pain vaccine (Defense booster 3) +50 health" << endl;
    return 50;
}
Dragon::~Dragon(){}
//--------------------------------------------------Bigfoot Functions--------------------------------------------------------
Bigfoot::Bigfoot()
{
    char name[] = "Bigfoot";
    change_nme(name);
    change_health(100);
    change_armour(100);
    change_weakness(0);
}
Bigfoot::Bigfoot(const Monster &copy) : Monster(copy){}

int Bigfoot::Attack1()
{
    cout << "Bigfoot stinky armpits caused you to reevaulate your life choices (level 1 attack) 15 damage." << endl;
    return 15;
}
int Bigfoot::Attack2()
{
    cout << "Bigfoot blasted you in the face with a right hook (level 2 attack) 25 damage." << endl;
    return 25;
}
int Bigfoot::Attack3()
{
    cout << "Bigfoot kicked you with his big foot (level 3 attack) 30 damage." << endl;
    return 30;
}
int Bigfoot::Attack_special()
{
    cout << "SPECIAL ATTACK!!! YOU TRIED TO GET A PICTURE OF BIGFOOT BUT IT CAME OUT GRAINY, Now you feel stupid ,50 DAMAGE Worth of stupid!!!!." << endl;
    return 50;
}
int Bigfoot::defense1()
{
    cout << "You found some berries and shrubs in the woods (Defense booster 1) +15 health " << endl;
    return 15;
}
int Bigfoot::defense2()
{
    cout << "You found magic mushrooms, bigfoot feels great (Defense booster 2) +20 health " << endl;
    return 20;
}
int Bigfoot::defense3()
{
    cout << "Finally something useful you got a pain vaccine (Defense booster 3) +50 health" << endl;
    return 50;
}
Bigfoot::~Bigfoot(){}
//--------------------------------------------------Chupacabra Functions--------------------------------------------------------
Chupacabra::Chupacabra()
{
    char name[] = "Chupacabra";
    change_nme(name);
    change_health(100);
    change_armour(100);
    change_weakness(1);
}
Chupacabra::Chupacabra(const Monster &copy) : Monster(copy){}
int Chupacabra::Attack1()
{
    cout << "El Chupacabra bit your pinky finger and it hurt more than you expected(level 1 attack) 15 damage." << endl;
    return 15;
}
int Chupacabra::Attack2()
{
    cout << "Chupacabra made a deal with diablo and now your hair is on fire(level 2 attack) 25 damage." << endl;
    return 25;
}
int Chupacabra::Attack3()
{
    cout << "Chupacabra hath taketh your dignity (level 3 attack)30 damage." << endl;
    return 30;
}
int Chupacabra::Attack_special()
{
    cout << "SPECIAL ATTACK!!! ,CHUPACABRA CRAWLS UP YOUR ORAFACE AND SCRATCHES YOUR INTESTINES, SO MUCH DAMAGE 50 DAMAGE!!!!." << endl;
    return 50;
}
int Chupacabra::defense1()
{
    cout << "You found some rabbit food. Which is a cousin of a Chupacabra (Defense booster 1) +15 health " << endl;
    return 15;
}
int Chupacabra::defense2()
{
    cout << "You collected Hydroxochloriquine (Defense booster 2) +20 health " << endl;
    return 20;
}
int Chupacabra::defense3()
{
    cout << "Finally something useful you got a pain vaccine (Defense booster 3) +50 health" << endl;
    return 50;
}
Chupacabra::~Chupacabra(){}
//--------------------------------------------------Abominable_Snowman Functions--------------------------------------------------------
Abominable_Snowman::Abominable_Snowman()
{
    char name[] = "Abominable_Snowman";
    change_nme(name);
    change_health(100);
    change_armour(100);
    change_weakness(0);
}
Abominable_Snowman::Abominable_Snowman(const Monster & copy) : Monster(copy){}
int Abominable_Snowman::Attack1()
{
    cout << "Abominable Snowman hit you with a snowball(level 1 attack) 15 damage." << endl;
    return 15;
}
int Abominable_Snowman::Attack2()
{
    cout << "Abominable Snowman white washed you, ouch(level 2 attack) 25 damage." << endl;
    return 25;
}
int Abominable_Snowman::Attack3()
{
    cout << "Abominable Snowman never called you back. (level 3 attack)30 damage." << endl;
    return 30;
}
int Abominable_Snowman::Attack_special()
{
    cout << "SPECIAL ATTACK!!! SUPER COLD ICEY BREATH, SO MUCH DAMAGE 50 DAMAGE!!!!." << endl;
    return 50;
}
int Abominable_Snowman::defense1()
{
    cout << "A nice cold avalanche (Defense booster 1) +15 health " << endl;
    return 15;
}
int Abominable_Snowman::defense2()
{
    cout << "Cracking open a cold one with the boys (Defense booster 2) +20 health " << endl;
    return 20;
}
int Abominable_Snowman::defense3()
{
    cout << "Finally something useful you got a pain vaccine (Defense booster 3) +50 health" << endl;
    return 50;
}
Abominable_Snowman::~Abominable_Snowman(){}
//--------------------------------------------------ARR Node functions-----------------------------------------------------------
ARRNode::ARRNode()
{
    pick = 0;
    next = NULL;
    prev = NULL;
}

ARRNode::ARRNode(int value)
{
    pick = value;
    next = NULL;
    prev = NULL;
}
ARRNode*& ARRNode::get_prev()
{
    return prev;
}
ARRNode*& ARRNode::get_next()
{
    return next;
}
int ARRNode::get_pick()
{
    return pick;
}
void ARRNode::set_next(ARRNode * connect)
{
    next = connect;
}
void ARRNode::set_prev(ARRNode * connect)
{
    prev = connect;
}
ARRNode::~ARRNode()
{
    next = NULL;
    prev = NULL;
}
//--------------------------------------------------ARR functions-----------------------------------------------------------
ARR::ARR()
{
    head = new ARRNode*[SIZE]; // creating an array of Node ptrs. It Will always be of size (2)
    for(int i = 0; i<SIZE; ++i)
    {
        head[i] = NULL;
    }
}
//This array represents my attacks/defenses they correspond to different integers
//array[0] is my attacks, array[1] is my defenses
void ARR::insert_node(int value, int index)
{
    if(!head[index])
    {
        head[index] = new ARRNode(value);
        //head[index]->set_prev(NULL);
        //head[index]->set_next(NULL);
        return;
    }
    ARRNode * temp = new ARRNode(value);
    //temp->set_prev(NULL);
    temp->set_next(head[index]);
    head[index]->set_prev(temp);
    head[index]= temp;
    return;
}
void ARR::delete_all(ARRNode *current)
{
    if(!current)
        return ;
    delete_all(current->get_next());
    delete current;
    return;
}
int ARR::find_number(ARRNode * current, int num)
{
    for(int i = 0; i < num; ++i)
        current = current->get_next();
    return current->get_pick();
}
int ARR::get_attack()
{
    srand(time(NULL));//seed aat random
    int num = rand() % 19;//pick a number from 0-19
    ARRNode * temp= head[0];
    int send = find_number(temp,num);//we traverse the list num amount of times
    return send;//we return the number at that node
}
int ARR::get_defense()
{
    srand(time(NULL));//seed aat random
    int num = rand() % 19;//pick a number from 0-19
    ARRNode * temp= head[1];
    int send = find_number(temp,num);//we traverse the list num amount of times
    return send;//we return the number at that node
}
//TODO Double check this
ARR::~ARR()
{
    for(int i(0); i < SIZE; ++i)
    {
        if(head[i])
        {
            delete_all(head[i]);
            head[i] = NULL;
        }
    }
    delete [] head;
    head = NULL;
}

