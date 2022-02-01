/* Jonathon Harris - Project 5 - Media Manager
This class is my binary search tree, each node of the binary tree is a course
each course has a playlist, each playlist index is a list of media based on topic.
This class is responsible for managing courses: adding, removing, displaying courses.
 */
package com.company;

public class Tree {
    private Course root;//my root reference
    public Course add_course(String course_name, int course_id){
    return add_course(course_name,course_id,root);
    }
    protected Course add_course(String course_name, int course_id, Course root){
        if(root == null){
            root = new Course(course_name,course_id);
            return root;
        }
        //compare the roots string name and the root name we're adding
        int compare = root.getName().compareToIgnoreCase(course_name);
        //If the course we are trying to add to our tree is less than roots course_name
        if(compare>0){
            add_course(course_name, course_id, root.getLeft());
            //else it is greater or equal to
        }else{
            add_course(course_name, course_id, root.getRight());
        }
        return root;
    }
    //WRAPPER FOR DISPLAY ALL
    public int display_all(){
        if(root == null)
            return 0 ;
        return display_all(root);
    }
    // DISPLAYS all nodes in order, returns count of courses
    protected int display_all(Course root){
        if(root == null)
            return 0;
        int count = 0 ;
        root.getLeft();
        count += root.display_course();
        root.getRight();
        return count;
    }
    public Course remove_all(){if(root==null)return null; return remove_all(root);}
    //TODO Double check this works
    public Course remove_all(Course root){
        if(root == null)
            return null;
       root.setLeft(remove_all(root.getLeft())); // suspect
       root.setRight(remove_all(root.getRight()));// suspect
       root = null;
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
    public Course find_course(String to_find){ return find_course(root,to_find);}
    protected Course find_course(Course root, String to_find){
        if(root == null)
            return null;
        if(root.getName().equals(to_find)){
            return root;
        }
        int compare = to_find.compareToIgnoreCase(root.getName());
        //Is to_find greater than root->name
        if(compare > 0){
            //go right
            find_course(root.getRight(), to_find);
        }else{
            //go left
            find_course(root.getLeft(), to_find);
        }
        return root;
    }

}
