#pragma once
#include<iostream>
#include<exception>
#include<iomanip>	// для ф-ий setw и setfill
// подкласс Часы:
class Watch {
public:
	Watch() : m_hour(0), m_min(0), m_sec(0){}
	Watch(unsigned sec) {
		m_min = sec / 60;
		m_sec = sec % 60;
		m_hour = m_min / 60;
		m_min = m_min % 60;
	}	
	friend std::ostream& operator<<(std::ostream& out, const Watch& obj) {
		out << std::setw(2) << std::setfill('0') << obj.m_hour << ':' << std::setw(2) <<
			obj.m_min << ':' << std::setw(2) << obj.m_sec << std::endl;
		return out;
	}
private:
	unsigned m_hour;
	unsigned m_min;
	unsigned m_sec;
};
// основной класс:
class Time {
private:
	unsigned my_sec;
	Watch m_time;
public:
	Time() : my_sec(0){
		m_time = Watch();
	}
	Time(unsigned sec) : my_sec(sec){		
		m_time = Watch(my_sec);
	}
	Time(const unsigned hrs, const unsigned min, const unsigned sec){
		// "броски" при неправильном вводе значений:
		if (hrs > 24)
			throw std::invalid_argument("The value \'hours\' is entered incorrectly.");
		if(min > 60)
			throw std::invalid_argument("The value \'minutes\' is entered incorrectly.");
		if(sec > 60)
			throw std::invalid_argument("The value \'seconds\' is entered incorrectly.");
		my_sec = hrs * 3600 + min * 60 + sec;
		m_time = Watch(my_sec);
	}
	void calculateTime(unsigned hrs, unsigned min, unsigned sec) {
		my_sec = hrs * 3600 + min * 60 + sec;
		m_time = Watch(my_sec);
	}
	friend std::ostream& operator<<(std::ostream& out, const Time& obj) {
		out << obj.m_time;
		return out;
	}
};
