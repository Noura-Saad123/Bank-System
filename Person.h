
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "ValidationManager.h"
using namespace std;
class Person
{
	public:

		void setFullName(string name){

			if(validationManager.isName(name))
			this->fullName = name;
		}
		//[0-9] len 14
		void setNationId(string id){
			if(validationManager.isValidNumber(id,14)){
				this->national_id = id;
			}
		}
		//[0-9] len 11 startwith(011,012,010,015)
		void setPhone(string phone){
			if(validationManager.isPhone(phone)){
				this->phone = phone;
			}
		}
		string getFullName(){
			return fullName;
		}
		string getNationalId(){
			return national_id;
		}
		string getPhone(){
			return phone;
		}
	protected:

		string fullName;
		string national_id;
		string phone;
		ValidationManager validationManager;
};

#endif
