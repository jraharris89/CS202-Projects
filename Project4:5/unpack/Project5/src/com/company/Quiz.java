/* Jonathon Harris - CS202 - Media Manager
   Quiz is part of the hierarchy, Quiz is a child of video which is child of Media. It holds the questions data member of the media
 */
package com.company;

public class Quiz extends Video{
    String questions;

    public Quiz(String title, String topic, String description, String comments, int view_count, float duration, String questions){
        super(title, topic, description, comments, view_count, duration);
        this.questions = questions;
    }
    //Copy constructor
    public Quiz(Quiz cpy){
        super(cpy);
        this.questions = questions;
    }

    public Quiz() {
       super();
       this.questions = null;
    }

    public int display_one(){
        displayMFields();
        System.out.println("Questions: " + questions);
        System.out.println();
        System.out.println();

        return 0;
    }
}
