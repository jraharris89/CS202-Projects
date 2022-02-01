/* Jonathon Harris - CS202 - Media Manager
   Video is part of the hierarchy, video is a child of Media. It holds the duration data member of the media
 */
package com.company;

public class Video extends Media{
    //Video specific data
    private float duration;

    public Video(String title, String topic, String description, String comments, int view_count, float duration) {
        super(title, topic, description, comments, view_count);
        this.duration = duration;
    }
    //Copy constructor
    public Video(Video cpy){
        super(cpy);
        this.duration = cpy.duration;
    }

    public Video() {
        super();
        this.duration = 0;
    }

    //Display fields of media/video
    protected int display_one() {
        displayMFields();
        System.out.println("Duration: " + duration);
        System.out.println();
        System.out.println();
        return 0;
    }
}
