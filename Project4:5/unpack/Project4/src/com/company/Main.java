/* Jonathon Harris - CS202 - Media Manager
This is the main program, It has an interactive menu that the client interacts with. Currently
the client can add different types of media, remove individual media's, display one media or display all by topic
as well as importing media from a text file.
 */

package com.company;

import java.util.Scanner;



public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Playlist newPlaylist = new Playlist();
        mediaReader read = new mediaReader();
        String title, topic, description, comments, questions, body, user_in2;
        float duration;
        //Driver myDriver;
        int user_in;
        //TODO add courses first, once finished then add media's etc..
        do {
            System.out.println();
            System.out.println();
            System.out.println("1. Add Media");
            System.out.println("2. Remove Media");
            System.out.println("3. Display");
            System.out.println("4. Import Media");
            System.out.println("5. Quit");
            user_in = input.nextInt();
            input.nextLine();
            switch (user_in) {
                //USER WANTS TO ADD MEDIA, WHAT KIND?
                case 1 -> {
                    System.out.println("Which Type of Media Do You Want To Add?");
                    System.out.println("1. Video");
                    System.out.println("2. Video(with quiz)");
                    System.out.println("3. Document");
                    user_in2 = input.nextLine();
                    //USER CHOOSES TO ADD VIDEO
                    if (user_in2.equals("1")) {
                        System.out.println("Enter Title of Video: ");
                        title = input.nextLine();
                        System.out.println("Enter Topic of Video: ");
                        topic = input.nextLine();
                        System.out.println("Enter Description of Video: ");
                        description = input.nextLine();
                        System.out.println("Enter Comments for the Video: ");
                        comments = input.nextLine();
                        System.out.println("Enter Duration of the Video: ");
                        duration = input.nextFloat();
                        //Create a new object video
                        Video newVideo = new Video(title, topic, description, comments, 0, duration);
                        //Add it to the newPlaylist

                        newPlaylist.add_media(newVideo, topic);
                        //USER CHOOSES TO ADD VIDEO W/ QUIZ
                    } else if (user_in2.equals("2")) {
                        System.out.println("Enter Title of Video: ");
                        title = input.nextLine();
                        System.out.println("Enter Topic of Video: ");
                        topic = input.nextLine();
                        System.out.println("Enter Description of Video: ");
                        description = input.nextLine();
                        System.out.println("Enter Comments for the Video: ");
                        comments = input.nextLine();
                        System.out.println("Enter the Questions for the Video: ");
                        questions = input.next();
                        System.out.println("Enter Duration of the Video: ");
                        duration = input.nextFloat();
                        //Create a new object quiz
                        Quiz newQuiz = new Quiz(title, topic, description, comments, 0, duration, questions);
                        //Add it to the newPlaylist
                        newPlaylist.add_media(newQuiz, topic);
                        //USER CHOOSES TO ADD A DOCUMENT
                    } else if (user_in2.equals("3")) {
                        System.out.println("Enter Title of Document: ");
                        title = input.nextLine();
                        System.out.println("Enter Topic of Document: ");
                        topic = input.nextLine();
                        System.out.println("Enter Description of Document: ");
                        description = input.nextLine();
                        System.out.println("Enter Comments for the Document: ");
                        comments = input.nextLine();
                        System.out.println("Enter Body of the Document: ");
                        body = input.next();
                        //Create a new object document
                        Documents newDoc = new Documents(title, topic, description, comments, 0, body);
                        //Add it to the newPlaylist
                        newPlaylist.add_media(newDoc, topic);
                    } else {
                        System.out.println("Invalid option.");
                    }
                }
                case 2 -> {
                    System.out.println("Enter Topic of Media You Wish to Remove: ");
                    topic = input.nextLine();
                    System.out.println("Enter Title of Video You Wish to Remove: ");
                    title = input.nextLine();
                    newPlaylist.remove(topic, title);
                }
                case 3 -> {
                    System.out.println("Which Display Do You Want?");
                    System.out.println("1. Display Individual Media (Enter title and Topic) ");
                    System.out.println("2. Display All Based on Topic");
                    System.out.println("3. Display All. ");
                    user_in2 = input.nextLine();
                    if (user_in2.equals("1") ) {
                        System.out.println("Enter Topic of Your Media: ");
                        topic = input.nextLine();
                        System.out.println("Enter Title of Media you want to display: ");
                        title = input.nextLine();
                        newPlaylist.display(topic, title);
                    } else if (user_in2.equals("2")) {
                        System.out.println("Enter Topic of Playlist you want to display: ");
                        topic = input.nextLine();
                        newPlaylist.display_all(topic);
                    } else if (user_in2.equals("3")) {
                        System.out.println("Media: ");
                        System.out.println();
                        newPlaylist.display_all_ARR();
                    } else
                        System.out.println("Invalid Choice.");
                }
                case 4 -> {
                    System.out.println("Choose Which Type of Media To Upload.");
                    System.out.println("1. Video");
                    System.out.println("2. Video(with quiz)");
                    System.out.println("3. Document");
                    user_in2 = input.nextLine();
                    if (user_in2.equals("1")) {
                        Media newVid = new Video();
                        newVid = read.read(1);
                        newPlaylist.add_media(newVid, newVid.retrieve_top());
                    } else if (user_in2.equals("2")) {
                        Media newVid = new Quiz();
                        newVid = read.read(2);
                        newPlaylist.add_media(newVid, newVid.retrieve_top());

                    } else if (user_in2.equals("3")) {
                        Media newVid = new Documents();
                        newVid = read.read(3);
                        newPlaylist.add_media(newVid, newVid.retrieve_top());
                    } else {
                        System.out.println("Invalid Option..");
                    }
                }
                case 5 -> {
                    return;
                }
                default -> throw new IllegalStateException("Unexpected value: " + user_in);
            }
        } while (user_in > 0 && user_in <= 6 ) ;
    }
}