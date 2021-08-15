
#ifndef PARSER_H
#define PARSER_H
#include "Client.h"
#include <string>
#include <sstream>
#include <vector>
#include "Date.h"
#include "Card.h"
#include "Leon.h"
#include<iostream>
#include "Employee.h"
using namespace std;
class Parser
{
	public:
		Client parseClient(string s){
			stringstream ob(s);
			vector<string>myVec;
			for(int i=0;i<3;i++){
				string temp;
				getline(ob,temp,'$');
				myVec.push_back(temp);
			}
			Client client;
			client.setNationId(myVec[0]);
			client.setFullName(myVec[1]);
			client.setPhone(myVec[2]);
			return client;

		}
		pair<string,Account> parseAccount(string s){
			stringstream ob(s);
			vector<string>myVec;
			for(int i=0;i<6;i++){
				string temp;
				getline(ob,temp,'$');
				myVec.push_back(temp);
			}
			string nationalID = myVec[0];
			Account account;
			account.setBalance(parseDouble(myVec[1]));
			account.setID(parseInt(myVec[2]));
			Date creationDate;
			creationDate.setDay(parseInt(myVec[3]));
			creationDate.setMonth(parseInt(myVec[4]));
			creationDate.setYear(parseInt(myVec[5]));
			account.setCreationDate(creationDate);
			pair<string,Account> p;
			p.first= nationalID;
			p.second = account;
			return p;
		}
		pair<string,Card> parseCard(string s){
			stringstream ob(s);
			vector<string>myVec;
			for(int i=0;i<7;i++){
				string temp;
				getline(ob,temp,'$');
				myVec.push_back(temp);
			}
			string nationalID = myVec[0];
			Card card;
			card.setNumber(myVec[1]);
			card.setName(myVec[2]);
			card.setCVV(myVec[3]);
			card.setPinCode(myVec[4]);

			Date date;
			date.setMonth(parseInt(myVec[5]));
			date.setYear(parseInt(myVec[6]));
			card.setExpireDate(date);
			pair<string,Card> p;
			p.first= nationalID;
			p.second = card;
			return p;
		}
		pair<string,Leon> parseLeon(string s){
			stringstream ob(s);
			vector<string>myVec;
			for(int i=0;i<7;i++){
				string temp;
				getline(ob,temp,'$');
				myVec.push_back(temp);
			}
			string nationalID = myVec[0];
			Leon leon;
			leon.setAmount(parseDouble(myVec[1]));
			leon.setProfite(parseDouble(myVec[2]));
			leon.setNumOfMonths(parseInt(myVec[3]));
			leon.setInstallMent(parseDouble(myVec[4]));
			Date date;
			date.setDay(parseInt(myVec[5]));
			date.setMonth(parseInt(myVec[6]));
			pair<string,Leon> p;
			p.first= nationalID;
			p.second = leon;
			return p;
		}
		Employee parseEmployee(string s){
			stringstream ob(s);
			vector<string>myVec;
			for(int i=0;i<7;i++){
				string temp;
				getline(ob,temp,'$');
				myVec.push_back(temp);
			}
			Employee e;
			e.setNationId(myVec[0]);
			e.setID(parseInt(myVec[1]));
			e.setFullName(myVec[2]);
			e.setPhone(myVec[3]);
			e.setSalary(parseDouble(myVec[4]));
			e.setISAdmin(parseBool(myVec[5]));
			e.setPassword(myVec[6]);
			return e;

		}
		double parseDouble(string s){
			istringstream iss(s);
			double value;
			iss >> value;
			return value;
		}
		int parseInt(string s){
			istringstream iss(s);
			int value;
			iss >> value;
			return value;
		}

		bool parseBool(string s){
			istringstream iss(s);//convert
			//stringstream ss;//split
			bool value;
			iss >> value;
			return value;
		}
	protected:
};

#endif
