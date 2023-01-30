#include <iostream>
#include <sstream> 
#include <fstream>
#include<cmath>
using namespace std;
ofstream ofs("input.csv");
ofstream ofs2("output.csv");

double gaussf(double wr, double count, double p){
	return 2.0*p/M_PI/wr*exp(-2.0*count/wr);
	}
int main(){
	int a;
	double r=27.0/127.0
	double p=0, CDL=0;
	double x=0, y=0, count=0, g=0;
	double XR=r, YR=r;
	double xy[500][25]={0}, X[500]={0}, Y[250]={0};
	double wr=pow(r,2);
       	double dx=(2.0*r+CDL)/500.0, dy=2.0*r/250.0;
	printf("条件数を入力￥ｎ")；
	scanf("%d",a);
	// CSVファイルを開く
	FILE * fp = fopen( "input.csv" , "r" ) ;
	// 例外
	if( fp == NULL ) {
		printf( "Error! File can not be opened\n" ) ;
		return -1;
	for(; fscanf(fp, "%d,%lf\n", p, &age, &height) != EOF; ){//出力，CDL値
		}
	}
		for(int i=0;i<1;i++){
		printf("%d\n",i);
		for(int j=0;j<500;j++){
			if(i==0){
				X[j]=x;
			}
			for(int k=0;k<250;k++){
				if(i==0&&j==0){
					Y[k]=y;
				}
				count=pow(x-XR,2)+pow(y-YR,2);
				if(count>wr){
					xy[j][k]+=0;
				}else{
					xy[j][k]+=gaussf(wr,count,p);
					//printf("[x%d],[y%d],%lf\n",j,k,xy[j][k]);
				}
				y+=dy;
				count=0;
			}
			y=0;
			x+=dx;
		}
		x=0;
		XR+=dx;
	}
	ofs2 << " " << ", " << "y" << endl;
	ofs2 << "x" << ", ";
	for(int i=0; i<250; i++){
		ofs2 << Y[i] << ",";
	}
	ofs2 << endl;
	for(int j=0;j<500;j++){        
		ofs2 << X[j] << ",";
		for(int k=0;k<250;k++){        
			ofs2 << xy[j][k] << ",";
		}
		ofs2 << endl;
	}
	//printf("%lf",xy[0][0]);
	return 0;
}
