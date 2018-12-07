#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio> // equivalent fstream -- FILE
#include <vector>
#include <map>
#include <iterator>
#include <list>
#include <string>
#include <cstdarg>


#define String string

using namespace std;

class Column{
private:	
	union{
		int *ival;
		long int *lival;
		long long int *llival;
		char *chval;
		char *sval;
		String *ssval;
	};
	
	String label;
	int Type;
	
	const int TInt=1;
	const int TLint=2;
	const int TLlint=3;
	const int TCh=4;
	const int TChS=5;
	const int TStr=6;
	
public:
	Column();
	Column(int);
	Column(long int);
	Column(long long int);
	Column(char);
	Column(char*);
	Column(string);
	
	Column(String,int);
	Column(String,long int);
	Column(String,long long int);
	Column(String,char);
	Column(String,char*);
	Column(String,String);
	
	void SetCurType(String type);
	String GetCurType();
};

class Node{
private:
	map<String,Column*> mapvals;
	
public:
	Node(vector<Column>);
	Node();
	
};

class DBCore{
public:
	DBCore();
	DBCore(String); // String -- filename
	DBCore(Node,vector<Node>); // Node -- template node colums
	
	bool add(Node el);
	bool addAll(...); // va_args
	bool remove(int index);
	bool remove(int from,int to);
	bool removeAll();
	
	
	Node& get(int index);
	
	Node& find(String req);
	
};
