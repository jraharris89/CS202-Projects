/* Jonathon Harris - Project 2 - user_imp.cpp is my implementation file for user.h. We have our function definitions
 * associated with Account, Acct_node, and user_list in this file.
 */
#include "user.h"
// ------------------------------------------------------User Functions------------------------------------
//default constructor
User::User()
{
    name = NULL;
}
//parameterized constructor
User::User(char * nme)
{
    if(nme)
    {
        name = new char[strlen(nme)+1];
        strcpy(name,nme);
    }
    else
        name = NULL;
}
//Copy constructor for user
User::User(const User &copy)
{
    if(copy.name)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    else
        name = NULL;
}
//getter for name
char * User::get_name()
{
    return name;
}
//compares name that was passed in by user to name of this user;
bool User::compare_name(char * nme) const
{
    if(!nme)
        return false;
    if(!name)
        return false;
    if(strcmp(name, nme) == 0)
        return true;
    else
        return false;
}
//displays a single name
int User::display_name() const
{
    cout << "Username: " << name << endl;
    return 1;
}
//destructor for User
User::~User()
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}
// ------------------------------------------------------User_node Functions------------------------------------
// default constructor
User_node::User_node()
{
    head = NULL;
    next = NULL;
}
//User_node copy constructor
User_node::User_node(const User_node &copy) : User(copy)
{
    head = NULL;
    next = NULL;
}
//parameterized constructor
User_node::User_node(char * username) : User(username)
{
    head = NULL;
    next= NULL;
}

//User_node getter for next pointer
User_node *& User_node::get_next()
{
    return next;
}
//User_node getter for Acct_node * head
Acct_node *& User_node::get_head()
{
    return head;
}
//User_node set next pointer
void User_node::set_next(User_node * connect)
{
    next = connect;
}
//User_node set head pointer
void User_node::set_head(Acct_node * connect)
{
    head = connect;
}
//adding account is a multistep process, we have to find the user first
//then call apon this function to add it to an existing user. 

int User_node::add_slack_account()
{
    if(!head)//create new node at the beginning
    {
        head = new Acct_node;
        head->set_next(NULL);
        head->set_slack();
        return 1;
    }
    else//add to beginning
    {
        Acct_node * temp = new Acct_node;
        //temp->next = head
        temp->set_next(head);
        temp->set_slack();
        head = temp;
        return 1;
    }
}
//adding account is a multistep process, we have to find the user first
//then call apon this function to add it to an existing user. 

int User_node::add_email_account()
{
    if(!head)//create new node at the beginning
    {
        head = new Acct_node;
        head->set_next(NULL);
        head->set_email();
        return 1;
    }
    else//add to beginning
    {
        Acct_node * temp = new Acct_node;
        //temp->next = head
        temp->set_next(head);
        temp->set_email();
        head = temp;
        return 1;
    }
}
//adding account is a multistep process, we have to find the user first
//then call apon this function to add it to an existing user. 

int User_node::add_discord_account()
{
    if(!head)//create new node at the beginning
    {
        head = new Acct_node;
        head->set_next(NULL);
        head->set_discord();
        return 1;
    }
    else//add to beginning
    {
        Acct_node * temp = new Acct_node;
        //temp->next = head
        temp->set_next(head);
        temp->set_discord();
        head = temp;
        return 1;
    }
}
//Add account to our User_node list
//passing in what we want to copy so we can insert it using copy constructor
int User_node::add_account(Acct_node &to_add)
{
    if(!head)//create new node at the beginning
    {
        head = new Acct_node(to_add);
        head->set_next(NULL);
        return 1;
    }
    else//add to beginning
    {
        Acct_node * temp = new Acct_node(to_add);
        //temp->next = head
        temp->set_next(head);
        head = temp;
        return 1;
    }
}
//Wrapper function to remove all accounts associated with a particular user
int User_node::remove_all_accounts()
{
    if(!head)
        return 0;
    return remove_all_accounts(head);
}
//function to remove all accounts associated with a particular user, return how many accounts removed
int User_node::remove_all_accounts(Acct_node *&head)
{
    int count(0);
    if(!head)
        return 0;
    ++count + remove_all_accounts(head->get_next());
        delete head;
        head = NULL;
        return count;
}
//Wrapper for inserting message within a user_node
bool User_node::insert_email_message(Message &to_send, char * to_find)
{
    return insert_email_message(to_send,to_find,head);
}
//Wrapper for inserting message within a user_node
bool User_node::insert_discord_message(Message &to_send, char * to_find)
{
    return insert_discord_message(to_send,to_find,head);
}
//Wrapper for inserting message within a user_node
bool User_node::insert_slack_message(Message &to_send, char * to_find)
{
    return insert_slack_message(to_send,to_find,head);
}
//Wrapper for removing a message within a user_node
bool User_node::remove_email_message(char * subject)
{
    return remove_email_message(subject,head);
}
//Wrapper for removing a message within a user_node
bool User_node::remove_discord_message(char * subject)
{
    return remove_discord_message(subject,head);
}
//Wrapper for removing a message within a user_node
bool User_node::remove_slack_message(char * subject)
{
    return remove_slack_message(subject,head);
}
//Wrapper for removing a message within a user_node
int User_node::remove_all_emailmsgs()
{
    return remove_all_emailmsgs(head);
}
//Wrapper for removing a message within a user_node
int User_node::remove_all_slackmsgs()
{
    return remove_all_slackmsgs(head);
}
//Wrapper for removing a message within a user_node
int User_node::remove_all_discordmsgs()
{
    return remove_all_discordmsgs(head);
}
//We check to see what Account * ABC we are pointing to using RTTI
int User_node::remove_all_emailmsgs(Acct_node *&head)
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Email * ptr = dynamic_cast<Email *>(temp);
    if(ptr)
    {
        int count = ptr->remove_all_msgs();
        return count;
    }
    else
        return remove_all_emailmsgs(head->get_next());
}
//We check to see what Account * ABC we are pointing to using RTTI
int User_node::remove_all_slackmsgs(Acct_node *&head)
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Slack* ptr = dynamic_cast<Slack *>(temp);
    if(ptr)
    {
        int count = ptr->remove_all_msgs();
        return count;
    }
    else
        return remove_all_slackmsgs(head->get_next());
}
//We check to see what Account * ABC we are pointing to using RTTI
int User_node::remove_all_discordmsgs(Acct_node *&head)
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Discord * ptr = dynamic_cast<Discord *>(temp);
    if(ptr)
    {
        int count = ptr->remove_all_msgs();
        return count;
    }
    else
        return remove_all_discordmsgs(head->get_next());
}
//THIS FUNCTION CAN BE USED WITH ADD_MSG AND SEND_MSG
//We check to see what Account * ABC we are pointing to using RTTI
bool User_node::insert_email_message(Message &to_send, char * to_find, Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Email * ptr = dynamic_cast<Email *>(temp);
    if(ptr)
    {
        ptr->send_msg(to_send);
        return true;
    }
    else
        return insert_email_message(to_send,to_find,head->get_next());
}
//THIS FUNCTION CAN BE USED WITH ADD_MSG AND SEND_MSG
//We check to see what Account * ABC we are pointing to using RTTI
bool User_node::insert_discord_message(Message &to_send, char * to_find, Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Discord * ptr = dynamic_cast<Discord *>(temp);
    if(ptr)
    {
        ptr->send_msg(to_send);
        return true;
    }
    else
        return insert_discord_message(to_send,to_find,head->get_next());
}
//THIS FUNCTION CAN BE USED WITH ADD_MSG AND SEND_MSG
//We check to see what Account * ABC we are pointing to using RTTI
bool User_node::insert_slack_message(Message &to_send, char * to_find, Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Slack * ptr = dynamic_cast<Slack *>(temp);
    if(ptr)
    { 
        ptr->send_msg(to_send);
        return true;
    }
    else
        return insert_slack_message(to_send,to_find,head->get_next());
}
//GOES THROUGH OUR USER_NODES AND CHECKS TO SEE IF THE ABC* MATCHES
bool User_node::remove_email_message(char * subject,Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Email * ptr = dynamic_cast<Email *>(temp);
    if(ptr)
    {
        ptr->remove_msg(subject);
        return true;
    }
    else
        return remove_email_message(subject,head->get_next());
}
//GOES THROUGH OUR USER_NODES AND CHECKS TO SEE IF THE ABC* MATCHES
bool User_node::remove_discord_message(char * subject,Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Discord * ptr = dynamic_cast<Discord *>(temp);
    if(ptr)
    {
        ptr->remove_msg(subject);
        return true;
    }
    else
        return remove_discord_message(subject,head->get_next());
}
//GOES THROUGH OUR USER_NODES AND CHECKS TO SEE IF THE ABC* MATCHES
bool User_node::remove_slack_message(char * subject,Acct_node *&head)
{
    if(!head)
        return false;
    Account * temp = head->get_account();
    Slack * ptr = dynamic_cast<Slack*>(temp);
    if(ptr)
    {
        ptr->remove_msg(subject);
        return true;
    }
    else
        return remove_slack_message(subject,head->get_next());
}
//wrapper for my view discord message function
int User_node::view_discord_messages() 
{
    return view_discord_messages(head);
}
//We have found the user that matches now we need to check the account to see
//if its a discord account, if it is then we call discords read_all_msgs function
//otherwise we move to the next account and repeat.
int User_node::view_discord_messages(Acct_node *head) 
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Discord * ptr = dynamic_cast<Discord*>(temp);
    if(ptr)
    {
        int count = ptr->read_all_msgs();
        return count;
    }
    else
        return view_discord_messages(head->get_next());
}
//wrapper for my view slack message function
int User_node::view_slack_messages() 
{
    return view_slack_messages(head);
}
//We have found the user that matches now we need to check the account to see
//if its a slack account, if it is then we call slack read_all_msgs function
//otherwise we move to the next account and repeat.
int User_node::view_slack_messages(Acct_node *head) 
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Slack * ptr = dynamic_cast<Slack*>(temp);
    if(ptr)
    {
        int count = ptr->read_all_msgs();
        return count;
    }
    else
        return view_slack_messages(head->get_next());
}
//wrapper for my view email message function
int User_node::view_email_messages() 
{
    return view_email_messages(head);
}
//We have found the user that matches now we need to check the account to see
//if its a email account, if it is then we call email read_all_msgs function
//otherwise we move to the next account and repeat.
int User_node::view_email_messages(Acct_node *head) 
{
    if(!head)
        return 0;
    Account * temp = head->get_account();
    Email * ptr = dynamic_cast<Email*>(temp);
    if(ptr)
    {
        int count = ptr->read_all_msgs();
        return count;
    }
    else
        return view_email_messages(head->get_next());
}
//destructor for user_node
User_node::~User_node()
{
    remove_all_accounts();
    next = NULL;
}
// ------------------------------------------------------User_list Functions------------------------------------
// Default constructor
User_list::User_list()
{
    head = NULL;
}
//wrapper for find_user pass in what username we are looking for
User_node * User_list::find_user(char * username)
{
    return find_user(head,username);
}
//finds the user we are looking for returns its location
User_node * User_list::find_user(User_node *current,char * username)
{
    if(!current)
        return NULL;
    if(current->compare_name(username))
        return current;
    else
        return find_user(current->get_next(),username);
}
//viewing account is a multistep process, we have to find the user first
//then call apon User_nodes view discord function
int User_list::view_discord_messages(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->view_discord_messages();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//viewing account is a multistep process, we have to find the user first
//then call apon User_nodes view email function
int User_list::view_email_messages(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->view_email_messages();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//viewing account is a multistep process, we have to find the user first
//then call apon User_nodes view slack function
int User_list::view_slack_messages(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->view_slack_messages();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//adding account is a multistep process, we have to find the user first
//then call apon User_nodes add_discord function
int User_list::add_discord_account(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->add_discord_account();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//adding account is a multistep process, we have to find the user first
//then call apon User_nodes add_emailfunction
int User_list::add_email_account(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->add_email_account();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//adding account is a multistep process, we have to find the user first
//then call apon User_nodes add_slack function
int User_list::add_slack_account(char * username)
{
    if(!head)
    {
        cout << "No users found, please create a user then add an account to it." << endl;
        return 0;
    }
    User_node * temp = NULL;
    temp = find_user(username);
    if(temp)
    {
        int success = temp->add_slack_account();
        return success;
    }
    else
    {
        cout << "Couldn't find that user, program failed successfully.";
        return 0;
    }
}
//Find the user, once we are at their node then we call the other insert_email to add the message
//We can use this function for SEND MESSAGE and ADD_MESSAGE (just pass in current users name)
bool User_list::insert_email_message(Message &to_send, char* to_find)
{
    if(!to_find)
        return false;
    User_node * user_location =  NULL;
    user_location= find_user(to_find);// find the location of the user
    if(user_location)//if it exists
    {
        return user_location->insert_email_message(to_send, to_find);
    }
    else
        return false;
}
//Find the user, once we are at their node then we call the other insert_email to add the message
//We can use this function for SEND MESSAGE and ADD_MESSAGE (just pass in current users name)
bool User_list::insert_discord_message(Message &to_send, char* to_find)
{
    if(!to_find)
        return false;
    User_node * user_location =  NULL;
    user_location= find_user(to_find);// find the location of the user
    if(user_location)//if it exists
    {
        return user_location->insert_discord_message(to_send, to_find);
    }
    else
        return false;
}
//Find the user, once we are at their node then we call the other insert_email to add the message
//We can use this function for SEND MESSAGE and ADD_MESSAGE (just pass in current users name)
bool User_list::insert_slack_message(Message &to_send, char* to_find)
{
    if(!to_find)
        return false;
    User_node * user_location =  NULL;
    user_location= find_user(to_find);// find the location of the user
    if(user_location)//if it exists
    {
        return user_location->insert_slack_message(to_send, to_find);
    }
    else
        return false;
}
int User_list::insert_user(User_node *to_add)
{
    //No list, create node set
    if(!head)
    {
        head = new User_node(*to_add);
        head->set_next(NULL);
        return 1;
    }
    //>1 node, attach to front.
    else
    {
        User_node * temp  = new User_node(*to_add);
        //temp->next = head
        temp->set_next(head);
        this->head = temp;
        return 1;
    }
}
//This function finds the user that client enters then calls a remove function for User_node
bool User_list::remove_email_message(char * username, char * subject)
{
    if(!username || !subject)
        return false;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_email_message(subject);
    else
        return false;
}
//This function finds the user that client enters then calls a remove function for User_node
bool User_list::remove_discord_message(char * username, char * subject)
{
    if(!username || !subject)
        return false;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_discord_message(subject);
    else
        return false;
}
//This function finds the user that client enters then calls a remove function for User_node
bool User_list::remove_slack_message(char * username, char * subject)
{
    if(!username || !subject)
        return false;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_slack_message(subject);
    else
        return false;
}
//This function finds the user that client enters then calls a remove function for User_node
int User_list::remove_all_emailmsgs(char * username)
{
    if(!username)
        return 0;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_email_message(username);
    else
        return 0;
}
//This function finds the user that client enters then calls a remove function for User_node
int User_list::remove_all_slackmsgs(char * username)
{
    if(!username)
        return 0;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_slack_message(username);
    else
        return 0;
}
//This function finds the user that client enters then calls a remove function for User_node
int User_list::remove_all_discordmsgs(char * username)
{
    if(!username)
        return 0;
    User_node * user_location = NULL;
    user_location = find_user(username);
    if(user_location)
        return user_location->remove_discord_message(username);
    else
        return 0;
}

//Removes a user from the User_list WRAPPER FUNCTION
int User_list::remove_user(char * user)
{
    User_node * prev = head;
    return remove_user(head,prev, user);
}
//Removes a user from the User_list, check if it is matching
//if it is check if its at the head of our list, otherwise delete from middle/end
int User_list::remove_user(User_node *&current,User_node *&prev, char * user)
{
    if(!current)
        return 0;
    if(strcmp(current->get_name(), user) == 0)
    {
        //delete first node
        if(current == this->head)
        {
            User_node * temp = current;
            //head = head->next
            current = current ->get_next();
            temp->remove_all_accounts();//remove the accounts associated with this user TODO DOUBLE CHECK THIS
            delete temp;
            return 1;
        }
        //delete from middle or end
        else
        {
            //prev->next = current->next
            User_node * temp = current->get_next();
            current->remove_all_accounts();//remove the accounts for this user TODO DOUBLE CHECK THIS
            delete current;
            current = temp;
            return 1 + remove_user(current,current,user);
        }
    }
    else
        return remove_user(current->get_next(),current,user);
}
//Displays all the users in our User_list WRAPPER
int User_list::display_all_users() const
{
    if(!head)
        return 0;
    return display_all_users(head);
}
//Displays all the users in our User_list, return count back to client
int User_list::display_all_users(User_node *head) const
{
    int count = 0;

    if(!head)
        return count;
    else
    {
        head->display_name();
        count += 1 + display_all_users(head->get_next());
    }
    return count;
}
//retrieve wrapper function for user nodes, name is what we're looking for, create new list
int User_list::retrieve(char *name, User_list &newList)
{
    if(!head)
        return 0;
    return retrieve(name, newList, head);
}
//retrieve by username, create new list, return how many copied over
int User_list::retrieve(char * name, User_list &newList, User_node *current)
{
    int count(0);

    if(!current)
        return 0;
    if(current->compare_name(name))
    {
        ++count;
        newList.insert_user(current);
    }
    return count + retrieve(name,newList,current->get_next());
}
//DELETE ALL USERS AND ACCOUNTS, Mostly used for the User_list destructor
int User_list::remove_all_users()
{
    if(!head)
        return 0;
    return remove_all_users(head);
}
//Removes every thing from our list (users and accounts)
int User_list::remove_all_users(User_node *&head)
{
    int count(0);
    if(!head)
        return 0;
    if(head)
    {
        ++count;
        User_node * temp = head;
        //head = head->next
        head = head->get_next();
        temp->remove_all_accounts();
        delete temp;
        return count;
    }
    return count + remove_all_users(head->get_next());
}
//User_list destructor, deletes all the users, when we remove one user it will 
//delete the accounts for that user before removing the user itself
User_list::~User_list()
{
    if(head)
        remove_all_users();
}
//clear screen with newlines
void User_list::clear()
{
    for(int i = 0; i < 250; ++i )
        cout << '\n';
}
//menu for main
void User_list::menu(int &user_in)
{
    cout << '\n';
    cout << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl << endl
        << "Please select from the following options: " <<endl
        << "1. Add user" << endl
        << "2. Display all users" << endl
        << "3. Remove user" << endl
        << "4. Retrieve user" << endl
        << "5. Add discord account to an existing user. " << endl
        << "6. Add email account to an existing user. " << endl
        << "7. Add slack account to an existing user. " << endl
        << "8. Add discord message. " << endl
        << "9. Add Email message. " << endl
        << "10. Add Slack message. " << endl
        << "11. Display all discord messages." << endl
        << "12. Display all email messages." << endl
        << "13. Display all slack messages." << endl
        << "14. Remove a Discord message." << endl
        << "15. Remove an Email message." << endl
        << "16. Remove a Slack message." << endl
        << "17. Remove all Discord messages." << endl
        << "18. Remove all Email messages." << endl
        << "19. Remove all Slack messages." << endl
        << "20. Quit Program ." << endl
        << "----------------------------------------- " << endl
        << "----------------------------------------- " << endl;
    cin >> user_in;
    cin.ignore(100, '\n');
    if(user_in <= 0 || user_in > 20)
    {
        cout << "--------Select a Valid option.---------- " << endl
            << "----------------------------------------- " << endl << endl
            << "Please select from the following options: " <<endl
            << "1. Add user" << endl
            << "2. Display all users" << endl
            << "3. Remove user" << endl
            << "4. Retrieve user" << endl
            << "5. Add discord account to an existing user. " << endl
            << "6. Add email account to an existing user. " << endl
            << "7. Add slack account to an existing user. " << endl
            << "8. Add discord message. " << endl
            << "9. Add Email message. " << endl
            << "10. Add Slack message. " << endl
            << "11. Display all discord messages." << endl
            << "12. Display all email messages." << endl
            << "13. Display all slack messages." << endl
            << "14. Remove a Discord message." << endl
            << "15. Remove an Email message." << endl
            << "16. Remove a Slack message." << endl
            << "17. Remove all Discord messages." << endl
            << "18. Remove all Email messages." << endl
            << "19. Remove all Slack messages." << endl
            << "20. Quit Program ." << endl
            << "----------------------------------------- " << endl
            << "----------------------------------------- " << endl;
    }

}                   


// ------------------------------------------------------Acct_node Functions------------------------------------
// Default constructor for account node
Acct_node::Acct_node()
{
    next = NULL;
}
//Account node getter
Acct_node *& Acct_node::get_next()
{
    return next;
}
Account *& Acct_node::get_account()
{
    return myAcct;
}
//Account node setter
void Acct_node::set_next(Acct_node * connect)
{
    next = connect;
}
//Sets myAcct ABC pointer to a discord derived object
void Acct_node::set_discord()
{
    myAcct = new Discord;
}
//Sets myAcct ABC pointer to a email derived object
void Acct_node::set_email()
{
    myAcct = new Email;
}
//Sets myAcct ABC pointer to a slack derived object
void Acct_node::set_slack()
{
    myAcct = new Slack;
}
//TODO Make sure this is correct
Acct_node::Acct_node(const Acct_node &copy)
{
    if(copy.myAcct)
        myAcct = copy.myAcct;
    next = NULL;
}
// Default destructor for account node
Acct_node::~Acct_node()
{
    if(myAcct)
        delete myAcct;
    next = NULL;
}

