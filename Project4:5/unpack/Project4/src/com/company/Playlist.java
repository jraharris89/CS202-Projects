package com.company;

//Playlist is an array of nodes, Nodes hold our media and a next pointer
//Playlist responsibilities are to add/remove/display media.
//We add by topic, since every row should correspond to the same topic.
public class Playlist {

    final int SIZE = 15;
    Node[] head;//The start of the array

    Playlist() {
        this.head = new Node[SIZE];
        //for (int i = 0; i < SIZE; ++i) {
         //   this.head[i] = null;
        //}
    }

    //Parameterized constructor
    /*Playlist(String playName, String playDescr, int quantity) {
       this.playDescr = playDescr;
       this.quantity = quantity;
     */
    /*
    //Wrapper function
    Node find_index(String topicname) {
        if (topicname == null)
            return null;
        return find_index(head, topicname);
    }
     */
    //returns the starting point of our index with the same name
    protected int find_index(Node[] head, String topicname) {
        for (int i = 0; i < SIZE; ++i)
            if (head[i] != null && head[i].getMedia().compare_topic(topicname)) {
                return i;
            }
        return -1;
    }
    //returns the starting point of our index with the same name
    protected Node find_address(Node[] head, String topicname) {
        for (int i = 0; i < SIZE; ++i)
            if (head[i] != null && head[i].getMedia().compare_topic(topicname)) {
                return head[i];
            }
            return null;
    }
    public void add_media (Media obj, String topic){
        if(topic == null)
            return ;
        //returns index of array where the existing topic was found
        int find = find_index(head, topic);
        //this if statement will get executed if we've found a matching topic
        if(find != -1){
            // Call function to add to the end of our list
            head[find] = insert_end(head[find],obj);
            //We havent found a matching topic so add the node to an empty index
        }else
            add_media(obj, 0);
    }
    //insert at the beginning of an index that is null
    protected void add_media(Media obj,int index){
       if(index == SIZE)
           return ;
       //Our find_index function couldn't find a match
        // so we are going to add to the first index that is null
       if(head[index] == null){
           //This function goes through the list until we find a spot that is null
           //Then we can insert at that spot
           //Bring this into function
           head[index] = new Node(obj);
           return;
       }
        add_media(obj,index+1);

    }
    //This function goes to the end of an existing list and adds a node to it
    protected Node insert_end(Node head, Media obj){
        if(head == null){
            Node newNode = new Node(obj);
            return newNode;
        }
        else{
            head.setNext(insert_end(head.getNext(),obj));
        }
        return head;
    }

    //First we find the index of the topic, then we go through the list checking the media name
    //If it matches then we "remove" it
    protected Node remove(String topic, String title) {
        Node find = find_address(head, topic);
        int index = find_index(head,topic);
        if (find == null)
            return null;
        return remove_media(index, find, title);
    }
    //if we didn't find a topic that matches return, else check if it is at the first index
    //else go through the list a check the matching titles to remove
    protected Node remove_media(int index, Node found, String title){
        if(found == null)
            return null;
        //Node to remove is at the beginning of the list
        if(found == this.head[index] && found.getMedia().compare_title(title)){
            this.head[index] = head[index].getNext();
//            this.head[index].setNext(this.head[index].getNext());
            return this.head[index];
        }
        //else the node to remove is somewhere after the first node
        if(found.getMedia().compare_title(title)){
            Node connect = found.getNext();
            //found.setNext(found.getNext());
            return connect;
        }
        found.setNext(remove_media(index, found.getNext(),title));
        return found;
    }
    //Wrapper for display of one object
    public void display(String topic, String title) {
        display(head, topic, title);
    }
    //This displays the contents of one media object, we assume no 2 media's have the same title
    //This function finds the matching topic row, then calls display_one
    protected void display(Node[] head, String topic, String title) {
        if(head == null)
            return;
        Node find = find_address(head, topic);
        if(find == null)
            return;
        display_one(find, title);
        return;
        }
        //Display_one goes throw each node on that index and checks to see if the title matches
        //if match then display that node
        protected int display_one(Node found , String title){
            if(found == null)
                return 0 ;
            if (found.getMedia().compare_title(title)) {
                found.getMedia().display_one();
                found.getMedia().incrementView();
                return 0;
            }
            return 1 + display_one(found.getNext(),title);
        }
        //WRAPPER FUNCTION
    public int display_all(String topic){ return display_all(head,topic); }
    //GO find the index based on the topic we're looking for
    //call/send that address to display_all recursive display
    protected int display_all(Node []head, String topic){
        if(head == null)
            return 0;
        Node find = find_address(head, topic);
        if(find == null)
            return 0;
        int i = display_all(find);
        return i;
        //return how many objects were displayed from a given topic

    }
    //We have the address we want go through and display all Nodes
    protected int display_all(Node found){
        if(found == null) {
            return 0;
        }
        found.getMedia().incrementView();
        found.getMedia().display_one();
        return 1 + display_all(found.getNext());


        }
        public int display_all_ARR(){
        return display_all_ARR(0);
        }
        protected int display_all_ARR(int index){
        if(index == SIZE){
            return 0;
        }
        int count = 0;
        Node current = head[index];
        count += display_all_ARR(current);
        count +=display_all_ARR(++index);
        return count;
        }
        protected int display_all_ARR(Node current){
        if(current == null)
            return 0 ;
        return current.getMedia().display_one();

        }
}

