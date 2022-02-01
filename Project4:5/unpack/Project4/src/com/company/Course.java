/* Jonathon Harris - Media Manager
This class is responsible for holding a single playlist object, it represents a unique course that a instructor
is in charge of. Course can also be viewed as a BST node. It doesn't have alot of responsibilities it only holds
the playlist and points to the left and right courses.
 */
package com.company;

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
    }
    protected int display_course(){
        System.out.println();
        System.out.println("Course Name: " + course_name);
        System.out.println("Course ID: " + course_id);
        return 1;
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

    protected Playlist getPlaylist() {
        return myPlaylist;
    }
    //SETTERS
    protected void setLeft(Course connection) {
        left = connection;
    }

    protected void setRight(Course connection) {
        right = connection;
    }

}