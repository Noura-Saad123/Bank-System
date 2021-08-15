
#ifndef ATM_H
#define ATM_H
#include "FileManager.h"
#include "Client.h"
#include "Card.h"
#include "Account.h"
#include <string>
#include <vector>
#include "ValidationManager.h"
using namespace std;
class ATM
{
	//login ->cardNumber pincode
	//1- withdraw ->amount
	//2- deposite ->amount
	//3- check balance
	//4- change pinCode -> newpassword confirm
	//5- logout

	public:
		void start(){
			client = login();
			printMenu();
			FileManager fileManager;
			vector<Client> clients = fileManager.getAllClients();
			for(int i=0;i<clients.size();i++){
				if(client.getNationalId()==clients[i].getNationalId()){
					clients[i] = client;
				}
			}

			fileManager.clear();
			cout<<"Clients size: "<<clients.size()<<endl;
			for(int i=0;i<clients.size();i++){

				fileManager.save(clients[i]);
			}
		}
		void withdraw(){
			cout<<"enter your amount"<<endl;
			double amount;
			cin>>amount;
			//2000-500
			double res = client.getAccount().getBalance()-amount;
			if(res>=1000){
				Account account = client.getAccount();
				account.setBalance(res);
				client.setAccount(account);
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
		void deposite(){
			cout<<"enter your amount"<<endl;
			double amount;
			cin>>amount;
			double res = client.getAccount().getBalance()+amount;
			if(amount>0){
				Account account = client.getAccount();
				account.setBalance(res);
				client.setAccount(account);
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
			}
		}
		void checkBalance(){
			cout<<"Yor Balance: "<<client.getAccount().getBalance()<<endl;
			cout<<"do you want play again?y/n";
			char c;
			cin>>c;
			if(c=='y'||c=='Y'){
				printMenu();
			}
		}
		void changePinCode(){
			ValidationManager manager;
			cout<<"enter new password"<<endl;
			string password;
			cin>>password;
			cout<<"enter confirm password"<<endl;
			string confirmPassword;
			cin>>confirmPassword;
			if(manager.isValidNumber(password,4)&&password==confirmPassword){
				Card card = client.getMyCard();
				card.setPinCode(password);
				client.setCard(card);
			}else{
				cout<<"invalid password";
				printMenu();
			}
			cout<<"do you want play again?y/n";
			char c;
			cin>>c;
			if(c=='y'||c=='Y'){
				printMenu();
			}
		}
		void printMenu(){
			cout<<"1- withdraw"<<endl;
			cout<<"2- deposite"<<endl;
			cout<<"3- checkBalance"<<endl;
			cout<<"4- change PinCode"<<endl;
			cout<<"5- logout"<<endl;
			int x;
			cin>>x;
			switch(x){
				case 1:
					withdraw();
					break;
				case 2:
					deposite();
					break;
				case 3:
					checkBalance();
					break;
				case 4:
					changePinCode();
					break;
				default:
					return;
			}

		}
		Client login(){
			FileManager fileManager;
			vector<Client> clients = fileManager.getAllClients();
			while(true){
				cout<<"please enter your Card Number"<<endl;
				string cardNumber;
				cin>>cardNumber;
				cout<<"please enter your pinCode"<<endl;
				string pinCode;
				cin>>pinCode;
				for(int i=0;i<clients.size();i++){
					if(cardNumber==clients[i].getMyCard().getNumber()
					&&pinCode==clients[i].getMyCard().getPinCode()){
						return clients[i];
					}
				}
				cout<<"invalid data"<<endl;
			}
		}
	private:
		Client client;
};

#endif
