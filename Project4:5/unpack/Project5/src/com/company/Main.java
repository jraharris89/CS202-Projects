/* Jonathon Harris - CS202 - Media Manager
This is the main program, It has an interactive menu that the client interacts with. Currently
the client can add different courses, types of media, remove all courses or individual media's, display one media or display all by topic
as well as importing media from a text file. The data structures are a BST with each node containing an array of LLL.
 */
//TODO I just need to fix mediaReader, to get the last field to parse out an array of Strings
package com.company;

import java.util.Scanner;



public class Main {

    public static void main(String[] args) {
        Course findCourse;//we use this to point at some course in our tree
        Scanner input = new Scanner(System.in);//read in data from user
        Playlist newPlaylist = new Playlist();// Creating a playlist to copy
        mediaReader read = new mediaReader();//Import data from text file
        Tree newTree = new Tree();//This is our binary search tree
        Tree reTreeval= new Tree();//This is our binary search tree for retrieve function
        String title, topic, description, comments, questions, body,course_name, user_in2;//All the strings needed to read in
        float duration;//duration of video media
        int user_in, course_ID;
        do {
            System.out.println();
            System.out.println();
            System.out.println("1. Add Course.");
            System.out.println("2. Add Media To Course");
            System.out.println("3. Remove Options");
            System.out.println("4. Display Options");
            System.out.println("5. Import Media From Text");
            System.out.println("6. Retrieve Course, Add to New Tree.");
            System.out.println("7. Quit");
            user_in = input.nextInt();
            input.nextLine();
            switch (user_in) {
                //USER WANTS TO ADD MEDIA, WHAT KIND?
                case 1 -> {
                    System.out.println("Enter the name of the course: ");
                    course_name = input.nextLine();
                    System.out.println("Enter the course ID number: ");
                    course_ID = input.nextInt();
                    newTree.add_course(course_name, course_ID);
                }
                case 2 -> {
                    System.out.println("Which Course Would You Like To Add To?");
                    course_name = input.nextLine();
                    newTree.display_all_courses();
                    findCourse = newTree.find_course(course_name);
                    if (findCourse == null)
                        throw new IllegalStateException("Couldn't find course name: " + course_name);
                    else {
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
                            //Go to that course
                            findCourse.add_Course_Media(newVideo, topic);
                            //Add it to the newPlaylist
                            //newPlaylist.add_media(newVideo, topic);
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
                            findCourse = newTree.find_course(course_name);
                            findCourse.add_Course_Media(newQuiz, topic);
                            //newPlaylist.add_media(newQuiz, topic);
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
                            findCourse = newTree.find_course(course_name);
                            findCourse.add_Course_Media(newDoc, topic);
                            //Add it to the newPlaylist
                            newPlaylist.add_media(newDoc, topic);
                        } else {
                            System.out.println("Invalid option.");
                        }
                    }
                }
                // REMOVAL OPTIONS
                case 3 -> {
                    System.out.println("1. Remove Media From Course.");
                    System.out.println("2. Remove Single Course.");
                    System.out.println("3. Remove All Courses.");
                    user_in2 = input.nextLine();
                    if(user_in2.equals("1")) {

                        System.out.println("Enter Course Name: ");
                        course_name = input.nextLine();
                        System.out.println("Enter Topic of Media You Wish to Remove: ");
                        topic = input.nextLine();
                        System.out.println("Enter Title of Video You Wish to Remove: ");
                        title = input.nextLine();
                        //find that course
                        findCourse = newTree.find_course(course_name);
                        if (findCourse == null)
                            System.out.println("Couldn't find " + course_name);
                        else {
                            findCourse.remove_Course_Media(topic, title);
                            System.out.println("Removed " + title + " successfully.");
                        }
                    }else if(user_in2.equals("2")) {
                        System.out.println("Which Course Would You Like To Remove: ");
                        course_name = input.nextLine();
                        newTree.remove_individual(course_name);
                    }else if(user_in2.equals("3")){
                        newTree.remove_all();
                        System.out.println("All courses removed successfully.");
                    }else
                        System.out.println("Invalid Option.");
                }
                //DISPLAY OPTIONS
                case 4 -> {
                    System.out.println("What Would You Like To Display?");
                    System.out.println("-------------------------------");
                    System.out.println("1. Display Individual Media (Enter Course, title and Topic) ");
                    System.out.println("2. Display All Based on Topic (Enter Course and Topic.");
                    System.out.println("3. Display All Courses.");
                    System.out.println("4. Display All Media.");
                    user_in2 = input.nextLine();
                    if (user_in2.equals("1") ) {
                        System.out.println("Enter Course Name: ");
                        course_name = input.nextLine();
                        System.out.println("Enter Title of Media you want to display: ");
                        title = input.nextLine();
                        System.out.println("Enter Topic of Your Media: ");
                        topic = input.nextLine();
                        findCourse = newTree.find_course(course_name);
                        if(findCourse == null)
                            System.out.println("Couldn't find " + course_name);
                        else
                            findCourse.display_individual(topic,title);
                    } else if (user_in2.equals("2")) {
                        System.out.println("Enter Course Name: ");
                        course_name = input.nextLine();
                        System.out.println("Enter Topic of Playlist you want to display: ");
                        topic = input.nextLine();
                        findCourse = newTree.find_course(course_name);
                        if(findCourse == null)
                            System.out.println("Couldn't find " + course_name);
                        else
                            findCourse.display_topic(topic);
                    } else if(user_in2.equals("3")){
                        newTree.display_all_courses();
                    } else if (user_in2.equals("4")) {
                        System.out.println();
                        newTree.display_all_media();
                    }else {
                        System.out.println("Invalid Choice.");
                    }
                }
                //Upload from text file
                case 5 -> {
                    newTree.display_all_courses();
                    System.out.println("Enter Course you wish to add to.");
                    course_name = input.nextLine();
                    System.out.println("Choose Which Type of Media To Upload.");
                    System.out.println("1. Video");
                    System.out.println("2. Video(with quiz)");
                    System.out.println("3. Document");
                    user_in2 = input.nextLine();
                    findCourse = newTree.find_course(course_name);
                    if(findCourse == null){
                        throw new IllegalStateException("Couldn't find course name: " + course_name);
                    }
                    else {
                        if (user_in2.equals("1")) {
                            Media newVid = new Video();
                            newVid = read.read(1);
                            findCourse.add_Course_Media(newVid,newVid.retrieve_top());
                            System.out.println("Add Successful.");
                        } else if (user_in2.equals("2")) {
                            Media newQuiz = new Quiz();
                            newQuiz = read.read(2);
                            findCourse.add_Course_Media(newQuiz ,newQuiz.retrieve_top());
                            System.out.println("Add Successful.");
                        } else if (user_in2.equals("3")) {
                            Media newDoc= new Documents();
                            newDoc = read.read(3);
                            findCourse.add_Course_Media(newDoc,newDoc.retrieve_top());
                            System.out.println("Add Successful.");
                        } else {
                            System.out.println("Invalid Option..");
                        }
                    }
                }
                case 6 -> {
                    System.out.println("Enter the Course Name you want to retrieve: ");
                    course_name = input.nextLine();
                    newTree.retrieve_course(reTreeval, course_name);
                    System.out.println("Here is the new tree: ");
                    reTreeval.display_all_courses();
                }
                case 7 -> {
                    return;
                }
                default -> throw new IllegalStateException("Unexpected value: " + user_in);
            }
        } while (user_in > 0 && user_in <= 7 ) ;
    }
}