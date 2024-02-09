#include<bits/stdc++.h>

using namespace std;

class mint{
	public:
	int value;
	const int mod = 1000000009;
	
	mint(int _value):value(_value) {};
	~mint(){};
	
	int operator + (mint obj){
		 return (this.value+ obj.value) % mod;
	}
	int operator - (mint obj){
		return (mod + this.value - obj.value) % mod;
	}
	int operator * (mint obj){
		return (this.value * obj.value) % mod;
	}
	int operator / (mint obj){
		return 10;
	}
	int operator = (mint obj){
		this -> value = obj.value;
		return this -> value;
	}
}

int main(){
	
}
