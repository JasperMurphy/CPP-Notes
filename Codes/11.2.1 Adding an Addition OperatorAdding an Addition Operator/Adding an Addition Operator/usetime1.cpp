// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together

// ������������������
// �޸ļ�¼��
// Date: 2022-06-19
// Reference:
// Author:
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
	Time total3plus;//���������϶���ʹ�÷������صĽ��

    cout << "planning time = ";
    planning.Show();
    cout << endl;
 
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
	// �������н�����+������,����֮��ķ��ſ���ֱ��ʹ�ã����������Ƶ��ú���һ��ʹ��total = morefixing.operator*(total);
    //total = coding + fixing; //����coding�ǵ��ö����Ҳ��fixing����Ϊ���������ݵĶ���
	total = coding * fixing;
    // operator notation
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    //total = morefixing.operator+(total);
	total = morefixing.operator*(total);
	//total = morefixing * total;
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    // std::cin.get();

	//���������϶���ʹ�÷������صĽ��
	total3plus = coding * fixing * total;
	cout << "total3plus = ";
	total3plus.Show();
	cout << endl;


	system("pause");
    return 0;
}
