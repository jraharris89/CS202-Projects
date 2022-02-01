/* Jonathon Harris - CS202 - Media Manager
This is the node class, it is responsible for holding a media, with a next pointer.
The array is filled with nodes. There are 15 indexes.
 */
package com.company;

public class Node {
    //each row should have the same topic name
    //each video should have a unique name
    private Media myMedia;
//    private int sequence;//the order they go in
    private Node next = null;

    public Node(Media myMedia) {
        this.myMedia = myMedia;
    }
    public Media getMedia(){
        return myMedia;
    }
    public void setNext(Node connection){
        next = connection;
    }
    public Node getNext(){
        return next;
    }

}
