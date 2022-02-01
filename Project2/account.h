/* Jonathon Harris - Project 2 - Account.h is my header file for my Abstract Base class and the children (discord, email, slack) of that class.
 * Each child holds a Message * head pointer, Message is then setup as a LLL, Message has a next pointer in the class to point to the next message.
 * Message is the same across all communications
 */
#ifndef ACCOUNT_H
#define ACCOUNT_H
//----------------------------------------MESSAGE "NODE" ----------------------
//email Message is the message used for emails 
class Message
{
    public:
        Message();
        Message(const Message &copy); //copy constructor for message
        Message(char *mesID, char * bdy);
        Message(char *too,  char * frm, char * sbj,char * bdy);
        void set_next(Message * connect);//set next pointer
        bool compare_subject(char *to_compare);//compare the subj of message to one user passes in
        bool compare_msgID(char *to_compare);//compare the msgID of message to one user passes in
        //GETTERS
        Message *& get_next();
        char * get_msgID();
        char * get_to();
        char * get_from();
        char * get_subject();
        char * get_body();
        ~Message();//destructor 
    private:
        char * msgID;//so we can track what discord message to delete
        char * to; // who are we sending it to
        char * from;//where is it from
        char * subject;//subject header
        char * body;//Message body
        Message * next;// next pointer to next Message
};
//---------------------------Abstract Base Class ------------------------------
class Account
{
    public:
        Account();
        virtual int add_msg(Message &to_add) = 0;//Adds message to current user
        virtual bool send_msg(Message &to_send) = 0 ;//sends a message to a different user
        virtual int read_all_msgs() const= 0 ;//display all messages
        virtual bool remove_msg(char *subject)= 0 ;//remove a message from current user
        virtual int remove_all_msgs()= 0 ;//deletes all the messages for current user
        virtual ~Account();
};
//-------------------------------------COMMUNICATION CLASSES (Derived from ABC) -----------------
class Email: public Account
{
    public:
        Email();
        int add_msg(Message &to_add);//add message to the current users list
        bool send_msg(Message &to_send);//send message to a different user
        int read_all_msgs() const;//display all messages
        bool remove_msg(char *subject);//remove message by subject
        int remove_all_msgs();//destroy all messages
        ~Email(); // destructor
    protected:
        bool remove_msg(Message *&head,Message *&prev,char *subject);
        int remove_all_msgs(Message *&head) ;
        int read_all_msgs(Message *head) const;
    private: 
        Message * head;
};
class Discord: public Account
{
    public:
        Discord();
        int add_msg(Message &to_add);//add message to the current users list
        bool send_msg(Message &to_send);//send message to a different user
        int read_all_msgs() const;//display all messages
        bool remove_msg(char *subject);//remove message by subject
        int remove_all_msgs();//destroy all messages
        ~Discord(); // destructor
    protected:
        bool remove_msg(Message *&head,Message *&prev,char *subject);
        int remove_all_msgs(Message *&head) ;
        int read_all_msgs(Message *head) const;
    private: 
        Message * head;
};
class Slack: public Account
{
    public:
        Slack();
        int add_msg(Message &to_add);//add message to the current users list
        bool send_msg(Message &to_send);//send message to a different user
        int read_all_msgs() const;//display all messages
        bool remove_msg(char *subject);//remove message by subject
        int remove_all_msgs();//destroy all messages
        ~Slack(); // destructor
    protected:
        bool remove_msg(Message *&head,Message *&prev,char *subject);
        int remove_all_msgs(Message *&head) ;
        int read_all_msgs(Message *head) const;
    private: 
        Message * head;
};

#endif
