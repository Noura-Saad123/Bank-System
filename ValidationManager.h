
#ifndef VALIDATIONMANAGER_H
#define VALIDATIONMANAGER_H
#include <string>
using namespace std;
class ValidationManager
{
	public:

		bool isValidNumber(string s,int size){
			//pattern = "0123456789
			//s ="12354a"
			if(s.size() != size)return false;
			for(int i =0;i<s.size();i++){
				if(isDigit(s[i])==false){
					return false;
				}
			}
			return true;
		}
		bool isPhone(string phone){
			if(isValidNumber(phone,11)&&(phone.substr(0,3)=="011"||phone.substr(0,3)=="010"||phone.substr(0,3)=="012"||phone.substr(0,3)=="015")){
				return true;
			}
			return false;
		}
		bool isName(string s){

			if(s.size() < 10||s.size()>20)return false;
			for(int i =0;i<s.size();i++){
				if(!isCapital(s[i])&&!isSmall(s[i])&&s[i]!=' '){
					return false;
				}
			}
			return true;
		}
		bool isDigit(char c){
			if(c>='0'&&c<='9'){
				return true;
			}
			return false;
		}

		bool isCapital(char c){
			if(c>='A'&&c<='Z'){
				return true;
			}
			return false;
		}

		bool isSmall(char c){
			if(c>='a'&&c<='z'){
				return true;
			}
			return false;
		}
		int getCVV_SIZE(){
			return 3;
		}
		double getMinBalance(){
			return 1000;
		}
	private:
};

#endif
