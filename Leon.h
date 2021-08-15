
#ifndef LEON_H
#define LEON_H
//
class Leon
{
	public:
		void setProfite(double val){
			if(val>=0.06&&val<=0.17){
				profite = val;
			}
		}
		double getProfite(){
			return profite;
		}
		void setAmount(double amount){
			if(amount>=20000&&amount<=1000000){
				this->amount = amount;
			}
		}
		double getAmount(){
			return amount;
		}
		void setNumOfMonths(int val){
			if(val>=6&&val<=84){
				numOfMonths = val;
			}
		}
		int getNumOfMonths(){
			return numOfMonths;
		}
		double getInstallmentValue(){
			float numOfYears = numOfMonths/12.0;
			float totalProfite = numOfYears*amount*profite;
			installment_value = (totalProfite+amount)/numOfMonths;
			return installment_value;
		}
		void setInstallMent(double val){
			installment_value = val;
		}
		void setInstallmentDate(Date date){
			installment_date = date;
		}
		Date getInstallmentDate(){
			return installment_date;
		}
	private:
		double profite;// min = 6.0,max = 17.0%
		double amount; //min = 20000,max =1M
		int numOfMonths;//min = 6 months,max = 84 months
		double installment_value ; //((amount*profite/12)+amount)
		Date installment_date;//dd/mm

};

#endif
