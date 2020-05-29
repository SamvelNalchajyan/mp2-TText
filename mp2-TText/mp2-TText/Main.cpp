#include <conio.h>
#include <iostream>
#include <string>
#include <clocale>
#include "TText.h"

using namespace std;

TTextMem TTextLink::MemHead;

void Menu(TText& txt)
{
	string st;
	string command;
	setlocale(LC_CTYPE, "Russian");
	do
	{
		cout << "������� 'help' ����� ������� ������ ������" << endl;
		cin >> command;
		if (command == "exit")
		{
			break;
		}
		if (command == "print")
		{
			txt.Print();
		}
		if (command == "print_iterator")
		{
			for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
			{
				cout << txt.GetLine() << endl;
			}
		}
		if (command == "first")
		{
			txt.GoFirstLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "down")
		{
			txt.GoDownLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "next")
		{
			txt.GoNextLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "prev")
		{
			txt.GoPrevLink();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "delete_down")
		{
			txt.DelDown();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "delete_next")
		{
			txt.DelNext();
			cout << "Now in " << txt.GetLine() << endl;
		}
		if (command == "insert_down_line")
		{
			cout << "string - " << endl;
			cin >> st;
			txt.InsDownLine(st);
		}
		if (command == "insert_down_section")
		{
			cout << "string - " << endl;
			cin >> st;
			txt.InsDownSection(st);
		}
		if (command == "insert_next_line")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextLine(st);
		}
		if (command == "insert_next_section")
		{
			cout << "enter string..." << endl;
			cin >> st;
			txt.InsNextSection(st);
		}
		if (command == "free")
		{
			TTextLink::PrintFreeLinks();
		}

		if (command == "help")
		{
			cout << "print - ������ ������ � ���������" << endl;
			cout << "print_iterator - ������ ������ �� ���������" << endl;
			cout << "first - ������� � ������ ������" << endl;
			cout << "next - ������� �� ��������� ������" << endl;
			cout << "down - ������� �� ������" << endl;
			cout << "prev - ������� �� ����������" << endl;
			cout << "delete_down - ������� ������ ������" << endl;
			cout << "delete_next - ������� ��������� ������" << endl;
			cout << "insert_down_line - �������� ������ �� ������� ����" << endl;
			cout << "insert_down_section - �������� ������ �� ������� ����" << endl;
			cout << "insert_next_line - �������� ������ �� ����� ���������" << endl;
			cout << "insert_next_section - �������� ������ �� ����� ���������" << endl;
			cout << "free - �������� ��������� ������" << endl;
			cout << "exit - ������� ���������" << endl;
		}
	} while (command != "exit");
}

int main()
{
	TTextLink::InitMem(100);
	TText t;
	t.Read("../FILE_in.txt");
	Menu(t);
	t.Write("../FILE_out.txt");
	TTextLink::MemClean(t);
	TTextLink::PrintFreeLinks();
}