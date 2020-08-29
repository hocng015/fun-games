package Student_Database;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.scene.text.Text;
import javafx.scene.text.Font;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class student_data extends Application {
	private Text greet = new Text("*Note all parts must be completed* 1) Register a Student (2) Search for a student (3) Show Information on All Student");
	private Text printInfo = new Text();
	private Label first = new Label("First Name:");
	private Label last = new Label("Last Name:");
	private Label phone = new Label("Phone Number:");
	private Label address = new Label("Address:");
	private Label major = new Label("Major:");
	private TextField stu_first = new TextField("Enter His/Her first name"); 
	private TextField stu_last = new TextField("Enter His/Her last name");
	private TextField stu_phone = new TextField("Enter His/Her Phone Number");
	private TextField stu_address = new TextField("Enter His/Her Address");
	private TextField stu_major = new TextField("Enter His/Her Major");
	private Button enter = new Button("Enter");
	private Button search = new Button("Search");
	private Button delete = new Button("Delete");
	private Button printAll = new Button("Show All");

	public void start(Stage primaryStage) throws Exception{
		primaryStage.setTitle("Student Database");
		greet.setFont(new Font("Helvetica", 14));
		printInfo.setFont(new Font("Helvetica", 14));
		printAll.setOnAction(this::read);
		enter.setOnAction(this::write);
		search.setOnAction(this::search);
		delete.setOnAction(this::delete);
		GridPane gridPane = new GridPane();
		gridPane.setMinSize(400, 200); 
		gridPane.setPadding(new Insets(10, 10, 10, 10)); 
	    gridPane.setVgap(10); 
	    gridPane.setHgap(10); 
	    gridPane.add(greet, 0, 0);
	    gridPane.add(first, 0, 1);
	    gridPane.add(stu_first, 0, 2);
	    gridPane.add(last, 0, 3);
	    gridPane.add(enter, 1, 3);
	    gridPane.add(stu_last, 0, 4);	    
	    gridPane.add(phone, 0, 5);
	    gridPane.add(search, 1, 5);
	    gridPane.add(stu_phone, 0, 6);
	    gridPane.add(address, 0, 7);
	    gridPane.add(printAll, 1, 7);
	    gridPane.add(stu_address, 0, 8);
	    gridPane.add(major, 0, 9);
	    gridPane.add(delete, 1, 9);
	    gridPane.add(stu_major, 0, 10);
	    gridPane.add(printInfo, 0, 12, 1, 4);
        Scene scene = new Scene(gridPane, 800, 1000); 
        primaryStage.setWidth(1000);
        primaryStage.setHeight(800);
        primaryStage.setScene(scene); 
        primaryStage.show();
	}
	
	public void write(ActionEvent e) {
			try {
				File file = new File("students.txt");
				FileWriter fw = new FileWriter(file, true);
				String first = stu_first.getText();
				String last = stu_last.getText();
				String phone = stu_phone.getText();
				String address = stu_address.getText();
				String major = stu_major.getText();	
				fw.write(first+"\n"+last+"\n"+phone+"\n"+address+"\n"+major);
				fw.close();
		        printInfo.setText(" Registration Successfully.");
		      } catch (IOException e1) {
		        printInfo.setText("An error occurred.");  
		        e1.printStackTrace();
		      }		
	}
	
	public void read(ActionEvent e) {
			try {
		        File myObj = new File("students.txt");
		        Scanner myReader = new Scanner(myObj);
		        while (myReader.hasNextLine()) {
		          String data = myReader.nextLine();
		          printInfo.setText(data);
		        }
		        myReader.close();
		      } catch (FileNotFoundException e1) {
		        printInfo.setText("An error occurred.");
		        e1.printStackTrace();
		       }
	}
	
	public void search(ActionEvent e) {
		try {
			File file = new File("students.txt");
			File temp = File.createTempFile("file", ".txt", file.getParentFile());
			String charset = "UTF-8";
			String first = stu_first.getText();
			String last = stu_last.getText();
			String phone = stu_phone.getText();
			String address = stu_address.getText();
			String major = stu_major.getText();
			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(file), charset));
			for (String line; (line = reader.readLine()) != null;) {
				if(line.equals(first)) {
					if(line.equals(last)) {
						if(line.equals(phone)){
							if(line.equals(address)) {
								if(line.equals(major)) {
									printInfo.setText("Found A Match!");									
								}
							}
						}
					}
				}
				else {
					printInfo.setText("No Match");	
				}
			}
			
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}
	
	public void delete(ActionEvent e) {
		try {
			File file = new File("students.txt");
			File temp = File.createTempFile("file", ".txt", file.getParentFile());
			String charset = "UTF-8";
			String first = stu_first.getText();
			String last = stu_last.getText();
			String phone = stu_phone.getText();
			String address = stu_address.getText();
			String major = stu_major.getText();
			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(file), charset));
			PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(temp), charset));
			for (String line; (line = reader.readLine()) != null;) {
				line = line.replace(first,"");
				line = line.replace(last,"");
				line = line.replace(phone,"");
				line = line.replace(address,"");
				line = line.replace(major,"");
				writer.println(line);
			}
			reader.close();
			writer.close();
			file.delete();
			temp.renameTo(file);
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}
	
	public static void main(String[] args)
    {
        launch(args);
    }
}