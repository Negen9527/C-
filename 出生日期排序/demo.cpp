#include<iostream>
using namespace std;



//定义学生结构体
struct student{
	int year;     //出生年份
	int month;
	int day;


};


void print_sencond(struct student temp[100],int N){
	if(N > 2){
		for(int i=0; i < N; i++){
			if(i == 1){
				cout << "排行老二的是:";
				cout << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << endl;
				break;
			}
			
		}
	}

}


student * sortbirthday(struct student temp[100],int N){
	student tempstu;
	for(int i=0; i < N; i++){
		for(int j=i+1; j < N; j++){
			int first = temp[i].year*10000 + temp[i].month*100 + temp[i].day;
			int second = temp[j].year*10000 + temp[j].month*100 + temp[j].day;
			if( first > second){
				tempstu = temp[i];
				temp[i] = temp[j];
				temp[j] = tempstu;
			}
		}
	}
	return temp;
	
}





void main(){
	int N;            //定义学生总数

	student stu[100];
	cout << "请输入学生总数";
	cin >> N;
	for(int i=0; i<N ; i++){
		cin >> stu[i].year >> stu[i].month >> stu[i].day; 
		
	}
	
	student *sortedstu;
	
	sortedstu = sortbirthday(stu,N);
	print_sencond(sortedstu,N);
}




