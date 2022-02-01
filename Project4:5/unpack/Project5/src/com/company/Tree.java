/* Jonathon Harris - Project 5 - Media Manager
This class is my binary search tree, each node of the binary tree is a course
each course has a playlist, each playlist index is a list of media based on topic.
This class is responsible for managing courses: adding, removing, displaying courses.
 */
package com.company;

public class Tree {
    private Course root;//my root reference
    //=============TREE FUNCTIONS =============
    //Wrapper for add course to a tree
    public Course add_course(String course_name, int course_id){
        if(this.root == null){
            this.root = new Course(course_name,course_id);
            return this.root;
        } else
            return add_course(course_name,course_id,root);
    }
    //ADD COURSE FUNCTION, compares the names then adds accordingly
    protected Course add_course(String course_name, int course_id, Course root){
        if(root == null ){
            root = new Course(course_name,course_id);
            return root;
        }
        //compare the roots string name and the root name we're adding
        int compare = course_name.compareToIgnoreCase(root.getName());
        //If the course we are trying to add to our tree is less than roots course_name
        if(compare<0){
           root.setLeft(add_course(course_name, course_id, root.getLeft()));
            //else it is greater or equal to
        }else{
//            root = add_course(course_name, course_id, root.getRight());
            root.setRight(add_course(course_name, course_id, root.getRight()));
        }
        return root;
    }
    //Wrapper for displaying all the media in the tree
    public int display_all_media(){
        if(root==null)
            return 0;
        return display_all_media(root);
    }
    //This function goes through each course and displays all media
    protected int display_all_media(Course root){
        if(root == null)
            return 0;
        int count = 0 ;
        display_all_media(root.getLeft());
        root.display_course();
        root.display_all();
        display_all_media(root.getRight());
        return count;
    }
    //WRAPPER FOR DISPLAY ALL
    public int display_all_courses(){
        if(root == null)
            return 0 ;
        return display_all_courses(root);
    }
    // DISPLAYS all nodes in order, returns count of courses
    protected int display_all_courses(Course root){
        if(root == null)
            return 0;
        int count = 0 ;
        display_all_courses(root.getLeft());
        count += root.display_course();
        display_all_courses(root.getRight());
        return count;
    }
    //remove all just sets this.root to null
    public Course remove_all() {
        if (this.root != null) {
            this.root = null;
        }
        return null;
    }
    //Wrapper for removing an individual course from a tree
    public Course remove_individual(String to_remove) {
        if (root == null || to_remove == null) return null;
        if(this.root.getLeft() == null && this.root.getRight() == null && to_remove.equals(root.getName())){
            System.out.println("Removed " + root.getName() + " Successfully.");
            this.root = null;
            return null;
        }
        return remove_individual(root, to_remove);
    }
    //Goes through comparing names then goes to the appropriate location checks its children 3 cases
    //Then removes accordingly
    private Course remove_individual(Course root, String to_remove) {
        if(root == null)
            return null;
        int compare = to_remove.compareToIgnoreCase(root.getName());
        if(compare < 0)
            root.setLeft(remove_individual(root.getLeft(),to_remove));
        else if(compare > 0)
            root.setRight(remove_individual(root.getRight(),to_remove));
        else{
            if(root.getLeft() == null && root.getRight() == null){
                System.out.println("Removed " + root.getName() + " Successfully.");
                return null;
            }else if(root.getLeft() == null){
                System.out.println("Removed " + root.getName() + " Successfully.");
                return root.getRight();
            }else if(root.getRight() == null){
                System.out.println("Removed " + root.getName() + " Successfully.");
                return root.getLeft();
                //We're trying to remove a course with 2 children
            }else{
                //Save the IOS's data
                int saveID = searchMinID(root.getRight());
                String saveName = searchMinName(root.getRight());
                root.setName(saveName);
                root.setID(saveID);
                root.setRight(remove_individual(root.getRight(),to_remove));
                System.out.println("Removed " + root.getName() + " Successfully.");
            }
        }
        return root;
    }
    //wrapper for retrieve course
    public int retrieve_course(Tree newTree, String to_find) {
        if (root == null)
            return 0;
        return retrieve_course(root, newTree, to_find);
    }
    //Pass in new tree object then add to it based on matching name to_find
    private int retrieve_course(Course root, Tree newTree, String to_find) {
        if (root == null)
            return 0;
        int count = 0;
        int compare = to_find.compareToIgnoreCase(root.getName());
        if(compare < 0)
            root.setLeft(remove_individual(root.getLeft(),to_find));
        else if(compare > 0)
            root.setRight(remove_individual(root.getRight(),to_find));
        else{
            ++count;
            newTree.add_course(root.getName(),root.getID());
        }
        return count;
    }


    //These functions are used when removing individual course from tree
    private int searchMinID(Course root) {
        if (root.getLeft() != null) {
            return searchMinID(root.getLeft());
        }
        return root.getID();
    }
    //These functions are used when removing individual course from tree
    private String searchMinName(Course root){
       if(root.getLeft() != null){
           return searchMinName(root.getLeft());
       }
       return root.getName();
    }
    //These functions are used when removing individual course from tree
    private Course setMinNULL(Course root){
        if(root.getLeft()!= null){
            return setMinNULL(root.getLeft());
        }
        return root;
    }

    //To find the IOS we pass in the root->right into the function then
    //it travels to the farthest left child then returns its position
    private Course find_IOS(Course root){
        if(root == null)
            return null;
        if(root.getLeft() == null && root.getRight() == null)
            return root;
        return find_IOS(root.getLeft());
    }
    //Wrapper for find course
    public Course find_course(String to_find){ return find_course(root,to_find);}
    //Very helpful function returns the location of the matching course "to_find"
    protected Course find_course(Course root, String to_find) {
        if (root == null)
            return null;
        if (root.getName().equals(to_find))
            return root;
        int compare = to_find.compareToIgnoreCase(root.getName());
        //Is to_find greater than root->name
        if(compare > 0){
            //go right
            return find_course(root.getRight(), to_find);
        }else{
            //go left
            return find_course(root.getLeft(), to_find);
        }
    }

}
