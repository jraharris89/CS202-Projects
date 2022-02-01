/* Jonathon Harris- Project 1 Relief Catalogue - CS202
 * class.h has my base class along with the first set of children which 
 * are the relief types.
 */
#ifndef CLASS_H
#define CLASS_H
using namespace std;

//SUPERCLASS
class Info
{
    public: 
        Info(); //default constructor
        Info(char *nme, int quan);//parameterized constructor
        Info(const Info & copy_from);//copy constructor
        bool compare_name(char *nme);//compares name
        int Info_display() const;
        ~Info();//destructor

    private:
        char * name;
        int quantity;
};
//Food is a derived class of info
class Food : public Info
{
    public:
        Food();//default constructor
        Food(char *nme, int quan,char * expir, char *allerg);//parameterized constructor
        Food(const Food & copy_from);//copy constructor
        int food_display() const;
        ~Food();//Destructor

    private:
        char *expiration;
        char *allergies;
};
//Clothing is a derived class of info
class Clothing : public Info
{
    public:
        Clothing();//default constructor
        Clothing(char *nme, int quan,char * sze, char *sx);//parameterized constructor
        Clothing(const Clothing & copy_from);//copy constructor
        int clothing_display() const;
        ~Clothing();//Destructor

    private:
        char *size;
        char *sex;
        
};
//Shelter is a derived class of info
class Shelter : public Info
{
    public:
        Shelter();//default constructor
        Shelter(char *nme, int quan,char * duration, bool bath, bool pets);//parameterized constructor
        Shelter(const Shelter &copy_from);//copy constructor
        int shelter_display() const;
        ~Shelter();//Destructor

    private:
        char *duration;
        bool bathroom;
        bool pets_allowed;
};
#endif


        
