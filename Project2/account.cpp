/* Jonathon Harris - Project 2 Communication dynamic casting - CS202
 * This is my account implementation it defines all classes found in account.h 
 * Those include : Message, Account (ABC), Discord (child),Slack (child), Email(Child)
 * Each child has a LLL of messages attached to it. 
 * Each Acct_Node has an ABC pointer that can be represented as any child. 
 */



#include "user.h"
#include "account.h"

// ------------------------------------------------------Email Functions------------------------------------
//Always adding messages to the beginning of the list, passing in what we want to copy
Email::Email()
{
    head= NULL;
}
int Email::add_msg(Message &to_add)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_add);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_add);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
//put in User_list class
//if you have a BC pointer pointing at a child pointer you have to cast it before you can access the data.
//TODO FIGURE OUT HOW TO SEND MSG, User_node * necessary?

bool Email::send_msg(Message &to_send)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_send);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_send);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
int Email::read_all_msgs() const
{
    if(!head)
        return 0;
    return read_all_msgs(head);
}
int Email::read_all_msgs(Message *head) const
{
    if(!head)
        return 0;

    int count(0);
    if(head->get_to()) 
        cout << "To: " << head->get_to()<< endl;
    if(head->get_from()) 
        cout << "From: " << head->get_from()<< endl;
    if(head->get_subject()) 
        cout << "Subject: " << head->get_subject()<< endl;
    if(head->get_body()) 
        cout << "body: " << head->get_body()<< endl;

    return ++count + read_all_msgs(head->get_next());
}
bool Email::remove_msg(char * subject)
{
    if(!head)
        return 0;
    Message * prev = head;
    return remove_msg(head,prev, subject);
}
bool Email::remove_msg(Message *&head,Message *&prev,  char * subject)
{
    if(!head)
        return false;
    if(head->compare_subject(subject)) // subject matches
    {
        if(this->head == head)//deleting the first node
        {
            Message * temp = head;
            head = head->get_next();
            delete temp;
            temp = NULL;
            head = this->head;
        }
        else//deleteing middle/end
        {
            //prev->next = head->next
            prev->set_next(head->get_next());
            delete head;
            head = prev;
        }
        return true;
    }
    return remove_msg(head->get_next(),head,subject);
}
int Email::remove_all_msgs()
{
    if(!head)
        return 0;
    return remove_all_msgs(head);
}
int Email::remove_all_msgs(Message *&head)
{
    if(!head)
        return 0;
    int count(0);
    ++count + remove_all_msgs(head->get_next()) ;
    delete head;
    head = NULL;
    return count;
}
Email::~Email()
{
    if(head)
        remove_all_msgs();
}
// ------------------------------------------------------Discord Functions------------------------------------
Discord::Discord()
{
    head = NULL;
}
int Discord::add_msg(Message &to_add)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_add);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_add);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
//put in User_list class
//if you have a BC pointer pointing at a child pointer you have to cast it before you can access the data.
//TODO FIGURE OUT HOW TO SEND MSG, User_node * necessary?

bool Discord::send_msg(Message &to_send)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_send);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_send);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
int Discord::read_all_msgs() const
{
    if(!head)
        return 0;
    return read_all_msgs(head);
}
int Discord::read_all_msgs(Message *head) const
{
    if(!head)
        return 0;

    int count(0);
    if(head->get_msgID())
        cout << "Message ID: " << head->get_msgID() << '\n';
    if(head->get_body()) 
        cout << "Body: " << head->get_body()<< endl;

    return ++count + read_all_msgs(head->get_next());
}
bool Discord::remove_msg(char * msgID)
{
    if(!head)
        return 0;
    Message * prev = head;
    return remove_msg(head,prev, msgID);
}
bool Discord::remove_msg(Message *&head,Message *&prev,  char * msgID)
{
    if(!head)
        return false;
    if(head->compare_msgID(msgID)) // msgID matches
    {
        if(this->head == head)//deleting the first node
        {
            Message * temp = head;
            head = head->get_next();
            delete temp;
            temp = NULL;
            head = this->head;
        }
        else//deleteing middle/end
        {
            //prev->next = head->next
            prev->set_next(head->get_next());
            delete head;
            head = prev;
        }
        return true;
    }
    return remove_msg(head->get_next(),head,msgID);
}
int Discord::remove_all_msgs()
{
    if(!head)
        return 0;
    return remove_all_msgs(head);
}
int Discord::remove_all_msgs(Message *&head)
{
    if(!head)
        return 0;
    int count(0);
    ++count + remove_all_msgs(head->get_next()) ;
    delete head;
    head = NULL;
    return count;
}
Discord::~Discord()
{
    remove_all_msgs();
}


// ------------------------------------------------------Slack Functions------------------------------------
Slack::Slack()
{
    head = NULL;
}
int Slack::add_msg(Message &to_add)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_add);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_add);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
//put in User_list class
//if you have a BC pointer pointing at a child pointer you have to cast it before you can access the data.
bool Slack::send_msg(Message &to_send)
{
    if(!head)
    {
        //copy message data into new node head
        head = new Message(to_send);
        //head->next = NULL
        head->set_next(NULL);
        return 1;
    }
    else
    {
        //create new message pass in message data
        Message * temp = new Message(to_send);
        //temp->next = head
        temp->set_next(head);
        //temp is now the new head of the list
        head = temp;
        return 1;
    }
}
int Slack::read_all_msgs() const
{
    if(!head)
        return 0;
    return read_all_msgs(head);
}
int Slack::read_all_msgs(Message *head) const
{
    if(!head)
        return 0;

    int count(0);

    if(head->get_msgID())
        cout << "Message ID: " << head->get_msgID() << endl;
    if(head->get_subject()) 
        cout << "Subject: " << head->get_subject()<< endl;

    return ++count + read_all_msgs(head->get_next());
}
bool Slack::remove_msg(char * msgID)
{
    if(!head)
        return 0;
    Message * prev = head;
    return remove_msg(head,prev, msgID);
}
bool Slack::remove_msg(Message *&head,Message *&prev,  char * msgID)
{
    if(!head)
        return false;
    if(head->compare_msgID(msgID)) // msgID matches
    {
        if(this->head == head)//deleting the first node
        {
            Message * temp = head;
            head = head->get_next();
            delete temp;
            temp = NULL;
            head = this->head;
        }
        else//deleteing middle/end
        {
            //prev->next = head->next
            prev->set_next(head->get_next());
            delete head;
            head = prev;
        }
        return true;
    }
    return remove_msg(head->get_next(),head,msgID);
}
int Slack::remove_all_msgs()
{
    if(!head)
        return 0;
    return remove_all_msgs(head);
}
int Slack::remove_all_msgs(Message *&head)
{
    if(!head)
        return 0;
    int count(0);
    ++count + remove_all_msgs(head->get_next()) ;
    delete head;
    head = NULL;
    return count;
}
Slack::~Slack()
{
    if(head)
        remove_all_msgs();
}


// ------------------------------------------------------Message Functions------------------------------------
Message::Message()
{
    msgID = NULL;
    to = NULL;
    from = NULL;
    subject = NULL;
    body = NULL;
    next = NULL;
}
Message::Message(char *too,  char * frm, char * sbj,char * bdy)
{
    if(too)
    {
        to= new char[strlen(too)+1];
        strcpy(to,too);
    }
    else
        to= NULL;

    if(frm)
    {
        from= new char[strlen(frm)+1];
        strcpy(from,frm);
    }
    else
        from= NULL;
    if(sbj)
    {
        subject =  new char[strlen(sbj)+1];
        strcpy(subject,sbj);
    }
    else
        subject = NULL;

    if(bdy)
    {
        body= new char[strlen(bdy)+1];
        strcpy(body,bdy);
    }
    else
        body = NULL;
}

//parameterized constructor for slack and discord
Message::Message(char *mesID, char * bdy)
{
    if(mesID)
    {
        msgID = new char[strlen(mesID)+1];
        strcpy(msgID,mesID);
    }
    else
        msgID = NULL;

    if(bdy)
    {
        body = new char[strlen(bdy)+1];
        strcpy(body,bdy);
    }
    else
        msgID = NULL;
}

//Message copy constructor, copies over all the dynamic char *, if data does not exist set it to NULL 
//and then move on.
Message::Message(const Message &copy)
{
    if(copy.msgID)
        msgID = copy.msgID;
    else
        msgID = 0;

    if(copy.msgID)
    {
        msgID= new char[strlen(copy.msgID)+1];
        strcpy(msgID,copy.msgID);
    }
    else
        msgID= NULL;
    if(copy.to)
    {
        to = new char[strlen(copy.to)+1];
        strcpy(to,copy.to);
    }
    else
        to = NULL;
    if(copy.from)
    {
        from = new char[strlen(copy.from)+1];
        strcpy(from,copy.from);
    }
    else
        from = NULL;
    if(copy.subject)
    {
        subject = new char[strlen(copy.subject)+1];
        strcpy(subject,copy.subject);
    }
    else
        subject = NULL;
    if(copy.body)
    {
        body = new char[strlen(copy.body)+1];
        strcpy(body,copy.body);
    }
    else
        body = NULL;
    next = NULL;
}
//setter for messages next pointer 
void Message::set_next(Message * connect)
{
    next = connect;
}
//checks to see if the subject user passes in matches the subject of our Message node
bool Message::compare_subject(char * to_compare)
{
    if(to_compare)
    {
        if(strcmp(subject,to_compare)==0)
            return true;
        else
            return false;
    }
    return false;
}
//checks to see if the msgID user passes in matches the subject of our Message node
bool Message::compare_msgID(char * to_compare)
{
    if(to_compare)
    {
        if(strcmp(msgID,to_compare)==0)
            return true;
        else
            return false;
    }
    return false;
}
//Message destructor, deletes all allocated memory
Message::~Message()
{
    if(msgID)
    {
        delete [] msgID;
        msgID = NULL;
    }
    if(to)
    {
        delete [] to;
        to = NULL;
    }
    if(from)
    {
        delete [] from;
        from = NULL;
    }
    if(subject)
    {
        delete [] subject;
        subject = NULL;
    }
    if(body)
    {
        delete [] body;
        body = NULL;
    }
    next = NULL;
}
//GETTERS  for MESSAGE 
Message *& Message::get_next()
{
    return next;
}
char * Message::get_msgID()
{
    if(msgID)
        return msgID;
    else
        return NULL;
}
char * Message::get_to()
{
    if(to)
        return to;
    else
        return NULL;
}
char * Message::get_from()
{
    if(from)
        return from;
    else
        return NULL;
}
char * Message::get_subject()
{
    if(subject)
        return subject;
    else
        return NULL;
}
char * Message::get_body()
{
    if(body)
        return body;
    else
        return NULL;
}

// ------------------------------------------------------Account Functions------------------------------------
Account::Account(){}
//try to dynamic cast if its discord, email slack then copy the pointer over

Account::~Account(){}
