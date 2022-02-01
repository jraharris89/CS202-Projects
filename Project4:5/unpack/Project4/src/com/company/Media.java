/* Jonathon Harris - CS202 - Media Manager
    Media is the superclass, it holds most of the information for media. Such as title, topic, description, comments and
    viewcount. Viewcount gets incremented everytime the client displays a media. There is 3 children.
    The hierarchy is Media->Video, Media->Video->Quiz, and Media->documents.
 */
package com.company;
//Media is our abstract base class
public abstract class Media {
    //MEDIA DATA FIELDS
    private String title;
    private String topic;
    private String description;
    private String comments;
    private int view_count;

    public Media(){
        this.title = null;
        this.topic= null;
        this.description= null;
        this.comments = null;
        this.view_count= 0;
    }
    //Parameterized constructor
    public Media(String title, String topic, String description, String comments, int view_count){
       this.title = title;
       this.topic = topic;
       this.description = description;
       this.comments = comments;
       this.view_count = view_count;
    }
    //Copy constructor, not actually needed.
    public Media(Media cpy){
       this.title= cpy.title;
       this.topic = cpy.topic;
       this.description = cpy.description;
       this.comments = cpy.comments;
       this.view_count = cpy.view_count;
    }
    abstract int display_one();

    //Display fields of Media (used for children displays)
    protected void displayMFields(){
        System.out.println("Title: " + title);
        System.out.println("Topic: " + topic);
        System.out.println("Description: " + description);
        System.out.println("Comments: " + comments);
        System.out.println("View Count: " + view_count);
    }
    protected boolean compare_topic(String name){
        if(name.equals(this.topic))
            return true;
        else
            return false;
    }
    protected String retrieve_top(){
        return topic;
    }
    protected boolean compare_title(String name){
        if(name.equals(this.title))
            return true;
        else
            return false;
    }
    protected void incrementView(){
        ++view_count;
    }


}

