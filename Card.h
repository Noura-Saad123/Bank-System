
#ifndef CARD_H
#define CARD_H
#include<string>
#include "Date.h"
#include "ValidationManager.h"
using namespace std;
class Card
{
	public:
		void setNumber(string s){
			if(validationManager.isValidNumber(s,14)){
				number = s;
			}
		}
		void setCVV(string s){
			if(validationManager.isValidNumber(s,validationManager.getCVV_SIZE())){
				cvv =s;
			}
		}

		void setPinCode(string s){
			if(validationManager.isValidNumber(s,4)){
				pinCode = s;
			}
		}

		void setName(string s){
			if(validationManager.isName(s)){
				name = s;
			}
		}

		void setExpireDate(Date d){
			expireDate = d;
		}
		Date getExpireDate(){
			return expireDate;
		}
		string getNumber(){
			return number;
		}
		string getCVV(){
			return cvv;
		}
		string getName(){
			return name;
		}
		string getPinCode(){
			return pinCode;
		}
	private:
		string number;//len 14 digits
		string cvv;// len 3 digits
		string name;// len min =10 and max 20
		string pinCode;//len 4 and digits
		Date expireDate;//mm/yyyy
		ValidationManager validationManager;
};

#endif
