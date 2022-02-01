/* Jonathon Harris- Project 1 Releif catalogue - CS202
 * This cpp file contains my List functions implementation
 * and my menu. The list is responsible for 
 * managing my CLL's so the majority of functions will be here. */

#include "node.h"
List::List()
{
    f_rear = NULL;
    c_rear = NULL;
    s_rear = NULL;
}
// TODO Make sure this is correct
// List destructor calls each list destroy_all functions
List::~List()
{
    if(f_rear)
        destroy_fList();
    if(s_rear)
        destroy_sList();
    if(c_rear)
        destroy_cList();

}
//Wrapper for add_food node
int List::add_food_node(f_Node *to_add)
{
    return add_food_node(f_rear, to_add);
}
//Adds food nodes to our food CLL
//We always add to the end of our list so we didnt implement recursion
int List::add_food_node(f_Node *&f_rear, f_Node *to_add)
{

    if(!f_rear)
    {
        f_rear = new f_Node(*to_add);
        //rear->next = rear
        f_rear->set_next(f_rear);
        //f_rear->get_next()->set_next(f_rear);
        return 1;
    }
    else
    {

        f_Node * temp;
        //temp = rear->next
        temp = f_rear->get_next();
        //temp->set_next(f_rear->get_next());
        f_Node * newRear = new f_Node(*to_add);
        //rear->next = newRear;
        f_rear->set_next(newRear);
        //newRear->next = temp
        newRear->set_next(temp);
        f_rear = newRear;
        return 1;
    }
    return -1;
}
//Wrapper for add_food node
int List::add_clothing_node(c_Node *to_add)
{
    return add_clothing_node(c_rear, to_add);
}
//Adds clothing nodes to our clothing CLL
//We always add to the end of our list so we didnt implement recursion
int List::add_clothing_node(c_Node *&c_rear, c_Node *to_add)
{

    if(!c_rear)
    {
        c_rear = new c_Node(*to_add);
        //rear->next = rear
        c_rear->set_next(c_rear);
        //c_rear->get_next()->set_next(c_rear);
        return 1;
    }
    else
    {

        c_Node * temp;
        //temp = rear->next
        temp = c_rear->get_next();
        //temp->set_next(c_rear->get_next());
        c_Node * newRear = new c_Node(*to_add);
        //rear->next = newRear;
        c_rear->set_next(newRear);
        //newRear->next = temp
        newRear->set_next(temp);
        c_rear = newRear;
        return 1;
    }
    return -1;
}
//Wrapper for add_food node
int List::add_shelter_node(s_Node *to_add)
{
    return add_shelter_node(s_rear, to_add);
}
//Adds shelter nodes to our shelter CLL
//We always add to the end of our list so we didnt implement recursion
int List::add_shelter_node(s_Node *&s_rear, s_Node *to_add)
{

    if(!s_rear)
    {
        s_rear = new s_Node(*to_add);
        //rear->next = rear
        s_rear->set_next(s_rear);
        //s_rear->get_next()->set_next(s_rear);
        return 1;
    }
    else
    {

        s_Node * temp;
        //temp = rear->next
        temp = s_rear->get_next();
        //temp->set_next(s_rear->get_next());
        s_Node * newRear = new s_Node(*to_add);
        //rear->next = newRear;
        s_rear->set_next(newRear);
        //newRear->next = temp
        newRear->set_next(temp);
        s_rear = newRear;
        return 1;
    }
    return -1;
}
//Displays everything in our food list
int List::display_all_food() const
{
    if(!f_rear)
        return 0;
    int count = 0;
    count = display_all_food(f_rear->get_next());
    return count;
}
int List::display_all_food(f_Node *f_rear) const
{
    int count = 0;
    if(f_rear == this->f_rear)
    {
        ++count;
        f_rear->food_display();
        return count;
    }
    f_rear->food_display();
    count += 1 + display_all_food(f_rear->get_next());
    return count;
}
//Displays everything in our clothing list
int List::display_all_clothing() const
{
    if(!c_rear)
        return 0;
    int count = 0;
    count = display_all_clothing(c_rear->get_next());
    return count;
}
int List::display_all_clothing(c_Node *c_rear) const
{
    int count = 0;
    if(c_rear == this->c_rear)
    {
        ++count;
        c_rear->clothing_display();
        return count;
    }
    c_rear->clothing_display();
    count += 1 + display_all_clothing(c_rear->get_next());
    return count;
}
//Displays everything in our shelter list
int List::display_all_shelter() const
{
    if(!s_rear)
        return 0;
    int count = 0;
    count = display_all_shelter(s_rear->get_next());
    return count;
}
int List::display_all_shelter(s_Node *s_rear) const
{
    int count = 0;
    if(s_rear == this->s_rear)
    {
        ++count;
        s_rear->shelter_display();
        return count;
    }
    s_rear->shelter_display();
    count += 1 + display_all_shelter(s_rear->get_next());
    return count;
}

//Wrapper for remove food node passes in rear->next so we start
//at the begnning of the list, prev is used in the edge case that we 
//remove the last node and need to reconnect the rear
int List::remove_food_node(char * name)
{
    if(!f_rear)
        return 0;

    f_Node * prev = f_rear;

    return remove_food_node(f_rear->get_next(),prev,name);
}
//Deletes every name match found, returns count of deletions 
int List::remove_food_node(f_Node *& f_rear,f_Node *prev, char * name)
{
    int count = 0;
    if(f_rear == this->f_rear)
    {
        if(f_rear->compare_name(name))
        {
            ++count;
            f_Node * temp = f_rear;
            //rear = rear->next
            f_rear = f_rear->get_next();
            if(f_rear == this->f_rear)
            {
                delete this->f_rear;
                this->f_rear = NULL;
            }
            else
            {
//            f_rear->set_next(f_rear);
            //f_rear->set_next(f_rear->get_next());
            delete temp;
            this->f_rear = prev;
            }
        }
        return count;
    }
    if(f_rear->compare_name(name))
    {
        ++count;
        f_Node * temp = f_rear;
        //rear = rear->next
        f_rear = f_rear->get_next();
        delete temp;
        count += remove_food_node(f_rear,f_rear,name);
        return count;
    }
    return remove_food_node(f_rear->get_next(),f_rear,name);
}
int List::remove_clothing_node(char * name)
{
    if(!c_rear)
        return 0;

    c_Node * prev = c_rear;

    return remove_clothing_node(c_rear->get_next(),prev,name);
}
//Deletes every name match found, returns count of deletions 
int List::remove_clothing_node(c_Node *& c_rear,c_Node *prev, char * name)
{
    int count = 0;
    if(c_rear == this->c_rear)
    {
        if(c_rear->compare_name(name))
        {
            ++count;
            c_Node * temp = c_rear;
            //rear = rear->next
            c_rear = c_rear->get_next();
            if(c_rear == this->c_rear)
            {
                delete this->c_rear;
                this->c_rear = NULL;
            }
            else
            {
//            c_rear->set_next(c_rear);
            //c_rear->set_next(c_rear->get_next());
            delete temp;
            this->c_rear = prev;
            }
        }
        return count;
    }
    if(c_rear->compare_name(name))
    {
        ++count;
        c_Node * temp = c_rear;
        //rear = rear->next
        c_rear = c_rear->get_next();
        delete temp;
        count += remove_clothing_node(c_rear,c_rear,name);
        return count;
    }
    return remove_clothing_node(c_rear->get_next(),c_rear,name);
}
int List::remove_shelter_node(char * name)
{
    if(!s_rear)
        return 0;

    s_Node * prev = s_rear;

    return remove_shelter_node(s_rear->get_next(),prev,name);
}
//Deletes every name match found, returns count of deletions 
int List::remove_shelter_node(s_Node *& s_rear,s_Node *prev, char * name)
{
    int count = 0;
    if(s_rear == this->s_rear)
    {
        if(s_rear->compare_name(name))
        {
            ++count;
            s_Node * temp = s_rear;
            //rear = rear->next
            s_rear = s_rear->get_next();
            if(s_rear == this->s_rear)
            {
                delete this->s_rear;
                this->s_rear = NULL;
            }
            else
            {
//            s_rear->set_next(s_rear);
            //s_rear->set_next(s_rear->get_next());
            delete temp;
            this->s_rear = prev;
            }
        }
        return count;
    }
    if(s_rear->compare_name(name))
    {
        ++count;
        s_Node * temp = s_rear;
        //rear = rear->next
        s_rear = s_rear->get_next();
        delete temp;
        count += remove_shelter_node(s_rear,s_rear,name);
        return count;
    }
    return remove_shelter_node(s_rear->get_next(),s_rear,name);
}
//Search food wrapper, passes in rear->next so we start at the 
//beginning of our list, catches the count.
int List::search_food(char * name)const
{
    if(!f_rear)
        return 0;
    int count = search_food(f_rear->get_next(), name);
    return count;
}
//Searches for name matches in our list, displaying them as we go
//returns count of matches
int List::search_food(f_Node *f_rear, char * name) const
{
    int count =0;
    if(f_rear == this->f_rear)
    {
        if(f_rear->compare_name(name))
        {
            ++count;
            f_rear->food_display();
        }
        return count;
    }
    if(f_rear->compare_name(name))
    {
        ++count;
        f_rear->food_display();
    }
    count += search_food(f_rear->get_next(), name);
    return count;
}
//Search clothing wrapper, passes in rear->next so we start at the 
//beginning of our list, catches the count.
int List::search_clothing(char * name)const
{
    if(!c_rear)
        return 0;
    int count = search_clothing(c_rear->get_next(), name);
    return count;
}
//Searches for name matches in our list, displaying them as we go
//returns count of matches
int List::search_clothing(c_Node *c_rear, char * name) const
{
    int count =0;
    if(c_rear == this->c_rear)
    {
        if(c_rear->compare_name(name))
        {
            ++count;
            c_rear->clothing_display();
        }
        return count;
    }
    if(c_rear->compare_name(name))
    {
        ++count;
        c_rear->clothing_display();
    }
    count += search_clothing(c_rear->get_next(), name);
    return count;
}
//Search shelter wrapper, passes in rear->next so we start at the 
//beginning of our list, catches the count.
int List::search_shelter(char * name)const
{
    if(!s_rear)
        return 0;
    int count = search_shelter(s_rear->get_next(), name);
    return count;
}
//Searches for name matches in our list, displaying them as we go
//returns count of matches
int List::search_shelter(s_Node *s_rear, char * name) const
{
    int count =0;
    if(s_rear == this->s_rear)
    {
        if(s_rear->compare_name(name))
        {
            ++count;
            s_rear->shelter_display();
        }
        return count;
    }
    if(s_rear->compare_name(name))
    {
        ++count;
        s_rear->shelter_display();
    }
    count += search_shelter(s_rear->get_next(), name);
    return count;
}
//Food retrieve wrapper calls on rear->next pointer so we start 
//searching for matches at the beginning of the list

int List::food_retrieve(char *name,List &newList) const
{
    if(!f_rear)
        return 0;
    return food_retrieve(f_rear->get_next(),newList,name);
}

//Food retrieve creates a new list object, once we find a name that matches
//we use the add_food_node function to insert. Returns number of matches.
int List::food_retrieve(f_Node *f_rear, List &newList,  char * name) const
{
    int count = 0;
   if(f_rear == this->f_rear)
   {
       if(f_rear->compare_name(name))
       {    
           ++count;
           newList.add_food_node(f_rear);
       }
       return count;
   }
   if(f_rear->compare_name(name))
   {
       ++count;
       newList.add_food_node(f_rear);
   }
   count += food_retrieve(f_rear->get_next(), newList, name);
   return count;
}
//clothing retrieve wrapper calls on rear->next pointer so we start 
//searching for matches at the beginning of the list

int List::clothing_retrieve(char *name,List &newList) const
{
    if(!c_rear)
        return 0;
    return clothing_retrieve(c_rear->get_next(),newList,name);
}

//clothing retrieve creates a new list object, once we find a name that matches
//we use the add_clothing_node function to insert. Returns number of matches.
int List::clothing_retrieve(c_Node *c_rear, List &newList,  char * name) const
{
    int count = 0;
   if(c_rear == this->c_rear)
   {
       if(c_rear->compare_name(name))
       {    
           ++count;
           newList.add_clothing_node(c_rear);
       }
       return count;
   }
   if(c_rear->compare_name(name))
   {
       ++count;
       newList.add_clothing_node(c_rear);
   }
   count += clothing_retrieve(c_rear->get_next(), newList, name);
   return count;
}
//shelter retrieve wrapper calls on rear->next pointer so we start 
//searching for matches at the beginning of the list

int List::shelter_retrieve(char *name,List &newList) const
{
    if(!s_rear)
        return 0;
    return shelter_retrieve(s_rear->get_next(),newList,name);
}

//shelter retrieve creates a new list object, once we find a name that matches
//we use the add_shelter_node function to insert. Returns number of matches.
int List::shelter_retrieve(s_Node *s_rear, List &newList,  char * name) const
{
    int count = 0;
   if(s_rear == this->s_rear)
   {
       if(s_rear->compare_name(name))
       {    
           ++count;
           newList.add_shelter_node(s_rear);
       }
       return count;
   }
   if(s_rear->compare_name(name))
   {
       ++count;
       newList.add_shelter_node(s_rear);
   }
   count += shelter_retrieve(s_rear->get_next(), newList, name);
   return count;
}
//Destroy food list wrapper, it sets rear->next to NULL
//and sets a pointer to the front
int List::destroy_fList()
{
    if(!f_rear)
        return 0;
    int count = 0;
    f_Node * front = f_rear->get_next();
    this->f_rear->set_next(NULL);
    count = destroy_fList(front);
    this->f_rear = NULL; 
    return count;
} 
//Uses head recursion so we delete on our way back
//returns number of nodes deleted.
int List::destroy_fList(f_Node *&f_rear)
{
    if(!f_rear)
        return 0;
    int count = 0;
    count += 1 + destroy_fList(f_rear->get_next());
    delete f_rear;
    f_rear = NULL;
    return count;
}
//Destroy clothing list wrapper, it sets rear->next to NULL
//and sets a pointer to the front
int List::destroy_cList()
{
    if(!c_rear)
        return 0;
    int count = 0;
    c_Node * front = c_rear->get_next();
    this->c_rear->set_next(NULL);
    count = destroy_cList(front);
    this->c_rear = NULL; 
    return count;
} 
    
//Uses head recursion so we delete on our way back
//returns number of nodes deleted.
int List::destroy_cList(c_Node *&c_rear)
{
    if(!c_rear)
        return 0;
    int count = 0;
    count += 1 + destroy_cList(c_rear->get_next());
    delete c_rear;
    c_rear = NULL;
    return count;
}
//Destroy shelter list wrapper, it sets rear->next to NULL
//and sets a pointer to the front
int List::destroy_sList()
{
    if(!s_rear)
        return 0;
    int count = 0;
    s_Node * front = s_rear->get_next();
    this->s_rear->set_next(NULL);
    count = destroy_sList(front);
    this->s_rear = NULL; 
    return count;
} 
//Uses head recursion so we delete on our way back
//returns number of nodes deleted.
int List::destroy_sList(s_Node *&s_rear)
{
    if(!s_rear)
        return 0;
    int count = 0;
    count += 1 + destroy_sList(s_rear->get_next());
    delete s_rear;
    s_rear = NULL;
    return count;
}
//-------------------------------------------MENU------------------------------
void List::clear()
{
    for(int i = 0; i < 250; ++i )
        cout << '\n';
}
void List::menu(int &user_in)
{
    cout << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add a new food donation. " << endl
        << "2. Add a new clothing. " << endl
        << "3. Add a new shelter. " << endl
        << "4. Remove food donation." << endl
        << "5. Remove clothing donation." << endl
        << "6. Remove shelter donation." << endl
        << "7. Search food donations." << endl
        << "8. Search clothing donations." << endl
        << "9. Search shelter." << endl
        << "10. Retrieve all food name matches." <<endl
        << "11. Retrieve all clothing name matches." <<endl
        << "12. Retrieve all shelter name matches." <<endl
        << "13. Display all food. " <<endl
        << "14. Display all clothing. ." <<endl
        << "15. Display all shelter. " <<endl
        << "16. Erase all food." <<endl
        << "17. Erase all clothing." <<endl
        << "18. Erase all shelter." <<endl
        << "19. Display history for searches." <<endl
        << "20. Exit the program. " << endl << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl;
    cin >> user_in;
    cin.ignore(100, '\n');
    if(user_in <= 0 || user_in > 20)
    {
    cout << "--------Select a Valid option.---------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add a new food donation. " << endl
        << "2. Add a new clothing. " << endl
        << "3. Add a new shelter. " << endl
        << "4. Remove food donation." << endl
        << "5. Remove clothing donation." << endl
        << "6. Remove shelter donation." << endl
        << "7. Search food donations." << endl
        << "8. Search clothing donations." << endl
        << "9. Search shelter." << endl
        << "10. Retrieve all food matches." <<endl
        << "11. Retrieve all clothing matches." <<endl
        << "12. Retrieve all shelter matches." <<endl
        << "13. Display all food. " <<endl
        << "14. Display all clothing. ." <<endl
        << "15. Display all shelter. " <<endl
        << "16. Erase all food." <<endl
        << "17. Erase all clothing." <<endl
        << "18. Erase all shelter." <<endl
        << "19. Display history for searches." <<endl
        << "20. Exit the program. " << endl << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl;
    }

}

    

    






