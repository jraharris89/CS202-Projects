/* Jonathon Harris - PROJECT 5 - Media Manager
This class is responsible for holding a single playlist object, it represents a unique course that a instructor
is in charge of. Course can also be viewed as a BST node. It doesn't have alot of responsibilities it only holds
the playlist and points to the left and right courses.
 */
package com.company;
//Course is my BST Node
public class Course {
    protected Playlist myPlaylist;
    private Course left;//left reference
    private Course right;//right reference
    private String course_name;
    private int course_id;

    public Course() {
        myPlaylist = new Playlist();
        left = null;
        right = null;
        course_name = null;
        course_id = 0;
    }
    public Course(String course, int course_id) {
        myPlaylist = new Playlist();
        this.course_name = course;
        this.course_id= course_id;
        this.left = null;
        this.right= null;
    }
    protected int display_course(){
        System.out.println();
        System.out.println("----------------------");
        System.out.println("Course Name: " + course_name);
        System.out.println("Course ID: " + course_id);
        System.out.println("----------------------");
        System.out.println();
        return 1;
    }
    //ADDS media to a course
    //This function calls on playlists add function
    public void add_Course_Media(Media to_add, String topic){
        myPlaylist.add_media(to_add, topic);
    }
    //Removes media From a course
    //This function calls on playlists remove function
    public void remove_Course_Media(String topic, String title){
        myPlaylist.remove(topic, title);
    }
    //Displays one media From a course
    //This function calls on playlists display_one function
    public void display_individual(String topic, String title){
        myPlaylist.display(topic, title);
    }
    //Displays all Media based on a topic
    //This function calls on playlists display_all function
    public void display_topic(String topic){
        myPlaylist.display_all(topic);
    }
    //This displays all media from all courses
    //This function calls on display all media in the array
    public int display_all(){
        return myPlaylist.display_all_ARR();
    }
    //GETTERS
    protected String getName(){
        return course_name;
    }
    protected int getID(){
        return course_id;
    }
    protected Course getRight() {
        return right;
    }

    protected Course getLeft() {
        return left;
    }
    //TODO I don't think i need this, maybe delete
    protected Playlist getPlaylist() {
        return myPlaylist;
    }
    //SETTERS
    protected void setLeft(Course connection) {
        left = connection;
    }
    protected void setRight(Course connection) { right = connection; }
    protected void setName(String connection) {course_name = connection; }
    protected void setID(int ID) { course_id = ID; }

}