// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together

// 功能描述：符号重载
// 修改记录：
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
	Time total3plus;//三个及以上对象使用符号重载的结果

    cout << "planning time = ";
    planning.Show();
    cout << endl;
 
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
	// 下面这行进行了+的重载,重载之后的符号可以直接使用，还可以类似调用函数一样使用total = morefixing.operator*(total);
    //total = coding + fixing; //左侧的coding是调用对象，右侧的fixing是作为参数被传递的对象
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

	//三个及以上对象使用符号重载的结果
	total3plus = coding * fixing * total;
	cout << "total3plus = ";
	total3plus.Show();
	cout << endl;


	system("pause");
    return 0;
}
