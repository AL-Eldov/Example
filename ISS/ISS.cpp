#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<list>
#include<stdio.h>
using namespace std;
class listOfInvestments;
class listOfDepositInvestments;
/////////////////////////////////////////////
struct quoteDate//����������� ������ ��� �������� ������� ��������� ������ �����
{
	double quotation;
	string date;
	quoteDate(double t1, string t2) :quotation(t1), date(t2) {}
};
enum tupeOfSecurity//���������� ��� ������ ������
{
	bond,
	bill_of_exchange,
	stock,
	mortgage,
	unknownS
};
class security//����� ����������� ������ ������
{
private:
	string security_code;
	double minimum_transaction_amount;
	int rating;
	double  income_last_year;
	tupeOfSecurity tupe;
	vector<quoteDate> quoteDateHistory;//������� ���������
public:
	security() :security_code("0"), minimum_transaction_amount(0), rating(0), income_last_year(0), tupe(unknownS) {}
	security(string t1, double t2, int t3, double t4, tupeOfSecurity t5) :security_code(t1), minimum_transaction_amount(t2), rating(t3), income_last_year(t4), tupe(t5) {}
	string getAllData()const//����� ������������ ��� ���������� � ������ ������
	{
		string s = security_code + "   " + to_string(minimum_transaction_amount) + "   " + to_string(rating) + "   " + to_string(income_last_year) + "   ";
		switch (tupe)
		{
		case bond: s += "bond"; break;
		case bill_of_exchange: s += "bill of exchange"; break;
		case stock: s += "stock"; break;
		case mortgage: s += "mortgage"; break;
		default: s += "unknown"; break;
		}
		s += "\n" + getHistory();
		return s;
	}
	void setAllData(string t1, double t2, int t3, double t4, tupeOfSecurity t5)// ���� ������� set-����
	{
		security_code = t1;
		minimum_transaction_amount = t2;
		rating = t3;
		income_last_year = t4;
		tupe = t5;
	}
	void setSecurityCode(string t1)
	{
		security_code = t1;
	}
	void setMinimumTransactionAmount(double t2)
	{
		minimum_transaction_amount = t2;
	}
	void setRating(int t3)
	{
		rating = t3;
	}
	void setIncomeLastYear(double t4)
	{
		income_last_year = t4;
	}
	void setTupe(tupeOfSecurity t5)
	{
		tupe = t5;
	}
	string getSecurityCode()const// ���� ������� get-����
	{
		return security_code;
	}
	double getMinimumTransactionAmount()const
	{
		return minimum_transaction_amount;
	}
	int getRating()const
	{
		return rating;
	}
	double getIncomeLastYear()const
	{
		return income_last_year;
	}
	tupeOfSecurity getTupe()const
	{
		return tupe;
	}
	vector<quoteDate>& getVector()//������ ��� ������ � �������� ���������
	{
		return quoteDateHistory;
	}
	string getHistory()const
	{
		string strTemp;
		for (int i = 0; i < quoteDateHistory.size(); i++)
		{
			strTemp += "\t" + quoteDateHistory.at(i).date + "   " + to_string(quoteDateHistory.at(i).quotation) + "\n";
		}
		return strTemp;
	}
	void addToHistory(quoteDate tempVar)
	{
		quoteDateHistory.push_back(tempVar);
	}
};
/////////////////////////////////////////////
enum typeOfProperty//���������� ��� �������
{
	privat,
	municipal,
	state,
	unknownP
};
class client//����� ����������� �������
{
private:
	string name;
	string adress;
	string phone;
	typeOfProperty tupe;
public:
	client() :name("0"), adress("0"), phone("0"), tupe(unknownP) {}
	client(string t1, string t2, string t3, typeOfProperty t4) :name(t1), adress(t2), phone(t3), tupe(t4) {}
	string getAllData()const//����� ������������ ��� ���������� � �������
	{
		string s = name + "   " + adress + "   " + phone + "   ";
		switch (tupe)
		{
		case privat: s += "privat"; break;
		case municipal:s += "municipal"; break;
		case state: s += "state"; break;
		default: s += "unknown"; break;
		}
		return s;
	}
	void setAllData(string t1, string t2, string t3, typeOfProperty t4)// ���� ������� set-����
	{
		name = t1;
		adress = t2;
		phone = t3;
		tupe = t4;
	}
	void setName(string t1)
	{
		name = t1;
	}
	void setAdress(string t2)
	{
		adress = t2;
	}
	void setPhone(string t3)
	{
		phone = t3;
	}
	void setTupe(typeOfProperty t4)
	{
		tupe = t4;
	}
	string getName()const// ���� ������� get-����
	{
		return name;
	}
	string getAdress()const
	{
		return adress;
	}
	string getPhone()const
	{
		return phone;
	}
	typeOfProperty getTupe()const
	{
		return tupe;
	}
};
/////////////////////////////////////////////
class investment//����� ����������� ���������� � �������� ������� � ������ ������
{
private:
	security* paper;
	client* men;
	double purchase_quotation;
	double quotation_on_sale;
	string purchase_date;
	string date_of_sale;
public:
	investment() : paper(NULL), men(NULL), purchase_quotation(0), quotation_on_sale(0), purchase_date("0"), date_of_sale("0") {}
	investment(double t1, double t2, string t3, string t4, security* t5, client* t6) :purchase_quotation(t1), quotation_on_sale(t2), purchase_date(t3), date_of_sale(t4), paper(t5), men(t6) {}
	void createInvestment(security* temp1S, client* temp2C, double t1, double t2, string t3, string t4)//����� ����������� ���� ������
	{
		men = temp2C;
		paper = temp1S;
		purchase_quotation = t1;
		quotation_on_sale = t2;
		purchase_date = t3;
		date_of_sale = t4;
		temp1S->getVector().push_back(quoteDate(t1, t3));
		temp1S->getVector().push_back(quoteDate(t2, t4));
	}
	string getAllData()const//����� ������������ ��� ���������� � ����������
	{
		if (paper == NULL || men == NULL)
		{
			return "---ERROR---";
		}
		return purchase_date + "   " + to_string(purchase_quotation) + "   " + date_of_sale + "   " + to_string(quotation_on_sale) + "\n" + men->getAllData() + "\n" + paper->getAllData();
	}
	void setPurchaseQuotation(double t1)// ���� ������� set-����
	{
		purchase_quotation = t1;
	}
	void setQuotationOnSale(double t2)
	{
		quotation_on_sale = t2;
	}
	void setPurchaseDate(string t3)
	{
		purchase_date = t3;
	}
	void setDateOfSale(string t4)
	{
		date_of_sale = t4;
	}
	void setPaper(security* paperT)
	{
		paper = paperT;
	}
	void setMen(client* menT)
	{
		men = menT;
	}
	client* getMen()const// ���� ������� get-����
	{
		return men;
	}
	security* getPaper()const
	{
		return paper;
	}
	double getPurchaseQuotation()const
	{
		return purchase_quotation;
	}
	double getQuotationOnSale()const
	{
		return quotation_on_sale;
	}
	string getPurchaseDate()const
	{
		return purchase_date;
	}
	string getDateOfSale()const
	{
		return date_of_sale;
	}
	string getHistory()const
	{
		string strTemp;
		for (int i = 0; i < paper->getVector().size(); i++)
		{
			strTemp += "\t" + paper->getVector().at(i).date + "   " + to_string(paper->getVector().at(i).quotation) + "\n";
		}
		return strTemp;
	}
};
///////////////////////////////////////////////////////////////////////
class depositInvestment//����� ����������� ����� � ���� � �������� �������
{
private:
	client* men;
	double investmentSumm;
	double profitForYear;
	string depositAccount;
	string openDate;
public:
	depositInvestment() :men(NULL), investmentSumm(0), profitForYear(0), depositAccount("0"), openDate("0") {}
	depositInvestment(double t2, double t3, string t4, string t5, client* t1) :men(t1), investmentSumm(t2), profitForYear(t3), depositAccount(t4), openDate(t5) {}
	void createDepositInvestment(client* t1, double t2, double t3, string t4, string t5)//����� ����������� ���� ������
	{
		men = t1;
		investmentSumm = t2;
		profitForYear = t3;
		depositAccount = t4;
		openDate = t5;
	}
	string getAllData()const//����� ������������ ��� ���������� � ����������
	{
		if (men == NULL)
		{
			return "---ERROR---";
		}
		return depositAccount + "   " + openDate + "   " + to_string(investmentSumm) + "   " + to_string(profitForYear) + "\n" + men->getAllData();
	}
	void setMen(client* temp)// ���� ������� set-����
	{
		men = temp;
	}
	void setInvestmentSumm(double temp)
	{
		investmentSumm = temp;
	}
	void setProfitForYear(double temp)
	{
		profitForYear = temp;
	}
	void setDepositAccount(string temp)
	{
		depositAccount = temp;
	}
	void setOpenDate(string temp)
	{
		openDate = temp;
	}
	client* getMen()const// ���� ������� get-����
	{
		return men;
	}
	double getInvestmentSumm()const
	{
		return investmentSumm;
	}
	double getProfitForYear()const
	{
		return profitForYear;
	}
	string getDepositAccount()const
	{
		return depositAccount;
	}
	string getOpenDate()const
	{
		return openDate;
	}
};
///////////////////////////////////////////////////////////////////////
class listOfClients//����� ����������� ������ ��������
{
private:
	list<client*> clientsList;
public:
	list<client*>& getClientsList()//����� ������������  ������ �� ��� ����
	{
		return clientsList;
	}
	string getALLClients()const//����� ������������ ��� ���������� � ��������
	{
		string strTemp = "";
		for (auto i = clientsList.begin(); i != clientsList.end(); i++)
		{
			strTemp += (*i)->getAllData() + "\n\n";
		}
		return strTemp;
	}
	void createNewObjectInList(string t1, string t2, string t3, typeOfProperty t4)//����� ����������� ������ ������� � ����� ������
	{
		client* cliTemp = new client(t1, t2, t3, t4);
		clientsList.push_back(cliTemp);
	}
	void addOjectInList(client* cliTemp, int N)//����� ����������� ������� � ������ ����� ������
	{
		int j = 1;
		auto iter = clientsList.begin();
		while (j != N)
		{
			j++;
			iter++;
		}
		clientsList.emplace(iter, cliTemp);
	}
	void deleteObject(int N)//����� ��������� ���������� �������
	{
		N--;
		auto iter = clientsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		delete* iter;
		clientsList.erase(iter);
	}
	client* getOrSetAttributeValuev(int N)//����� ������������ ��������� �� ����������� ������� 
	{                                     //��� ���� ����������� ������������ ������ ������ client
		N--;
		auto iter = clientsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		return (*iter);
	}
};
///////////////////////////////////////////////////////////////////////
class listOfSecurities//����� ����������� ������ ������ �����
{
private:
	list<security*> securitiesList;
public:
	list<security*>& getSecuritiesList()//����� ������������  ������ �� ��� ����
	{
		return securitiesList;
	}
	string getALLSecurities()const// ����� ������������ ��� ���������� � ������ �������
	{
		string strTemp = "";
		for (auto i = securitiesList.begin(); i != securitiesList.end(); i++)
		{
			strTemp += (*i)->getAllData() + "\n";
		}
		return strTemp;
	}
	void createNewObjectInList(string t1, double t2, int t3, double t4, tupeOfSecurity t5)//����� ����������� ����� ������ ������ � ����� ������
	{
		security* secTemp = new security(t1, t2, t3, t4, t5);
		securitiesList.push_back(secTemp);
	}
	void addOjectInList(security* secTemp, int N)//����� ����������� ������ ������ � ������ ����� ������
	{
		int j = 1;
		auto iter = securitiesList.begin();
		while (j != N)
		{
			j++;
			iter++;
		}
		securitiesList.emplace(iter, secTemp);
	}
	void deleteObject(int N)//����� ��������� ��������� ������ ������
	{
		N--;
		auto iter = securitiesList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		delete* iter;
		securitiesList.erase(iter);
	}
	security* getOrSetAttributeValuev(int N)//����� ������������ ��������� �� ���������� ������ ������ 
	{                                     //��� ���� ����������� ������������ ������ ������ securiti
		N--;
		auto iter = securitiesList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		return (*iter);
	}
};
///////////////////////////////////////////////////////////////////////
class listOfInvestments//����� ����������� ������ ����������
{
private:
	list<investment*> investmentsList;
public:
	list<investment*>& getInvestmentsList()//����� ������������  ������ �� ��� ����
	{
		return investmentsList;
	}
	string getALLInvestments()const// ����� ������������ ��� ���������� � �����������
	{
		try
		{
			if (investmentsList.empty())
			{
				throw "Investments list empty";
			}
			else
			{
				string strTemp = "";
				for (auto i = investmentsList.begin(); i != investmentsList.end(); i++)
				{
					strTemp += (*i)->getAllData() + "\n";
				}
				return strTemp;
			}
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << '\n';
		}
	}
	void createNewObjectInList(double t1, double t2, string t3, string t4, security* t5, client* t6)//����� ����������� ����� ���������� � ����� ������
	{
		investment* invTemp = new investment(t1, t2, t3, t4, t5, t6);
		investmentsList.push_back(invTemp);
	}
	void addOjectInList(investment* invTemp, int N)//����� ����������� ���������� � ������ ����� ������
	{
		int j = 1;
		auto iter = investmentsList.begin();
		while (j != N)
		{
			j++;
			iter++;
		}
		investmentsList.emplace(iter, invTemp);
	}
	void deleteObject(int N)//����� ��������� ��������� ������ ������
	{
		N--;
		auto iter = investmentsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		delete* iter;
		investmentsList.erase(iter);
	}
	investment* getOrSetAttributeValuev(int N)//����� ������������ ��������� �� ���������� ���������� 
	{                                     //��� ���� ����������� ������������ ������ ������ investment
		N--;
		auto iter = investmentsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		return (*iter);
	}
};
///////////////////////////////////////////////////////////////////////
class listOfDepositInvestments//����� ����������� ������ ������� � ����
{
private:
	list<depositInvestment*> depositInvestmentsList;
public:
	list<depositInvestment*>& getDepositInvestmentsList()//����� ������������  ������ �� ��� ����
	{
		return depositInvestmentsList;
	}
	string getALLDepositInvestments()const// ����� ������������ ��� ���������� � ������� � ����
	{
		try
		{
			if (depositInvestmentsList.empty())
			{
				throw "Deposit investments list empty";
			}
			else
			{
				string strTemp = "";
				for (auto i = depositInvestmentsList.begin(); i != depositInvestmentsList.end(); i++)
				{
					strTemp += (*i)->getAllData() + "\n";
				}
				return strTemp;
			}
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << '\n';
		}
	}
	void createNewObjectInList(double t2, double t3, string t4, string t5, client* t1)//����� ����������� ����� ����� � ����� ������
	{
		depositInvestment* invTemp = new depositInvestment(t2, t3, t4, t5, t1);
		depositInvestmentsList.push_back(invTemp);
	}
	void addOjectInList(depositInvestment* invTemp, int N)//����� ����������� ������ � ������ ����� ������
	{
		int j = 1;
		auto iter = depositInvestmentsList.begin();
		while (j != N)
		{
			j++;
			iter++;
		}
		depositInvestmentsList.emplace(iter, invTemp);
	}
	void deleteObject(int N)//����� ��������� ��������� �����
	{
		N--;
		auto iter = depositInvestmentsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		delete* iter;
		depositInvestmentsList.erase(iter);
	}
	depositInvestment* getOrSetAttributeValuev(int N)//����� ������������ ��������� �� ���������� �����
	{                                     //��� ���� ����������� ������������ ������ ������ investment
		N--;
		auto iter = depositInvestmentsList.begin();
		while (N != 0)
		{
			iter++;
			N--;
		}
		return (*iter);
	}
};
///////////////////////////////////////////////////////////////////////
class ISS
{
private:
	listOfClients* clientsListName;
	listOfSecurities* securitiesListName;
	listOfInvestments* investmentsListName;
	listOfDepositInvestments* depositInvestmentsListName;
public:
	ISS()
	{
		clientsListName = new listOfClients;
		securitiesListName = new listOfSecurities;
		investmentsListName = new listOfInvestments;
		depositInvestmentsListName = new listOfDepositInvestments;
	}
	void clearAllList()//����� ��� ������� ���� ������
	{
		while (!investmentsListName->getInvestmentsList().empty())
		{
			investmentsListName->deleteObject(1);
		}
		while (!depositInvestmentsListName->getDepositInvestmentsList().empty())
		{
			depositInvestmentsListName->deleteObject(1);
		}
		while (!clientsListName->getClientsList().empty())
		{
			clientsListName->deleteObject(1);
		}
		while (!securitiesListName->getSecuritiesList().empty())
		{
			securitiesListName->deleteObject(1);
		}
	}
	bool checkListEmpty()//����� ��� �������� ����������� ���� ������ �� ������� 
	{
		return investmentsListName->getInvestmentsList().empty() || depositInvestmentsListName->getDepositInvestmentsList().empty() || clientsListName->getClientsList().empty() || securitiesListName->getSecuritiesList().empty();
	}
	listOfClients* getClientsListPointer()//����� ���� ���� ������� ��� ��������� ���� ��������� �������� �� �������� 
	{                                     //� ���������� ��������� ���������� ��������
		return clientsListName;           //��������� ������ ���������� ������ ISS
	}
	listOfSecurities* getSecuritiesListPointer()
	{
		return securitiesListName;
	}
	listOfInvestments* getInvestmentsListPointer()
	{
		return investmentsListName;
	}
	listOfDepositInvestments* getDepositInvestmentsListPointer()
	{
		return depositInvestmentsListName;
	}
	list<client*>& getClientsList()
	{
		return clientsListName->getClientsList();
	}
	string getALLClients()const
	{
		return clientsListName->getALLClients();
	}
	void createNewObjectInClientList(string t1, string t2, string t3, typeOfProperty t4)
	{
		clientsListName->createNewObjectInList(t1, t2, t3, t4);
	}
	void addOjectInClientList(client* cliTemp, int N)
	{
		clientsListName->addOjectInList(cliTemp, N);
	}
	void deleteClientObject(int N)
	{
		bool truFal = false;
		client* cliTemp = clientsListName->getOrSetAttributeValuev(N);
		for (auto iterI = investmentsListName->getInvestmentsList().begin(); iterI != investmentsListName->getInvestmentsList().end(); iterI++)
		{
			if (cliTemp == (*iterI)->getMen())
			{
				truFal = true;
			}
		}
		for (auto iterDI = depositInvestmentsListName->getDepositInvestmentsList().begin(); iterDI != depositInvestmentsListName->getDepositInvestmentsList().end(); iterDI++)
		{
			if (cliTemp == (*iterDI)->getMen())
			{
				truFal = true;
			}
		}
		if (truFal)
		{
			cout << "--- client using in investment ---\n";
		}
		else
		{
			clientsListName->deleteObject(N);
		}
	}
	client* getClientPointer(int N)
	{
		return clientsListName->getOrSetAttributeValuev(N);
	}
	list<security*>& getSecuritiesList()
	{
		return securitiesListName->getSecuritiesList();
	}
	string getALLSecurities()const
	{
		return securitiesListName->getALLSecurities();
	}
	void createNewObjectInSecurityList(string t1, double t2, int t3, double t4, tupeOfSecurity t5)
	{
		securitiesListName->createNewObjectInList(t1, t2, t3, t4, t5);
	}
	void addOjectInSecurityList(security* secTemp, int N)
	{
		securitiesListName->addOjectInList(secTemp, N);
	}
	void deleteSecurityObject(int N)
	{
		bool truFal = false;
		security* secTemp = securitiesListName->getOrSetAttributeValuev(N);
		for (auto iterI = investmentsListName->getInvestmentsList().begin(); iterI != investmentsListName->getInvestmentsList().end(); iterI++)
		{
			if (secTemp == (*iterI)->getPaper())
			{
				truFal = true;
			}
		}
		if (truFal)
		{
			cout << "--- security using in investment ---\n";
		}
		else
		{
			securitiesListName->deleteObject(N);
		}
	}
	security* getSecurityPointer(int N)
	{
		return securitiesListName->getOrSetAttributeValuev(N);
	}
	list<investment*>& getInvestmentsList()
	{
		return investmentsListName->getInvestmentsList();
	}
	string getALLInvestments()const
	{
		return investmentsListName->getALLInvestments();
	}
	void createNewObjectInInvestmentList(double t1, double t2, string t3, string t4, security* t5, client* t6)
	{
		investmentsListName->createNewObjectInList(t1, t2, t3, t4, t5, t6);
	}
	void addOjectInInvestmentList(investment* invTemp, int N)
	{
		investmentsListName->addOjectInList(invTemp, N);
	}
	void deleteInvestmentObject(int N)
	{
		investmentsListName->deleteObject(N);
	}
	investment* getInvestmentPointer(int N)
	{
		return investmentsListName->getOrSetAttributeValuev(N);
	}
	list<depositInvestment*>& getDepositInvestmentsList()
	{
		return depositInvestmentsListName->getDepositInvestmentsList();
	}
	string getALLDepositInvestments()const
	{
		return depositInvestmentsListName->getALLDepositInvestments();
	}
	void createNewObjectInDepositInvestmentsList(double t2, double t3, string t4, string t5, client* t1)
	{
		depositInvestmentsListName->createNewObjectInList(t2, t3, t4, t5, t1);
	}
	void addOjectInDepositInvestmentsList(depositInvestment* invTemp, int N)
	{
		depositInvestmentsListName->addOjectInList(invTemp, N);
	}
	void deleteDepositInvestmentsObject(int N)
	{
		depositInvestmentsListName->deleteObject(N);
	}
	depositInvestment* getDepositInvestmentsPointer(int N)
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N);
	}
	string getAllDataAboutClient(int N)const
	{
		return clientsListName->getOrSetAttributeValuev(N)->getAllData();
	}
	void setAllDataAboutClient(int N, string t1, string t2, string t3, typeOfProperty t4)
	{
		clientsListName->getOrSetAttributeValuev(N)->setAllData(t1, t2, t3, t4);
	}
	void setClientName(int N, string t1)
	{
		clientsListName->getOrSetAttributeValuev(N)->setName(t1);
	}
	void setClientAdress(int N, string t2)
	{
		clientsListName->getOrSetAttributeValuev(N)->setAdress(t2);
	}
	void setClientPhone(int N, string t3)
	{
		clientsListName->getOrSetAttributeValuev(N)->setPhone(t3);
	}
	void setClientTupe(int N, typeOfProperty t4)
	{
		clientsListName->getOrSetAttributeValuev(N)->setTupe(t4);
	}
	string getClientName(int N)const
	{
		return clientsListName->getOrSetAttributeValuev(N)->getName();
	}
	string getClientAdress(int N)const
	{
		return clientsListName->getOrSetAttributeValuev(N)->getAdress();
	}
	string getClientPhone(int N)const
	{
		return clientsListName->getOrSetAttributeValuev(N)->getPhone();
	}
	typeOfProperty getClientTupe(int N)const
	{
		return clientsListName->getOrSetAttributeValuev(N)->getTupe();
	}
	string getAllDataAboutSecurity(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getAllData();
	}
	void setAllDataAboutSecurity(int N, string t1, double t2, int t3, double t4, tupeOfSecurity t5)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setAllData(t1, t2, t3, t4, t5);
	}
	void setSecurityCode(int N, string t1)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setSecurityCode(t1);
	}
	void setSecurityMinimumTransactionAmount(int N, double t2)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setMinimumTransactionAmount(t2);
	}
	void setSecurityRating(int N, int t3)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setRating(t3);
	}
	void setSecurityIncomeLastYear(int N, double t4)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setIncomeLastYear(t4);
	}
	void setSecurityTupe(int N, tupeOfSecurity t5)
	{
		securitiesListName->getOrSetAttributeValuev(N)->setTupe(t5);
	}
	string getSecurityCode(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getSecurityCode();
	}
	double getSecurityMinimumTransactionAmount(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getMinimumTransactionAmount();;
	}
	int getSecurityRating(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getRating();
	}
	double getSecurityIncomeLastYear(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getIncomeLastYear();
	}
	tupeOfSecurity getSecurityTupe(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getTupe();
	}
	vector<quoteDate>& getSecurityVector(int N)
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getVector();
	}
	string getSecurityHistory(int N)const
	{
		return securitiesListName->getOrSetAttributeValuev(N)->getHistory();
	}
	void addToSecurityHistory(int N, quoteDate tempVar)
	{
		securitiesListName->getOrSetAttributeValuev(N)->addToHistory(tempVar);
	}
	void setAllDataAboutInvestment(int N, security* temp1S, client* temp2C, double t1, double t2, string t3, string t4)
	{
		investmentsListName->getOrSetAttributeValuev(N)->createInvestment(temp1S, temp2C, t1, t2, t3, t4);
	}
	string getAllDataAboutInvestment(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getAllData();
	}
	void setInvestmentPurchaseQuotation(int N, double t1)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setPurchaseQuotation(t1);
	}
	void setInvestmentQuotationOnSale(int N, double t2)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setQuotationOnSale(t2);
	}
	void setInvestmentPurchaseDate(int N, string t3)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setPurchaseDate(t3);
	}
	void setInvestmentDateOfSale(int N, string t4)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setDateOfSale(t4);
	}
	void setInvestmentPaper(int N, security* paperT)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setPaper(paperT);
	}
	void setInvestmentMen(int N, client* menT)
	{
		investmentsListName->getOrSetAttributeValuev(N)->setMen(menT);
	}
	client* getInvestmentMen(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getMen();
	}
	security* getInvestmentPaper(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getPaper();
	}
	double getInvestmentPurchaseQuotation(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getPurchaseQuotation();
	}
	double getInvestmentQuotationOnSale(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getQuotationOnSale();
	}
	string getInvestmentPurchaseDate(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getPurchaseDate();
	}
	string getInvestmentDateOfSale(int N)const
	{
		return investmentsListName->getOrSetAttributeValuev(N)->getDateOfSale();
	}
	void setAllDataAboutDepositInvestment(int N, client* t1, double t2, double t3, string t4, string t5)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->createDepositInvestment(t1, t2, t3, t4, t5);
	}
	string getAllDataAboutDepositInvestment(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getAllData();
	}
	void setDepositInvestmentMen(int N, client* temp)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->setMen(temp);
	}
	void setDepositInvestmentSumm(int N, double temp)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->setInvestmentSumm(temp);
	}
	void setDepositInvestmentProfitForYear(int N, double temp)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->setProfitForYear(temp);
	}
	void setDepositInvestmentAccount(int N, string temp)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->setDepositAccount(temp);
	}
	void setDepositInvestmentOpenDate(int N, string temp)
	{
		depositInvestmentsListName->getOrSetAttributeValuev(N)->setOpenDate(temp);
	}
	client* getDepositInvestmentMen(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getMen();
	}
	double getDepositInvestmentSumm(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getInvestmentSumm();
	}
	double getDepositInvestmentProfitForYear(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getProfitForYear();;
	}
	string getDepositInvestmentAccount(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getDepositAccount();
	}
	string getDepositInvestmentOpenDate(int N)const
	{
		return depositInvestmentsListName->getOrSetAttributeValuev(N)->getOpenDate();
	}
	string getAllInfoFromBase()
	{
		return getALLClients() + getALLSecurities() + getALLInvestments() + getALLDepositInvestments();
	}
	~ISS()
	{
		clearAllList();
		delete clientsListName;
		delete securitiesListName;
		delete investmentsListName;
		delete depositInvestmentsListName;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ISS ISS_BASE;
	bool test = ISS_BASE.checkListEmpty();
	cout << test << endl << endl;
	cout << "SUCCESS\n\n\n";
	return 0;
}