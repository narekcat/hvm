#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
using namespace std;
struct mat
{
	short int m[400][400];
};

struct connect
{
	short int t[2];
};

class graph:public CObject
{
public:
	void setGraphParams(int,short int);
	graph():cq(0),tq(0){};
	~graph();
	void Serialize(CArchive& archive);
	int getcq(){return cq;}
	short int gettq(){return tq;}
	connect* p;
	short int fatq[400];
	double mtog[400];
	vector<mat> vm;
	short int n_vm;
	int lq;
	int run(short int&,short int&,short int&,int&,double&,double&,double&,double&,int&);
private:
	short int formal();
	bool test();
	int cq;
	short int tq;
	DECLARE_SERIAL(graph);
//	vector<mat> vecm;
};
#endif