#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Student{
    private:
    int rollNo;
    string name,dum[4];
    float percentage;
    

    public:
    //Adds the Student to the Record 
        void addStudent(){
            ofstream fout;
            fout.open("studentData.txt",ios::app);

            cout<<"\nEnter the name of the student : ";
            cin>>name;
            cout<<"Enter the roll number : ";
            cin>>rollNo;
            cout<<"Enter the percentage : ";
            cin>>percentage;

            fout<<rollNo<<"\n"<<name<<"\n"<<percentage<<"%\n\n";
            fout.close();


        }
    //Helps in viewing the student
        void viewStudent(int count){
            cout<<"\n"<<count<<")\n";
            cout<<"Name : "<<dum[1]<<"\n";
            cout<<"Roll no : "<<dum[0]<<"\n";
            cout<<"Percentage : "<<dum[2]<<"\n\n";
        }


    //Searches student by roll number    
        void searchByRoll(string r){
            ifstream fin;
            fin.open("studentData.txt");
            if (!fin)
            {
              cout<<"File not found"<<endl;
            }
            string line;
            int i=0;
            bool c = 0,rec=1;
            while (getline(fin,line))
            {
                if (r == line)
                {
                c=1;
                }
                if (c)
                {
                dum[i] = line;
                i++;
                }
                
                if (i==3)
                {
                 c=0;
                 rec=0;
                 viewStudent(1);
                 break;
                }
                
                
            }
            if (rec)
            {
                 cout<<"\nStudent Record Not Found!!\n";
            }
            
          
            fin.close();
            
        }
    
    //Shows all the students
        void viewAllStudents(){
            ifstream fin;
            fin.open("studentData.txt");
            if (!fin)
            {
              cout<<"File not found"<<endl;
            }
            
            string line;
            int i =0,count=1;
            bool b=0;
            while (getline(fin,line))
            {
               if (b)
                {
                   b=0;
                   continue;
                }
               dum[i] = line;
               i++;
                
                
               if (i==3)
               {
                viewStudent(count);
                i=0;
                count++;
                b=1;
               }
               
            }
           
            
            fin.close();
            

            

        }

    //Deletes the student from the record
        void deleteStudent(string r){
            ofstream fout;
            fout.open("temp.txt",ios::app);
           
            
            ifstream fin;
            fin.open("studentData.txt");
             if (!fin)
            {
               cout<<"File not found !";
            }
             string line;
            int i=0;
            bool c = 0,rec=0;
            while (getline(fin,line))
            {
                if (c) {
              
                i++;
                
                if (i==4)
                {
                  c=0;
                
                }
                continue;
                }
               
                if (r == line)
                {
                    c=1;
                   
                    rec=1;
                    i++;
                
                }else{
                    fout<<line<<"\n";
                    
                    
                }
                
                
                
                
                
            }
            fout.close();
            fin.close();

            remove("studentData.txt");
            rename("temp.txt","studentData.txt");
            if (rec)
            {
                cout<<"\nDeleted !!\n";
            }else{
                cout<<"\nStudent Record Not Found!!\n";
            }
            
           
        }

};


int main(){
    Student s;
    bool m=1;
    string roll;
    cout<<"\nWelcome to Student Record Manager\n";

    
    while (m)
    {
        cout<<"\n1.Add Student\n2.View All Students\n3.Search by Roll Number\n4.Delete Student\n5.Exit\n\n";
    int choose;
    cout<<"Enter your choice : ";
    cin>>choose;

    switch (choose)
    {
    case 1:
        s.addStudent();
        cout<<"\nAdded !!\n";
        break;
    case 2:
        s.viewAllStudents();
        break;
    case 3:
       
        cout<<"\nEnter roll no : ";
        cin>>roll;
        s.searchByRoll(roll);
        break;
    case 4:
        cout<<"\nEnter roll no : ";
        cin>>roll;
        s.deleteStudent(roll);
       
        break;
    case 5:
        cout<<"\nExitinggg!!";
        m=0;
        break;
    default:
        cout<<"Invalid Option!!\n";
        break;
    }
    }
    
    
    return 0;
}