#include<iostream>
using namespace std;



//����ѧ���ṹ��
struct student{
	int year;     //�������
	int month;
	int day;


};


void print_sencond(struct student temp[100],int N){
	if(N > 2){
		for(int i=0; i < N; i++){
			if(i == 1){
				cout << "�����϶�����:";
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
	int N;            //����ѧ������

	student stu[100];
	cout << "������ѧ������";
	cin >> N;
	for(int i=0; i<N ; i++){
		cin >> stu[i].year >> stu[i].month >> stu[i].day; 
		
	}
	
	student *sortedstu;
	
	sortedstu = sortbirthday(stu,N);
	print_sencond(sortedstu,N);
}




