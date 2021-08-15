
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "ValidationManager.h"
#include <string>
using namespace std;
class Account
{
	public:
		void setBalance(double b){
			if(b>=validationManager.getMinBalance()){
				balance = b;
			}
		}
		double getBalance(){
			return balance;
		}
		void setID(int s){
			id = s;
		}
		int getID(){
			return id;
		}
		void setCreationDate(Date d){
			creationDate = d;
		}
		Date getCreationDate(){
			return creationDate;
		}
	private:
		double balance;//min =1000
		int id;
		Date creationDate;//dd/mm/yyyy
		ValidationManager validationManager;
};

#endif
