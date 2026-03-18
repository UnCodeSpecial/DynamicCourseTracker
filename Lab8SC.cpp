// Identification comments code block
// UnCodeSpecial
// Lab 8
// Editor(s) used: Repl.it IDE
// Compiler(s) used: Repl.it IDE
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <cstring>
using std::string;

#include <algorithm>
using std::swap;

#include <fstream>
using std::fstream;

#include <cstdlib>

#include <ctime>

void printMenu(int, int);

struct Course
{
  
  char name[13];
  int year;
  int units;
  char grade;
  
};

void doubleCapacity(Course*& array, int& capacity) // function to double the capacity
{
  Course* temp = new Course[2 *capacity];
  for (int i = 0; i < capacity; i++)
  {
    temp[i] = (array)[i];
  }
  delete [  ] array;
  array = temp;
  capacity *= 2;

}



int main()
{
  // identification output code block
  cout << "Lab 8\n";
  cout << "UnCodeSpecial\n";
  cout << "Editor(s) used: Repl.it IDE\n";
  cout << "Compiler(s) used: Repl.it IDE\n";
  cout << "File: " << __FILE__ << "\n"; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  int size = 0, courseObjectCount = 2;
  // declaring size and capacity
  
  Course* courseArray = new Course[courseObjectCount];
  //creating a dynamic array
    
  char choice;
  
  while(true)
  {
    // print menu
    printMenu(size, courseObjectCount);
    cout << "\nYour choice > ";
    cin>>choice;

    if(choice == 'A' || choice == 'a') // getting details from user
    {
      
      char buf[13];
      cout << "\n";
      // doubling size if the size is equal to capacity
      if (size == courseObjectCount ) doubleCapacity(courseArray, courseObjectCount);

        
      // Enter the details from User
      cin.ignore(1000,10);
      cout<<"Enter a courses' name:"<< endl;
      cin.getline(buf, 13);
    
      for (int i = 0; i < 13; i++)
      {
        courseArray[size].name[i] = toupper(buf[i]);
      }

    

      cout<<"Enter the year for "<<courseArray[size].name<<" [like 2016]:"<<endl;
      cin >> courseArray[size].year;
      

      cout<<"Enter the units for "<<courseArray[size].name<<" [0, 1, 2,...]:"<<endl;
      cin>>courseArray[size].units;
  
      cout<<"Enter the grade for "<<courseArray[size].name<<" [A, B,..., X if still in progress or planned]:"<<endl;
      cin>>courseArray[size].grade;
      courseArray[size].grade = toupper(courseArray[size].grade);
      
    
      // incrementing size by 1 if course if fully added
      size++;

    }

    else if(choice == 'L'|| choice == 'l')
    {
      // printing courses
      cout<<"\nCourse Year Units Grade" <<endl;
      cout << "-----------------------" << endl;
    
      for(int t = 0 ; t < size; t++)
      {
      
        cout << courseArray[t].name; 
        cout.width(6);
        cout <<  courseArray[t].year;
        cout.width(4);
        cout << courseArray[t].units;
        cout.width(6);
        cout << courseArray[t].grade;
        cout << "\n";
      
      }
    }

    else if(choice == 'C' || choice == 'c')
    {
    // sort the values hi-to-lo
      cout << "\n";
      for (int i = 0; i < size; i++)
      {
        for (int j = i + 1; j < size; j++)
        {
          if (courseArray[i].name < courseArray[j].name)
          swap(courseArray[i], courseArray[j]);
        }
      }
      cout<<"\nCourse Year Units Grade" <<endl;
      cout << "-----------------------" << endl;
      for(int t = 0 ; t < size; t++)
      {
      
        cout << courseArray[t].name; 
        cout.width(6);
        cout <<  courseArray[t].year;
        cout.width(4);
        cout << courseArray[t].units;
        cout.width(6);
        cout << courseArray[t].grade;
        cout << "\n";
      
      }
      printMenu(size, courseObjectCount);
    }


    else if(choice == 'Y' || choice == 'y')
    {
      // sort the values hi-to-lo
      cout << "\n";
      for (int i = 0; i < size; i++)
      {
        for (int j = i + 1; j < size; j++)
        {
          if (courseArray[i].year < courseArray[j].year)
          swap(courseArray[i], courseArray[j]);
        }
      }
      cout<<"\nCourse Year Units Grade" <<endl;
      cout << "-----------------------" << endl;
      for(int t = 0 ; t < size; t++)
      {
      
        cout << courseArray[t].name; 
        cout.width(6);
        cout <<  courseArray[t].year;
        cout.width(4);
        cout << courseArray[t].units;
        cout.width(6);
        cout << courseArray[t].grade;
        cout << "\n";
      
      }
      printMenu(size, courseObjectCount);

    }


    else if(choice == 'U' || choice == 'u')
    {
    // sort the values hi-to-lo
      cout << "\n";
      for (int i = 0; i < size; i++)
      {
        for (int j = i + 1; j < size; j++)
        {
          if (courseArray[i].units < courseArray[j].units)
          swap(courseArray[i], courseArray[j]);
        }
      }
      printMenu(size, courseObjectCount);
      cout<<"\nCourse Year Units Grade" <<endl;
      cout << "-----------------------" << endl;
      for(int t = 0 ; t < size; t++)
      {
      
        cout << courseArray[t].name; 
        cout.width(6);
        cout <<  courseArray[t].year;
        cout.width(4);
        cout << courseArray[t].units;
        cout.width(6);
        cout << courseArray[t].grade;
        cout << "\n";
      
      }

    }
    else if(choice == 'G' || choice == 'g')
    {
      // sort the values hi-to-lo
      cout << "\n";
      for (int i = 0; i < size; i++)
      {
        for (int j = i + 1; j < size; j++)
        {
          if (courseArray[i].grade < courseArray[j].grade)
          swap(courseArray[i], courseArray[j]);
        }
      }
      printMenu(size, courseObjectCount);
      cout<<"\nCourse Year Units Grade" <<endl;
      cout << "-----------------------" << endl;
      for(int t = 0 ; t < size; t++)
      {
      
        cout << courseArray[t].name; 
        cout.width(6);
        cout <<  courseArray[t].year;
        cout.width(4);
        cout << courseArray[t].units;
        cout.width(6);
        cout << courseArray[t].grade;
        cout << "\n";
      
      }
 
    }
    else if(choice == 'Q' || choice == 'q')
    {
      //serialise down if user quits
      fstream fout;      
      fout.open("cards.dat", ios::binary | ios::out);      
      fout.write(reinterpret_cast<char*>(&courseObjectCount),  sizeof(int));      
      fout.write(reinterpret_cast<char*>(&size), sizeof(int));      
      fout.write(reinterpret_cast<char*>(courseArray), size * sizeof(Course)); fout.close();
      break;
    }
  }

  return 0;
}

void printMenu(int size, int courseObjectCount)
{
  // function to print the menu
  cout<<"Array size: "<< size << " capacity: "<< courseObjectCount << endl;    
  cout<<"MENU"<< endl;
  cout<<"Press A ..Add a course"<< endl;
  cout<<"Press L ..List all courses"<< endl;
  cout<<"Press C ..Arrange by course"<< endl;
  cout<<"Press Y ..arrange by Year"<< endl;
  cout<<"Press U ..arrange by Units"<< endl;
  cout<<"Press G ..arrange by Grade"<< endl;
  cout<<"Press Q ..Quit"<< endl;
  

}
