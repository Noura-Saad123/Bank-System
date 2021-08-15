
#ifndef DATE_H
#define DATE_H

class Date
{
	public:
		void setMonth(int m){
			if(m>=1&&m<=12){
				month = m;
			}
		}
		void setYear(int y){
			if(y>=2021&&y<=9999){
				year = y;
			}
		}
		int getMonth(){
			return month;
		}
		int getYear(){
			return year;
		}
		void setDay(int day){
			if(day>=1&&day<=31){
				this->day = day;
			}
		}
		int getDay(){
			return day;
		}
	protected:
		int day;
		int month;
		int year;
};

#endif
