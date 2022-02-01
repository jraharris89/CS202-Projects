
/* Jonathon Harris- Project 2 Communication Dynamic Casting - CS202:
 * I kind of misinterpreted part of the assignment and assumed that sending a message
 * was between different users, because of that I made a bunch more work for myself. So plz
 * go nice on me..
 * The way my program is structured is I have a LLL of users, each user has a LLL of 
 * accounts, those accounts all have an Account ABC pointer which will represent 
 * Email, Slack or Discord. Email, slack and discord have their own LLL of messages. 
 * So all in all I have a LLL of users, LLL of accounts, and a LLL of messages. 
 * All of my functions use RTTI because we need to determine what kind of base pointer
 * we are on before we execute the associated code for it.
 *
 * The client must add a user and accounts to that user before calling Account
 * functions for that user. 
 *
 * DEBUG NOTES: When adding an account to a user, it works if the user is at the head 
 * of the list, otherwise it fails. GDB goes into an infinite loop in the User::compare_name
 * fuction once we get to the node that matches. FIXED
 *
 *
 */

#include "user.h"

int main()
{
    User_list newList;
    User_list retrieve;
    int user_input = 0;
    char username[100] = {};
    char to[100]= {};
    char from[100]= {};
    char subject[100]= {};
    char body[100]= {};//used to get answers for bathroom
    char msgID[100]= {};//used to get answers from pets
    newList.clear();
    cout << "Welcome to the Account Manager™: Start by creating users,\n" 
         << "then you can add accounts to those users.\nOnce you've created users and " 
         << "accounts for those users you can \nuse all the functionality Account Manager™ "
         << "has to provide.\nIts not recommended to add two of the same accounts to the same"
         << " user." << endl << endl; 

do{
    newList.menu(user_input);
    switch(user_input)
    {
        //ADD USER 
        case 1: 
            {
                newList.clear();
                cout << "Enter a username: ";
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                User_node newUser(username);//parameterized constructor invoked
                newList.insert_user(&newUser);
                cout << username << " added successfully." << endl;
            break;
            }
        //DISPLAY ALL USERS
        case 2: 
            {
                newList.clear();
                int count = newList.display_all_users();
                cout << count << " users on the platform." << endl;
            break;
            }
        //REMOVE USER
        case 3: 
            {
                newList.clear();
                cout << "Enter the username you wish to remove: ";
                cin.get(username, 100, '\n');
                cin.ignore(100,'\n');
                if(newList.remove_user(username) != 0)
                    cout << username << " has successfully been removed." << endl;
                else
                    cout << "Could not delete " << username << endl;
            break;
            }
        //RETRIEVE USER
        case 4:
            {
                newList.clear();
                cout << "Enter the username you wish to retrieve: ";
                cin.get(username, 100, '\n');
                cin.ignore(100,'\n');
                newList.retrieve(username,retrieve);
                cout << "Here is your new list of users matching " << username << ": ";
                cout << '\n';
                int count = retrieve.display_all_users();
                cout << "Your new list contains " << count << " users." <<endl;
            break;
            }
        //Add discord account to existing user
        case 5:
            {
                newList.clear();
                cout << "Which existing user would you like to a discord account to: ";
                cin.get(username, 100, '\n');
                cin.ignore(100,'\n');
                if(newList.add_discord_account(username) == 1)
                    cout << "Added discord account successfully." << endl;
                else
                    cout << "Couldn't add discord account, make sure you typed the username correctly.";
            break;
            }
        //Add email account to existing user
        case 6:
            {
                newList.clear();
                cout << "Which existing user would you like to an email acccount to: ";
                cin.get(username, 100, '\n');
                cin.ignore(100,'\n');
                if(newList.add_email_account(username) == 1)
                    cout << "Added email account successfully." << endl;
                else
                    cout << "Couldn't add email account, make sure you typed the username correctly.";
            break;
            }
        //Add Slack account to existing user
        case 7: 
            {
                newList.clear();
                cout << "Which existing user would you like to an slack acccount to: ";
                cin.get(username, 100, '\n');
                cin.ignore(100,'\n');
                if(newList.add_slack_account(username) == 1)
                    cout << "Added slack account successfully." << endl;
                else
                    cout << "Couldn't add slack account, make sure you typed the username correctly.";
            break;
            }
        //add discord message 
        case 8: 
            {
                newList.clear();
                cout << "Add message: ";
                cin.get(body,100, '\n');
                cin.ignore(100, '\n');
                cout << "Add message ID: ";
                cin.get(msgID,100, '\n');
                cin.ignore(100, '\n');
                Message newMsg(msgID, body);
                cout << "Which user are we sending this message to: " ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                if(newList.insert_discord_message(newMsg,username))
                    cout << "Message sent to " << username << " successfully." ;
                else
                    cout << "Program failed successfully." ;
            break;
            }
        //add Email message 
        case 9: 
            {
                newList.clear();
                cout << "To: " ;
                cin.get(to,100, '\n');
                cin.ignore(100, '\n');
                cout << "From: " ;
                cin.get(from,100, '\n');
                cin.ignore(100, '\n');
                cout << "Subject: " ;
                cin.get(subject,100, '\n');
                cin.ignore(100, '\n');
                cout << "Body: " ;
                cin.get(body,100, '\n');
                cin.ignore(100, '\n');
                Message newMsg(to,from,subject,body);
                cout << "Which user are we sending this message to: " ;
                cin.get(username, 100, '\n');
                cin.ignore(100, '\n');
                if(newList.insert_email_message(newMsg, username))
                    cout << "Message sent to " << username << " successfully." ;
                else
                    cout << "Program failed successfully." ;
            break;
            }
        //add slack message 
        case 10: 
            {
                newList.clear();
                cout << "Add message: ";
                cin.get(body,100, '\n');
                cin.ignore(100, '\n');
                cout << "Add message ID: ";
                cin.get(msgID,100, '\n');
                cin.ignore(100, '\n');
                Message newMsg(msgID, body);
                cout << "Which user are we sending this message to: " ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                if(newList.insert_slack_message(newMsg,username))
                    cout << "Message sent to " << username << " successfully." ;
                else
                    cout << "Program failed successfully." ;
            break;
            }
        //DISPLAY ALL DISCORD MESSAGES
        case 11: 
            {
                newList.clear();
                cout << "Which user's discord messages would you like to view: ";
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.view_discord_messages(username);
                cout << "Displaying " << count << " messages.";
                break;
            }
        //DISPLAY ALL EMAIL MESSAGES
        case 12: 
            {
                newList.clear();
                cout << "Which user's email messages would you like to view: ";
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.view_email_messages(username);
                cout << "Displaying " << count << " messages.";
            break;
            }
        //DISPLAY ALL Slack MESSAGES
        case 13: 
            {
                newList.clear();
                cout << "Which user's slack messages would you like to view: ";
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.view_slack_messages(username);
                cout << "Displaying " << count << " messages.";
            break;
            }
        //REMOVE DISCORD MESSAGE
        case 14: 
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                newList.view_discord_messages(username);
                cout << "Enter the message ID that you want to remove: "<< '\n';
                cin.get(msgID,100,'\n');
                cin.ignore(100,'\n');
                if(newList.remove_discord_message(username, msgID))
                {
                    cout << "Successfully removed " << msgID << " message." << endl;
                    newList.view_discord_messages(username);
                }
                else
                    cout << "Program failed successfully." << endl;

            break;
            }
        //REMOVE EMAIL MESSAGE
        case 15: 
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                newList.view_email_messages(username);
                cout << "Enter the subject that you want to remove: "<< '\n';
                cin.get(subject,100,'\n');
                cin.ignore(100,'\n');
                if(newList.remove_email_message(username, subject))
                {
                    cout << "Successfully removed " << subject << " message." << endl;
                    newList.view_email_messages(username);
                }
                else
                    cout << "Program failed successfully." << endl;
            break;
            }
        //REMOVE SLACK MESSAGES
        case 16:
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                newList.view_slack_messages(username);
                cout << "Enter the message ID that you want to remove: " << '\n';
                cin.get(msgID,100,'\n');
                cin.ignore(100,'\n');
                if(newList.remove_slack_message(username, msgID))
                {
                    cout << "Successfully removed " << msgID << " message." << endl;
                    newList.view_slack_messages(username);
                }
                else
                    cout << "Program failed successfully." << endl;
            break;
            }
        //REMOVE ALL DISCORD MESSAGES
        case 17:
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.remove_all_discordmsgs(username);
                cout << count << " messages removed from " << username << ". " <<endl;
            break;
            }
        //REMOVE ALL EMAIL MESSAGES
        case 18:
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.remove_all_emailmsgs(username);
                cout << count << " messages removed from " << username << ". " <<endl;
            break;
            }
        //REMOVE ALL SLACK MESSAGES
        case 19:
            {
                newList.clear();
                cout << "Enter name of the account you wish to remove: " << '\n' ;
                cin.get(username,100,'\n');
                cin.ignore(100,'\n');
                int count = newList.remove_all_slackmsgs(username);
                cout << count << " messages removed from " << username << ". " <<endl;
            break;
            }
            //QUIT PROGRAM
        case 20:
            {
                newList.remove_all_users();
                return 0;
            }

                
    }
}while(user_input>=1 || user_input <  20);

}
