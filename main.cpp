#include <iostream>
#include "Card.h"
#include "Client.h"
#include "Date.h"
#include <vector>
#include "FileManager.h"
#include "Parser.h"
#include "ATM.h"
#include "Bank.h"
#include "Parser.h"
#include "Employee.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Bank obj;
	obj.start();
	/*
	FileManager file;
	vector<int>ids = file.getLastIds();
	ids[0]++;
	ids[1]++;
	file.saveIds(ids);
	cout<<ids[0]<<" "<<ids[1]<<endl;
	*/
	/*int x;
	string s = "123";
	istringstream iss(s);
	iss>>x;
	cin>>x;
	cout<<x<<endl;*/
	/*Parser p;
	p.splitString();*/
	/*Employee e = p.parseEmployee("12345678912345$123$ibrahim ali$01210982507$4000$1$1234");
	cout<<e.getFullName()<<" "<<e.getNationalId()<<" "<<e.getId()<<" ";
	cout<<e.getPassword()<<" "<<e.getPhone()<<" "<<e.getSalary()<<" ";
	cout<<e.isAdmin()<<endl;
	FileManager fileManager;
	vector<Employee>employees = fileManager.getAllEmployees();
	cout<<employees.size()<<endl;
	cout<<employees[0].getNationalId()<<" "<<employees[0].getPassword()<<endl;
	*/
	/*Bank bank;
	bank.login();*/
	/*ATM atm;
	atm.start();
	Employee e;
	e.setFullName("ibrahim ali");
	e.setID(123);
	e.setISAdmin(true);
	e.setPhone("01210982507");
	e.setNationId("12345678912345");
	e.setSalary(4000);
	e.setPassword("1234");
	FileManager fileManager;
	fileManager.save(e);*/
	/*FileManager fileManager;
	vector<Client>clients = fileManager.getAllClients();
	cout<<clients[0].getFullName()<<endl;
	cout<<clients[0].getMyCard().getNumber()<<endl;
	cout<<clients[0].getAccount().getBalance()<<endl;
	cout<<clients[0].getLeons()[0].getAmount()<<endl;*/
	//Parser p;
	//p.parseClient("01234567891234$Mark Essam$01210982507");
	//string s = "123.52";
	//double balance = atof(s.c_str());
	/*istringstream iss(s);
	int balance;
	iss >> balance;
	cout<<balance<<endl;*/
	//FileManager fileManager;
	//fileManager.displayClients();
	/*Client client;
	Account account;
	account.setBalance(100000);
	account.setID(12);
	Date date1;
	date1.setDay(1);
	date1.setMonth(4);
	date1.setYear(2021);
	account.setCreationDate(date1);

	Card card;
	card.setName("Mark Essam");
	card.setCVV("123");
	card.setNumber("12345678912345");
	card.setPinCode("1234");
	Date date;
	date.setMonth(4);
	date.setYear(2026);
	card.setExpireDate(date);


	Leon leon;
	leon.setAmount(100000);
	leon.setNumOfMonths(24);
	leon.setProfite(0.075);
	Date installmentDate;
	installmentDate.setDay(1);
	installmentDate.setMonth(4);
	leon.setInstallmentDate(installmentDate);

	vector<Leon>leons;
	leons.push_back(leon);

	client.setFullName("Mark Essam");
	client.setNationId("01234567891234");
	client.setPhone("01210982507");
	client.setCard(card);
	client.setAccount(account);
	client.setLeons(leons);
	FileManager fileManager;
	fileManager.save(client);*/
	//client info
	/*client.setFullName("Mark Essam");
	client.setNationId("01234567891234");
	client.setPhone("01210982507");
	//card info
	Card card;
	card.setName("Mark Essam");
	card.setCVV("123");
	card.setNumber("12345678912345");
	card.setPinCode("1234");
	Date date;
	date.setMonth(4);
	date.setYear(2026);
	card.setExpireDate(date);*/
	//Account info
	/*Account account;
	account.setBalance(100000);
	account.setID(12);
	Date date1;
	date1.setDay(1);
	date1.setMonth(4);
	date1.setYear(2021);
	account.setCreationDate(date1);
	//Leons info
	Leon leon;
	leon.setAmount(100000);
	leon.setNumOfMonths(24);
	leon.setProfite(0.075);
	Date installmentDate;
	installmentDate.setDay(1);
	installmentDate.setMonth(4);
	leon.setInstallmentDate(installmentDate);

	vector<Leon>leons;
	leons.push_back(leon);

	client.setCard(card);
	client.setAccount(account);
	client.setLeons(leons);

	FileManager file;
	file.save(client);
	// nationalId   account
	//map -> Bineary search tree
	map["13456987"] = account;
	//key,value
	*/
	/*FileManager fileManager;
	vector<Client>clients = fileManager.readAllClients();
	cout<<"Size "<<clients.size()<<endl;
	for(int i=0;i<clients.size();i++){
		cout<<"Client"<<endl;
		cout<<clients[i].getNationalId()<<" "<<clients[i].getFullName()<<endl;
		cout<<clients[i].getMyCard().getNumber()<<endl;
	}*/
	//fileManager.readAllClients();
	//fileManager.parseAccount("01234567891234$100000$12$1$4$2021");
	return 0;
}
