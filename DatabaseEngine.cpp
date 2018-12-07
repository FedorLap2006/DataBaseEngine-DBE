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
	Column(){
		
	}
	Column(int v){
		
	}
	Column(long int v);
	Column(long long int v);
	Column(char v);
	Column(char* v);
	Column(string v);
	
	Column(String l,int v);
	Column(String l,long int v);
	Column(String l,long long int v);
	Column(String l,char v);
	Column(String l,char* v);
	Column(String l,String v);
	
	void SetCurType(String type);
	String GetCurType();
};

class Node{
private:
	map<String,Column*> mapvals;
	
public:
	Node(vector<Column> cols);
	set(int i,Column v);
	
};

class DBCore{
public:
	DBCore();
	DBCore(String filename);
	DBCore(Node tempcols,vector<Node> temps); // Node -- template node colums
	
	bool add(Node el);
	bool addAll(...); // va_args
	bool remove(int index);
	bool remove(int from,int to);
	bool removeAll();
	
	
	Node& get(int index);
	
	Node& find(String req);
	
};
