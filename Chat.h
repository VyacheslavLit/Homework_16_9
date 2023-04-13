#pragma once
#include <vector>
#include <iostream>
#include "Message.h"
#include "Dict.h"

class Dict;

/*
	����� Chat - �������� ����� �������������� ����� ���������.

	me_ - ���������� ������������ ������������              -- �������������� ������ - ������ LoginMenu --
	users_ - ��������� �������������					getUsersFile  -  ��������  ������������� � ��������� �� �����
	message_ - ��������� � ����������					login - ���� ������������
	currentUser_ - ��������� �� ������������ (����)		registration - ����������� ������������
			�� ������ ���������� �������������				setUsersFile (�������������� ����� ������ registration) -
																		��������   �������������������  ������������
		--- �������� ������ ---											� ����
	LoginMenu - ���� � ����������� ������������				-- �������������� ������ - ������ showChat --
	showChat - ���������								getMessage_File - �������� ��������� �� �����
														chat - ����� ���������
	getUserByLogin - ��������� ����������� �����		addMessage - ����������  ���������  �  ���  �  ���������� ���
		�� ������� ��������										� ��������� ���������
	getUserByName - ��������� ����������� ���				-- ��������������� ����� --
		�� ������� ��������								expCin - ��������� ������ ��� ������������� ��������� cin
*/
class Chat {
	string me_ = "";
	map <const string, User> users_;
	vector<Message> message_;

public:
	string getMe() const { return me_; }
	void loginMenu();
	void showChat();
	void showChatDict(Dict dict);

private:
	void getUsersFile();
	void login();
	void registration();
	void setUsersFile(string, string, string);
	void getMessage_File();
	void chat();
	void addMessage(const string txt);
	void expCin();

	bool getUserByLogin(const string& login) const;
	bool getUserByName(const string& name)const;
	string getNameToLogin(string);
};

