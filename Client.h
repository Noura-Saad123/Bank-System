
#ifndef CLIENT_H
#define CLIENT_H
#include<string>
#include "Card.h"
#include "Person.h"
#include<vector>
#include "Leon.h"
#include "Account.h"
using namespace std;
class Client  : public Person
{

	public:
		Client(){
		}
		void setCard(Card card){
			this->MyCard = card;
		}
		Card getMyCard(){
			return MyCard;
		}
		void setAccount(Account account ){
			this->account = account;
		}
		Account getAccount(){
			return account;
		}
		vector<Leon>getLeons(){
			return myLeons;
		}
		void setLeons(vector<Leon>leons){
			this->myLeons = leons;
		}
		void setIsActive(bool isActive){
			this->active = isActive;
		}
		bool isActive(){
			return active;
		}
		void addLeon(Leon leon){
			myLeons.push_back(leon);
		}
	private:
		//fullName,nationalId,phone,
		Card MyCard;
		Account account;
		vector<Leon>myLeons;
		bool active;
};

#endif
