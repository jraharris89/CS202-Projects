/* Jonathon Harris - Project 3 - Monster Bash
 * 
 * For this project I preloaded the tree with one of each 
 * monster, then the Array of DLL's is preloaded with
 * attacks and defenses. The user picks player 1 and 
 * Player 2. Then the battle continues until one of the players
 * health <= 0.
 */
#include "string.h"
#include "RedBlackTree.h"


int main()
{
    //This is for the timer delay
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;

    String value = NULL;
    int user_input= 0;//For menu options
    int user_choice= 0;//For choosing players
    char name_dragon[] = "Dragon";//pass into find_monster
    char name_Bigfoot[] = "Bigfoot";//pass into find_monster
    char name_Chupcabra[] = "Chupacabra";//pass into find_monster
    char name_Abomin[] = "Abominable_Snowman";//pass into find_monster
    ARR myArray;//ARR of DLL for attack/defenses
    Tree newTree;
    Monster * Player1;//Holds address of Monster * player 1
    Monster * Player2;//Holds address of Monster * player 2
    newTree.clear();
    //My monster objects
    //Preload my tree with one of each monster
    newTree.insert_monster(1);//insert dragon
    newTree.insert_monster(2);//insert Bigfoot
    newTree.insert_monster(3);//insert Chupcabra
    newTree.insert_monster(4);//insert Abomin_Snowman
    //This loads up an array DLL with random numbers (1-7)
    //These numbers represent attacks which is on 
    //array[0] index and defenses which is on Array[1] index
    srand(time(NULL));
    int i = 0;
    while(i<20)
    {
        int num = rand() % 4 + 1; // from 1 - 4
        myArray.insert_node(num, 0);
        int num2 = rand() % 4 + 1; // from 1 - 4
        myArray.insert_node(num2, 1);
        ++i;
    }
    //Client chooses which player 1 they want 
    cout <<"Choose player 1 for battle: " << endl
        <<"1. Dragon" << endl
        <<"2. Bigfoot" << endl
        <<"3. Chupacabra" << endl
        <<"4. Abominable Snowman" << endl << endl;
    cin >> user_choice;
    cin.ignore();
    //Go find that monster in our tree
    if(user_choice == 1)
        Player1 = newTree.find_monster(name_dragon);
    else if(user_choice == 2)
        Player1 = newTree.find_monster(name_Bigfoot);
    else if(user_choice == 3)
        Player1 = newTree.find_monster(name_Chupcabra);
    else if(user_choice == 4)
        Player1 = newTree.find_monster(name_Abomin);
    else 
        cout << "Couldn't find your monster." << endl;
    
    //Client chooses which player 2 they want 
    cout <<"Choose a different player for player 2: " << endl
        <<"1. Dragon" << endl
        <<"2. Bigfoot" << endl
        <<"3. Chupacabra" << endl
        <<"4. Abominable Snowman" << endl << endl;
    cin >> user_choice;
    cin.ignore();
    //go find that monster in the tree
    if(user_choice == 1)
        Player2 = newTree.find_monster(name_dragon);
    else if(user_choice == 2)
        Player2 = newTree.find_monster(name_Bigfoot);
    else if(user_choice == 3)
        Player2 = newTree.find_monster(name_Chupcabra);
    else if(user_choice == 4)
        Player2 = newTree.find_monster(name_Abomin);
    else 
        cout << "Couldn't find your monster." << endl;

    newTree.clear();//clear screen
    cout << Player1->return_name() << " VS " << Player2->return_name() << endl;
    while(Player1->return_health() > 0 || Player2->return_health() >0)
    {
        newTree.clear();//clear screen
        Player1->display_all();
        cout << '\n' << '\n';
        Player2->display_all();
        cout << Player1->return_name() << "'s turn." << endl;
        cout << "1. Attack " << endl
             << "2. Defend " << endl
             << "3. Quit" << endl;
        cin >> user_choice;
        cin.ignore();
        if(user_choice == 1)
        {
            int attackOption= myArray.get_attack();//Picks a random number from ARR
            if(attackOption== 1)//User chose attack
            {
                int damage  = Player1->Attack1();
                Player2->decrease_armour(Player2, damage);
            }
            else if(attackOption == 2)
            {
                int damage  = Player1->Attack2();
                Player2->decrease_armour(Player2, damage);
            }
            else if(attackOption == 3)
            {
                int damage  = Player1->Attack3();
                Player2->decrease_armour(Player2, damage);
            }
            else if(attackOption == 4)
            {
                int damage  = Player1->Attack_special();
                Player2->decrease_armour(Player2, damage);
            }
            else
                cout << "Something went wrong when retrieving Attack. " << endl;
        }
        else if(user_choice == 2)//User chose defense
        {
            int defenseOption= myArray.get_attack();//Picks a random number from ARR
            if(defenseOption== 1)//User chose attack
            {
                int health  = Player1->defense1();
                Player1->increase_armour(Player1, health);
            }
            else if(defenseOption == 2)
            {
                int health  = Player1->defense2();
                Player1->increase_armour(Player1, health);
            }
            else if(defenseOption == 3)
            {
                int health  = Player1->defense3();
                Player1->increase_armour(Player1, health);
            }
            else if(defenseOption == 4)
            {
                int health  = Player1->defense3();
                Player1->increase_armour(Player1, health);
            }
            else 
                cout << "Something went wrong when retrieving defense. " << endl;


        }
        else if(user_choice == 3)
            return 0;
        else 
            cout << "Invalid option. Players turn gets skipped." << endl;

        cout << Player2->return_name() << "'s turn." << endl;
        cout << "1. Attack " << endl
             << "2. Defend " << endl
             << "3. Quit" << endl;
        cin >> user_choice;
        cin.ignore();
        if(user_choice == 1)
        {
            int attackOption= myArray.get_attack();//Picks a random number from ARR
            if(attackOption== 1)//User chose attack
            {
                int damage  = Player2->Attack1();
                Player1->decrease_armour(Player1, damage);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(attackOption == 2)
            {
                int damage  = Player2->Attack2();
                Player1->decrease_armour(Player1, damage);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(attackOption == 3)
            {
                int damage  = Player2->Attack3();
                Player1->decrease_armour(Player1, damage);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(attackOption == 4)
            {
                int damage  = Player2->Attack_special();
                Player1->decrease_armour(Player1, damage);
                sleep_until(system_clock::now() + 1.5s);
            }
            else
            {
                cout << "Something went wrong when retrieving Attack. " << endl;
                sleep_until(system_clock::now() + 1s);
            }
        }
        else if(user_choice == 2)//User chose defense
        {
            int defenseOption= myArray.get_defense();//Picks a random number from ARR
            if(defenseOption== 1)//User chose attack
            {
                int health  = Player2->defense1();
                Player2->increase_armour(Player2, health);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(defenseOption == 2)
            {
                int health  = Player2->defense2();
                Player2->increase_armour(Player2, health);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(defenseOption == 3)
            {
                int health  = Player2->defense3();
                Player2->increase_armour(Player2, health);
                sleep_until(system_clock::now() + 1.5s);
            }
            else if(defenseOption == 4)
            {
                int health  = Player2->defense3();
                Player2->increase_armour(Player2, health);
                sleep_until(system_clock::now() + 1.5s);
            }
            else 
                cout << "Something went wrong when retrieving defense. " << endl;
        }
        else if(user_choice == 3)
            return 0;
        else
            cout << "Not a valid option, Players turn gets skipped." << endl;
    }




/*
    do{
        newTree.menu(user_input);
        switch(user_input)
        {
            //INSERT NODE
            case 1: 
                {   
                    break;
                }
            case 2: 
                {
                    newTree.clear();
                    cout << "Enter the name of the monster to remove." << endl;
                    cin >> value;
                    cin.ignore();
                    newTree.delete_monster(value);
                    break;
                }
                //Preorder 
            case 3: 
                {
                    newTree.clear();
                    newTree.preorder();
                    break;
                }
                //Inorder 
            case 4: 
                {
                    newTree.clear();
                    newTree.inorder();
                    break;
                }

            case 5:
                {
                    return 0;
                }
        }
    }while(user_input >=1 || user_input <=5);
    //Filing up our array with random numbers that represent
    //attacks/defenses


       String var = "This is a string.";
       String cat = "How about now.";
       String abc = "abc";
       String def= "def";
       String plus = abc;
       plus += def;
       cin >> def;
       cout << def;

       if(abc < def)
       cout << "ABC IS LESS THAN" << endl;
       else
       cout << " < is not working." << endl;
       String concat = var + cat;
       cout << "VAR + CAT= " << concat << '\n';
       cout << " += abcdef " << plus<< '\n';
       */

    return 0;
}
