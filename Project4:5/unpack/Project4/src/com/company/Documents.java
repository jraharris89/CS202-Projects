/* Jonathon Harris - CS202 - Media Manager
   Documents is part of the hierarchy, documents is a child of Media. It holds the body of the questions.
 */


package com.company;

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
    //Copy constructor
    public Documents(Documents cpy) {
        super(cpy);
        this.body = cpy.body;
    }

    protected int display_one() {
        displayMFields();
        System.out.println("Document: " + body);
        System.out.println();
        return 0;
    }
}