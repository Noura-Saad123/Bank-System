
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include "Client.h"
#include "Card.h"
#include <sstream>
#include <vector>
#include<iostream>
#include "Parser.h"
#include "Employee.h"
using namespace std;
class FileManager
{
	public:
		void clear(){
			fstream file;
			file.open("clients.txt",ios::out);
			file.close();
			file.open("accounts.txt",ios::out);
			file.close();
			file.open("cards.txt",ios::out);
			file.close();
			file.open("leons.txt",ios::out);
			file.close();
		}
		void save(Client client){
			fstream file;
			file.open("clients.txt",ios::app);
			if(client.getNationalId().size()==0)return;
			file<<client.getNationalId()<<"$"<<client.getFullName()
			<<"$"<<client.getPhone()<<"\n";
			if(client.getMyCard().getCVV()!=""){
				save(client.getMyCard(),client.getNationalId());
			}
			if(client.getLeons().size()>0){
				for(int i=0;i<client.getLeons().size();i++){
					save(client.getLeons()[i],client.getNationalId());
				}
			}
			save(client.getAccount(),client.getNationalId());
			file.close();
		}
		void save(Card card,string nationalId){
			fstream file;
			file.open("cards.txt",ios::app);
			file<<nationalId<<"$"<<card.getNumber()<<"$"
			<<card.getName()<<"$"<<card.getCVV()<<"$"<<card.getPinCode()<<"$"
			<<card.getExpireDate().getMonth()<<"$"<<card.getExpireDate().getYear()<<"\n";
			file.close();
		}
		void save(Account account,string nationalId){
			fstream file;
			file.open("accounts.txt",ios::app);
			file<<nationalId<<"$"<<account.getBalance()<<"$"
			<<account.getID()<<"$"<<account.getCreationDate().getDay()
			<<"$"<<account.getCreationDate().getMonth()<<"$"
			<<account.getCreationDate().getYear()<<"\n";
			file.close();
		}
		void save(Leon leon,string nationalId){
			fstream file;
			file.open("leons.txt",ios::app);
			file<<nationalId<<"$"<<leon.getAmount()<<"$"
			<<leon.getProfite()<<"$"<<leon.getNumOfMonths()<<"$"
			<<leon.getInstallmentValue()<<"$"
			<<leon.getInstallmentDate().getDay()<<"$"
			<<leon.getInstallmentDate().getMonth()<<"\n";
			file.close();
		}
		void save(Employee e){
			fstream file;
			file.open("employees.txt",ios::app);
			file<<e.getNationalId()<<"$"<<e.getId()<<"$"<<
			e.getFullName()<<"$"<<e.getPhone()<<"$"<<e.getSalary()<<"$"
			<<e.isAdmin()<<"$"<<e.getPassword()<<"\n";
		}
		Account getAccount(vector< pair<string,Account> >accounts,
		string nationalId){
			for(int i=0;i<accounts.size();i++){
					if(accounts[i].first ==nationalId){
						return accounts[i].second;
					}
				}
				Account account;
			return account;
		}
		Card getCard(vector<pair<string,Card> > cards,string nationalId){

				for(int i=0;i<cards.size();i++){
					if(cards[i].first ==nationalId){
						return cards[i].second;
					}
				}
				Card c;
				return c;
		}
		vector<Employee> getAllEmployees(){
			fstream file;
			file.open("employees.txt",ios::in);
			vector<Employee>employees;
			Parser p;
			while(!file.eof()){
				string s;
				getline(file,s);
				Employee e = p.parseEmployee(s);

				employees.push_back(e);
			}
			file.close();
			return employees;

		}
		vector<Client> getAllClients(){
			fstream file;
			Parser p;
			file.open("clients.txt",ios::in);
			string s;
			vector< pair<string,Account> >accounts=readAllAccounts();
			vector< pair<string,Card> > cards= readAllCards();
			vector< pair<string,Leon> > leons= readAllLeons();
			vector<Client>clients;
			while(file.eof()==false){
				getline(file,s);
				Client c = p.parseClient(s);
				c.setAccount(getAccount(accounts,c.getNationalId()));
				c.setCard(getCard(cards,c.getNationalId()));
				for(int i=0;i<leons.size();i++){
					if(leons[i].first ==c.getNationalId()){
						c.addLeon(leons[i].second);
					}
				}
				clients.push_back(c);
			}
			file.close();
			return clients;
		}

		vector< pair<string,Account> > readAllAccounts(){
			fstream file;
			Parser parser;
			file.open("accounts.txt",ios::in);
			string text;
			vector< pair<string,Account> > myVec;
			while(file.eof()==false){
				getline(file,text);
				pair<string,Account> p;
				p =parser.parseAccount(text);
				myVec.push_back(p);
			}
			file.close();
			return myVec;
		}
		vector< pair<string,Card> > readAllCards(){
			fstream file;
			Parser parser;
			file.open("cards.txt",ios::in);
			string text;
			vector< pair<string,Card> > myVec;
			while(file.eof()==false){
				getline(file,text);
				pair<string,Card> p;
				p =parser.parseCard(text);
				myVec.push_back(p);
			}
			file.close();
			return myVec;
		}
		vector< pair<string,Leon> > readAllLeons(){
			fstream file;
			Parser parser;
			file.open("leons.txt",ios::in);
			string text;
			vector< pair<string,Leon> > myVec;
			while(file.eof()==false){
				getline(file,text);
				pair<string,Leon> p;
				p =parser.parseLeon(text);
				myVec.push_back(p);
			}
			file.close();
			return myVec;
		}
		vector<int> getLastIds(){
			fstream file;
			Parser parser;
			file.open("ids.txt",ios::in);
			string text;
			vector<int>myVec;
			while(file.eof()==false){
				getline(file,text);
				myVec.push_back(parser.parseInt(text));
			}
			file.close();
			return myVec;
		}
		void saveIds(vector<int>ids){
			fstream file;
			file.open("ids.txt",ios::out);
			file<<ids[0]<<"\n"<<ids[1]<<"\n";
			file.close();
		}

	protected:
};

#endif
