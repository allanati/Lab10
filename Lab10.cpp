#include <iostream>
#include <string>
#include <vector>
#define n 2

class Student
{
	private:
		std::string m_name = " ";
		std::string m_surname = " ";
		std::string m_lecturer = " ";
		int m_ID = 0;
	public:
		/*/Student(std::string name, std::string surname, int ID)
		{
			m_name = name;
			m_surname = surname;
			m_ID = ID;
		};*/
		Student() {}	//default constructor
		~Student() {
			std::cout << "Destructor works!" << std::endl;
		}
		void StudInfo()
		{
			std::cout << m_name << " ";
			std::cout << m_surname << " ";
			std::cout << m_ID << std::endl;
		}
		int RetID()
		{
			return m_ID;
		}
		void SetName(std::string name)
		{
			m_name = name;
		}
		void SetSurname(std::string surname)
		{
			m_surname = surname;
		}
		void SetID(int ID)
		{
			m_ID = ID;
		}
};

class Lecturer
{
	private:
		std::string m_surname;
		int m_id;
		std::vector <Student*> m_students;
		int m_SpisStud[4];
		int m_x = 0;
	public:
		Lecturer(std::string surname, int id)
		{
			m_surname = surname;
			m_id = id;
		};

		~Lecturer() {
			for (int i = 0; i < m_students.size(); i++) {
				m_students[i] = 0;
			}
			std::cout << "Destructor works!" << std::endl;
		}

		void addStud(Student* stud)
		{
			m_students.push_back(stud);
			m_SpisStud[m_x] = stud->RetID();
			m_x += 1;
		}
		void ShowStudID()		// IDs of all lecturer's students
		{
			for (int i = 0; i < m_students.size(); i++)
			{
				std::cout << m_students[i]->RetID() << std::endl;
			}
		}
		void IsItYourClass(int x)		// checks if this student is in the lecturer's class
		{
			for (int i = 0; i < m_students.size(); i++)
			{
				if (x == m_SpisStud[i])
				{
					std::cout << "Come in, you're right on time." << std::endl;
					return;
				}
			}
			std::cout << "You're not my student, go away." << std::endl;
		}
};

int main()
{
	Student stud[n];	// n - number of students
	for (int i = 0; i < n; i++) {	
		std::string name, surname;
		int ID;
		std::cin >> name >> surname >> ID;
		stud[i].SetName(name);
		stud[i].SetSurname(surname);
		stud[i].SetID(ID);
	}
	Lecturer lec1("Hudenko", 101);
	for (int i = 0; i < n; i++) 
		lec1.addStud(&stud[i]);
	lec1.ShowStudID();
	lec1.IsItYourClass(10);
}