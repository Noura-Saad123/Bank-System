
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
class Employee :public Person
{
	public:
		void setSalary(double s){
			if(s>=2400)
			salary= s;
		}
		double getSalary(){
			return salary;
		}
		void setID(int id){
			this->emp_id = id;
		}
		int getId(){
			return emp_id;
		}
		void setISAdmin(bool admin){
			this->admin = admin;
		}
		bool isAdmin(){
			return admin;
		}
		void setPassword(string p){
			password = p;
		}
		string getPassword(){
			return password;
		}
	protected:
		double salary;
		int emp_id;
		bool admin;
		string password;
};

#endif
