/* Jonathon Harris- Project 1 Relief Catalogue - CS202
 * The purpose of this program is to create a relief catalogue for people who are in need.
 * Each relief type has its own circular linked list.
 * My inheritance looks like this Info->Food->f_node, Info->clothing->c_node, Info->shelter->s_node
 * My containment relationship is with List having 3 rear pointers. List manages all the lists. 
 *
 * DEBUGGING NOTES: When creating a object in main, in your add_function, do not create use "new" again
 * when deleting all nodes be sure to set this->rear = NULL so it updates the actual rear
 */

#include "node.h"

int main()
{
    List newList;
    List duplicateList;// for retrieve function
    History history_list;

    int user_input = 0;
    char item_name[100]= {};
    int quantity = 0;
    char food_expiration[100]={};
    char food_allergies[100]={};
    char sex[100]= {};
    char size[100]= {};
    char duration[100]= {};
    bool bath = false;
    bool pets= false;
    char read_in[100];//used to get answers for bathroom
    char read_in2[100];//used to get answers from pets

do{
    newList.menu(user_input);
    switch(user_input)
    {
        //ADD NEW FOOD
        case 1: 
            {   newList.clear();
                cout << "Enter the name of the food: " << endl;
                cin.get(item_name, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter the quantity: " << endl;
                cin >> quantity;
                cin.ignore(100,'\n');
                cout << "Enter the expiration date (ex Jan. 28, 2020): " << endl;
                cin.get(food_expiration, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter any allergies for " << item_name << ": " << endl;
                cin.get(food_allergies, 100, '\n');
                cin.ignore(100, '\n');
                f_Node new_food(item_name,quantity,food_expiration,food_allergies);
                newList.add_food_node(&new_food);
                newList.clear();
                break;
            }
            //ADD NEW CLOTHING
        case 2: 
            {   newList.clear();
                cout << "Enter the type of clothing: " << endl;
                cin.get(item_name, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter the quantity: " << endl;
                cin >> quantity;
                cin.ignore(100,'\n');
                cout << "Enter the size: " << endl;
                cin.get(size, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter sex for " << item_name << ": " << endl;
                cin.get(sex, 100, '\n');
                cin.ignore(100, '\n');
                c_Node new_clothing(item_name,quantity,size,sex);
                newList.add_clothing_node(&new_clothing);
                newList.clear();
                break;
            }
            //ADD NEW SHELTER 
        case 3: 
            {   newList.clear();
                cout << "Enter the type of shelter: " << endl;
                cin.get(item_name, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter the quantity of people allowed to stay: " << endl;
                cin >> quantity;
                cin.ignore(100,'\n');
                cout << "How long may they stay? " << endl;
                cin.get(duration, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Is there a bathroom? (yes/no):";
                cin.get(read_in, 100, '\n');
                cin.ignore(100, '\n');
                for(int i = 0; i <strlen(read_in); ++i)
                    putchar(toupper(read_in[i]));
                if(strcmp(read_in,"YES") == 0)
                    bath = true;
                else
                    bath = false;
                cout << "Are pets allowed? (yes/no): ";
                cin.get(read_in2, 100, '\n');
                cin.ignore(100, '\n');
                for(int i = 0; i <strlen(read_in2); ++i)
                    putchar(toupper(read_in2[i]));
                if(strcmp(read_in2,"YES") == 0)
                    pets = true;
                else
                    pets = false;
                s_Node new_shelter(item_name,quantity,duration,bath,pets);
                newList.add_shelter_node(&new_shelter);
                newList.clear();
                break;
            }
            //REMOVE FOOD ITEM
        case 4:
            {
                newList.clear();
                cout << "Enter the name of the food you want to remove: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.remove_food_node(item_name);
                cout << '\n' << item_name << " successfully removed." << endl;
                break;
            }
            //REMOVE CLOTHING ITEM
        case 5:
            {
                newList.clear();
                cout << "Enter the name of the clothing you want to remove: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.remove_clothing_node(item_name);
                cout << '\n' << item_name << " successfully removed." << endl;
                break;
            }
            //REMOVE SHELTER ITEM
        case 6:
            {
                newList.clear();
                cout << "Enter the name of the shelter you want to remove: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.remove_shelter_node(item_name);
                cout << '\n' << item_name << " successfully removed." << endl;
                break;
            }
            //SEARCH FOOD DONATIONS
        case 7: 
            {
                newList.clear();
                cout <<"Enter the name of the food you want to find: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                history_list.add_node(item_name);//add to history list
                newList.search_food(item_name);//search for food

                break;
            }
            //SEARCH clothing DONATIONS
        case 8: 
            {
                newList.clear();
                cout <<"Enter the name of the clothing you want to find: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                history_list.add_node(item_name);//add to history list
                newList.search_clothing(item_name);
                break;
            }
            //SEARCH SHELTER DONATIONS
        case 9: 
            {
                newList.clear();
                cout <<"Enter the name of the shelter you want to find: ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                history_list.add_node(item_name);//add to history list
                newList.search_shelter(item_name);
                break;
            }
            //RETRIEVE FOOD MATCHES, CREATES NEW LIST
        case 10: 
            {
                newList.clear();
                cout << "Enter food name to retrieve:  ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.food_retrieve(item_name,duplicateList);

                duplicateList.display_all_food();

                break;
            }
            //RETRIEVE CLOTHING MATCHES, CREATES NEW LIST
        case 11: 
            {
                newList.clear();
                cout << "Enter name of clothing to retrieve:  ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.clothing_retrieve(item_name,duplicateList);

                duplicateList.display_all_clothing();

                break;
            }
            //RETRIEVE SHELTER MATCHES, CREATES NEW LIST
        case 12: 
            {
                newList.clear();
                cout << "Enter shelter name to retrieve:  ";
                cin.get(item_name, 100, '\n');
                cin.ignore(100,'\n');
                newList.shelter_retrieve(item_name,duplicateList);

                duplicateList.display_all_shelter();

                break;
            }
            //DISPLAY ALL FOOD
        case 13: 
            {
                newList.clear();
                int count = newList.display_all_food();
                cout << '\n' <<  "Total food items: " << count << endl;
                break;
            }
            //DISPLAY ALL CLOTHING 
        case 14: 
            {
                newList.clear();
                int count = newList.display_all_clothing();
                cout << '\n' <<  "Total clothing items: " << count << endl;
                break;
            }
            //DISPLAY ALL SHELTER 
        case 15: 
            {
                newList.clear();
                int count = newList.display_all_shelter();
                cout << '\n' <<  "Total shelter items: " << count << endl;
                break;
            }
            //ERASE ALL FOOD ITEMS
        case 16:
            {
                newList.clear();
                int count = newList.destroy_fList();
                cout << '\n' <<  "Total food items removed: " << count << endl;
               break;
            }
            //ERASE ALL CLOTHING ITEMS
        case 17:
            {
                newList.clear();
                int count = newList.destroy_cList();
                cout << '\n' <<  "Total clothing items removed: " << count << endl;
               break;
            }
            //ERASE ALL SHELTER ITEMS
        case 18:
            {
                newList.clear();
                int count = newList.destroy_sList();
                cout << '\n' <<  "Total shelter items removed: " << count << endl;
               break;
            }
            //DISPLAY HISTORY LIST
        case 19:
            {
                newList.clear();
                int count = history_list.display_history();
                cout << '\n' <<  "Total items in history: " << count << endl;
               break;
            }
            //QUIT PROGRAM
        case 20:
            {
               // newList.destroy_fList();
                return 0;
            }

                
    }
}while(user_input>=1 || user_input <  20);

}
