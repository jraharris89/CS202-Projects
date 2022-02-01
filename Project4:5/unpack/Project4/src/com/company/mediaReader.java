//Jonathon Harris - Project 4/5 - Media Organizer
/*Jonathon Harris - CS202 - Media Manager
//The purpose of this mediaReader is to read in from a local text file
//determine what kind of media we are reading in
//then we can parse out the data and insert a new media object into a class
This class/function parses the info passed in as a txt file then it
creates a new object which gets added in main.
TODO work on getting it to import multiple objects
 */
package com.company;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
//TODO Probably put this in the TREE class
    public class mediaReader {
    Media read(int userInput) {
        try {
            //System.out.println("Which type of media would you like to upload:\n 1.Video\n2.Video(w/quiz)\n3.Document");
            //Scanner userInput = new Scanner(System.in);
            //IF USER IMPORTS VIDEO
            if (userInput == 1) {
                String fileLocation = File.separator + "Users" + File.separator + "jaywon" + File.separator + "IdeaProjects" + File.separator + "Project4" + File.separator + "src" + File.separator + "com" + File.separator + "company" + File.separator + "VideoFile.txt";
                //Finds the file
                File mediaFile = new File(fileLocation);
                //use scanner to read in file
                Scanner mediaScanner = new Scanner(mediaFile).useDelimiter("---\n");
                //read in one line at a time
                //while (mediaScanner.hasNext()) {
                String getLine = mediaScanner.next();
                //Seperate with delimitor
                String[] mediaFields = getLine.split("\n");
                // Split up the fields base on newline delimitor
                String titleField = mediaFields[0];
                String topicField = mediaFields[1];
                String descriptionField = mediaFields[2];
                String commentField = mediaFields[3];
                String view_countField = mediaFields[4];
                String durationField = mediaFields[5];
                //Convert String to appropriate fields
                int viewCnt = Integer.parseInt(view_countField);
                float dur = Float.parseFloat(durationField);
                Media newMedia = new Video(titleField, topicField, descriptionField, commentField, viewCnt, dur);
                return newMedia;
                //}
                //USER CHOOSES TO UPLOAD A VIDEO w/ QUIZ
            } else if (userInput == 2) {
                String fileLocation2 = File.separator + "Users" + File.separator + "jaywon" + File.separator + "IdeaProjects" + File.separator + "Project4" + File.separator + "src" + File.separator + "com" + File.separator + "company" + File.separator + "Quiz.txt";
                //Finds the file
                File mediaFile = new File(fileLocation2);
                //use scanner to read in file
                Scanner mediaScanner = new Scanner(mediaFile).useDelimiter("---\n");
                //read in one line at a time
                String getLine = mediaScanner.next();
                //Seperate with delimitor
                String[] mediaFields = getLine.split("\n");
                // Split up the fields base on newline delimitor
                String titleField = mediaFields[0];
                String topicField = mediaFields[1];
                String descriptionField = mediaFields[2];
                String commentField = mediaFields[3];
                String view_countField = mediaFields[4];
                String durationField = mediaFields[5];
                String questionsField = mediaFields[6];
                //FOR THE QUESTION PORTION WE PARSE TILL THE END OF FILE
                //String[] eof = getLine.split("EOF");
                //String questionsField = eof[6];
                //Convert String to appropriate fields
                int viewCnt = Integer.parseInt(view_countField);
                float dur = Float.parseFloat(durationField);
                Media newMedia = new Quiz(titleField, topicField, descriptionField, commentField, viewCnt, dur, questionsField);
                return newMedia;
                //USER CHOOSES TO UPLOAD DOCUMENT
            } else if (userInput == 3) {
                String fileLocation3 = File.separator + "Users" + File.separator + "jaywon" + File.separator + "IdeaProjects" + File.separator + "Project4" + File.separator + "src" + File.separator + "com" + File.separator + "company" + File.separator + "Document.txt";
                //Finds the file
                File mediaFile = new File(fileLocation3);
                //use scanner to read in file
                Scanner mediaScanner = new Scanner(mediaFile).useDelimiter("---\n");
                //read in one line at a time
                String getLine = mediaScanner.next();
                //Seperate with delimitor
                String[] mediaFields = getLine.split("\n");
                // Split up the fields base on newline delimitor
                String titlefield = mediaFields[0];
                String topicField = mediaFields[1];
                String descriptionField = mediaFields[2];
                String commentField = mediaFields[3];
                String view_countField = mediaFields[4];
                String durationField = mediaFields[5];
                String body = mediaFields[6];
                //FOR THE QUESTION PORTION WE PARSE TILL THE END OF FILE
                //String[] eof = getLine.split("EOF");
                //String body = eof[6];
                //Convert String to appropriate fields
                int viewCnt = Integer.parseInt(view_countField);
                float dur = Float.parseFloat(durationField);
                Media newMedia = new Documents(titlefield, topicField, descriptionField, commentField, viewCnt, body);
                return newMedia;
            } else
                System.out.println("Invalid option.");

            //System.out.println("Next Line: " + getLine);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(mediaReader.class.getName()).log(Level.SEVERE, "Couldn't find file.", ex);
            ex.printStackTrace();
        }
        return null;
    }
}