#include "stdafx.h"
#include "graph.h"
//#include <fstream.h>

void graph::setGraphParams(int i_cq,short int i_tq)
{
	cq=i_cq;
	tq=i_tq;
	lq=2*cq;
	p=new connect[cq];
	for(int i=0;i<cq;i++)
		p[i].t[0]=p[i].t[1]=-1;
}

graph::~graph()
{
	delete [] p;
	p=NULL;
}

bool graph::test()
{
	short int i,j;
	for(i=1;i<tq-1;i++)
		for(j=i+1;j<tq;j++)
			if(vm[n_vm-1].m[i][j] || vm[n_vm-1].m[j][i])
				return true;
	return false;
}

short int graph::formal()
{
	short int i,j,q=0;
	for(i=1;i<=tq;i++)
	{
		for(j=1;j<=tq;j++)
			if(vm[n_vm-1].m[j][i])
				break;
		if(j==tq+1)
			q++;
	}
	return q;
}

int graph::run(short int& mtq,short int& etq,short int& mitq,int& nkq,double& mkg,double& mtg,double& mtogm,double& kg,int& etmkq)
{
	short int vec[400],i,g,l,vece[400],et=0;
	int j,qs,qe;
	mtq=0;
	mitq=0;
	etq=0;
////assembler////
	for(i=1;i<=tq;i++)
	{
		qs=0;
		qe=0;
		for(j=0;j<cq;j++)
		{
			if(i==p[j].t[0] && p[j].t[1]!=0)
				qs++;
			if(i==p[j].t[1])
				qe++;
		}
		if(qs==0 && qe!=0)
			etq++;
		else
			if(qs!=0 && qe==0)
				mtq++;
			else
				if(qs!=0 && qe!=0)
				{
					vec[mitq]=i;
					mitq++;
				}
	}
////end////
	mtg=double(mitq)/tq;
	mat m;
////assembler////
	for(i=0;i<=tq;i++)
		for(j=0;j<=tq;j++)
			m.m[i][j]=0;
	for(i=0;i<cq;i++)
		m.m[p[i].t[0]][p[i].t[1]]=1;
////end////
	while(!vm.empty())
		vm.pop_back();
	vm.push_back(m);
	n_vm=1;
	mtogm=0;
//	fstream fout("output.txt",ios::out);
	while(test())
	{
		fatq[n_vm-1]=formal();
		mtog[n_vm-1]=double(fatq[n_vm-1]-n_vm)/fatq[n_vm-1];
//		fout<<fatq[n_vm-1]<<' '<<mtog[n_vm-1]<<endl;
		mtogm+=mtog[n_vm-1];
		vm.push_back(m);
////assembler////
		for(i=0;i<=tq;i++)
			for(j=0;j<=tq;j++)
			{
				g=0;
				for(l=0;l<=tq;l++)
					g+=vm[n_vm-1].m[i][l]*m.m[l][j];
				vm[n_vm].m[i][j]=g;
			}
		n_vm++;
////end////
	}
	fatq[n_vm-1]=formal();
	mtog[n_vm-1]=double(fatq[n_vm-1]-n_vm)/fatq[n_vm-1];
	mtogm+=mtog[n_vm-1];
	mtogm/=n_vm;
//	fout<<mtogm<<endl;
	for(i=0;i<cq;i++)
		if(!p[i].t[1])
		{
			vece[et]=p[i].t[0];
			et++;
		}
////assembler////
	for(i=0;i<=tq;i++)
		for(l=0;l<=tq;l++)
			vm[n_vm].m[i][l]=0;
	for(j=0;j<n_vm;j++)
		for(i=0;i<=tq;i++)
			for(l=0;l<=tq;l++)
				vm[n_vm].m[i][l]+=vm[j].m[i][l];
////end////
	etmkq=0;
	for(j=0;j<et-1;j++)
		for(l=j+1;l<et;l++)
			etmkq+=vm[n_vm].m[vece[j]][vece[l]];
	if(et==1)
		kg=0;
	else
		kg=2*etmkq/(et*(et-1));
////assembler////
	nkq=0;
	for(i=0;i<mitq;i++)
		for(l=i+1;l<mitq;l++)
			nkq+=vm[0].m[vec[i]][vec[l]];
////end////
	mkg=double(nkq)/cq;
	return n_vm;
}

void graph::Serialize(CArchive& archive)
{
	if(archive.IsStoring())
	{
		archive<<cq;
		archive<<tq;
		archive<<lq;
		for(int i=0;i<cq;i++)
			archive<<p[i].t[0]<<p[i].t[1];
	}
	else
	{
		archive>>cq;
		archive>>tq;
		archive>>lq;
		p=new connect[cq];
		for(int i=0;i<cq;i++)
			archive>>p[i].t[0]>>p[i].t[1];
	}
}

IMPLEMENT_SERIAL(graph,CObject,0)