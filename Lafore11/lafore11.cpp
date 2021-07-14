#include<iostream>
#include<string>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int RATION = 70;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class WorldCurrency
{
protected:
	int basicMoney;
	int supportMoney;
public:
	WorldCurrency() :basicMoney(0), supportMoney(0) {}
	WorldCurrency(int tempBasic, int tempSupp) :basicMoney(tempBasic), supportMoney(tempSupp) {}
	WorldCurrency(float tempMoney)
	{
		int tempVar = static_cast<int>(tempMoney);
		basicMoney = tempVar;
		supportMoney = static_cast<int>((tempMoney - tempVar) * 100);
	}
	virtual void outScreen()  =0
	{
		std::cout << basicMoney << " and " << supportMoney;
	}
	virtual void getMoney() =0
	{
		std::cin >> basicMoney;
		std::cin >> supportMoney;
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Rubles : private WorldCurrency
{
public:
	Rubles() :WorldCurrency() {}
	Rubles(int tempBasic, int tempSupp) :WorldCurrency(tempBasic, tempSupp) {}
	Rubles(float tempMoney) :WorldCurrency(tempMoney) {}
	void outScreen()
	{
		std::cout << "Rubles ";
		WorldCurrency::outScreen();
		std::cout << " copeick" << std::endl;
	}
	void getMoney()
	{
		std::cout << "Enter rubles then copeick\n";
		WorldCurrency::getMoney();
	}
	int getRub() const
	{
		return basicMoney;
	}
	int getCop() const
	{
		return supportMoney;
	}
	friend Rubles operator+(Rubles, Rubles);
	friend Rubles operator-(Rubles, Rubles);
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Dollars : private WorldCurrency
{
public:
	Dollars() :WorldCurrency() {}
	Dollars(int tempBasic, int tempSupp) :WorldCurrency(tempBasic, tempSupp) {}
	Dollars(float tempMoney) :WorldCurrency(tempMoney) {}
	Dollars(const Rubles& tempRub) 
	{
		float tempMoney = (static_cast<float>(tempRub.getRub()) + (static_cast<float>(tempRub.getCop()) / 100)) / 70;
		std::cout << tempMoney << std::endl;
		int tempVar = static_cast<int>(tempMoney);
		basicMoney = tempVar;
		supportMoney = static_cast<int>((tempMoney - tempVar) * 100);
	}
	void outScreen()
	{
		std::cout << "Dollars ";
		WorldCurrency::outScreen();
		std::cout << " cents" << std::endl;
	}
	void getMoney()
	{
		std::cout << "Enter dollars then cents\n";
		WorldCurrency::getMoney();
	}
	friend Dollars operator+(Dollars, Dollars);
	friend Dollars operator-(Dollars, Dollars);
	Dollars& operator=(Dollars tempDoll)
	{
		std::cout << "what is heppend?" << std::endl;
		basicMoney = tempDoll.basicMoney;
		supportMoney = tempDoll.supportMoney;
		return *this;
	}
	operator Rubles() const
	{
		int tempRubl = basicMoney * RATION;
		int tempCop = supportMoney * RATION;
		while (tempCop >= 100)
		{
			tempCop -= 100;
			tempRubl++;
		}
		return Rubles(tempRubl, tempCop);
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dollars operator+(Dollars temp1, Dollars temp2)
{
	int tempBasicMoney = temp1.basicMoney + temp2.basicMoney;
	int tempSupportMoney = temp1.supportMoney + temp2.supportMoney;
	if (tempSupportMoney >= 100)
	{
		tempBasicMoney++;
		tempSupportMoney -= 100;
	}
	return Dollars(tempBasicMoney, tempSupportMoney);
}
Rubles operator+(Rubles temp1, Rubles temp2)
{
	int tempBasicMoney = temp1.basicMoney + temp2.basicMoney;
	int tempSupportMoney = temp1.supportMoney + temp2.supportMoney;
	if (tempSupportMoney >= 100)
	{
		tempBasicMoney++;
		tempSupportMoney -= 100;
	}
	return Rubles(tempBasicMoney, tempSupportMoney);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dollars operator-(Dollars temp1, Dollars temp2)
{
	int tempBasicMoney;
	int tempSupportMoney;
	if (temp1.basicMoney - temp2.basicMoney < 0)
	{
		tempBasicMoney = -1 * temp1.basicMoney - temp2.basicMoney;
	}
	else
	{
		tempBasicMoney = temp1.basicMoney - temp2.basicMoney;
	}
	if (temp1.supportMoney - temp2.supportMoney < 0)
	{
		tempSupportMoney = 100 + temp1.supportMoney - temp2.supportMoney;
		tempBasicMoney--;
	}
	else
	{
		tempSupportMoney = temp1.supportMoney - temp2.supportMoney;
	}
	return Dollars(tempBasicMoney, tempSupportMoney);
}
Rubles operator-(Rubles temp1, Rubles temp2)
{
	int tempBasicMoney;
	int tempSupportMoney;
	if (temp1.basicMoney - temp2.basicMoney < 0)
	{
		tempBasicMoney = -1 * temp1.basicMoney - temp2.basicMoney;
	}
	else
	{
		tempBasicMoney = temp1.basicMoney - temp2.basicMoney;
	}
	if (temp1.supportMoney - temp2.supportMoney < 0)
	{
		tempSupportMoney = 100 + temp1.supportMoney - temp2.supportMoney;
		tempBasicMoney--;
	}
	else
	{
		tempSupportMoney = temp1.supportMoney - temp2.supportMoney;
	}
	return Rubles(tempBasicMoney, tempSupportMoney);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Rubles temp1(333, 70), temp2(555, 70);
	Dollars tempDol,tempDol2(temp2);
	tempDol = temp1 + temp2;
	tempDol.outScreen();
	tempDol = tempDol2;
	tempDol.outScreen();
	return 0;
}
