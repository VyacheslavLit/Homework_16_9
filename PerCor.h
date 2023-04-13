#pragma once
#include <vector>
//#include <exception>
//#include <memory>
#include <iostream>
#include "MessagePC.h"


//��������� ���������� �� ������ ������
struct ExpLogin :public exception
{
	const char* what() const noexcept override
	{
		return "� ��������� ������ ����� �����, �������� �����.\n";
	}
};

//��������� ���������� �� ������ �����
struct ExpName :public exception
{
	const char* what() const noexcept override
	{
		return "� ��������� ������ ��� ������, �������� ���.\n";
	}
};



/*
	����� PerCor - �������� ����� �������������� ����� ���������.

	me_ - ���������� ������������ ������������              -- �������������� ������ - ������ LoginMenu --
	party_ - ���������� ������������ �����������       getUsersFile - �������� ������������� � ��������� �� �����
	users_ - ��������� �������������                   login - ���� ������������
	perCorParty_ - ��������� �������������             registration - ����������� ������������
			� �������� ������� ���������				  setUsersFile (�������������� ����� ������ registration) -
	messagePC_ - ��������� � ������ ����������							�������� ������������������� ������������ � ����
	currentUser_ - ��������� �� ������������ (����)			-- �������������� ������ - ������ UserMenu --
			�� ������ ���������� �������������         getMessagePC_File - �������� ������ ��������� �� �����
			--- �������� ������ ---					   perCorParty - ���������� ���������� ������������� � �������� ������� ������ ���������
	LoginMenu - ���� � ����������� ������������	  	   setParty - ����� �������� �����������
	UserMenu - ����� �����������					   addParty - ���������� � ����� ������ �����������
	showPC - ��������� 								   expParty (�������������� ����� ������ addParty) -
	loginAdminPC() - ���� ������					   �������� ���������� ������������ �� ������
															-- �������������� ������ - ������ showPC --
	getUserByLogin - ��������� ����������� �����	   chat - ����� ������ ��������� � ��������� ������������
		�� �������� ��������						   addMessage - ���������� ��������� � ��� � ���������� ��� � ��������� ���������
	getUserByName - ��������� ����������� ���				-- ��������������� ����� --
		�� �������� ��������						   expCin - ��������� ������ ��� ������������� ��������� cin
*/
class PerCor {
	string me_="";
	string party_;
	map <const string, User> users_;

	set <string> perCorParty_;
	vector<MessagePC> messagePC_;

public:
	string getMe() const { return me_; }
	void loginMenuPC();
	void userMenuPC();
	void showPC();
	void loginAdminPC();
	auto getParty() { return party_; }

private:
	void getUsersFile();
	void login();
	void registration();
	void setUsersFile(const string, const string, const string);
	void getMessagePC_File();
	void perCorParty();
	void addParty();
	bool expParty(const string name);
	void chat();
	void addMessage(const string txt);
	void expCin();

	bool getUserByLogin(const string& login) const;
	bool getUserByName(const string& name)const;
	string getNameToLogin(string);

};
