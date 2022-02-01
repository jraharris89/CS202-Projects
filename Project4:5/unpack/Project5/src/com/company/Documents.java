/* Jonathon Harris - CS202 - Media Manager
   Documents is part of the hierarchy, documents is a child of Media. It holds the body of the questions.
 */


package com.company;
//Documents is a child of media
public class Documents extends Media {
    //Media specific data
    private String body;

    public Documents(String title , String topic, String description, String comments, int view_count, String body) {
        super(title, topic, description, comments, view_count);
        this.body = body;
    }
    public Documents(){
        super();
        this.body = null;
    }
    //Copy constructor not used just had to build it for peace of mind
    public Documents(Documents cpy) {
        super(cpy);
        this.body = cpy.body;
    }
    //Displays the Media data first then the data specific to documents
    protected int display_one() {
        displayMFields();
        System.out.println("Document: " + body);
        System.out.println();
        return 1;
    }
}