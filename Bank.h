
#ifndef BANK_H
#define BANK_H
#include <string>
#include <iostream>
#include "Employee.h"
#include "FileManager.h"
#include<vector>
using namespace std;
class Bank
{
	public:
		void start(){
			login();
			if(loginCount<=3){
				printMenu();
			}
		}
		void login(){
			loginCount++;
			if(loginCount>3){
				cout<<"login count 3"<<endl;
				return;
			}
			cout<<"enter your national id"<<endl;
			string nationalId;
			cin>>nationalId;
			cout<<"enter your password"<<endl;
			string password;
			cin>>password;
			FileManager file;
			vector<Employee> employees = file.getAllEmployees();
			for(int i =0;i<employees.size();i++){
				if(employees[i].getNationalId()==nationalId&&
				employees[i].getPassword()==password){
					employee = employees[i];
					return;
				}
			}
			cout<<"invalid data"<<endl;
			login();
		}
		void printMenu(){
			cout<<"1- Create Client"<<endl;
			cout<<"2- Create Leon"<<endl;
			cout<<"3- Create Card"<<endl;
			cout<<"4- transfare Money"<<endl;
			cout<<"5- delete Client"<<endl;
			cout<<"6- list All Clients"<<endl;
			cout<<"7- change password"<<endl;
			cout<<"8- show info"<<endl;
			cout<<"9- logout"<<endl;
			int x;
			cin>>x;
			switch(x){
				case 1:
					createClient();
					break;
				case 2:
					createLeon();
					break;
				case 3:
					createCard();
					break;
				case 4:
					transMoney();
					break;
				case 6:
					listAllClients();
					break;
				default:

					break;
			}
		}
		void listAllClients(){
			FileManager file;
			vector<Client> clients = file.getAllClients();
			for(int i=0;i<clients.size();i++){
				cout<<"CLient "<<i+1<<endl;
				cout<<"Name: "<<clients[i].getFullName()<<endl;
				cout<<"NationalId: "<<clients[i].getNationalId()<<endl;
				cout<<"phone Number: "<<clients[i].getPhone()<<endl;
			}
		}
		void transMoney(){
			Client client1 = getClient();
			Client client2 = getClient();
			while(true){
				cout<<"enter your amount"<<endl;
				double amount;
				cin>>amount;
				Account account1 = client1.getAccount();
				Account account2 = client2.getAccount();
			double res = account1.getBalance()-amount;
			if(res>=1000){
				account1.setBalance(res);
				account2.setBalance(account2.getBalance()+amount);
				client1.setAccount(account1);
				client2.setAccount(account2);
				FileManager manager;
				vector<Client>clients = manager.getAllClients();
				manager.clear();
				for(int i=0;i<clients.size();i++){
					if(clients[i].getNationalId()==client1.getNationalId()){
						clients[i] = client1;
					}
					if(clients[i].getNationalId()==client2.getNationalId()){
						clients[i] = client2;
					}
					manager.save(clients[i]);
				}

				cout<<"done successfully"<<endl;
				cout<<"do you want play again?y/n";
				char c;
				cin>>c;
				if(c=='y'||c=='Y'){
					printMenu();
				}
				return;
			}else{
				cout<<"min balance 1000"<<endl;
				printMenu();
			}
			}
		}
		void createCard(){
			//like createLeon
			//01234567891234$12345678912345$Mark Essam$123$1234$4$2025
			Client client =getClient();
			string number = getCardNumber();
			string cvv = getCVV();
			string pinCode = getPinCode();
			Date date = readCreationDate();
			Card card;
			card.setCVV(cvv);
			card.setExpireDate(date);
			card.setName(client.getFullName());
			card.setNumber(number);
			card.setPinCode(pinCode);
			FileManager manager;
			manager.save(card,client.getNationalId());
			cout<<"done successfully"<<endl;
			cout<<"do you want play again?y/n";
			char c;
			cin>>c;
			if(c=='y'||c=='Y'){
				printMenu();
			}

		}

		string getPinCode(){
			cout<<"enter your card PinCode"<<endl;
			string number;
			cin>>number;
			ValidationManager manager;
			if(manager.isValidNumber(number,4)){
				return number;
			}
			return getPinCode();
		}
		string getCVV(){
			cout<<"enter your card CVV"<<endl;
			string number;
			cin>>number;
			ValidationManager manager;
			if(manager.isValidNumber(number,3)){
				return number;
			}
			return getCVV();
		}
		string getCardNumber(){
			cout<<"enter your card number"<<endl;
			string number;
			cin>>number;
			ValidationManager manager;
			if(manager.isValidNumber(number,14)){
				return number;
			}
			return getCardNumber();
		}
		void createLeon(){
			Client client =getClient();
			int months = readNumOfMonths();
			double profite = readProfite();
			double amount = readAmount();
			Date date = readCreationDate();
			Leon leon;
			leon.setAmount(amount);
			leon.setProfite(profite);
			leon.setNumOfMonths(months);
			leon.setInstallmentDate(date);
			FileManager file;
			file.save(leon,client.getNationalId());
			cout<<"done successfully"<<endl;
			cout<<"do you want play again?y/n";
			char c;
			cin>>c;
			if(c=='y'||c=='Y'){
				printMenu();
			}

		}
		Client getClient(){
			string id;
			ValidationManager manager;
			FileManager fileManager;
			Client client;
			while(true){
				cout<<"enter National id"<<endl;
				cin>>id;
				if(manager.isValidNumber(id,14)){
					vector<Client> clients = fileManager.getAllClients();
					for(int i=0;i<clients.size();i++){
						if(id==clients[i].getNationalId()){
							return clients[i];
						}
					}
				}
			}
		}
		int readNumOfMonths(){
			cout<<"enter NumOfMonths"<<endl;
			int n;
			cin>>n;
			if(n>=6&&n<=84){
				return n;
			}
			return readNumOfMonths();
		}
		double readProfite(){
			cout<<"enter leon profite"<<endl;
			double profite;
			cin>>profite;
			if(profite>=0.06&&profite<=0.17){
				return profite;
			}
			return readProfite();
		}
		double readAmount(){
			cout<<"enter leon amount"<<endl;
			double amount;
			cin>>amount;
			if(amount>=20000){
				return amount;
			}
			return readAmount();
		}
		void createClient(){
			// name,phone,nationalId,Account;
			string name = readName();
			string nationalId = readNationalId();
			string phone = readPhoneNumber();
			Account account = readAccount();
			Client client ;
			client.setAccount(account);
			client.setNationId(nationalId);
			client.setFullName(name);
			client.setPhone(phone);
			FileManager file;
			file.save(client);
			cout<<"done successfully"<<endl;
			cout<<"do you want play again?y/n";
			char c;
			cin>>c;
			if(c=='y'||c=='Y'){
				printMenu();
			}

		}
		string readName(){
			cout<<"enter your name"<<endl;
			string name;
			getline(cin,name);
			ValidationManager manager;

			if(manager.isName(name)){
				return name;
			}
			return readName();
		}
		string readNationalId(){
			cout<<"enter National ID"<<endl;
			string id;
			getline(cin,id);

			ValidationManager manager;
			if(manager.isValidNumber(id,14)){
				return id;
			}
			return readNationalId();
		}
		string readPhoneNumber(){
			cout<<"enter Phone Number"<<endl;
			string phone;
			getline(cin,phone);
			ValidationManager manager;
			if(manager.isPhone(phone)){
				return phone;
			}
			return readPhoneNumber();
		}
		Account readAccount(){
			Account account;
			//id,balance,creation date
			//123->124
			double balance = readBalance();
			Date date = readCreationDate();
			FileManager file;
			vector<int>ids = file.getLastIds();
			ids[0] = ids[0]+1;
			account.setBalance(balance);
			account.setCreationDate(date);
			account.setID(ids[0]);
			file.saveIds(ids);
			return account;

		}
		double readBalance(){
			cout<<"enter Account Balance"<<endl;
			double balance;
			cin>>balance;
			if(balance>=1000){
				return balance;
			}
			return readBalance();
		}
		Date readCreationDate(){

			cout<<"enter Creation Date"<<endl;
			int day,month,year;
			cin>>day>>month>>year;
			if(day>=1&&day<=31&&month>=1&&month<=12&&year>=2021&&year<=9999){
				Date date;
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				return date;
			}
			return readCreationDate();

		}
	private:
		Employee employee;
		int loginCount = 0;
};

#endif
