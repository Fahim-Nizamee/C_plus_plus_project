#include<bits/stdc++.h>
using namespace std;
//int total_student = 0;
int student=0;

class University{
int id;
string name;
string department;
string section;
public:
void read(int id,string name, string department, string section)
{
  this->id=id;
  this->name=name;
  this->department=department;
  this->section=section;
}

int getId()
{
    return id;
}
string getName()
{
    return name;
}
string getDepartment()
{
    return department;
} 
string getSection()
{
    return section;
}
void setId(int id)
{
  this->id=id;
}

void setName(string name)
{
    this->name=name;
}
void setDepartment(string department)
{
    this->department=department;
}
void setSection(string section)
{
    this->section=section;
}
void show()
{
        cout<<endl;
        cout<<"\t#ID         :"<<getId()<<endl;
        cout<<"\t#NAME       :"<<getName()<<endl;
        cout<<"\t#DEPARTMENT :"<<getDepartment()<<endl;
        cout<<"\t#SECTION    :"<<getSection()<<endl<<endl;
}

};

class University university[100];

void save_txt_file() //Save Data in Text file.
{
   ofstream file("version3.txt");
   for(int i=0; i<student; i++)
   {
       file << university[i].getId() << endl;
       file << university[i].getName() << endl;
       file << university[i].getDepartment() << endl;
       file << university[i].getSection() << endl;
   }
   file.close();
}

void read_txt_file() //read data from text file.
{
    ifstream file("version3.txt");
    int id;
    string name;
    string department;
    string section;
    
    while (file >> id)
    {
        file.ignore();
        getline(file,name);
        file >> department;
        file >> section;
        university[student].read(id,name,department,section);
        student++;
    }
    file.close();
}

void msg()
{
     cout<<"\t_____________________________"<<endl;
     cout<<"\t|                           |"<<endl;
     cout<<"\t| PRESS 7 TO VIEW HOME PAGE |"<<endl;
     cout<<"\t|___________________________|"<<endl;

}
void add()
{
system("cls");
system("color B");
  cout<<"\tHOW MANY STUDENTS YOU WANT TO ADD : ";
  cin>>student;
  cout<<endl;
  int id;
  string name;
  string department;
  string section;

  for(int i=0; i<student; i++)
  {
      cout<<"\t->ID          :";
      cin>>id;
      cin.ignore();
      cout<<"\t->NAME        :";
      getline(cin,name);
      cout<<"\t->DEPARTMENT  :";
      cin>>department;
      cout<<"\t->SECTION     :";
      cin>>section;
      cout<<endl;
      university[i].read(id,name,department,section);

  }
  save_txt_file();
  msg();

}

void see_all_student()
{
    system("cls");
    system("color 9");
    cout<<"\tALL STUDENTS INFORMATION"<<endl<<endl;
    for(int i=0; i<student; i++)
    {
      university[i].show();
    }
    if(student==0) cout<<"\tNO STUDENTS FOUND...!!!"<<endl;
msg();
}

void see_a_student()
{
    system("cls");
    system("color 5");
    cout<<"\tENTER STUDENT ID : ";
    int x,count=0;
    cin>>x;
    cout<<endl;
    for(int i=0; i<student; i++)
    {
        if(university[i].getId()==x)
        {
          university[i].show();
          count++;
        }
    }
        if(student==0||count==0)cout<<"\tID NOT FOUND...!!!"<<endl;
         msg();
}

void see_department()
{
    system("cls");
    system("color 3");
    cout<<"\t->ENTER A DEPARTMENT : ";
    int count=0;
    string x;
    cin>>x;
    cout<<endl;
    for(int i=0; i<student; i++)
    {
        if(university[i].getDepartment()==x)
        {
          university[i].show();
          count++;
        }
    }
    if(student==0 || count==0)cout<<"\tNO STUDENTS FOUND...!!!"<<endl;
msg();
}

void see_section()
{
    system("cls");
    system("color 3");
    cout<<"\tENTER A SECTION :";
    int count=0;
    string x;
    cin>>x;
    cout<<endl;
    for(int i=0; i<student; i++)
    {
        if(university[i].getSection()==x)
        {
          university[i].show();
          count++;
        }
    }
   if(student==0 || count==0)cout<<"\tNO STUDENTS FOUND...!!!"<<endl;
msg();
}

void delete_student()
{
    system("cls");
    system("color C");
    int x, count=0;
    cout<<"\tENTER STUDENT ID : ";
    cin>>x;
    cout<<endl;
     for(int i=0; i<student; i++)
    {
        if(university[i].getId()==x)
        {
        for(int j=i; j<student-1; j++)
        {
            university[j]=university[j+1];

        }
        count++;
        student--;

        }
    }
    cout<<endl;
    save_txt_file();
    if(count==0)cout<<"\tId Not Found...!!!"<<endl;
    else cout<<"\tId Deleted successfully..!!"<<endl;
msg();
}

void edit_student()
{
   system("cls");
   system("color E");
    int x,count=0;
   cout<<"\tENTER STUDENT ID : ";
    cin>>x;
    cout<<endl;
    string name;
    string department, section;
    for(int i=0; i<student; i++)
    {
        if(university[i].getId()==x)
        {
           cin.ignore();
           cout<<"\tNAME       :";
           getline(cin,name);
           university[i].setName(name);
           cout<<"\tDEPARTMENT :";
           cin>>department;
           university[i].setDepartment(department);
           cout<<"\tSECTION    :";
           cin>>section;
           university[i].setSection(section);
           count++;
        }
    }
    save_txt_file();
    cout<<endl;
    if(count==0)cout<<"\tId Not Found...!!!"<<endl;
    else cout<<"\tId Edited successfully..!!"<<endl;
msg();
}


void home_page()
{
      system("cls");
      system("color A");
     cout<<"\t____________________________________________________"<<endl;
     cout<<"\t|                                                  |"<<endl;
     cout<<"\t|  -> PRESS 0 TO ADD STUDENTS.                     |"<<endl;
     cout<<"\t|  -> PRESS 1 TO SEE ALL STUDENTS.                 |"<<endl;
     cout<<"\t|  -> PRESS 2 TO SEE A SPECIFIC STUDENT.           |"<<endl;
     cout<<"\t|  -> PRESS 3 TO SEE A DEPARTMENT.                 |"<<endl;
     cout<<"\t|  -> PRESS 4 TO SEE A SECTION.                    |"<<endl;
     cout<<"\t|  -> PRESS 5 TO DELETE A STUDENT.                 |"<<endl;
     cout<<"\t|  -> PRESS 6 TO EDIT A STUDENT.                   |"<<endl;
     cout<<"\t|  -> PRESS 8 TO SEE STUDENTS IN ASCENDING ORDER.  |"<<endl;
     cout<<"\t|  -> PRESS 9 TO EXIT.                             |"<<endl;
     cout<<"\t|__________________________________________________|"<<endl<<endl;
}

void sort_student()
{
    system("cls");
    system("color B");
    int i, j,temp;
    for(i=0; i<student; i++)
    {
        for(j=i+1; j<student; j++)
        {
            if(university[i].getId()>university[j].getId())
            {
                swap(university[i],university[j]);
            }
        }
    }
    for(i=0; i<student; i++)
    {
        university[i].show();
    }
   if(student==0) cout<<"\tNO STUDENTS FOUND...!!!"<<endl;
   save_txt_file();
msg();
}


int main()
{
     read_txt_file();
     home_page();
     while(1)
     {
         int x;
         cout<<endl;
         cout<<"\t[ENTER] :";
         cin>>x;
         cout<<endl;
         if(x==0)add();
         if(x==1)see_all_student();
         if(x==2)see_a_student();
         if(x==3)see_department();
         if(x==4)see_section();
         if(x==5)delete_student();
         if(x==6)edit_student();
         if(x==7)home_page();
         if(x==8)sort_student();
         if(x==9)break;
     }
     return 0;
}

