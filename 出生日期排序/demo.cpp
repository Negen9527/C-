#include<iostream>
#include<iomanip>
using namespace std;


//����ѧ���ṹ��
struct student{
	int id;              //ѧ��
    char name[128];      //����
	char sex[2];         //�Ա�
	int year;            //��
	int month;           //��
	int day;             //��
};

void showMain(struct student stu[100],int N);
void loopMain(struct student stu[100],int N);

//������еڶ�����λ
void print_sencond(struct student temp[100],int N){
	if(N >= 2){
		for(int i=0; i < N; i++){
			if(i == 1){
				cout << "�����϶�����:";
				cout << "ѧ��:" << temp[i].id << "|";
				cout <<	"����:" << temp[i].name << "|";
				cout << "�Ա�:" << temp[i].sex << "|";
				cout << "��������:" << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << endl;
				break;
			}
		}
	}else{
		cout << "��ǰ���ҽ���һλѧ��������";
	}
	loopMain(temp,N);
}


//������������������
student * sortbirthday(struct student temp[100],int N){
	student *stu;
	stu = temp;
	student tempstu;
	for(int i=0; i < N; i++){
		for(int j=i+1; j < N; j++){
			int first = stu[i].year*10000 + stu[i].month*100 + stu[i].day;
			int second = stu[j].year*10000 + stu[j].month*100 + stu[j].day;
			if( first > second){
				tempstu = stu[i];
				stu[i] = stu[j];
				stu[j] = tempstu;
			}
		}
	}
	return stu;
}


//������е�ѧ��
void print_all(struct student temp[100],int N){
	cout << setw(8) << "ѧ��:";
	cout <<	setw(8) << "����:";
	cout << setw(8) << "�Ա�:";
	cout << setw(12) << "��������:" << endl;
	for(int i=0; i < N; i++){			
			cout << setw(8) << temp[i].id << "|";
			cout <<	setw(8) << temp[i].name << "|";
			cout << setw(8) << temp[i].sex << "|";
			cout << setw(8) << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << endl;
	}
	loopMain(temp,N);
}

//��ѧ�Ų���ѧ��
void searchStudentById(struct student temp[100],int N){
	int id;
	cout << "������ѧ��:";
	cin >> id;
	if(id > N){
		cout << "��ѯ���:" << "���޴���..." << endl;
	}else{
		for(int i=0; i<N; i++){
			if(temp[i].id == id){
				cout << "��ѯ���:<";
				cout << "ѧ��:" << temp[i].id << "|";
				cout <<	"����:" << temp[i].name << "|";
				cout << "�Ա�:" << temp[i].sex << "|";
				cout << "��������:" << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << ">" <<endl;
				break;
			}
		
		}
	}
	loopMain(temp,N);
}

//�����б�
void showMain(struct student stu[100],int N){
	cout << "+===========Main===========" << endl;
	cout << "+����:" << endl;
	cout << "+1���鿴����ѧ��" << endl;
	cout << "+2���鿴���еڶ���ѧ��" << endl;
	cout << "+3����ѧ�Ų���ѧ��" << endl;
	cout << "+4���˳�" << endl;
	cout << "+========================" << endl;
	cout << "��������Ӧ�����ѡ�����:";
	int choice;
	cin >> choice;
	switch(choice){
		case 1:              //�������ѧ��
			print_all(stu,N);
			break;
		case 2:              //�鿴���еڶ���ѧ��
			student *sortedstu;
			sortedstu = sortbirthday(stu,N);
			print_sencond(sortedstu,N);
			break;
		case 3:              //��ѧ�Ų���ѧ��
			searchStudentById(stu,N);
			break;
		case 4:
			exit(0);
			break;
	}

}



//ѭ���˵�
void loopMain(struct student stu[100],int N){
	cout << "-----------------------" << endl;
	cout << "����:1 ; �˳�:0 \n��ѡ��:";
	int choice;
	cin >> choice;
	if(choice == 1)
	{
		showMain(stu,N);
	}
		if(choice == 0)
	{
		exit(0);
	}
}


void main(){
	int N;                    //����ѧ������
	student stu[100];         //����ѧ������
	cout << "������ѧ��������";
	cin >> N;
	cout << "����������<" << N << ">λѧ������Ϣ" << endl;
	cout << "��ʽ: ���� �Ա� �� �� ��" << endl;
	cout << ">>============¼�뿪ʼ===========<<" << endl;
	for(int i=0; i<N ; i++){
		cout << "��" << i+1 << "λ--->";
		stu[i].id = i + 1;
		cin >> stu[i].name >> stu[i].sex >> stu[i].year >> stu[i].month >> stu[i].day; 
	}
	cout << ">>============¼�����===========<<\n\n" << endl;
	showMain(stu,N);
	
}




