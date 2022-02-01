/* Jonathon Harris - Project 2 - user.h - The way my program is setup is I have a LLL of User_nodes, Each User_node has an Acct_Node * head. 
 * The Acct_node head is the starting point to my LLL of Acct_nodes. Each Acct_node HAS AN Account Abstract base class pointer. From
 * there I set each one of those Pointers to represent either an email, discord or slack. Each email, discord, or slack contains a message in private section
 * The message has a next pointer, so essentially I have a LLL of users each user has a LLL of accounts each account is associated 
 * with a communication type and the communication type has a LLL of messages. 
 * I interpreted the intructions wrong and thought that sending a message meant to a different user in the program.
 * So I created a ton of more work than what was required, plz keep that in mind.
 */
#include "account.h" 
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#ifndef USER_H
#define USER_H
using namespace std;
//Account node HAS AN Account (Base class) ptr and has an Acct_node next pointer
class Acct_node 
{
    public: 
        Acct_node();
        Acct_node(const Acct_node &copy);//TODO Make sure this is good
        Acct_node *& get_next();
        Account *& get_account();
        void set_discord();//sets Account pointer to a discord obj 
        void set_email();//sets Account pointer to an email obj ;
        void set_slack();//sets Account pointer to a slack obj ;
        void set_next(Acct_node * connect);
        ~Acct_node();

    protected:
        class Account * myAcct;// MY ACCOUNT ABC  pointer
        Acct_node * next;//Next account

};
class User  
{
    public: 
        User();//default constructor
        User(char * name);//Parameterized constructor
        User(const User &copy);//cpy constructor
        bool compare_name(char * nme) const;//compares name data member with name passed in
        int display_name() const;//displays the name of our user
        char * get_name();
        ~User();//destructor

    protected:
        char * name; // users name
};
//IS A user - and is also responsible for managing Acct_node's list 
class User_node : public User
{
    public:
        User_node();
        User_node(const User_node &copy);
        User_node(char * username);
        User_node *& get_next();
        Acct_node *& get_head();
        void set_next(User_node * connect);
        void set_head(Acct_node * connect);
        int remove_all_accounts();
        int add_discord_account();
        int add_email_account();
        int add_slack_account();
        int view_discord_messages();
        int view_slack_messages();
        int view_email_messages();
        bool insert_email_message(Message &to_send, char * to_find);
        bool insert_discord_message(Message &to_send, char * to_find);
        bool insert_slack_message(Message &to_send, char * to_find);
        bool remove_email_message(char * subject);
        bool remove_discord_message(char * subject);
        bool remove_slack_message(char * subject);
        int remove_all_emailmsgs();
        int remove_all_slackmsgs();
        int remove_all_discordmsgs();
        ~User_node();
    protected:
        int add_account(Acct_node &to_add);
        int remove_all_accounts(Acct_node *&head);

        Acct_node * head;//Each user node has an Acct head pointer
        User_node * next;//Pointer to the next User_node
    private:
        bool insert_email_message(Message &to_send, char * to_find, Acct_node *&head);
        bool insert_discord_message(Message &to_send, char * to_find, Acct_node *&head);
        bool insert_slack_message(Message &to_send, char * to_find, Acct_node *&head);
        bool remove_email_message(char * subject,Acct_node *&head);
        bool remove_discord_message(char * subject,Acct_node *&head);
        bool remove_slack_message(char * subject,Acct_node *&head);
        int remove_all_emailmsgs(Acct_node *&head);
        int remove_all_slackmsgs(Acct_node *&head);
        int remove_all_discordmsgs(Acct_node *&head);
        int view_discord_messages(Acct_node *head);
        int view_slack_messages(Acct_node *head);
        int view_email_messages(Acct_node *head);
};
//Holds account base ptr this is responsible for Managing a linked list of accounts
//User_list manages User_node List
class User_list 
{
    public:
        User_list();
        int insert_user(User_node *to_add);
        bool insert_email_message(Message &to_send, char * to_find);
        bool insert_discord_message(Message &to_send, char* to_find);
        bool insert_slack_message(Message &to_send, char* to_find); 
        int view_discord_messages(char * username);
        int view_slack_messages(char * username);
        int view_email_messages(char * username);
        int remove_user(char * username);
        int add_discord_account(char * username);
        int add_slack_account(char * username);
        int add_email_account(char * username);
        bool remove_email_message(char * username, char * subject);
        bool remove_discord_message(char * username, char * subject);
        bool remove_slack_message(char * username, char * subject);
        int remove_all_emailmsgs(char * username);
        int remove_all_discordmsgs(char * username);
        int remove_all_slackmsgs(char * username);
        int remove_all_users();
        int display_all_users() const;
        void menu(int &user_in);
        void clear();
        int retrieve(char * name, User_list &newList);
        User_node * find_user(char *username);
        ~User_list();

    protected:
        int remove_user(User_node *&head,User_node *&prev,char * username);
        int remove_all_users(User_node *&head);
        int display_all_users(User_node *head) const;
        int retrieve(char * name, User_list &newList, User_node *head);
        User_node * find_user(User_node *head, char * user_name);
        User_node * head;
};


#endif
