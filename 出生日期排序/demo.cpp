#include<iostream>
#include<iomanip>
using namespace std;


//定义学生结构体
struct student{
	int id;              //学号
    char name[128];      //姓名
	char sex[2];         //性别
	int year;            //年
	int month;           //月
	int day;             //日
};

void showMain(struct student stu[100],int N);
void loopMain(struct student stu[100],int N);

//输出排行第二的那位
void print_sencond(struct student temp[100],int N){
	if(N >= 2){
		for(int i=0; i < N; i++){
			if(i == 1){
				cout << "排行老二的是:";
				cout << "学号:" << temp[i].id << "|";
				cout <<	"姓名:" << temp[i].name << "|";
				cout << "性别:" << temp[i].sex << "|";
				cout << "出生日期:" << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << endl;
				break;
			}
		}
	}else{
		cout << "当前有且仅有一位学生！！！";
	}
	loopMain(temp,N);
}


//按出生日期排序（升序）
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


//输出所有的学生
void print_all(struct student temp[100],int N){
	cout << setw(8) << "学号:";
	cout <<	setw(8) << "姓名:";
	cout << setw(8) << "性别:";
	cout << setw(12) << "出生日期:" << endl;
	for(int i=0; i < N; i++){			
			cout << setw(8) << temp[i].id << "|";
			cout <<	setw(8) << temp[i].name << "|";
			cout << setw(8) << temp[i].sex << "|";
			cout << setw(8) << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << endl;
	}
	loopMain(temp,N);
}

//按学号查找学生
void searchStudentById(struct student temp[100],int N){
	int id;
	cout << "请输入学号:";
	cin >> id;
	if(id > N){
		cout << "查询结果:" << "查无此人..." << endl;
	}else{
		for(int i=0; i<N; i++){
			if(temp[i].id == id){
				cout << "查询结果:<";
				cout << "学号:" << temp[i].id << "|";
				cout <<	"姓名:" << temp[i].name << "|";
				cout << "性别:" << temp[i].sex << "|";
				cout << "出生日期:" << temp[i].year << "_" << temp[i].month << "_" << temp[i].day << ">" <<endl;
				break;
			}
		
		}
	}
	loopMain(temp,N);
}

//操作列表
void showMain(struct student stu[100],int N){
	cout << "+===========Main===========" << endl;
	cout << "+操作:" << endl;
	cout << "+1、查看所有学生" << endl;
	cout << "+2、查看排行第二的学生" << endl;
	cout << "+3、按学号查找学生" << endl;
	cout << "+4、退出" << endl;
	cout << "+========================" << endl;
	cout << "请输入相应的序号选择操作:";
	int choice;
	cin >> choice;
	switch(choice){
		case 1:              //输出所有学生
			print_all(stu,N);
			break;
		case 2:              //查看排行第二的学生
			student *sortedstu;
			sortedstu = sortbirthday(stu,N);
			print_sencond(sortedstu,N);
			break;
		case 3:              //按学号查找学生
			searchStudentById(stu,N);
			break;
		case 4:
			exit(0);
			break;
	}

}



//循环菜单
void loopMain(struct student stu[100],int N){
	cout << "-----------------------" << endl;
	cout << "返回:1 ; 退出:0 \n请选择:";
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
	int N;                    //定义学生总数
	student stu[100];         //定义学生数组
	cout << "请输入学生总数：";
	cin >> N;
	cout << "请依次输入<" << N << ">位学生的信息" << endl;
	cout << "格式: 姓名 性别 年 月 日" << endl;
	cout << ">>============录入开始===========<<" << endl;
	for(int i=0; i<N ; i++){
		cout << "第" << i+1 << "位--->";
		stu[i].id = i + 1;
		cin >> stu[i].name >> stu[i].sex >> stu[i].year >> stu[i].month >> stu[i].day; 
	}
	cout << ">>============录入结束===========<<\n\n" << endl;
	showMain(stu,N);
	
}




