import java.util.*;
import java.lang.*;

//user defind exceptiom classes
class myxception1 extends Exception {
	String s1;
	myxception1(String s2){
		s1 = s2;
	}
	public String toString() {
		return ("myxception occured : " + s1);
	}
}

class myxception2 extends Exception {
	String s1;
	myxception2(String s2){
		s1 = s2;
	}
	public String toString() {
		return ("myxception occured : " + s1);
	}
}

//multilevel inheritance achived by following code
class personal_reocrd { 
	String namep, address,  DOB, bg;
	int height, contact_no;
	int x, cnt = 0;
	Scanner in = new Scanner(System.in);
	void get_personal_record(int i) {
		try {
			System.out.println("Enter  personal data of "+ i+1 + " employee");
			System.out.println("Enter name ");
			namep = in.nextLine();
			System.out.println("Enter address ");
			address = in.nextLine();
			System.out.println("Enter contact number without(+91) ");
			contact_no = in.nextInt();
			x = contact_no;
			//to check the contact number have only 10 digits//
			while(x != 0){
				x /= 10;
				++cnt;
			}
			//if contact number is greater or less than 10 digits//
			if(cnt < 10 || cnt > 10){
				throw new myxception1("enter valid contact(size should 10 digits)");
			}
			System.out.println("Enter DOB ");
			DOB = in.nextLine();
			System.out.println("Enter blood group ");
			bg = in.nextLine();
			System.out.println("Enter height in meter ");
			height = in.nextInt();	
		}
		catch(InputMismatchException ex) {
			//System.out.println("Inbuilt Exception occur" + ex + "Enter valid data next time!");
			//System.exit(0);
		}
		catch(myxception1 me) {
			System.out.println(me);
			System.exit(0);
		}
		

	}
	//show the information we have given//
	void show_personal_record(int i) {
		System.out.println("\nBio Data of " + i+1 + " employee\n");
		System.out.println("personal record ");
		System.out.println("Name - " + namep);
		System.out.println("Aderess - " + address);
		System.out.println("Contat number(without +91) - " + contact_no);
		System.out.println("DOB - " + DOB);
		System.out.println("Blood Group - " + bg);
		System.out.println("Height - " + height + "meter");
	}
}

//academic record details// 
class Academic_record extends personal_reocrd {
	int ssc_m, hsc_m, yof_passing, x;
	float degree_p;
	String namea,qualification;
	void get_Academic_reord(int i) {
		try {
			System.out.println("Enter Academic Data of " + i+1 + " employee");
			System.out.println("Enter name as per SSC ");
			namea = in.nextLine();
			System.out.println("Enter qualification ");
			qualification = in.nextLine();		
			System.out.println("Enter marks obtained in SSC ");
			ssc_m = in.nextInt();		
			System.out.println("Enter marks obtained in HSC ");
			hsc_m = in.nextInt();
			System.out.println("Enter degree percentage ");
			degree_p = in.nextFloat();
			System.out.println("Enter year of passing(only year) ");
			yof_passing = in.nextInt();
			x = yof_passing;
			cnt = 0;
			while(x != 0) {
				x /= 4;
				++cnt;
			}
			if(cnt < 4 )
				throw new myxception2("enter valid year");
		}
		catch(InputMismatchException ex) {
			//System.out.println("Inbuilt Exception occur" + ex);
			//System.exit(0);
		}
		catch(myxception2 me) {
			System.out.println(me);
			System.exit(0);
		}
				
	}
	void show_Academic_reocrd() {
		System.out.println("Academic Record");		
		System.out.println("Name as per SSC - " + namea);
		System.out.println("qualification(completed) - " + qualification);
		System.out.println("SSC marks - " + ssc_m);
		System.out.println("HSC marks - " + hsc_m);
		System.out.println("Degree percentage" + degree_p + "%");
		System.out.println("Year of passing - " + yof_passing);
	}
}

//professional record details//
class professional_record extends Academic_record { 

	int salary, emp_id, exp;
	String emp_name, designation, j_date;
	void get_professional_record(int i) {
		try {
			System.out.println("Enter Professional Data of " + i+1 + " employee");
			System.out.println("Enter name  ");
			emp_name = in.nextLine();
			System.out.println("Enter designation ");
			designation = in.nextLine();
			System.out.println("Enter Joining date ");
			j_date = in.nextLine();
			System.out.println("Enter salary ");
			salary = in.nextInt();
			System.out.println("Enter Employee ID ");
			emp_id = in.nextInt();
			System.out.println("Enter year of experiance ");
			exp = in.nextInt();	
		}
		catch(InputMismatchException ex) {
			//System.out.println("Inbuilt Exception occur" + ex);
			//System.exit(0);
		}	
		
	} 
	void show_professional_record() {
		System.out.println("Professional Record");		
		System.out.println("employee name- " + emp_name);
		System.out.println("designation - " + designation);
		System.out.println("Joining Date - " + j_date);
		System.out.println("salary - " + salary);
		System.out.println("employee id - " + emp_id);
		System.out.println("experiance of working - " + exp + " yrs");
	}
	public static void main(String[] args) {
	int n;
	Scanner in = new Scanner(System.in);
	System.out.println("Enter number of employees = ");
	try {
		n = in.nextInt();
		professional_record[] p;
		p = new  professional_record[n];
		for(int i = 0; i < n; i++)
			p[i] = new professional_record();

		for(int i = 0; i < n; i++) {
			p[i].get_personal_record(i);
			p[i].get_Academic_reord(i);
			p[i].get_professional_record(i);
		}
		for(int i = 0; i < n; i++) {
			p[i].show_personal_record(i);
			p[i].show_Academic_reocrd();
			p[i].show_professional_record();
		}	
	}
	catch(InputMismatchException ex) {
		//System.out.println("Inbuilt Exception occur" + ex + "Enter valid data next time!");
		//System.exit(0);
	}
	catch( OutOfMemoryError e) {
		System.out.println("Inbuilt Exception occur" + e);
		System.exit(0);
	}
    }
}